#ifndef _run_j_h
#define _run_j_h

void DrawLine_j(int x1, int y1, int x2, int y2, int x3, int y3, int color);
void DrawStar_j();
void Draw_run_Screen_j(setuser *person, int *judge, setuser *head);
void run_check_Screen_j(setuser *person, int *judge, setuser *head);
void run_power_Screen_j(setuser *person, int *judge, setuser *head);
void Draw_poly1_j();                         //更改权限
void Draw_poly2_j();                         //删除用户
void Draw_frame1_j(int x, int y, int color); //更改权限操作框
void Draw_frame2_j(int x, int y, int color); //删除用户操作框
void change_power_Screen_j(setuser *person, int *judge, setuser *head);
void delete_user_Screen_j(setuser *person, int *judge, setuser *head);

#endif