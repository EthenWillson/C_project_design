#include "common_c.h"
#include "draw_j.h"
void DrawbuyScreen_j(setuser *person, int *judge, setuser *head, all_lines_stations *all); //��Ʊ����
void rectangles_j(int color);
void DrawcheckScreen_j(setuser *person, int *judge, setuser *head);  //��ѯ����
void DrawchargeScreen_j(setuser *person, int *judge, setuser *head); //��ֵ����
void outputcharge_j(setuser *person, int add_money, setuser *head);  //�޸ġ�ʵʱ��ʾ�û�����ʾdelay���ڳ�ֵ
void click_charge_j(int color);                                      //�����Ч��
void DrawUserScreen_j(setuser *person, int *judge);                  //��ͨ�û�����
void rectangles_j(int color)
{
    setlinestyle(0, 0, 3);
    setcolor(color);
    rectangle(170, 80, 470, 150);
    rectangle(170, 200, 470, 270);
    rectangle(170, 320, 470, 390);
}

/***********************************************
Function��DrawUserScreen
Description������ͨ�û�����
Attention:
***********************************************/
void DrawUserScreen_j(setuser *person, int *judge)
{
    int buttons, mx, my;         //�����ر���
    char temp[2] = {'\0', '\0'}; //�������ռ��̻������ı���
    int sign[3] = {0, 0, 0};
    // ��ʼ��
    // ����ʼ��
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    puthz(90, 28, "���ã��𾴵ģ�", 16, 16, GREEN);
    settextstyle(0, 0, 2);
    outtextxy(220, 25, person->accounts);
    returnBtn_c(550, 210, GREEN);
    //�����������Σ����Ϊ��ɫ
    setfillstyle(1, YELLOW);
    bar(170, 80, 470, 150);
    bar(170, 200, 470, 270);
    bar(170, 320, 470, 390);
    rectangles_j(GREEN);

    puthz(200, 95, "��Ʊ", 32, 32, GREEN);
    puthz(200, 215, "�˻���ѯ", 32, 32, GREEN);
    puthz(200, 335, "�˻���ֵ", 32, 32, GREEN);

    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (buttons) //����¼�
        {
            if (mx >= 550 && mx <= 610 && my >= 210 && my <= 270 && buttons) //���ذ�ť�������
            {
                *judge = turnTo_c(person, 1);
                return;
            }
            if (mx >= 170 && mx <= 470 && my >= 80 && my <= 150 && buttons) //���빺Ʊ����
            {
                *judge = turnTo_c(person, 5);
                return;
            }
            if (mx >= 170 && mx <= 470 && my >= 200 && my <= 270 && buttons) //��������ѯ����
            {
                *judge = turnTo_c(person, 6);
                return;
            }
            if (mx >= 170 && mx <= 470 && my >= 320 && my <= 390 && buttons) //�����ֵ����
            {
                *judge = turnTo_c(person, 7);
                return;
            }
        }
        //������ȥ�������ɫ�Ķ���
        if (mx >= 170 && mx <= 470 && my >= 80 && my <= 150 && sign[0] == 0)
        {
            mousehide(mx, my);
            setcolor(LIGHTMAGENTA);
            rectangle(170, 80, 470, 150);
            setcolor(GREEN);
            rectangle(170, 200, 470, 270);
            rectangle(170, 320, 470, 390);
            sign[0] = 1;
            getMousebk(mx, my);
        }
        else if (mx >= 170 && mx <= 470 && my >= 200 && my <= 270 && sign[1] == 0)
        {
            mousehide(mx, my);
            setcolor(LIGHTMAGENTA);
            rectangle(170, 200, 470, 270);
            setcolor(GREEN);
            rectangle(170, 80, 470, 150);
            rectangle(170, 320, 470, 390);
            sign[1] = 1;
            getMousebk(mx, my);
        }
        else if (mx >= 170 && mx <= 470 && my >= 320 && my <= 390 && sign[2] == 0)
        {
            mousehide(mx, my);
            setcolor(LIGHTMAGENTA);
            rectangle(170, 320, 470, 390);
            setcolor(GREEN);
            rectangle(170, 80, 470, 150);
            rectangle(170, 200, 470, 270);
            sign[2] = 1;
            getMousebk(mx, my);
        }
        else if ((sign[0] || sign[1] || sign[2]) && !(mx >= 170 && mx <= 470 && my >= 80 && my <= 150) && !(mx >= 170 && mx <= 470 && my >= 200 && my <= 270) && !(mx >= 170 && mx <= 470 && my >= 320 && my <= 390))
        {
            mousehide(mx, my);
            rectangles_j(GREEN);
            sign[0] = 0;
            sign[1] = 0;
            sign[2] = 0;
            getMousebk(mx, my);
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
    int money;                  //�û����
    int sign[4] = {0, 0, 0, 0}; //sign0��־���Ʒѹ��򡱿�
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
    //��ʾ���밴ť
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
                *judge = turnTo_c(person, -1);
                return;
            }
            if (mx >= 400 && mx <= 510 && my >= 150 && my <= 220 && buttons) //�Ʒѹ���
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
        //��Ʊ��
        if (mx >= 550 && mx <= 610 && my >= 120 && my <= 180 && buttons && flag == 2)
        {
            mousehide(mx, my);
            money = atoi(person->money);
            if (money >= price)
            {
                setfillstyle(1, LIGHTMAGENTA);
                bar(220, 180, 450, 300);
                puthz(220, 210, "��Ʊ�ɹ���", 16, 16, GREEN);
                puthz(220, 240, "��ѯ���������ġ����˻���ѯ", 16, 16, GREEN);
                changemoney_j(-price, person, 10, head);
                changescore_j(price * 10, person, head);
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
        if (mx >= 400 && mx <= 510 && my >= 150 && my <= 220 && sign[0] == 0) //�Ʒѹ������
        {
            mousehide(mx, my);
            setlinestyle(0, 0, 3);
            setcolor(LIGHTMAGENTA);
            rectangle(400, 150, 510, 220);
            sign[0] = 1;
            getMousebk(mx, my);
        }
        else if (mx >= 400 && mx <= 510 && my >= 240 && my <= 310 && sign[1] == 0) //��ʾ�������
        {
            mousehide(mx, my);
            setlinestyle(0, 0, 3);
            setcolor(LIGHTMAGENTA);
            rectangle(400, 240, 510, 310);
            sign[1] = 1;
            getMousebk(mx, my);
        }
        else if (mx >= 550 && mx <= 610 && my >= 120 && my <= 180 && sign[2] == 0 && flag == 2) //��Ʊ����(ѡ��������յ�Ż��ɫ)
        {
            mousehide(mx, my);
            setlinestyle(0, 0, 3);
            setcolor(LIGHTMAGENTA);
            circle(580, 150, 30);
            sign[2] = 1;
            getMousebk(mx, my);
        }
        else if (mx >= 550 && mx <= 610 && my >= 290 && my <= 350 && sign[3] == 0)
        {
            mousehide(mx, my);
            setlinestyle(0, 0, 3);
            setcolor(LIGHTMAGENTA);
            circle(580, 320, 30);
            sign[3] = 1;
            getMousebk(mx, my);
        }
        else if ((sign[0] || sign[1] || sign[2] || sign[3]) && !(mx >= 400 && mx <= 510 && my >= 150 && my <= 220) && !(mx >= 400 && mx <= 510 && my >= 240 && my <= 310) && !(mx >= 550 && mx <= 610 && my >= 120 && my <= 180) && !(mx >= 550 && mx <= 610 && my >= 290 && my <= 350))
        {
            mousehide(mx, my);
            setlinestyle(0, 0, 3);
            setcolor(GREEN);
            circle(580, 150, 30);
            circle(580, 320, 30);
            rectangle(400, 150, 510, 220);
            rectangle(400, 240, 510, 310);
            sign[0] = sign[1] = sign[2] = sign[3] = 0;
            getMousebk(mx, my);
        }
    }
}
/**********************************************************
Function:  DrawcheckScreen
Description�������˻���ѯ����
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
    settextstyle(0, 0, 2);
    setcolor(LIGHTMAGENTA);

    puthz(90, 28, "���ã��𾴵ģ�", 16, 16, CYAN);
    setcolor(MAGENTA);
    outtextxy(220, 30, person->accounts);

    setlinestyle(0, 0, 1);
    setcolor(LIGHTRED);

    //�������ذ�ť
    returnBtn_c(300, 400, GREEN);

    puthz(90, 100, "��", 16, 16, CYAN);
    puthz(250, 100, "���֣�", 16, 16, CYAN);
    //changemoney_j(0, person, 10, head);
    setcolor(MAGENTA);
    if (atoi(person->money) == 0)
    {
        outtextxy(140, 95, "0");
    }
    else
    {
        outtextxy(140, 95, person->money);
    }
    if (atoi(person->score) == 0)
    {
        outtextxy(300, 95, "0");
    }
    else
    {
        outtextxy(300, 95, person->score);
    }

    puthz(90, 160, "������ѡ��", 16, 16, CYAN);
    setfillstyle(1, LIGHTCYAN);

    bar(100, 200, 280, 290);
    bar(330, 200, 510, 290);
    bar(100, 305, 280, 395);
    bar(330, 305, 510, 395);
    puthz(160, 223, "��Ʊ", 32, 32, MAGENTA);
    puthz(357, 223, "�޸�����", 32, 32, MAGENTA);
    puthz(127, 328, "��Ʊ��¼", 32, 32, MAGENTA);
    puthz(357, 328, "�����̳�", 32, 32, MAGENTA);

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
            if (mx >= 330 && mx <= 510 && my >= 200 && my <= 290 && buttons) //����޸����뷽��
            {
                *judge = turnTo_c(person, 14);
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
Function:  outputcharge
Description���޸ġ�ʵʱ��ʾ�û�����ʾdelay���ڳ�ֵ
Attention:  ��
**********************************************************/
void outputcharge_j(setuser *person, int add_money, setuser *head)
{
    setcolor(LIGHTMAGENTA);
    setlinestyle(0, 0, 1);
    rectangle(400, 70, 560, 110);
    puthz(410, 75, "����֧���С�����", 16, 16, LIGHTMAGENTA);
    settextstyle(0, 0, 2);
    setcolor(LIGHTMAGENTA);
    if (atoi(person->money) == 0)
    {
        outtextxy(200, 75, "0");
    }
    else
    {
        outtextxy(200, 75, person->money);
    }
    puthz(270, 75, "Ԫ", 16, 16, LIGHTMAGENTA);
    delay(1000);
    setcolor(WHITE);
    bar(400, 70, 560, 110);
    bar(200, 70, 280, 110);
    changemoney_j(add_money, person, 10, head); //��ֵadd_moneyԪ���޸�person->money��ֵ
    settextstyle(0, 0, 2);
    setcolor(LIGHTMAGENTA);
    outtextxy(200, 75, person->money);
    puthz(270, 75, "Ԫ", 16, 16, LIGHTMAGENTA);
}
/**********************************************************
Function:  click_charge_j
Description�����֮��ӿ�Ч��
Attention:  ��
**********************************************************/
void click_charge_j(int color) //���֮��ӿ�Ч��
{
    int kuang[] = {498, 55, 555, 55, 555, 85, 498, 85, 498, 55};
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    setcolor(color);
    drawpoly(5, kuang);
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
    int key = 0, sign = 0;       //���뷨��ǵڼ������ֻ���ĸ�Ĳ���
    int choose;
    int charge = 0;
    int flag;
    char place[4];
    char str_charge[4];
    int zidingyi;
    place[0] = '\0';
    mouseInit(&mx, &my, &buttons);
    choose = 0;
    flag = 0;
    zidingyi = 0;
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    puthz(80, 28, "���ã��𾴵ģ�", 16, 16, GREEN);
    outtextxy(190, 27, person->accounts);
    //puthz(400, 435, "��������", 16, 16, MAGENTA);
    //puthz(540, 435, "����", 16, 16, MAGENTA);

    // closegraph();
    // printf("%s",place);//���������
    // getch();

    setlinestyle(0, 0, 1);
    setcolor(LIGHTRED);
    //rectangle(398, 433, 465, 453); //�������ǵ�λ��
    //rectangle(538, 433, 571, 453); //������λ��
    //�������ذ�ť
    returnBtn_c(300, 400, GREEN);

    puthz(80, 75, "������", 16, 16, GREEN);
    settextstyle(0, 0, 2);
    setcolor(LIGHTMAGENTA);
    if (atoi(person->money) == 0)
    {
        outtextxy(200, 75, "0");
    }
    else
    {
        outtextxy(200, 75, person->money);
    }
    puthz(270, 75, "Ԫ", 16, 16, LIGHTMAGENTA);
    setlinestyle(0, 0, 1);
    puthz(80, 110, "������ѡ��", 16, 16, GREEN);
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
            else if (mx >= 100 && mx <= 190 && my >= 150 && my <= 200 && buttons && choose == 0)
            {
                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370); //���ǵ������ѳɹ���ֵXXXԪ������ʾ
                bar(180, 70, 290, 100);
                outputcharge_j(person, 10, head);
                puthz(80, 350, "���ѳɹ���ֵ10Ԫ", 16, 16, RED);
            }
            else if (mx >= 280 && mx <= 370 && my >= 150 && my <= 200 && buttons && choose == 0)
            {
                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                bar(180, 70, 290, 100);
                outputcharge_j(person, 20, head);
                puthz(80, 350, "���ѳɹ���ֵ20Ԫ", 16, 16, RED);
            }
            else if (mx >= 460 && mx <= 550 && my >= 150 && my <= 200 && buttons && choose == 0)
            {
                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                bar(180, 70, 290, 100);
                outputcharge_j(person, 50, head);
                puthz(80, 350, "���ѳɹ���ֵ50Ԫ", 16, 16, RED);
            }
            else if (mx >= 100 && mx <= 190 && my >= 280 && my <= 330 && buttons && choose == 0)
            {

                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                bar(180, 70, 290, 100);
                outputcharge_j(person, 100, head);
                puthz(80, 350, "���ѳɹ���ֵ100Ԫ", 16, 16, RED);
            }
            else if (mx >= 280 && mx <= 370 && my >= 280 && my <= 330 && buttons && choose == 0)
            {

                setfillstyle(1, WHITE);
                bar(60, 340, 250, 370);
                bar(180, 70, 290, 100);
                outputcharge_j(person, 200, head);
                puthz(80, 350, "���ѳɹ���ֵ200Ԫ", 16, 16, RED);
            }
            else if (mx >= 460 && mx <= 550 && my >= 280 && my <= 330 && buttons && zidingyi == 0) //֮ǰû������Զ��塱
            {
                setfillstyle(1, DARKGRAY);
                bar(400, 50, 560, 112);
                setfillstyle(1, WHITE);
                bar(500, 55, 555, 85);
                bar(420, 88, 470, 108); //ȷ��
                bar(490, 88, 540, 108); //ȡ��
                puthz(430, 90, "ȷ��", 16, 16, BLUE);
                puthz(500, 90, "ȡ��", 16, 16, BLUE);
                puthz(405, 60, "�������", 16, 16, WHITE);
                zidingyi = 1;
            }
            else if (mx >= 500 && mx <= 545 && my >= 55 && my <= 85 && buttons) //�����Ч��
            {
                mousehide(mx, my);
                choose = 1; //ѡ���˿��
                click_charge_j(GREEN);
                getMousebk(mx, my);
            }
            else if (mx >= 490 && mx <= 540 && my >= 88 && my <= 108 && buttons) //�����ȡ����
            {
                mousehide(mx, my);
                setfillstyle(1, WHITE);
                bar(400, 50, 560, 112);
                bar(350, 115, 600, 147);
                choose = 0;
                sign = 0;
                zidingyi = 0;
                getMousebk(mx, my);
            }
            else if (mx >= 420 && mx <= 470 && my >= 88 && my <= 108 && buttons && choose == 1 && charge != 0 && flag == 0) //�����ȷ�ϡ�
            {
                mousehide(mx, my);
                setfillstyle(1, WHITE);
                bar(400, 50, 560, 112);
                bar(60, 340, 250, 370);
                bar(180, 70, 290, 100);
                choose = 0;
                sign = 0;
                zidingyi = 0;
                outputcharge_j(person, charge, head);
                itoa(charge, str_charge, 10);
                bar(60, 340, 250, 370); //���ǵ������ѳɹ���ֵXXXԪ������ʾ
                puthz(80, 350, "���ѳɹ���ֵ", 16, 16, RED);
                puthz(180, 350, str_charge, 16, 16, RED);
                puthz(235, 350, "Ԫ", 16, 16, RED);
                getMousebk(mx, my);
            }
        }
        settextstyle(SMALL_FONT, HORIZ_DIR, 7);
        setcolor(BLUE);
        if (choose == 1) //ѡ���˺ſ�
        {
            key = 0; //���ü�ֵ���õ��¼�ֵ
            temp[0] = '\0';
            if (kbhit() != 0) //�����⵽��������
            {
                mousehide(mx, my);
                key = bioskey(0);
                if (key != 0xe08 && sign >= 0 && sign <= 3) //������벻���˸��
                {
                    if (searchKeyValue(key) == '0' || searchKeyValue(key) == '1' || searchKeyValue(key) == '2' || searchKeyValue(key) == '3' || searchKeyValue(key) == '4' ||
                        searchKeyValue(key) == '5' || searchKeyValue(key) == '6' || searchKeyValue(key) == '7' || searchKeyValue(key) == '8' || searchKeyValue(key) == '9') //���������������
                    {
                        sign++; //�ַ�����һ
                        //setfillstyle(1,WHITE);
                        //bar(500+sign*12,80,500+(sign+1)*12,98);
                        settextstyle(SMALL_FONT, HORIZ_DIR, 7);
                        setcolor(BLUE);
                        temp[0] = searchKeyValue(key);
                        place[sign - 1] = temp[0]; //�ַ�����
                        place[sign] = '\0';
                        outtextxy(490 + sign * 12, 60, temp);
                        charge = atoi(place);
                    }
                }
                else if (key == 0xe08 && sign > 0) //������˻�ɾ��
                {
                    sign--; //�ַ�����1
                    setfillstyle(1, WHITE);
                    bar(500 + sign * 12, 60, 500 + (sign + 1) * 12, 78); //�����1�˺�
                    place[sign] = '\0';
                    charge = atoi(place);
                }
                getMousebk(mx, my);
            }
            if (charge > 200)
            {
                puthz(350, 120, "���ʳ�ֵ���ɳ���200Ԫ��", 16, 16, RED);
                flag = 1;
            }
            if (charge <= 200 && choose == 1 && flag == 1)
            {
                setfillstyle(1, WHITE);
                bar(350, 115, 600, 147);
                flag = 0;
            }
        }
    }
}