#ifndef _SOMEFOUNCTION_H
#define _SOMEFOUNCTION_H

#include <ctime>
#include <string>
#include <chrono>
#include <string>
#include <memory>

using std::chrono::system_clock;

std::string current_time()
{
    system_clock::time_point tp = system_clock::now();

    time_t raw_time = system_clock::to_time_t(tp);

    // tm*使用完后不用delete，因为tm*是由localtime创建的，并且每个线程中会有一个
    struct tm *timeinfo = std::localtime(&raw_time);

    char buf[24] = {0};
    // 标准c++中也可以使用"%F %X,"，但VC2017中不能这样用
    strftime(buf, 24, "%Y-%m-%d %H:%M:%S,", timeinfo);

    // tm只能到秒，毫秒需要另外获取
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());

    std::string milliseconds_str = std::to_string(ms.count() % 1000);

    if (milliseconds_str.length() < 3)
    {
        milliseconds_str = std::string(3 - milliseconds_str.length(), '0') + milliseconds_str;
    }

    return std::string(buf) + milliseconds_str;
};


float force_calcular(vector<float> canshuliebiao)
{

	int standNo = 0;
	float carbon = 0, manganese = 0, silicon = 0, nickel = 0, chromium = 0, vanadium = 0, molybdenum = 0, niobium, titanium, copper, aluminium, kChem;
	float kf = 1; //passData.inherActive.inherVal.force;
	//if (standNo >= 21 && standNo <= 27)
	//{
	//    kf = limitJudge(kf, paramap->getConfig().kRFLimit.at(standNo - 21));
	//}
	//else
	//{
	//    kf = limitJudge(kf, paramap->getConfig().RmRFLimit);
	//}
	//kf
	float entry_temp, rel_redu, entry_thk, exit_thk, cir_speed, radius, wrdiam, entry_tension, exit_tension, width;
	float ak[12] = { 9.55047,2.24723,	1.79067,	1.65026,	0.963662,	0.713756,	4.94787	,3.15128,	8.85264,	3.60935,	1.47319,	0 };
	float bk[10] = { 0.066075,	0.313821,	3.14465,	0.178837,	0.136993,	0,	0,	0	,0,	0 };
	kChem = ak[0]
		+ ak[1] * carbon
		+ ak[2] * manganese
		+ ak[3] * silicon
		+ ak[4] * nickel
		+ ak[5] * chromium
		+ ak[6] * vanadium
		+ ak[7] * molybdenum
		+ ak[8] * niobium
		+ ak[9] * titanium
		+ ak[10] * copper
		+ ak[11] * aluminium;

	float k_T = exp(bk[0] + bk[1] * carbon + bk[2] * silicon + bk[3] * 1000 / (273 + entry_temp));//对铁素体轧制的温度进行过处理。
	float k_e = std::log(1.0 / (1 - rel_redu));
	float deltaH = entry_thk - exit_thk;
	rel_redu = deltaH / entry_thk;
	float k_er = 1000 * cir_speed / sqrt(radius * deltaH) * k_e;
	radius = wrdiam / 2.0;
	deltaH = entry_thk - exit_thk;


	float km = kChem * k_T * pow(k_e, bk[4]) * pow(k_er, bk[5]);

	km = km * 1; // corrkm

	//tencorr[0] = 1;
	//tencorr[1] = 1;
	//if (paradata.am.size() > 10 && paradata.am.at(10) != 0)
	//{
	//    tencorr[0] = paradata.am.at(10);
	//    tencorr[1] = paradata.am.at(11);
	//};

	//km = km + tencorr[1] * entry_tension + tencorr[0] * exit_tension;

	km = km + entry_tension + exit_tension;


	km = kChem * k_T * pow(k_e, bk[4]) * pow(k_er, bk[5]);

	float am[] = { 0.773, -0.031,	1.19823,	0.0271803,	0.19578 };
	//压扁半径,外摩擦系数
	float cq[10] = {};
	cq[0] = am[0];
	cq[1] = am[1];
	cq[2] = am[2];
	cq[3] = am[3];
	cq[4] = am[4];

	float  q1 = cq[0] + cq[1] * rel_redu;
	float q2 = cq[2] + cq[3] * rel_redu + cq[4] * rel_redu * rel_redu;

	float C_R = deltaH; deltaH = entry_thk - exit_thk;
	float Deform = 2.2069e-005f;
	float B_R = Deform * km * q1 * sqrt(radius * C_R);
	float A_R = C_R - Deform * km * q2 * radius * sqrt(rel_redu / (1 - rel_redu));

	float kRadius = (B_R + sqrt(B_R * B_R + 4 * A_R * C_R)) / 2.0 / A_R;
	float Rd = radius * kRadius * kRadius;
	radius = wrdiam / 2.0;
	//if (A_R > 0)
	//{
	//    kRadius = (B_R + sqrt(B_R * B_R + 4 * A_R * C_R)) / 2.0 / A_R;
	//}
	//else
	//{
	//    kRadius = 1.0;
	//}





	q1 = cq[0] + cq[1] * rel_redu;
	q2 = cq[2] + cq[3] * rel_redu + cq[4] * rel_redu * rel_redu;
	/*  if (paradata.am.size() > 5 && paradata.am.at(5) > 0)
	  {
		  cq[0] = paradata.am.at(5);
		  cq[1] = paradata.am.at(6);
		  cq[2] = paradata.am.at(7);
		  cq[3] = paradata.am.at(8);
		  cq[4] = paradata.am.at(9);
	  }*/
	  /*   else
		 {
			 cq[0] = C[0];
			 cq[1] = C[1];
			 cq[2] = C[2];
			 cq[3] = C[3];
			 cq[4] = C[4];
		 }*/



	float Ld = sqrt(Rd * C_R);


	float Q_F = q1 + q2 * sqrt(Rd / exit_thk);

	//bao hu
	if (Q_F <= 0)	Q_F = 0.001;
	Rd = radius * kRadius * kRadius;


	float force = kf * width * km * Ld * Q_F / 1000.0;  //KN




	return force;
	//return 0.0;
};














float temp_calcular();

bool query_kind(sqlite3 *sql, onestrip &p)
{

    char linkchar[500];
    sprintf(linkchar, "select rowid,* from '2021-11' where STAND_NO=7 and SFC=%d and QUAL_NO=%d and THICK_CLASS=%d and WIDTH_CLASS=%d and toc<(select toc from '2021-11' where STRIP_NO =%ld ) order by toc desc limit 7", int(p["SFC"]), int(p["QUAL_NO"]), int(p["THICK_CLASS"]), int(p["WIDTH_CLASS"]), long(p["STRIP_NO"]));
        string link = string(linkchar);
    onestrip old_strip = search_dat(sql, linkchar);
    if(old_strip.size()==0)
    return 0;
    else
    return 1;
}

;

#endif