#include"interface.h"
#include"KEYBOARD.H"
#include"common_c.h"
/**********************************************************
����Ϊ��ʼ�������غ���
**********************************************************/
void Btn_change_manager_c();
void Btn_change_user_c();
void click_user_c();
void click_pass_c();
void click_limit_c();
void clear_effect_c(int manager);
void Drawplane();
void Drawloginscreen()
{
	int manager=0;//�Ƿ�������Ա��ť
	// int temp;//�������ռ��̻������ı���
    int buttons,mx,my;//�����ر���
	int key=0,i[3]={0,0,0};//���뷨��ǵڼ������ֻ���ĸ�Ĳ���
	char temp[2]={'\0','\0'};//�������ռ��̻������ı���
	// char arr[]="asdfhasjkdh";
	int choose=0;//���������¼���0û��ѡ�п�1�˺ſ�2�����3Ȩ�����
	setManager managerTemp;//�����������Ϣ
	mouseInit(&mx, &my, &buttons);  //����ʼ��

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
				exit(1);
			}
			else if(mx >= 500 && mx <= 600 && my >= 50&& my <= 82 && buttons)//�������Ա��ť
			{
				manager=1;
				choose=0;
				clear_effect_c(manager);//����ӿ�Ч��
				Btn_change_manager_c();//�������Ա��ť��ť��ʽ�任
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
				click_user_c();//����˺ż���

				//�����˺�
				//outtextxy(410,130,arr);//����λ��
				
			}
			else if(mx >= 410 && mx <= 590 && my >= 200&& my <= 230 && buttons)//��������
			{
				choose=2;
				clear_effect_c(manager);//����ӿ�Ч��
				click_pass_c();//���������̿�
			}
			else if(mx >= 510 && mx <= 590 && my >= 235&& my <= 265 && buttons && manager==1)//���Ȩ�����
			{
				choose=3;
				clear_effect_c(manager);//����ӿ�Ч��
				click_limit_c();//���Ȩ������̿�
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
			if (kbhit() != 0)
			{
				key = bioskey(0);
				i[0]++;
			}
			//������˻�ɾ�� 
			if (key == 0xe08 && i[0]>0)
			{
				setfillstyle(1,RED);
				bar(410+(i[0]-1)*12,133,413+i[0]*12,157);//�����1�˺�
				i[0]=i[0]-2;
				if(i[0]<0){i[0]=0;}
			}
			else if(i[0]>=0 && i[0]<11)
			{
				settextstyle(SMALL_FONT,HORIZ_DIR,7);
				setcolor(BLUE);
				temp[0]=searchKeyValue(key);
				outtextxy(410+i[0]*12,133,temp);
			}
			
		}
		else if(choose==2 && i[1]>=0 && i[1]<11)//ѡ�������
		{
			key = 0;//���ü�ֵ���õ��¼�ֵ
			temp[0]='\0';
			if (kbhit() != 0)
			{
				key = bioskey(0);
				i[1]++;
			}
			temp[0]=searchKeyValue(key);
			outtextxy(410+i[1]*11,203,temp);
		}
		else if(choose==3 && manager==1 && i[2]>=0 && i[2]<5)//ѡ��Ȩ�����
		{
			key = 0;//���ü�ֵ���õ��¼�ֵ
			temp[0]='\0';
			if (kbhit() != 0)
			{
				key = bioskey(0);
				i[2]++;
			}
			temp[0]=searchKeyValue(key);
			outtextxy(510+i[2]*11,238,temp);
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

void click_user_c()//����˺ż��̿�
{
	int kuang[]={410,130,590,130,590,160,410,160,410,130};
	setcolor(GREEN);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	drawpoly(5,kuang);
}
void click_pass_c()//���������̿�
{
	int kuang[]={410,200,590,200,590,230,410,230,410,200};
	setcolor(GREEN);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	drawpoly(5,kuang);
}
void click_limit_c()//���Ȩ������̿�
{
	int kuang[]={510,235,590,235,590,265,510,265,510,235};
	setcolor(GREEN);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	drawpoly(5,kuang);
}
void clear_effect_c(int manager)//����ӿ�Ч��
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
}
// void input_c(int x,int y)//������ʾ����
// {
// 	int key = 0;//���ü�ֵ���õ��¼�ֵ
// 	char temp[2]={'\0','\0'};
// 	temp[0]='\0';
//     if (kbhit() != 0)
//     {
//         key = bioskey(0);
//         i++;
//     }
//     temp[0]=searchKeyValue(key);
//     outtextxy(145+i*10,55,temp);
// }
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
����Ϊ�������غ���
**********************************************************/