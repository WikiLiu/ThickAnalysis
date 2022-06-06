#include "Count.h"
#include "Logic.h"
#include "Analysis_1780.h"

#include <iostream>
#include <ctime>

using namespace std;
int main(int argc, char *argv[]) //
{
  // judge *zhazhili= new force_act_judge(10,20);
  // // judge* a = new force_act_judge(10,20);
  // std::cout<<zhazhili->compare()<<std::endl;
  // string path_db = "";
  // strip_no current = "argv[1]";
  // analysis_1780(&path_db, &current);

  ///current_strip["delta_thick"]<parameter_current.ap_thick
  cout << argc << "  " << argv[1] << endl;
  analysis_1780();
  return 0;
}

/// ThickaAnalysis_o