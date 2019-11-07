#include "common_c.h"
#include "personal.h"
void main()
{
	int judge = 1;		  //判断应该调用那些函数的变量
	setuser person;		  //表示当前用户的变量
	setuser *head = NULL; //用户链表的头节点
	int temp;			  //用于吸收键盘缓冲区的变量
	int buttons, mx, my;  //鼠标相关变量
	int driver = VGA;
	int mode = VGAHI;
	all_lines_stations all;
	setTrainInfo Info[3]; //记录三条线调度的相关参数

	person.accounts[0] = '\0'; //初始化
	person.code[0] = '\0';	 //初始化

	initgraph(&driver, &mode, "..\\BORLANDC\\bgi");
	cleardevice();
	if ((head = (setuser *)malloc(sizeof(setuser))) == NULL)
	{
		closegraph();
		printf("\nout of memory");
		getch();
		return;
	}
	createuserlist_c(head); //创建用户链表，记得要释放

	station_information_j(&all);
	initTranInfo(Info, &all);

	judge = 1;
	while (1)
	{
		/*根据judge的值判断需要调用界面和其后台函数*/
		switch (judge)
		{
		case 0:					   //退出程序
			freeuserlist_c(&head); //释放用户链表
			closegraph();
			return;
		case 1: //登录
			Drawloginscreen_c(&person, &judge, head);
			break;
		case 2: //调度管理员调度中心
			DrawControlSystem_c(&person, &judge);
			break;
		case 3: //普通用户
			DrawUserScreen_j(&person, &judge);
			break;
		case 4: //个人中心
			PersonalCenter_c(&person, &judge);
			break;
		case 5:	//购票界面
			DrawbuyScreen_j(&person, &judge, head, &all); //这个地方少传一个参数竟然不会报错！
			break;
		case 6: //账户查询
			DrawcheckScreen_j(&person, &judge);
			break;
		case 7: //充值
			DrawchargeScreen_j(&person, &judge, head);
			break;
		case 8: //票价说明
			DrawpriceScreen_j(&person, &judge);
			break;
		case 9: //购票记录
			DrawrecordScreen_j(&person, &judge);
			break;
		case 10: //积分商城
			DrawscoreScreen_j(&person, &judge);
			break;
		case 11: //调度界面
			drawControlScreen(&person, &judge, &all, Info);
			//drawControlScreen(setuser *person,int *judge,all_lines_stations *all,setTrainInfo *Info)
			break;
		case 12: //关于我们
			Draw_about_us_Screen_j(&judge);
			break;
		case 13: //运营管理员界面
			Draw_run_Screen_j(&person, &judge);
			break;
		case 14: //修改密码
			changePasswordScreen_c(&person, &judge, head);
			break;
		case 15://用户查询
			run_check_Screen_j(&person, &judge, head);
			break;
		case 16://权限管理
			run_power_Screen_j(&person, &judge);
			break;
		case 17://更改权限
		    change_power_Screen_j(&person,&judge,head);
			break;
		case 18://删除用户
		    delete_user_Screen_j(&person,&judge,head);
			break;
		case 20: //帮助界面
			DrawhelpScreen_c(&judge);
			break;
		case 21: //登陆帮助界面
			DrawLoginHelp(&judge);
			break;
		case 22: //购票帮助界面
			DrawBuyHelp(&judge);
			break;
		case 23://记录帮助界面
			DrawRecordHelp(&judge);
			break;
		case 24://调度帮助界面
			DrawManageHelp(&judge);
			break;
		case 25://商品兑换界面
			DrawStoreScreen(&person,&judge,head);
			break;
		case 26://我的兑换界面
			DrawMyChangeScreen(&person,&judge);
			break;
		case 27://运营管理员使用帮助界面
			DrawRunHelp(&judge);
			break;
		}
	}
}