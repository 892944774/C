#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//�������캯��
	//����Ĺ��캯����һ���ǵ��εģ����������������Ͷ�������ã�һ������¼�const��
	//��ʹ���Ѵ��ڵĶ��󴴽��¶���ʱ���ɱ������Զ�����
	//һ�㿽������Ҫͨ���ⲿ���βθı��ⲿ��ʵ�Σ������const��������
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << this << ":" << &d << endl;
	}

	~Data()
	{
		//����Data����������д��д������ν��һ����������Ƕ���д
		//��Ϊ��������һ������ǰ�����е���Դ����Data����û���漰����Դ����
		//�������������û��Ƿ���Ҫ����Ĭ�ϵĻ����Լ�����
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 7);
	
	//d1��ʶ��d2
	//d2���´����Ķ��󣬼�Ȼ�´����˶������Ҫ���ù��캯�� 
	//��Ϊ�����Ѿ����ڵ�d1�����¶���d2������Ҫ���ÿ������캯��
	Data d2(d1);
	return 0;
}
#endif

#if 0
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 7);

	//Data��û����ʾ�ṩ�������캯��������d2���󴴽��ɹ���d2�����е����ݺ�d1�����е�������ͬ
	//���Ѿ����ڶ���d1���������¶���d2---���õľ��Ǳ��������ɵ�Ĭ�ϵĿ������캯��
	//��������data�����ɵ�Ĭ�ϵĿ������캯���Ѿ��ܹ���ɿ����Ĺ���
	//���������ɿ������캯����ֵ�ÿ�������һ�������е�����ԭ�ⲻ���Ŀ������¶�����
	
	//����Data�ࣺʹ�ñ��������ɵ�Ĭ�Ϲ��캯��û������
	//Data�Ŀ������캯��д��д������
	Data d2(d1);
	return 0;
}
#endif

#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str)+1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
			free(_str);
	}
	 
private:
	char* _str; 
};

int main()
{
	//��s1��������s2���϶�Ҫ���ÿ������캯��
	//��ΪString��û����ʾ�ṩ�������캯������ʹ�õ��Ǳ��������ɵ�Ĭ�ϵĿ������캯��
	//��Ĭ�ϵĿ������캯���ǰ���ֵ�÷�ʽ���п�����������s1�����е�����ԭ�ⲻ���Ŀ����¶�����
	String s1("hello");
	String s2(s1);
	return 0;
}
#endif

#if 0
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//isLess��һ����Ա��������ҪData���͵Ķ�����е���
	//ע�⣺isLess��������Ҳ������ֵ�ķ�ʽ��ֻ��������ֵ�ķ�ʽ���Σ��ڴ���ʱ����ֵ�ķ�ʽ���У��ڴ���ʱ�ᴴ��һ����ʱ���󣬻�Ӱ������Ч��
	//һ������£���������Ϊ�����Ĳ���ʱ��һ�㶼�ǰ������õķ�ʽ���д��Σ��������Ҫͨ���βθı��ⲿʵ�Σ���Ҫ����const
	bool isLess(const Data& d)
	{
		if ((_year < d._year) || (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		return false;
	}

	//< �����������
	bool operator<(const Data& d)
	{
		if ((_year < d._year) || (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		return false;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 7);
	Data d2(2020, 8, 8);

	//Data���û��Զ�������ͣ��Զ������Ͱ��������Ա��������������֪������ʲô������бȽ�
	//1.���߱�������ζ��������͵Ķ�����бȽϣ���<�������������
	if (d1 < d2)
		cout << "d1 < d2" << endl;

	//2. �ṩ��һ�����еĺ��������бȽ�
	if (d1.isLess(d2))
	{
		cout << "d1 < d2" << endl;
	}
	return 0;
}
#endif

#if 0
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//==����
	bool operator==(const Data& d)
	{
		return _year == d._year &&
			   _month == d._month &&
			   _day == d._day;
	}

	//!=����
	bool operator!=(const Data& d)
	{
		return !(*this == d);
	}
private:
	int _year;
	int _month;
	int _day;
};

//ȫ�ֱ����еĲ�����
//+������������������������Ҫ�ṩ����������
//+���������������int���͵����ݣ�������������֧�֣��ٽ������ؾͶ��һ�٣����һ��γ������޵ĵݹ�
//����ڽ������������ʱ��������һ�������ͻ���ö�����͵Ĳ���
//int operator+(int left, int right)
//{
//	return left + right;
//}

enum DATA {ONE, TOW, THREE};

int opertaor + (DATA op1, int op2)
{
	return op1 + op2;
}

int main()
{
	Data d1(2020, 8, 7);
	Data d2(d1);

	if (d1 == d2)
		cout << "d1 == d2" << endl;
	else
		cout << "d1 != d2" << endl;
}
#endif
class Data
{
public:
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 7);
	Data d2(2020, 8, 8);

	d2 = d1;
	return 0;
}