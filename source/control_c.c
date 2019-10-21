#include"control_c.h"
#include"common_c.h"
void otherEvent()//其它事件，如鼠标的更新和点击事件等
{
    newxy(&mx, &my, &buttons);
	if(buttons)//点击事件
	{
		if (mx >= 585 && mx <= 615 && my >= 5&& my <= 45)//退出按钮点击退出
		{
			*judge=turnTo_c(person,2);
			return;
		}
	}
}
void drawControlScreen(setuser *person,int *judge,setuser *head)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
	int i;//划线循环变量
    setTrainInfo Info[2];//记录两条线调度的相关参数
	// 初始化
	// 鼠标初始化
	mouseInit(&mx, &my, &buttons);
	cleardevice();

	// //绘制地铁线路









	
	while(1)
	{
		otherEvent();
	}
}