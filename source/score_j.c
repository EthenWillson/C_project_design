/**********************************************************
Description： 此文件专门存放积分商城相关的函数
Attention:  必须要用GB2312编码保存，不然汉字会有乱码
Author：陈俊玮
**********************************************************/
#include "score_j.h"
#include "common_c.h"
/**********************************************************
Function:  DrawBag
Description：	画出购物袋
Attention:  无
**********************************************************/
void DrawBag(int x,int y,int lcolor)
{
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setcolor(lcolor);
    setfillstyle(1,lcolor);
    line(x+40,y+80,x+140,y+80);
    line(x+40,y+80,x+40,y+190);
    line(x+140,y+80,x+140,y+190);
    line(x+40,y+190,x+140,y+190);
    line(x+50,y+180,x+130,y+180);
    ellipse(x+90,y+75,360,180,37,52);
    ellipse(x+90,y+75,360,180,29,45);
}
/**********************************************************
Function:  DrawTrolly
Description：	画出购物推车
Attention:  无
**********************************************************/
void DrawTrolly(int x,int y,int lcolor)
{
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setcolor(lcolor);
    setfillstyle(1,lcolor);
    line(x,y+80,x+25,y+80);
    line(x+31,y+115,x+130,y+115);
    line(x+25,y+80,x+45,y+170);
    line(x+130,y+115,x+116,y+170);
    line(x+45,y+170,x+116,y+170);
    circle(x+50,y+188,10);
    circle(x+111,y+188,10);
}
/**********************************************************
Function:  DrawMineGFrame
Description：	画出我的兑换图标
Attention:  无
**********************************************************/
void DrawMineGFrame(int x,int y,int bkcolor,int lcolor)
{
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setcolor(bkcolor);
    setfillstyle(1,bkcolor);
    bar(x,y,x+180,y+220);
    DrawBag(x,y,lcolor);
    
}
/**********************************************************
Function:  DrawStoreFrame
Description：	画出商城图标
Attention:  无
**********************************************************/
void DrawStoreFrame(int x,int y,int bkcolor,int lcolor)
{
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setcolor(bkcolor);
    setfillstyle(1,bkcolor);
    bar(x,y,x+180,y+220);
    DrawTrolly(x+13,y-20,lcolor);
}
/**********************************************************
Function:  DrawAppleFrame
Description：	画出苹果商品框
Attention:  无
**********************************************************/
void DrawAppleFrame(int x,int y,int bkcolor)
{
    setcolor(bkcolor);
    setfillstyle(1,bkcolor);
    bar(x,y,x+120,y+120);
    DrawApple_c(x+60,y+60);
}
/**********************************************************
Function:  DrawAppleFrame
Description：	画苹果
Attention:  无
**********************************************************/
void DrawApple_c(int x,int y)
{
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setcolor(LIGHTRED);
    setfillstyle(1,LIGHTRED);
    sector(x,y,0,360,40,33);
    setcolor(BROWN);
    line(x-15,y-15,x+15,y-15);
    line(x,y-15,x+4,y-50);
}
/**********************************************************
Function:  DrawscoreScreen
Description：	画出积分兑换界面
Attention:  无
**********************************************************/
void DrawscoreScreen_j(setuser* person,int *judge,setuser* head)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变量
    int mouseover[2]={0,0};
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//返回按钮
    puthz(260,25,"积分商城",32,32,CYAN);
    puthz(80, 80, "用户：", 16, 16, CYAN); 
    puthz(450, 80, "积分：", 16, 16, CYAN); 
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(140,76,person->accounts);
    outtextxy(510,76,person->score);
    DrawMineGFrame(100,150,DARKGRAY,LIGHTGRAY);
    DrawStoreFrame(360,150,DARKGRAY,LIGHTGRAY);

    while(1)
    {
        newxy(&mx,&my,&buttons);
        if (mx >= 100 && mx <= 280 && my >= 150 && my <= 370 && mouseover[0]==0) //鼠标移至我的兑换
        {
            mousehide(mx,my);
            DrawMineGFrame(100,150,DARKGRAY,LIGHTBLUE);
            puthz(160, 260, "我的兑换", 16, 16, LIGHTBLUE);
            mouseover[0]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 100 && mx <= 280 && my >= 150 && my <= 370) && mouseover[0]==1) 
        {
            mousehide(mx,my);
            DrawMineGFrame(100,150,DARKGRAY,LIGHTGRAY);
            mouseover[0]=0;
            getMousebk(mx,my);
        }
        if (mx >= 360 && mx <= 540 && my >= 150 && my <= 370 && mouseover[1]==0) //鼠标移至商品兑换
        {
            mousehide(mx,my);
            DrawStoreFrame(360,150,DARKGRAY,LIGHTBLUE);
            puthz(423, 263, "商品兑换", 16, 16, LIGHTBLUE);
            mouseover[1]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 360 && mx <= 540 && my >= 150 && my <= 370) && mouseover[1]==1) 
        {
            mousehide(mx,my);
            DrawStoreFrame(360,150,DARKGRAY,LIGHTGRAY);
            mouseover[1]=0;
            getMousebk(mx,my);
        }
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //返回按钮点击返回
            {
                *judge=turnTo_c(person,-1);
                return;
            }
            else if (mx >= 100 && mx <= 280 && my >= 150 && my <= 370)
            {
                *judge=turnTo_c(person,26);
                return;
            }
            else if (mx >= 360 && mx <= 540 && my >= 150 && my <= 370)
            {
                *judge=turnTo_c(person,25);
                return;
            }
        }
    }

}
/**********************************************************
Function:  DrawStoreScreen
Description：	画出商品兑换界面 代号25
Attention:  无
**********************************************************/
void DrawStoreScreen(setuser* person,int *judge,setuser* head)
{
    int buttons, mx, my;         //鼠标相关变量
    cleardevice();
    setbkcolor(WHITE);
    mouseInit(&mx, &my, &buttons);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//返回按钮
    puthz(260,25,"商品兑换",32,32,CYAN);
    puthz(80, 80, "用户：", 16, 16, CYAN); 
    puthz(450, 80, "积分：", 16, 16, CYAN); 
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
    outtextxy(140,76,person->accounts);
    outtextxy(510,76,person->score);
    DrawAppleFrame(60,150,DARKGRAY);
    while(1)
    {
        newxy(&mx,&my,&buttons);
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //返回按钮点击返回
            {
                *judge=turnTo_c(person,10);
                return;
            }
        }
    }
}
/**********************************************************
Function:  DrawMyChangeScreen
Description：	画出我的兑换界面 代号26
Attention:  无
**********************************************************/
void DrawMyChangeScreen(setuser* person,int *judge,setuser* head)
{
    int buttons, mx, my;         //鼠标相关变量
    cleardevice();
    setbkcolor(WHITE);
    mouseInit(&mx, &my, &buttons);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//返回按钮
    puthz(90,60,"您的兑换记录如下：",16,16,CYAN);
    puthz(150,100,"代号",16,16,CYAN);
    puthz(290,100,"商品名",16,16,CYAN);
    puthz(430,100,"花费积分",16,16,CYAN);
    while(1)
    {
        newxy(&mx,&my,&buttons);
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //返回按钮点击返回
            {
                *judge=turnTo_c(person,10);
                return;
            }
        }
    }
}