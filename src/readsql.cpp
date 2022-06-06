#include"readsql.h"
#include<iostream>
#include"sqlite3.h"
#include<fstream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include<map>
#include<time.h>
using  namespace std;


onestrip search_dat(sqlite3* sql,char combat[])
{
   
   
   /* strcat(combat, finish_dat);
    strcat(combat, "';");*/
    onestrip stripcolunm;
    vector<map < string, double >> pandavector;
    map < string, double > panda;
    string oldstripno="";
    // char* sqlSentence = combat;
    int i, j;
    int result;
    char* errmsg = NULL;
    char** dbResult; //�� char ** ���ͣ�����*��
    int nRow, nColumn;
  
    result = sqlite3_get_table(sql,combat,&dbResult, &nRow, &nColumn, &errmsg);
    // bool had=0;
    
    if (result == 0) {

        // ÿ��һ��sqlite3_step()������stmt������ͻ�ָ����һ����¼
        int index = nColumn;
        int nr = nRow;
        for (i = 0; i < nr; i++)
        {
    
            for (j = 0; j < nColumn; j++)
            {
                stripcolunm.insert(map<string, double>::value_type(dbResult[j], atof(dbResult[index])));
                
                index++;
                // dbResult ���ֶ�ֵ�������ģ��ӵ�0�������� nColumn - 1���������ֶ����ƣ��ӵ� nColumn ������ʼ�����涼���ֶ�ֵ������һ����ά�ı�����ͳ�����б�ʾ������һ����ƽ����ʽ����ʾ
            }
            pandavector.push_back(stripcolunm);
            
           
            if (oldstripno == "")
            {
               oldstripno = std::to_string((stripcolunm["STRIP_NO"])).substr(0, 12);
            }
            
            if (pandavector.size()==7) {
                // pandas.insert(map<string, vector<map < string, double >>>::value_type(oldstripno.substr(0, 12), pandavector));
                oldstripno = "";
                
                // pandavector.clear();
            }

            // stripcolunm.clear();
            printf("------ - \n");
        }
    }

    try{
        if(stripcolunm.size()==0)
        throw "dont have strip_no in database";
    }catch(const char *msg)
    {
            cout<<msg<<endl;
    };
    

    sqlite3_free_table(dbResult);


    return stripcolunm;
}

class evaluation {
public:
    evaluation(sqlite3* p):sql(p) {
    };
    void change(vector<map<string,double>>* basebatch) {


    }
private:
    sqlite3* sql;


};