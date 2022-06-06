#pragma once
#ifndef _READSQL_H_
#define _READSQL_H_

#include "sqlite3.h"
#include <math.h>
#include <string.h>
#include <iostream>

#include <vector>
#include <map>
using namespace std;


typedef map<string, double> onestrip;
typedef vector<map<string, double>> somestrip;
using namespace std;
onestrip search_dat(sqlite3 *sql, char combat[]);
#endif // READSQL_H
