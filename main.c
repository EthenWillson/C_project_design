#include"common_c.h"
#include"personal.h"
void main()
{
	//int key=0;
    int judge = 1;    //判断应该调用那些函数的变量
	setuser person;    //表示当前用户的变量
	setuser *head = NULL;    //用户链表的头节点
	int temp;//用于吸收键盘缓冲区的变量
    int buttons,mx,my;//鼠标相关变量
	int driver = VGA;
	int mode = VGAHI;
	all_lines_stations all;
	setTrainInfo Info[3];//记录三条线调度的相关参数
	
	//char *p=NULL;
	//setuser *pt = NULL;
	person.accounts[0] = '\0';//初始化
	person.code[0] = '\0';//初始化
	//person.Routes=NULL;
	//person.size=0;

	
	

	// clock();
	initgraph(&driver, &mode, "../BORLANDC\\bgi");  
	cleardevice();
	if ((head = (setuser *)malloc(sizeof(setuser))) == NULL)
	{
		closegraph();
		printf("\nout of memory");
		getch();
		return ;
	}
	createuserlist_c(head);//创建用户链表，记得要释放
	
	station_information_j(&all);
	initTranInfo(Info,&all);

	// closegraph();
	// printf("%d %d\n",Info[0].trainHead->x,Info[0].rtrainHead->y);
	// getch();

	judge=11;
	while (5)
	{
		/*根据judge的值判断需要调用界面和其后台函数*/
		switch (judge)
		{
		case 0://退出程序
			freeuserlist_c(&head);//释放用户链表
			closegraph();
		 	//free(person.Routes);
			return;
		case 1: //登录
			Drawloginscreen_c(&person,&judge,head);
			break;
			
		case 2: //调度管理员调度中心	
			DrawControlSystem_c(&person,&judge);
			break;
		case 3: //普通用户	
			DrawUserScreen_j(&person,&judge);
			break;
		case 4://个人中心
			// DrawPersonalCenter_c(&person,&judge,head);
			// DrawPersonalCenter_c(&person,&judge);
			PersonalCenter_c(&person,&judge,head);
			break;
		case 5://购票界面
			DrawbuyScreen_j(&person,&judge,head,&all);//这个地方少传一个参数竟然不会报错！
			break;
		case 6://账户查询
			DrawcheckScreen_j(&person,&judge,head);
			break;
		case 7://充值
			DrawchargeScreen_j(&person,&judge,head);
			break;
		case 8:
		    //closegraph();
			//getch();
		    DrawpriceScreen_j(&person,&judge); 
			break;
		case 9:
		    DrawrecordScreen_j(&person,&judge,&all);
			break;
		case 10:
		    DrawscoreScreen_j(&person,&judge,head);	
            break;
		case 11://调度界面 
			drawControlScreen(&person,&judge,head,&all,&Info);
			break;
		case 12:
		    Draw_about_us_j(&judge);
			break;
		// case 2: //注册	
		// 	Drawregisterscreen();
		// 	judge = personregister(head, person.accounts, person.code);
		// 	break;
			
		// case 3: //用户登录后
		//     Drawjiazaitiao();
        //     Drawuserscreen();
        //     judge = usermain(&person);
		// 	//将person的信息存入链表
		// 	saveinftolist(head,&person);
			
		// 	person.accounts[0] = '\0';
	    //     person.code[0] = '\0';
		// 	break;
			
		// case 4://管理员登录后
		//     //Drawmanagerscreen();
		// 	//judge=manager();
		// 	manage();
		// 	judge=1;
		// 	break;
			
		// case 5://退出程序
		// 	freeuserlist(&head);//释放用户链表
		// 	 //free(person.Routes);
		// 	return ;
			
		}
	}
}