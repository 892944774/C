#include <iostream>
using namespace std;
#include <string.h>

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

public:
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
