#include "Logic.h"
#include "parameter.h"
extern struct parameter parameter_current;

force_act_judge::force_act_judge(float a, float b, float c, float force_delta)
{
    setting = a;
    actual = b;
    thick_delta = c; ////shiji - shedin
    delta = force_delta;
}
check_yes_no force_act_judge::compare()
{

    if ((actual - setting) * 100 / actual >= delta && (actual - setting) * thick_delta > 0) ////扎制力的方向和厚度方向相同
    {
        return yes;
    }
    else
    {
        return no;
    }
}

thick_roll_judge::thick_roll_judge(float a, float b, float thick_roll_delta)
{
    thick = a;
    roll = b;
    delta = thick_roll_delta;
}
check_yes_no thick_roll_judge::compare()
{
    ////getdata

    if ((thick - roll) < delta)
    {
        return yes;
    }
    else
    {
        return no;
    }
}
act_act_judge::act_act_judge(float a, float b)
{
    force = a;
    force_ws = b;

}
act_act_judge::act_act_judge(float a)
{
    sum_force = a;
}
check_yes_no act_act_judge::compare()
{
    ////getdata

    if (sum_force == 0)
    {
        if ((force + force_ws) < parameter_current.max_force7 && (force + force_ws) > parameter_current.min_force7)
        {
            return yes;
        }
        else
        {
            return no;
        }
    }
    else   ////输入一个值
    {
        if ((sum_force) < parameter_current.max_force7 && (sum_force) > parameter_current.min_force7)
        {
            return yes;
        }
        else
        {
            return no;
        }
    }
}

post_force_act_judge::post_force_act_judge(float a, float b, float thick_roll_delta)
{
    post_force = a;
    act_force = b;
    delta = thick_roll_delta;
}
check_yes_no post_force_act_judge::compare()
{
    ////getdata
    if ((act_force - post_force) * 100 / act_force <= delta) ////基本一致
    {
        return yes;
    }
    else
    {
        return no;
    }
}

post_temp_force_opposite_judge::post_temp_force_opposite_judge(float a, float b, float c)
{
    acttempSUBpost = a;
    actforceSUBpost = b;
    temp_delta = c;
}
check_yes_no post_temp_force_opposite_judge::compare()
{
    ////getdata  是实际温度减后计算吗?
    if ((acttempSUBpost * actforceSUBpost) < 0 && acttempSUBpost >= temp_delta)
    {
        return yes;
    }
    else
    {
        return no;
    }
}

temp_thick_judge::temp_thick_judge(float a, float b, float c)
{
    temp_to_thick = a;
    thick_delta = b;
    delta = c;
}
check_yes_no temp_thick_judge::compare()
{
    ////getdata
    if ((temp_to_thick - thick_delta) <= delta)
    {
        return yes;
    }
    else
    {
        return no;
    }
}

size_stuff_judge::size_stuff_judge(float a, float b, float m, float n, float c)
{
    chicun_cal = a;
    chengfen_cal = b;
    chicun_post = m;
    chengfen_post = n;
    delta = c;
}
check_yes_no size_stuff_judge::compare()
{
    ////getdata
    if ((chicun_cal - chicun_post) <= delta && (chicun_post - chengfen_post) <= delta)
    {
        return yes;
    }
    else
    {
        return no;
    }
}

speed_judge::speed_judge(float a, float b, float c)
{
    //  chicun_cal=a;
    // chengfen_cal=b;
    // chicun_post=m;
    //  chengfen_post=n;
    // delta = c;
}
check_yes_no speed_judge::compare()
{
    ////getdata
    // if ((chicun_cal - chicun_post) <= delta  && (chicun_post-chengfen_post)<=delta)
    // {
    //     return yes;
    // }
    // else
    // {
    return no;
    // }
}

water_judge::water_judge(float a, float b, float c)
{
    //  chicun_cal=a;
    // chengfen_cal=b;
    // chicun_post=m;
    //  chengfen_post=n;
    // delta = c;
}
check_yes_no water_judge::compare()
{
    ////getdata
    // if ((chicun_cal - chicun_post) <= delta  && (chicun_post-chengfen_post)<=delta)
    // {
    //     return yes;
    // }
    // else
    // {
    return no;
    // }
}
