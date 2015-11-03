// GameOfLife(1)View.h : interface of the CGameOfLife1View class
//
/////////////////////////////////////////////////////////////////////////////
#include<vector>
#pragma once
#include "Set_Size.h"
#include "Field.h"

class CGameOfLife1View : public CWindowImpl<CGameOfLife1View>
{
public:
	DECLARE_WND_CLASS(NULL)

	BOOL PreTranslateMessage(MSG* pMsg);

	BEGIN_MSG_MAP(CGameOfLife1View)
		MSG_WM_RBUTTONDOWN(OnRButtonDown)
		MSG_WM_LBUTTONDOWN(OnLButtonDown)
		MESSAGE_HANDLER(WM_ERASEBKGND, OnPaint);
		MSG_WM_MOUSEMOVE(OnMouseMove)
		MESSAGE_HANDLER(WM_ERASEBACKGROUND, OnPaint)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		MSG_WM_CREATE(OnCreate)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
	LRESULT Play(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	
	void GameClear();
	void CreateVector();
	LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnLButtonDown(UINT nFlags, CPoint pos);
	LRESULT OnRButtonDown(UINT nFlags, CPoint pos);
	LRESULT OnMouseMove(UINT nFlags, CPoint pos);
	LRESULT OnCreate(LPCREATESTRUCT pCreate);
	LRESULT Save();
	LRESULT Open();
	void ChangeFieldParams(int col, int row, int RectSize);

	bool isRunning = true;
	int RectSize = 20;
	int row = 50;
	int col = 20;
	bool stop = false;
	BOOL ab = false;
	std::vector<int> arrVector = { 0 };
	int tempX = 100;
	int tempY = 100;
	bool isMouseUp = true;
	UINT seconds = 50;
	void GetPosition(CPoint pos);

	MyField field;
	//«м≥нн≥ шаблон≥в ф≥гур
	bool Glider = false;
	bool LightSpace = false;
	bool MiddleSpace = false;
	bool HeavySpace = false;
	bool Brain = false;
	bool Dart = false;
	bool Flotilla = false;
	bool Hivenudg = false;
	bool SchickEngine = false;
	bool Turtle = false;
	bool Weekend = false;
	bool Spider = false;
	bool Pushalong = false;
	bool Orion = false;
	bool Swan = false;
};
