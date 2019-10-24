/**********************************************************
此文件专门存放用户相关的函数
作者：江明轩
**********************************************************/


#include"customer_j.h"
#include"common_c.h"



void DrawbuyScreen_j(setuser *person,int *judge,setuser *head,all_lines_stations *all);
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
void DrawbuyScreen_j(setuser *person,int *judge,setuser *head,all_lines_stations *all)
{
    int buttons,mx,my;//鼠标相关变量
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
    int i;//划线循环变量
    int sta_checkclick[5][10];//二维数组标志量，检验点击了几次（0表示没点击，1表示点击了）
    int flag;
    int start_station;//存储起点信息,比如12代表1号线第2站为起点
    int end_station;//存储终点信息，和上面一行差不多
    //char sss[10]="江明轩";
    flag=0;
    start_station=0;
    end_station=0;
    mouseInit(&mx, &my, &buttons);
	cleardevice();
    setbkcolor(WHITE);
	//DrawBeautifulFrame_c();
    //puthz(30,130,sss,16,16,RED);//这句话可以显示！
    //outtextxy(30,160,all->line1[1].x);

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
        if(buttons)//专门用来搞返回上个界面
        {
             if (mx >= 550 && mx <= 610 && my >= 210&& my <= 270 && buttons)//返回按钮点击返回
			{
				*judge=turnTo_c(person,3);
				return;
			}
        }
       
        
        /***************对于第一次点击起点站******************/
        if(buttons&&flag==0&&flag!=2)
        {
            //三条线的圈圈，并且显示出起点
            //1号线的
            if(mx >= 75 && mx <= 85 && my >= 95 && my <= 105 && buttons )//第一次点击
            {
                Draw_start_sta_j(80,100,&all->line1[1],&sta_checkclick[1][1],&start_station,&flag);
            }
            if(mx >= 135 && mx <= 145 && my >= 95 && my <= 105 && buttons )
            {
                Draw_start_sta_j(140,100,&all->line1[2],&sta_checkclick[1][2],&start_station,&flag);  
            }
            if(mx >= 195 && mx <= 205 && my >= 95 && my <= 105 && buttons )
            {
                Draw_start_sta_j(200,100,&all->line1[3],&sta_checkclick[1][3],&start_station,&flag);
            }
            if(mx >= 255 && mx <= 265 && my >= 95 && my <= 105 && buttons )//这个是循礼门站，1和2的交点，到时候要特殊处理
            {
                Draw_start_sta_j(260,100,&all->line1[4],&sta_checkclick[1][4],&start_station,&flag);
            }
            if(mx >= 315 && mx <= 325 && my >= 95 && my <= 105 && buttons )
            {
                Draw_start_sta_j(320,100,&all->line1[5],&sta_checkclick[1][5],&start_station,&flag);
            }
            if(mx >= 375 && mx <= 385 && my >= 95 && my <= 105 && buttons )
            {
                Draw_start_sta_j(380,100,&all->line1[6],&sta_checkclick[1][6],&start_station,&flag);
            }
            if(mx >= 435 && mx <= 445 && my >= 95 && my <= 105 && buttons )
            {
               Draw_start_sta_j(440,100,&all->line1[7],&sta_checkclick[1][7],&start_station,&flag);
            }
            if(mx >= 495 && mx <= 505 && my >= 95 && my <= 105 && buttons )
            {
                Draw_start_sta_j(500,100,&all->line1[8],&sta_checkclick[1][8],&start_station,&flag);
            }
            //2号线的
            if(mx >= 295 && mx <= 305 && my >= 65 && my <= 75 && buttons )//第一次点击
            {
                Draw_start_sta_j(300,170,&all->line2[1],&sta_checkclick[2][1],&start_station,&flag);
            }
            if(mx >= 255 && mx <= 265 && my >= 151 && my <= 161 && buttons )
            {
                Draw_start_sta_j(260,156,&all->line2[3],&sta_checkclick[2][3],&start_station,&flag);   
            }
                if(mx >= 255 && mx <= 265 && my >= 207 && my <= 217 && buttons )
                {
                    Draw_start_sta_j(260,212,&all->line2[4],&sta_checkclick[2][4],&start_station,&flag);
                }
                if(mx >= 255 && mx <= 265 && my >= 263 && my <= 273 && buttons )
                {
                    Draw_start_sta_j(260,268,&all->line2[5],&sta_checkclick[2][5],&start_station,&flag);
                }
                if(mx >= 255 && mx <= 265 && my >= 319 && my <= 329 && buttons )
                {
                    Draw_start_sta_j(260,324,&all->line2[6],&sta_checkclick[2][6],&start_station,&flag);//有个小的计算失误，但问题不大
                }                                                                                       //这两个draw距离其实是66
                if(mx >= 255 && mx <= 265 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_start_sta_j(260,380,&all->line2[7],&sta_checkclick[2][7],&start_station,&flag);
                }
                if(mx >= 195 && mx <= 205 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_start_sta_j(200,380,&all->line2[8],&sta_checkclick[2][8],&start_station,&flag);
                }
                if(mx >= 235 && mx <= 245 && my >= 405 && my <= 415 && buttons )
                {
                    Draw_start_sta_j(240,410,&all->line2[9],&sta_checkclick[2][9],&start_station,&flag);
                }
                //4号线的
                if(mx >= 75 && mx <= 85 && my >= 375 && my <= 385 && buttons )//第一次点击
                {
                    Draw_start_sta_j(80,380,&all->line4[1],&sta_checkclick[4][1],&start_station,&flag);
                }
                if(mx >= 135 && mx <= 145 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_start_sta_j(140,380,&all->line4[2],&sta_checkclick[4][2],&start_station,&flag);   
                }
                if(mx >= 315 && mx <= 325 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_start_sta_j(320,380,&all->line4[5],&sta_checkclick[4][5],&start_station,&flag);
                }
                if(mx >= 375 && mx <= 380 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_start_sta_j(380,380,&all->line4[6],&sta_checkclick[4][6],&start_station,&flag);
                }
                if(mx >= 435 && mx <= 445 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_start_sta_j(440,380,&all->line4[7],&sta_checkclick[4][7],&start_station,&flag);
                }
                if(mx >= 495 && mx <= 505 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_start_sta_j(500,380,&all->line2[8],&sta_checkclick[4][8],&start_station,&flag);
                }
                continue;
            }//if第一次点击起始站
            /***************对于第一次点击起点站之后******************/
            
            if(buttons&&flag==1)
            {
                if(mx >= 75 && mx <= 85 && my >= 95 && my <= 105 && buttons )//第一次点击
                {
                    Draw_end_sta_j(all,80,100,all->line1[1],&sta_checkclick[1][1],&start_station,&end_station,&flag);
                }
                if(mx >= 135 && mx <= 145 && my >= 95 && my <= 105 && buttons )
                {
                    Draw_end_sta_j(all,140,100,all->line1[2],&sta_checkclick[1][2],&start_station,&end_station,&flag);  
                }
                if(mx >= 195 && mx <= 205 && my >= 95 && my <= 105 && buttons )
                {
                    Draw_end_sta_j(all,200,100,all->line1[3],&sta_checkclick[1][3],&start_station,&end_station,&flag);
                }
                if(mx >= 255 && mx <= 265 && my >= 95 && my <= 105 && buttons )//这个是循礼门站，1和2的交点，到时候要特殊处理
                {
                    Draw_end_sta_j(all,260,100,all->line1[4],&sta_checkclick[1][4],&start_station,&end_station,&flag);
                }
                if(mx >= 315 && mx <= 325 && my >= 95 && my <= 105 && buttons )
                {
                    Draw_end_sta_j(all,320,100,all->line1[5],&sta_checkclick[1][5],&start_station,&end_station,&flag);
                }
                if(mx >= 375 && mx <= 385 && my >= 95 && my <= 105 && buttons )
                {
                    Draw_end_sta_j(all,380,100,all->line1[6],&sta_checkclick[1][6],&start_station,&end_station,&flag);
                }
                if(mx >= 435 && mx <= 445 && my >= 95 && my <= 105 && buttons )
                {
                    Draw_end_sta_j(all,440,100,all->line1[7],&sta_checkclick[1][7],&start_station,&end_station,&flag);
                }
                if(mx >= 495 && mx <= 505 && my >= 95 && my <= 105 && buttons )
                {
                    Draw_end_sta_j(all,500,100,all->line1[8],&sta_checkclick[1][8],&start_station,&end_station,&flag);
                }
                //2号线的
                if(mx >= 295 && mx <= 305 && my >= 65 && my <= 75 && buttons )
                {
                    Draw_end_sta_j(all,300,170,all->line2[1],&sta_checkclick[2][1],&start_station,&end_station,&flag);
                }
                if(mx >= 255 && mx <= 265 && my >= 151 && my <= 161 && buttons )
                {
                    Draw_end_sta_j(all,260,151,all->line2[3],&sta_checkclick[2][3],&start_station,&end_station,&flag);   
                }
                if(mx >= 255 && mx <= 265 && my >= 207 && my <= 217 && buttons )
                {
                    Draw_end_sta_j(all,260,212,all->line2[4],&sta_checkclick[2][4],&start_station,&end_station,&flag);
                }
                if(mx >= 255 && mx <= 265 && my >= 263 && my <= 273 && buttons )
                {
                    Draw_end_sta_j(all,260,278,all->line2[5],&sta_checkclick[2][5],&start_station,&end_station,&flag);
                }
                if(mx >= 255 && mx <= 265 && my >= 319 && my <= 329 && buttons )
                {
                    Draw_end_sta_j(all,260,334,all->line2[6],&sta_checkclick[2][6],&start_station,&end_station,&flag);
                }
                if(mx >= 255 && mx <= 265 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_end_sta_j(all,260,380,all->line2[7],&sta_checkclick[2][7],&start_station,&end_station,&flag);
                }
                if(mx >= 195 && mx <= 205 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_end_sta_j(all,200,380,all->line2[8],&sta_checkclick[2][8],&start_station,&end_station,&flag);
                }
                if(mx >= 235 && mx <= 245 && my >= 405 && my <= 415 && buttons )
                {
                    Draw_end_sta_j(all,240,410,all->line2[9],&sta_checkclick[2][9],&start_station,&end_station,&flag);
                }
                //4号线的
                if(mx >= 75 && mx <= 85 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_end_sta_j(all,80,380,all->line4[1],&sta_checkclick[4][1],&start_station,&end_station,&flag);
                }
                if(mx >= 135 && mx <= 145 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_end_sta_j(all,140,380,all->line4[2],&sta_checkclick[4][2],&start_station,&end_station,&flag);   
                }
                if(mx >= 315 && mx <= 325 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_end_sta_j(all,320,380,all->line4[5],&sta_checkclick[4][5],&start_station,&end_station,&flag);
                }
                if(mx >= 375 && mx <= 380 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_end_sta_j(all,380,380,all->line4[6],&sta_checkclick[4][6],&start_station,&end_station,&flag);
                }
                if(mx >= 435 && mx <= 445 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_end_sta_j(all,440,380,all->line4[7],&sta_checkclick[4][7],&start_station,&end_station,&flag);
                }
                if(mx >= 495 && mx <= 505 && my >= 375 && my <= 385 && buttons )
                {
                    Draw_end_sta_j(all,500,380,all->line2[8],&sta_checkclick[4][8],&start_station,&end_station,&flag);
                }
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