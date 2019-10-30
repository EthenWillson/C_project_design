#include "score_j.h"
#include "common_c.h"

void DrawscoreScreen_j(setuser* person,int *judge,setuser* head)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变量
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();

    while(1)
    {
        newxy(&mx,&my,&buttons);
        //if()
    }

}