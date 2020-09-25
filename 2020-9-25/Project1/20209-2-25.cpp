#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <iostream>
using namespace std;

#if 0
//���캯�����г�ʼ���б�Ĺ���
//��ʼ���б����þ���������Ա������ʼ������
class Time
{
public:
	//ע�⣺���һ����û����ʾ�����κι��캯�����������������һ��Ĭ�ϵĹ��캯�����޲εĹ��캯����
	//һ���û����ˣ��������Ͳ���������
	//Time�಻����Ĭ�ϵĹ��캯��
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int,int,int)" << endl;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

//���һ����A�а�����B�Ķ�����B�����޲ι��캯��ʱ����A���뽫���ڲ�������B�Ķ���
//����A�ĳ�ʼ���б��н��г�ʼ��
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		, ra(_day)
		��_t(0,0,0)//����Time��Ĺ��캯������Time���ж���_t���г�ʼ��
		
		//����Ķ��ǳ�ʼ���б�����Ĺ��캯���к������Ǹ�ֵ
	{
		//ע�⣺���캯�������Ǹ�ֵ�����ǳ�ʼ��
		/*_year = year;
		_month = month;
		_day = day;
		_day = 2020;*/
	}

	//��Ա�б������е���������������ʼ������
private:
	int _year;
	int _month;
	int _day;
	Time _t;

	int& ra;
};

int main()
{
	Date d(2020,9,25);
	return 0;
}
#endif

#if 0
class Time
{
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int,int,int)" << endl;
	}

private:
	int _hour; 
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year)
		: _year(year)
		, _month(1)
		, _day(1)
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2020);

	d = 2021;
	//���⣺d��һ��������Ķ���2021ֻ��һ���������͵����ݣ���ν��и�ֵ��
	/*
	1 ʹ��2021���õ������͵Ĺ��캯��������һ�������Ķ���û�����ֵĶ���
	2 ʹ�ø����������d�����и�ֵ
	3 ������������
	*/
	return 0;
}
#endif 

int count = 0;
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		//, _count(0)
	{
		cout << "Date(int,int,int):" << this << endl;
		_count++;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}

	~Date()
	{
		--_count;
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
public:
	//��̬��Ա����������ֻ������������Ҫ��������ж���
	static int _count;//��̬��Ա����
};

int Date::_count = 0;//��̬��Ա����
//��̬��Ա��������ͨ��Ա����֮�������
//��̬��Ա��������Ҫ��������г�ʼ��
//��̬��Ա����û�а����ڶ����У�ÿ�����󶼿���ʹ�ã������������ģ����������
//��̬��Ա��������Ӱ��һ����Ĵ�С
//��̬��Ա����ͨ������.���ʣ�Ҳ����ͨ��������������
//��̬��Ա���������ٹ��캯����ʼ���б��λ�ó�ʼ������Ϊ���캯���б�λ�ó�ʼ���Ķ��ǰ����ڶ����еĳ�Ա

void TestDate()
{
	Date d1(2020,9,25);
	Date d2(2020, 9, 25);
	Date d3(2020, 9, 25);
	Date d4(2020, 9, 25);

	Date d5(d1);
}

int main()
{
	TestDate();

	cout << Date::_count << endl;
	return 0;
}