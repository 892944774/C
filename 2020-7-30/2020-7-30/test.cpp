#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>

#if 0
void TestFunc(int a)
{
	cout << "TestFunc(int)" << endl;
}

void TestFunc(int* pa)
{
	cout << "TestFunc(int*)" << endl;
}

int main()
{
	int a = 0;
	int* pa = &a;

	int* pb = NULL;

	TestFunc(0);//��ֵΪ0��Ӧ�õ��õ��ǵ�һ������
	TestFunc(NULL);//���ݵ���һ��ָ�����ͣ�Ӧ�õ��õ��ǵڶ�������,����λ��ʵ�ʵ��õ����������͵�func����
				   //ʵ���Ͽ�ָ��Ķ�����һ����#define NULL 0
				   //���ʵ�ʵĵ��ù�����TestFunc(NULL)-->Ԥ����׶� ����>TestFunc(0);
				   //���ʹ��nullptr��ʾָ��Ϊ��
	return 0;
}
#endif

#if 0
//Studet���Կ�����һ��ѧ��Ⱥ�����ͣ���˿����ø����Ͷ������
struct Student
{
	char _name[20];
	char _gender[3];
	char _school[20];
	int  _age;

	void SetStudentInfo(char name[], char gender[], char school[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		strcpy(_school, school);
		_age = age;
	}

	void PrintfStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _school << "-" << _age << endl;
	}
};

int main()
{
	Student s1, s2, s3;//���ඨ�����s1, s2, s3��ѧ������
	s1.SetStudentInfo("����", "��", "�ʵ�", 22);
	s2.SetStudentInfo("����", "��", "����", 32);
	s3.SetStudentInfo("����", "Ů", "�廪", 23);

	s1.PrintfStudentInfo();
	s2.PrintfStudentInfo();
	s3.PrintfStudentInfo();
	return 0;
}
#endif

#if 0
class Student
{
private:
	//���ԣ���������ѧ���Ļ�����Ϣ��һ�㲻��������֪��
	char _name[20];
	char _gender[3];
	char _school[20];
	int  _age;

public:
	void SetStudentInfo(char name[], char gender[], char school[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		strcpy(_school, school);
		_age = age;
	}

	void PrintfStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _school << "-" << _age << endl;
	}
};

int main()
{
	Student s1, s2, s3;//���ඨ�����s1, s2, s3��ѧ������
	s1.SetStudentInfo("����", "��", "�ʵ�", 22);
	s2.SetStudentInfo("����", "��", "����", 32);
	s3.SetStudentInfo("����", "Ů", "�廪", 23);

	s1.PrintfStudentInfo();
	s2.PrintfStudentInfo();
	s3.PrintfStudentInfo();
	return 0;
}
#endif

#if 0
//���еĳ�Ա������ֻ���ڳ�Ա������ʹ�ã����еĳ�Ա����Ҳ�������е�ȫ�ֱ���
class Test
{
public:
	void SetTest(int a)
	{
		_a = a;
	}

	void Printtest()
	{
		cout << _a << endl;
	}

private:
	int _a;//�ó�Ա�������������������ж�����ʹ�ã�
	//��˳�Ա�����Ϳ��Ե��ɸ����Ա�����е�ȫ�ֱ���
};

int main()
{
	Test s;//s������ʵ�����Ľ��
	return 0;
}
#endif

#if 0
class Student
{
public:
	void SetStudentInfo(char name[], char gender[], char school[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		strcpy(_school, school);
		_age = age;
	}

	void PrintfStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _school << "-" << _age << endl;
	}

private:
	//���ԣ���������ѧ���Ļ�����Ϣ��һ�㲻��������֪��
	char _name[20];
	char _gender[3];
	char _school[20];
	int  _age;
};

int main()
{
	Student s;//���ඨ�����s��ѧ������
	
	//Ҫ���Student������ж������֪�������а�������Щ��Ա
	//s. �ķ�ʽ
	return 0;
}
#endif

#if 0
class A1 {
public:
	void f1() {}
public:
	int _a;
	char _b;
};

// ���н��г�Ա����
class A2 {
public:
	void f2() {}
};

// ����ʲô��û��---����
class A3
{};

int main()
{
	cout << sizeof(A1) << endl;//8
	cout << sizeof(A2) << endl;//1
	cout << sizeof(A3) << endl;//1,��Ϊû�г�Ա��������������Ĵ�С�����0����ʵ����1

	cout << offsetof(A1, _b) << endl;//��_�������ʼλ�õ�ƫ����
	return 0;
}
#endif

//ÿ�����Ա��������һ��Ĭ�ϵĲ������ò���ʱʱ�̿�ָ����øó�Ա�����Ķ��󣬽��ò�����Ϊthisָ��
//thisָ���Ǳ������ڱ����ڼ��Զ����ϵģ��û�����Ҫ��ӣ�Ҳ����Ҫ����
class Student
{
public:
	void SetStudentInfo(/*Student* const this, */char name[], char gender[], int age)
	{
		cout << this << endl;
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintfStudentInfo(/*Student* const this*/)
	{
		cout << /*this->*/_name << "-" << /*this->*/_gender << "-" << /*this->*/_age << endl;
	}

	void TestFunc(...) //��ʾ��������
	{}
private:
	//���ԣ���������ѧ���Ļ�����Ϣ��һ�㲻��������֪��
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	Student s1, s2, s3;//���ඨ�����s1, s2, s3��ѧ������

	//����ѧ��������ó�Ա����
	cout << &s1 << endl;
	s1.SetStudentInfo("����", "��", 22);

	cout << &s2 << endl;
	s2.SetStudentInfo("����", "��", 32);

	cout << &s3 << endl;
	s3.SetStudentInfo("����", "Ů", 23);

	//thisָ��Ĵ��ݷ�ʽ
	// 1 �ò������б��������ݵ�
	// 2 һ������ò�����ͨ��ecx�Ĵ��������ݵ�
	// 3 �����������ͨ������ѹջ�ķ�ʽ����
	// ע�⣺һ������³�Ա�������Ǳ�this_call����Լ�����εģ�����this_call����Լ�����εĳ�Ա����
	//      thisָ����ͨ��exc�Ĵ������ݣ���_cdecl����Լ�����εĺ�����this��ͨ������ѹջ�ķ�ʽ���ݵ�
	s1.PrintfStudentInfo();
	s2.PrintfStudentInfo();
	s3.PrintfStudentInfo();
	return 0;
}

#if 0
//��c���Եķ�ʽʵ����������
struct Student
{
	char name[20];
	char gender[3];
	int age;
};

void SetStudentInfo(Student* ps, char name[], char gender[], int age)
{
	strcpy(ps->name, name);
	strcpy(ps->gender, gender);
	ps->age = age;
}

void PrintfStudentInfo(Student* ps)
{
	printf("%s %s %d\n", ps->name, ps->gender, ps->age);
}

int main()
{
	Student s1, s2, s3;
	SetStudentInfo(&s1, "����", "��", 23);
	SetStudentInfo(&s2, "����", "��", 24);
	SetStudentInfo(&s3, "����", "��", 25);

	PrintfStudentInfo(&s1);
	PrintfStudentInfo(&s2);
	PrintfStudentInfo(&s3);
	return 0;
}
#endif