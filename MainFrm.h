// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "GameOfLife(1)View.h"

class CMainFrame : 
	public CFrameWindowImpl<CMainFrame>, 
	public CUpdateUI<CMainFrame>,
	public CMessageFilter, public CIdleHandler
{
public:
	DECLARE_FRAME_WND_CLASS(NULL, IDR_MAINFRAME)
	CGameOfLife1View m_view;

	CCommandBarCtrl m_CmdBar;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnIdle();

	BEGIN_UPDATE_UI_MAP(CMainFrame)
		UPDATE_ELEMENT(ID_VIEW_TOOLBAR, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_VIEW_STATUS_BAR, UPDUI_MENUPOPUP)
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP(CMainFrame)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		COMMAND_ID_HANDLER(ID_APP_EXIT, OnFileExit)
		COMMAND_ID_HANDLER(ID_FILE_NEW, OnFileNew)
		COMMAND_ID_HANDLER(ID_VIEW_TOOLBAR, OnViewToolBar)
		COMMAND_ID_HANDLER(ID_VIEW_STATUS_BAR, OnViewStatusBar)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		CHAIN_MSG_MAP(CUpdateUI<CMainFrame>)
		CHAIN_MSG_MAP(CFrameWindowImpl<CMainFrame>)
		COMMAND_ID_HANDLER(ID_FILE_Run, OnFileRun)
		COMMAND_ID_HANDLER(ID_GAME_Clear, OnGameClear)
		COMMAND_ID_HANDLER(ID_GAME_STOP, OnGameStop)
		MESSAGE_HANDLER(WM_TIMER, m_view.Play)
		COMMAND_ID_HANDLER(ID_RunT, OnFileRun)
		COMMAND_ID_HANDLER(ID_ClearT, OnGameClear)
		COMMAND_ID_HANDLER(ID_StopT, OnGameStop)
		COMMAND_ID_HANDLER(ID_ExitT, ExitProgram)
		COMMAND_ID_HANDLER(ID_GAME_SETSIZ, OnGameSetsiz)
		COMMAND_ID_HANDLER(ID_OptionsT, OnGameSetsiz)
		COMMAND_ID_HANDLER(IDC_STEP, OnStep)
		COMMAND_ID_HANDLER(ID_StepT, OnStep)
		COMMAND_ID_HANDLER(ID_TIMELESS_GILDER, OnTimelessGilder)
		COMMAND_ID_HANDLER(ID_FIGURES_DEFAULT, OnFiguresDefault)
		COMMAND_ID_HANDLER(ID_CLASSISCSPACESHIP_LIGHTWEIGHTSPACESHIP, OnClassiscspaceshipLightweightspaceship)
		COMMAND_ID_HANDLER(ID_CLASSISCSPACESHIP_MIDDLEWEIGHTSPACESHIP, OnClassiscspaceshipMiddleweightspaceship)
		COMMAND_ID_HANDLER(ID_CLASSICSSPACESHIP_MIDDLESPACESHIP, OnClassicsspaceshipMiddlespaceship)
		COMMAND_ID_HANDLER(ID_CLASSISCSPACESHIP_HEAVYWEIGHTSPACESHIP, OnClassiscspaceshipHeavyweightspaceship)
		COMMAND_ID_HANDLER(ID_SPACESHIPS_BRAIN, OnSpaceshipsBrain)
		COMMAND_ID_HANDLER(ID_SPACESHIPS_DART, OnSpaceshipsDart)
		COMMAND_ID_HANDLER(ID_SPACESHIPS_FLOTILLA, OnSpaceshipsFlotilla)
		COMMAND_ID_HANDLER(ID_SPACESHIPS_HIVENUDG, OnSpaceshipsHivenudg)
		COMMAND_ID_HANDLER(ID_SPACESHIPS_SCHIKENGINE, OnSpaceshipsSchikengine)
		COMMAND_ID_HANDLER(ID_SPACESHIPS_TURTLE, OnSpaceshipsTurtle)
		COMMAND_ID_HANDLER(ID_SPACESHIPS_WEEKEND, OnSpaceshipsWeekend)
		COMMAND_ID_HANDLER(ID_SPACESHIPS_SPIDER, OnSpaceshipsSpider)
		COMMAND_ID_HANDLER(ID_SPACESHIPS_PUSHALONG, OnSpaceshipsPushalong)
		COMMAND_ID_HANDLER(ID_SPACESHIPS_ORION, OnSpaceshipsOrion)
		COMMAND_ID_HANDLER(ID_SPACESHIPS_SWAN, OnSpaceshipsSwan)
		COMMAND_ID_HANDLER(ID_FILE_SAVE, OnFileSave)
		COMMAND_ID_HANDLER(ID_FILE_OPEN, OnFileOpen)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	LRESULT OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnFileNew(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnFileRun(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnGameClear(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnGameStop(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT ExitProgram(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnGameSetsiz(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	//LRESULT OnBnClickedOk(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	
	LRESULT OnStep(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnTimelessGilder(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnFiguresDefault(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnClassiscspaceshipLightweightspaceship(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnClassiscspaceshipMiddleweightspaceship(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	void AllDefault();
	LRESULT OnClassicsspaceshipMiddleweightspaceship(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnClassicsspaceshipMiddlespaceship(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnClassiscspaceshipHeavyweightspaceship(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSpaceshipsBrain(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSpaceshipsDart(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSpaceshipsFlotilla(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSpaceshipsHivenudg(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSpaceshipsSchikengine(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSpaceshipsTurtle(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSpaceshipsWeekend(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSpaceshipsSpider(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSpaceshipsPushalong(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSpaceshipsOrion(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSpaceshipsSwan(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnFileSave(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnFileOpen(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	};
