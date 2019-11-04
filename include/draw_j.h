#ifndef _draw_j_h
#define _draw_j_h

void DrawbuyScreen_j(setuser *person, int *judge, setuser *head, all_lines_stations *all); //购票界面
void rectangles_j(int color);
void DrawcheckScreen_j(setuser *person, int *judge, setuser *head);  //查询界面
void DrawchargeScreen_j(setuser *person, int *judge, setuser *head); //充值界面
void outputcharge_j(setuser *person, int add_money, setuser *head);  //修改、实时显示用户余额，显示delay正在充值
void click_charge_j(int color);                                      //点框框加效果
void DrawUserScreen_j(setuser *person, int *judge);                  //普通用户界面

#endif