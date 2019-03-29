// XWebBrowser.h: interface for the CXWebBrowser class.
// http://blog.csdn.net/Sidyhe
//////////////////////////////////////////////////////////////////////

#ifndef	_INCLUDE_WEBBROWSEREX_FILE_H_
#define _INCLUDE_WEBBROWSEREX_FILE_H_
#pragma once
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#if _DEBUG
#include <crtdbg.h>//_ASSERT
#endif
//�г�ͻ,��Ȼ���궨����,ȡ����(WinUser.h��)
#ifdef TranslateAccelerator
#undef TranslateAccelerator
#endif

#include <oleidl.h>
#include <MsHTML.h>
#include <MSHTMHST.H>
#include <EXDISP.H>
/*
ʹ�ô���ǰ��ص���OleInitialize,�������!
*/
enum _PAGE_ACT
{
	PAGE_GOBACK,	//����
	PAGE_GOFORWARD,	//ǰ��
	PAGE_GOHOME,	//��ҳ
	PAGE_SEARCH,	//����
	PAGE_REFRESH,	//ˢ��
	PAGE_STOP		//ֹͣ
};

class CXWebBrowser ://IE�ؼ�Ҫ�̳��⼸������
	public IDispatch,
	public IOleClientSite,
	public IOleInPlaceSite,
	public IOleInPlaceFrame,
	public IDocHostUIHandler
{
public:
	CXWebBrowser(void);
	~CXWebBrowser(void);
	//////////////////////////////////////////////////////////////////////////
	// ���ǵ��Ժ���ܱ��̳�/����,����д�����,���Ǳ���Ҳʵ����
protected:
	//IUnKnown
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject);
	virtual ULONG STDMETHODCALLTYPE AddRef(void);
	virtual ULONG STDMETHODCALLTYPE Release(void);
	//IDispatch
	virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT* pctinfo);
	virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo);
	virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId);
	virtual HRESULT STDMETHODCALLTYPE Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags,
		DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr);
	//IOleWindow
	virtual HRESULT STDMETHODCALLTYPE GetWindow(HWND* phwnd);
	virtual HRESULT STDMETHODCALLTYPE ContextSensitiveHelp(BOOL fEnterMode);
	//IOleInPlaceUIWindow
	virtual HRESULT STDMETHODCALLTYPE GetBorder(LPRECT lprectBorder);
	virtual HRESULT STDMETHODCALLTYPE RequestBorderSpace(LPCBORDERWIDTHS pborderwidths);
	virtual HRESULT STDMETHODCALLTYPE SetBorderSpace(LPCBORDERWIDTHS pborderwidths);
	virtual HRESULT STDMETHODCALLTYPE SetActiveObject(IOleInPlaceActiveObject* pActiveObject, LPCOLESTR pszObjName);
	//IOleInPlaceFrame
	virtual HRESULT STDMETHODCALLTYPE InsertMenus(HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidths);
	virtual HRESULT STDMETHODCALLTYPE SetMenu(HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject);
	virtual HRESULT STDMETHODCALLTYPE RemoveMenus(HMENU hmenuShared);
	virtual HRESULT STDMETHODCALLTYPE SetStatusText(LPCOLESTR pszStatusText);
	virtual HRESULT STDMETHODCALLTYPE EnableModeless(BOOL fEnable);
	//����0,����Ӧ�س���Ϣ,��������δ֪
	virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator(LPMSG lpmsg, WORD wID);
	//IOleClientSite
	virtual HRESULT STDMETHODCALLTYPE SaveObject(void);
	virtual HRESULT STDMETHODCALLTYPE GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker** ppmk);
	virtual HRESULT STDMETHODCALLTYPE GetContainer(IOleContainer** ppContainer);
	virtual HRESULT STDMETHODCALLTYPE ShowObject(void);
	virtual HRESULT STDMETHODCALLTYPE OnShowWindow(BOOL fShow);
	virtual HRESULT STDMETHODCALLTYPE RequestNewObjectLayout(void);
	//IDocHostUIHandler
		//����0,�򲻵�������Ҽ��˵�,��������δ֪
	virtual HRESULT STDMETHODCALLTYPE ShowContextMenu(DWORD dwID, POINT* ppt, IUnknown* pcmdtReserved, IDispatch* pdispReserved);
	virtual HRESULT STDMETHODCALLTYPE GetHostInfo(DOCHOSTUIINFO* pInfo);
	virtual HRESULT STDMETHODCALLTYPE ShowUI(DWORD dwID, IOleInPlaceActiveObject* pActiveObject,IOleCommandTarget* pCommandTarget, IOleInPlaceFrame* pFrame, IOleInPlaceUIWindow* pDoc);
	virtual HRESULT STDMETHODCALLTYPE HideUI(void);
	virtual HRESULT STDMETHODCALLTYPE UpdateUI(void);
	//	HRESULT STDMETHODCALLTYPE EnableModeless(BOOL fEnable);//�ظ���
	virtual HRESULT STDMETHODCALLTYPE OnDocWindowActivate(BOOL fActivate);
	virtual HRESULT STDMETHODCALLTYPE OnFrameWindowActivate(BOOL fActivate);
	virtual HRESULT STDMETHODCALLTYPE ResizeBorder(LPCRECT prcBorder, IOleInPlaceUIWindow* pUIWindow, BOOL fRameWindow);
	virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator(LPMSG lpMsg, const GUID* pguidCmdGroup, DWORD nCmdID);
	virtual HRESULT STDMETHODCALLTYPE GetOptionKeyPath(LPOLESTR* pchKey, DWORD dw);
	virtual HRESULT STDMETHODCALLTYPE GetDropTarget(IDropTarget* pDropTarget, IDropTarget** ppDropTarget);
	virtual HRESULT STDMETHODCALLTYPE GetExternal(IDispatch** ppDispatch);
	virtual HRESULT STDMETHODCALLTYPE TranslateUrl(DWORD dwTranslate, OLECHAR* pchURLIn, OLECHAR** ppchURLOut);
	virtual HRESULT STDMETHODCALLTYPE FilterDataObject(IDataObject* pDO, IDataObject** ppDORet);
	//IOleInPlaceSite
	virtual HRESULT STDMETHODCALLTYPE CanInPlaceActivate(void);
	virtual HRESULT STDMETHODCALLTYPE OnInPlaceActivate(void);
	virtual HRESULT STDMETHODCALLTYPE OnUIActivate(void);
	virtual HRESULT STDMETHODCALLTYPE GetWindowContext(IOleInPlaceFrame** ppFrame, IOleInPlaceUIWindow** ppDoc,LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo);
	virtual HRESULT STDMETHODCALLTYPE Scroll(SIZE scrollExtant);
	virtual HRESULT STDMETHODCALLTYPE OnUIDeactivate(BOOL fUndoable);
	virtual HRESULT STDMETHODCALLTYPE OnInPlaceDeactivate(void);
	virtual HRESULT STDMETHODCALLTYPE DiscardUndoState(void);
	virtual HRESULT STDMETHODCALLTYPE DeactivateAndUndo(void);
	virtual HRESULT STDMETHODCALLTYPE OnPosRectChange(LPCRECT lprcPosRect);
private://�ڲ�˽�б���
	IStorage* m_pStorage;				//�洢������
	IOleObject* m_pObject;				//OLE����
	IOleInPlaceObject* m_pInPlaceObj;	//InPlace����
	IWebBrowser2* m_pIWebBrowser2;		//IWebBrowser2����
	HWND m_hDlg;						//��������
	BOOL m_bInPlaced;					//�Ƿ����???
	DWORD m_RefCount;					//���ü���
	IOleInPlaceActiveObject* m_pInPlaceActiveObj;
public://�����ⲿ�ɵ��ú���
	BOOL Initialize(IN HWND hDlg/*������,IE�ؼ�������*/);
	HWND GetHwnd(void);
	IOleObject* GetIOleObject(void);
	IWebBrowser2* GetIWebBrowser2(void);
	IOleInPlaceObject* GetIOleInPlaceObject(void);
	IOleInPlaceActiveObject* GetIOleInPlaceActiveObject(void);
	virtual BOOL OpenUrl(IN PWCHAR pszUrl/*Unicode*/);
	virtual VOID DoPageAction(IN _PAGE_ACT eAct);
	/*
	��HTML������ʽ��ʾ��ҳ(����ҳ)
	����:<P>����һ��ͼƬ<P><IMG src="mypic.jpg">
	ע:����Ҫ<BODY></BODY>��ǩ
	*/
	virtual BOOL PutHtmlCode(IN PWCHAR pszCode);
	virtual BOOL GetHtmlCode(OUT PWCHAR pszCode, IN OUT int* iszCount/*�ַ���*/);
	virtual BOOL ClickElementByID(PWCHAR pID);
	//���ݿؼ�ID����ֵ,�����Զ����
	virtual BOOL SetElementValueByID(IN PWCHAR pID, IN PWCHAR pszValue);
	//���ݿؼ�ID��ȡֵ
	virtual BOOL GetElementValueByID(IN PWCHAR pID, IN PWCHAR pszValue, IN OUT int* iszCount/*�ַ���*/);
};

#endif

/*
Ŀǰ�޷�ʵ�ֿ�ݼ��ĸ���/ճ���Ȳ���
�������֮һ����CreateWindowEx��������
�ں����GetMessage���������ж�
����WebBrowser��������
ճ������:(�μ�OLECMDIDö�ٽṹ)
m_pIWebBrowser2->ExecWB(OLECMDID_PASTE, OLECMDEXECOPT_DODEFAULT, NULL, NULL);
*/
