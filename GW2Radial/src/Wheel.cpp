#include <Main.h>
#include <Wheel.h>
#include <Core.h>
#include <Utility.h>
#include <UnitQuad.h>
#include <ImGuiExtensions.h>
#include <imgui.h>
#include <utility>
#include <Input.h>
#include "../imgui/imgui_internal.h"
#include <algorithm>

namespace GW2Radial
{

Wheel::Wheel(uint bgResourceId, uint inkResourceId, std::string nickname, std::string displayName, IDirect3DDevice9 * dev)
	: nickname_(std::move(nickname)), displayName_(std::move(displayName)),
	  keybind_(nickname_, u8"�����λ����ʾ"), 
	  centralKeybind_(nickname_ + "_cl", u8"����Ļ������ʾ"),
	  centerBehaviorOption_(u8"���ĵ���Ϊ", "center_behavior", "wheel_" + nickname_),
	  centerFavoriteOption_(u8"ϲ��ѡ��", "center_favorite", "wheel_" + nickname_),
	  scaleOption_(u8"��С", "scale", "wheel_" + nickname_, 1.f),
	  centerScaleOption_(u8"���Ĵ�С", "center_scale", "wheel_" + nickname_, 0.2f),
	  displayDelayOption_(u8"�����ӳ�", "delay", "wheel_" + nickname_),
	  animationTimeOption_(u8"����ʱ��", "anim_time", "wheel_" + nickname_, 750),
	  resetCursorOnLockedKeybindOption_(u8"��ʾ����ʱ��������õ�����", "reset_cursor_cl", "wheel_" + nickname_, true),
	  lockCameraWhenOverlayedOption_(u8"��ʾ����ʱ�������", "lock_camera", "wheel_" + nickname_, true),
	  showOverGameUIOption_(u8"��ʾ����ϷUI֮��", "show_over_ui", "wheel_" + nickname_, true),
	  noHoldOption_(u8"�������ɿ�������¼����һ������ѡ��", "no_hold", "wheel_" + nickname_, false)
{
	D3DXCreateTextureFromResource(dev, Core::i()->dllModule(), MAKEINTRESOURCE(bgResourceId), &backgroundTexture_);
	D3DXCreateTextureFromResource(dev, Core::i()->dllModule(), MAKEINTRESOURCE(inkResourceId), &inkTexture_);

	mouseMoveCallback_ = [this]() { return OnMouseMove(); };
	Input::i()->AddMouseMoveCallback(&mouseMoveCallback_);
	inputChangeCallback_ = [this](bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys) { return OnInputChange(changed, keys, changedKeys); };
	Input::i()->AddInputChangeCallback(&inputChangeCallback_);

	SettingsMenu::i()->AddImplementer(this);
}

Wheel::~Wheel()
{
	COM_RELEASE(backgroundTexture_);
	COM_RELEASE(inkTexture_);

	if(auto i = Input::iNoInit(); i)
	{
		i->RemoveMouseMoveCallback(&mouseMoveCallback_);
		i->RemoveInputChangeCallback(&inputChangeCallback_);
	}
	
	if(auto i = SettingsMenu::iNoInit(); i)
		i->RemoveImplementer(this);
}

void Wheel::UpdateHover()
{
	const auto io = ImGui::GetIO();

	D3DXVECTOR2 mousePos;
	mousePos.x = io.MousePos.x / float(Core::i()->screenWidth());
	mousePos.y = io.MousePos.y / float(Core::i()->screenHeight());
	mousePos -= currentPosition_;

	mousePos.y *= float(Core::i()->screenHeight()) / float(Core::i()->screenWidth());

	WheelElement* lastHovered = currentHovered_;

	auto activeElements = GetActiveElements();

	// Middle circle does not count as a hover event
	if (!activeElements.empty() && D3DXVec2LengthSq(&mousePos) > SQUARE(scaleOption_.value() * 0.125f * 0.8f * centerScaleOption_.value()))
	{
		float mouseAngle = atan2(-mousePos.y, -mousePos.x) - 0.5f * float(M_PI);
		if (mouseAngle < 0)
			mouseAngle += float(2 * M_PI);

		const float elementAngle = float(2 * M_PI) / activeElements.size();
		const int elementId = int((mouseAngle - elementAngle / 2) / elementAngle + 1) % activeElements.size();

		currentHovered_ = activeElements[elementId];
	}
	else
		currentHovered_ = GetCenterHoveredElement();

	if (lastHovered != currentHovered_)
	{
		const auto time = TimeInMilliseconds();

		if(lastHovered) lastHovered->currentExitTime(time);
		if(currentHovered_) currentHovered_->currentHoverTime(time);
	}
}

void Wheel::DrawMenu()
{
	ImGui::PushID((nickname_ + "Elements").c_str());
	ImGui::BeginGroup();

	ImGui::TextUnformatted(u8"����Ϸ�ڰ������ñ���һ��:");

	for(auto& we : wheelElements_)
		ImGuiKeybindInput(we->keybind());
	
	ImGui::Separator();
	ImGuiSpacing();
	
	ImGuiKeybindInput(keybind_);
	ImGuiKeybindInput(centralKeybind_);

	ImGui::PushItemWidth(0.66f * ImGui::GetWindowContentRegionWidth());
	
	ImGuiConfigurationWrapper(&ImGui::SliderInt, displayDelayOption_, 0, 1000, "%d ms");
	ImGuiConfigurationWrapper(&ImGui::SliderInt, animationTimeOption_, 0, 2000, "%d ms");
	ImGuiConfigurationWrapper(&ImGui::SliderFloat, scaleOption_, 0.25f, 4.f, "%.2f", 1.f);
	ImGuiConfigurationWrapper(&ImGui::SliderFloat, centerScaleOption_, 0.05f, 0.25f, "%.2f", 1.f);

	ImGui::PopItemWidth();

	ImGuiConfigurationWrapper(&ImGui::Checkbox, noHoldOption_);

	if(!noHoldOption_.value())
	{
		ImGui::Text((centerBehaviorOption_.displayName() + ":").c_str());
		ImGui::SameLine();
		ImGui::PushItemWidth(0.25f * ImGui::GetWindowContentRegionWidth());

		bool (*rb)(const char*, int*, int) = &ImGui::RadioButton;
		ImGuiConfigurationWrapper(rb, u8"��", centerBehaviorOption_, int(CenterBehavior::NOTHING));
		ImGui::SameLine();
		ImGuiConfigurationWrapper(rb, u8"��һ��", centerBehaviorOption_, int(CenterBehavior::PREVIOUS));
		ImGui::SameLine();
		ImGuiConfigurationWrapper(rb, u8"�Զ���", centerBehaviorOption_, int(CenterBehavior::FAVORITE));
		
		ImGui::PopItemWidth();
	
		if (CenterBehavior(centerBehaviorOption_.value()) == CenterBehavior::FAVORITE)
		{
			ImGuiIndent();
			
			const auto textSize = ImGui::CalcTextSize(centerFavoriteOption_.displayName().c_str());
			const auto itemSize = ImGui::CalcItemWidth() - textSize.x - ImGui::GetCurrentWindowRead()->WindowPadding.x;
			ImGui::PushItemWidth(itemSize);

			std::vector<const char*> potentialNames(wheelElements_.size());
				for (uint i = 0; i < wheelElements_.size(); i++)
					potentialNames[i] = wheelElements_[i]->displayName().c_str();

			bool (*cmb)(const char*, int*, const char* const*, int, int) = &ImGui::Combo;
			ImGuiConfigurationWrapper(cmb, centerFavoriteOption_, potentialNames.data(), int(potentialNames.size()), -1);
			ImGui::PopItemWidth();
			ImGuiUnindent();
		}
	}
	
	ImGuiConfigurationWrapper(&ImGui::Checkbox, resetCursorOnLockedKeybindOption_);
	ImGuiConfigurationWrapper(&ImGui::Checkbox, lockCameraWhenOverlayedOption_);
	ImGuiConfigurationWrapper(&ImGui::Checkbox, showOverGameUIOption_);

	ImGui::Separator();
	ImGuiSpacing();
	ImGui::Text(u8"�ɼ���˳��(˳ʱ������):");

	for(auto it = wheelElements_.begin(); it != wheelElements_.end(); ++it)
	{
		const auto extremum = it == wheelElements_.begin() ? 1 : it == std::prev(wheelElements_.end()) ? -1 : 0;
		auto& e = *it;
		if(const auto dir = e->DrawPriority(extremum); dir != 0)
		{
			if(dir == 1 && e == wheelElements_.front() ||
				dir == -1 && e == wheelElements_.back())
				continue;

			auto& eOther = dir == 1 ? *std::prev(it) : *std::next(it);
			e.swap(eOther);
			const auto tempPriority = eOther->sortingPriority();
			eOther->sortingPriority(e->sortingPriority());
			e->sortingPriority(tempPriority);
		}
	}

	ImGui::EndGroup();
	ImGui::PopID();
}

void Wheel::Draw(IDirect3DDevice9* dev, ID3DXEffect* fx, UnitQuad* quad)
{
	if (isVisible_)
	{
		const int screenWidth = Core::i()->screenWidth();
		const int screenHeight = Core::i()->screenHeight();

		quad->Bind();

		const auto currentTime = TimeInMilliseconds();

		if (currentTime >= currentTriggerTime_ + displayDelayOption_.value())
		{
			if(resetCursorPositionToCenter_)
			{
				RECT rect = { };
				if (GetWindowRect(Core::i()->gameWindow(), &rect))
				{
					if (SetCursorPos((rect.right - rect.left) / 2 + rect.left, (rect.bottom - rect.top) / 2 + rect.top))
					{
						auto& io = ImGui::GetIO();
						io.MousePos.x = Core::i()->screenWidth() * 0.5f;
						io.MousePos.y = Core::i()->screenHeight() * 0.5f;
					}
				}
				resetCursorPositionToCenter_ = false;
			}
			uint passes = 0;

			// Setup viewport
			D3DVIEWPORT9 vp;
			vp.X = vp.Y = 0;
			vp.Width = screenWidth;
			vp.Height = screenHeight;
			vp.MinZ = 0.0f;
			vp.MaxZ = 1.0f;
			dev->SetViewport(&vp);

			D3DXVECTOR4 screenSize(float(screenWidth), float(screenHeight), 1.f / screenWidth, 1.f / screenHeight);

			auto activeElements = GetActiveElements();
			if (!activeElements.empty())
			{
				D3DXVECTOR4 baseSpriteDimensions;
				baseSpriteDimensions.x = currentPosition_.x;
				baseSpriteDimensions.y = currentPosition_.y;
				baseSpriteDimensions.z = scaleOption_.value() * 0.5f * screenSize.y * screenSize.z;
				baseSpriteDimensions.w = scaleOption_.value() * 0.5f;
				
				const float fadeTimer = std::min(1.f, (currentTime - (currentTriggerTime_ + displayDelayOption_.value())) / float(animationTimeOption_.value() * 0.45f));
				const float inkTimer = std::min(1.f, (currentTime - (currentTriggerTime_ + displayDelayOption_.value())) / float(animationTimeOption_.value()));
				
				std::vector<float> hoveredFadeIns;
				std::transform(activeElements.begin(), activeElements.end(), std::back_inserter(hoveredFadeIns),
					[&](const WheelElement* elem) { return elem->hoverFadeIn(currentTime, this); });

				switch(CenterBehavior(centerBehaviorOption_.value()))
				{
				case CenterBehavior::PREVIOUS:
					if(previousUsed_)
						hoveredFadeIns.push_back(previousUsed_->hoverFadeIn(currentTime, this));
					break;
				case CenterBehavior::FAVORITE:
					for(const auto& e : wheelElements_)
						if(e->sortingPriority() == minElementSortingPriority_ + uint(centerFavoriteOption_.value()))
							hoveredFadeIns.push_back(e->hoverFadeIn(currentTime, this));
					break;
				default:
					hoveredFadeIns.push_back(0.f);
					break;
				}

				fx->SetTechnique("BgImage");
				fx->SetTexture("texBgImage", backgroundTexture_);
				fx->SetTexture("texInkImage", inkTexture_);
				fx->SetValue("g_vInkSpot", inkSpot_, sizeof(inkSpot_));
				fx->SetVector("g_vSpriteDimensions", &baseSpriteDimensions);
				fx->SetValue("g_fWheelFadeIn", &D3DXVECTOR2(fadeTimer, inkTimer), sizeof(D3DXVECTOR2));
				fx->SetFloat("g_fAnimationTimer", fmod(currentTime / 1010.f, 55000.f));
				fx->SetFloat("g_fCenterScale", centerScaleOption_.value());
				fx->SetInt("g_iElementCount", int(activeElements.size()));
				fx->SetFloatArray("g_fHoverFadeIns", hoveredFadeIns.data(), UINT(hoveredFadeIns.size()));
				fx->Begin(&passes, 0);
				fx->BeginPass(0);
				quad->Draw();
				fx->EndPass();
				fx->End();

				fx->SetTechnique(alphaBlended_ ? "MountImageAlphaBlended" : "MountImage");
				fx->SetTexture("texBgImage", backgroundTexture_);
				fx->SetVector("g_vScreenSize", &screenSize);
				fx->Begin(&passes, 0);
				fx->BeginPass(0);

				int n = 0;
				for (auto it : activeElements)
				{
					it->Draw(n, baseSpriteDimensions, activeElements.size(), currentTime, currentHovered_, this);
					n++;
				}

				fx->EndPass();
				fx->End();
			}

			{
				const auto& io = ImGui::GetIO();

				fx->SetTechnique("Cursor");
				fx->SetTexture("texBgImage", backgroundTexture_);
				D3DXVECTOR4 spriteDimensions(io.MousePos.x * screenSize.z, io.MousePos.y * screenSize.w, 0.05f  * screenSize.y * screenSize.z, 0.05f);
				fx->SetVector("g_vSpriteDimensions", &spriteDimensions);

				fx->Begin(&passes, 0);
				fx->BeginPass(0);
				quad->Draw();
				fx->EndPass();
				fx->End();
			}
		}
	}
}

void Wheel::OnFocusLost()
{
	currentHovered_ = nullptr;
	isVisible_ = false;
	currentTriggerTime_ = 0;
}

void Wheel::Sort()
{
	std::sort(wheelElements_.begin(), wheelElements_.end(),
		[](const std::unique_ptr<WheelElement>& a, const std::unique_ptr<WheelElement>& b) { return a->sortingPriority() < b->sortingPriority(); });
	minElementSortingPriority_ = wheelElements_.front()->sortingPriority();
}

WheelElement* Wheel::GetCenterHoveredElement()
{
	if(noHoldOption_.value())
		return nullptr;

	switch (CenterBehavior(centerBehaviorOption_.value()))
	{
	case CenterBehavior::PREVIOUS:
		return previousUsed_;
	case CenterBehavior::FAVORITE:
		for(const auto& e : wheelElements_)
			if(e->sortingPriority() == minElementSortingPriority_ + uint(centerFavoriteOption_.value()))
				return e.get();
	default:
		return nullptr;
	}
}

std::vector<WheelElement*> Wheel::GetActiveElements()
{
	std::vector<WheelElement*> elems;
	for(auto& we : wheelElements_)
		if(we->isActive())
			elems.push_back(we.get());

	return elems;
}

bool Wheel::OnMouseMove()
{
	if(isVisible_)
	{
		UpdateHover();
		
		// If holding down the button is not necessary, modify behavior
		if(noHoldOption_.value() && isVisible_ && currentHovered_ != nullptr)
			DeactivateWheel();
	}

	return isVisible_ && lockCameraWhenOverlayedOption_.value();
}

InputResponse Wheel::OnInputChange(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys)
{
	const bool previousVisibility = isVisible_;

	//bool mountOverlay = keybind_.isSet() && std::includes(keys.begin(), keys.end(), keybind_.keys().begin(), keybind_.keys().end());
	//bool mountOverlayLocked = centralKeybind_.isSet() && std::includes(keys.begin(), keys.end(), centralKeybind_.keys().begin(), centralKeybind_.keys().end());
	
	bool mountOverlay = keybind_.matchesPartial(keys);
	bool mountOverlayLocked = centralKeybind_.matchesPartial(keys);


	if(mountOverlay)
		mountOverlay &= !keybind_.conflicts(keys);
	if(mountOverlayLocked)
		mountOverlayLocked &= !centralKeybind_.conflicts(keys);

	isVisible_ = mountOverlayLocked || mountOverlay;
	
	// If holding down the button is not necessary, modify behavior
	if(noHoldOption_.value() && previousVisibility && currentHovered_ == nullptr)
		isVisible_ = true;

	if (isVisible_ && !previousVisibility)
		ActivateWheel(mountOverlayLocked);
	else if (!isVisible_ && previousVisibility)
		DeactivateWheel();
	
	{
		const auto isAnyElementBeingModified = std::any_of(wheelElements_.begin(), wheelElements_.end(),
			[](const auto& we) { return we->keybind().isBeingModified(); });

		{
			// If a key was lifted, we consider the key combination *prior* to this key being lifted as the keybind
			bool keyLifted = false;
			auto fullKeybind = keys;

			// Explicitly filter out M1 (left mouse button) from keybinds since it breaks too many things
			fullKeybind.erase(VK_LBUTTON);

			for (const auto& ek : changedKeys)
			{
				if(ek.vk == VK_LBUTTON)
					continue;

				if (!ek.down)
				{
					fullKeybind.insert(ek.vk);
					keyLifted = true;
				}
			}


			keybind_.keys(fullKeybind);
			centralKeybind_.keys(fullKeybind);

			if(keyLifted)
			{
				keybind_.isBeingModified(false);	
				centralKeybind_.isBeingModified(false);	
			}

			for (auto& we : wheelElements_)
			{
				we->keybind().keys(fullKeybind);	
				if(keyLifted)
					we->keybind().isBeingModified(false);	
			}
		}

		if(isAnyElementBeingModified)
			return InputResponse::PREVENT_ALL;
	}
	
	return InputResponse::PASS_TO_GAME;
}

void Wheel::ActivateWheel(bool isMountOverlayLocked)
{
	auto& io = ImGui::GetIO();

	if (resetCursorPositionBeforeKeyPress_)
		cursorResetPosition_ = { static_cast<int>(io.MousePos.x), static_cast<int>(io.MousePos.y) };

	// Mount overlay is turned on
	if (isMountOverlayLocked)
	{
		currentPosition_.x = currentPosition_.y = 0.5f;

		if (resetCursorOnLockedKeybindOption_.value())
			resetCursorPositionToCenter_ = true;
	}
	else
	{
		resetCursorPositionToCenter_ = false;
		currentPosition_.x = io.MousePos.x / float(Core::i()->screenWidth());
		currentPosition_.y = io.MousePos.y / float(Core::i()->screenHeight());
	}

	currentTriggerTime_ = TimeInMilliseconds();
	
	inkSpot_ = D3DXVECTOR3(frand() * 0.20f + 0.40f, frand() * 0.20f + 0.40f, frand() * 2 * float(M_PI));

	UpdateHover();
}

void Wheel::DeactivateWheel()
{
	isVisible_ = false;
	resetCursorPositionToCenter_ = false;

	// Check for special behavior if no mount is hovered
	if(!currentHovered_)
		currentHovered_ = GetCenterHoveredElement();

	// Mount overlay is turned off, send the keybind
	if (currentHovered_)
		Input::i()->SendKeybind(currentHovered_->keybind().keys(), cursorResetPosition_);

	previousUsed_ = currentHovered_;
	currentHovered_ = nullptr;
}

}
