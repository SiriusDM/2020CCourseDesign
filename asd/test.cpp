#include <stdio.h>
#include <windows.h>
extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow();
HDC set_pen(int a,int b,int c,int d)
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc=GetDC(hwnd);//获取图形设备接口		
	HPEN hPen;
	hPen=CreatePen(PS_INSIDEFRAME,d,RGB(a,b,c));
	SelectObject(hdc,hPen);
	return hdc;
}
void print_image(char who[][20],int how_much[],int counter)
{
	int x_offset=500;
	int y_offset=500;
	int x_border=1100;
	HDC hdc1=set_pen(255,255,255,3);
	MoveToEx(hdc1,x_offset,y_offset,NULL);
	LineTo(hdc1,x_border,y_offset);
	int maxn=0;
	for(int i=0;i<counter;i++)
	{
		if(how_much[i]>maxn)
			maxn=how_much[i];
	}
	int seg=600/counter;
	for(int i=0;i<counter;i++)
	{
		Rectangle(hdc1,
			x_offset+seg*i+seg/4,
			y_offset-int((float)how_much[i]*400.0/maxn),
			x_offset+seg*i+seg/4*3,
			y_offset);
	}
	getchar();
	getchar();
	return;
}
