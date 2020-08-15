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
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Data(const Data& d):" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

//��ֵ�ķ�ʽ���������͵Ķ����ڴ����ڼ����������ÿ������캯��������һ����ʱ����
//ȱ�ݣ����������Ч�ʵ�
void TestData1(Data dd)
{}

//һ������º���ʹ����ֵ�ķ�ʽ���������͵Ĳ�����һ�㶼��ʹ�����õķ�ʽ��Ϊ��������
//�ŵ㣺����һ�ο�������ĵ��ã�����Ч�ʸ�
//ȱ�㣺�޸��βξ��Ǹı��ⲿʵ��
void TestData2(const Data& dd)
{}

Data TestData3()
{
	Data d;
	return d;
}

//�ڷ���ֵ�ڼ䣬���ù��캯��������һ������������Ϊ����������û�����֣�Ҳ�ò����ö���ĵ�ַ��
//����޷���������޸ģ���˱��������������󵱳�һ����ʱ�����������з���
Data TestData4()
{
	return Data(2020,8,8);//������һ��û�����ֵĶ���---��������
}

int main()
{
	Data d(2020, 8, 8);
	TestData1(d);
	TestData3();
	TestData4();
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
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Data(const Data& d):" << this << endl;
	}

	//ִ�е���ǰ��++����
	Data& operator++()
	{
		_day += 1;
		return *this;
	}

	//����++
	//ע�⣺temp�Ǻ���ջ�ϵĶ��󣬵������˳�ʱ��temp��Ҫ�����ٵ�
	//��˺���++�ĺ�������ֵ����ʹ�����õķ�ʽ���з��أ�ֻ�ܰ���ֵ�ķ�ʽ���з���
	//�﷨Ϊ�����ֺ���++��ǰ��++��������ص�����
	//�����ں���++�Ĳ����б���������һ��int���͵Ĳ���,��ʵ�ʺ���������int���Ͳ�������ʹ��
	Data operator++(int)
	{
		Data temp(*this);
		_day += 1;
		return temp;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1(2020, 8, 8);
	Data d2;

	d2 = ++d1;//d2 = d1.operator++();

	d2 = d1++;//�൱��d2 = d1.operator++(0);
	return 0;
}
#endif

#if 0
//����Ҫ�з���ֵ��Ŀ����Ϊ��֧��������ֵ
Date& operator=(const Date& d)
{
	//�����Լ����Լ���ֵ--����this��d�Ƿ���ͬһ������
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return &*this;
}
#endif

//const���εı���
/*
��C�����У���const���ε���һ�����ܱ��޸ĵı���
���ԣ�const int a = 10;  int array[a];//���뱨��
��C++�У���const���ε��Ѿ���һ�����������Ҿ��к��滻������
void TestConst()
{
	const int a = 10;
	int* pa = (int*)&a;

	*pa = 100;
	cout << a << endl;//10 ����a��ֵ�Ѿ���100��ԭ�����ڱ���׶Σ��������Ѿ���a��10�滻��
	cout << *pa << endl;//100
}
const���γ������滻�����ڱ���׶Σ������������͵ļ�⣬����İ�ȫ�Ը��ߡ�
��C++�н���ʹ��const���εĳ�������곣��
*/

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//��const���εĳ�Ա������Ϊconst���͵ĳ�Ա����
	//const��Ա�����в����޸���ġ���Ա������
	//const���������ε��ǳ�Ա�������ص�thisָ��
	//��ʾ��thisָ��ָ��Ŀռ��е����ݲ��ܱ��޸ģ�����thisָ��ǰ�������޸�
	void PrintDate()const
	{
		
		cout << _year << "-" << _month << "-" << _day << endl;
		//_day++;//��const���Σ����ܱ��޸�
		cout << typeid(this).name() << endl;
	}

	//const�ڷ���ֵ����֮ǰ�����ε��Ǹú����ķ���ֵ
	//��ͨ��Ա�����У������޸�thisָ��ĵ�ǰ�����������Ϣ
	const Date& GetDate()
	{
		_day++;
		cout << typeid(this).name() << endl;
		return *this;
	}
	/*
	C++�����Ի���
	�����ϣ���const���εĳ�Ա�����в����޸��κε�"��Ա����"������Щ����£�������Ҫ��const��Ա�������޸ĸ����Ա����
	*/

private:
	int _year;
	int _month;
	int _day;
	//mutable int _day;
};

int main()
{
	Date d(2020,8,8);
	d.PrintDate();
	d.GetDate();
	return 0;
}
#endif

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//Date* const this
	Date* operator&()
	{
		cout << this << endl;
		return this;
	}

	//const���γ�Ա����������������thisָ��
	//thisָ�����ͣ�const Date* const this
	const Date* operator&()const
	{
		return this;
	}

	void SetDay(int day)
	{
		_day = day;
	}

	int GetDay()const
	{
		return _day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	const Date d1(2020, 8, 8);
	d1.PrintDate();

	//d1��const���͵Ķ��󣬼�d1����ĳ�Ա���ܱ��޸ģ�������������ͨ���͵ĳ�Ա�������п��ܱ��޸�
	//���const���͵Ķ���ֻ�ܵ���const���͵ĳ�Ա���������ܵ�����ͨ���͵ĳ�Ա����
	//d1.SetDay(9);
	
	Date d2(2020,8,9);
	d2.GetDay(9);
	return 0;
}