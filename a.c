#pragma comment(lib,"user32")
#pragma comment(lib,"gdi32")
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
HWND WINAPI GetConsoleWindow();
HDC set_pen(int a, int b, int c, int d)
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);		
	HPEN hPen;
	hPen = CreatePen(PS_INSIDEFRAME, d, RGB(a, b, c));
	SelectObject(hdc, hPen);
	return hdc;
}
void print_image(int how_much[])
{
	int x_offset = 1000;
	int y_offset = 1000;
	int x_border = 1600;
	HDC hdc1 = set_pen(255, 0, 0, 3);
	HDC hdc2 = set_pen(255, 0, 255, 3);
	HDC hdc3 = set_pen(255, 255, 0, 3);
	HDC hdc4 = set_pen(0, 255, 0, 3);
	HDC hdc5 = set_pen(0, 0, 255, 3);
	MoveToEx(hdc1, x_offset, y_offset, NULL);
	LineTo(hdc1, x_border, y_offset);
	int maxn = 0;
	for (int i = 1; i < 6; i++)
	{
		if (how_much[i] > maxn)
			maxn = how_much[i];
	}
	int seg = 120;
	Rectangle(hdc1,
		x_offset + seg / 4,
		y_offset - (int)((float)how_much[1] * 400.0 / maxn),
		x_offset + seg / 4 * 3,
		y_offset);
	Rectangle(hdc2,
		x_offset + seg + seg / 4,
		y_offset - (int)((float)how_much[2] * 400.0 / maxn),
		x_offset + seg + seg / 4 * 3,
		y_offset);
	Rectangle(hdc3,
		x_offset + seg * 2 + seg / 4,
		y_offset - (int)((float)how_much[3] * 400.0 / maxn),
		x_offset + seg * 2 + seg / 4 * 3,
		y_offset);
	Rectangle(hdc4,
		x_offset + seg * 3 + seg / 4,
		y_offset - (int)((float)how_much[4] * 400.0 / maxn),
		x_offset + seg * 3 + seg / 4 * 3,
		y_offset);
	Rectangle(hdc5,
		x_offset + seg * 4 + seg / 4,
		y_offset - (int)((float)how_much[5] * 400.0 / maxn),
		x_offset + seg * 4 + seg / 4 * 3,
		y_offset);
	getchar();
	getchar();
	return;
}
int main() {
	int b[6];
	float a[6];
	a[1] = 1.0;
	a[2] = 2.0;
	a[3] = 3.0;
	a[4] = 4.0;
	a[5] = 5.0;
	for (int i = 1; i <= 5; i++) b[i] = (int)a[i];
	printf("***********************************************************\nasdawdaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\nasdddddddddddddddddddddddddddddddddddddddddddddddddddd\n");
	getchar();
	print_image(b);
	
}
