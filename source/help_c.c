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
            DrawListbutton(210, 320, LIGHTBLUE,LIGHTBLUE,"��Ӫ�ӵ���");
            mouseover[3]=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 200 && mx <= 440 && my >= 330 && my <= 360 )&& mouseover[3]==1) //����Ƴ�����ť
        {
            mousehide(mx,my);
            setcolor(WHITE);
            setfillstyle(1,WHITE);
            bar(190,300,500,370);
            DrawListbutton(200, 330, LIGHTGRAY,LIGHTGRAY,"��Ӫ�ӵ���");
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
    puthz(70,90,"����½��",16,16,LIGHTGRAY);
    puthz(80,120,"���û���½�������Ѿ�ע�������ͨ�û���������Ͻ��û���ť����",16,16,LIGHTGRAY);
    puthz(80,140,"�����������û��������룬������¼��ť����ϵͳ��",16,16,LIGHTGRAY);
    puthz(80,170,"������Ա��½�������Ѿ�ע����Ĺ���Ա��������Ͻǹ���Ա��ť��",16,16,LIGHTGRAY);
    puthz(80,190,"�ڿ����������û��������뼰Ȩ���룬������¼��ť����ϵͳ��",16,16,LIGHTGRAY);
    puthz(70,230,"��ע�᣺",16,16,LIGHTGRAY);
    puthz(80,260,"���û�ע�᣺�������û���������Ͻ��û���ť���ڿ�����������Ҫ",16,16,LIGHTGRAY);
    puthz(80,280,"�������û��������룬�����Զ�ע�ᰴť����ע���˻�������ϵͳ��",16,16,LIGHTGRAY);
    puthz(80,310,"������Աע�᣺�����¹���Ա��������Ͻǹ���Ա��ť���ڿ�������",16,16,LIGHTGRAY);
    puthz(80,330,"����Ҫ�������û��������룬��Ϊ���ȹ���ԱȨ������дcjwzs��",16,16,LIGHTGRAY);
    puthz(80,350,"��Ϊ��ӪȨ������дjmxs�������Զ�ע�ᰴť����ע���˻�����",16,16,LIGHTGRAY);
    puthz(80,370,"��ϵͳ��",16,16,LIGHTGRAY);
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
    puthz(80,180,"������Ա��ֵ�����ȹ���Ա�����������Ͻ�ͷ��ͼ�꣬�������Ա��",16,16,LIGHTGRAY);
    puthz(80,200,"�����ģ�����˻���ֵ����Ӫ����Ա�����ҳ��â���˻���ֵѡ�",16,16,LIGHTGRAY);
    puthz(70,240,"����Ʊ��",16,16,LIGHTGRAY);
    puthz(80,270,"���û���Ʊ�����û�����������Ʊѡ����빺Ʊ���棬ѡ�����",16,16,LIGHTGRAY);
    puthz(80,290,"���յ�󣬵����Ʊ",16,16,LIGHTGRAY);
    puthz(80,320,"������Ա��Ʊ���ڹ���Ա��������̫���²࣬���빺Ʊ���棻��Ӫ",16,16,LIGHTGRAY);
    puthz(80,340,"����Ա�����â�ǹ�Ʊѡ��",16,16,LIGHTGRAY);
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
    puthz(80,180,"������Ա�����ȹ���Ա�����������Ͻ�ͷ��ͼ�꣬�������Ա����",16,16,LIGHTGRAY);
    puthz(80,200,"���ģ�����˻���ѯ����Ӫ����Ա�����â���޸�����ѡ��",16,16,LIGHTGRAY);
    puthz(70,240,"�����м�¼��",16,16,LIGHTGRAY);
    puthz(80,270,"���û������û����������˻���ѯѡ������˻���ѯ���棬ѡ��",16,16,LIGHTGRAY);
    puthz(80,290,"��Ʊ��¼ѡ��ɲ鿴��ʷ��Ʊ��¼",16,16,LIGHTGRAY);
    puthz(80,320,"������Ա���ڵ��ȹ���Ա�������ĵ���˻���ѯѡ���Ӫ����Ա��",16,16,LIGHTGRAY);
    puthz(80,340,"����â���˻���ѯѡ���������ͬ�û�",16,16,LIGHTGRAY);
    
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
    int mouseover=0;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//���ذ�ť
    puthz(298,40,"����",32,32,CYAN);
    puthz(65,100,"�����ȣ�",16,16,LIGHTGRAY);
    puthz(75,130,"��������ȹ���Ա�����棬���̫���ϲ࣬������Ƚ��棬��������",16,16,LIGHTGRAY);
    puthz(85,150,"ģ�飺",16,16,LIGHTGRAY);
    puthz(85,180,"����·ѡ��ģ�飺���Ͻǿ�ѡ����Ƶ���·",16,16,LIGHTGRAY);
    puthz(85,210,"����������ģ�飺�Ҳ�ģ��ɵ�����ǰѡ����·���г��ٶȣ�ͣվʱ",16,16,LIGHTGRAY);
    puthz(85,240,"��ͷ������",16,16,LIGHTGRAY);
    puthz(85,270,"��վ����Ϣģ�飺�ڵ�������������վ�㣬������ʾվ�����Ϣ",16,16,LIGHTGRAY);
    puthz(75,300,"����������ģ�⣬������½�reset��ť",16,16,LIGHTGRAY);
    returnBtn_next_c(420,70,CYAN);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (mx >= 350 && mx <= 450 && my >= 40 && my <= 70 && mouseover==0) 
        {
            mousehide(mx,my);
            returnBtn_next_c(420,70,LIGHTBLUE);
            mouseover=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 350 && mx <= 450 && my >= 40 && my <= 70) && mouseover==1) 
        {
            mousehide(mx,my);
            returnBtn_next_c(420,70,CYAN);
            mouseover=0;
            getMousebk(mx,my);
        }
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //���ذ�ť�������
            {
                *judge = 20;
                return;
            }
            if (mx >= 350 && mx <= 450 && my >= 40 && my <= 70) //��һ���Ӫ��������
            {
                *judge = 27;
                return;
            }
        }
    }
}
/**********************************************************
Function:      DrawRunHelp
Description��	��������ӵ��Ȱ������� ����27
Input:   ͼ������ꣻ��ɫ
**********************************************************/
void DrawRunHelp(int *judge)
{
    int buttons, mx, my;         //�����ر���
    int mouseover=0;
    mouseInit(&mx, &my, &buttons);
    cleardevice();
    setbkcolor(WHITE);
    DrawBeautifulFrame_c();
    returnBtn_c(290, 400, CYAN);//���ذ�ť
    puthz(298,40,"��Ӫ",32,32,CYAN);
    puthz(65,100,"����Ӫ��",16,16,LIGHTGRAY);
    puthz(75,130,"��������Ӫ����Ա�����棬��â������ѡ���ϣ�����������Ӫģ�飺",16,16,LIGHTGRAY);
    puthz(85,160,"���û���ѯģ�飺���Բ�ѯ��ע���û��ĸ�����Ϣ",16,16,LIGHTGRAY);
    puthz(85,190,"��Ȩ�޹���ģ�飺�����޸��û���Ȩ�ޣ�ɾ���û�",16,16,LIGHTGRAY);
    // puthz(85,210,"��ͷ������",16,16,LIGHTGRAY);
    // puthz(85,240,"��վ����Ϣģ�飺�ڵ�������������վ�㣬������ʾվ�����Ϣ",16,16,LIGHTGRAY);
    // puthz(75,280,"����������ģ�⣬������½�reset��ť",16,16,LIGHTGRAY);
    returnBtn_small_c(240,40,CYAN);
    while (1)
    {
        newxy(&mx, &my, &buttons);
        if (mx >= 250 && mx <= 280 && my >= 30 && my <= 80 && mouseover==0) 
        {
            mousehide(mx,my);
            returnBtn_small_c(240,40,LIGHTBLUE);
            mouseover=1;
            getMousebk(mx,my);
        }
        if (!(mx >= 250 && mx <= 280 && my >= 30 && my <= 80) && mouseover==1) 
        {
            mousehide(mx,my);
            returnBtn_small_c(240,40,CYAN);
            mouseover=0;
            getMousebk(mx,my);
        }
        if(buttons)
        {
            if (mx >= 290 && mx <= 360 && my >= 400 && my <= 460) //���ذ�ť�������
            {
                *judge = 20;
                return;
            }
            if (mx >= 250 && mx <= 280 && my >= 30 && my <= 80) //��һ��������
            {
                *judge = 24;
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