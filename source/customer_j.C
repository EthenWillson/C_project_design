/**********************************************************
此文件专门存放用户相关的函数
作者：江明轩
**********************************************************/


#include"customer_j.h"
#include"common_c.h"



void DrawbuyScreen_j(setuser *person,int *judge,setuser *head);
void DrawcheckScreen_j(setuser *person,int *judge,setuser *head);
void DrawchargeScreen_j(setuser *person,int *judge,setuser *head);
//void Drawtipframe();
void changemoney_j(int n,setuser *person,int radix,setuser *head);

/**********************************************************
Function:  Drawtipframe
Description：	画出购票提示框
Attention:  无
**********************************************************/
/*
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
    
}
*/
/**********************************************************
Function:  changemoney
Description：	改变文件中用户余额
Attention:  无
**********************************************************/
void changemoney_j(int n,setuser *person,int radix,setuser *head)//文件操作
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
    int checkclick;//检验点击了几次
    mouseInit(&mx, &my, &buttons);
	cleardevice();
    setbkcolor(WHITE);
	//DrawBeautifulFrame_c();
    checkclick=0;
    

    //画出返回按钮
	returnBtn_c(550,210,GREEN);


    setcolor(BROWN);
    setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
    line(460,0,460,75);
    line(460,75,640,75);

    setlinestyle(0,0,3);
    setcolor(LIGHTCYAN);
    line(500,10,550,10);
    outtextxy(560,0,"1");
    puthz(570,5,"号线",16,16,LIGHTBLUE);
    setcolor(LIGHTGREEN);
    line(500,30,550,30);
    outtextxy(560,20,"2");
    puthz(570,25,"号线",16,16,LIGHTGREEN);
    setcolor(YELLOW);
    line(500,50,550,50);
    outtextxy(560,40,"3");
    puthz(570,45,"号线",16,16,YELLOW);
    puthz(180,0,"武汉地铁交通线",32,32,BROWN);

    Drawstation1_j();
    Drawstation2_j();
    Drawstation4_j();
    DrawCircles_j();
    
    //购票按钮
    setcolor(GREEN);
    circle(580,150,30);
    puthz(565,142,"购票",16,16,CYAN);
    puthz(30,5,"请先点击起点",16,16,RED);
    puthz(30,25,"再点击终点",16,16,RED);
    puthz(30,45,"最后点击购票按钮",16,16,RED);

    

    

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
            if(mx >= 555 && mx <= 605 && my >= 125 && my <= 175 && buttons && checkclick==0)//第一次点击
            {
                checkclick=1;//代表已经点击了一次
                setfillstyle(1,WHITE);
                
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
    changemoney_j(0,person,10,head);
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
                setfillstyle(1,WHITE);
                bar(60,340,250,370);
                changemoney_j(10,person,10,head);//充值10元，修改person->money的值
                //changemoney_j(person,head);
                puthz(80,350,"您已成功充值10元",16,16,RED);
            }
            if (mx >= 280 && mx <= 370 && my >= 150&& my <= 200 && buttons)
            {
                setfillstyle(1,WHITE);
                bar(60,340,250,370);
                changemoney_j(20,person,10,head);//充值20元，修改person->money的值
                //changemoney_j(person,head);
                puthz(80,350,"您已成功充值20元",16,16,RED);
            }
            if (mx >= 460 && mx <= 550 && my >= 150&& my <= 200 && buttons)
            {
                setfillstyle(1,WHITE);
                bar(60,340,250,370);
                changemoney_j(50,person,10,head);
                //changemoney_j(person,head);
                puthz(80,350,"您已成功充值50元",16,16,RED);
            }
            if (mx >= 100 && mx <= 190 && my >= 280&& my <= 330 && buttons)
            {
                
                setfillstyle(1,WHITE);
                bar(60,340,250,370);changemoney_j(100,person,10,head);
                //changemoney_j(person,head);
                puthz(80,350,"您已成功充值100元",16,16,RED);
            }
            if (mx >= 280 && mx <= 370 && my >= 280&& my <= 330 && buttons)
            {
                
                setfillstyle(1,WHITE);
                bar(60,340,250,370);changemoney_j(200,person,10,head);
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