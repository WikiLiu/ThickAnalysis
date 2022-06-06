#include "Count.h"

float count::force_to_roll(sqlite3* sql,onestrip& current_strip){
    ////getdata

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}

float count::force_to_roll(sqlite3* sql,onestrip& current_strip,float force){
    ////getdata

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}



float count::temp_to_force(sqlite3* sql,onestrip& current_strip){
    ////getdata   感度计算

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}

float count::temp_to_force(sqlite3* sql,onestrip& current_strip,float temp){
    ////getdata   感度计算

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}


float count::temp_to_thick(sqlite3* sql,onestrip& current_strip){
    ////getdata   扎制力对厚度

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}

float count::temp_to_thick(float force_of_temp,onestrip& current_strip){
    ////getdata   扎制力对厚度

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}

float count::size_to_force(sqlite3* sql,onestrip& current_strip){
    ////getdata   尺寸对扎制力

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}


float count::size_to_temp(sqlite3* sql,onestrip& current_strip){
    ////getdata   尺寸对温度

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}


float count::speed_to_temp(sqlite3* sql,onestrip& current_strip){
    ////getdata   

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}

float count::speed_to_force(sqlite3* sql,onestrip& current_strip){
    ////getdata   

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}

float count::water_to_temp(sqlite3* sql,onestrip& current_strip){
    ////getdata   

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}

float count::water_to_force(sqlite3* sql,onestrip& current_strip){
    ////getdata   

    return  (current_strip["FORCE"] + current_strip["FORCE_WS"]-current_strip["ROLL_FORCE_CAL"])/600/3  ;
}

