// GameOfLife(1)View.cpp : implementation of the CGameOfLife1View class
//
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "resource.h"
#include "GameOfLife(1)View.h"
#include <thread>
#include "Field.h"
#include "MainFrm.h"
//#include "SetSizeDialog.h"
#include <fstream>


BOOL CGameOfLife1View::PreTranslateMessage(MSG* pMsg)
{
	pMsg;
	return FALSE;
}
bool flag = true;


LRESULT CGameOfLife1View::OnPaint(UINT uMsg, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	//TODO: Add your drawing code here
	CPaintDC dc(m_hWnd);
	field.SetSize(row, col);
	field.RectSize = RectSize;
	field.DrawField(dc);

	if (uMsg == WM_ERASEBACKGROUND)
		field.DrawField(dc);
	else if (uMsg == WM_PAINT)
		field.RedrawRect(dc);
	return 0;
}

LRESULT CGameOfLife1View::OnRButtonDown(UINT nFlags, CPoint pos)
{
	GetPosition(pos);
	field.DrawRect(pos, tempX, tempY, false);
	RedrawWindow();
	return 0;
}

LRESULT CGameOfLife1View::OnLButtonDown(UINT nFlags, CPoint pos)
{
	GetPosition(pos);
	field.DrawRect(pos, tempX, tempY, true);
	RedrawWindow();

	return 0;
}

LRESULT CGameOfLife1View::OnMouseMove(UINT nFlags, CPoint pos)
{
	
	if (nFlags == MK_LBUTTON)
	{
		GetPosition(pos);
		if(!field.isRectDraw(tempX, tempY))
			OnLButtonDown(nFlags, pos);
	}
	else if (nFlags == MK_RBUTTON)
	{
		GetPosition(pos);
		if(field.isRectDraw(tempX, tempY))
			OnRButtonDown(nFlags, pos);
	}
	return 0;
}


LRESULT CGameOfLife1View::OnCreate(LPCREATESTRUCT pCreate)
{
	SetTimer(1, 1000);
	SetMsgHandled(false);
	return 0;
}

LRESULT CGameOfLife1View::Play(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	field.Run();
	RedrawWindow();
	if (stop)KillTimer(IDT_TIMER1);
	return 0;
}

void CGameOfLife1View::GameClear()
{
	field.Clear();
	KillTimer(IDT_TIMER1);
	RedrawWindow();
}

void CGameOfLife1View::CreateVector()
{
	for (int i = 0; i < field.row*field.col * 10; i++)
		arrVector.push_back(0);
}


LRESULT CGameOfLife1View::Save()
{
	using namespace std;
	LPTSTR url;
	LPCTSTR szFilter(L"Text files (*.txt)|*.txt|");
	LPTSTR s1 = { L" " };
	// TODO: Add your command handler code here
	CFileDialog lg1(FALSE, L"txt", L"life_game_files", OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
		L"Camera Data Files (*.txt)|*.txt|*.dat||", m_hWnd);
	if (lg1.DoModal() == IDOK) {

		url = lg1.m_ofn.lpstrFile;
		char a[1024];
		string d;


		int i = 0;
		for (i = 0; i <= 1024; i++) {
			if (!url[i]) break;
		}
		for (int j = 0; j < i; j++) {
			d += url[j];
		}
		ofstream fout(d);
		fout << row << "/" << col << "/" << RectSize << "/" << seconds;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (field.arrVector[row*j + i] == 1)
				{
					fout << "1";
				}
				else
				{
					fout << "0";
				}
			}
		}

	}
	return 0;
}

LRESULT CGameOfLife1View::Open()
{
	using namespace std;
	LPTSTR url;
	LPCTSTR szFilter(L"Text files (*.txt)|*.txt|");
	LPTSTR s1 = { L" " };
	// TODO: Add your command handler code here
	CFileDialog lg1(TRUE, L"txt", L"vicon_cams_data", OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
		L"Camera Data Files (*.txt)|*.txt|*.dat||", m_hWnd);
	if (lg1.DoModal() == IDOK) {

		url = lg1.m_ofn.lpstrFile;
		char a[1024];
		string d;
		int i = 0;
		for (i = 0; i <= 1024; i++) {
			if (!url[i]) break;
		}
		for (int j = 0; j < i; j++) {
			d += url[j];
		}
		char bv;
		ifstream fin(d);

		fin >> row >> a >> col >> a >> a >> RectSize >> a >> seconds >> a;
		RedrawWindow();
		/*int j = 6;
		for (int z = 0; z < x_main / size_of_rect; z++) {
			for (j; j < y_main / size_of_rect; j++) {
				fin >> that.cont[that.ret_index(z, j, 1)] >> a;
			}
			j = 0;
		}*/
		char b;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				fin >> b;
				if (b == '0')
					field.arrVector[row*j + i] = 0;
				else if(b == '1')
					field.arrVector[row*j + i] = 1;
			}
			fin >> a;
		}
	}
	RedrawWindow();
	return 0;
}

void CGameOfLife1View::ChangeFieldParams(int col, int row, int RectSize)
{
	this->col = (col == 0) ? this->col : col;
	this->row = (row == 0) ? this->row : row;
	this->RectSize = RectSize == 0 ? this->RectSize : RectSize;
	field.ChangeParams(row, col);
	RedrawWindow();
}

void CGameOfLife1View::GetPosition(CPoint pos)
{
	if (!field.isClickOnField(pos))
		return;
	tempX = pos.x / RectSize;
	tempY = pos.y / RectSize;
}
