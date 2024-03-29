/**********************************************************
Description：  此文件专门存放界面相关的函数	
Attention:  必须要用GB2312编码保存，不然汉字会有乱码
Author：陈俊玮
**********************************************************/
#include"face.h"
#include"common_c.h"
void Drawloginscreen_c(setuser *person,int *judge,setuser *head);//开始界面函数
void Btn_change_manager_c(void);
void Btn_change_user_c(void);
void click_user_c(int color);
void click_pass_c(int color);
void click_limit_c(int color);
void clear_effect_c(int manager);
void failConfirm_c(int sign);
void Drawplane(void);//画飞机函数
void DrawControlSystem_c(setuser *person,int *judge);//管理员调控中心界面函数
void DrawPersonalCenter_c(setuser *person,int *judge);//个人中心界面
void drawSignal(int x,int y,int r);
/**********************************************************
以下为开始界面的相关函数
**********************************************************/
void Drawloginscreen_c(setuser *person,int *judge,setuser *head)
{
	int manager=0;//是否点击管理员按钮
	// int temp;//用于吸收键盘缓冲区的变量
    int buttons,mx,my;//鼠标相关变量
	int key=0,i[3]={0,0,0};//输入法标记第几个数字或字母的参数
	char temp[2]={'\0','\0'};//用于吸收键盘缓冲区的变量
	int page,choose=0;//点击输入框事件：0没有选中框，1账号框，2密码框，3权限码框
	setManager managerTemp;//缓存输入的信息
	// setuser *up=NULL;
	int sign[2]={0,0};
	//初始化
	//managerTemp初始化
	managerTemp.accounts[0]='\0';
	managerTemp.code[0]='\0';
	managerTemp.class[0]='\0';
	strcpy(managerTemp.money,"00000");
	//鼠标初始化
	mouseInit(&mx, &my, &buttons);

	//绘制登录界面
    cleardevice();
	setbkcolor(WHITE);
	Drawplane();	
	setfillstyle(1, DARKGRAY);
	bar(400,50,500 ,82 );//用户按钮
	bar(400,82,600,400);
	setfillstyle(1,LIGHTGRAY);
	bar(500,50,600,82);//管理员按钮
	
	
	
	setfillstyle(1,WHITE);
	bar(410,130,590,160);//输入框1账号
	bar(410,200,590,230);//输入框2密码
	// bar(410,235,490,265);//验证码
	// bar(510,235,590,265);//验证码输入
	setfillstyle(1,CYAN);//青色
	bar(410,270,590,290);//登录框
	bar(410,310,590,330);//注册框
	
	puthz(430, 55, "用户名", 16, 16, WHITE);
	puthz(515,55,"管理员",16,16,WHITE);
	puthz(410, 105, "账号", 16, 16, WHITE);
	puthz(410, 175, "密码", 16, 16, WHITE);
	puthz(485, 270, "登录", 16, 16, WHITE);
	puthz(470, 310, "自动注册", 16, 16, WHITE);
	puthz(50, 50, "武汉地铁交通模拟系统", 32, 32, GREEN);                           
    puthz(5, 6, "帅哥们的c课设之", 16, 16, GREEN);                                                                                                          
	puthz(400, 435, "关于我们", 16, 16,MAGENTA );
	puthz(540 ,435, "帮助", 16, 16, MAGENTA);
	
	setcolor(BROWN);
	outtextxy(30,364,"We are committed to");
	outtextxy(50,384,"provide you with");
	outtextxy(10,404,"the best booking experience");
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
	outtextxy(80,100,"H U S T");
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(130,160,"A U T O");
	
	//画退出系统按钮
	setlinestyle(0, 0, 3);
	setcolor(LIGHTRED);
	arc(600, 30, 110, 430, 15);
	line(600, 5, 600, 31);
	
	setlinestyle(0, 0, 1);
	setcolor(LIGHTRED);
	rectangle(398,433,465,453);//关于我们的位置
	rectangle(538,433,571,453);//帮助的位置
	
	
	while(1)
	{
		newxy(&mx, &my, &buttons);
		if(buttons)//点击事件
		{
			if (mx >= 585 && mx <= 615 && my >= 5&& my <= 45)//退出按钮点击退出
			{
				page=Choose_c("您是否要退出","", &mx, &my, BROWN);
				if(page==1)
				{
					*judge=0;
					return;
				}
				else if(page==0)
				{
					*judge=1;
					return;
				}
			}
			else if(mx >= 398 && mx <= 465 &&my >= 433 && my<= 453)//关于我们
			{
				*judge=turnTo_c(person,12);
				return;
			}
			else if(mx >= 538 && mx <= 571 &&my >= 433 && my<= 453)//帮助
			{
				*judge=20;
				return;
			}
			else if(mx >= 500 && mx <= 600 && my >= 50&& my <= 82)//点击管理员按钮
			{
				manager=1;
				choose=0;
				clear_effect_c(manager);//清除加框效果
				Btn_change_manager_c();//点击管理员按钮后按钮样式变换
				// getMousebk(mx,my);
				backgroundChange(mx,my, 500, 50, 600 , 82);
			}
			else if(mx >= 400 && mx <= 500 && my >= 50&& my <= 82)//点击用户按钮
			{
				manager=0;
				choose=0;
				clear_effect_c(manager);//清除加框效果
				Btn_change_user_c();//点击用户按钮后按钮样式变换
				backgroundChange(mx,my, 400, 50, 500 , 82);
				// getMousebk(mx,my);
			}
			else if(mx >= 410 && mx <= 590 && my >= 130&& my <= 160)//点击账号框
			{
				choose=1;
				mousehide(mx,my);
				clear_effect_c(manager);//清除加框效果
				click_user_c(GREEN);//点击账号加绿
				// backgroundChange(mx , my, 410, 130, 590 , 160);
				getMousebk(mx,my);

				//输入账号
				//outtextxy(410,130,arr);//试验位置
				
			}
			else if(mx >= 410 && mx <= 590 && my >= 200&& my <= 230)//点击密码框
			{
				choose=2;
				mousehide(mx,my);
				clear_effect_c(manager);//清除加框效果
				click_pass_c(GREEN);//点击密码加绿框
				getMousebk(mx,my);
				// backgroundChange(mx , my, 410, 200, 590 , 230);
				// getMousebk(mx,my);
			}
			else if(mx >= 510 && mx <= 590 && my >= 235&& my <= 265 && manager==1)//点击权限码框
			{
				choose=3;
				mousehide(mx,my);
				clear_effect_c(manager);//清除加框效果
				click_limit_c(GREEN);//点击权限码加绿框
				getMousebk(mx,my);
				// backgroundChange(mx , my, 510, 235, 590 , 265);
				// getMousebk(mx,my);
			}
			else if(mx >= 410 && mx <= 590 && my >= 270 && my <= 290 )//点击登陆按钮
			//bar(410,270,590,290);//登录框
			//bar(410,310,590,330);//注册框
			{
				clear_effect_c(manager);//清除加框效果
				if(strlen(managerTemp.code)<6)
				{
					click_pass_c(RED);//点击密码加红框
					puthz(450, 175, "密码不得少于6位", 16, 16, RED);
					// getMousebk(mx,my);
				}
				if(strlen(managerTemp.accounts)<6)
				{
					click_user_c(RED);//点击用户名加红框
					puthz(450, 105, "账号名不得少于6位", 16, 16, RED);
					// getMousebk(mx,my);
				}
				if(strlen(managerTemp.class)<5 && manager==1)
				{
					click_limit_c(RED);//点击权限码加红框
					// getMousebk(mx,my);
				}
				if(strlen(managerTemp.code)>=6 && strlen(managerTemp.accounts)>=6 && ((strlen(managerTemp.class)==5 && manager==1) || manager==0))
				{
					if(manager==0){strcpy(managerTemp.class,"00000");}
					if(login_c(managerTemp,head,person)==1)//验证成功
					{
						*judge=turnTo_c(person,-1);
						return;
					}
					else if(login_c(managerTemp,head,person)==0)//验证失败，用户不存在
					{
						failConfirm_c(3);
					}
					else if(login_c(managerTemp,head,person)==2)//验证失败，密码错误
					{
						failConfirm_c(1);
					}
					
				}
			}
			else if(mx >= 410 && mx <= 590 && my >= 310 && my <= 330)//点击注册按钮
			{
				clear_effect_c(manager);//清除加框效果
				if(strlen(managerTemp.code)<6)
				{
					click_pass_c(RED);//密码加红框
					puthz(450, 175, "密码不得少于6位", 16, 16, RED);
					// getMousebk(mx,my);
				}
				if(strlen(managerTemp.accounts)<6)
				{
					click_user_c(RED);//账号加红框
					puthz(450, 105, "账号名不得少于6位", 16, 16, RED);
					// getMousebk(mx,my);
				}
				if(strlen(managerTemp.class)<5 && manager==1)
				{
					click_limit_c(RED);//权限码加红框
					// getMousebk(mx,my);
				}
				if(strlen(managerTemp.code)>=6 && strlen(managerTemp.accounts)>=6 && ((strlen(managerTemp.class)==5 && manager==1) || manager==0))
				{
					if(manager==0){strcpy(managerTemp.class,"00000");}
					if(strcmp(managerTemp.class,"cjwzs")!=0 && strcmp(managerTemp.class,"jmxzs")!=0&&strcmp(managerTemp.class,"00000")!=0)//权限码有误
					{
						click_limit_c(RED);//权限码加红框
						// getMousebk(mx,my);
					}
					else
					{
						if(login_c(managerTemp,head,person)==2)//如果用户名已存在
						{
							failConfirm_c(2);
						}
						else
						{
							strcpy(person->accounts,managerTemp.accounts);
							strcpy(person->code,managerTemp.code);
							strcpy(person->class,managerTemp.class);
							strcpy(person->money,managerTemp.money);
							strcpy(person->score,"0\0");
							strcpy(person->goods,"\0");
							strcpy(person->record,"\0");
							register_c(managerTemp,head);//注册新用户

							*judge=turnTo_c(person,-1);
							return;
						}
						
					}
					
				}
			}
			else
			{
				choose=0;
				clear_effect_c(manager);//清除加框效果
				// getMousebk(mx,my);
			}
        }//点击事件结束
		//关于我们和帮助的动画
		if(mx >= 398 && mx <= 465 &&my >= 433 && my<= 453&&sign[0]==0)//关于我们
		{
			mousehide(mx,my);
			setlinestyle(0,0,1);
			setcolor(GREEN);
			rectangle(398,433,465,453);
			sign[0]=1;
			getMousebk(mx,my);
		}
		else if(mx >= 538 && mx <= 571 &&my >= 433 && my<= 453&&sign[1]==0)//帮助
		{
			mousehide(mx,my);
			setlinestyle(0,0,1);
			setcolor(GREEN);
			rectangle(538,433,571,453);
			sign[1]=1;
			getMousebk(mx,my);
		}
		else if((sign[0]||sign[1])&&!(mx >= 398 && mx <= 465 &&my >= 433 && my<= 453)&&!(mx >= 538 && mx <= 571 &&my >= 433 && my<= 453))
		{
			setlinestyle(0,0,1);
			setcolor(LIGHTRED);
			rectangle(398,433,465,453);
			rectangle(538,433,571,453);
			sign[0]=sign[1]=0;
		}
		//输入法
		settextstyle(SMALL_FONT,HORIZ_DIR,7);
		setcolor(BLUE);
		if(choose==1)//选中账号框
		{
			key = 0;//重置键值并得到新键值
			temp[0]='\0';
			if (kbhit() != 0)//如果检测到键盘输入
			{
				key = bioskey(0);
				if(key != 0xe08 && i[0]>=0 && i[0]<12)//如果输入不是退格键
				{
					if(searchKeyValue(key) != '\0')//其中输入的是字母或者数字
					{
						mousehide(mx,my);
						i[0]++;//账户名字符数加一
						setfillstyle(1,WHITE);
						bar(410+i[0]*12,133,410+(i[0]+1)*12,157);
						settextstyle(SMALL_FONT,HORIZ_DIR,7);
						setcolor(BLUE);
						temp[0]=searchKeyValue(key);
						managerTemp.accounts[i[0]-1]=temp[0];//账号名字符缓存
						managerTemp.accounts[i[0]]='\0';
						outtextxy(410+i[0]*12,133,temp);
						getMousebk(mx,my);
					}
				}
				else if (key == 0xe08 && i[0]>0)//如果按了回删键 
				{
					mousehide(mx,my);
					setfillstyle(1,WHITE);
					bar(410+i[0]*12,133,410+(i[0]+1)*12,157);//输入框1账号
					managerTemp.accounts[i[0]-1]='\0';
					i[0]--;//账号字符数减1
					getMousebk(mx,my);
					// getMousebk(mx,my);
				}
			}
			
		}
		else if(choose==2)//选中密码框
		{
			key = 0;//重置键值并得到新键值
			temp[0]='\0';
			if (kbhit() != 0)//如果检测到键盘输入
			{
				key = bioskey(0);
				if(key != 0xe08 && i[1]>=0 && i[1]<12)//如果输入不是退格键
				{
					if(searchKeyValue(key) != '\0')//其中输入的是字母或者数字
					{
						mousehide(mx,my);
						i[1]++;//密码字符数加一
						setfillstyle(1,WHITE);
						bar(410+i[1]*12,203,410+(i[1]+1)*12,227);
						settextstyle(SMALL_FONT,HORIZ_DIR,7);
						setcolor(BLUE);
						temp[0]=searchKeyValue(key);
						managerTemp.code[i[1]-1]=temp[0];//密码字符缓存
						managerTemp.code[i[1]]='\0';
						temp[0]='*';//把密码遮住
						outtextxy(410+i[1]*12,203,temp);
						getMousebk(mx,my);
					}
				}
				else if (key == 0xe08 && i[1]>0)//如果按了回删键 
				{
					mousehide(mx,my);
					setfillstyle(1,WHITE);
					bar(410+i[1]*12,203,410+(i[1]+1)*12,227);
					managerTemp.code[i[1]-1]='\0';
					i[1]--;//密码字符数减1
					getMousebk(mx,my);
				}
			}
			
		}
		else if(choose==3)//选中权限码框
		{
			key = 0;//重置键值并得到新键值
			temp[0]='\0';
			if (kbhit() != 0)//如果检测到键盘输入
			{
				key = bioskey(0);
				if(key != 0xe08 && i[2]>=0 && i[2]<5)//如果输入不是退格键
				{
					if(searchKeyValue(key) != '\0')//其中输入的是字母或者数字
					{
						mousehide(mx,my);
						i[2]++;//权限字符数加一
						setfillstyle(1,WHITE);
						bar(510+i[2]*12,238,513+(i[2]+1)*12,262);
						settextstyle(SMALL_FONT,HORIZ_DIR,7);
						setcolor(BLUE);
						temp[0]=searchKeyValue(key);
						managerTemp.class[i[2]-1]=temp[0];//权限码字符缓存
						managerTemp.class[i[2]]='\0';
						temp[0]='*';//把权限码遮住
						outtextxy(510+i[2]*12,238,temp);
						getMousebk(mx,my);
					}
					
				}
				else if (key == 0xe08 && i[2]>0)//如果按了回删键 
				{
					mousehide(mx,my);
					setfillstyle(1,WHITE);
					bar(510+i[2]*12,238,513+(i[2]+1)*12,262);
					managerTemp.class[i[2]-1]='\0';
					i[2]--;//权限码字符数减1
					getMousebk(mx,my);
				}
			}
			
		}
		else if(choose==0)//没选中
		{
			key = 0;//重置键值并得到新键值
			temp[0]='\0';
			temp[1]='\0';
		}
	}
}	

void Btn_change_manager_c(void)//点击管理员按钮后按钮样式变换
{
	setfillstyle(1, DARKGRAY);
	bar(500,50,600,82);//管理员按钮
	setfillstyle(1,LIGHTGRAY);
	bar(400,50,500 ,82 );//用户按钮
	puthz(430, 55, "用户名", 16, 16, WHITE);
	puthz(515,55,"管理员",16,16,WHITE);
	setfillstyle(1,WHITE);
	bar(510,235,590,265);//验证码输入框
	puthz(410,240,"管理员权限码",16,16,WHITE);
}

void Btn_change_user_c(void)//点击用户按钮后按钮样式变换
{
	setfillstyle(1, DARKGRAY);
	bar(400,50,500 ,82 );//用户按钮
	setfillstyle(1,LIGHTGRAY);
	bar(500,50,600,82);//管理员按钮
	puthz(430, 55, "用户名", 16, 16, WHITE);
	puthz(515,55,"管理员",16,16,WHITE);
	setfillstyle(1,DARKGRAY);
	bar(407,232,593,268);//涂掉管理员权限码
}

void click_user_c(int color)//点击账号加框
{
	int kuang[]={410,130,590,130,590,160,410,160,410,130};
	setcolor(color);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	drawpoly(5,kuang);
}
void click_pass_c(int color)//点击密码加框
{
	int kuang[]={410,200,590,200,590,230,410,230,410,200};
	setcolor(color);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	drawpoly(5,kuang);
}
void click_limit_c(int color)//点击权限码加框
{
	int kuang[]={510,235,590,235,590,265,510,265,510,235};
	setcolor(color);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	drawpoly(5,kuang);
}
void failConfirm_c(int sign)//登陆失败提示
{
	if(sign==1)
	{
		puthz(420, 360, "密码错误！", 16, 16, RED);
	}
	else if(sign==2)
	{
		puthz(420, 360, "用户名已存在！", 16, 16, RED);
	}
	else if(sign==3)
	{
		puthz(420, 360, "用户不存在！", 16, 16, RED);
	}
}
void clear_effect_c(int manager)//清除效果
{
	int kuang1[]={410,130,590,130,590,160,410,160,410,130};
	int kuang2[]={410,200,590,200,590,230,410,230,410,200};
	int kuang3[]={510,235,590,235,590,265,510,265,510,235};
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	drawpoly(5,kuang1);
	drawpoly(5,kuang2);
	if(manager==1)
	{
		drawpoly(5,kuang3);
	}
	//抹掉提示信息
	setfillstyle(1,DARKGRAY);
	bar(450,170,595,191);//验证码输入框
	bar(450,100,595,121);
	bar(410,360,595,400);//抹掉登陆失败信息
}

/**********************************************************
Function:  Drawplane
Description：	画飞机函数函数
Attention:  必须要用GB2312编码保存，不然汉字会有乱码
**********************************************************/
void Drawplane(void)
{
	setcolor(LIGHTCYAN);
	setlinestyle(0,0,1);
	line(100 - 10, 215 + 15, 101 - 10, 210 + 15);
	line(101 - 10, 210 + 15, 103 - 10, 208 + 15);
	line(103 - 10, 208 + 15, 105 - 10, 206 + 15);
	line(105 - 10, 206 + 15, 110 - 10, 205 + 15);
	line(110 - 10, 205 + 15, 115 - 10, 206 + 15);
	line(115 - 10, 206 + 15, 117 - 10, 208 + 15);
	line(117 - 10, 208 + 15, 119 - 10, 210 + 15);
	line(119 - 10, 210 + 15, 120 - 10, 215 + 15);
	line(120 - 10, 215 + 15, 115 - 10, 217 + 15);
	line(115 - 10, 217 + 15, 110 - 10, 218 + 15);
	line(110 - 10, 218 + 15, 105 - 10, 217 + 15);
	line(105 - 10, 217 + 15, 100 - 10, 215 + 15);
	line(100 - 10, 215 + 15, 97 - 10, 217 + 15);
	line(97 - 10, 217 + 15, 93 - 10, 220 + 15);
	line(93 - 10, 220 + 15, 90 - 10, 224 + 15);
	line(90 - 10, 224 + 15, 88 - 10, 227 + 15);
	line(88 - 10, 227 + 15, 87 - 10, 230 + 15);
	line(87 - 10, 230 + 15, 86 - 10, 232 + 15);
	line(86 - 10, 232 + 15, 85 - 10, 240 + 15);
	line(85 - 10, 240 + 15, 95 - 10, 241 + 15);
	line(95 - 10, 241 + 15, 102 - 10, 240 + 15);
	line(102 - 10, 240 + 15, 109 - 10, 238 + 15);
	line(109 - 10, 238 + 15, 115 - 10, 235 + 15);
	line(115 - 10, 235 + 15, 124 - 10, 230 + 15);
	line(124 - 10, 230 + 15, 130 - 10, 225 + 15);
	line(130 - 10, 225 + 15, 135 - 10, 220 + 15);
	line(135 - 10, 220 + 15, 137 - 10, 215 + 15);
	line(137 - 10, 215 + 15, 140 - 10, 210 + 15);
	line(140 - 10, 210 + 15, 234 - 10, 125 + 15);
	line(234 - 10, 125 + 15, 223 - 10, 103 + 15);
	line(223 - 10, 103 + 15, 217 - 10, 101 + 15);
	line(217 - 10, 101 + 15, 210 - 10, 120 + 15);
	line(210 - 10, 120 + 15, 200 - 10, 135 + 15);
	line(200 - 10, 135 + 15, 137 - 10, 186 + 15);
	line(137 - 10, 186 + 15, 127 - 10, 193 + 15);
	line(127 - 10, 193 + 15, 110 - 10, 205 + 15);
	line(85 - 10, 240 + 15, 88 - 10, 245 + 15);
	line(85 - 10, 240 + 15, 88 - 10, 245 + 15);
	line(88 - 10, 245 + 15, 90 - 10, 247 + 15);
	line(90 - 10, 247 + 15, 96 - 10, 250 + 15);
	line(96 - 10, 250 + 15, 101 - 10, 251 + 15);
	line(101 - 10, 251 + 15, 110 - 10, 250 + 15);
	line(110 - 10, 250 + 15, 150 - 10, 220 + 15);
	line(150 - 10, 220 + 15, 153 - 10, 222 + 15);
	line(153 - 10, 222 + 15, 158 - 10, 221 + 15);
	line(158 - 10, 221 + 15, 160 - 10, 217 + 15);
	line(160 - 10, 217 + 15, 158 - 10, 210 + 15);
	line(158 - 10, 210 + 15, 154 - 10, 208 + 15);
	line(154 - 10, 208 + 15, 150 - 10, 210 + 15);
	line(150 - 10, 210 + 15, 148 - 10, 215 + 15);
	line(148 - 10, 215 + 15, 150 - 10, 220 + 15);
	line(150 - 10, 210 + 15, 160 - 10, 200 + 15);
	line(160 - 10, 200 + 15, 163 - 10, 199 + 15);
	line(163 - 10, 199 + 15, 165 - 10, 199 + 15);
	line(165 - 10, 199 + 15, 168 - 10, 200 + 15);
	line(168 - 10, 200 + 15, 169 - 10, 202 + 15);
	line(169 - 10, 202 + 15, 170 - 10, 206 + 15);
	line(170 - 10, 206 + 15, 160 - 10, 217 + 15);
	line(170 - 10, 206 + 15, 172 - 10, 207 + 15);
	line(172 - 10, 207 + 15, 160 - 10, 221 + 15);
	line(160 - 10, 221 + 15, 157 - 10, 223 + 15);
	line(157 - 10, 223 + 15, 150 - 10, 220 + 15);
	line(170 - 10, 206 + 15, 175 - 10, 200 + 15);
	line(175 - 10, 200 + 15, 225 - 10, 140 + 15);
	line(225 - 10, 140 + 15, 235 - 10, 127 + 15);
	line(235 - 10, 127 + 15, 234 - 10, 125 + 15);
	line(150 - 10, 220 + 15, 155 - 10, 224 + 15);
	line(155 - 10, 224 + 15, 158 - 10, 225 + 15);
	line(158 - 10, 225 + 15, 162 - 10, 226 + 15);
	line(162 - 10, 226 + 15, 232 - 10, 240 + 15);
	line(232 - 10, 240 + 15, 245 - 10, 233 + 15);
	line(245 - 10, 233 + 15, 175 - 10, 200 + 15);
	line(103 - 10, 208 + 15, 102 - 10, 205 + 15);
	line(102 - 10, 205 + 15, 101 - 10, 201 + 15);
	line(101 - 10, 201 + 15, 102 - 10, 198 + 15);
	line(102 - 10, 198 + 15, 105 - 10, 198 + 15);
	line(105 - 10, 198 + 15, 107 - 10, 200 + 15);
	line(107 - 10, 200 + 15, 110 - 10, 205 + 15);
	line(102 - 10, 198 + 15, 120 - 10, 185 + 15);
	line(120 - 10, 185 + 15, 125 - 10, 188 + 15);
	line(125 - 10, 188 + 15, 127 - 10, 193 + 15);
	line(127 - 10, 193 + 15, 110 - 10, 205 + 15);
	line(102 - 10, 198 + 15, 90 - 10, 122 + 15);
	line(90 - 10, 122 + 15, 100 - 10, 125 + 15);
	line(100 - 10, 125 + 15, 137 - 10, 186 + 15);
	line(137 - 10, 186 + 15, 127 - 10, 193 + 15);
	line(137 - 10, 186 + 15, 200 - 10, 135 + 15);
	line(200 - 10, 135 + 15, 180 - 10, 115 + 15);
	line(180 - 10, 115 + 15, 180 - 10, 110 + 15);
	line(180 - 10, 110 + 15, 210 - 10, 120 + 15);
	line(234 - 10, 125 + 15, 259 - 10, 133 + 15);
	line(259 - 10, 133 + 15, 258 - 10, 137 + 15);
	line(258 - 10, 137 + 15, 225 - 10, 140 + 15);
	
}

/**********************************************************
以下为管理员界面的相关函数
**********************************************************/
void DrawControlSystem_c(setuser *person,int *judge)
{
	int buttons,mx,my;//鼠标相关变量
	int sign[2]={0,0};//移动到按钮的标志
	int page;
	int mouseover=0;
	//int tri[]={25,15};//用户图标的三角形
	// 初始化
	// 鼠标初始化
	mouseInit(&mx, &my, &buttons);

	//绘制调度界面
    cleardevice();
	setbkcolor(DARKGRAY);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);//个人信息显示栏
	//头像图标
	setcolor(DARKGRAY);
	setfillstyle(1,DARKGRAY);
	pieslice(25,25,0,360,20);
	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	pieslice(25,20,0,360,9);
	pieslice(25,25,232,308,19);
	//文字
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	puthz(60, 17, "账号：", 16, 16, WHITE);
	puthz(253, 17, "身份：调度管理员", 16, 16, WHITE);
	// outtextxy(50,238,person->class);
	outtextxy(110,12,person->accounts);
	//画退出系统按钮
	setlinestyle(0, 0, 3);
	setcolor(LIGHTRED);
	arc(600, 30, 110, 430, 15);
	line(600, 5, 600, 31);
	//太极
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	pieslice(320,265,0,360,202);
	moveto(320,265);
	setcolor(DARKGRAY);
	ellipse(320,265,270,90,200,200);
	ellipse(320,165,90,270,100,100);
	ellipse(320,365,270,90,100,100);
	setcolor(DARKGRAY);
	setfillstyle(1,DARKGRAY);
	floodfill(325,260,DARKGRAY);
	//太极的两个点
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	pieslice(320,165,0,360,20);
	setcolor(DARKGRAY);
	setfillstyle(1,DARKGRAY);
	pieslice(320,365,0,360,20);
	// circle(320,240,200);
	// floodfill(320,240,WHITE);



	while(1)
	{
		newxy(&mx, &my, &buttons);
		if(mx >= 0 && mx <= 50 && my >= 0&& my <= 50 && mouseover==0)//进入个人中心
		{
			mouseover=1;
			mousehide(mx,my);
			setcolor(LIGHTBLUE);
			setfillstyle(1,LIGHTBLUE);
			pieslice(25,25,0,360,20);
			setcolor(WHITE);
			setfillstyle(1,WHITE);
			pieslice(25,20,0,360,9);
			pieslice(25,25,232,308,19);
			getMousebk(mx,my);
		}
		if(!(mx >= 0 && mx <= 50 && my >= 0&& my <= 50) && mouseover==1)
		{
			mouseover=0;
			mousehide(mx,my);
			setcolor(DARKGRAY);
			setfillstyle(1,DARKGRAY);
			pieslice(25,25,0,360,20);
			setcolor(LIGHTGRAY);
			setfillstyle(1,LIGHTGRAY);
			pieslice(25,20,0,360,9);
			pieslice(25,25,232,308,19);
			getMousebk(mx,my);
		}
		if(buttons)//点击事件
		{
			if (mx >= 585 && mx <= 615 && my >= 5&& my <= 45)//注销按钮点击退出
			{
				page=Choose_c("您是否要注销","", &mx, &my, BROWN);
				if(page==1)
				{
					*judge=1;
					return;
				}
				else if(page==0)
				{
					*judge=2;
					return;
				}
			}
			else if(mx >= 0 && mx <= 50 && my >= 0&& my <= 50)//进入个人中心
			{
				*judge=turnTo_c(person,4);
				return;
			}
		}
		if (mx >= 245 && mx <= 395 && my >= 90 && my <= 240)//鼠标移到上点
		{
			if(sign[0]==0)
			{
				mousehide(mx,my);
				//遮住原先的点
				setcolor(DARKGRAY);
				setfillstyle(1,DARKGRAY);
				bar(290,135,350,195);
				//绘制新的点
				setcolor(WHITE);
				setfillstyle(1,WHITE);
				pieslice(320,125,0,360,20);
				puthz(290, 160, "调度", 32, 32, WHITE);
				sign[0]=1;
				getMousebk(mx,my);
			}
			if(buttons)//点击上点
			{
				*judge=turnTo_c(person,11);
				return;
			}
		}
		else if(sign[0]==1 && !(mx >= 245 && mx <= 395 && my >= 90 && my <= 240))
		{
			mousehide(mx,my);
			sign[0]=0;
			setcolor(DARKGRAY);
			setfillstyle(1,DARKGRAY);
			bar(280,90,360,205);
			//太极的两个点
			setcolor(WHITE);
			setfillstyle(1,WHITE);
			pieslice(320,165,0,360,20);
			getMousebk(mx,my);
		}
		if (mx >= 245 && mx <= 395 && my >= 290 && my <= 440)//鼠标移到下点
		{
			if(sign[1]==0)
			{
				mousehide(mx,my);
				//遮住原先的点
				setcolor(WHITE);
				setfillstyle(1,WHITE);
				bar(280,320,385,440);
				//绘制新的点
				setcolor(DARKGRAY);
				setfillstyle(1,DARKGRAY);
				pieslice(320,405,0,360,20);
				puthz(290, 340, "购票", 32, 32, DARKGRAY);
				sign[1]=1;
				getMousebk(mx,my);
			}
			if(buttons)//点击下点
			{
				*judge=turnTo_c(person,5);
				return;
			}
		}
		else if(sign[1]==1 && !(mx >= 245 && mx <= 395 && my >= 290 && my <= 440))
		{
			mousehide(mx,my);
			sign[1]=0;
			setcolor(WHITE);
			setfillstyle(1,WHITE);
			bar(280,320,385,440);
			//太极的两个点
			setcolor(DARKGRAY);
			setfillstyle(1,DARKGRAY);
			pieslice(320,365,0,360,20);
			getMousebk(mx,my);
		}
	}
}
void drawSignal(int x,int y,int r)
{
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(LIGHTRED);
	ellipse(x,y,90,270,r,r);
	setcolor(LIGHTBLUE);
	ellipse(x,y,90,270,2*r,2*r);
	setcolor(LIGHTRED);
	ellipse(x,y+r/2,270,90,3*r/2,3*r/2);
	ellipse(x,y-3*r,270,90,r,r);
	setcolor(LIGHTMAGENTA);
	line(x,y-4*r,x,y+4*r);
	ellipse(x-r/2,y+4*r,180,0,r/2,r/2);
}
