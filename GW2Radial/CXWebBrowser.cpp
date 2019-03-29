#include "CXWebBrowser.h"



// XWebBrowser.cpp: implementation of the CXWebBrowser class.
// http://blog.csdn.net/Sidyhe
//////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXWebBrowser::CXWebBrowser()
{
	//初始化
	m_bInPlaced = FALSE;
	m_hDlg = NULL;
	m_RefCount = 0;
	m_pObject = NULL;
	m_pStorage = NULL;
#if _DEBUG
	//创建一个存储根对象
	_ASSERT(StgCreateDocfile(NULL, STGM_READWRITE | STGM_SHARE_EXCLUSIVE | STGM_DIRECT | STGM_CREATE, 0, &m_pStorage) == ERROR_SUCCESS);
	//创建OLE对象
	_ASSERT(OleCreate(CLSID_WebBrowser, IID_IOleObject, OLERENDER_DRAW, NULL, this/*万恶的继承*/, m_pStorage, (void**)& m_pObject) == ERROR_SUCCESS);
	_ASSERT(m_pObject->QueryInterface(IID_IOleInPlaceObject, (void**)& m_pInPlaceObj) == ERROR_SUCCESS);
	_ASSERT(m_pObject->QueryInterface(IID_IOleInPlaceActiveObject, (void**)& m_pInPlaceActiveObj) == ERROR_SUCCESS);
	_ASSERT(m_pObject->QueryInterface(IID_IWebBrowser2, (void**)& m_pIWebBrowser2) == ERROR_SUCCESS);
#else
	StgCreateDocfile(NULL, STGM_READWRITE | STGM_SHARE_EXCLUSIVE | STGM_DIRECT | STGM_CREATE, 0, &m_pStorage);
	OleCreate(CLSID_WebBrowser, IID_IOleObject, OLERENDER_DRAW, NULL, this, m_pStorage, (void**)& m_pObject);
	m_pObject->QueryInterface(IID_IOleInPlaceObject, (void**)& m_pInPlaceObj);
	m_pObject->QueryInterface(IID_IOleInPlaceActiveObject, (void**)& m_pInPlaceActiveObj);
	m_pObject->QueryInterface(IID_IWebBrowser2, (void**)& m_pIWebBrowser2);
#endif
}

CXWebBrowser::~CXWebBrowser()
{
	m_pInPlaceActiveObj->Release();//IOleInPlaceActiveObject
	m_pInPlaceObj->Release();//IOleInPlaceObject
	m_pIWebBrowser2->Release();//IWebBrowser2
	m_pObject->Close(OLECLOSE_NOSAVE);
	m_pObject->Release();
	//有必要么
//	OleClose(m_pObject);
}

//IUnKnown

HRESULT CXWebBrowser::QueryInterface(REFIID riid, void** ppvObject)
{
	//!!!
	*ppvObject = NULL;
	if (riid == IID_IOleClientSite) * ppvObject = (IOleClientSite*)this;
	if (riid == IID_IUnknown) * ppvObject = this;
	if (riid == IID_IDispatch) * ppvObject = (IDispatch*)this;
	if (!m_bInPlaced)
	{
		if (riid == IID_IOleInPlaceSite) * ppvObject = (IOleInPlaceSite*)this;
		if (riid == IID_IOleInPlaceFrame) * ppvObject = (IOleInPlaceFrame*)this;
		if (riid == IID_IOleInPlaceUIWindow) * ppvObject = (IOleInPlaceUIWindow*)this;
	}
	if (riid == DIID_DWebBrowserEvents2) * ppvObject = (DWebBrowserEvents2*)this;
	if (riid == IID_IDocHostUIHandler) * ppvObject = (IDocHostUIHandler*)this;
	if (*ppvObject)
	{
		AddRef();
		return ERROR_SUCCESS;
	}
	else
	{
		return E_NOINTERFACE;
	}
}

ULONG CXWebBrowser::AddRef(void)
{
	InterlockedExchangeAdd((PLONG)& m_RefCount, 1);
	return ERROR_SUCCESS;
}

ULONG CXWebBrowser::Release(void)
{
#if _DEBUG
	if (InterlockedExchangeAdd((PLONG)& m_RefCount, -1) == 0) _ASSERT(0);
#else
	InterlockedExchangeAdd((PLONG)& m_RefCount, -1);
#endif
	return ERROR_SUCCESS;
}

//IDispatch

HRESULT CXWebBrowser::GetTypeInfoCount(UINT * pctinfo)
{
	return E_NOTIMPL;//貌似是不支持的意思
}

HRESULT CXWebBrowser::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo * *ppTInfo)
{
	return E_NOTIMPL;
}

HRESULT CXWebBrowser::GetIDsOfNames(REFIID riid, LPOLESTR * rgszNames, UINT cNames, LCID lcid, DISPID * rgDispId)
{
	return E_NOTIMPL;
}

HRESULT CXWebBrowser::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS * pDispParams, VARIANT * pVarResult, EXCEPINFO * pExcepInfo, UINT * puArgErr)
{
	return E_NOTIMPL;
}

//IOleWindow

HRESULT CXWebBrowser::GetWindow(HWND * phwnd)
{
	*phwnd = m_hDlg;
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::ContextSensitiveHelp(BOOL fEnterMode)
{
	return E_NOTIMPL;
}

//IOleInPlaceUIWindow

HRESULT CXWebBrowser::GetBorder(LPRECT lprectBorder)
{
	GetClientRect(m_hDlg, lprectBorder);
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::RequestBorderSpace(LPCBORDERWIDTHS pborderwidths)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::SetBorderSpace(LPCBORDERWIDTHS pborderwidths)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::SetActiveObject(IOleInPlaceActiveObject * pActiveObject, LPCOLESTR pszObjName)
{
	return ERROR_SUCCESS;
}

//IOleInPlaceFrame

HRESULT CXWebBrowser::InsertMenus(HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths)
{
	return E_NOTIMPL;
}

HRESULT CXWebBrowser::SetMenu(HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject)
{
	return E_NOTIMPL;
}

HRESULT CXWebBrowser::RemoveMenus(HMENU hmenuShared)
{
	return E_NOTIMPL;
}

HRESULT CXWebBrowser::SetStatusText(LPCOLESTR pszStatusText)
{
	return E_NOTIMPL;
}

HRESULT CXWebBrowser::EnableModeless(BOOL fEnable)
{
	return E_NOTIMPL;
}

HRESULT CXWebBrowser::TranslateAccelerator(LPMSG lpmsg, WORD wID)
{
	return TRUE;
}

//IOleClientSite

HRESULT CXWebBrowser::SaveObject(void)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker * *ppmk)
{
	*ppmk = NULL;
	return E_NOTIMPL;
}

HRESULT CXWebBrowser::GetContainer(IOleContainer * *ppContainer)
{
	*ppContainer = NULL;
	return E_FAIL;
}

HRESULT CXWebBrowser::ShowObject(void)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::OnShowWindow(BOOL fShow)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::RequestNewObjectLayout(void)
{
	return ERROR_SUCCESS;
}

//IDocHostUIHandler

HRESULT CXWebBrowser::ShowContextMenu(DWORD dwID, POINT * ppt, IUnknown * pcmdtReserved, IDispatch * pdispReserved)
{
	return TRUE;
}

HRESULT CXWebBrowser::GetHostInfo(DOCHOSTUIINFO * pInfo)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::ShowUI(DWORD dwID, IOleInPlaceActiveObject * pActiveObject, IOleCommandTarget * pCommandTarget, IOleInPlaceFrame * pFrame, IOleInPlaceUIWindow * pDoc)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::HideUI(void)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::UpdateUI(void)
{
	return ERROR_SUCCESS;
}

//EnableModeless重复了

HRESULT CXWebBrowser::OnDocWindowActivate(BOOL fActivate)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::OnFrameWindowActivate(BOOL fActivate)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::ResizeBorder(LPCRECT prcBorder, IOleInPlaceUIWindow * pUIWindow, BOOL fRameWindow)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::TranslateAccelerator(LPMSG lpMsg, const GUID * pguidCmdGroup, DWORD nCmdID)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::GetOptionKeyPath(LPOLESTR * pchKey, DWORD dw)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::GetDropTarget(IDropTarget * pDropTarget, IDropTarget * *ppDropTarget)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::GetExternal(IDispatch * *ppDispatch)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::TranslateUrl(DWORD dwTranslate, OLECHAR * pchURLIn, OLECHAR * *ppchURLOut)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::FilterDataObject(IDataObject * pDO, IDataObject * *ppDORet)
{
	return ERROR_SUCCESS;
}

//IOleInPlaceSite

HRESULT CXWebBrowser::CanInPlaceActivate(void)
{
	if (m_bInPlaced)
	{
		return S_FALSE;
	}
	else
	{
		m_bInPlaced = TRUE;
		return ERROR_SUCCESS;
	}
}

HRESULT CXWebBrowser::OnInPlaceActivate(void)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::OnUIActivate(void)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::GetWindowContext(IOleInPlaceFrame * *ppFrame, IOleInPlaceUIWindow * *ppDoc, LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo)
{
	RECT rect;

	*ppFrame = (IOleInPlaceFrame*)this;
	AddRef();
	*ppDoc = NULL;
	GetClientRect(m_hDlg, &rect);
	*lprcPosRect = rect;
	*lprcClipRect = rect;
	lpFrameInfo->cb = sizeof(OLEINPLACEFRAMEINFO);
	lpFrameInfo->hwndFrame = GetParent(m_hDlg);
	lpFrameInfo->cAccelEntries = 0;
	lpFrameInfo->fMDIApp = FALSE;
	lpFrameInfo->haccel = NULL;
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::Scroll(SIZE scrollExtant)
{
	return E_NOTIMPL;
}

HRESULT CXWebBrowser::OnUIDeactivate(BOOL fUndoable)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::OnInPlaceDeactivate(void)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::DiscardUndoState(void)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::DeactivateAndUndo(void)
{
	return ERROR_SUCCESS;
}

HRESULT CXWebBrowser::OnPosRectChange(LPCRECT lprcPosRect)
{
	return ERROR_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////
BOOL CXWebBrowser::Initialize(HWND hDlg)
{
	RECT rect;
	IConnectionPointContainer* pCPC = NULL;
	IConnectionPoint* pCP = NULL;
	DWORD dwCookie = 0;

	if (!m_bInPlaced)
	{
#if _DEBUG
		_ASSERT(IsWindow(hDlg));
#endif
		m_hDlg = hDlg;
		GetClientRect(m_hDlg, &rect);
		m_pObject->DoVerb(OLEIVERB_INPLACEACTIVATE, 0, (IOleClientSite*)this, 0, m_hDlg, &rect);
		m_pIWebBrowser2->QueryInterface(IID_IConnectionPointContainer, (void**)& pCPC);
		pCPC->FindConnectionPoint(DIID_DWebBrowserEvents2, &pCP);
		pCP->Advise((IUnknown*)(void*)this, &dwCookie);
		m_bInPlaced = TRUE;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

HWND CXWebBrowser::GetHwnd()
{
	return m_hDlg;
}

IOleObject* CXWebBrowser::GetIOleObject()
{
	return m_pObject;
}

IWebBrowser2* CXWebBrowser::GetIWebBrowser2()
{
	return m_pIWebBrowser2;
}

IOleInPlaceObject* CXWebBrowser::GetIOleInPlaceObject()
{
	return m_pInPlaceObj;
}

IOleInPlaceActiveObject* CXWebBrowser::GetIOleInPlaceActiveObject()
{
	return m_pInPlaceActiveObj;
}

BOOL CXWebBrowser::OpenUrl(PWCHAR pszUrl)
{
	BOOL bRet = FALSE;
	VARIANT vUrl;

	if (pszUrl == NULL) return bRet;
	VariantInit(&vUrl);
	vUrl.vt = VT_BSTR;
	vUrl.bstrVal = SysAllocString(pszUrl);
	if (vUrl.bstrVal)
	{
		m_pIWebBrowser2->Navigate2(&vUrl, NULL, NULL, NULL, NULL);
		VariantClear(&vUrl);
		bRet = TRUE;
	}
	return bRet;
}

VOID CXWebBrowser::DoPageAction(_PAGE_ACT eAct)
{
	switch (eAct)
	{
	case PAGE_GOBACK:
		m_pIWebBrowser2->GoBack();
		break;
	case PAGE_GOFORWARD:
		m_pIWebBrowser2->GoForward();
		break;
	case PAGE_GOHOME:
		m_pIWebBrowser2->GoHome();
		break;
	case PAGE_SEARCH:
		m_pIWebBrowser2->GoSearch();
		break;
	case PAGE_REFRESH:
		m_pIWebBrowser2->Refresh();
		break;
	case PAGE_STOP:
		m_pIWebBrowser2->Stop();
		break;
	}
	return;
}

BOOL CXWebBrowser::PutHtmlCode(PWCHAR pszCode)
{
	BOOL bRet = FALSE;
	VARIANT vUrl;
	IDispatch* pDispatch = NULL;
	IHTMLDocument2* htmlDoc2 = NULL;
	SAFEARRAY* sfArray = NULL;
	SAFEARRAYBOUND ArrayBound = { 1, 0 };
	VARIANT* pVar = NULL;

	if (pszCode == NULL) return bRet;
	__try
	{
		VariantInit(&vUrl);
		vUrl.vt = VT_BSTR;
		vUrl.bstrVal = SysAllocString(L"about:blank");
		if (!vUrl.bstrVal) __leave;
		m_pIWebBrowser2->Navigate2(&vUrl, NULL, NULL, NULL, NULL);
		VariantClear(&vUrl);
		if (m_pIWebBrowser2->get_Document(&pDispatch) != ERROR_SUCCESS) __leave;
		if (pDispatch == NULL) __leave;
		if (pDispatch->QueryInterface(IID_IHTMLDocument2, (void**)& htmlDoc2) != ERROR_SUCCESS) __leave;
		if (htmlDoc2 == NULL) __leave;
		sfArray = SafeArrayCreate(VT_VARIANT, 1, (SAFEARRAYBOUND*)& ArrayBound);
		if (sfArray == NULL) __leave;
		if (SafeArrayAccessData(sfArray, (void**)& pVar) != ERROR_SUCCESS) __leave;
		pVar->vt = VT_BSTR;
		pVar->bstrVal = SysAllocString(pszCode);
		htmlDoc2->write(sfArray);
		htmlDoc2->close();
		SafeArrayDestroy(sfArray);
		bRet = TRUE;
	}
	__finally
	{
		if (htmlDoc2) htmlDoc2->Release();
		if (pDispatch) pDispatch->Release();
	}
	return bRet;
}

BOOL CXWebBrowser::GetHtmlCode(PWCHAR pszCode, int* iszCount)
{
	BOOL bRet = FALSE;
	IDispatch* pDispatch = NULL;
	IHTMLDocument2* htmlDoc2 = NULL;
	IHTMLElement* pBodyElement = NULL;
	PWCHAR pHtmlCode = NULL;
	int iLen = 0;

	if (pszCode == NULL || iszCount == NULL) return bRet;
	__try
	{
		if (m_pIWebBrowser2->get_Document(&pDispatch) != ERROR_SUCCESS) __leave;
		if (pDispatch == NULL) __leave;
		if (pDispatch->QueryInterface(IID_IHTMLDocument2, (void**)& htmlDoc2) != ERROR_SUCCESS) __leave;
		if (htmlDoc2 == NULL) __leave;
		htmlDoc2->get_body(&pBodyElement);
		if (pBodyElement == NULL) __leave;
		pBodyElement->get_innerHTML(&pHtmlCode);
		if (pHtmlCode == NULL) __leave;
		iLen = lstrlenW(pHtmlCode) + 1;//还有个'\0'
		if (pszCode)
		{
			if (*iszCount >= iLen)
			{
				ZeroMemory(pszCode, *iszCount * sizeof(WCHAR));
				CopyMemory(pszCode, pHtmlCode, iLen * sizeof(WCHAR));
			}
		}
		else
		{
			*iszCount = iLen;
			__leave;
		}
		bRet = TRUE;
	}
	__finally
	{
		if (pBodyElement) pBodyElement->Release();
		if (htmlDoc2) htmlDoc2->Release();
		if (pDispatch) pDispatch->Release();
	}
	return bRet;
}

BOOL CXWebBrowser::ClickElementByID(PWCHAR pID)
{
	BOOL bRet = FALSE;
	IDispatch* pDispatch = NULL;
	IHTMLDocument3* htmlDoc3 = NULL;
	IHTMLElement* pElement = NULL;

	if (pID == NULL) return bRet;
	__try
	{
		if (m_pIWebBrowser2->get_Document(&pDispatch) != ERROR_SUCCESS) __leave;
		if (pDispatch == NULL) __leave;
		if (pDispatch->QueryInterface(IID_IHTMLDocument3, (void**)& htmlDoc3) != ERROR_SUCCESS) __leave;
		if (htmlDoc3 == NULL) __leave;
		htmlDoc3->getElementById(pID, &pElement);
		if (pElement == NULL) __leave;
		pElement->click();
		bRet = TRUE;
	}
	__finally
	{
		if (pElement) pElement->Release();
		if (htmlDoc3) htmlDoc3->Release();
		if (pDispatch) pDispatch->Release();
	}
	return bRet;
}

BOOL CXWebBrowser::SetElementValueByID(PWCHAR pID, PWCHAR pszValue)
{
	BOOL bRet = FALSE;
	IDispatch* pDispatch = NULL;
	IHTMLDocument3* htmlDoc3 = NULL;
	IHTMLElement* pElement = NULL;
	VARIANT variant;

	if (pID == NULL || pszValue == NULL) return bRet;
	__try
	{
		if (m_pIWebBrowser2->get_Document(&pDispatch) != ERROR_SUCCESS) __leave;
		if (pDispatch == NULL) __leave;
		if (pDispatch->QueryInterface(IID_IHTMLDocument3, (void**)& htmlDoc3) != ERROR_SUCCESS) __leave;
		if (htmlDoc3 == NULL) __leave;
		htmlDoc3->getElementById(pID, &pElement);
		if (pElement == NULL) __leave;
		VariantInit(&variant);
		variant.vt = VT_BSTR;
		variant.bstrVal = SysAllocString(pszValue);
		if (variant.bstrVal == NULL) __leave;
		pElement->setAttribute(L"value", variant);
		VariantClear(&variant);
		bRet = TRUE;
	}
	__finally
	{
		if (pElement) pElement->Release();
		if (htmlDoc3) htmlDoc3->Release();
		if (pDispatch) pDispatch->Release();
	}
	return bRet;
}

BOOL CXWebBrowser::GetElementValueByID(PWCHAR pID, PWCHAR pszValue, int* iszCount/*字符数*/)
{
	BOOL bRet = FALSE;
	IDispatch* pDispatch = NULL;
	IHTMLDocument3* htmlDoc3 = NULL;
	IHTMLElement* pElement = NULL;
	VARIANT variant;
	int iLen;

	if (iszCount == NULL) return bRet;
	__try
	{
		if (m_pIWebBrowser2->get_Document(&pDispatch) != ERROR_SUCCESS) __leave;
		if (pDispatch == NULL) __leave;
		if (pDispatch->QueryInterface(IID_IHTMLDocument3, (void**)& htmlDoc3) != ERROR_SUCCESS) __leave;
		if (htmlDoc3 == NULL) __leave;
		htmlDoc3->getElementById(pID, &pElement);
		if (pElement == NULL) __leave;
		VariantInit(&variant);
		pElement->getAttribute(L"value", 0, &variant);
		iLen = lstrlenW(variant.bstrVal) + 1;
		if (*iszCount >= iLen && pszValue)
		{
			ZeroMemory(pszValue, *iszCount * sizeof(WCHAR));
			CopyMemory(pszValue, variant.bstrVal, iLen * sizeof(WCHAR));
		}
		else
		{
			*iszCount = iLen;
			VariantClear(&variant);
			__leave;
		}
		VariantClear(&variant);
		bRet = TRUE;
	}
	__finally
	{
		if (pElement) pElement->Release();
		if (htmlDoc3) htmlDoc3->Release();
		if (pDispatch) pDispatch->Release();
	}
	return bRet;
}

