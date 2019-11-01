/**********************************************************
���ļ�ר�Ŵ��ע���¼���û������ļ�������صĺ���
���ߣ��¿���
**********************************************************/
#include"register_c.h"
#include"struct_c.h"
#include"common_c.h"
/****************************************
Function:  register_c
Description:��ע���û�д���ĵ��У�Ŀǰδ��������ȷ�ϣ����ڽ��е�������
Attention:money,spend������ֵ����Ŀ��ܻ������⣬��ý����Ϊ�ַ������ͷ����ȡ�ʹ���
*****************************************/
void register_c(setManager managertemp,setuser *head)//ע�ắ������ע���û�д���ĵ���
{
    FILE *fp;
    setuser *p=head;

    //�������
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
    strcpy(p->money,"0");
    strcpy(p->score,"0");
    p->record[0]='\0';
    p->next=NULL;

    //�ļ�����
    if((fp=fopen("data_c\\user\\userinf.txt","rt"))==NULL)
    {
        fp=fopen("data_c\\user\\userinf.txt","wt+");
    }
    fp=fopen("data_c\\user\\userinf.txt","at+");
    fputc('@',fp);//@��־һ���û��Ŀ�ͷ
    fputs(managertemp.accounts,fp);
    fputc('*',fp);//*��־�û�����Ŀ�ͷ
    fputs(managertemp.code,fp);
    fputc('#',fp);//#��־�û���Ȩ����
    fputs(managertemp.class,fp);
    fputc('$',fp);//$��־�û����
    fputs("00000",fp);
    fputc('(',fp);//(��־�û�����
    fputs("00000",fp);
    fclose(fp);
}
/****************************************
Function:  turnTo_c
Description:���ݴ�����Ϣ��ת������ҳ��
Attention:
*****************************************/
int turnTo_c(setuser *person,int direct)//��ת����
{
    if(direct==-1)//������ж�
    {
        if(strcmp(person->class,"cjwzs")==0)//Ȩ����Ϊcjwzs���¿�����˧������Ա���������ϵͳ
        {
            return 2;
        }
        else if(strcmp(person->class,"jmxzs")==0)
        {
            return 13;
        }
        else if(strcmp(person->class,"00000")==0)//��ͨ�û�Ȩ����00000��������ͨ�û�����
        {
            return 3;
        }
        else if(strcmp(person->class,"cjwzs")!=0 && strcmp(person->class,"00000")!=0)//Ȩ��������
        {
            return 1;
        }
    }
    else//ֱ����ת
    {
        return direct;
    }
    return -1;
}
/****************************************
Function:  login_c
Description:����������û���������������������ĵ��������û�������ƥ���򷵻�1��½�ɹ�����ƥ���򷵻�0��½ʧ��
Attention:money,spend������ֵ����Ŀ��ܻ������⣬��ý����Ϊ�ַ������ͷ����ȡ�ʹ���
*****************************************/
int login_c(setManager managertemp,setuser *head,setuser *person)//��½����
{
    setuser *p;
    for(p=head;p!=NULL;p=p->next)
    {
        if(strcmp(managertemp.accounts,p->accounts)==0 && strcmp(managertemp.code,p->code)==0 && strcmp(managertemp.class,p->class)==0)//������֤�ɹ�
        {
            
            strcpy(person->accounts,p->accounts);
            strcpy(person->code,p->code);
            strcpy(person->class,p->class);
            strcpy(person->money,p->money);
            strcpy(person->score,p->score);
            strcpy(person->record,p->record);
            return 1;//��֤�ɹ�����1
        }
        else if(strcmp(managertemp.accounts,p->accounts)==0)
        {
            return 2;//�û����ظ�����2
        }
    }
    return 0;//��֤ʧ�ܷ���0
}
/****************************************
Function:  changePass_c
Description: �޸����뺯��
output: 0�����޸�����ɹ�,1����������֤ʧ��
Attention:
*****************************************/
int changePass_c(setChangePass *managerTemp,char *accounts,setuser *head)
{
    FILE *fp=NULL; //���ļ���ָ��
    setuser *ph;
    for(ph=head->next;ph!=NULL;ph=ph->next)
    {
        if( strcmp(ph->accounts,accounts)==0 && strcmp(ph->code,managerTemp->old)==0 )//�ɵ�������֤�ɹ�
        {
            strcpy(ph->code,managerTemp->new);
        }
    }
    if ((fp = fopen("data_c\\user\\usernew.txt", "wt")) == NULL)//��д�ķ�ʽ�½�һ���ļ�
    {
        closegraph();
        printf("Can't open usernew.txt");
    }
    for(ph=head->next;ph!=NULL;ph=ph->next)
    {
        fputc('@',fp);//@��־һ���û��Ŀ�ͷ
        fputs(ph->accounts,fp);
        fputc('*',fp);//*��־�û�����Ŀ�ͷ
        fputs(ph->code,fp);
        fputc('#',fp);//#��־�û���Ȩ����
        fputs(ph->class,fp);
        fputc('$',fp);//$��־�û����
        fputs(ph->money,fp);
        fputc('(',fp);//(��־�û�����
        fputs(ph->score,fp);
        fputc('^',fp);//��־���м�¼�Ŀ�ͷ
        fputs(ph->record,fp);
        fputc('&',fp);//������
    }
    fclose(fp);
    remove("data_c\\user\\userinf.txt");
    rename("data_c\\user\\usernew.txt","data_c\\user\\userinf.txt");
    return 0;
}
/****************************************
Function:  createuserlist_c
Description:���������ļ��д洢���û���Ϣ��������
Attention:�ļ����밴Ҫ���ʽ����д;
            һ��Ҫ��ָ��ĵ�ַ������
            money,spend������ֵ����Ŀ��ܻ������⣬��ý����Ϊ�ַ������ͷ����ȡ�ʹ���
*****************************************/
void createuserlist_c(setuser *head)//�����û�����
{
    FILE *fp=NULL; //���ļ���ָ��
	setuser *now=NULL;
	char cha;    //���ڽ��ղ������ļ��ڲ��ַ����м����
    char *p=NULL;   //ָ����Ҫ�����ַ��ĵ�ַ��ָ�����

	
	now=head;//nowָ���ͷ
	p=head->accounts;
    if ((fp = fopen("data_c\\user\\userinf.txt", "r+")) == NULL)//�Զ�д�ķ�ʽ��
    {
        closegraph();
        printf("Can't open userinf.txt");
	    //getchar();
	    //exit(1);
    }
    while(!feof(fp))//�ļ���ȡ����������ļ���������ֵ��1������Ϊ0
	{
		cha=fgetc(fp);//��ȡһ���ַ�
		
		if(cha=='@')//@Ĭ��Ϊ�˻����Ŀ�ʼ
		{
            if((now->next=(setuser*)malloc(sizeof(setuser)))==NULL)//����һ���µĽ��
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
	    else if(cha=='*')      //��ʾ�˻����Ľ��������봮�Ŀ�ʼ
        {
	        *p='\0';           
            p=now->code;
        }
        else if(cha=='#')      //��ʾ���봮�Ľ�����Ȩ����Ŀ�ʼ
        {
	        *p='\0';           
            p=now->class;
        }
        else if(cha=='$')      //��ʾȨ����Ľ��������Ŀ�ʼ//�������
        {
	        *p='\0';   
            p=now->money;
            // fprintf(fp,"%d",now->money);     
        }
        else if(cha=='(')
        {
            *p='\0';
            p=now->score;
        }
        else if(cha=='^') 
        {     //��ʾ���Ľ��������м�¼�Ŀ�ʼ
	        *p='\0';   
            p=now->record;
            // fprintf(fp,"%d",now->money);     
        }
       
	    else if(cha!=' '&&cha!='\n')       //����Ӧ���˻��������봮װ��������
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
Description:�ͷ�������ڴ�ռ䲢��ͷָ����ΪNULL
Attention:�ļ����밴Ҫ���ʽ����д;
            һ��Ҫ��ָ��ĵ�ַ������
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