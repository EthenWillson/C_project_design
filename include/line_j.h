#ifndef _line_j_h
#define _line_j_h
#include "struct_c.h"
void Initstation_j(station *sta, int x, int y, char *station_name, int code, float dx, float dy, float dz, int level);
void station_information_j(all_lines_stations *all);
void DrawCircles_j(void);
void Drawstation1_j(void);
void Drawstation2_j(void);
void Drawstation4_j(void);
void Draw_start_sta_j(int x, int y, station *sta, int *sta_checkclick, int *start_station, int *flag);
void Draw_end_sta_j(all_lines_stations *all, int x, int y, station sta, int *sta_checkclick, int *start_station, int *end_station, int *flag, int *price);
float cal_distance_j(all_lines_stations *all, int *start_name, int *end_name);
int cal_price_j(float distance);
void transform1(float num, char *str);
void transform2(float num, char *str);
#endif