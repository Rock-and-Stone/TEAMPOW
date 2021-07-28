#pragma once

//�� �׷��ִ� �Լ�    (�ѷ��� DC, ������ X, Y, ���� X, Y)
inline void LineMake(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

inline POINT PointMake(int x, int y)
{
	POINT pt = { x, y };

	return pt;
}


//��Ʈ���� ��ũ��
inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };

	return rc;
}

inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - (width /2 ), y - (height / 2), x + (width / 2), y + (height / 2) };

	return rc;
}

inline void Rectangle(HDC hdc, RECT& rc)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

//�簢�� �׷��ִ� ��ũ���Լ� (�ѷ���DC, ������ X(left), ������Y(top), ����ũ��, ����ũ��)
inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

//�簢�� �׷��ִ� ��ũ���Լ� (�ѷ���DC, ����X(left), ����Y(top), ����ũ��, ����ũ��)
inline void RectangleMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}

inline void Ellipse(HDC hdc, RECT& rc)
{
	Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

//�� �׷��ִ� ��ũ���Լ� (�ѷ���DC, ������ X(left), ������Y(top), ����ũ��, ����ũ��)
inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

//�� �׷��ִ� ��ũ���Լ� (�ѷ���DC, ����X(left), ����Y(top), ����ũ��, ����ũ��)
inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}