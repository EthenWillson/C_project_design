/**********************************************************
此文件专门存放注册登录与用户数据文件交互相关的函数
作者：陈俊玮
**********************************************************/
#include"register_c.h"
#include"struct_c.h"
#include"common_c.h"
/****************************************
Function:  register_c
Description:把注册用户写入文档中（目前未设置密码确认，后期进行迭代处理）
Attention:money,spend等用数值储存的可能会有问题，最好将其改为字符串类型方便读取和存入
*****************************************/
void register_c(setManager managertemp,setuser *head)//注册函数：把注册用户写入文档中
{
    FILE *fp;
    setuser *p=head;

    //链表操作
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=(setuser*)malloc(sizeof(setuser));
    if(p->next==NULL)
    {
        printf("No memory.");
        exit(1);
    }
    p=p->next;
    strcpy(p->accounts,managertemp.accounts);
    strcpy(p->code,managertemp.code);
    strcpy(p->class,managertemp.class);
    strcpy(p->money,"00000");
    p->next=NULL;

    //文件操作
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
    fputs("00000",fp);
    fclose(fp);
}
/****************************************
Function:  turnTo_c
Description:根据传入信息跳转到其它页面
Attention:
*****************************************/
int turnTo_c(setuser *person,int direct)//跳转函数
{
    if(direct==-1)//按情况判断
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
    }
    else//直接跳转
    {
        return direct;
    }
    return -1;
}
/****************************************
Function:  login_c
Description:根据输入的用户名和密码检索根据数据文档产生的用户链表，若匹配则返回1登陆成功，不匹配则返回0登陆失败
Attention:money,spend等用数值储存的可能会有问题，最好将其改为字符串类型方便读取和存入
*****************************************/
int login_c(setManager managertemp,setuser *head,setuser *person)//登陆函数
{
    setuser *p;
    for(p=head;p!=NULL;p=p->next)
    {
        if(strcmp(managertemp.accounts,p->accounts)==0 && strcmp(managertemp.code,p->code)==0 && strcmp(managertemp.class,p->class)==0)//密码验证成功
        {
            
            strcpy(person->accounts,p->accounts);
            strcpy(person->code,p->code);
            strcpy(person->class,p->class);
            strcpy(person->money,p->money);
            person->spend=p->spend;
            return 1;//验证成功返回1
        }
        else if(strcmp(managertemp.accounts,p->accounts)==0)
        {
            return 2;//用户名重复返回2
        }
    }
    return 0;//验证失败返回0
}
/****************************************
Function:  changePass_c
Description: 修改密码函数
output: 0代表修改密码成功,1代表密码验证失败
Attention:
*****************************************/
int changePass_c(setChangePass *managerTemp,char *accounts,setuser *head)
{
    FILE *fp=NULL; //打开文件的指针
    setuser *ph;
    for(ph=head->next;ph!=NULL;ph=ph->next)
    {
        if( strcmp(ph->accounts,accounts)==0 && strcmp(ph->code,managerTemp->old)==0 )//旧的密码验证成功
        {
            strcpy(ph->code,managerTemp->new);
        }
    }
    if ((fp = fopen("data_c\\user\\usernew.txt", "wt")) == NULL)//以写的方式新建一个文件
    {
        closegraph();
        printf("Can't open usernew.txt");
    }
    for(ph=head->next;ph!=NULL;ph=ph->next)
    {
        fputc('@',fp);//@标志一个用户的开头
        fputs(ph->accounts,fp);
        fputc('*',fp);//*标志用户密码的开头
        fputs(ph->code,fp);
        fputc('#',fp);//#标志用户的权限码
        fputs(ph->class,fp);
        fputc('$',fp);//$标志用户余额
        fputs(ph->money,fp);
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt","data_c\\user\\userinf.txt");
    return 0;
}
/****************************************
Function:  createuserlist_c
Description:根据数据文件中存储的用户信息创建链表
Attention:文件必须按要求格式化书写;
            一定要把指针的地址传过来
            money,spend等用数值储存的可能会有问题，最好将其改为字符串类型方便读取和存入
*****************************************/
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
	    //exit(1);
    }
    while(!feof(fp))//文件读取，如果遇到文件结束返回值是1，否则为0
	{
		cha=fgetc(fp);//读取一个字符
		
		if(cha=='@')//@默认为账户名的开始
		{
            if((now->next=(setuser*)malloc(sizeof(setuser)))==NULL)//开辟一个新的结点
			{
				closegraph();
				printf("\n OUT OF MEMORY!");
		        // getchar();
		        //exit(1);
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
            p=now->money;
            // fprintf(fp,"%d",now->money);     
        }
	    else if(cha!=' '&&cha!='\n')       //将对应的账户串或密码串装入链表中
        {
	        *p=cha;
            p++;
        }
        else if(cha==' '&&cha=='\n')
        {
            *p='\0';  
        }
    }
    now->next=NULL;
    // closegraph();
    // printf("%s\n%s\n%s\n\n",now->accounts,now->code,now->class);
}
/****************************************
Function:  freeuserlist_c
Description:释放链表的内存空间并将头指针置为NULL
Attention:文件必须按要求格式化书写;
            一定要把指针的地址传过来
*****************************************/
void freeuserlist_c(setuser **head)
{
   setuser *per= *head;
   setuser *cur=(*head)->next;
    if(*head==NULL)
        return ;
    while(cur!=NULL)
    {
        free(per);
        per=cur;
        cur=cur->next;
    }
	free(per);
	*head=NULL;
}