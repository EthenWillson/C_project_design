#include "common_c.h"
/**********************************************************
Description： 此文件专门存放运营相关的函数
Attention:  查询用户的数量，余额，积分，出行记录，并且可以注销用户
Author：江明轩
**********************************************************/
void DrawLine_j(int x1, int y1, int x2, int y2, int x3, int y3, int color);
void DrawStar_j();
void Draw_run_Screen_j(setuser *person, int *judge, setuser *head);
void run_check_Screen_j(setuser *person, int *judge, setuser *head);
void run_power_Screen_j(setuser *person, int *judge, setuser *head);
void Draw_poly1_j();                         //更改权限
void Draw_poly2_j();                         //删除用户
void Draw_frame1_j(int x, int y, int color); //更改权限操作框
void Draw_frame2_j(int x, int y, int color); //删除用户操作框
void change_power_Screen_j(setuser *person, int *judge, setuser *head);
void delete_user_Screen_j(setuser *person, int *judge, setuser *head);
/**********************************************************
Function:  DrawLine
Description：画三角
Attention:  无
**********************************************************/
void DrawLine_j(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
    setlinestyle(0, 0, 3);
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
/**********************************************************
Function:  DrawStar
Description：画六芒星
Attention:  无
**********************************************************/
void DrawStar_j()
{
    setlinestyle(0, 0, 3);
    setcolor(YELLOW);
    line(320, 100, 185, 340);
    line(185, 340, 455, 340);
    line(455, 340, 320, 100);
    line(185, 180, 455, 180);
    line(455, 180, 320, 420);
    line(320, 420, 185, 180);
}
/**********************************************************
Function:  Draw_run_Screen
Description：运营管理员基本界面
Attention:  无
**********************************************************/
void Draw_run_Screen_j(setuser *person, int *judge, setuser *head)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变量
    int sign[2] = {0, 0};        //用于判断鼠标移动到按钮上的标志
    int page;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(DARKGRAY);
    setfillstyle(1, LIGHTGRAY);
    bar(0, 0, 640, 50); //个人信息显示栏
    //头像图标
    setcolor(DARKGRAY);
    setfillstyle(1, DARKGRAY);
    pieslice(25, 25, 0, 360, 20);
    setcolor(LIGHTGRAY);
    setfillstyle(1, LIGHTGRAY);
    pieslice(25, 20, 0, 360, 9);
    pieslice(25, 25, 232, 308, 19);
    //文字
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    puthz(60, 17, "用户：", 16, 16, WHITE);
    puthz(300, 17, "身份：运营管理员", 16, 16, WHITE);
    //用户名
    settextstyle(1, 0, 2);
    outtextxy(110, 14, person->accounts);
    //画退出系统按钮
    setlinestyle(0, 0, 3);
    setcolor(LIGHTRED);
    arc(600, 30, 110, 430, 15);
    line(600, 5, 600, 31);
    //画六芒星！！！
    DrawStar_j();
    //功能们
    puthz(305,140,"购票",16,16,WHITE);
    puthz(215,185,"修改",16,16,WHITE);
    puthz(215,210,"密码",16,16,WHITE);
    puthz(395,185,"账户",16,16,WHITE);
    puthz(395,210,"查询",16,16,WHITE);
    puthz(215,295,"用户",16,16,WHITE);
    puthz(215,320,"查询",16,16,WHITE);
    puthz(395,295,"权限",16,16,WHITE);
    puthz(395,320,"管理",16,16,WHITE);
    puthz(305,360,"充值",16,16,WHITE);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons) //点击事件
        {
            if (mx >= 585 && mx <= 615 && my >= 5 && my <= 45 && buttons) //注销按钮点击退出
            {
                page = Choose_c("您是否要注销", "", &mx, &my, BROWN);
                if (page == 1)
                {
                    *judge = 1;
                    return;
                }
                else if (page == 0)
                {
                    *judge = 2;
                    return;
                }
            }
            else if (mx >= 0 && mx <= 50 && my >= 0 && my <= 50 && buttons) //进入个人中心
            {
                *judge = turnTo_c(person, 4);
                return;
            }
        }
        if (mx >= 278 && mx <= 362 && my >= 100 && my <= 177) //购票
        {
            if (sign[0] == 0)
            {
                mousehide(mx, my);
                sign[0] = 1;
                //DrawLine_j(320,100,275,180,365,180,DARKGRAY);
                DrawLine_j(320, 100, 275, 180, 365, 180, WHITE);
                getMousebk(mx, my);
            }
            if (buttons)
            {
               *judge=turnTo_c(person,5);
                return;
            } 
        }
        else if (mx >= 185 && mx <= 272 && my >= 183 && my <= 257) //修改密码
        {
            if (sign[0] == 0)
            {
                mousehide(mx, my);
                sign[0] = 1;
                DrawLine_j(185, 180, 275, 180, 230, 260, WHITE);
                getMousebk(mx, my);
            }
            if (buttons)
            {
                *judge = turnTo_c(person, 14);
                return;
            }
        }
        else if (mx >= 368 && mx <= 455 && my >= 183 && my <= 257) //账户查询
        {
            if (sign[0] == 0)
            {
                mousehide(mx, my);
                sign[0] = 1;
                DrawLine_j(365, 180, 455, 180, 410, 260, WHITE);
                getMousebk(mx, my);
            }
            if (buttons)
            {
               *judge=turnTo_c(person,6);
                return;
            } 
        }
        else if (mx >= 185 && mx <= 272 && my >= 263 && my <= 337) //用户查询
        {
            if (sign[0] == 0)
            {
                mousehide(mx, my);
                sign[0] = 1;
                DrawLine_j(230, 260, 185, 340, 275, 340, WHITE);
                getMousebk(mx, my);
            }
            if (buttons)
            {
                *judge = turnTo_c(person, 15);
                return;
            }
        }
        else if (mx >= 368 && mx <= 455 && my >= 263 && my <= 337) //权限管理
        {
            if (sign[0] == 0)
            {
                mousehide(mx, my);
                sign[0] = 1;
                DrawLine_j(410, 260, 365, 340, 455, 340, WHITE);
                getMousebk(mx, my);
            }
            if (buttons)
            {
                *judge = turnTo_c(person, 16);
                return;
            }
        }
        else if (mx >= 277 && mx <= 362 && my >= 343 && my <= 420) //充值
        {
            if (sign[0] == 0)
            {
                mousehide(mx, my);
                sign[0] = 1;
                DrawLine_j(275, 340, 365, 340, 320, 420, WHITE);
                getMousebk(mx, my);
            }
            if (buttons)
            {
                *judge = turnTo_c(person, 7);
                return;
            }
        }
        else if (sign[0] == 1 && !(mx >= 275 && mx <= 362 && my >= 100 && my <= 177) && !(mx >= 185 && mx <= 272 && my >= 183 && my <= 257) && !(mx >= 368 && mx <= 455 && my >= 183 && my <= 257) && !(mx >= 185 && mx <= 272 && my >= 263 && my <= 337) && !(mx >= 368 && mx <= 455 && my >= 263 && my <= 337) && !(mx >= 278 && mx <= 362 && my >= 343 && my <= 420))
        {
            mousehide(mx, my);
            DrawStar_j();
            sign[0] = 0;
            getMousebk(mx, my);
        }
    }
}
/**********************************************************
Function:  run_check_Screen
Description：用户查询功能
Attention:  无
**********************************************************/
void run_check_Screen_j(setuser *person, int *judge, setuser *head)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区
    int i = 0;                   //标记用户总数
    int ordinary_user = 0;       //标记普通用户
    int run_manager = 0;         //标记运营管理员
    int control_manager = 0;     //标记调度管理员
    setuser *p = head->next;     //临时指针
    char str_money[5];
    char str_score[5];
    int cur_money = 0;
    int cur_score = 0;
    char user_num[3];
    char control_num[3];
    char run_num[3];
    char ordinary_num[3];

    settextstyle(0, 0, 1);
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(DARKGRAY);
    returnBtn_small_c(15, 15, LIGHTBLUE);

    puthz(50, 30, "用户总数：", 16, 16, YELLOW);
    puthz(180, 30, "普通用户数：", 16, 16, YELLOW);
    puthz(320, 30, "调度管理员数：", 16, 16, YELLOW);
    puthz(450, 30, "运营管理员数：", 16, 16, YELLOW);
    puthz(80, 80, "用户名", 16, 16, YELLOW);
    puthz(250, 80, "密码", 16, 16, YELLOW);
    puthz(350, 80, "权限码", 16, 16, YELLOW);
    puthz(450, 80, "余额", 16, 16, YELLOW);
    puthz(530, 80, "积分", 16, 16, YELLOW);

    //打印出所有用户的信息，并统计各类用户的数量
    while (p)
    {
        if (strcmp(p->class, "00000") == 0)
        {
            ordinary_user++;
        }
        else if (strcmp(p->class, "cjwzs") == 0)
        {
            control_manager++;
        }
        else if (strcmp(p->class, "jmxzs") == 0)
        {
            run_manager++;
        }
        outtextxy(50, 110 + 30 * i, p->accounts);
        outtextxy(240, 110 + 30 * i, p->code);
        outtextxy(350, 110 + 30 * i, p->class);
        cur_money = atoi(p->money);
        itoa(cur_money, str_money, 10);
        outtextxy(450, 110 + 30 * i, str_money);
        cur_score = atoi(p->score);
        itoa(cur_score, str_score, 10);
        outtextxy(530, 110 + 30 * i, str_score);
        i++;
        p = p->next;
    }
    itoa(i, user_num, 10);
    outtextxy(140, 35, user_num);
    itoa(i - run_manager - control_manager, ordinary_num, 10);
    outtextxy(280, 35, ordinary_num);
    itoa(control_manager, control_num, 10);
    outtextxy(430, 35, control_num);
    itoa(run_manager, run_num, 10);
    outtextxy(560, 35, run_num);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            if (mx > 10 && mx <= 40 && my >= 10 && my <= 50 && buttons)
            {
                *judge = turnTo_c(person, 13);
                return;
            }
        }
    }
}
void Draw_poly1_j()
{
    line(320, 120, 200, 170);
    line(200, 170, 320, 220);
    line(320, 220, 440, 170);
    line(440, 170, 320, 120);
}
void Draw_poly2_j()
{
    line(320, 270, 200, 320);
    line(200, 320, 320, 370);
    line(320, 370, 440, 320);
    line(440, 320, 320, 270);
}
/**********************************************************
Function:  run_power_Screen
Description：管理用户权限功能
Attention:  无
**********************************************************/
void run_power_Screen_j(setuser *person, int *judge, setuser *head)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变
    int sign = 0;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(DARKGRAY);
    returnBtn_small_c(15, 15, LIGHTBLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    setcolor(YELLOW);
    Draw_poly1_j();
    Draw_poly2_j();
    puthz(80, 22, "您可以选择：", 16, 16, WHITE);
    puthz(255, 155, "更改权限", 32, 32, WHITE);
    puthz(255, 305, "删除用户", 32, 32, WHITE);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            if (mx > 10 && mx <= 40 && my >= 10 && my <= 50 && buttons)
            {
                *judge = turnTo_c(person, 13);
                return;
            }
        }
        if (mx >= 200 && mx <= 440 && my >= 120 && my <= 220) //更改权限
        {
            if (sign == 0)
            {
                mousehide(mx, my);
                setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
                setcolor(LIGHTBLUE);
                Draw_poly1_j();
                sign = 1;
                getMousebk(mx, my);
            }
            if (buttons)
            {
                *judge = turnTo_c(person, 17);
                return;
            }
        }
        else if (mx >= 200 && my <= 440 && my >= 270 && my <= 370) //删除用户
        {
            if (sign == 0)
            {
                mousehide(mx, my);
                setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
                setcolor(LIGHTBLUE);
                Draw_poly2_j();
                sign = 1;
                getMousebk(mx, my);
            }
            if (buttons)
            {
                *judge = turnTo_c(person, 18);
                return;
            }
        }
        else if (sign == 1 && !(mx >= 200 && mx <= 440 && my >= 120 && my <= 220) && !(mx >= 200 && my <= 440 && my >= 270 && my <= 370))
        {
            mousehide(mx, my);
            setcolor(YELLOW);
            Draw_poly1_j();
            Draw_poly2_j();
            sign = 0;
            getMousebk(mx, my);
        }
    }
}
/**********************************************************
Function:  Draw_frame1
Description：更改权限操作框
Attention:  无
**********************************************************/
void Draw_frame1_j(int x, int y, int color)
{
    setlinestyle(0, 0, 1);
    setcolor(color);
    puthz(240 + x, 110 + y, "您可以将普通用户提升为管理员：", 16, 16, WHITE);
    puthz(160 + x, 157 + y, "用户账号", 16, 16, WHITE);
    puthz(160 + x, 207 + y, "提升选项", 16, 16, WHITE);
    rectangle(x + 250, y + 150, x + 460, y + 180); //账号输入框
    rectangle(x + 250, y + 200, x + 350, y + 230); //运营管理员选项框
    rectangle(x + 360, y + 200, x + 460, y + 230); //调度管理员选项框
    puthz(x + 260, y + 207, "运营管理员", 16, 16, LIGHTBLUE);
    puthz(x + 370, y + 207, "调度管理员", 16, 16, LIGHTBLUE);
    //rectangle(x+90,y+100,x+260,y+130);//确认密码输入框
    setcolor(LIGHTRED);
    setfillstyle(1, LIGHTRED);
    bar(x + 325, y + 250, x + 380, y + 280); //确认按钮
    puthz(x + 337, y + 257, "确认", 16, 16, WHITE);
}

/**********************************************************
Function:  run_power_Screen
Description：将普通用户的权限提升为管理员
Attention:  无
**********************************************************/
void change_power_Screen_j(setuser *person, int *judge, setuser *head)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变
    int x = 0, y = 0;            //平移量
    int sign[3] = {0, 0, 0};     //sign[0]标志输入账户框是否被点击，sign[1]标志运营管理员框是否被点击，sign[2]标志调度管理员是否被点击
    int key;
    int input_num = 0; //标志输入了几个字符
    char place[14];    //字符缓存，最多可以存13位，在用户输入第13位的时候会有提示
    int flag = 0;      //标志账号不可多于12位的提示
    //int flag2=0;//给出“请输入普通用户账号”的提示
    int find = 0;
    setuser *p; //临时指针
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(DARKGRAY);
    returnBtn_small_c(15, 15, LIGHTBLUE);
    Draw_frame1_j(x, y, LIGHTBLUE); //初始位置x，y都为0，之后可以通过xy的值进行平移

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            if (mx > 10 && mx <= 40 && my >= 10 && my <= 50 && buttons)
            {
                *judge = turnTo_c(person, 16);
                return;
            }
            if (mx >= (250 + x) && mx <= (460 + x) && my >= (150 + y) && my <= (180 + y) && sign[0] == 0 && buttons) //此时账号框没有被点击过
            {
                mousehide(mx, my);
                setcolor(GREEN);
                setlinestyle(0, 0, 3);
                rectangle(x + 250, y + 150, x + 460, y + 180); //账号输入框加绿
                //choose[0]=1;
                sign[0] = 1;
                getMousebk(mx, my);
            }
            if (mx >= (250 + x) && mx <= (350 + x) && my >= (200 + y) && my <= (230 + y) && sign[1] == 0 && buttons) //运营管理员选项框
            {
                mousehide(mx, my);
                setcolor(GREEN);
                setlinestyle(0, 0, 3);
                rectangle(x + 250, y + 200, x + 350, y + 230); //运营管理员选项框变绿
                setcolor(DARKGRAY);
                rectangle(x + 360, y + 200, x + 460, y + 230); //调度管理员选项框先用背景色涂掉
                setlinestyle(0, 0, 1);
                setcolor(LIGHTBLUE);
                rectangle(x + 360, y + 200, x + 460, y + 230); //调度管理员选项框再用蓝色重新画
                //choose[0]=1;
                sign[1] = 1;
                sign[2] = 0;
                getMousebk(mx, my);
            }
            if (mx >= (360 + x) && mx <= (460 + x) && my >= (200 + y) && my <= (230 + y) && sign[2] == 0 && buttons) //调度管理员选项框
            {
                mousehide(mx, my);
                setcolor(GREEN);
                setlinestyle(0, 0, 3);
                rectangle(x + 360, y + 200, x + 460, y + 230); //调度管理员选项框变绿
                setcolor(DARKGRAY);
                rectangle(x + 250, y + 200, x + 350, y + 230); //运营管理员选项框先用背景色涂掉
                setlinestyle(0, 0, 1);
                setcolor(LIGHTBLUE);
                rectangle(x + 250, y + 200, x + 350, y + 230); //运营管理员选项框再用蓝色重新画
                //choose[0]=1;
                sign[1] = 0;
                sign[2] = 1;
                getMousebk(mx, my);
            }
            if (mx >= (x + 325) && mx <= (x + 380) && my >= (y + 250) && my <= (y + 280) && buttons && sign[0] == 1 && (sign[1] || sign[2]))
            {
                //判断，给出提示（成功or失败），改变用户的权限码change_class_j----customer
                mousehide(mx, my);
                p = head->next;

                while (p)
                {
                    if (strcmp(place, p->accounts) == 0)
                    {
                        find = 1; //代表账号是存在的
                        if (strcmp(p->class, "jmxzs") == 0 || strcmp(p->class, "cjwzs") == 0)
                        {
                            puthz(240, 80, "请输入普通用户的账号！", 16, 16, RED);
                            delay(800);
                            *judge = turnTo_c(person, 17);
                            return;
                        }
                        else if (strcmp(p->class, "00000") == 0)
                        {
                            //setfillstyle(1, DARKGRAY);
                            //bar(240, 30, 450, 50);
                            //mousehide(mx, my);
                            puthz(240, 30, "操作成功！", 16, 16, RED);
                            change_class_j(p, head, sign[1], sign[2]);
                            delay(800);
                            *judge = turnTo_c(person, 16);
                            return;
                        }
                    }
                    p = p->next;
                }
                puthz(240, 80, "该账号不存在！", 16, 16, RED);
                delay(800);
                *judge = turnTo_c(person, 17);
                return;
            }
        }
        //输入
        settextstyle(SMALL_FONT, HORIZ_DIR, 7);
        setcolor(BLUE);
        if (sign[0] == 1)
        {
            key = 0; //重置键值并得到新键值
            temp[0] = '\0';
            if (kbhit() != 0) //如果检测到键盘输入
            {
                mousehide(mx, my);
                key = bioskey(0);
                if (key != 0xe08 && input_num >= 0 && input_num < 12) //如果输入不是退格键
                {
                    if (searchKeyValue(key) != '\0') //其中输入的是字母或者数字
                    {
                        input_num++; //字符数加一
                        //setfillstyle(1,DARKGRAY);
                        //bar(305+i[0]*12,153,305+(i[0]+1)*12,177);
                        settextstyle(SMALL_FONT, HORIZ_DIR, 7);
                        setcolor(BLUE);
                        temp[0] = searchKeyValue(key);
                        place[input_num - 1] = temp[0];
                        place[input_num] = '\0';
                        outtextxy(255 + input_num * 12, 153, temp);
                    }
                }
                else if (key == 0xe08 && input_num > 0) //如果按了回删键
                {
                    input_num--;
                    setfillstyle(1, DARKGRAY);
                    bar(265 + input_num * 12, 153, 265 + (input_num + 1) * 12, 177);
                    place[input_num - 1] = '\0';
                }
                getMousebk(mx, my);
            }
            if (strlen(place) > 12)
            {
                puthz(240, 80, "账号不可多于12位！", 16, 16, RED);
                flag = 1;
            }
            if (strlen(place) <= 12 && sign[0] == 1 && flag == 1)
            {
                setfillstyle(1, DARKGRAY);
                bar(240, 30, 450, 50);
                flag = 0;
            }
        }
    }
}
void Draw_frame2_j(int x, int y, int color)
{
    setlinestyle(0, 0, 1);
    setcolor(color);
    puthz(220 + x, 110 + y, "您可以将普通用户或调度管理员删除：", 16, 16, WHITE);
    puthz(160 + x, 157 + y, "用户账号", 16, 16, WHITE);
    rectangle(x + 250, y + 150, x + 460, y + 180); //账号输入框
    setcolor(LIGHTRED);
    setfillstyle(1, LIGHTRED);
    bar(x + 325, y + 200, x + 380, y + 230); //确认按钮
    puthz(x + 337, y + 207, "确认", 16, 16, WHITE);
}
/**********************************************************
Function:  delete_user_Screen
Description：删除普通用户信息
Attention:  无
**********************************************************/
void delete_user_Screen_j(setuser *person, int *judge, setuser *head)
{
    int buttons, mx, my;         //鼠标相关变量
    char temp[2] = {'\0', '\0'}; //用于吸收键盘缓冲区的变
    int sign = 0;
    char place[14];
    int key;
    int input_num = 0;
    int flag = 0; //账号不可多于12位的提示
    int x = 0, y = 0;
    int find = 0;
    setuser *p;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(DARKGRAY);
    returnBtn_small_c(15, 15, LIGHTBLUE);
    Draw_frame2_j(0, 0, LIGHTBLUE);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            if (mx > 10 && mx <= 40 && my >= 10 && my <= 50 && buttons)
            {
                *judge = turnTo_c(person, 16);
                return;
            }
            if (mx >= (250 + x) && mx <= (460 + x) && my >= (150 + y) && my <= (180 + y) && sign == 0 && buttons) //此时账号框没有被点击过
            {
                mousehide(mx, my);
                setcolor(GREEN);
                setlinestyle(0, 0, 3);
                rectangle(x + 250, y + 150, x + 460, y + 180); //账号输入框加绿
                //choose[0]=1;
                sign = 1;
                getMousebk(mx, my);
            }
            if (mx >= (x + 325) && mx <= (x + 380) && my >= (y + 200) && my <= (y + 230) && buttons && sign == 1)
            {
                mousehide(mx, my);
                p = head->next;

                while (p)
                {
                    if (strcmp(place, p->accounts) == 0)
                    {
                        find = 1; //代表账号是存在的
                        if (strcmp(p->class, "jmxzs") == 0)
                        {
                            puthz(240, 80, "您不可删除运营管理员的账号！", 16, 16, RED);
                            delay(1000);
                            *judge = turnTo_c(person, 18);
                            return;
                        }
                        else
                        {
                            puthz(240, 30, "操作成功！", 16, 16, RED);
                            delete_user_j(p, head);
                            delay(1000);
                            *judge = turnTo_c(person, 16);
                            return;
                        }
                    }
                    p = p->next;
                }
                puthz(240, 80, "该账号不存在！", 16, 16, RED);
                delay(800);
                *judge = turnTo_c(person, 18);
                return;
            }
        }
        //输入
        settextstyle(SMALL_FONT, HORIZ_DIR, 7);
        setcolor(BLUE);
        if (sign == 1)
        {
            key = 0; //重置键值并得到新键值
            temp[0] = '\0';
            if (kbhit() != 0) //如果检测到键盘输入
            {
                mousehide(mx, my);
                key = bioskey(0);
                if (key != 0xe08 && input_num >= 0 && input_num < 12) //如果输入不是退格键
                {
                    if (searchKeyValue(key) != '\0') //其中输入的是字母或者数字
                    {
                        input_num++; //字符数加一
                        settextstyle(SMALL_FONT, HORIZ_DIR, 7);
                        setcolor(BLUE);
                        temp[0] = searchKeyValue(key);
                        place[input_num - 1] = temp[0];
                        place[input_num] = '\0';
                        outtextxy(255 + input_num * 12, 153, temp);
                    }
                }
                else if (key == 0xe08 && input_num > 0) //如果按了回删键
                {
                    input_num--;
                    setfillstyle(1, DARKGRAY);
                    bar(265 + input_num * 12, 153, 265 + (input_num + 1) * 12, 177);
                    place[input_num - 1] = '\0';
                }
                getMousebk(mx, my);
            }
            if (strlen(place) > 12)
            {
                puthz(240, 80, "账号不可多于12位！", 16, 16, RED);
                flag = 1;
            }
            if (strlen(place) <= 12 && sign == 1 && flag == 1)
            {
                setfillstyle(1, DARKGRAY);
                bar(240, 30, 450, 50);
                flag = 0;
            }
        }
    }
}
