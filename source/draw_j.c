#include "common_c.h"
#include "draw_j.h"
void DrawbuyScreen_j(setuser *person, int *judge, setuser *head, all_lines_stations *all); //购票界面
void rectangles_j(int color);
void DrawcheckScreen_j(setuser *person, int *judge, setuser *head);  //查询界面
void DrawchargeScreen_j(setuser *person, int *judge, setuser *head); //充值界面
void outputcharge_j(setuser *person, int add_money, setuser *head);  //修改、实时显示用户余额，显示delay正在充值
void click_charge_j(int color);                                      //点框框加效果
void DrawUserScreen_j(setuser *person, int *judge);                  //普通用户界面
void rectangles_j(int color)
{
    setlinestyle(0, 0, 3);
    setcolor(color);
    rectangle(170, 80, 470, 150);
    rectangle(170, 200, 470, 270);
    rectangle(170, 320, 470, 390);
}

/***********************************************
Function：DrawUserScreen
Description：画普通用户界面
Attention:
***********************************************/
void DrawUserScreen_j(setuser *person, int *judge)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变量
    int sign[3] = {0, 0, 0};
    // 初始化
    // 鼠标初始化
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    puthz(90, 28, "您好！尊敬的：", 16, 16, GREEN);
    settextstyle(0, 0, 2);
    outtextxy(220, 25, person->accounts);
    returnBtn_c(550, 210, GREEN);
    //画出三个矩形，填充为黄色
    setfillstyle(1, YELLOW);
    bar(170, 80, 470, 150);
    bar(170, 200, 470, 270);
    bar(170, 320, 470, 390);
    rectangles_j(GREEN);

    puthz(200, 95, "购票", 32, 32, GREEN);
    puthz(200, 215, "账户查询", 32, 32, GREEN);
    puthz(200, 335, "账户充值", 32, 32, GREEN);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons) //点击事件
        {
            if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //返回按钮点击返回
            {
                *judge = turnTo_c(person, 1);
                return;
            }
            if (mx >= 170 && mx <= 470 && my >= 80 && my <= 150 && buttons) //点入购票界面
            {
                *judge = turnTo_c(person, 5);
                return;
            }
            if (mx >= 170 && mx <= 470 && my >= 200 && my <= 270 && buttons) //点入余额查询界面
            {
                *judge = turnTo_c(person, 6);
                return;
            }
            if (mx >= 170 && mx <= 470 && my >= 320 && my <= 390 && buttons) //点入充值界面
            {
                *judge = turnTo_c(person, 7);
                return;
            }
        }
        //鼠标放上去，框变紫色的动画
        if (mx >= 170 && mx <= 470 && my >= 80 && my <= 150 && sign[0] == 0)
        {
            mousehide(mx, my);
            setcolor(LIGHTMAGENTA);
            rectangle(170, 80, 470, 150);
            setcolor(GREEN);
            rectangle(170, 200, 470, 270);
            rectangle(170, 320, 470, 390);
            sign[0] = 1;
            getMousebk(mx, my);
        }
        else if (mx >= 170 && mx <= 470 && my >= 200 && my <= 270 && sign[1] == 0)
        {
            mousehide(mx, my);
            setcolor(LIGHTMAGENTA);
            rectangle(170, 200, 470, 270);
            setcolor(GREEN);
            rectangle(170, 80, 470, 150);
            rectangle(170, 320, 470, 390);
            sign[1] = 1;
            getMousebk(mx, my);
        }
        else if (mx >= 170 && mx <= 470 && my >= 320 && my <= 390 && sign[2] == 0)
        {
            mousehide(mx, my);
            setcolor(LIGHTMAGENTA);
            rectangle(170, 320, 470, 390);
            setcolor(GREEN);
            rectangle(170, 80, 470, 150);
            rectangle(170, 200, 470, 270);
            sign[2] = 1;
            getMousebk(mx, my);
        }
        else if ((sign[0] || sign[1] || sign[2]) && !(mx >= 170 && mx <= 470 && my >= 80 && my <= 150) && !(mx >= 170 && mx <= 470 && my >= 200 && my <= 270) && !(mx >= 170 && mx <= 470 && my >= 320 && my <= 390))
        {
            mousehide(mx, my);
            rectangles_j(GREEN);
            sign[0] = 0;
            sign[1] = 0;
            sign[2] = 0;
            getMousebk(mx, my);
        }
    }
}
/**********************************************************
Function:  DrawbuyScreen
Description：	画出购票界面，实现购票功能
Attention:  无
**********************************************************/
void DrawbuyScreen_j(setuser *person, int *judge, setuser *head, all_lines_stations *all)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变量
    int i;                       //划线循环变量
    int sta_checkclick[5][10];   //二维数组标志量，检验点击了几次（0表示没点击，1表示点击了），其实这个没啥用了，后期可以删掉了
    int flag;
    int start_station; //存储起点信息,比如12代表1号线第2站为起点
    int end_station;   //存储终点信息，和上面一行差不多
    int price;
    int money;                  //用户余额
    int sign[4] = {0, 0, 0, 0}; //sign0标志“计费规则”框
    //char sss[10]="江明轩";
    flag = 0;
    start_station = 0;
    end_station = 0;
    price = 0;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    //DrawBeautifulFrame_c();
    //puthz(30,130,sss,16,16,RED);//这句话可以显示！
    //outtextxy(30,160,all->line1[1].x);

    //画出返回按钮
    returnBtn_c(550, 210, GREEN);

    setcolor(BROWN);
    setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
    line(460, 0, 460, 75);
    line(460, 75, 640, 75);

    setlinestyle(0, 0, 3);
    setcolor(LIGHTCYAN);
    line(500, 10, 550, 10);
    outtextxy(560, 0, "1");
    puthz(570, 5, "号线", 16, 16, LIGHTBLUE);
    setcolor(LIGHTGREEN);
    line(500, 30, 550, 30);
    outtextxy(560, 20, "2");
    puthz(570, 25, "号线", 16, 16, LIGHTGREEN);
    setcolor(YELLOW);
    line(500, 50, 550, 50);
    outtextxy(560, 40, "4");
    puthz(570, 45, "号线", 16, 16, YELLOW);
    puthz(180, 0, "武汉地铁交通线", 32, 32, BROWN);

    Drawstation1_j();
    Drawstation2_j();
    Drawstation4_j();
    DrawCircles_j();

    //购票按钮
    setcolor(GREEN);
    circle(580, 150, 30);
    //重选按钮
    setcolor(GREEN);
    circle(580, 320, 30);
    //计费规则按钮
    rectangle(400, 150, 510, 220);
    //显示距离按钮
    rectangle(400, 240, 510, 310);

    puthz(565, 142, "购票", 16, 16, CYAN);
    puthz(565, 312, "重选", 16, 16, CYAN);
    puthz(425, 180, "计费规则", 16, 16, CYAN);
    puthz(425, 270, "显示距离", 16, 16, CYAN);
    puthz(30, 5, "请先点击起点", 16, 16, RED);
    puthz(30, 25, "再点击终点", 16, 16, RED);
    puthz(30, 45, "最后点击购票按钮", 16, 16, RED);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons) //专门用来搞返回上个界面
        {
            if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //返回按钮点击返回
            {
                *judge = turnTo_c(person, -1);
                return;
            }
            if (mx >= 400 && mx <= 510 && my >= 150 && my <= 220 && buttons) //计费规则
            {
                *judge = turnTo_c(person, 8);
                return;
            }
            if (mx >= 400 && mx <= 510 && my >= 240 && my <= 310 && buttons)
            {
                DrawDistance_j();
            }
        }

        /***************对于第一次点击起点站******************/
        if (buttons && flag == 0)
        {
            //三条线的圈圈，并且显示出起点
            //1号线的
            mousehide(mx, my);
            if (mx >= 75 && mx <= 85 && my >= 95 && my <= 105 && buttons) //第一次点击
            {
                Draw_start_sta_j(80, 100, &all->line1[1], &sta_checkclick[1][1], &start_station, &flag, &price);
            }
            if (mx >= 135 && mx <= 145 && my >= 95 && my <= 105 && buttons)
            {
                Draw_start_sta_j(140, 100, &all->line1[2], &sta_checkclick[1][2], &start_station, &flag, &price);
            }
            if (mx >= 195 && mx <= 205 && my >= 95 && my <= 105 && buttons)
            {
                Draw_start_sta_j(200, 100, &all->line1[3], &sta_checkclick[1][3], &start_station, &flag, &price);
            }
            if (mx >= 255 && mx <= 265 && my >= 95 && my <= 105 && buttons) //这个是循礼门站，1和2的交点，到时候要特殊处理
            {
                Draw_start_sta_j(260, 100, &all->line1[4], &sta_checkclick[1][4], &start_station, &flag, &price);
            }
            if (mx >= 315 && mx <= 325 && my >= 95 && my <= 105 && buttons)
            {
                Draw_start_sta_j(320, 100, &all->line1[5], &sta_checkclick[1][5], &start_station, &flag, &price);
            }
            if (mx >= 375 && mx <= 385 && my >= 95 && my <= 105 && buttons)
            {
                Draw_start_sta_j(380, 100, &all->line1[6], &sta_checkclick[1][6], &start_station, &flag, &price);
            }
            if (mx >= 435 && mx <= 445 && my >= 95 && my <= 105 && buttons)
            {
                Draw_start_sta_j(440, 100, &all->line1[7], &sta_checkclick[1][7], &start_station, &flag, &price);
            }
            if (mx >= 495 && mx <= 505 && my >= 95 && my <= 105 && buttons)
            {
                Draw_start_sta_j(500, 100, &all->line1[8], &sta_checkclick[1][8], &start_station, &flag, &price);
            }
            //2号线的
            if (mx >= 295 && mx <= 305 && my >= 65 && my <= 75 && buttons) //第一次点击
            {
                Draw_start_sta_j(300, 70, &all->line2[1], &sta_checkclick[2][1], &start_station, &flag, &price);
            }
            if (mx >= 255 && mx <= 265 && my >= 151 && my <= 161 && buttons)
            {
                Draw_start_sta_j(260, 156, &all->line2[3], &sta_checkclick[2][3], &start_station, &flag, &price);
            }
            if (mx >= 255 && mx <= 265 && my >= 207 && my <= 217 && buttons)
            {
                Draw_start_sta_j(260, 212, &all->line2[4], &sta_checkclick[2][4], &start_station, &flag, &price);
            }
            if (mx >= 255 && mx <= 265 && my >= 263 && my <= 273 && buttons)
            {
                Draw_start_sta_j(260, 268, &all->line2[5], &sta_checkclick[2][5], &start_station, &flag, &price);
            }
            if (mx >= 255 && mx <= 265 && my >= 319 && my <= 329 && buttons)
            {
                Draw_start_sta_j(260, 324, &all->line2[6], &sta_checkclick[2][6], &start_station, &flag, &price); //有个小的计算失误，但问题不大
            }                                                                                                     //这两个draw距离其实是66
            if (mx >= 255 && mx <= 265 && my >= 375 && my <= 385 && buttons)
            {
                Draw_start_sta_j(260, 380, &all->line2[7], &sta_checkclick[2][7], &start_station, &flag, &price);
            }
            if (mx >= 195 && mx <= 205 && my >= 375 && my <= 385 && buttons)
            {
                Draw_start_sta_j(200, 380, &all->line2[8], &sta_checkclick[2][8], &start_station, &flag, &price);
            }
            if (mx >= 235 && mx <= 245 && my >= 405 && my <= 415 && buttons)
            {
                Draw_start_sta_j(240, 410, &all->line2[9], &sta_checkclick[2][9], &start_station, &flag, &price);
            }
            //4号线的
            if (mx >= 75 && mx <= 85 && my >= 375 && my <= 385 && buttons) //第一次点击
            {
                Draw_start_sta_j(80, 380, &all->line4[1], &sta_checkclick[4][1], &start_station, &flag, &price);
            }
            if (mx >= 135 && mx <= 145 && my >= 375 && my <= 385 && buttons)
            {
                Draw_start_sta_j(140, 380, &all->line4[2], &sta_checkclick[4][2], &start_station, &flag, &price);
            }
            if (mx >= 315 && mx <= 325 && my >= 375 && my <= 385 && buttons)
            {
                Draw_start_sta_j(320, 380, &all->line4[5], &sta_checkclick[4][5], &start_station, &flag, &price);
            }
            if (mx >= 375 && mx <= 385 && my >= 375 && my <= 385 && buttons)
            {
                Draw_start_sta_j(380, 380, &all->line4[6], &sta_checkclick[4][6], &start_station, &flag, &price);
            }
            if (mx >= 435 && mx <= 445 && my >= 375 && my <= 385 && buttons)
            {
                Draw_start_sta_j(440, 380, &all->line4[7], &sta_checkclick[4][7], &start_station, &flag, &price);
            }
            if (mx >= 495 && mx <= 505 && my >= 375 && my <= 385 && buttons)
            {
                Draw_start_sta_j(500, 380, &all->line4[8], &sta_checkclick[4][8], &start_station, &flag, &price);
            }
            getMousebk(mx, my);
            continue;
        } //if第一次点击起始站
        /***************对于第一次点击起点站之后******************/

        if (buttons && flag == 1)
        {
            mousehide(mx, my);
            if (mx >= 75 && mx <= 85 && my >= 95 && my <= 105 && buttons) //第一次点击
            {
                Draw_end_sta_j(all, 80, 100, all->line1[1], &sta_checkclick[1][1], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 135 && mx <= 145 && my >= 95 && my <= 105 && buttons)
            {
                Draw_end_sta_j(all, 140, 100, all->line1[2], &sta_checkclick[1][2], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 195 && mx <= 205 && my >= 95 && my <= 105 && buttons)
            {
                Draw_end_sta_j(all, 200, 100, all->line1[3], &sta_checkclick[1][3], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 255 && mx <= 265 && my >= 95 && my <= 105 && buttons) //这个是循礼门站，1和2的交点，到时候要特殊处理
            {
                Draw_end_sta_j(all, 260, 100, all->line1[4], &sta_checkclick[1][4], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 315 && mx <= 325 && my >= 95 && my <= 105 && buttons)
            {
                Draw_end_sta_j(all, 320, 100, all->line1[5], &sta_checkclick[1][5], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 375 && mx <= 385 && my >= 95 && my <= 105 && buttons)
            {
                Draw_end_sta_j(all, 380, 100, all->line1[6], &sta_checkclick[1][6], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 435 && mx <= 445 && my >= 95 && my <= 105 && buttons)
            {
                Draw_end_sta_j(all, 440, 100, all->line1[7], &sta_checkclick[1][7], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 495 && mx <= 505 && my >= 95 && my <= 105 && buttons)
            {
                Draw_end_sta_j(all, 500, 100, all->line1[8], &sta_checkclick[1][8], &start_station, &end_station, &flag, &price);
            }
            //2号线的
            if (mx >= 295 && mx <= 305 && my >= 65 && my <= 75 && buttons)
            {
                Draw_end_sta_j(all, 300, 70, all->line2[1], &sta_checkclick[2][1], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 255 && mx <= 265 && my >= 151 && my <= 161 && buttons)
            {
                Draw_end_sta_j(all, 260, 156, all->line2[3], &sta_checkclick[2][3], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 255 && mx <= 265 && my >= 207 && my <= 217 && buttons)
            {
                Draw_end_sta_j(all, 260, 212, all->line2[4], &sta_checkclick[2][4], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 255 && mx <= 265 && my >= 263 && my <= 273 && buttons)
            {
                Draw_end_sta_j(all, 260, 268, all->line2[5], &sta_checkclick[2][5], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 255 && mx <= 265 && my >= 319 && my <= 329 && buttons)
            {
                Draw_end_sta_j(all, 260, 324, all->line2[6], &sta_checkclick[2][6], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 255 && mx <= 265 && my >= 375 && my <= 385 && buttons)
            {
                Draw_end_sta_j(all, 260, 380, all->line2[7], &sta_checkclick[2][7], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 195 && mx <= 205 && my >= 375 && my <= 385 && buttons)
            {
                Draw_end_sta_j(all, 200, 380, all->line2[8], &sta_checkclick[2][8], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 235 && mx <= 245 && my >= 405 && my <= 415 && buttons)
            {
                Draw_end_sta_j(all, 240, 410, all->line2[9], &sta_checkclick[2][9], &start_station, &end_station, &flag, &price);
            }
            //4号线的
            if (mx >= 75 && mx <= 85 && my >= 375 && my <= 385 && buttons)
            {
                Draw_end_sta_j(all, 80, 380, all->line4[1], &sta_checkclick[4][1], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 135 && mx <= 145 && my >= 375 && my <= 385 && buttons)
            {
                Draw_end_sta_j(all, 140, 380, all->line4[2], &sta_checkclick[4][2], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 315 && mx <= 325 && my >= 375 && my <= 385 && buttons)
            {
                Draw_end_sta_j(all, 320, 380, all->line4[5], &sta_checkclick[4][5], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 375 && mx <= 385 && my >= 375 && my <= 385 && buttons)
            {
                Draw_end_sta_j(all, 380, 380, all->line4[6], &sta_checkclick[4][6], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 435 && mx <= 445 && my >= 375 && my <= 385 && buttons)
            {
                Draw_end_sta_j(all, 440, 380, all->line4[7], &sta_checkclick[4][7], &start_station, &end_station, &flag, &price);
            }
            if (mx >= 495 && mx <= 505 && my >= 375 && my <= 385 && buttons)
            {
                Draw_end_sta_j(all, 500, 380, all->line4[8], &sta_checkclick[4][8], &start_station, &end_station, &flag, &price);
            }
            getMousebk(mx, my);
        }
        //重选，flag重新置0，覆盖前面的文字
        if (mx >= 550 && mx <= 610 && my >= 290 && my <= 350 && buttons)
        {
            mousehide(mx, my);
            flag = 0;
            setfillstyle(1, WHITE); //把原来的涂掉
            bar(20, 130, 160, 280);
            DrawCircles_j();
            start_station = 0; //起点站置0
            end_station = 0;   //终点站置0
            price = 0;
            getMousebk(mx, my);
        }
        //购票！
        if (mx >= 550 && mx <= 610 && my >= 120 && my <= 180 && buttons && flag == 2)
        {
            mousehide(mx, my);
            money = atoi(person->money);
            if (money >= price)
            {
                setfillstyle(1, LIGHTMAGENTA);
                bar(220, 180, 450, 300);
                puthz(220, 210, "购票成功！", 16, 16, GREEN);
                puthz(220, 240, "查询：个人中心——账户查询", 16, 16, GREEN);
                changemoney_j(-price, person, 10, head);
                changescore_j(price * 10, person, head);
                changerecord_j(person, head, start_station, end_station, price);
                delay(2000);
                *judge = turnTo_c(person, -1);
                return;
            }
            if (money < price)
            {
                setfillstyle(1, LIGHTMAGENTA);
                bar(220, 180, 420, 300);
                puthz(220, 225, "余额不足！请先充值！", 16, 16, GREEN);
                delay(2000);
                *judge = turnTo_c(person, 3);
                return;
            }
            getMousebk(mx, my);
        }
        if (mx >= 400 && mx <= 510 && my >= 150 && my <= 220 && sign[0] == 0) //计费规则变紫
        {
            mousehide(mx, my);
            setlinestyle(0, 0, 3);
            setcolor(LIGHTMAGENTA);
            rectangle(400, 150, 510, 220);
            sign[0] = 1;
            getMousebk(mx, my);
        }
        else if (mx >= 400 && mx <= 510 && my >= 240 && my <= 310 && sign[1] == 0) //显示距离变紫
        {
            mousehide(mx, my);
            setlinestyle(0, 0, 3);
            setcolor(LIGHTMAGENTA);
            rectangle(400, 240, 510, 310);
            sign[1] = 1;
            getMousebk(mx, my);
        }
        else if (mx >= 550 && mx <= 610 && my >= 120 && my <= 180 && sign[2] == 0 && flag == 2) //购票变紫(选好了起点终点才会变色)
        {
            mousehide(mx, my);
            setlinestyle(0, 0, 3);
            setcolor(LIGHTMAGENTA);
            circle(580, 150, 30);
            sign[2] = 1;
            getMousebk(mx, my);
        }
        else if (mx >= 550 && mx <= 610 && my >= 290 && my <= 350 && sign[3] == 0)
        {
            mousehide(mx, my);
            setlinestyle(0, 0, 3);
            setcolor(LIGHTMAGENTA);
            circle(580, 320, 30);
            sign[3] = 1;
            getMousebk(mx, my);
        }
        else if ((sign[0] || sign[1] || sign[2] || sign[3]) && !(mx >= 400 && mx <= 510 && my >= 150 && my <= 220) && !(mx >= 400 && mx <= 510 && my >= 240 && my <= 310) && !(mx >= 550 && mx <= 610 && my >= 120 && my <= 180) && !(mx >= 550 && mx <= 610 && my >= 290 && my <= 350))
        {
            mousehide(mx, my);
            setlinestyle(0, 0, 3);
            setcolor(GREEN);
            circle(580, 150, 30);
            circle(580, 320, 30);
            rectangle(400, 150, 510, 220);
            rectangle(400, 240, 510, 310);
            sign[0] = sign[1] = sign[2] = sign[3] = 0;
            getMousebk(mx, my);
        }
    }
}
/**********************************************************
Function:  DrawcheckScreen
Description：画出账户查询界面
Attention:  无
**********************************************************/
void DrawcheckScreen_j(setuser *person, int *judge, setuser *head)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变量
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    settextstyle(0, 0, 2);
    setcolor(LIGHTMAGENTA);

    puthz(90, 28, "您好！尊敬的：", 16, 16, CYAN);
    setcolor(MAGENTA);
    outtextxy(220, 30, person->accounts);

    setlinestyle(0, 0, 1);
    setcolor(LIGHTRED);

    //画出返回按钮
    returnBtn_c(300, 400, GREEN);

    puthz(90, 100, "余额：", 16, 16, CYAN);
    puthz(250, 100, "积分：", 16, 16, CYAN);
    //changemoney_j(0, person, 10, head);
    setcolor(MAGENTA);
    if (atoi(person->money) == 0)
    {
        outtextxy(140, 95, "0");
    }
    else
    {
        outtextxy(140, 95, person->money);
    }
    if (atoi(person->score) == 0)
    {
        outtextxy(300, 95, "0");
    }
    else
    {
        outtextxy(300, 95, person->score);
    }

    puthz(90, 160, "您可以选择：", 16, 16, CYAN);
    setfillstyle(1, LIGHTCYAN);

    bar(100, 200, 280, 290);
    bar(330, 200, 510, 290);
    bar(100, 305, 280, 395);
    bar(330, 305, 510, 395);
    puthz(160, 223, "购票", 32, 32, MAGENTA);
    puthz(357, 223, "修改密码", 32, 32, MAGENTA);
    puthz(127, 328, "购票记录", 32, 32, MAGENTA);
    puthz(357, 328, "积分商城", 32, 32, MAGENTA);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            mousehide(mx, my);
            if (mx >= 300 && mx <= 360 && my >= 400 && my <= 460 && buttons) //返回按钮点击返回
            {
                *judge = turnTo_c(person, -1);
                return;
            }
            if (mx >= 100 && mx <= 280 && my >= 200 && my <= 290 && buttons) //点击购票方框，返回购票界面
            {
                *judge = turnTo_c(person, 5);
                return;
            }
            if (mx >= 330 && mx <= 510 && my >= 200 && my <= 290 && buttons) //点击修改密码方框
            {
                *judge = turnTo_c(person, 14);
                return;
            }
            if (mx >= 100 && mx <= 305 && my >= 280 && my <= 395 && buttons)
            {
                *judge = turnTo_c(person, 9);
                return;
            }
            if (mx >= 330 && mx <= 510 && my >= 305 && my <= 395 && buttons)
            {
                *judge = turnTo_c(person, 10);
                return;
            }
            getMousebk(mx, my);
        }
    }
}
/**********************************************************
Function:  outputcharge
Description：修改、实时显示用户余额，显示delay正在充值
Attention:  无
**********************************************************/
void outputcharge_j(setuser *person, int add_money, setuser *head)
{
    setcolor(LIGHTMAGENTA);
    setlinestyle(0, 0, 1);
    rectangle(400, 70, 560, 110);
    puthz(410, 75, "正在支付中。。。", 16, 16, LIGHTMAGENTA);
    settextstyle(0, 0, 2);
    setcolor(LIGHTMAGENTA);
    if (atoi(person->money) == 0)
    {
        outtextxy(200, 75, "0");
    }
    else
    {
        outtextxy(200, 75, person->money);
    }
    puthz(270, 75, "元", 16, 16, LIGHTMAGENTA);
    delay(1000);
    setcolor(WHITE);
    bar(400, 70, 560, 110);
    bar(200, 70, 280, 110);
    changemoney_j(add_money, person, 10, head); //充值add_money元，修改person->money的值
    settextstyle(0, 0, 2);
    setcolor(LIGHTMAGENTA);
    outtextxy(200, 75, person->money);
    puthz(270, 75, "元", 16, 16, LIGHTMAGENTA);
}
/**********************************************************
Function:  click_charge_j
Description：点击之后加框效果
Attention:  无
**********************************************************/
void click_charge_j(int color) //点击之后加框效果
{
    int kuang[] = {498, 55, 555, 55, 555, 85, 498, 85, 498, 55};
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    setcolor(color);
    drawpoly(5, kuang);
}
/**********************************************************
Function:  DrawchargeScreen
Description：画充值界面，并且实现充值功能
Attention:  无
**********************************************************/

void DrawchargeScreen_j(setuser *person, int *judge, setuser *head)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变量
    int key = 0, sign = 0;       //输入法标记第几个数字或字母的参数
    int choose;
    int charge = 0;
    int flag;
    char place[4];
    char str_charge[4];
    int zidingyi;
    place[0] = '\0';
    mouseInit(&mx, &my, &buttons);
    choose = 0;
    flag = 0;
    zidingyi = 0;
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    puthz(80, 28, "您好！尊敬的：", 16, 16, GREEN);
    outtextxy(190, 27, person->accounts);
    //puthz(400, 435, "关于我们", 16, 16, MAGENTA);
    //puthz(540, 435, "帮助", 16, 16, MAGENTA);

    // closegraph();
    // printf("%s",place);//输出乱码了
    // getch();

    setlinestyle(0, 0, 1);
    setcolor(LIGHTRED);
    //rectangle(398, 433, 465, 453); //关于我们的位置
    //rectangle(538, 433, 571, 453); //帮助的位置
    //画出返回按钮
    returnBtn_c(300, 400, GREEN);

    puthz(80, 75, "您的余额：", 16, 16, GREEN);
    settextstyle(0, 0, 2);
    setcolor(LIGHTMAGENTA);
    if (atoi(person->money) == 0)
    {
        outtextxy(200, 75, "0");
    }
    else
    {
        outtextxy(200, 75, person->money);
    }
    puthz(270, 75, "元", 16, 16, LIGHTMAGENTA);
    setlinestyle(0, 0, 1);
    puthz(80, 110, "您可以选择：", 16, 16, GREEN);
    setcolor(YELLOW);
    //画充值框
    rectangle(100, 150, 190, 200);
    rectangle(280, 150, 370, 200);
    rectangle(460, 150, 550, 200);
    rectangle(100, 280, 190, 330);
    rectangle(280, 280, 370, 330);
    rectangle(460, 280, 550, 330);

    puthz(122, 170, "10元", 16, 16, LIGHTCYAN);
    puthz(302, 170, "20元", 16, 16, LIGHTCYAN);
    puthz(482, 170, "50元", 16, 16, LIGHTCYAN);
    puthz(112, 300, "100元", 16, 16, LIGHTCYAN);
    puthz(292, 300, "200元", 16, 16, LIGHTCYAN);
    puthz(482, 295, "自定义", 16, 16, LIGHTCYAN);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            mousehide(mx, my);
            if (mx >= 300 && mx <= 360 && my >= 400 && my <= 460 && buttons) //返回按钮点击返回
            {
                *judge = turnTo_c(person, -1);
                return;
            }
            else if (mx >= 100 && mx <= 190 && my >= 150 && my <= 200 && buttons && choose == 0)
            {
                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370); //覆盖掉“您已成功充值XXX元”的提示
                bar(180, 70, 290, 100);
                outputcharge_j(person, 10, head);
                puthz(80, 350, "您已成功充值10元", 16, 16, RED);
            }
            else if (mx >= 280 && mx <= 370 && my >= 150 && my <= 200 && buttons && choose == 0)
            {
                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                bar(180, 70, 290, 100);
                outputcharge_j(person, 20, head);
                puthz(80, 350, "您已成功充值20元", 16, 16, RED);
            }
            else if (mx >= 460 && mx <= 550 && my >= 150 && my <= 200 && buttons && choose == 0)
            {
                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                bar(180, 70, 290, 100);
                outputcharge_j(person, 50, head);
                puthz(80, 350, "您已成功充值50元", 16, 16, RED);
            }
            else if (mx >= 100 && mx <= 190 && my >= 280 && my <= 330 && buttons && choose == 0)
            {

                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                bar(180, 70, 290, 100);
                outputcharge_j(person, 100, head);
                puthz(80, 350, "您已成功充值100元", 16, 16, RED);
            }
            else if (mx >= 280 && mx <= 370 && my >= 280 && my <= 330 && buttons && choose == 0)
            {

                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                bar(180, 70, 290, 100);
                outputcharge_j(person, 200, head);
                puthz(80, 350, "您已成功充值200元", 16, 16, RED);
            }
            else if (mx >= 460 && mx <= 550 && my >= 280 && my <= 330 && buttons && zidingyi == 0) //之前没点过“自定义”
            {
                setfillstyle(1, DARKGRAY);
                bar(400, 50, 560, 112);
                setfillstyle(1, WHITE);
                bar(500, 55, 555, 85);
                bar(420, 88, 470, 108); //确定
                bar(490, 88, 540, 108); //取消
                puthz(430, 90, "确定", 16, 16, BLUE);
                puthz(500, 90, "取消", 16, 16, BLUE);
                puthz(405, 60, "请输入金额：", 16, 16, WHITE);
                zidingyi = 1;
            }
            else if (mx >= 500 && mx <= 545 && my >= 55 && my <= 85 && buttons) //框变绿效果
            {
                mousehide(mx, my);
                choose = 1; //选中了框框
                click_charge_j(GREEN);
                getMousebk(mx, my);
            }
            else if (mx >= 490 && mx <= 540 && my >= 88 && my <= 108 && buttons) //点击“取消”
            {
                mousehide(mx, my);
                setfillstyle(1, WHITE);
                bar(400, 50, 560, 112);
                bar(350, 115, 600, 147);
                choose = 0;
                sign = 0;
                zidingyi = 0;
                getMousebk(mx, my);
            }
            else if (mx >= 420 && mx <= 470 && my >= 88 && my <= 108 && buttons && choose == 1 && charge != 0 && flag == 0) //点击“确认”
            {
                mousehide(mx, my);
                setfillstyle(1, WHITE);
                bar(400, 50, 560, 112);
                bar(60, 340, 250, 370);
                bar(180, 70, 290, 100);
                choose = 0;
                sign = 0;
                zidingyi = 0;
                outputcharge_j(person, charge, head);
                itoa(charge, str_charge, 10);
                bar(60, 340, 250, 370); //覆盖掉“您已成功充值XXX元”的提示
                puthz(80, 350, "您已成功充值", 16, 16, RED);
                puthz(180, 350, str_charge, 16, 16, RED);
                puthz(235, 350, "元", 16, 16, RED);
                getMousebk(mx, my);
            }
        }
        settextstyle(SMALL_FONT, HORIZ_DIR, 7);
        setcolor(BLUE);
        if (choose == 1) //选中账号框
        {
            key = 0; //重置键值并得到新键值
            temp[0] = '\0';
            if (kbhit() != 0) //如果检测到键盘输入
            {
                mousehide(mx, my);
                key = bioskey(0);
                if (key != 0xe08 && sign >= 0 && sign <= 3) //如果输入不是退格键
                {
                    if (searchKeyValue(key) == '0' || searchKeyValue(key) == '1' || searchKeyValue(key) == '2' || searchKeyValue(key) == '3' || searchKeyValue(key) == '4' ||
                        searchKeyValue(key) == '5' || searchKeyValue(key) == '6' || searchKeyValue(key) == '7' || searchKeyValue(key) == '8' || searchKeyValue(key) == '9') //其中输入的是数字
                    {
                        sign++; //字符数加一
                        //setfillstyle(1,WHITE);
                        //bar(500+sign*12,80,500+(sign+1)*12,98);
                        settextstyle(SMALL_FONT, HORIZ_DIR, 7);
                        setcolor(BLUE);
                        temp[0] = searchKeyValue(key);
                        place[sign - 1] = temp[0]; //字符缓存
                        place[sign] = '\0';
                        outtextxy(490 + sign * 12, 60, temp);
                        charge = atoi(place);
                    }
                }
                else if (key == 0xe08 && sign > 0) //如果按了回删键
                {
                    sign--; //字符数减1
                    setfillstyle(1, WHITE);
                    bar(500 + sign * 12, 60, 500 + (sign + 1) * 12, 78); //输入框1账号
                    place[sign] = '\0';
                    charge = atoi(place);
                }
                getMousebk(mx, my);
            }
            if (charge > 200)
            {
                puthz(350, 120, "单笔充值金额不可超过200元！", 16, 16, RED);
                flag = 1;
            }
            if (charge <= 200 && choose == 1 && flag == 1)
            {
                setfillstyle(1, WHITE);
                bar(350, 115, 600, 147);
                flag = 0;
            }
        }
    }
}