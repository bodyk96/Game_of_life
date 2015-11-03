#include <vector>
#pragma once
class MyField
{
public:
	MyField();
	MyField(int row, int col, int RectSize);
	~MyField();
	void Run();
	void Clear();
	void DrawField(CPaintDC &dc);
	void DrawRect(CPoint pos, int &tempX, int &tempY,bool isDrawRect);
	int row;
	int col;
	int RectSize;
	std::vector<int> arrVector = { 0 };
	void SetSize(int rowN, int colN);
	void RedrawRect(CPaintDC &dc);
	bool isRectDraw(int x, int y);
	std::vector<int> CreateTemp(int row, int col, std::vector<int> arrVectorTemp);
	void SetColor(CPaintDC &dc);
	void SetDefaultColor(CPaintDC &dc);
	void DrawRectByCoordanates(CPaintDC &dc, int i, int j);
	bool isClickOnField(CPoint pos);
	bool isChangeField = false;
	void ChangeParams(int rowN, int colN);
private:
	bool isDrawRect;
	int ChkRules(int num, int count);
};