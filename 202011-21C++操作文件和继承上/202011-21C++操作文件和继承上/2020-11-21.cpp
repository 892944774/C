#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0 
int main()
{
	FILE* pf = fopen("1.txt", "wb");
	if (NULL == pf)
	{
		exit(0);
	}

	//�����Ƹ�ʽ��д�ļ�
	int a = 12345678;
	fwrite(&a, sizeof(a), 1, pf);
	char ch = -1;
	fwrite(&ch, 1, 1, pf);

	char sz[32] = {0};
	_itoa(a, sz, 10);//������ת��Ϊ�ַ�,10����
	fwrite(sz, 1, strlen(sz), pf);
	fclose(pf);

	return 0;
}
#endif

#if 0 
int main()
{
	int a = 12345678;
	char sz[32] = {0};
	_itoa(a, sz, 10);

	memset(sz, 0, 32);//�����ú�Ŀռ�ȫ������Ϊ0
	sprintf(sz, "%d", a);
	return 0;
}
#endif

#include <sstream>
#if 0
int main()
{
	int a = 12345678;
	stringstream ss;
	ss << a;

	string str;
	ss >> str;
	string ret = ss.str();

	ss.clear();
	ss.str("");
	double d = 12.34;
	ss << d;
	//ss >> str;

	ret = ss.str();
	cout << ret << endl;
	return 0;
}
#endif

#if 0
int main()
{
	stringstream ss;
	ss << "hello";
	ss << "     ";
	ss << "world!!!";

	string s;
	s = ss.str();
	cout << s << endl;
	return 0;
}
#endif

#include <string>

//  ����/����
#if 0
class Person
{
public:
	void Eat()
	{
		cout << "Eat" << endl;
	}

	void Sleep()
	{
		cout << "Sleep" << endl;
	}
private:
	string _name;
	string _gender;
	int _age;
};

//������/����
class Student : public Person
{
public:
	void Study()
	{
		cout << "study" << endl;
	}
private:
	int _stuid;
};

int main()
{
	Student s;
	s.Eat();//����
	s.Sleep();//����

	cout << sizeof(Student) << endl;//64
	return 0;
}
#endif

#if 0
class Person
{
public:
	void Eat()
	{
		cout << "Eat" << endl;
	}

	void Sleep()
	{
		cout << "Sleep" << endl;
	}
private:
	//�Ȳ���������ֱ��ʹ�ã�Ҳ������������ֱ��ʹ��
	string _name;
	string _gender;

protected:
	//����������ֱ��ʹ�ã�������������ֱ��ʹ��
	int _age;
};

//������/����
class Student : public Person
{
public:
	void Study()
	{
		//������protected��Ա�������п���ֱ��ʹ��
		//Ȩ�ޣ�protected
		_age = 19;

		//������private���εĳ�Ա�������в��ɼ�������ֱ��ʹ�ã�
		//_name = "zhangsen";//err
		cout << "study" << endl;
	}
private:
	int _stuid;
};

//����һ����������࣬��֤������protected������������ֱ��ʹ��
class A : public Student
{
public:
	int Test()
	{
		_age = 10;
		return _age;
	}
};

int main()
{
	A a;
	a.Test();
	a.Eat();
	int ret = a.Test();
	cout << ret << endl;
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive : protected Base
{
public:
	void test()
	{
		//������public���ε������е�Ȩ�ޱ��protected
		_pub = 10;

		//������protected���ε������е�Ȩ��û��
		_pro = 10;

		//������private���ε������е�Ȩ�޲��ɼ�
		//_pri = 10;
	}
};

class A : public Derive
{
public:
	void test()
	{
		_pub = 2;
		_pro = 3;
	}
};

int main()
{
	Derive d;
	//d._pub = 10;
	return 0;
}
#endif

//��ֵ���ݹ���ǰ�������public�̳з�ʽ
//1. ���������Ը����������и�ֵ������������
//2. �������ָ�Ż������ÿ���ֱ��ָ������Ķ���
//3. �����ָ�벻��ֱ��ָ�����Ķ���

//�����public�ļ̳з�ʽ��
//����ͻ���Ĺ�ϵ��is-a(��һ��)���Խ�������󿴳���һ���������
//����ģ�ͣ������г�Ա���ڴ��еķֲ���ʽ
#if 0
class Person
{
public:
	void Eat()
	{
		cout << "Eat" << endl;
	}

	void Sleep()
	{
		cout << "Sleep" << endl;
	}

	string _name;
	string _gender;
private:
	int _age;
};

class Student : public Person
{
public:
	void Study()
	{
		cout << "study" << endl;
	}

	int _stuid;
};

int main()
{
	//1. ���������Ը����������и�ֵ������������
	Person p;
	Student s;

	p = s;
	//s = p;//err

	//2. ����ָ��������ÿ���ֱ��ָ������Ķ���
	Person* pp = &s;
	Person& rp = s;

	//3. �����ָ�벻��ֱ��ָ�����Ķ��󣬵���ǿת����--����ȫ
	Student* ps = (Student*)&p;
	ps->_name = "zhangsen";
	ps->_gender = "��";
	ps->_stuid = 100;//��Ϊ������û�������Ա���������Խ����ú�ֵ����ȫ
	return 0;
<<<<<<< HEAD


=======
>>>>>>> 366348505fad10581a9f7775379c94dd164be008
}
#endif
