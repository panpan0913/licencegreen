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

//��������
void SetDate(int y, int m, int d, tagDate *date)
{
	date->year = y;
	date->month = m;
	date->day = d;
}

//�Ƿ�����
int IsLeapYear(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0);
}

//�õ�date.month���������
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

//�����Ƿ�Ϸ�
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

//date1��date2С����ֵΪ1������Ϊ0
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
//�����������ڵļ������
long DateDiff(tagDate date1, tagDate date2)
{
	long delta = 0;
	tagDate date3;
	//��date1 > date2,����date1,date2
	if (!Compare(date1, date2))
	{
		date3 = date2;
		date2 = date1;
		date1 = date3;
	}

	//date1��date2��ʱ��date1���ڼ�1
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
	strftime(ch, sizeof(ch) - 1, "%Y$%m$%d", localtime(&t));     //��-��-�� ʱ-��-��
	return ch;
}
void TimeStrToInt(const string Time,int& year ,int &mth,int& day)//��ʱ����ַ������磺"2010$10$21";����������������
{
	//�ַ���ȡ
	std::string yearIn = Time.substr(0, 4);
	std::string mthIn = Time.substr(5, 2);
	std::string dayIn = Time.substr(8, 2);
	//����ת��
	year = stoi(yearIn);
	mth = stoi(mthIn);
	day = stoi(dayIn);
}

//��ȡ�������ʱ���ַ������뵱ǰʱ��ȶԡ�
//���أ�-YY������
//���أ�+XX��ʹ��ʱ��
int TimeDiff(string startTime,int UseingTime)
{
	//��ȡlicence������ʱ��
	string  LastTime;
	int Syear, Smth, Sday;
	TimeStrToInt(startTime, Syear, Smth, Sday);
 
	//��ȡ��ǰʱ��
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

	int RemainingTime=UseingTime - difTime;//��ʹ��ʱ���ȥ����ʱ��=ʣ���ʹ����������С��10�쵯�����棩
	//cout <<"Result : "<< difTime << endl;
	if (RemainingTime < 10)
	{
		return (-1)*RemainingTime;//���ظ�������ʾ��ʣ��ʹ������
	}
	else 
	{
		return 11;//ʣ��ʱ���ԣ������11
	}
 
}

#endif
