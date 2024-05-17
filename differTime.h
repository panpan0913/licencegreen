#ifndef _DIFFERTIME_H_
#define _DIFFERTIME_H_
#include <stdio.h>
#include <string.h>

using namespace std;
struct tagDate
{
	int year;
	int month;
	int day;
};

//设置日期
void SetDate(int y, int m, int d, tagDate *date)
{
	date->year = y;
	date->month = m;
	date->day = d;
}

//是否闰年
int IsLeapYear(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0);
}

//得到date.month的最大天数
int GetLastDay(tagDate date)
{
	int num;
	switch (date.month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		num = 31;
		break;
	case 2:
		num = 28 + IsLeapYear(date.year);
		break;
	default:
		num = 30;
	}
	return num;
}

//日期是否合法
int IsDateValid(tagDate date)
{
	if (date.year <0 || date.month <1 || date.month> 12)
		return 0;

	if (date.day <1 || date.day> GetLastDay(date))
		return 0;

	return 1;
}

//date+1
void AddDay(tagDate *date)
{
	date->day++;
	if (date->day > GetLastDay(*date))
	{
		date->day = 1;
		date->month++;
		if (date->month > 12)
		{
			date->month = 1;
			date->year++;
		}
	}
}

//date1比date2小返回值为1，否则为0
int Compare(tagDate date1, tagDate date2)
{
	if (date1.year < date2.year)
		return 1;
	if (date1.year <= date2.year && date1.month < date2.month)
		return 1;
	if (date1.year <= date2.year && date1.month <= date2.month && date1.day < date2.day)
		return 1;

	return 0;
}
//计算两个日期的间隔天数
long DateDiff(tagDate date1, tagDate date2)
{
	long delta = 0;
	tagDate date3;
	//若date1 > date2,交换date1,date2
	if (!Compare(date1, date2))
	{
		date3 = date2;
		date2 = date1;
		date1 = date3;
	}

	//date1比date2少时，date1日期加1
	while (Compare(date1, date2))
	{
		AddDay(&date1);
		delta++;
	}
	return delta;
}
string  getCurrentTimeStr2()
{
	time_t t = time(NULL);
	char ch[64] = { 0 };
	strftime(ch, sizeof(ch) - 1, "%Y$%m$%d", localtime(&t));     //年-月-日 时-分-秒
	return ch;
}
void TimeStrToInt(const string Time,int& year ,int &mth,int& day)//将时间的字符串（如："2010$10$21";）解析出三个数字
{
	//字符提取
	std::string yearIn = Time.substr(0, 4);
	std::string mthIn = Time.substr(5, 2);
	std::string dayIn = Time.substr(8, 2);
	//数字转换
	year = stoi(yearIn);
	mth = stoi(mthIn);
	day = stoi(dayIn);
}

//读取解析后的时间字符串；与当前时间比对。
//返回：-YY；出错
//返回：+XX；使用时间
int TimeDiff(string startTime,int UseingTime)
{
	//读取licence解析的时间
	string  LastTime;
	int Syear, Smth, Sday;
	TimeStrToInt(startTime, Syear, Smth, Sday);
 
	//读取当前时间
	LastTime = getCurrentTimeStr2();
	int Lyear, Lmth, Lday;
	TimeStrToInt(LastTime, Lyear, Lmth, Lday);

	tagDate date1, date2;
 	SetDate(Syear, Smth, Sday, &date1);
	if (!IsDateValid(date1))
	{
		return 9;
	}
 
	SetDate(Lyear, Lmth, Lday, &date2);
	if (!IsDateValid(date2))
	{
		return 10;
	}
	int difTime = DateDiff(date1, date2);

	int RemainingTime=UseingTime - difTime;//可使用时间减去已用时间=剩余可使用天数（如小于10天弹出警告）
	//cout <<"Result : "<< difTime << endl;
	if (RemainingTime < 10)
	{
		return (-1)*RemainingTime;//返回负数，表示，剩余使用天数
	}
	else 
	{
		return 11;//剩余时间充裕，返回11
	}
 
}

#endif
