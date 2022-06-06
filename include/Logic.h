#ifndef _LOGIC_H_
#define _LOGIC_H_

#define yes bool(1);
#define no bool(0);
typedef bool check_yes_no;
class judge
{
public:
  
    virtual check_yes_no compare() = 0;
};

class force_act_judge:public judge
{
    public:
    force_act_judge(float,float,float thick_delta,float force_delta=10);
    check_yes_no compare();
    
    private:
    float setting;
    float actual;
    float thick_delta;
    float delta;
};

class thick_roll_judge:public judge
{   ////////通过扎制力误差计算的厚度差 与实际厚度差 公差取多少表示由扎制力引起的呢? 多少可以忽视辊缝
    public:
    thick_roll_judge(float,float,float thick_roll_delta=0.05);
    check_yes_no compare();
    
    private:
    float thick;
    float roll;
    float delta;
};

class act_act_judge:public judge  /////////////////getdata
{
    public:
    act_act_judge(float,float,float c=10);
    check_yes_no compare();
    
    private:
    float first;
    float second;
    float delta;
};

class post_force_act_judge:public judge
{
    public:
    post_force_act_judge(float post_force,float act_force,float c=10);
    check_yes_no compare();
    
    private:
    float post_force;
    float act_force;
    float delta;
};



class size_stuff_judge:public judge
{
    public:
    size_stuff_judge(float chicun_cal,float  chengfen_cal,float chicun_post,float chengfen_post,float c=0);
    check_yes_no compare();
    
    private:
    float chicun_cal;
    float chengfen_cal;
    float chicun_post;
    float chengfen_post;
    float delta;
};
class speed_judge:public judge
{
    public:
    speed_judge(float,float,float c=0);
    check_yes_no compare();
    
    private:
    float first;
    float second;
    float delta;
};

class water_judge:public judge
{
    public:
    water_judge(float,float,float c=0);
    check_yes_no compare();
    
    private:
    float first;
    float second;
    float delta;
};


class post_temp_force_opposite_judge:public judge
{
    public:
    post_temp_force_opposite_judge(float acttempSUBpost,float actforceSUBpost,float temp_force_delta=15);
    check_yes_no compare();
    
    private:
    float acttempSUBpost;
    float actforceSUBpost;
    float temp_delta=15;
};


class temp_thick_judge:public judge
{
    public:
    temp_thick_judge(float temp_to_thick,float thick_delta,float delta=0);
    check_yes_no compare();
    
    private:
    float temp_to_thick;
    float thick_delta;
    float delta;
};


#endif