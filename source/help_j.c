#include "help_j.h"
#include "common_c.h"
void DrawpriceScreen_j(setuser *person, int *judge);
void judgestation_j(int x, int y, int station_name);
void DrawDistance_j(void);
void Draw_about_us_Screen_j(int *judge);
/**********************************************************
Function:  DrawpriceScreen
Description：价格图
Attention:  无
**********************************************************/
void DrawpriceScreen_j(setuser *person, int *judge)
{
    int buttons, mx, my;         //鼠标相关变量
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);

    DrawBeautifulFrame_c();
    returnBtn_c(550, 210, GREEN); //返回按钮

    puthz(60, 60, "尊敬的用户，您好！", 16, 16, LIGHTGRAY);
    puthz(60, 90, "根据武汉地铁最新收费标准：", 16, 16, LIGHTGRAY);
    puthz(60, 120, "（1）行程4公里以内（含4公里），2元；", 16, 16, LIGHTGRAY);
    puthz(60, 150, "（2）行程4——12公里（含12公里），1元每4公里；", 16, 16, LIGHTGRAY);
    puthz(60, 180, "（3）行程12——24公里（含24公里），1元每6公里；", 16, 16, LIGHTGRAY);
    puthz(60, 210, "距离可在地图上查询", 16, 16, LIGHTGRAY);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //返回按钮点击返回
            {
                *judge = turnTo_c(person, 5);
                return;
            }
        }
    }
}
/**********************************************************
Function:  judgestation
Description：将站点的简易编码变成站点名，在（x，y）处显示出来
Attention:  无
**********************************************************/
void judgestation_j(int x, int y, int station_name)
{
    if (station_name == 10)
        puthz(x, y, "循礼门", 16, 16, LIGHTMAGENTA);
    else if (station_name == 11)
        puthz(x, y, "崇仁路", 16, 16, LIGHTMAGENTA);
    else if (station_name == 12)
        puthz(x, y, "利济北路", 16, 16, LIGHTMAGENTA);
    else if (station_name == 13)
        puthz(x, y, "友谊路", 16, 16, LIGHTMAGENTA);
    else if (station_name == 15)
        puthz(x, y, "大智路", 16, 16, LIGHTMAGENTA);
    else if (station_name == 16)
        puthz(x, y, "三阳路", 16, 16, LIGHTMAGENTA);
    else if (station_name == 17)
        puthz(x, y, "黄浦路", 16, 16, LIGHTMAGENTA);
    else if (station_name == 18)
        puthz(x, y, "头道街", 16, 16, LIGHTMAGENTA);
    else if (station_name == 21)
        puthz(x, y, "中山公园", 16, 16, LIGHTMAGENTA);
    else if (station_name == 23)
        puthz(x, y, "江汉路", 16, 16, LIGHTMAGENTA);
    else if (station_name == 24)
        puthz(x, y, "积玉桥", 16, 16, LIGHTMAGENTA);
    else if (station_name == 25)
        puthz(x, y, "螃蟹岬", 16, 16, LIGHTMAGENTA);
    else if (station_name == 26)
        puthz(x, y, "小龟山", 16, 16, LIGHTMAGENTA);
    else if (station_name == 20)
        puthz(x, y, "洪山广场", 16, 16, LIGHTMAGENTA);
    else if (station_name == 29)
        puthz(x, y, "宝通寺", 16, 16, LIGHTMAGENTA);
    else if (station_name == 30)
        puthz(x, y, "中南路", 16, 16, LIGHTMAGENTA);
    else if (station_name == 41)
        puthz(x, y, "武昌火车站", 16, 16, LIGHTMAGENTA);
    else if (station_name == 42)
        puthz(x, y, "梅苑小区", 16, 16, LIGHTMAGENTA);
    else if (station_name == 45)
        puthz(x, y, "楚河汉街", 16, 16, LIGHTMAGENTA);
    else if (station_name == 46)
        puthz(x, y, "青鱼嘴", 16, 16, LIGHTMAGENTA);
    else if (station_name == 47)
        puthz(x, y, "东亭", 16, 16, LIGHTMAGENTA);
    else if (station_name == 48)
        puthz(x, y, "岳家嘴", 16, 16, LIGHTMAGENTA);
}
/**********************************************************
Function:  DrawDistance
Description：显示站点之间的距离
Attention:  无
**********************************************************/
void DrawDistance_j(void)
{
    setcolor(RED);
    settextstyle(0, 0, 1);
    //line1
    outtextxy(100, 100, "0.9");
    outtextxy(160, 100, "0.9");
    outtextxy(220, 100, "1.0");
    outtextxy(280, 100, "1.1");
    outtextxy(340, 100, "2.7");
    outtextxy(400, 100, "1.2");
    outtextxy(460, 100, "1.2");
    //line2
    outtextxy(280, 85, "1.5");
    outtextxy(255, 120, "2.6");
    outtextxy(255, 180, "3.4");
    outtextxy(255, 240, "1.6");
    outtextxy(255, 290, "0.9");
    outtextxy(255, 350, "1.3");
    outtextxy(220, 395, "1.4");
    //line4
    outtextxy(100, 380, "1.0");
    outtextxy(160, 380, "1.1");
    outtextxy(220, 380, "0.9");
    outtextxy(280, 380, "1.1");
    outtextxy(340, 380, "1.4");
    outtextxy(400, 380, "0.9");
    outtextxy(460, 380, "1.0");
}

/**********************************************************
Function:  Draw_about_us_Screen
Description：关于我们
Attention:  无
**********************************************************/
void Draw_about_us_Screen_j(int *judge)
{
    int buttons, mx, my;         //鼠标相关变量
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(550, 210, GREEN); //返回按钮
    settextstyle(1, 0, 2);
    puthz(100, 40, "武汉地铁交通模拟系统", 32, 32, CYAN);
    setcolor(CYAN);
    outtextxy(440, 54, "Version 1.0.1");
    setcolor(LIGHTGRAY);
    outtextxy(60, 84, "designed by");
    puthz(200, 90, "陈俊玮，江明轩", 16, 16, LIGHTGRAY);
    outtextxy(320, 84, "from HUST");
    puthz(60, 120, "本系统分为以下两块：", 16, 16, LIGHTGRAY);
    puthz(60, 150, "A普通用户  B管理员", 16, 16, LIGHTGRAY);
    puthz(60, 180, "普通用户：", 16, 16, LIGHTGRAY);
    puthz(60, 210, "可实现：创建账号，更改密码，购票，余额充值，账户查询，积分兑换", 16, 16, LIGHTGRAY);
    puthz(60, 240, "调度管理员：", 16, 16, LIGHTGRAY);
    puthz(60, 270, "可实现：用户端功能，地铁调度", 16, 16, LIGHTGRAY);
    puthz(60, 300, "运营管理员：", 16, 16, LIGHTGRAY);
    puthz(60, 330, "可实现：用户端功能，用户信息查询，权限管理，注销", 16, 16, LIGHTGRAY);
    puthz(170, 370, "《HUST AUTO许可及服务协议》", 16, 16, LIGHTGRAY);
    puthz(230, 400, "HUST版权所有", 16, 16, LIGHTGRAY);
    setcolor(LIGHTGRAY);
    outtextxy(130, 425, "Copyright @2019 All Rights Reserved");
    drawSignal(520,140,10);//标志
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //返回按钮点击返回
            {
                *judge = 1;
                return;
            }
        }
    }
}