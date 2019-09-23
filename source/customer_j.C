#include"customer_j.h"
#include"common_c.h"

void DrawbuyScreen_j(setuser *person,int *judge,setuser *head);
void DrawcheckScreen_j(setuser *person,int *judge,setuser *head);
void DrawchargeScreen_j(setuser *person,int *judge,setuser *head);

void DrawbuyScreen_j(setuser *person,int *judge,setuser *head)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
    int i;//划线循环变量
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
    for(i=0;i<=7;i++)
    {
        line(90+56*i,80,126+56*i,80);
    }
    
    setcolor(YELLOW);
    //2号线的线路
    circle(80,235,8);
    circle(80,235,7);
    circle(150,235,8);
    circle(150,235,7);
    circle(220,235,8);
    circle(220,235,7);
    circle(290,235,8);
    circle(290,235,7);
    circle(360,235,8);
    circle(360,235,7);
    circle(430,235,8);
    circle(430,235,7);
    circle(500,235,8);
    circle(500,235,7);
    setcolor(GREEN);
    for(i=0;i<6;i++)
    {
        line(90+70*i,235,140+70*i,235);
    }

    puthz(72,245,"杨",16,16,BROWN);
    puthz(72,263,"家",16,16,BROWN);
    puthz(72,281,"湾",16,16,BROWN);
    puthz(142,245,"光",16,16,BROWN);
    puthz(142,263,"谷",16,16,BROWN);
    puthz(142,281,"广",16,16,BROWN);
    puthz(142,299,"场",16,16,BROWN);
    puthz(212,245,"珞",16,16,BROWN);
    puthz(212,263,"雄",16,16,BROWN);
    puthz(212,281,"路",16,16,BROWN); 
    puthz(282,245,"华",16,16,BROWN);
    puthz(282,263,"中",16,16,BROWN);
    puthz(282,281,"科",16,16,BROWN);
    puthz(282,299,"技",16,16,BROWN);
    puthz(282,317,"大",16,16,BROWN);
    puthz(282,335,"学",16,16,BROWN);
    

    setcolor(YELLOW);
    //3号线的线路
    circle(80,390,8);
    circle(80,390,7);
    circle(136,390,8);
    circle(136,390,7);//x+56
    circle(192,390,8);
    circle(192,390,7);
    circle(248,390,8);
    circle(248,390,7);
    circle(304,390,8);
    circle(304,390,7);
    circle(360,390,8);
    circle(360,390,7);
    circle(416,390,8);
    circle(416,390,7);
    circle(472,390,8);
    circle(472,390,7);
    circle(528,390,7);
    circle(528,390,7);
    setcolor(GREEN);
    for(i=0;i<=7;i++)
    {
        line(90+56*i,390,126+56*i,390);
    }

    line(198,88,284,227);
    line(296,243,410,382);
    

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