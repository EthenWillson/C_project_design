/**********************************************************
Description�� ���ļ�ר�Ŵ�Ÿ���������صĺ���
Attention:  ����Ҫ��GB2312���뱣�棬��Ȼ���ֻ�������
Author���¿���
**********************************************************/
#include"personal_c.h"
#include"common_c.h"
#include"NMOUSE.H"
void DrawBeautifulFrame_c();//Ư���ı߿�
void Drawxctubiaoone(int x, int y, int color);
void Drawxctubiaotwo(int x, int y, int color);
void Drawbuttons(int x, int y, int color);
void Drawxc_self( int x, int y, int color);//�޸����밴ť
void Drawxc_auto( int x, int y, int color);//��ֵ��ť
void returnBtn_c(int x,int y,int color);//���ذ�ť
void inputBoxGroup(int x, int y, int framecolor,int color);//����������庯��
void frameChange_c(int x1,int y1,int x2,int y2,int color);//������ɫ����
// void DrawPersonalCenter_c(setuser *person,int *judge,setuser *head);//�������Ľ���
// void changePasswordScreen_c(setuser *person,int *judge,setuser *head);//�޸��������
void DrawPersonalCenter_c(setuser *person,int *judge);//�������Ľ���
void changePasswordScreen_c(setuser *person,int *judge);//�޸��������

/**********************************************************
�������Ľ��溯��
**********************************************************/
// void DrawPersonalCenter_c(setuser *person,int *judge,setuser *head)
void DrawPersonalCenter_c(setuser *person,int *judge)//�������Ľ���
{
	int buttons,mx,my;//�����ر���
	char temp[2]={'\0','\0'};//�������ռ��̻������ı���
	int sign[2]={0,0};//�����ж�����ƶ�����ť�ϵı�־
	// ��ʼ��
	// ����ʼ��
	mouseInit(&mx, &my, &buttons);
	cleardevice();
	setbkcolor(WHITE);
	DrawBeautifulFrame_c();//�߿�
    Drawxc_self( 0, 0 , LIGHTGRAY);//�޸����밴ť
    Drawxc_auto( 0, 0 , LIGHTGRAY);//�˻���ֵ��ť
	returnBtn_c( 285, 395, CYAN);//���ذ�ť
	puthz(260, 30, "��������", 32, 32, GREEN); 
	puthz(220, 80, "���ã��𾴵ģ�", 16, 16, BLUE); 
	setcolor(BROWN);
	outtextxy(330,75,person->accounts);
	while(1)
	{
		newxy(&mx, &my, &buttons);
		if(buttons)//����¼�
		{
			if (mx >= 285 && mx <= 395 && my >= 345 && my <= 445 && buttons)//���ذ�ť����
			{
				*judge=turnTo_c(person,-1);
				return;
			}
		}
		//(157,134,476,220)�޸�����////////////////////////////////
		if( mx >= 147 && mx <= 486 && my >=111 && my <=230 )
		{
			if (sign[0]==0)
			{
			setfillstyle(1, WHITE);//��ԭ��ͼ������
			bar(157,124,480,220);
			Drawxc_self(10,-5,DARKGRAY);
			//getMousebk(*mx, *my);
			sign[0]=1;
			}
			if ( buttons )
			{
				// changePasswordScreen_c(person,judge,head);
				changePasswordScreen_c(person,judge);
				return;
			}
		}
		else if ( sign[0]==1 && !(mx >= 147 && mx <= 486 && my >=111 && my <=230) )
		{
			setfillstyle(1, WHITE);//��ԭ��ͼ������
			bar(157+10,124-5,480+10,220-5);
			Drawxc_self(0,0,LIGHTGRAY);
			sign[0]=0;
		}
		//(157,284,476,370)��ֵ///////////////////////////////////////
		if ( mx >= 147 && mx <= 486 && my >=261 && my <=380 )
		{
		
			if (sign[1]==0)
			{
				setfillstyle(1, WHITE);//��ԭ��ͼ������
				bar(157,274,480,370);
				Drawxc_auto(10,-5,DARKGRAY);
			  	//getMousebk(*mx, *my);
				sign[1]=1;
			}
			// if ( buttons )
			// {
			//   //�������ܹ滮ģ��
			// 	judge=2;
			// }
		}
		else if (sign[1]==1 && !(mx >= 147 && mx <= 486 && my >=261 && my <=380) )
		{
			setfillstyle(1, WHITE);//��ԭ��ͼ������
			bar(157+10,274-5,480+10,370-5);
			Drawxc_auto(0,0,LIGHTGRAY);
			sign[1]=0;
		}
	}
}
/**********************************************************
Description��	����Ư���߿�
**********************************************************/
void DrawBeautifulFrame_c()						//����߿�
{
	setcolor(CYAN);
	setlinestyle(0, 0, 1);
	line(40, 8, 600, 8);
	line(600, 8, 600, 48);
	line(600, 48, 604, 48);
	line(604, 8, 620, 8);
	line(604, 8, 604, 48);
	line(620, 8, 620, 24);
	line(620, 24, 588, 24);
	line(588, 24, 588, 32);
	line(588, 32, 620, 32);
	line(620, 32, 620, 448);
	line(620, 448, 588, 448);
	line(588, 448, 588, 456);
	line(588, 456, 620, 456);
	line(620, 456, 620, 472);
	line(620, 472, 604, 472);
	line(604, 472, 604, 432);
	line(604, 432, 600, 432);
	line(600, 432, 600, 472);
	line(600, 472, 40, 472);
	line(40, 472, 40, 432);
	line(40, 432, 36, 432);
	line(36, 432, 36, 472);
	line(36, 472, 20, 472);
	line(20, 472, 20, 456);
	line(20, 456, 52, 456);
	line(52, 456, 52, 448);
	line(52, 448, 20, 448);
	line(20, 448, 20, 32);
	line(20, 32, 52, 32);
	line(52, 32, 52, 24);
	line(52, 24, 20, 24);
	line(20, 24, 20, 8);
	line(20, 8, 36, 8);
	line(36, 8, 36, 48);
	line(36, 48, 40, 48);
	line(40, 48, 40, 8);
	line(44, 12, 596, 12);
	line(596, 12, 596, 52);
	line(596, 52, 608, 52);
	line(608, 52, 608, 12);
	line(608, 12, 616, 12);
	line(616, 12, 616, 20);
	line(616, 20, 584, 20);
	line(584, 20, 584, 36);
	line(584, 36, 616, 36);
	line(616, 36, 616, 444);
	line(616, 444, 584, 444);
	line(584, 444, 584, 460);
	line(584, 460, 616, 460);
	line(616, 460, 616, 468);
	line(616, 468, 608, 468);
	line(608, 468, 608, 428);
	line(608, 428, 596, 428);
	line(596, 428, 596, 468);
	line(596, 468, 44, 468);
	line(44, 468, 44, 428);
	line(44, 428, 32, 428);
	line(32, 428, 32, 468);
	line(32, 468, 24, 468);
	line(24, 468, 24, 460);
	line(24, 460, 56, 460);
	line(56, 460, 56, 444);
	line(56, 444, 24, 444);
	line(24, 444, 24, 36);
	line(24, 36, 56, 36);
	line(56, 36, 56, 20);
	line(56, 20, 24, 20);
	line(24, 20, 24, 12);
	line(24, 12, 32, 12);
	line(32, 12, 32, 52);
	line(32, 52, 44, 52);
	line(44, 52, 44, 12);

}
/**********************************************************
FUNCTION:   Drawxctubiaoone
Description��	������ķɻ�ͼ��
Input:   ͼ������ꣻ��ɫ
**********************************************************/
void Drawxctubiaoone(int x, int y, int color)
{
	setlinestyle(0, 0, 3);
	setcolor(color);
	line(x + 160, y + 110, x + 179, y + 115);
	line(x + 179, y + 115, x + 200, y + 100);
	line(x + 200, y + 100, x + 210, y + 100);
	line(x + 210, y + 100, x + 200, y + 121);
	line(x + 200, y + 121, x + 215, y + 125);
	line(x + 215, y + 125, x + 225, y + 115);
	line(x + 225, y + 115, x + 230, y + 115);
	line(x + 230, y + 115, x + 220, y + 135);
	line(x + 220, y + 135, x + 195, y + 130);
	line(x + 195, y + 130, x + 194, y + 128);
	line(x + 194, y + 128, x + 168, y + 123);
	line(x + 168, y + 123, x + 170, y + 125);
	line(x + 170, y + 125, x + 145, y + 120);
	line(x + 145, y + 120, x + 142, y + 119);
	line(x + 142, y + 119, x + 140, y + 118);
	line(x + 140, y + 118, x + 142, y + 116);
	line(x + 142, y + 116, x + 145, y + 115);
	line(x + 145, y + 115, x + 150, y + 115);
	line(x + 150, y + 115, x + 152, y + 113);
	line(x + 152, y + 113, x + 155, y + 111);
	line(x + 155, y + 111, x + 160, y + 110);
	line(x + 160, y + 110, x + 179, y + 115);
	line(x + 179, y + 115, x + 200, y + 121);
	line(x + 175, y + 114, x + 170, y + 120);
	line(x + 170, y + 120, x + 150, y + 115);
	line(x + 195, y + 105, x + 205, y + 107);
	line(x + 188, y + 111, x + 200, y + 113);
	line(x + 180, y + 130, x + 190, y + 132);
	line(x + 190, y + 140, x + 200, y + 142);
	line(x + 194, y + 128, x + 205, y + 150);
	line(x + 205, y + 150, x + 190, y + 145);
	line(x + 190, y + 145, x + 170, y + 125);
	circle(x + 160, y + 124, 2);

}
/**********************************************************
Function:      Drawxctubiaotwo
Description��	����Ĳ���ͼ��
Input:   ͼ������ꣻ��ɫ
**********************************************************/
void Drawxctubiaotwo(int x, int y, int color)
{
	setlinestyle(0, 0, 3);
	setcolor(color);
	circle(x + 240, y + 350, 8);
	circle(x + 240, y + 350, 10);
	line(x + 260, y + 340, x + 231, y + 340);
	line(x + 231, y + 340, x + 229, y + 342);
	line(x + 229, y + 342, x + 231, y + 346);
	line(x + 231, y + 340, x + 232, y + 344);
	line(x + 233, y + 357, x + 239, y + 383);
	line(x + 239, y + 383, x + 241, y + 380);
	line(x + 241, y + 380, x + 236, y + 359);
	line(x + 241, y + 380, x + 270, y + 380);
	line(x + 270, y + 380, x + 300, y + 370);
	line(x + 300, y + 370, x + 289, y + 331);
	line(x + 289, y + 331, x + 260, y + 340);
	line(x + 300, y + 370, x + 301, y + 373);
	line(x + 301, y + 373, x + 272, y + 382);
	line(x + 272, y + 382, x + 270, y + 381);
	line(x + 270, y + 381, x + 268, y + 382);
	line(x + 268, y + 382, x + 239, y + 383);
	line(x + 263, y + 341, x + 287, y + 333);
	line(x + 287, y + 333, x + 290, y + 345);
	line(x + 290, y + 345, x + 266, y + 353);
	line(x + 266, y + 353, x + 263, y + 341);
	line(x + 267, y + 356, x + 291, y + 348);
	line(x + 291, y + 348, x + 292, y + 352);
	line(x + 292, y + 352, x + 268, y + 360);
	line(x + 268, y + 360, x + 267, y + 356);
	line(x + 269, y + 363, x + 293, y + 355);
	line(x + 293, y + 355, x + 294, y + 359);
	line(x + 294, y + 359, x + 270, y + 367);
	line(x + 270, y + 367, x + 269, y + 363);
	line(x + 271, y + 370, x + 295, y + 362);
	line(x + 295, y + 362, x + 296, y + 366);
	line(x + 296, y + 366, x + 272, y + 374);
	line(x + 272, y + 374, x + 271, y + 370);
	line(x + 260, y + 340, x + 270, y + 380);
	line(x + 244, y + 359, x + 246, y + 362);
	line(x + 246, y + 362, x + 253, y + 378);
	line(x + 253, y + 378, x + 250, y + 379);
	line(x + 250, y + 379, x + 243, y + 363);
	line(x + 243, y + 363, x + 243, y + 359);
	line(x + 243, y + 363, x + 246, y + 362);
}

/**********************************************************
Function:      Drawbuttons
Description��	������ť���
Input:   ͼ������ꣻ��ɫ
**********************************************************/
void Drawbuttons(int x, int y, int color)
{
	setlinestyle(0, 0, 3);
	setcolor(color);
	line(x+120, y + 120, x+160, y + 80);
	line(x + 160, y + 80, x + 200, y + 80);
	line(x + 200, y + 80 , x + 240, y + 120);
	line(x + 240, y + 120 , x + 200, y + 160 );
	line(x + 200, y + 160 , x + 160 , y + 160 );
	line(x + 160, y + 160 , x + 120 , y + 120 );
	line(x + 220, y + 100 , x + 420 , y + 100 );
	line(x + 420, y + 100 , x + 440 , y + 120 );
	line(x + 420, y + 140 , x + 440 , y + 120 );
	line(x + 420, y + 140 , x + 220 , y + 140 );
}
/**********************************************************
Function:    Drawxc_self
Description:   ���޸����밴ť
**********************************************************/
void Drawxc_self( int x, int y, int color)
{
	setlinestyle(0, 0, 3);
	Drawbuttons( x+90-50,  y+235-180, color);
	Drawxctubiaoone(x+80-50, y+235-180,  color);
	puthz(x+360-50,y+343-180,"�޸�����",16,16,color);
	setcolor(DARKGRAY);
}
/**********************************************************
Function:    Drawxc_auto
Description:   ���˻���ֵ��ť
**********************************************************/
void Drawxc_auto( int x, int y, int color)
{
	setlinestyle(0, 0, 3);
	Drawbuttons( x+40,  y+235-30, color);
	Drawxctubiaotwo(x+7-50, y-3-30,  color);
	puthz(x+360-50,y+313,"�˻���ֵ",16,16,color);
}
/**********************************************************
FUNCTION:   returnBtn_c
Description��	������ķ��ذ�ť
Input:   ͼ������ꣻ��ɫ
**********************************************************/
void returnBtn_c(int x,int y,int color)
{
	int i;
	int arrow_one[]={25,5,5,30,25,55};
	int arrow_two[]={60,5,40,30,60,55};
	for(i=0;i<3;i++)
	{
		arrow_one[i*2+1]=arrow_one[i*2+1]+y;
		arrow_two[i*2+1]=arrow_two[i*2+1]+y;
	}
	for(i=0;i<3;i++)
	{
		arrow_one[i*2]=arrow_one[i*2]+x;
		arrow_two[i*2]=arrow_two[i*2]+x;
	}
	setcolor(color);
	setlinestyle(0, 0, 3);
	drawpoly(3,arrow_one);
	drawpoly(3,arrow_two);
	for(i=0;i<3;i++)
	{
		arrow_one[i*2]=arrow_one[i*2]+4;
		arrow_two[i*2]=arrow_two[i*2]-4;
	}
	drawpoly(3,arrow_one);
	drawpoly(3,arrow_two);
}








/**********************************************************
�޸�������溯��
**********************************************************/
// void changePasswordScreen_c(setuser *person,int *judge,setuser *head)
void changePasswordScreen_c(setuser *person,int *judge)//�޸��������
{
	int buttons,mx,my;//�����ر���
	char temp[2]={'\0','\0'};//�������ռ��̻������ı���
	int sign[2]={0,0};//�����ж�����ƶ�����ť�ϵı�־
	int key=0,i[3]={0,0,0};//���뷨��ǵڼ������ֻ���ĸ�Ĳ���
	setChangePass managerTemp;//�޸����뻺��
	int choose=0;//������ĵ��¼�
	// ��ʼ��
	// ����ʼ��
	mouseInit(&mx, &my, &buttons);
	cleardevice();
	setbkcolor(WHITE);
	DrawBeautifulFrame_c();//�߿�
	inputBoxGroup(210, 150, BLUE, LIGHTGRAY);//�������������
	returnBtn_c(60,184,GREEN);
	while(1)
	{
		newxy(&mx, &my, &buttons);
		if(buttons)//����¼�
		{
			if (mx >= 60 && mx <= 120 && my >= 184&& my <= 244 && buttons)//���ذ�ť���ظ������Ľ���
			{
				*judge=turnTo_c(person,4);
				return;
			}
			else if (mx >= 300 && mx <= 470 && my >= 150 && my <= 180 && buttons)//���ԭ����
			{
				frameChange_c(300,150,470,180,GREEN);//ԭ����������
				frameChange_c(300,200,470,230,BLUE);
				frameChange_c(300,250,470,280,BLUE);
				choose=1;
			}
			else if (mx >= 300 && mx <= 470 && my >= 200 && my <= 230 && buttons)//���������
			{
				frameChange_c(300,200,470,230,GREEN);//ԭ����������
				frameChange_c(300,150,470,180,BLUE);
				frameChange_c(300,250,470,280,BLUE);
				choose=2;
			}
			else if (mx >= 300 && mx <= 470 && my >= 250 && my <= 280 && buttons)//���������
			{
				frameChange_c(300,250,470,280,GREEN);//ȷ������������
				frameChange_c(300,150,470,180,BLUE);
				frameChange_c(300,200,470,230,BLUE);
				choose=3;
			}
			// else if (mx >= 300 && mx <= 360 && my >= 350 && my <= 380 && buttons)//���ȷ�ϰ�ť
			// {
				
			// 	if(strcmp(managerTemp.new,managerTemp.confirm)==0)
			// 	{
			// 		if(changePass_c(&managerTemp,person->accounts,head)==1)
			// 		{
			// 			frameChange_c(300,250,470,280,RED);
			// 			frameChange_c(300,150,470,180,BLUE);
			// 			frameChange_c(300,200,470,230,BLUE);
			// 		}
			// 		else if(changePass_c(&managerTemp,person->accounts,head)==0)
			// 		{
			// 			frameChange_c(300,250,470,280,CYAN);
			// 			frameChange_c(300,150,470,180,CYAN);
			// 			frameChange_c(300,200,470,230,CYAN);
			// 		}
			// 	}
			// 	else
			// 	{
			// 		frameChange_c(300,250,470,280,BLUE);
			// 		frameChange_c(300,150,470,180,RED);
			// 		frameChange_c(300,200,470,230,RED);
			// 	}
				
				
			// }
			
			else
			{
				frameChange_c(300,150,470,180,BLUE);
				frameChange_c(300,200,470,230,BLUE);
				frameChange_c(300,250,470,280,BLUE);
				choose=0;
			}
		}//����¼�����
		//�����¼�
		settextstyle(SMALL_FONT,HORIZ_DIR,7);
		setcolor(BLUE);
		switch(choose)
		{
			case 1://ԭ���������¼���(300,150,470,180)����
				key = 0;//���ü�ֵ���õ��¼�ֵ
				temp[0]='\0';
				if (kbhit() != 0)//�����⵽��������
				{
					key = bioskey(0);
					if(key != 0xe08 && i[0]>=0 && i[0]<12)//������벻���˸��
					{
						if(searchKeyValue(key) != '\0')//�������������ĸ��������
						{
							i[0]++;//ԭ�����ַ�����һ
							setfillstyle(1,WHITE);
							bar(305+i[0]*12,153,305+(i[0]+1)*12,177);
							settextstyle(SMALL_FONT,HORIZ_DIR,7);
							setcolor(DARKGRAY);
							temp[0]=searchKeyValue(key);
							managerTemp.old[i[0]-1]=temp[0];
							managerTemp.old[i[0]]='\0';
							outtextxy(305+i[0]*12,153,temp);
						}
						
					}
					else if (key == 0xe08 && i[0]>0)//������˻�ɾ�� 
					{
						setfillstyle(1,WHITE);
						bar(305+i[0]*12,153,305+(i[0]+1)*12,177);
						managerTemp.old[i[0]-1]='\0';
						i[0]--;
					}
				}
				break;
			
			case 2://�����������¼���(300,200,470,230)����
				key = 0;//���ü�ֵ���õ��¼�ֵ
				temp[0]='\0';
				if (kbhit() != 0)//�����⵽��������
				{
					key = bioskey(0);
					if(key != 0xe08 && i[1]>=0 && i[1]<12)//������벻���˸��
					{
						if(searchKeyValue(key) != '\0')//�������������ĸ��������
						{
							i[1]++;//�������ַ�����һ
							setfillstyle(1,WHITE);
							bar(305+i[1]*12,203,305+(i[1]+1)*12,227);
							settextstyle(SMALL_FONT,HORIZ_DIR,7);
							setcolor(DARKGRAY);
							temp[0]=searchKeyValue(key);
							managerTemp.new[i[1]-1]=temp[0];
							managerTemp.new[i[1]]='\0';
							outtextxy(305+i[1]*12,203,temp);
						}
						
					}
					else if (key == 0xe08 && i[1]>0)//������˻�ɾ�� 
					{
						setfillstyle(1,WHITE);
						bar(305+i[1]*12,203,305+(i[1]+1)*12,227);
						managerTemp.new[i[1]-1]='\0';
						i[1]--;
					}
				}
				break;

			case 3://ȷ�����������¼���(300,250,470,280)����
				key = 0;//���ü�ֵ���õ��¼�ֵ
				temp[0]='\0';
				if (kbhit() != 0)//�����⵽��������
				{
					key = bioskey(0);
					if(key != 0xe08 && i[2]>=0 && i[2]<12)//������벻���˸��
					{
						if(searchKeyValue(key) != '\0')//�������������ĸ��������
						{
							i[2]++;//�������ַ�����һ
							setfillstyle(1,WHITE);
							bar(305+i[2]*12,253,305+(i[2]+1)*12,277);
							settextstyle(SMALL_FONT,HORIZ_DIR,7);
							setcolor(DARKGRAY);
							temp[0]=searchKeyValue(key);
							managerTemp.confirm[i[2]-1]=temp[0];
							managerTemp.confirm[i[2]]='\0';
							outtextxy(305+i[2]*12,253,temp);
						}
						
					}
					else if (key == 0xe08 && i[2]>0)//������˻�ɾ�� 
					{
						setfillstyle(1,WHITE);
						bar(305+i[2]*12,253,305+(i[2]+1)*12,277);
						managerTemp.confirm[i[2]-1]='\0';
						i[2]--;
					}
				}
				break;
		}
	}
}
void inputBoxGroup(int x, int y, int framecolor,int color)//����������庯��
{
	puthz(x,y+7,"ԭ���룺",16,16,color);
	puthz(x,y+57,"�����룺",16,16,color);
	puthz(x,y+107,"ȷ�����룺",16,16,color);
	setcolor(framecolor);
	setlinestyle(0, 0, 1);
	rectangle(x+90,y,x+260,y+30);//ԭ���������
	rectangle(x+90,y+50,x+260,y+80);//�����������
	rectangle(x+90,y+100,x+260,y+130);//ȷ�����������
	setcolor(LIGHTRED);
	setfillstyle(1,LIGHTRED);
	bar(x+90,y+200,x+150,y+230);//ȷ�ϰ�ť
	puthz(x+105,y+207,"ȷ��",16,16,WHITE);
}
void frameChange_c(int x1,int y1,int x2,int y2,int color)//������ɫ����
{
	setlinestyle(0, 0, 1);
	setcolor(color);
	rectangle(x1,y1,x2,y2);
}