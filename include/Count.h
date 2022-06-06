 #ifndef _COUNT_H
#define _COUNT_H
#include "sqlite3.h"
#include <cmath>
#include "readsql.h"
using namespace std;

namespace count{

float force_to_roll(sqlite3*,onestrip&);
float force_to_roll(sqlite3*,onestrip&,float force);

float size_to_temp(sqlite3*,onestrip&);  ///这是累加的吗
float size_to_force(sqlite3*,onestrip&);  //这是累加的吗

float speed_to_temp(sqlite3*,onestrip&);
float speed_to_force(sqlite3*,onestrip&);


float water_to_temp(sqlite3*,onestrip&);
float water_to_force(sqlite3*,onestrip&);

float temp_to_force(sqlite3*,onestrip&);
float temp_to_force(sqlite3* sql,onestrip& current_strip,float temp);

float temp_to_thick(sqlite3*,onestrip&);    ///从数据库来
float temp_to_thick(float force_of_temp,onestrip&);   /////从温度开始引起的扎制力开始分析

float heredity(sqlite3*,onestrip&);
}

#endif