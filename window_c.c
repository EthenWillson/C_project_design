/**********************************************************
Description： 此文件专门存放弹出框体相关的函数
Attention:  必须要用GB2312编码保存，不然汉字会有乱码
Author：陈俊玮
**********************************************************/
#include"window_c.h"
/***********************************************************
Function: Choose_c
Description:选择框
Input:选择内容content,提示框坐标指针mx,my，提示字体颜色color
return:点击“是”返回1，点击“否”返回0
**********************************************************/
int Choose_c(char *contentOne,char *contentTwo, int *mx, int *my, int color)
{
	int buttons;

	setcolor(LIGHTCYAN);
	setfillstyle(1, WHITE);
	bar(200, 160, 420, 300);
	rectangle(200, 160, 420, 300);
	puthz(240, 200, contentOne, 16, 16, color);
	puthz(240, 223, contentTwo, 16, 16, color);

	setfillstyle(1, LIGHTGRAY);
	bar(233, 248, 267, 272);
	bar(358, 248, 392, 272);
	rectangle(233, 248, 267, 272);
	rectangle(358, 248, 392, 272);
	setlinestyle(1, 0, 1);
	rectangle(235, 250, 265, 270);
	rectangle(360, 250, 390, 270);
	setlinestyle(3, 0, 1);
	rectangle(202, 162, 418, 298);
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	puthz(240, 252, "是", 16, 16, GREEN);
	puthz(365, 252, "否", 16, 16, LIGHTRED);


	while (1)
	{
		newxy(mx, my, &buttons);

		if (*mx >= 240 && *mx <= 256 && *my >= 252 && *my <= 268 && buttons)
			return 1;//是
		else if (*mx >= 365 && *mx <= 381 && *my >= 252 && *my <= 268 && buttons)
			return 0;//否
	}
}