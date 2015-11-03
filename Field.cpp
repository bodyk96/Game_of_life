#include "stdafx.h"
#include "Field.h"

MyField::MyField(int rowN, int colN, int RectSizeN)
{
	row = rowN;
	col = colN;
	RectSize = RectSizeN;
	for (int i = 0; i < row*col; i++)
		arrVector.push_back(0);
}

MyField::MyField()
{
	row = 50;
	col = 20;
	RectSize = 20;
	for (int i = 0; i < row*col; i++)
		arrVector.push_back(0);
}

MyField::~MyField()
{
}

void MyField::Run()
{
	std::vector<int> arrVectorTemp;
	arrVectorTemp = CreateTemp(row, col, arrVectorTemp);
	int a = 5;
	for (int i = 0; i < row*col; i++)
	{
		int count = 0;
		if (i - row - 1 >= 0 && i + row + 1 < row*col)
		{
			if (arrVector[i - row - 1] == 1) count++;
			if (arrVector[i - row] == 1) count++;
			if (arrVector[i - row + 1] == 1)count++;
			if (arrVector[i - 1] == 1)count++;
			if (arrVector[i + row - 1] == 1) count++;
			if (arrVector[i + row] == 1) count++;
			if (arrVector[i + row + 1] == 1) count++;
			if (arrVector[i + 1] == 1) count++;
			arrVectorTemp[i] = ChkRules(arrVector[i], count);
		}
		else if (i == 0)// Ліва верхня клітинка
		{
			if (arrVector[i + 1] == 1) count++;
			if (arrVector[i + row] == 1)count++;
			if (arrVector[i + row + 1] == 1)count++;
			arrVectorTemp[i] = ChkRules(arrVector[i], count);
		}
		else if (i == row - 1)// Права верхня клітинка
		{
			if (arrVector[i - 1] == 1) count++;
			if (arrVector[i + row] == 1)count++;
			if (arrVector[i + row - 1] == 1)count++;
			arrVectorTemp[i] = ChkRules(arrVector[i], count);
		}
		else if (i == row*col - row)// Ліва нижня клітинка
		{
			if (arrVector[i - row] == 1) count++;
			if (arrVector[i - row + 1] == 1)count++;
			if (arrVector[i + 1] == 1)count++;
			arrVectorTemp[i] = ChkRules(arrVector[i], count);
		}
		else if (i == row*col - 1)// Права нижня клітинка
		{
			if (arrVector[i - 1] == 1) count++;
			if (arrVector[i - row] == 1)count++;
			if (arrVector[i - row - 1] == 1)count++;
			arrVectorTemp[i] = ChkRules(arrVector[i], count);
		}
		else if (i > 0 && i < row - 1)//Верхній рядок
		{
			if (arrVector[i - 1] == 1) count++;
			if (arrVector[i + 1] == 1) count++;
			if (arrVector[i + row - 1] == 1)count++;
			if (arrVector[i + row] == 1)count++;
			if (arrVector[i + row + 1] == 1) count++;
			arrVectorTemp[i] = ChkRules(arrVector[i], count);
		}
		else if (i >= row && i <= row*col - 2 * row && i % row == 0)//Лівий рядок
		{
			if (arrVector[i - row] == 1) count++;
			if (arrVector[i - row + 1] == 1) count++;
			if (arrVector[i + 1] == 1)count++;
			if (arrVector[i + row] == 1)count++;
			if (arrVector[i + row + 1] == 1) count++;
			arrVectorTemp[i] = ChkRules(arrVector[i], count);
		}
		else if (i >= (2 * row) - 1 && i <= (row*col - row - 1) && (((i + 1) % row) == 0))//Правий рядок
		{
			if (arrVector[i - row] == 1) count++;
			if (arrVector[i - row - 1] == 1) count++;
			if (arrVector[i - 1] == 1)count++;
			if (arrVector[i + row - 1] == 1)count++;
			if (arrVector[i + row] == 1) count++;
			arrVectorTemp[i] = ChkRules(arrVector[i], count);
		}
		else if (i > row*col - row)//Нижній рядок
		{
			if (arrVector[i - 1] == 1) count++;
			if (arrVector[i + 1] == 1) count++;
			if (arrVector[i - row] == 1)count++;
			if (arrVector[i - row - 1] == 1)count++;
			if (arrVector[i - row + 1] == 1) count++;
			arrVectorTemp[i] = ChkRules(arrVector[i], count);
		}
	}


	for (int i = 0; i < row*col; i++)
		arrVector[i] = arrVectorTemp[i];
}

void MyField::Clear()
{
	for (std::vector<int>::iterator i = arrVector.begin(); i < arrVector.end(); i++)
		*i = 0;
}



void MyField::DrawField(CPaintDC &dc)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			SetDCPenColor(dc, RGB(0, 0, 0));
			SetDCBrushColor(dc, RGB(255, 255, 255));
			dc.Rectangle(i * RectSize, j * RectSize,
				i * RectSize + RectSize, j * RectSize + RectSize);
			if (arrVector[row*j + i] == 1) 
			{
				SetColor(dc);
				DrawRectByCoordanates(dc, i, j);
				SetDefaultColor(dc);
			}
		}
	}
	SetDCPenColor(dc, RGB(0, 0, 0));
	SetDCBrushColor(dc, RGB(0, 0, 0));
}

void MyField::DrawRect(CPoint pos, int &tempX, int &tempY, bool isDrawRect)
{
	arrVector[row * tempY + tempX] = isDrawRect ? 1 : 0;
}

void MyField::SetSize(int rowN, int colN)
{
	row = rowN;
	col = colN;
}

void MyField::RedrawRect(CPaintDC &dc)
{
	SetColor(dc);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arrVector[row*j + i] == 1)
			{
				DrawRectByCoordanates(dc, i, j);
			}
		}
	}
	SetDefaultColor(dc);
}

bool MyField::isRectDraw(int x, int y)
{
	return arrVector[row * y + x] == 1 ? true : false;
}

int MyField::ChkRules(int num, int count)
{
	int answer = 0;
	if (num == 0 && count == 3)
		return 1;

	if (num == 1)
		if (count == 2 || count == 3)
			return 1;
		else if (count <= 1 || count >= 4)
			return 0;

	return answer;
}

void MyField::ChangeParams(int rowN, int colN)
{
	for (int i = 0; i < rowN; i++)
		for (int j = 0; j < colN; j++)
			arrVector.push_back(0);
}

std::vector<int> MyField::CreateTemp(int row, int col, std::vector<int> arrVectorTemp)
{
	for (int i = 0; i < row*col; i++)
		arrVectorTemp.push_back(0);
	return arrVectorTemp;
}

void MyField::SetDefaultColor(CPaintDC &dc)
{
	SetDCPenColor(dc, RGB(0, 0, 0));
	SetDCBrushColor(dc, RGB(255, 255, 255));
}

void MyField::DrawRectByCoordanates(CPaintDC & dc, int i, int j)
{
	dc.Rectangle(i * RectSize, j * RectSize,
		i * RectSize + RectSize, j * RectSize + RectSize);
}

bool MyField::isClickOnField(CPoint pos)
{
	return pos.x >= RectSize * row || pos.y >= RectSize * col ? false : true;
}

void MyField::SetColor(CPaintDC &dc)
{
	SelectObject(dc, GetStockObject(DC_PEN));
	SetDCPenColor(dc, RGB(70, 30, 90));
	SelectObject(dc, GetStockObject(DC_BRUSH));
	SetDCPenColor(dc, RGB(0, 0, 0));
	SetDCBrushColor(dc, RGB(255, 255, 255));
	SetDCBrushColor(dc, RGB(70, 30, 90));
}
