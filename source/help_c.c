/**********************************************************
���ļ�ר�Ŵ�Ű���������صĺ���
���ߣ��¿���
**********************************************************/
#include"help_c.h"
#include"common_c.h"
void DrawhelpScreen_c(int *judge)
{
    int buttons, mx, my;         //�����ر���
    int mouseover[4]={0,0,0,0};
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//���ذ�ť

    puthz(90,40,"�人������ͨģ��ϵͳʹ��˵��",32,32,CYAN);
    DrawListbutton(200, 120, LIGHTGRAY,LIGHTGRAY,"��½��ע��");
    DrawListbutton(200, 190, LIGHTGRAY,LIGHTGRAY,"��ֵ�͹�Ʊ");
    DrawListbutton(200, 260, LIGHTGRAY,LIGHTGRAY,"�˺����¼");
    DrawListbutton(200, 330, LIGHTGRAY,LIGHTGRAY,"����ӵ���");
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (mx >= 200 && mx <= 440 && my >= 120 && my <= 150 && mouseover[0]==0) //���������½��ť
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,110,500,160);
            DrawListbutton(210, 110, LIGHTBLUE , LIGHTBLUE,"��½��ע��");
            mouseover[0]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 200 && mx <= 440 && my >= 120 && my <= 150 )&& mouseover[0]==1) //����Ƴ���½��ť
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,100,500,160);
            DrawListbutton(200, 120, LIGHTGRAY,LIGHTGRAY,"��½��ע��");
            mouseover[0]=0;
            getMousebk(mx,my);
        }
        if (mx >= 200 && mx <= 440 && my >= 190 && my <= 220 && mouseover[1]==0) //���������ֵ��ť
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,160,500,230);
            DrawListbutton(210, 180, LIGHTBLUE , LIGHTBLUE,"��ֵ�͹�Ʊ");
            mouseover[1]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 200 && mx <= 440 && my >= 190 && my <= 220 )&& mouseover[1]==1) //����Ƴ���ֵ��ť
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,160,500,230);
            DrawListbutton(200, 190, LIGHTGRAY,LIGHTGRAY,"��ֵ�͹�Ʊ");
            mouseover[1]=0;
            getMousebk(mx,my);
        }
        if (mx >= 200 && mx <= 440 && my >= 260 && my <= 290 && mouseover[2]==0) //��������˺Ű�ť
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,230,500,300);
            DrawListbutton(210, 250, LIGHTBLUE,LIGHTBLUE,"�˺����¼");
            mouseover[2]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 200 && mx <= 440 && my >= 260 && my <= 290 )&& mouseover[2]==1) //����Ƴ��˺Ű�ť
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,230,500,300);
            DrawListbutton(200, 260, LIGHTGRAY,LIGHTGRAY,"�˺����¼");
            mouseover[2]=0;
            getMousebk(mx,my);
        }
        if (mx >= 200 && mx <= 440 && my >= 330 && my <= 360 && mouseover[3]==0) //�����������ť
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,300,500,370);
            DrawListbutton(210, 320, LIGHTBLUE,LIGHTBLUE,"����ӵ���");
            mouseover[3]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 200 && mx <= 440 && my >= 330 && my <= 360 )&& mouseover[3]==1) //����Ƴ�����ť
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,300,500,370);
            DrawListbutton(200, 330, LIGHTGRAY,LIGHTGRAY,"����ӵ���");
            mouseover[3]=0;
            getMousebk(mx,my);
        }
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //���ذ�ť�������
            {
                *judge = 1;
                return;
            }
            else if (mx >= 200 && mx <= 440 && my >= 120 && my <= 150) //�����½��ť
            {
                *judge = 21;
                return;
            }
            else if (mx >= 200 && mx <= 440 && my >= 190 && my <= 220) //�����ֵ�͹�Ʊ��ť
            {
                *judge = 22;
                return;
            }
            else if (mx >= 200 && mx <= 440 && my >= 260 && my <= 290) //����˺����¼��ť
            {
                *judge = 23;
                return;
            }
            else if (mx >= 200 && mx <= 440 && my >= 330 && my <= 360) //�������ӵ��Ȱ�ť
            {
                *judge = 24;
                return;
            }
        }
    }   
}
/**********************************************************
Function:      DrawLoginHelp
Description��	������½��ע��������� ����21
Input:   ͼ������ꣻ��ɫ
**********************************************************/
void DrawLoginHelp(int *judge)
{
    int buttons, mx, my;         //�����ر���
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//���ذ�ť
    puthz(248,40,"��½��ע��",32,32,CYAN);
    puthz(70,100,"����½��",16,16,LIGHTGRAY);
    puthz(80,130,"���û���½�������Ѿ�ע�������ͨ�û���������Ͻ��û���ť����",16,16,LIGHTGRAY);
    puthz(80,150,"�����������û��������룬������¼��ť����ϵͳ��",16,16,LIGHTGRAY);
    puthz(80,180,"������Ա��½�������Ѿ�ע����Ĺ���Ա��������Ͻǹ���Ա��ť��",16,16,LIGHTGRAY);
    puthz(80,200,"�ڿ����������û��������뼰Ȩ���룬������¼��ť����ϵͳ��",16,16,LIGHTGRAY);
    puthz(70,240,"��ע�᣺",16,16,LIGHTGRAY);
    puthz(80,270,"���û�ע�᣺�������û���������Ͻ��û���ť���ڿ�����������Ҫ",16,16,LIGHTGRAY);
    puthz(80,290,"�������û��������룬�����Զ�ע�ᰴť����ע���˻�������ϵͳ��",16,16,LIGHTGRAY);
    puthz(80,320,"������Աע�᣺�����¹���Ա��������Ͻǹ���Ա��ť���ڿ�������",16,16,LIGHTGRAY);
    puthz(80,340,"����Ҫ�������û��������룬Ȩ������дcjwzs�������Զ�ע��",16,16,LIGHTGRAY);
    puthz(80,360,"��ť����ע���˻�������ϵͳ��",16,16,LIGHTGRAY);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //���ذ�ť�������
            {
                *judge = 20;
                return;
            }
        }
    }
}
/**********************************************************
Function:      DrawBuyHelp
Description��	������ֵ�͹�Ʊ�������� ����22
Input:   ͼ������ꣻ��ɫ
**********************************************************/
void DrawBuyHelp(int *judge)
{
    int buttons, mx, my;         //�����ر���
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//���ذ�ť
    puthz(248,40,"��ֵ�͹�Ʊ",32,32,CYAN);
    puthz(70,100,"����ֵ��",16,16,LIGHTGRAY);
    puthz(80,130,"���û���ֵ�����û����������˻���ֵѡ������ֵ���棬ѡ��",16,16,LIGHTGRAY);
    puthz(80,150,"��ֵ�Ľ����ɳ�ֵ",16,16,LIGHTGRAY);
    puthz(80,180,"������Ա��ֵ���ڹ���Ա�����������Ͻ�ͷ��ͼ�꣬�������Ա����",16,16,LIGHTGRAY);
    puthz(80,200,"�����ģ�����˻���Ϣ�������˻���Ϣ���棬�ٵ���˻���ֵ������",16,16,LIGHTGRAY);
    puthz(80,220,"��ֵ���棬����ͬ�û���ֵ",16,16,LIGHTGRAY);
    puthz(70,260,"����Ʊ��",16,16,LIGHTGRAY);
    puthz(80,290,"���û���Ʊ�����û�����������Ʊѡ����빺Ʊ���棬ѡ�����",16,16,LIGHTGRAY);
    puthz(80,310,"���յ�󣬵����Ʊ",16,16,LIGHTGRAY);
    puthz(80,340,"������Ա��Ʊ���ڹ���Ա��������̫���²࣬���빺Ʊ���棬����",16,16,LIGHTGRAY);
    puthz(80,360,"ͬ�û���Ʊ",16,16,LIGHTGRAY);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //���ذ�ť�������
            {
                *judge = 20;
                return;
            }
        }
    }
}
/**********************************************************
Function:      DrawRecordHelp
Description��	�����˺����¼�������� ����23
Input:   ͼ������ꣻ��ɫ
**********************************************************/
void DrawRecordHelp(int *judge)
{
    int buttons, mx, my;         //�����ر���
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//���ذ�ť
    puthz(248,40,"�˺����¼",32,32,CYAN);
    puthz(70,100,"���޸����룺",16,16,LIGHTGRAY);
    puthz(80,130,"���û������û����������˻���ѯѡ������˻���ѯ���棬ѡ��",16,16,LIGHTGRAY);
    puthz(80,150,"�޸�����ѡ���Ҫ�����뼴���޸�����",16,16,LIGHTGRAY);
    puthz(80,180,"������Ա���ڹ���Ա�����������Ͻ�ͷ��ͼ�꣬�������Ա������",16,16,LIGHTGRAY);
    puthz(80,200,"�ģ�����޸����룬����ͬ�û�",16,16,LIGHTGRAY);
    puthz(70,240,"�����м�¼��",16,16,LIGHTGRAY);
    puthz(80,270,"���û������û����������˻���ѯѡ������˻���ѯ���棬ѡ��",16,16,LIGHTGRAY);
    puthz(80,290,"��Ʊ��¼ѡ��ɲ鿴��ʷ��Ʊ��¼",16,16,LIGHTGRAY);
    puthz(80,320,"������Ա���ڹ���Ա�������ĵ���˻���ѯѡ���������ͬ�û�",16,16,LIGHTGRAY);
    
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //���ذ�ť�������
            {
                *judge = 20;
                return;
            }
        }
    }
}
/**********************************************************
Function:      DrawManageHelp
Description��	��������ӵ��Ȱ������� ����24
Input:   ͼ������ꣻ��ɫ
**********************************************************/
void DrawManageHelp(int *judge)
{
    int buttons, mx, my;         //�����ر���
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//���ذ�ť
    puthz(248,40,"����ӵ���",32,32,CYAN);
    puthz(65,100,"�����ȣ�",16,16,LIGHTGRAY);
    puthz(75,130,"���������Ա�����棬���̫���ϲ࣬������Ƚ��棬��������ģ�飺",16,16,LIGHTGRAY);
    puthz(85,160,"����·ѡ��ģ�飺���Ͻǿ�ѡ����Ƶ���·",16,16,LIGHTGRAY);
    puthz(85,190,"����������ģ�飺�Ҳ�ģ��ɵ�����ǰѡ����·���г��ٶȣ�ͣվʱ",16,16,LIGHTGRAY);
    puthz(85,210,"��ͷ������",16,16,LIGHTGRAY);
    puthz(85,240,"��վ����Ϣģ�飺�ڵ�������������վ�㣬������ʾվ�����Ϣ",16,16,LIGHTGRAY);
    puthz(75,280,"����������ģ�⣬������½�reset��ť",16,16,LIGHTGRAY);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //���ذ�ť�������
            {
                *judge = 20;
                return;
            }
        }
    }
}
/**********************************************************
Function:      DrawListbutton
Description��	������ť���
Input:   ͼ������ꣻ��ɫ
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