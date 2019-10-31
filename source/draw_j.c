#include"common_c.h"
#include"draw_j.h"
void DrawbuyScreen_j(setuser *person, int *judge, setuser *head, all_lines_stations *all);//��Ʊ����
void DrawcheckScreen_j(setuser *person, int *judge, setuser *head);//��ѯ����
void DrawchargeScreen_j(setuser *person, int *judge, setuser *head);//��ֵ����
void DrawUserScreen_j(setuser *person,int *judge);//��ͨ�û�����
/***********************************************
Function��DrawUserScreen
Description������ͨ�û�����
Attention:
***********************************************/
void DrawUserScreen_j(setuser *person,int *judge)
{
	int buttons,mx,my;//�����ر���
	char temp[2]={'\0','\0'};//�������ռ��̻������ı���
	// ��ʼ��
	// ����ʼ��
	mouseInit(&mx, &my, &buttons);
	cleardevice();
	setbkcolor(WHITE);
	DrawBeautifulFrame_c();
	puthz(90, 28, "���ã��𾴵ģ�", 16, 16, GREEN);
	outtextxy(220,25,person->accounts);
	puthz(400, 435, "��������", 16, 16,MAGENTA );
	puthz(540 ,435, "����", 16, 16, MAGENTA);
	
	setlinestyle(0, 0, 1);
	setcolor(LIGHTRED);
	rectangle(398,433,465,453);//�������ǵ�λ��
	rectangle(538,433,571,453);//������λ��
	
	//�����˳���ť
	setlinestyle(0, 0, 3);
	setcolor(LIGHTRED);
	arc(550, 35, 110, 430, 15);
	line(550, 5, 550, 31);

    //�����������Σ����Ϊ��ɫ
	setfillstyle(1, YELLOW);
	bar(170,80,470,150);
	bar(170,200,470,270);
	bar(170,320,470,390);
	setlinestyle(0, 0, 3);
	setcolor(GREEN);
	line(170,80,470,80);
	line(170,80,170,150);
	line(470,80,470,150);
	line(170,150,470,150);
	line(170,200,470,200);
	line(170,200,170,270);
	line(470,200,470,270);
	line(170,270,470,270);
	line(170,320,470,320);
	line(170,320,170,390);
	line(470,320,470,390);
	line(170,390,470,390);
	puthz(200, 95, "��Ʊ", 32, 32, GREEN);
	puthz(200, 215, "�˻���ѯ", 32, 32, GREEN);
	puthz(200, 335, "�˻���ֵ", 32, 32, GREEN);

	while(1)
	{
		newxy(&mx, &my, &buttons);
		if(buttons)//����¼�
		{
			if (mx >= 535 && mx <= 565 && my >= 5&& my <= 45 && buttons)//�˳���ť����˳�
			{
				*judge=turnTo_c(person,1);
				return;
			}
			if (mx >= 170 && mx <= 470 && my >=80 && my<=150 && buttons)//���빺Ʊ����
			{
			    *judge=turnTo_c(person,5);
				return;
			}
			if (mx >= 170 && mx <= 470 && my >= 200&& my <= 270 && buttons)//��������ѯ����
			{
				*judge=turnTo_c(person,6);
				return;
			}
			if (mx >= 170 && mx <= 470 && my >= 320&& my <= 390 && buttons)//�����ֵ����
			{
				*judge=turnTo_c(person,7);
				return;
			}
		}
	}
}
/**********************************************************
Function:  DrawbuyScreen
Description��	������Ʊ���棬ʵ�ֹ�Ʊ����
Attention:  ��
**********************************************************/
void DrawbuyScreen_j(setuser *person, int *judge, setuser *head, all_lines_stations *all)
{
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
    int i;                       //����ѭ������
    int sta_checkclick[5][10];   //��ά�����־�����������˼��Σ�0��ʾû�����1��ʾ����ˣ�����ʵ���ûɶ���ˣ����ڿ���ɾ����
    int flag;
    int start_station; //�洢�����Ϣ,����12����1���ߵ�2վΪ���
    int end_station;   //�洢�յ���Ϣ��������һ�в��
    int price;
    int money; //�û����
    //char sss[10]="������";
    flag = 0;
    start_station = 0;
    end_station = 0;
    price = 0;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    //DrawBeautifulFrame_c();
    //puthz(30,130,sss,16,16,RED);//��仰������ʾ��
    //outtextxy(30,160,all->line1[1].x);

    //�������ذ�ť
    returnBtn_c(550, 210, GREEN);

    setcolor(BROWN);
    setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
    line(460, 0, 460, 75);
    line(460, 75, 640, 75);

    setlinestyle(0, 0, 3);
    setcolor(LIGHTCYAN);
    line(500, 10, 550, 10);
    outtextxy(560, 0, "1");
    puthz(570, 5, "����", 16, 16, LIGHTBLUE);
    setcolor(LIGHTGREEN);
    line(500, 30, 550, 30);
    outtextxy(560, 20, "2");
    puthz(570, 25, "����", 16, 16, LIGHTGREEN);
    setcolor(YELLOW);
    line(500, 50, 550, 50);
    outtextxy(560, 40, "4");
    puthz(570, 45, "����", 16, 16, YELLOW);
    puthz(180, 0, "�人������ͨ��", 32, 32, BROWN);

    Drawstation1_j();
    Drawstation2_j();
    Drawstation4_j();
    DrawCircles_j();

    //��Ʊ��ť
    setcolor(GREEN);
    circle(580, 150, 30);
    //��ѡ��ť
    setcolor(GREEN);
    circle(580, 320, 30);
    //�Ʒѹ���ť
    rectangle(400, 150, 510, 220);
    rectangle(400, 240, 510, 310);

    puthz(565, 142, "��Ʊ", 16, 16, CYAN);
    puthz(565, 312, "��ѡ", 16, 16, CYAN);
    puthz(425, 180, "�Ʒѹ���", 16, 16, CYAN);
    puthz(425, 270, "��ʾ����", 16, 16, CYAN);
    puthz(30, 5, "���ȵ�����", 16, 16, RED);
    puthz(30, 25, "�ٵ���յ�", 16, 16, RED);
    puthz(30, 45, "�������Ʊ��ť", 16, 16, RED);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons) //ר�������㷵���ϸ�����
        {
            if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //���ذ�ť�������
            {
                *judge = turnTo_c(person, 3);
                return;
            }
            if (mx >= 400 && mx <= 510 && my >= 150 && my <= 220 && buttons)
            {
                *judge = turnTo_c(person, 8);
                return;
            }
            if (mx >= 400 && mx <= 510 && my >= 240 && my <= 310 && buttons)
            {
                DrawDistance_j();
            }
        }

        /***************���ڵ�һ�ε�����վ******************/
        if (buttons && flag == 0)
        {
            //�����ߵ�ȦȦ��������ʾ�����
            //1���ߵ�
            mousehide(mx, my);
            if (mx >= 75 && mx <= 85 && my >= 95 && my <= 105 && buttons) //��һ�ε��
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
            if (mx >= 255 && mx <= 265 && my >= 95 && my <= 105 && buttons) //�����ѭ����վ��1��2�Ľ��㣬��ʱ��Ҫ���⴦��
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
            //2���ߵ�
            if (mx >= 295 && mx <= 305 && my >= 65 && my <= 75 && buttons) //��һ�ε��
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
                Draw_start_sta_j(260, 324, &all->line2[6], &sta_checkclick[2][6], &start_station, &flag, &price); //�и�С�ļ���ʧ�󣬵����ⲻ��
            }                                                                                                     //������draw������ʵ��66
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
            //4���ߵ�
            if (mx >= 75 && mx <= 85 && my >= 375 && my <= 385 && buttons) //��һ�ε��
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
        } //if��һ�ε����ʼվ
        /***************���ڵ�һ�ε�����վ֮��******************/

        if (buttons && flag == 1)
        {
            mousehide(mx, my);
            if (mx >= 75 && mx <= 85 && my >= 95 && my <= 105 && buttons) //��һ�ε��
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
            if (mx >= 255 && mx <= 265 && my >= 95 && my <= 105 && buttons) //�����ѭ����վ��1��2�Ľ��㣬��ʱ��Ҫ���⴦��
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
            //2���ߵ�
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
            //4���ߵ�
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
        //��ѡ��flag������0������ǰ�������
        if (mx >= 550 && mx <= 610 && my >= 290 && my <= 350 && buttons)
        {
            mousehide(mx, my);
            flag = 0;
            setfillstyle(1, WHITE); //��ԭ����Ϳ��
            bar(20, 130, 160, 280);
            DrawCircles_j();
            start_station = 0; //���վ��0
            end_station = 0;   //�յ�վ��0
            price = 0;
            getMousebk(mx, my);
        }
        //580, 150
        if (mx >= 550 && mx <= 610 && my >= 120 && my <= 180 && buttons && flag == 2)
        {
            mousehide(mx, my);
            money = atoi(person->money);
            if (money >= price)
            {
                setfillstyle(1, LIGHTMAGENTA);
                bar(220, 180, 420, 300);
                puthz(220, 210, "��Ʊ�ɹ���", 16, 16, GREEN);
                puthz(220, 240, "��ѯ���������ġ����˻���ѯ", 16, 16, GREEN);
                //( setuser *person,  setuser *head,int *start_name,int*end_name,int price);

                changemoney_j(-price, person, 10, head);
                changescore_j(price * 10, person, head);
                /*
                closegraph();
                printf("%s",person->score);
                getch();
                */
                changerecord_j(person, head, start_station, end_station, price);
                delay(2000);
                *judge = turnTo_c(person, -1);
                return;
            }
            if (money < price)
            {
                setfillstyle(1, LIGHTMAGENTA);
                bar(220, 180, 420, 300);
                puthz(220, 225, "���㣡���ȳ�ֵ��", 16, 16, GREEN);
                delay(2000);
                *judge = turnTo_c(person, 3);
                return;
            }
            getMousebk(mx, my);
        }
    }
}
/**********************************************************
Function:  DrawcheckScreen
Description����������ѯ����
Attention:  ��
**********************************************************/
void DrawcheckScreen_j(setuser *person, int *judge, setuser *head)
{
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    settextstyle(0,0,2);
    setcolor(LIGHTMAGENTA);

    puthz(90, 28, "���ã��𾴵ģ�", 16, 16, CYAN);
    setcolor(MAGENTA);
    outtextxy(220, 30, person->accounts);
    puthz(400, 435, "��������", 16, 16, MAGENTA);
    puthz(540, 435, "����", 16, 16, MAGENTA);

    setlinestyle(0, 0, 1);
    setcolor(LIGHTRED);
    rectangle(398, 433, 465, 453); //�������ǵ�λ��
    rectangle(538, 433, 571, 453); //������λ��

    //�������ذ�ť
    returnBtn_c(300, 400, GREEN);

    puthz(90, 100, "��", 16, 16, CYAN);
    puthz(250, 100, "���֣�", 16, 16, CYAN);
    //changemoney_j(0, person, 10, head);
    setcolor(MAGENTA);
    outtextxy(140, 90, person->money);
    outtextxy(300, 90, person->score);
    /*
    closegraph();
    printf("%s",person->score);
    printf("%s",person->money);
    getch();
    */

    puthz(90, 160, "������ѡ��", 16, 16, CYAN);
    setfillstyle(1, LIGHTCYAN);

    bar(100, 200, 280, 290);
    bar(330, 200, 510, 290);
    bar(100, 305, 280, 395);
    bar(330, 305, 510, 395);
    puthz(160, 223, "��Ʊ", 32, 32, MAGENTA);
    puthz(357, 223, "�˻���ֵ", 32, 32, MAGENTA);
    puthz(127, 328, "��Ʊ��¼", 32, 32, MAGENTA);
    puthz(357, 328, "���ֶһ�", 32, 32, MAGENTA);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            mousehide(mx, my);
            if (mx >= 300 && mx <= 360 && my >= 400 && my <= 460 && buttons) //���ذ�ť�������
            {
                *judge = turnTo_c(person, -1);
                return;
            }
            if (mx >= 100 && mx <= 280 && my >= 200 && my <= 290 && buttons) //�����Ʊ���򣬷��ع�Ʊ����
            {
                *judge = turnTo_c(person, 5);
                return;
            }
            if (mx >= 330 && mx <= 510 && my >= 200 && my <= 290 && buttons) //����˻���ֵ���򣬷����˻���ֵ����
            {
                *judge = turnTo_c(person, 7);
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
Function:  DrawchargeScreen
Description������ֵ���棬����ʵ�ֳ�ֵ����
Attention:  ��
**********************************************************/
void DrawchargeScreen_j(setuser *person, int *judge, setuser *head)
{
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    puthz(90, 28, "���ã��𾴵ģ�", 16, 16, GREEN);
    outtextxy(220, 25, person->accounts);
    puthz(400, 435, "��������", 16, 16, MAGENTA);
    puthz(540, 435, "����", 16, 16, MAGENTA);

    setlinestyle(0, 0, 1);
    setcolor(LIGHTRED);
    rectangle(398, 433, 465, 453); //�������ǵ�λ��
    rectangle(538, 433, 571, 453); //������λ��
                                   //�������ذ�ť
    returnBtn_c(300, 400, GREEN);

    puthz(80, 80, "��ѡ���ֵ��", 16, 16, GREEN);
    setlinestyle(0, 0, 1);
    setcolor(YELLOW);
    //����ֵ��
    rectangle(100, 150, 190, 200);
    rectangle(280, 150, 370, 200);
    rectangle(460, 150, 550, 200);
    rectangle(100, 280, 190, 330);
    rectangle(280, 280, 370, 330);
    rectangle(460, 280, 550, 330);

    puthz(122, 170, "10Ԫ", 16, 16, LIGHTCYAN);
    puthz(302, 170, "20Ԫ", 16, 16, LIGHTCYAN);
    puthz(482, 170, "50Ԫ", 16, 16, LIGHTCYAN);
    puthz(112, 300, "100Ԫ", 16, 16, LIGHTCYAN);
    puthz(292, 300, "200Ԫ", 16, 16, LIGHTCYAN);
    puthz(482, 295, "�Զ���", 16, 16, LIGHTCYAN);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons)
        {
            mousehide(mx, my);
            if (mx >= 300 && mx <= 360 && my >= 400 && my <= 460 && buttons) //���ذ�ť�������
            {
                *judge = turnTo_c(person, -1);
                return;
            }
            if (mx >= 100 && mx <= 190 && my >= 150 && my <= 200 && buttons)
            {
                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                changemoney_j(10, person, 10, head); //��ֵ10Ԫ���޸�person->money��ֵ
                //changemoney_j(person,head);
                puthz(80, 350, "���ѳɹ���ֵ10Ԫ", 16, 16, RED);
            }
            if (mx >= 280 && mx <= 370 && my >= 150 && my <= 200 && buttons)
            {
                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                changemoney_j(20, person, 10, head); //��ֵ20Ԫ���޸�person->money��ֵ
                //changemoney_j(person,head);
                puthz(80, 350, "���ѳɹ���ֵ20Ԫ", 16, 16, RED);
            }
            if (mx >= 460 && mx <= 550 && my >= 150 && my <= 200 && buttons)
            {
                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                changemoney_j(50, person, 10, head);
                //changemoney_j(person,head);
                puthz(80, 350, "���ѳɹ���ֵ50Ԫ", 16, 16, RED);
            }
            if (mx >= 100 && mx <= 190 && my >= 280 && my <= 330 && buttons)
            {

                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                changemoney_j(100, person, 10, head);
                //changemoney_j(person,head);
                puthz(80, 350, "���ѳɹ���ֵ100Ԫ", 16, 16, RED);
            }
            if (mx >= 280 && mx <= 370 && my >= 280 && my <= 330 && buttons)
            {

                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                changemoney_j(200, person, 10, head);
                //changemoney_j(person,head);
                puthz(80, 350, "���ѳɹ���ֵ200Ԫ", 16, 16, RED);
            }
            if (mx >= 460 && mx <= 550 && my >= 280 && my <= 330 && buttons)
            {
                //������
            }
            getMousebk(mx, my);
        }
    }
}