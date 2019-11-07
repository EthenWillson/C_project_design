#ifndef _user_h
#define _user_h
#include"struct_c.h"
void changemoney_j(int n, setuser *person, int radix, setuser *head);
void changescore_j(int n, setuser *person, setuser *head);
void changerecord_j(setuser *person, setuser *head, int start_name, int end_name, int price);
void change_class_j(setuser *person, setuser *head, int sign1, int sign2);
void delete_user_j(setuser *p, setuser *head);
void DrawrecordScreen_j(setuser *person, int *judge);

#endif