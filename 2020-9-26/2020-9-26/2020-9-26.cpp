#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	} 

	//��˽�е����Ա�����任�ɹ��еģ����Է���
	void setday(int day)
	{
		_day = day;
	}

	//��̬��Ա����
	//���ı��ʣ���̬��Ա����û��thisָ��
	//����Ҫͨ���������
	//���ܷ��ʷǾ�̬�ĳ�Ա����
	//���ܷ��ʷǾ�̬�ĳ�Ա����
	//����ʹ��const������--����Ϊconst����������thisָ�룬��̬��Ա����û��thisָ��
	static int Getcount()
	{
		return _count;
	}

	bool operator>(const Date& d)const
	{
		if ((_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day))
			return true;
		else
			return false;
	}

	void operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-"<< _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
	static int _count;//������ֻ������
};

//��̬��Ա��������������ȫ���������ж���
int Date::_count = 0;

int main()
{ 
	Date d1(2020, 9, 13);
	Date d2(d1);
	cout << Date::Getcount() << endl;

	d1.setday(1);

	Date d(2020, 9, 26);
	//cout << d;
	d << cout;
	return 0;
}
#endif 

#if 0
//��ʾ���������������س���ĳ�Ա��������Ϊ���õ��߼������
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator>(const Date& d)const
	{
		if ((_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day))
			return true;
		else
			return false;
	}

	void operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2020, 9, 26);
	//cout << d;
	d << cout;
	return 0;
}
#endif

#if 0
//�������س���ĳ�Ա��������������Ϊ��ͨ��ȫ�ֺ���
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day; 
	}

private:
public:
	int _year;
	int _month;
	int _day;
};

//�����������ر����з���ֵ�������޷�������ӡ
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

int main()
{
	Date d(2020, 9, 26);
	Date d1(2020, 9, 29);
	cout << d;
	cout << d << d1;
	//operator<<(operatpr<<(cout, d), d1)
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	int Getyear()const
	{
		return _year;
	}

	int Getmonth()const
	{
		return _month;
	}

	int Getday()const
	{
		return _day;
	}

private:
	int _year;
	int _month;
	int _day;
};

//�����������ر����з���ֵ�������޷�������ӡ
ostream& operator<<(ostream& _cout, const Date& d)
{
	//_cout << d._year << "-" << d._month << "-" << d._day << endl;
	_cout << d.Getyear() << "-" << d.Getmonth() << "-" << d.Getday();
	return _cout;
}

int main()
{
	Date d(2020, 9, 26);
	cout << d;

	return 0;
}
#endif

class Date
{
	//ע�⣺��Ԫ����������ĳ�Ա����
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	int Getyear()const
	{
		return _year;
	}

	int Getmonth()const
	{
		return _month;
	}

	int Getday()const
	{
		return _day;
	}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	//_cout << d._year << "-" << d._month << "-" << d._day << endl;
	_cout << d.Getyear() << "-" << d.Getmonth() << "-" << d.Getday();
	return _cout;
}

int main()
{
	Date d(2020, 9, 26);
	cout << d;

	return 0;
}