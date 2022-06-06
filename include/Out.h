 #ifndef _OUT_H
#define _OUT_H
#include "sqlite3.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
namespace out{              //////可增加选择追加和清空
typedef std::string outfile;

int consequece_roll(outfile*,char*,int *);
int consequece_roll(outfile*);

int consequece_force(outfile*,char*,int *);
int consequece_force(outfile*);


int consequece_act(outfile*,char*,int *);
int consequece_act(outfile*);


int consequece_set_cont(outfile*);


int consequece_stuff(outfile*,char*,int *);
int consequece_stuff(outfile*);

int consequece_speed(outfile*,char*,int *);
int consequece_speed(outfile*);

int consequece_water(outfile*,char*,int *);
int consequece_water(outfile*);

int consequece_force_model(outfile*,char*,int *);
int consequece_force_model(outfile*);


int consequece_temp(outfile,char*,int *);
int consequece_temp(outfile*);


int consequece_heredity(outfile* ,string c ="OKOKOK");/////////////遗传


}

#endif