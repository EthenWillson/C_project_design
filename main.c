#include "common_c.h"
#include "personal.h"
void main()
{
	int judge = 1;		  //�ж�Ӧ�õ�����Щ�����ı���
	setuser person;		  //��ʾ��ǰ�û��ı���
	setuser *head = NULL; //�û������ͷ�ڵ�
	int temp;			  //�������ռ��̻������ı���
	int buttons, mx, my;  //�����ر���
	int driver = VGA;
	int mode = VGAHI;
	all_lines_stations all;
	setTrainInfo Info[3]; //��¼�����ߵ��ȵ���ز���

	person.accounts[0] = '\0'; //��ʼ��
	person.code[0] = '\0';	 //��ʼ��

	initgraph(&driver, &mode, "..\\BORLANDC\\bgi");
	cleardevice();
	if ((head = (setuser *)malloc(sizeof(setuser))) == NULL)
	{
		closegraph();
		printf("\nout of memory");
		getch();
		return;
	}
	createuserlist_c(head); //�����û������ǵ�Ҫ�ͷ�

	station_information_j(&all);
	initTranInfo(Info, &all);

	judge = 1;
	while (1)
	{
		/*����judge��ֵ�ж���Ҫ���ý�������̨����*/
		switch (judge)
		{
		case 0:					   //�˳�����
			freeuserlist_c(&head); //�ͷ��û�����
			closegraph();
			return;
		case 1: //��¼
			Drawloginscreen_c(&person, &judge, head);
			break;
		case 2: //���ȹ���Ա��������
			DrawControlSystem_c(&person, &judge);
			break;
		case 3: //��ͨ�û�
			DrawUserScreen_j(&person, &judge);
			break;
		case 4: //��������
			PersonalCenter_c(&person, &judge);
			break;
		case 5:	//��Ʊ����
			DrawbuyScreen_j(&person, &judge, head, &all); //����ط��ٴ�һ��������Ȼ���ᱨ��
			break;
		case 6: //�˻���ѯ
			DrawcheckScreen_j(&person, &judge);
			break;
		case 7: //��ֵ
			DrawchargeScreen_j(&person, &judge, head);
			break;
		case 8: //Ʊ��˵��
			DrawpriceScreen_j(&person, &judge);
			break;
		case 9: //��Ʊ��¼
			DrawrecordScreen_j(&person, &judge);
			break;
		case 10: //�����̳�
			DrawscoreScreen_j(&person, &judge);
			break;
		case 11: //���Ƚ���
			drawControlScreen(&person, &judge, &all, Info);
			//drawControlScreen(setuser *person,int *judge,all_lines_stations *all,setTrainInfo *Info)
			break;
		case 12: //��������
			Draw_about_us_Screen_j(&judge);
			break;
		case 13: //��Ӫ����Ա����
			Draw_run_Screen_j(&person, &judge);
			break;
		case 14: //�޸�����
			changePasswordScreen_c(&person, &judge, head);
			break;
		case 15://�û���ѯ
			run_check_Screen_j(&person, &judge, head);
			break;
		case 16://Ȩ�޹���
			run_power_Screen_j(&person, &judge);
			break;
		case 17://����Ȩ��
		    change_power_Screen_j(&person,&judge,head);
			break;
		case 18://ɾ���û�
		    delete_user_Screen_j(&person,&judge,head);
			break;
		case 20: //��������
			DrawhelpScreen_c(&judge);
			break;
		case 21: //��½��������
			DrawLoginHelp(&judge);
			break;
		case 22: //��Ʊ��������
			DrawBuyHelp(&judge);
			break;
		case 23://��¼��������
			DrawRecordHelp(&judge);
			break;
		case 24://���Ȱ�������
			DrawManageHelp(&judge);
			break;
		case 25://��Ʒ�һ�����
			DrawStoreScreen(&person,&judge,head);
			break;
		case 26://�ҵĶһ�����
			DrawMyChangeScreen(&person,&judge);
			break;
		case 27://��Ӫ����Աʹ�ð�������
			DrawRunHelp(&judge);
			break;
		}
	}
}