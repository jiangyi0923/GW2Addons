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
//有冲突,居然被宏定义了,取消掉(WinUser.h中)
#ifdef TranslateAccelerator
#undef TranslateAccelerator
#endif

#include <oleidl.h>
#include <MsHTML.h>
#include <MSHTMHST.H>
#include <EXDISP.H>
/*
使用此类前务必调用OleInitialize,否则出错!
*/
enum _PAGE_ACT
{
	PAGE_GOBACK,	//后退
	PAGE_GOFORWARD,	//前进
	PAGE_GOHOME,	//主页
	PAGE_SEARCH,	//搜索
	PAGE_REFRESH,	//刷新
	PAGE_STOP		//停止
};

class CXWebBrowser ://IE控件要继承这几个基类
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
	// 考虑到以后可能被继承/重载,所以写成虚的,但是本身也实现了
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
	//返回0,则不相应回车消息,其他功能未知
	virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator(LPMSG lpmsg, WORD wID);
	//IOleClientSite
	virtual HRESULT STDMETHODCALLTYPE SaveObject(void);
	virtual HRESULT STDMETHODCALLTYPE GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker** ppmk);
	virtual HRESULT STDMETHODCALLTYPE GetContainer(IOleContainer** ppContainer);
	virtual HRESULT STDMETHODCALLTYPE ShowObject(void);
	virtual HRESULT STDMETHODCALLTYPE OnShowWindow(BOOL fShow);
	virtual HRESULT STDMETHODCALLTYPE RequestNewObjectLayout(void);
	//IDocHostUIHandler
		//返回0,则不弹出鼠标右键菜单,其他功能未知
	virtual HRESULT STDMETHODCALLTYPE ShowContextMenu(DWORD dwID, POINT* ppt, IUnknown* pcmdtReserved, IDispatch* pdispReserved);
	virtual HRESULT STDMETHODCALLTYPE GetHostInfo(DOCHOSTUIINFO* pInfo);
	virtual HRESULT STDMETHODCALLTYPE ShowUI(DWORD dwID, IOleInPlaceActiveObject* pActiveObject,IOleCommandTarget* pCommandTarget, IOleInPlaceFrame* pFrame, IOleInPlaceUIWindow* pDoc);
	virtual HRESULT STDMETHODCALLTYPE HideUI(void);
	virtual HRESULT STDMETHODCALLTYPE UpdateUI(void);
	//	HRESULT STDMETHODCALLTYPE EnableModeless(BOOL fEnable);//重复了
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
private://内部私有变量
	IStorage* m_pStorage;				//存储根对象
	IOleObject* m_pObject;				//OLE对象
	IOleInPlaceObject* m_pInPlaceObj;	//InPlace对象
	IWebBrowser2* m_pIWebBrowser2;		//IWebBrowser2对象
	HWND m_hDlg;						//窗口容器
	BOOL m_bInPlaced;					//是否替代???
	DWORD m_RefCount;					//引用计数
	IOleInPlaceActiveObject* m_pInPlaceActiveObj;
public://公开外部可调用函数
	BOOL Initialize(IN HWND hDlg/*窗体句柄,IE控件的容器*/);
	HWND GetHwnd(void);
	IOleObject* GetIOleObject(void);
	IWebBrowser2* GetIWebBrowser2(void);
	IOleInPlaceObject* GetIOleInPlaceObject(void);
	IOleInPlaceActiveObject* GetIOleInPlaceActiveObject(void);
	virtual BOOL OpenUrl(IN PWCHAR pszUrl/*Unicode*/);
	virtual VOID DoPageAction(IN _PAGE_ACT eAct);
	/*
	以HTML代码形式显示网页(新网页)
	例如:<P>这是一个图片<P><IMG src="mypic.jpg">
	注:不需要<BODY></BODY>标签
	*/
	virtual BOOL PutHtmlCode(IN PWCHAR pszCode);
	virtual BOOL GetHtmlCode(OUT PWCHAR pszCode, IN OUT int* iszCount/*字符数*/);
	virtual BOOL ClickElementByID(PWCHAR pID);
	//根据控件ID设置值,用于自动填表
	virtual BOOL SetElementValueByID(IN PWCHAR pID, IN PWCHAR pszValue);
	//根据控件ID获取值
	virtual BOOL GetElementValueByID(IN PWCHAR pID, IN PWCHAR pszValue, IN OUT int* iszCount/*字符数*/);
};

#endif

/*
目前无法实现快捷键的复制/粘贴等操作
解决方法之一是用CreateWindowEx创建窗体
在后面的GetMessage中做按键判断
再向WebBrowser发送命令
粘贴命令:(参见OLECMDID枚举结构)
m_pIWebBrowser2->ExecWB(OLECMDID_PASTE, OLECMDEXECOPT_DODEFAULT, NULL, NULL);
*/
