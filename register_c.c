/**********************************************************
此文件专门存放注册登录相关的函数
作者：陈俊玮
**********************************************************/
#include"register_c.h"
#include"struct_c.h"
#include"common_c.h"
void register_c(setManager managertemp)//注册函数：把注册用户写入文档中
{
    FILE *fp;
    if((fp=fopen("data_c\\user\\userinf.txt","rt"))==NULL)
    {
        fp=fopen("data_c\\user\\userinf.txt","wt+");
    }
    fp=fopen("data_c\\user\\userinf.txt","at+");
    fputc('@',fp);//@标志一个用户的开头
    fputs(managertemp.accounts,fp);
    fputc('*',fp);//*标志用户密码的开头
    fputs(managertemp.code,fp);
    fputc('#',fp);//#标志用户的权限码
    fputs(managertemp.class,fp);
    fputc('$',fp);//$标志用户余额
    fclose(fp);
}
int turnTo_c(setuser *person)//跳转函数
{
    if(strcmp(person->class,"cjwzs")==0)//权限码为cjwzs（陈俊玮最帅）的人员将进入调度系统
    {
        return 2;
    }
    else if(strcmp(person->class,"00000")==0)//普通用户权限码00000，进入普通用户界面
    {
        return 3;
    }
    else if(strcmp(person->class,"cjwzs")!=0 && strcmp(person->class,"00000")!=0)//权限码有误
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// void login_c(setManager managertemp)//登入函数
// {

// }
void createuserlist_c(setuser *head)//创建用户链表
{
    FILE *fp=NULL; //打开文件的指针
	setuser *now=NULL;
	char cha;    //用于接收并传送文件内部字符的中间变量
    char *p=NULL;   //指向需要接收字符的地址的指针变量

	
	now=head;//now指向表头
	p=head->accounts;
    if ((fp = fopen("data_c\\user\\userinf.txt", "r+")) == NULL)//以读写的方式打开
    {
	    closegraph();
	    printf("Can't open userinf.txt");
	    //getchar();
	    exit(1);
    }
    while(!feof(fp))//文件读取，如果遇到文件结束返回值是1，否则为0
	{
		cha=fgetc(fp);//读取一个字符
		
		if(cha=='@')//@默认为账户名的开始
		{
	        if((now->next=(setuser*)malloc(sizeof(setuser)))==NULL)
			{
				closegraph();
				printf("\n OUT OF MEMORY!");
		       // getchar();
		        exit(1);
		    }
            now=now->next;

	        *p='\0';
	        p=now->accounts;
	    }
	    else if(cha=='*')      //表示账户串的结束，密码串的开始
	    {
	        *p='\0';           
	        p=now->code;
	    }
        else if(cha=='#')      //表示密码串的结束，权限码的开始
	    {
	        *p='\0';           
	        p=now->class;
	    }
        else if(cha=='$')      //表示权限码的结束，金额的开始//数字如何
	    {
	        *p='\0';   
            fprintf(fp,"%d",now->money);     
	    }
	    else if(cha!=' '&&cha!='\n')       //将对应的账户串或密码串装入链表中
	    {
	        *p=cha;
	        p++;
	    }
    }
}