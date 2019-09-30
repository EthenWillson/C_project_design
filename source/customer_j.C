/**********************************************************
此文件专门存放用户相关的函数
作者：江明轩
**********************************************************/


#include"customer_j.h"
#include"common_c.h"



void DrawbuyScreen_j(setuser *person,int *judge,setuser *head);
void DrawcheckScreen_j(setuser *person,int *judge,setuser *head);
void DrawchargeScreen_j(setuser *person,int *judge,setuser *head);
void Drawtipframe();
void changemoney(int n,setuser *person,int radix,setuser *head);

/**********************************************************
Function:  Drawtipframe
Description：	画出购票提示框
Attention:  无
**********************************************************/
void Drawtipframe()
{
    int buttons,mx,my;//鼠标相关变量
    mouseInit(&mx, &my, &buttons);
    
    setfillstyle(1,DARKGRAY);
    bar(55,15,170,60);
    setfillstyle(1,WHITE);
    bar(60,20,165,55);

    puthz(60,20,"请先点击起点",16,16,RED);
    puthz(60,40,"再点击终点",16,16,RED);
    /*
    while(1)
    {
        newxy(&mx,&my,&buttons);
        if(buttons)
        {
            if( mx >= 375 && mx <= 410 && my >= 275 && my <= 290 && buttons)
            {

              
            }
        }
    }
    */
}
/**********************************************************
Function:  changemoney
Description：	改变文件中用户余额
Attention:  无
**********************************************************/
void changemoney(int n,setuser *person,int radix,setuser *head)//文件操作
{
    int number;
	FILE *fp=NULL; //打开文件的指针
    setuser *ph=head->next;
    
    number=atoi(person->money);
	itoa(n+number,person->money,radix);	//用于修改person->money的值，字符串与整型之间的转换

    for(ph=head->next;ph!=NULL;ph=ph->next)
    {
        if( strcmp(ph->accounts,person->accounts)==0 )
        {
            strcpy(ph->money,person->money);//修改链表中person->money值
        }
    }
    if ((fp = fopen("data_c\\user\\usernew.txt", "wt")) == NULL)//以写的方式新建一个文件
    {
        closegraph();
        printf("Can't open usernew.txt");
    }
    for(ph=head->next;ph!=NULL;ph=ph->next)
    {
        fputc('@',fp);//@标志一个用户的开头
        fputs(ph->accounts,fp);
        fputc('*',fp);//*标志用户密码的开头
        fputs(ph->code,fp);
        fputc('#',fp);//#标志用户的权限码
        fputs(ph->class,fp);
        fputc('$',fp);//$标志用户余额
        fputs(ph->money,fp);
    }
        fclose(fp);
        remove("data_c\\user\\userinf.txt");
        rename("data_c\\user\\usernew.txt","data_c\\user\\userinf.txt");
        return 0;
}

/**********************************************************
Function:  DrawbuyScreen
Description：	画出购票界面，实现购票功能
Attention:  无
**********************************************************/
void DrawbuyScreen_j(setuser *person,int *judge,setuser *head)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
    int i;//划线循环变量
    int checkclick=0;
    mouseInit(&mx, &my, &buttons);
	cleardevice();
    setbkcolor(WHITE);
	DrawBeautifulFrame_c();
    

    //画出返回按钮
	returnBtn_c(550,210,GREEN);


    setcolor(BROWN);
    Drawstation();
    outtextxy(26,65,"1");
    puthz(35,71,"号线",16,16,BROWN);

    outtextxy(26,220,"2");
    puthz(35,226,"号线",16,16,BROWN);

    outtextxy(26,375,"3");
    puthz(35,381,"号线",16,16,BROWN);

    puthz(200,32,"武汉地铁交通线",32,32,BROWN);
/*
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
    circle(528,80,8);
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

    puthz(72,245,"天",16,16,BROWN);
    puthz(72,263,"河",16,16,BROWN);
    puthz(72,281,"机",16,16,BROWN);
    puthz(72,299,"场",16,16,BROWN);
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
    puthz(352,245,"光",16,16,BROWN);
    puthz(352,263,"谷",16,16,BROWN);
    puthz(352,281,"大",16,16,BROWN);
    puthz(352,299,"道",16,16,BROWN);
    puthz(422,245,"佳",16,16,BROWN);
    puthz(422,263,"园",16,16,BROWN);
    puthz(422,281,"路",16,16,BROWN);
    puthz(492,245,"佛",16,16,BROWN);
    puthz(492,263,"祖",16,16,BROWN);
    puthz(492,281,"岭",16,16,BROWN);

    
    

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
    circle(528,390,8);
    circle(528,390,7);
    setcolor(GREEN);
    for(i=0;i<=7;i++)
    {
        line(90+56*i,390,126+56*i,390);
    }
*/

    //购票按钮
    setcolor(GREEN);
    circle(580,150,30);
    puthz(565,142,"购票",16,16,CYAN);
    puthz(60,30,"请点击购票按钮",16,16,RED);
    

    while(1)
	{
		newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 550 && mx <= 610 && my >= 210&& my <= 270 && buttons)//返回按钮点击返回
			{
				*judge=turnTo_c(person,-1);
				return;
			}
            if(mx >= 555 && mx <= 605 && my >= 125 && my <= 175 && buttons && checkclick==0)//第一次点击购票按钮
            {
                checkclick=1;//代表已经点击了一次
                setfillstyle(1,WHITE);
                bar(60,20,200,50);
                Drawtipframe();//画出提示框
            }
            //if(mx>=)
        }
    }
}
/**********************************************************
Function:  DrawcheckScreen
Description：画出余额查询界面
Attention:  无
**********************************************************/
void DrawcheckScreen_j(setuser *person,int *judge,setuser *head)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
    mouseInit(&mx, &my, &buttons);
	cleardevice();
    setbkcolor(WHITE);
	DrawBeautifulFrame_c();

    puthz(90, 28, "您好！尊敬的：", 16, 16, CYAN);
    setcolor(MAGENTA);
	outtextxy(220,25,person->accounts);
    puthz(400, 435, "关于我们", 16, 16,MAGENTA );
	puthz(540 ,435, "帮助", 16, 16, MAGENTA);
	
	setlinestyle(0, 0, 1);
	setcolor(LIGHTRED);
	rectangle(398,433,465,453);//关于我们的位置
	rectangle(538,433,571,453);//帮助的位置

    //画出返回按钮
	returnBtn_c(300,400,GREEN);

    puthz(90,95,"您的余额为：",16,16,CYAN);
    changemoney(0,person,10,head);
    setcolor(MAGENTA);
    outtextxy(200,90,person->money);

    puthz(90,160,"您可以选择：",16,16,CYAN);
    setfillstyle(1,LIGHTCYAN);
    
    bar(100,220,280,310);
    bar(330,220,510,310);
    puthz(160, 243, "购票", 32, 32,MAGENTA );
    puthz(357, 243, "账户充值", 32, 32,MAGENTA );


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
            if (mx >= 100 && mx <= 280 && my >= 220&& my <= 310 && buttons)//点击购票方框，返回购票界面
            {
                *judge=turnTo_c(person,5);
                return;
            }
            if (mx >= 330 && mx <= 510 && my >= 220&& my <= 310 && buttons)//点击账户充值方框，返回账户充值界面
            {
                *judge=turnTo_c(person,7);
                return;
            }
        }
    }
    
}
/**********************************************************
Function:  DrawchargeScreen
Description：画充值界面，并且实现充值功能
Attention:  无
**********************************************************/
void DrawchargeScreen_j(setuser *person,int *judge,setuser *head)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
    mouseInit(&mx, &my, &buttons);
	cleardevice();
    setbkcolor(WHITE);
	DrawBeautifulFrame_c();
    puthz(90, 28, "您好！尊敬的：", 16, 16, GREEN);
	outtextxy(220,25,person->accounts);
    puthz(400, 435, "关于我们", 16, 16,MAGENTA );
	puthz(540 ,435, "帮助", 16, 16, MAGENTA);
	
	setlinestyle(0, 0, 1);
	setcolor(LIGHTRED);
	rectangle(398,433,465,453);//关于我们的位置
	rectangle(538,433,571,453);//帮助的位置
    //画出返回按钮
	returnBtn_c(300,400,GREEN);

    puthz(80,80,"请选择充值金额：",16,16,GREEN);
    setlinestyle(0, 0, 1);
	setcolor(YELLOW);
    //画充值框
    rectangle(100,150,190,200);
    rectangle(280,150,370,200);
    rectangle(460,150,550,200);
    rectangle(100,280,190,330);
    rectangle(280,280,370,330);
    rectangle(460,280,550,330);

    puthz(122,170,"10元",16,16,LIGHTCYAN);
    puthz(302,170,"20元",16,16,LIGHTCYAN);
    puthz(482,170,"50元",16,16,LIGHTCYAN);
    puthz(112,300,"100元",16,16,LIGHTCYAN);
    puthz(292,300,"200元",16,16,LIGHTCYAN);
    puthz(482,295,"自定义",16,16,LIGHTCYAN);
    



    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 300 && mx <= 360 && my >= 400&& my <= 460 && buttons)//返回按钮点击返回
			{
				*judge=turnTo_c(person,-1);
				return;
			}
            if (mx >= 100 && mx <= 190 && my >= 150&& my <= 200 && buttons)
            {
                changemoney(10,person,10,head);//充值10元，修改person->money的值
                //changemoney_j(person,head);
                puthz(80,350,"您已成功充值10元",16,16,RED);
            }
            if (mx >= 280 && mx <= 370 && my >= 150&& my <= 200 && buttons)
            {
                changemoney(20,person,10,head);//充值20元，修改person->money的值
                //changemoney_j(person,head);
                puthz(80,350,"您已成功充值20元",16,16,RED);
            }
            if (mx >= 460 && mx <= 550 && my >= 150&& my <= 200 && buttons)
            {
                changemoney(50,person,10,head);
                //changemoney_j(person,head);
                puthz(80,350,"您已成功充值50元",16,16,RED);
            }
            if (mx >= 100 && mx <= 190 && my >= 280&& my <= 330 && buttons)
            {
                changemoney(100,person,10,head);
                //changemoney_j(person,head);
                puthz(80,350,"您已成功充值100元",16,16,RED);
            }
            if (mx >= 280 && mx <= 370 && my >= 280&& my <= 330 && buttons)
            {
                changemoney(200,person,10,head);
                //changemoney_j(person,head);
                puthz(80,350,"您已成功充值200元",16,16,RED);
            }
            if (mx >= 460 && mx <= 550 && my >= 280&& my <= 330 && buttons)
            {
                //待开发
            }

        }  
    }
    
}