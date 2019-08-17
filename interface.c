#include"interface.h"
// int add(int a,int b)
// {
//     return a+b;
// }
#include"common_c.h"
/**********************************************************
Function:  Drawplane
Description：	画飞机函数函数
Attention:  必须要用GB2312编码保存，不然汉字会有乱码
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
void Drawloginscreen()
{
	int temp;//用于吸收键盘缓冲区的变量
    int buttons,mx,my;//鼠标相关变量
	mouseInit(&mx, &my, &buttons);  //鼠标初始化

    cleardevice();
	setbkcolor(WHITE);
	Drawplane();	
	setfillstyle(1, DARKGRAY);
	bar(400,50,500 ,82 );
	bar(400,82,600,400);
	setfillstyle(1,LIGHTGRAY);
	bar(500,50,600,82);
	
	
	setfillstyle(1,WHITE);
	bar(410,130,590,160);//输入框1账号
	bar(410,200,590,230);//输入框2密码
	bar(410,235,490,265);//验证码
	bar(510,235,590,265);//验证码输入
	setfillstyle(1,CYAN);//青色
	bar(410,270,590,290);//登录框
	bar(410,310,590,330);//注册框
	
	puthz(430, 55, "用户名", 16, 16, WHITE);
	puthz(515,55,"管理员",16,16,WHITE);
	puthz(410, 105, "账号", 16, 16, WHITE);
	puthz(410, 175, "密码", 16, 16, WHITE);
	puthz(485, 270, "登录", 16, 16, WHITE);
	puthz(485, 310, "注册", 16, 16, WHITE);
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
	
	//setlinestyle(0, 0, 1);
	//setcolor(LIGHTRED);
	//rectangle(398,433,465,453);关于我们的位置
	//rectangle(538,433,571,453);帮助的位置
	
	
	while(1)
	{
		newxy(&mx, &my, &buttons);
		if (mx >= 585 && mx <= 615 && my >= 5&& my <= 45 && buttons)//退出按钮点击退出
        {
            exit(1);
        }
	}
}	