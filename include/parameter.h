#pragma once

#ifndef _PARAMETER_H_

#define _PARAMETER_H_

#include <string>

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
    char strip_no[20] = "220146900600";
    string outfile = "result.txt";
    string db_path = "/home/wiki/data/baosteel/thick_app/app/app/bin/Debug/analysis/thick_judge.db";

    float max_force7 = 20000;
    float min_force7 = 2100;

    /* data */
};


#endif