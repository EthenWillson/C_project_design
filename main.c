#include"common_c.h"
void main()
{
	int key=0;
    int judge = 1;    //判断应该调用那些函数的变量
	setuser person;    //表示当前用户的变量
	setuser *head = NULL;    //用户链表的头节点
	int temp;//用于吸收键盘缓冲区的变量
    int buttons,mx,my;//鼠标相关变量
	int driver = VGA;
	int mode = VGAHI;
	person.accounts[0] = '\0';//初始化
	person.code[0] = '\0';//初始化
	//person.Routes=NULL;
	//person.size=0;
	
	initgraph(&driver, &mode, "../BORLANDC\\bgi");  
	cleardevice();
	
	if ((head = (setuser *)malloc(sizeof(setuser))) == NULL)
	{
	    closegraph();
		printf("\nout of memory");
		return ;
	}
	//createuserlist(head);//创建用户链表，记得要释放
	while (1)
	{
		/*根据judge的值判断需要调用界面和其后台函数*/
		switch (judge)
		{
		case 1: //登录
		    //Drawdetail_fj();
			Drawloginscreen();
			// judge = personlogin(head, person.accounts, person.code);
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