#include"control_c.h"
#include"common_c.h"

void drawControlScreen(setuser *person,int *judge,setuser *head)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
	// 初始化
	// 鼠标初始化
	mouseInit(&mx, &my, &buttons);
	cleardevice();
	setbkcolor(WHITE);
	
	while(1)
	{
		newxy(&mx, &my, &buttons);
		if(buttons)//点击事件
		{
			if (mx >= 585 && mx <= 615 && my >= 5&& my <= 45)//退出按钮点击退出
			{
				*judge=turnTo_c(person,1);
				return;
			}
		}
	}
}