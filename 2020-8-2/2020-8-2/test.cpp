#include <iostream>
using namespace std;

#if 0
class Data
{
public:
	//���캯����һ������ĳ�Ա���������������¼��㣺
	//	1. ��������������ͬ
	//  2. �޷���ֵ����ʹ��voidҲ����
	//	3. ����ʵ����ʱ�������Զ����ö�Ӧ�Ĺ��캯���������ڶ��������������ֻ����һ��
	//	4. ���캯����������
	Data(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		return; //return;����д����ʾ����û�з���ֵ������ֱ�ӴӸ�λ���˳�
	}

	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintData()
	{ 
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//Data d1;
	//d1.SetData(2020, 8, 2);//ʵ�ʵ���Data::SetData(&d, 2020, 8, 2);
	//d1.PrintData();

	Data d2(2020, 8, 2);//������󲢶����ʼ��--���캯��������ɶ����ʼ��
	d2.PrintData();
	return 0;
}
#endif

#if 0
//���캯����������
class Data
{
public:
	//�ù��캯��ֻ�ܴ���������������Ķ��󣬲��ܴ����޲εĶ���
	Data(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Data()
	{
		_year = 1000;
		_month = 3;
		_day = 2;
	}

	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintData()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 2);
	d1.PrintData();

	Data d2(2020, 8, 3);
	
	Data d3;//�ö���û�в���������Ӧ�ô����޲εĹ��캯��
	d3.PrintData();
	return 0;
}
#endif

#if 0
//ȫȱʡ�Ĺ��캯�����޲εĹ��캯��ͳ��ΪĬ�ϵĹ��캯��
//ע�⣺ȫȱʡ�Ĺ��캯�����޲εĹ��캯������ͬʱ����
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	//�޲εĹ��캯��
	Data()
	{
		_year = 1000;
		_month = 3;
		_day = 2;
	}

	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintData()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 2);
	d1.PrintData();

	Data d2(2020, 8, 3);

	Data d3;//�ö���û�в���������Ӧ�ô����޲εĹ��캯��
	d3.PrintData();
	return 0;
}
#endif

#if 0
class Time
{
public:
	Time(int hour = 0, int mintue = 0, int second = 0)
	{
		_hour = hour;
		_mintue = mintue;
		_second = second;
		cout << "Time(int,int,int)" << endl;
	}

private:
	int _hour;
	int _mintue;
	int _second;
};

class Data
{
public:
	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void PrintData()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;

	Time _t;
};

int main()
{
	Data d;//�������������Ĭ�ϵĹ��캯����Time _t������Լ��������͵Ĺ��캯��
}
#endif

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
private:
	// ��������(��������)
	int _year;
	int _month;
	int _day;
	// �Զ�������
	Time _t;
};
int main()
{
	Date d;
	return 0;
}