/**********************************************************
此文件专门存放帮助界面相关的函数
作者：陈俊玮
**********************************************************/
#include"help_c.h"
#include"common_c.h"
void DrawhelpScreen_c(int *judge)
{
    int buttons, mx, my;         //鼠标相关变量
    int mouseover[4]={0,0,0,0};
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//返回按钮

    puthz(90,40,"武汉地铁交通模拟系统使用说明",32,32,CYAN);
    DrawListbutton(200, 120, LIGHTGRAY,LIGHTGRAY,"登陆及注册");
    DrawListbutton(200, 190, LIGHTGRAY,LIGHTGRAY,"充值和购票");
    DrawListbutton(200, 260, LIGHTGRAY,LIGHTGRAY,"账号与记录");
    DrawListbutton(200, 330, LIGHTGRAY,LIGHTGRAY,"管理加调度");
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (mx >= 200 && mx <= 440 && my >= 120 && my <= 150 && mouseover[0]==0) //鼠标移至登陆按钮
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,110,500,160);
            DrawListbutton(210, 110, LIGHTBLUE , LIGHTBLUE,"登陆及注册");
            mouseover[0]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 200 && mx <= 440 && my >= 120 && my <= 150 )&& mouseover[0]==1) //鼠标移出登陆按钮
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,100,500,160);
            DrawListbutton(200, 120, LIGHTGRAY,LIGHTGRAY,"登陆及注册");
            mouseover[0]=0;
            getMousebk(mx,my);
        }
        if (mx >= 200 && mx <= 440 && my >= 190 && my <= 220 && mouseover[1]==0) //鼠标移至充值按钮
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,160,500,230);
            DrawListbutton(210, 180, LIGHTBLUE , LIGHTBLUE,"充值和购票");
            mouseover[1]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 200 && mx <= 440 && my >= 190 && my <= 220 )&& mouseover[1]==1) //鼠标移出充值按钮
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,160,500,230);
            DrawListbutton(200, 190, LIGHTGRAY,LIGHTGRAY,"充值和购票");
            mouseover[1]=0;
            getMousebk(mx,my);
        }
        if (mx >= 200 && mx <= 440 && my >= 260 && my <= 290 && mouseover[2]==0) //鼠标移至账号按钮
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,230,500,300);
            DrawListbutton(210, 250, LIGHTBLUE,LIGHTBLUE,"账号与记录");
            mouseover[2]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 200 && mx <= 440 && my >= 260 && my <= 290 )&& mouseover[2]==1) //鼠标移出账号按钮
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,230,500,300);
            DrawListbutton(200, 260, LIGHTGRAY,LIGHTGRAY,"账号与记录");
            mouseover[2]=0;
            getMousebk(mx,my);
        }
        if (mx >= 200 && mx <= 440 && my >= 330 && my <= 360 && mouseover[3]==0) //鼠标移至管理按钮
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,300,500,370);
            DrawListbutton(210, 320, LIGHTBLUE,LIGHTBLUE,"运营加调度");
            mouseover[3]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 200 && mx <= 440 && my >= 330 && my <= 360 )&& mouseover[3]==1) //鼠标移出管理按钮
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,300,500,370);
            DrawListbutton(200, 330, LIGHTGRAY,LIGHTGRAY,"运营加调度");
            mouseover[3]=0;
            getMousebk(mx,my);
        }
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //返回按钮点击返回
            {
                *judge = 1;
                return;
            }
            else if (mx >= 200 && mx <= 440 && my >= 120 && my <= 150) //点击登陆按钮
            {
                *judge = 21;
                return;
            }
            else if (mx >= 200 && mx <= 440 && my >= 190 && my <= 220) //点击充值和购票按钮
            {
                *judge = 22;
                return;
            }
            else if (mx >= 200 && mx <= 440 && my >= 260 && my <= 290) //点击账号与记录按钮
            {
                *judge = 23;
                return;
            }
            else if (mx >= 200 && mx <= 440 && my >= 330 && my <= 360) //点击管理加调度按钮
            {
                *judge = 24;
                return;
            }
        }
    }   
}
/**********************************************************
Function:      DrawLoginHelp
Description：	画出登陆与注册帮助界面 代号21
Input:   图标的坐标；颜色
**********************************************************/
void DrawLoginHelp(int *judge)
{
    int buttons, mx, my;         //鼠标相关变量
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//返回按钮
    puthz(248,40,"登陆与注册",32,32,CYAN);
    puthz(70,90,"·登陆：",16,16,LIGHTGRAY);
    puthz(80,120,"·用户登陆：对于已经注册过的普通用户，点击右上角用户按钮，在",16,16,LIGHTGRAY);
    puthz(80,140,"框体中输入用户名和密码，单击登录按钮进入系统。",16,16,LIGHTGRAY);
    puthz(80,170,"·管理员登陆：对于已经注册过的管理员，点击右上角管理员按钮，",16,16,LIGHTGRAY);
    puthz(80,190,"在框体中输入用户名、密码及权限码，单击登录按钮进入系统。",16,16,LIGHTGRAY);
    puthz(70,230,"·注册：",16,16,LIGHTGRAY);
    puthz(80,260,"·用户注册：对于新用户，点击右上角用户按钮，在框体中输入想要",16,16,LIGHTGRAY);
    puthz(80,280,"创建的用户名和密码，单击自动注册按钮即可注册账户并进入系统。",16,16,LIGHTGRAY);
    puthz(80,310,"·管理员注册：对于新管理员，点击右上角管理员按钮，在框体中输",16,16,LIGHTGRAY);
    puthz(80,330,"入想要创建的用户名和密码，若为调度管理员权限码填写cjwzs，",16,16,LIGHTGRAY);
    puthz(80,350,"若为运营权限码填写jmxs，单击自动注册按钮即可注册账户并进",16,16,LIGHTGRAY);
    puthz(80,370,"入系统。",16,16,LIGHTGRAY);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //返回按钮点击返回
            {
                *judge = 20;
                return;
            }
        }
    }
}
/**********************************************************
Function:      DrawBuyHelp
Description：	画出充值和购票帮助界面 代号22
Input:   图标的坐标；颜色
**********************************************************/
void DrawBuyHelp(int *judge)
{
    int buttons, mx, my;         //鼠标相关变量
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//返回按钮
    puthz(248,40,"充值和购票",32,32,CYAN);
    puthz(70,100,"·充值：",16,16,LIGHTGRAY);
    puthz(80,130,"·用户充值：在用户主界面点击账户充值选项，进入充值界面，选择",16,16,LIGHTGRAY);
    puthz(80,150,"充值的金额，即可充值",16,16,LIGHTGRAY);
    puthz(80,180,"·管理员充值：调度管理员主界面点击左上角头像图标，进入管理员个",16,16,LIGHTGRAY);
    puthz(80,200,"人中心，点击账户充值；运营管理员点击首页六芒星账户充值选项。",16,16,LIGHTGRAY);
    puthz(70,240,"·购票：",16,16,LIGHTGRAY);
    puthz(80,270,"·用户购票：在用户主界面点击购票选项，进入购票界面，选择起点",16,16,LIGHTGRAY);
    puthz(80,290,"和终点后，点击购票",16,16,LIGHTGRAY);
    puthz(80,320,"·管理员购票：在管理员主界面点击太极下侧，进入购票界面；运营",16,16,LIGHTGRAY);
    puthz(80,340,"管理员点击六芒星购票选项",16,16,LIGHTGRAY);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //返回按钮点击返回
            {
                *judge = 20;
                return;
            }
        }
    }
}
/**********************************************************
Function:      DrawRecordHelp
Description：	画出账号与记录帮助界面 代号23
Input:   图标的坐标；颜色
**********************************************************/
void DrawRecordHelp(int *judge)
{
    int buttons, mx, my;         //鼠标相关变量
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//返回按钮
    puthz(248,40,"账号与记录",32,32,CYAN);
    puthz(70,100,"·修改密码：",16,16,LIGHTGRAY);
    puthz(80,130,"·用户：在用户主界面点击账户查询选项，进入账户查询界面，选择",16,16,LIGHTGRAY);
    puthz(80,150,"修改密码选项，按要求输入即可修改密码",16,16,LIGHTGRAY);
    puthz(80,180,"·管理员：调度管理员主界面点击左上角头像图标，进入管理员个人",16,16,LIGHTGRAY);
    puthz(80,200,"中心，点击账户查询；运营管理员点击六芒星修改密码选项",16,16,LIGHTGRAY);
    puthz(70,240,"·出行记录：",16,16,LIGHTGRAY);
    puthz(80,270,"·用户：在用户主界面点击账户查询选项，进入账户查询界面，选择",16,16,LIGHTGRAY);
    puthz(80,290,"购票记录选项可查看历史购票记录",16,16,LIGHTGRAY);
    puthz(80,320,"·管理员：在调度管理员个人中心点击账户查询选项；运营管理员点",16,16,LIGHTGRAY);
    puthz(80,340,"击六芒星账户查询选项，后续操作同用户",16,16,LIGHTGRAY);
    
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //返回按钮点击返回
            {
                *judge = 20;
                return;
            }
        }
    }
}
/**********************************************************
Function:      DrawManageHelp
Description：	画出管理加调度帮助界面 代号24
Input:   图标的坐标；颜色
**********************************************************/
void DrawManageHelp(int *judge)
{
    int buttons, mx, my;         //鼠标相关变量
    int mouseover=0;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//返回按钮
    puthz(298,40,"调度",32,32,CYAN);
    puthz(65,100,"·调度：",16,16,LIGHTGRAY);
    puthz(75,130,"·进入调度管理员主界面，点击太极上侧，进入调度界面，共有三个",16,16,LIGHTGRAY);
    puthz(85,150,"模块：",16,16,LIGHTGRAY);
    puthz(85,180,"·线路选择模块：右上角可选择控制的线路",16,16,LIGHTGRAY);
    puthz(85,210,"·调度主控模块：右侧模块可调整当前选择线路的列车速度，停站时",16,16,LIGHTGRAY);
    puthz(85,240,"间和发车间隔",16,16,LIGHTGRAY);
    puthz(85,270,"·站点信息模块：在地铁线上随意点击站点，左侧可显示站点的信息",16,16,LIGHTGRAY);
    puthz(75,300,"·若想重置模拟，点击右下角reset按钮",16,16,LIGHTGRAY);
    returnBtn_next_c(420,70,CYAN);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (mx >= 350 && mx <= 450 && my >= 40 && my <= 70 && mouseover==0) 
        {
            mousehide(mx,my);
            returnBtn_next_c(420,70,LIGHTBLUE);
            mouseover=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 350 && mx <= 450 && my >= 40 && my <= 70) && mouseover==1) 
        {
            mousehide(mx,my);
            returnBtn_next_c(420,70,CYAN);
            mouseover=0;
            getMousebk(mx,my);
        }
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //返回按钮点击返回
            {
                *judge = 20;
                return;
            }
            if (mx >= 350 && mx <= 450 && my >= 40 && my <= 70) //下一项到运营帮助界面
            {
                *judge = 27;
                return;
            }
        }
    }
}
/**********************************************************
Function:      DrawRunHelp
Description：	画出管理加调度帮助界面 代号27
Input:   图标的坐标；颜色
**********************************************************/
void DrawRunHelp(int *judge)
{
    int buttons, mx, my;         //鼠标相关变量
    int mouseover=0;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//返回按钮
    puthz(298,40,"运营",32,32,CYAN);
    puthz(65,100,"·运营：",16,16,LIGHTGRAY);
    puthz(75,130,"·进入运营管理员主界面，六芒星六个选项上，共有两个运营模块：",16,16,LIGHTGRAY);
    puthz(85,160,"·用户查询模块：可以查询已注册用户的各项信息",16,16,LIGHTGRAY);
    puthz(85,190,"·权限管理模块：可以修改用户的权限，删除用户",16,16,LIGHTGRAY);
    // puthz(85,210,"间和发车间隔",16,16,LIGHTGRAY);
    // puthz(85,240,"·站点信息模块：在地铁线上随意点击站点，左侧可显示站点的信息",16,16,LIGHTGRAY);
    // puthz(75,280,"·若想重置模拟，点击右下角reset按钮",16,16,LIGHTGRAY);
    returnBtn_small_c(240,40,CYAN);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (mx >= 250 && mx <= 280 && my >= 30 && my <= 80 && mouseover==0) 
        {
            mousehide(mx,my);
            returnBtn_small_c(240,40,LIGHTBLUE);
            mouseover=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 250 && mx <= 280 && my >= 30 && my <= 80) && mouseover==1) 
        {
            mousehide(mx,my);
            returnBtn_small_c(240,40,CYAN);
            mouseover=0;
            getMousebk(mx,my);
        }
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //返回按钮点击返回
            {
                *judge = 20;
                return;
            }
            if (mx >= 250 && mx <= 280 && my >= 30 && my <= 80) //上一项点击返回
            {
                *judge = 24;
                return;
            }
        }
    }
}
/**********************************************************
Function:      DrawListbutton
Description：	画出按钮框架
Input:   图标的坐标；颜色
**********************************************************/
void DrawListbutton(int x, int y, int bkcolor, int ccolor, char *str)
{
	setlinestyle(0, 0, 3);
	setcolor(bkcolor);
	// line(x, y + 120, x+40, y + 80);
	// line(x + 40, y + 80, x + 80, y + 80);
	// line(x + 80, y + 80 , x + 120, y + 120);
	// line(x + 120, y + 120 , x + 80, y + 160 );
	// line(x + 80, y + 160 , x + 40 , y + 160 );
	// line(x + 40, y + 160 , x + 0 , y + 120 );
	line(x + 20, y  , x + 220 , y  );
	line(x + 220, y  , x + 240 , y + 15 );
	line(x + 220, y + 30 , x + 240 , y + 15 );
	line(x + 220, y + 30 , x + 20 , y + 30 );
    line(x + 20, y  , x  , y + 15 );
    line(x , y + 15 , x + 20 , y + 30 );
    puthz(x+83,y+8,str,16,16,ccolor);
}