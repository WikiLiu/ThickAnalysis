#include "Count.h"
#include "Logic.h"
#include "Out.h"
#include "readsql.h"
#include "sqlite3.h"
#include "parameter.h"
#include <iostream>
#include <ctime>
#include "somefounction.h"
#include <thread>

using namespace std;
extern struct parameter parameter_current;
static float access;

int size_stuff(sqlite3 *sql, string *outfile, onestrip &current_strip, map<string, float> *return_stuff);
int speed(sqlite3 *sql, string *outfile, onestrip &current_strip, map<string, float> *return_speed);
int water(sqlite3 *sql, string *outfile, onestrip &current_strip, map<string, float> *return_speed);

int analysis_1780()
{

    string outfile = parameter_current.outfile;
    sqlite3 *sql = NULL; // 一个打开的数据库实例

    const string path = parameter_current.db_path;

    // 一个打开的数据库实例
    const char *path_db = path.c_str();

    // 根据文件路径打开数据库连接。如果数据库不存在，则创建。
    // 数据库文件的路径必须以C字符串传入。
    int result = sqlite3_open(path_db, &sql);

    if (result == 0)
    {
        std::clog << "open success\n";
    }
    else
    {
        std::clog << "open error\n";
    }
    char combat[120] = "select rowid,* from '2021-11' where STRIP_NO=";
    strcat(strcat(combat, parameter_current.strip_no), " and STAND_NO=7;");

    onestrip current_strip = search_dat(sql, combat);

    // judge *aaa = new force_act_judge(10, 20,10);
    // cout << aaa->compare() << endl;

    /*test
        vector<float> *return_stuff = new vector<float>();


        thread th1(size_stuff, sql, &outfile, ref(current_strip), return_stuff);

        // 等待线程 t1 完成
        th1.join();

        cout << return_stuff->at(0) << return_stuff->at(1) << endl;
    test*/
    ///////////////////start____
    if (abs(current_strip["FM_THICK_ACT"] - current_strip["FMOUTTHICK"]) < 0.1)
    {
        exit(1);
    }

    if (force_act_judge(current_strip["ROLL_FORCE_CAL"], current_strip["FORCE"] + current_strip["FORCE_WS"], current_strip["FM_THICK_ACT"] - current_strip["FMOUTTHICK"]).compare())
    {
        if (thick_roll_judge(current_strip["delta_thick"], count::force_to_roll(sql, current_strip)).compare()) //////a,b
        {
            out::consequece_force(&outfile);
            if (act_act_judge(current_strip["FORCE"], current_strip["FORCE_WS"]).compare()) //////////////给出一个标志位 什么时候测量异常
            {                                                                               ///////////////
                if (post_force_act_judge(current_strip["ROLL_FORCE_POST"], current_strip["FORCE"] + current_strip["FORCE_WS"]).compare())
                {
                    //////扎制力模型准确
                    out::consequece_set_cont(&outfile);
                    map<string, float> *return_stuff = new map<string, float>();
                    map<string, float> *return_speed = new map<string, float>();
                    map<string, float> *return_water = new map<string, float>();

                    thread th1(size_stuff, sql, &outfile, ref(current_strip), return_stuff);
                    thread th2(speed, sql, &outfile, ref(current_strip), return_speed);
                    thread th3(water, sql, &outfile, ref(current_strip), return_water);
                    // 等待线程 t1 完成
                    th1.join();
                    // 等待线程 t2 完成
                    th2.join();
                    // 等待线程 t3 完成
                    th3.join();

                    access = count::temp_to_force(sql, current_strip, (*return_stuff)["temp"]);
                    count::force_to_roll(sql, current_strip, access + (*return_stuff)["force"]);

                    access = count::temp_to_force(sql, current_strip, (*return_water)["temp"]);
                    count::force_to_roll(sql, current_strip, access + (*return_water)["force"]);

                    access = count::temp_to_force(sql, current_strip, (*return_water)["temp"]);
                    count::force_to_roll(sql, current_strip, access + (*return_water)["force"]);
                }
                else
                {

                    out::consequece_force_model(&outfile);
                    if (post_temp_force_opposite_judge(current_strip["FM_TEMP_ACT"] -
                                                           current_strip["EXIT_TEMP_POST"],
                                                       current_strip["FORCE"] + current_strip["FORCE_WS"] -
                                                           current_strip["ROLL_FORCE_POST"])
                            .compare())

                    /////////////////////getdata  后计算和扎制力抛偏差  扎制力是预计算扎制力还是后计算   后计算
                    {
                        access = count::temp_to_force(sql, current_strip);
                        access = count::force_to_roll(sql, current_strip, access);
                        if (temp_thick_judge(current_strip["delta_thick"], access).compare())
                        {
                            out::consequece_temp(&outfile);
                            return 1;
                        }
                        else
                        {
                            ////遗传分析
                            cout << "遗传分析" << endl;
                        }
                    }
                    else
                    {
                        ////遗传分析
                        cout << "遗传分析" << endl;
                        if (current_strip["CORR_FORCE_STAND_CAL"] == 1)
                            out::consequece_heredity(&outfile, "新钢种,机架系数为1");
                        if (current_strip["CORR_FORCE_STAND_CAL"] == 1.25)
                            out::consequece_heredity(&outfile, "扎制力系数调节范围有限,最高1.25");
                        if (current_strip["CORR_ZEROPOINT_USE"] == 0)
                            out::consequece_heredity(&outfile, "换辊后辊缝学习值置零");
                        ////////这里可增加一条新钢种 就写一条sql quary为null
                        if (!query_kind(sql, current_strip)) ////非表示没查到
                        {
                            out::consequece_heredity(&outfile, "该规格第一次扎制");
                        };
                    }
                }
            }
            else
            {
                out::consequece_act(&outfile);
            }
        }
        else
        {
            out::consequece_roll(&outfile);
            return 1;
        }
    }
    else
    {
        out::consequece_roll(&outfile);
        return 1;
    }

    // count::force_to_roll(sql,new char('a'),new char('b'));

    sqlite3_close(sql);
    return 0;
}

int size_stuff(sqlite3 *sql, string *outfile, onestrip &current_strip, map<string, float> *return_stuff)
{

    (*return_stuff)["force"] = 0.5;
    (*return_stuff)["temp"] = 0.5;
    if (size_stuff_judge(1, 2, 3, 4).compare())
    {
        out::consequece_stuff(outfile);
        count::size_to_temp(sql, current_strip);
        access = count::size_to_force(sql, current_strip);
        count::force_to_roll(sql, current_strip, access); //改成合理的顺序 是不是要温度扎制力累加起来 如果是 要设一个指针指到和
        return 0;
    }
    else
    {
        return 1;
    }
}

int speed(sqlite3 *sql, string *outfile, onestrip &current_strip, map<string, float> *return_speed)
{
    (*return_speed)["force"] = 0.5;
    (*return_speed)["temp"] = 0.5;

    if (speed_judge(1.0, 2.0, 3.0).compare())
    {
        out::consequece_speed(outfile);
        count::speed_to_temp(sql, current_strip);
        count::speed_to_force(sql, current_strip);
        return 0;
    }
    else
    {
        return 1;
    }
}

int water(sqlite3 *sql, string *outfile, onestrip &current_strip, map<string, float> *return_water)
{
    (*return_water)["force"] = 0.5;
    (*return_water)["temp"] = 0.5;

    if (speed_judge(1, 2, 3).compare())
    {
        out::consequece_water(outfile);
        count::water_to_temp(sql, current_strip);
        count::water_to_force(sql, current_strip);
        return 0;
    }
    else
    {
        return 1;
    }
}
