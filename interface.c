/**********************************************************
Description��  ���ļ�ר�Ŵ�Ž�����صĺ���	
Attention:  ����Ҫ��GB2312���뱣�棬��Ȼ���ֻ�������
Author���¿���
**********************************************************/
#include"interface.h"
#include"KEYBOARD.H"
#include"common_c.h"
void Drawloginscreen_c(setuser *person,int *judge,setuser *head);//��ʼ���溯��
void Btn_change_manager_c();
void Btn_change_user_c();
void click_user_c(int color);
void click_pass_c(int color);
void click_limit_c(int color);
void clear_effect_c(int manager);
void failConfirm_c(int sign);
void Drawplane();//���ɻ�����
void DrawControlSystem_c(setuser *person,int *judge);//����Ա�������Ľ��溯��
void DrawUserScreen_c(setuser *person,int *judge);//��ͨ�û�����
void DrawPersonalCenter_c(setuser *person,int *judge);//�������Ľ���

/**********************************************************
����Ϊ��ʼ�������غ���
**********************************************************/
void Drawloginscreen_c(setuser *person,int *judge,setuser *head)
{
	int manager=0;//�Ƿ�������Ա��ť
	// int temp;//�������ռ��̻������ı���
    int buttons,mx,my;//�����ر���
	int key=0,i[3]={0,0,0};//���뷨��ǵڼ������ֻ���ĸ�Ĳ���
	char temp[2]={'\0','\0'};//�������ռ��̻������ı���
	int choose=0;//���������¼���0û��ѡ�п�1�˺ſ�2�����3Ȩ�����
	setManager managerTemp;//�����������Ϣ
	setuser *up=NULL;
	//��ʼ��
	//managerTemp��ʼ��
	managerTemp.accounts[0]='\0';
	managerTemp.code[0]='\0';
	managerTemp.class[0]='\0';
	strcpy(managerTemp.money,"00000");
	//����ʼ��
	mouseInit(&mx, &my, &buttons);

	//���Ƶ�¼����
    cleardevice();
	setbkcolor(WHITE);
	Drawplane();	
	setfillstyle(1, DARKGRAY);
	bar(400,50,500 ,82 );//�û���ť
	bar(400,82,600,400);
	setfillstyle(1,LIGHTGRAY);
	bar(500,50,600,82);//����Ա��ť
	
	
	setfillstyle(1,WHITE);
	bar(410,130,590,160);//�����1�˺�
	bar(410,200,590,230);//�����2����
	// bar(410,235,490,265);//��֤��
	// bar(510,235,590,265);//��֤������
	setfillstyle(1,CYAN);//��ɫ
	bar(410,270,590,290);//��¼��
	bar(410,310,590,330);//ע���
	
	puthz(430, 55, "�û���", 16, 16, WHITE);
	puthz(515,55,"����Ա",16,16,WHITE);
	puthz(410, 105, "�˺�", 16, 16, WHITE);
	puthz(410, 175, "����", 16, 16, WHITE);
	puthz(485, 270, "��¼", 16, 16, WHITE);
	puthz(470, 310, "�Զ�ע��", 16, 16, WHITE);
	puthz(50, 50, "�人������ͨģ��ϵͳ", 32, 32, GREEN);                           
    puthz(5, 6, "˧���ǵ�c����֮", 16, 16, GREEN);                                                                                                          
	puthz(400, 435, "��������", 16, 16,MAGENTA );
	puthz(540 ,435, "����", 16, 16, MAGENTA);
	
	setcolor(BROWN);
	outtextxy(30,364,"We are committed to");
	outtextxy(50,384,"provide you with");
	outtextxy(10,404,"the best booking experience");
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
	outtextxy(80,100,"H U S T");
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	outtextxy(130,160,"A U T O");
	
	//���˳�ϵͳ��ť
	setlinestyle(0, 0, 3);
	setcolor(LIGHTRED);
	arc(600, 30, 110, 430, 15);
	line(600, 5, 600, 31);
	
	//setlinestyle(0, 0, 1);
	//setcolor(LIGHTRED);
	//rectangle(398,433,465,453);�������ǵ�λ��
	//rectangle(538,433,571,453);������λ��
	
	
	while(1)
	{
		newxy(&mx, &my, &buttons);
		if(buttons)//����¼�
		{
			if (mx >= 585 && mx <= 615 && my >= 5&& my <= 45 && buttons)//�˳���ť����˳�
			{
				*judge=turnTo_c(person,0);
				return;
			}
			else if(mx >= 500 && mx <= 600 && my >= 50&& my <= 82 && buttons)//�������Ա��ť
			{
				manager=1;
				choose=0;
				clear_effect_c(manager);//����ӿ�Ч��
				Btn_change_manager_c();//�������Ա��ť��ť��ʽ�任
				//backgroundChange(*mx, *my, 500, 50, 600 , 82);
			}
			else if(mx >= 400 && mx <= 500 && my >= 50&& my <= 82 && buttons)//����û���ť
			{
				manager=0;
				choose=0;
				clear_effect_c(manager);//����ӿ�Ч��
				Btn_change_user_c();//����û���ť��ť��ʽ�任
			}
			else if(mx >= 410 && mx <= 590 && my >= 130&& my <= 160 && buttons)//����˺ſ�
			{
				choose=1;
				clear_effect_c(manager);//����ӿ�Ч��
				click_user_c(GREEN);//����˺ż���

				//�����˺�
				//outtextxy(410,130,arr);//����λ��
				
			}
			else if(mx >= 410 && mx <= 590 && my >= 200&& my <= 230 && buttons)//��������
			{
				choose=2;
				clear_effect_c(manager);//����ӿ�Ч��
				click_pass_c(GREEN);//���������̿�
			}
			else if(mx >= 510 && mx <= 590 && my >= 235&& my <= 265 && buttons && manager==1)//���Ȩ�����
			{
				choose=3;
				clear_effect_c(manager);//����ӿ�Ч��
				click_limit_c(GREEN);//���Ȩ������̿�
			}
			else if(mx >= 410 && mx <= 590 && my >= 270 && my <= 290 && buttons)//�����½��ť
			//bar(410,270,590,290);//��¼��
			//bar(410,310,590,330);//ע���
			{
				clear_effect_c(manager);//����ӿ�Ч��
				if(strlen(managerTemp.code)<6)
				{
					click_pass_c(RED);//�������Ӻ��
					puthz(450, 175, "���벻������6λ", 16, 16, RED);
				}
				if(strlen(managerTemp.accounts)<6)
				{
					click_user_c(RED);//�������Ӻ��
					puthz(450, 105, "�˺�����������6λ", 16, 16, RED);
				}
				if(strlen(managerTemp.class)<5 && manager==1)
				{
					click_limit_c(RED);//�������Ӻ��
				}
				if(strlen(managerTemp.code)>=6 && strlen(managerTemp.accounts)>=6 && ((strlen(managerTemp.class)==5 && manager==1) || manager==0))
				{
					if(manager==0){strcpy(managerTemp.class,"00000");}
					if(login_c(managerTemp,head,person)==1)//��֤�ɹ�
					{
						*judge=turnTo_c(person,-1);
						return;
					}
					else if(login_c(managerTemp,head,person)==0)//��֤ʧ�ܣ��û�������
					{
						failConfirm_c(3);
					}
					else if(login_c(managerTemp,head,person)==2)//��֤ʧ�ܣ��������
					{
						failConfirm_c(1);
					}
					
				}
			}
			else if(mx >= 410 && mx <= 590 && my >= 310 && my <= 330 && buttons)//���ע�ᰴť
			{
				clear_effect_c(manager);//����ӿ�Ч��
				if(strlen(managerTemp.code)<6)
				{
					click_pass_c(RED);//����Ӻ��
					puthz(450, 175, "���벻������6λ", 16, 16, RED);
				}
				if(strlen(managerTemp.accounts)<6)
				{
					click_user_c(RED);//�˺żӺ��
					puthz(450, 105, "�˺�����������6λ", 16, 16, RED);
				}
				if(strlen(managerTemp.class)<5 && manager==1)
				{
					click_limit_c(RED);//Ȩ����Ӻ��
				}
				if(strlen(managerTemp.code)>=6 && strlen(managerTemp.accounts)>=6 && ((strlen(managerTemp.class)==5 && manager==1) || manager==0))
				{
					if(manager==0){strcpy(managerTemp.class,"00000");}
					if(strcmp(managerTemp.class,"cjwzs")!=0 && strcmp(managerTemp.class,"00000")!=0)//Ȩ��������
					{
						click_limit_c(RED);//Ȩ����Ӻ��
					}
					else//ע��ɹ�
					{
						if(login_c(managerTemp,head,person)==2)//����û����Ѵ���
						{
							failConfirm_c(2);
						}
						else
						{
							strcpy(person->accounts,managerTemp.accounts);
							strcpy(person->code,managerTemp.code);
							strcpy(person->class,managerTemp.class);
							strcpy(person->money,managerTemp.money);
							register_c(managerTemp);//ע�����û�

							// up=head;
							// while(up->next!=NULL)
							// {
							// 	up=head->next;
							// }
							// if((up->next=(setuser*)malloc(sizeof(setuser)))==NULL)
							// {
							// 	closegraph();
							// 	printf("\n OUT OF MEMORY!");
							// }
							// up=up->next;
							// strcpy(up->accounts,managerTemp.accounts);
							// strcpy(up->code,managerTemp.code);
							// strcpy(up->class,managerTemp.class);
							// strcpy(up->money,managerTemp.money);

							*judge=turnTo_c(person,-1);
							return;
						}
						
					}
					
				}
			}
			else
			{
				choose=0;
				clear_effect_c(manager);//����ӿ�Ч��
			}

			

		}//����¼�����
		//���뷨
		settextstyle(SMALL_FONT,HORIZ_DIR,7);
		setcolor(BLUE);
		if(choose==1)//ѡ���˺ſ�
		{
			key = 0;//���ü�ֵ���õ��¼�ֵ
			temp[0]='\0';
			if (kbhit() != 0)//�����⵽��������
			{
				key = bioskey(0);
				if(key != 0xe08 && i[0]>=0 && i[0]<12)//������벻���˸��
				{
					if(searchKeyValue(key) != '\0')//�������������ĸ��������
					{
						i[0]++;//�˻����ַ�����һ
						setfillstyle(1,WHITE);
						bar(410+i[0]*12,133,410+(i[0]+1)*12,157);
						settextstyle(SMALL_FONT,HORIZ_DIR,7);
						setcolor(BLUE);
						temp[0]=searchKeyValue(key);
						managerTemp.accounts[i[0]-1]=temp[0];//�˺����ַ�����
						managerTemp.accounts[i[0]]='\0';
						outtextxy(410+i[0]*12,133,temp);
					}
					
				}
				else if (key == 0xe08 && i[0]>0)//������˻�ɾ�� 
				{
					setfillstyle(1,WHITE);
					bar(410+i[0]*12,133,410+(i[0]+1)*12,157);//�����1�˺�
					managerTemp.accounts[i[0]-1]='\0';
					i[0]--;//�˺��ַ�����1
				}
			}
			
		}
		else if(choose==2)//ѡ�������
		{
			key = 0;//���ü�ֵ���õ��¼�ֵ
			temp[0]='\0';
			if (kbhit() != 0)//�����⵽��������
			{
				key = bioskey(0);
				if(key != 0xe08 && i[1]>=0 && i[1]<12)//������벻���˸��
				{
					if(searchKeyValue(key) != '\0')//�������������ĸ��������
					{
						i[1]++;//�����ַ�����һ
						setfillstyle(1,WHITE);
						bar(410+i[1]*12,203,410+(i[1]+1)*12,227);
						settextstyle(SMALL_FONT,HORIZ_DIR,7);
						setcolor(BLUE);
						temp[0]=searchKeyValue(key);
						managerTemp.code[i[1]-1]=temp[0];//�����ַ�����
						managerTemp.code[i[1]]='\0';
						temp[0]='*';//��������ס
						outtextxy(410+i[1]*12,203,temp);
					}
					
				}
				else if (key == 0xe08 && i[1]>0)//������˻�ɾ�� 
				{
					setfillstyle(1,WHITE);
					bar(410+i[1]*12,203,410+(i[1]+1)*12,227);
					managerTemp.accounts[i[1]-1]='\0';
					i[1]--;//�����ַ�����1
				}
			}
			
		}
		else if(choose==3)//ѡ��Ȩ�����
		{
			key = 0;//���ü�ֵ���õ��¼�ֵ
			temp[0]='\0';
			if (kbhit() != 0)//�����⵽��������
			{
				key = bioskey(0);
				if(key != 0xe08 && i[2]>=0 && i[2]<5)//������벻���˸��
				{
					if(searchKeyValue(key) != '\0')//�������������ĸ��������
					{
						i[2]++;//Ȩ���ַ�����һ
						setfillstyle(1,WHITE);
						bar(510+i[2]*12,238,513+(i[2]+1)*12,262);
						settextstyle(SMALL_FONT,HORIZ_DIR,7);
						setcolor(BLUE);
						temp[0]=searchKeyValue(key);
						managerTemp.class[i[2]-1]=temp[0];//Ȩ�����ַ�����
						managerTemp.class[i[2]]='\0';
						temp[0]='*';//��Ȩ������ס
						outtextxy(510+i[2]*12,238,temp);
					}
					
				}
				else if (key == 0xe08 && i[2]>0)//������˻�ɾ�� 
				{
					setfillstyle(1,WHITE);
					bar(510+i[2]*12,238,513+(i[2]+1)*12,262);
					managerTemp.accounts[i[2]-1]='\0';
					i[2]--;//Ȩ�����ַ�����1
				}
			}
			
		}
		else if(choose==0)//ûѡ��
		{
			key = 0;//���ü�ֵ���õ��¼�ֵ
			temp[0]='\0';
			temp[1]='\0';
		}
	}
}	

void Btn_change_manager_c()//�������Ա��ť��ť��ʽ�任
{
	setfillstyle(1, DARKGRAY);
	bar(500,50,600,82);//����Ա��ť
	setfillstyle(1,LIGHTGRAY);
	bar(400,50,500 ,82 );//�û���ť
	puthz(430, 55, "�û���", 16, 16, WHITE);
	puthz(515,55,"����Ա",16,16,WHITE);
	setfillstyle(1,WHITE);
	bar(510,235,590,265);//��֤�������
	puthz(410,240,"����ԱȨ����",16,16,WHITE);
}

void Btn_change_user_c()//����û���ť��ť��ʽ�任
{
	setfillstyle(1, DARKGRAY);
	bar(400,50,500 ,82 );//�û���ť
	setfillstyle(1,LIGHTGRAY);
	bar(500,50,600,82);//����Ա��ť
	puthz(430, 55, "�û���", 16, 16, WHITE);
	puthz(515,55,"����Ա",16,16,WHITE);
	setfillstyle(1,DARKGRAY);
	bar(407,232,593,268);//Ϳ������ԱȨ����
}

void click_user_c(int color)//����˺żӿ�
{
	int kuang[]={410,130,590,130,590,160,410,160,410,130};
	setcolor(color);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	drawpoly(5,kuang);
}
void click_pass_c(int color)//�������ӿ�
{
	int kuang[]={410,200,590,200,590,230,410,230,410,200};
	setcolor(color);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	drawpoly(5,kuang);
}
void click_limit_c(int color)//���Ȩ����ӿ�
{
	int kuang[]={510,235,590,235,590,265,510,265,510,235};
	setcolor(color);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	drawpoly(5,kuang);
}
void failConfirm_c(int sign)//��½ʧ����ʾ
{
	if(sign==1)
	{
		puthz(420, 360, "�������", 16, 16, RED);
	}
	else if(sign==2)
	{
		puthz(420, 360, "�û����Ѵ��ڣ�", 16, 16, RED);
	}
	else if(sign==3)
	{
		puthz(420, 360, "�û������ڣ�", 16, 16, RED);
	}
}
void clear_effect_c(int manager)//���Ч��
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
	//Ĩ����ʾ��Ϣ
	setfillstyle(1,DARKGRAY);
	bar(450,170,595,191);//��֤�������
	bar(450,100,595,121);
	bar(410,360,595,400);//Ĩ����½ʧ����Ϣ
}

/**********************************************************
Function:  Drawplane
Description��	���ɻ���������
Attention:  ����Ҫ��GB2312���뱣�棬��Ȼ���ֻ�������
**********************************************************/
void Drawplane()
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
����Ϊ����Ա�������غ���
**********************************************************/
void DrawControlSystem_c(setuser *person,int *judge)
{
	int buttons,mx,my;//�����ر���
	char temp[2]={'\0','\0'};//�������ռ��̻������ı���
	//int tri[]={25,15};//�û�ͼ���������
	// ��ʼ��
	// ����ʼ��
	mouseInit(&mx, &my, &buttons);

	//���Ƶ��Ƚ���
    cleardevice();
	setbkcolor(DARKGRAY);
	setfillstyle(1,LIGHTGRAY);
	bar(0,0,640,50);//������Ϣ��ʾ��
	//ͷ��ͼ��
	setcolor(DARKGRAY);
	setfillstyle(1,DARKGRAY);
	pieslice(25,25,0,360,20);
	setcolor(LIGHTGRAY);
	setfillstyle(1,LIGHTGRAY);
	pieslice(25,20,0,360,9);
	pieslice(25,25,232,308,19);
	//����
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	puthz(60, 17, "�û���", 16, 16, WHITE);
	puthz(250, 17, "��ݣ����ȹ���Ա", 16, 16, WHITE);
	// outtextxy(50,238,person->class);
	outtextxy(110,13,person->accounts);
	//���˳�ϵͳ��ť
	setlinestyle(0, 0, 3);
	setcolor(LIGHTRED);
	arc(600, 30, 110, 430, 15);
	line(600, 5, 600, 31);
	while(1)
	{
		newxy(&mx, &my, &buttons);
		if(buttons)//����¼�
		{
			if (mx >= 585 && mx <= 615 && my >= 5&& my <= 45 && buttons)//ע����ť����˳�
			{
				*judge=turnTo_c(person,1);
				return;
			}
			else if(mx >= 0 && mx <= 50 && my >= 0&& my <= 50 && buttons)//�����������
			{
				*judge=turnTo_c(person,4);
				return;
			}
		}
	}
}
/**********************************************************
����Ϊ��ͨ�û��������غ���
**********************************************************/
void DrawUserScreen_c(setuser *person,int *judge)
{
	int buttons,mx,my;//�����ر���
	char temp[2]={'\0','\0'};//�������ռ��̻������ı���
	// ��ʼ��
	// ����ʼ��
	mouseInit(&mx, &my, &buttons);
	cleardevice();
	setbkcolor(RED);
	while(1)
	{
		newxy(&mx, &my, &buttons);
		if(buttons)//����¼�
		{
			if (mx >= 585 && mx <= 615 && my >= 5&& my <= 45 && buttons)//�˳���ť����˳�
			{
				*judge=turnTo_c(person,1);
				return;
			}
		}
	}
}
