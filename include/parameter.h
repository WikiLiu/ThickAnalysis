#ifndef _PARAMETER_H 
#define _PARAMETER_H

#include<string>
#include"somefounction.h"


using namespace std;

typedef float thick_plus;
typedef int sfc;
typedef int qual_no;
typedef int thick_class;
typedef int width_class;
typedef int temp_class;
typedef std::string date;

struct parameter
{
    float ap_thick = 0.1;
    char strip_no[20]="220146900600";
    string outfile = "result.txt";
    string db_path = "/home/wiki/data/baosteel/thick_app/app/app/bin/Debug/analysis/thick_judge.db";
    
    /* data */
}parameter_current;


class parameters{

public:
 thick_plus set_thick_plus=0;
 date now_date=current_time();
};


#endif