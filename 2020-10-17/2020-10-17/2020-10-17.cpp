#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <string>

//����
#if 0
void TestStrings1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	string s4(10, 'a');

	string s5(100, 'b');

	string s6("hello", 10);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cin >> s1;
	cout << s1 << endl;
}
#endif 

//����
#if 0
void TestStirng2()
{
	string s1("hello");
	cout << s1.size() << endl;//5
	cout << s1.length() << endl;//5
	cout << s1.capacity() << endl;//15

	if (s1.empty())
	{
		cout << "���ַ���" << endl;
	}

	else
	{
		cout << "�ǿ��ַ���" << endl;
	}

	s1.clear();
	if (s1.empty())
	{
		cout << "���ַ���" << endl;
	}

	else
	{
		cout << "�ǿ��ַ���" << endl;
	}
}
#endif

//void resize(size_t n, char c)
//void resize(size_t n)
/*
s1.resize(20, '!');
����s1����Ч�ַ�Ϊsize ����Ϊcapacity
size > 20 ����Ч�ַ��������ٵ�20�����ڶ���������������
size < 20 ��s1����Ч�ַ��������ൽ20���������20-size���ַ�ʹ��!(�ڶ�������)�������
����ڶ�������û���ṩ����ʹ��0�������----����ʹ��
capacity > 20  �ײ㲻��Ҫ����
capacity < 20 �ٽ��ַ���������ʱ����Ҫ��������

��ʹ��resize���ַ���Ч��������ʱ��resize����������С�ײ������Ĵ�С
*/
#if 0
void TestString3()
{
	string s1("hello");

	//��s1�е��ַ����ӵ�10������������ã������
	s1.resize(10);

	//��s1����Ч�ַ����ӵ�32�����������22���ַ���$����ӣ��������ڼ��ַ�������
	s1.resize(32, '$');

	//resize������Ч�ַ��ĸ��������ǵײ��в�����С�ײ�ռ�Ĵ�С
	s1.resize(28, '&');
	s1 += "world";
	s1.resize(20);
	s1.resize(16);

	s1.resize(8);
}
#endif

//  void reserve(size_t newcapacity)
/*
���裺string���Ͷ���ԭ��������Ϊoldcapacity

newcapacity <= oldcapacity ��string���Ͷ���ײ��������С
��newcapacity > 15ʱ���ײ��������ᷢ���ı�
��newcapacity <= 15ʱ��string��Ὣ�ײ㶯̬���ٵĿռ��ͷŵ���ʹ���ڲ��ľ�̬����

newcapacity > oldcapacity����string���Ͷ���ײ����������
ʵ�����ӵ����newcapacityֻ��һ���ο�
*/
#if 0
void TestString4()
{
	string s1("hello");
	cout << sizeof(s1) << endl;

	//����
	s1.resize(10);
	s1.resize(12);
	s1.resize(20);
	s1.resize(42);

	//����
	s1.resize(32);
	s1.resize(28);
	s1.resize(20);
	s1.resize(13);
}
#endif

#if 0
void TestString5()
{
	string s1("hello");
	cout << s1[0] << endl;
	s1[0] = 'H';

	cout << s1.at(0) << endl;
}
#endif

#if 0
void TestString6()
{
	string s1("hello");
	cout << s1 << endl;

	s1.push_back(',');
	cout << s1 << endl;//hello,

	s1.append(1, '%');
	cout << s1 << endl;//hello,%

	s1.append(s1, 2, 3);
	cout << s1 << endl;//hello,%llo
}
#endif

#if 0
void TestString7()
{
	string s1("hello world !!!");
	s1.insert(s1.find(' ', 7), "$$$");//hello world$$$ !!!
	cout << s1 << endl;
}
#endif

void TestString8()
{
	string s;
	//cin >> s;  hello  world
	getline(cin, s);
	cout << s << endl;
	cout << s.substr(s.rfind(' ') + 1) << endl;//�Ӻ���ǰ�ҿո񣬼�1�ҵ��ո��ĵ�һ���ַ���Ȼ���ȡ�ַ�, world
	cout << s.substr(s.rfind(' ') + 1).size() << endl;//�Ӻ���ǰ�ҿո񣬼�1�ҵ��ո��ĵ�һ���ַ���Ȼ���ȡ�ַ�����,5
}

int main()
{
	//TestStrings1();
	//TestStirng2();
	//TestString3();
	//TestString4();
	//TestString5();
	//TestString6();
	//TestString7();
	TestString8();
	return 0;
}