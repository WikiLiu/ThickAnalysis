#include "Out.h"

int out::consequece_roll(string* outfile){

ofstream file;
file.open(*outfile, ios::out | ios::trunc );
file<<"辊缝设定不准"<<endl;
file.close();
return 1;
}
int out::consequece_force(string* outfile){

ofstream file;
file.open(*outfile, ios::out | ios::trunc );
file<<"轧制力设定不准引起厚度偏差"<<endl;
file.close();
return 1;
}
int out::consequece_act(string* outfile){

ofstream file;
file.open(*outfile, ios::out | ios::app );
file<<"实绩异常END"<<endl;
file.close();
return 1;
}
int out::consequece_force_model(string* outfile){

ofstream file;
file.open(*outfile, ios::out | ios::app );
file<<"轧制力模型不准确"<<endl;
file.close();
return 1;
}
int out::consequece_set_cont(string* outfile){

ofstream file;
file.open(*outfile, ios::out | ios::app );
file<<"设定与控制实绩不一致"<<endl;
file.close();
return 1;
}

int out::consequece_temp(string* outfile){

ofstream file;
file.open(*outfile, ios::out | ios::app );
file<<"温度模型不准确"<<endl;
file.close();
return 1;
}
int out::consequece_stuff(string* outfile){

ofstream file;
file.open(*outfile, ios::out | ios::app );
file<<"来料异常"<<endl;
file.close();
return 1;
}



int out::consequece_speed(string* outfile){

ofstream file;
file.open(*outfile, ios::out | ios::app );
file<<"速度异常"<<endl;
file.close();
return 1;
}

int out::consequece_water(string* outfile){

ofstream file;
file.open(*outfile, ios::out | ios::app );
file<<"水异常"<<endl;
file.close();
return 1;
}

int out::consequece_heredity(string* outfile , string c){

ofstream file;
file.open(*outfile, ios::out | ios::app );
file<<"遗传问题:"<<c<<endl;
file.close();
return 1;
}
