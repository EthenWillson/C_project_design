#include"customer_j.h"
#include"common_c.h"

void DrawbuyScreen_j(setuser *person,int *judge,setuser *head);
void DrawcheckScreen_j(setuser *person,int *judge,setuser *head);
void DrawchargeScreen_j(setuser *person,int *judge,setuser *head);

void DrawbuyScreen_j(setuser *person,int *judge,setuser *head)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
    mouseInit(&mx, &my, &buttons);
	cleardevice();
    setbkcolor(WHITE);
	DrawBeautifulFrame_c();

    //画出返回按钮
	returnBtn_c(300,400,GREEN);


    setcolor(BROWN);
    outtextxy(28,76,"1");
    puthz(35,71,"号线",16,16,BROWN);

    outtextxy(28,231,"2");
    puthz(35,226,"号线",16,16,BROWN);

    outtextxy(28,386,"3");
    puthz(35,381,"号线",16,16,BROWN);

    puthz(220,32,"武汉地铁交通线",32,32,BROWN);

    setlinestyle(0, 0, 3);
    setcolor(YELLOW);
    //1号线的线路
    circle(80,80,8);
    circle(80,80,7);
    circle(136,80,8);
    circle(136,80,7);//x+56
    circle(192,80,8);
    circle(192,80,7);
    circle(248,80,8);
    circle(248,80,7);
    circle(304,80,8);
    circle(304,80,7);
    circle(360,80,8);
    circle(360,80,7);
    circle(416,80,8);
    circle(416,80,7);
    circle(472,80,8);
    circle(472,80,7);
    circle(528,80,7);
    circle(528,80,7);
    setcolor(GREEN);//x1+10,x2-10
    line(90,80,126,80);
    line(146,80,182,80);
    line(202,80,238,80);
    line(258,80,294,80);
    line(314,80,350,80);
    line(370,80,406,80);
    line(426,80,462,80);
    line(482,80,518,80);

    setcolor(YELLOW);
    //2号线的线路
    circle(80,235,8);
    circle(80,235,7);
    circle(150,235,8);
    circle(150,235,7);





    while(1)
	{
		newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 300 && mx <= 360 && my >= 400&& my <= 460 && buttons)//返回按钮点击返回
			{
				*judge=turnTo_c(person,3);
				return;
			}
        }
    }
}

void DrawcheckScreen_j(setuser *person,int *judge,setuser *head)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
    mouseInit(&mx, &my, &buttons);
	cleardevice();
    setbkcolor(WHITE);
	DrawBeautifulFrame_c();

    //画出返回按钮
	returnBtn_c(300,400,GREEN);

    while (1)
    {
        newxy(&mx, &my, &buttons);  
        if(buttons)
        {
            if (mx >= 300 && mx <= 360 && my >= 400&& my <= 460 && buttons)//返回按钮点击返回
			{
				*judge=turnTo_c(person,3);
				return;
			}
        }
    }
    
}

void DrawchargeScreen_j(setuser *person,int *judge,setuser *head)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
    mouseInit(&mx, &my, &buttons);
	cleardevice();
    setbkcolor(WHITE);
	DrawBeautifulFrame_c();
    //画出返回按钮
	returnBtn_c(300,400,GREEN);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 300 && mx <= 360 && my >= 400&& my <= 460 && buttons)//返回按钮点击返回
			{
				*judge=turnTo_c(person,3);
				return;
			}
        }  
    }
    
}