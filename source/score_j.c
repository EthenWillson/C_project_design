#include "score_j.h"
#include "common_c.h"
/**********************************************************
Function:  DrawscoreScreen
Description：	画出积分兑换界面
Attention:  无
**********************************************************/
void DrawscoreScreen_j(setuser* person,int *judge,setuser* head)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变量
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(550, 210, GREEN);

    while(1)
    {
        newxy(&mx,&my,&buttons);
        if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //返回按钮点击返回
        {
            *judge = turnTo_c(person, 6);
            return;
        }
    }

}