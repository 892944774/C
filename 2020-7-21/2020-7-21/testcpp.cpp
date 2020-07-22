#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//������C++���̣�������Ҫ����C���Եķ�ʽ�������
#if 0
extern "C" int Add(int left, int right);

int main()
{
	Add(1, 2);
	return 0;
}
#endif

//����& ���õı��� = ����ʵ��;
#if 0
void TestRef()
{
	int a = 10;
	//ra����a�ı���,ra��a�ڵײ���ǹ���һ��ʵ�壬������һ���ڴ�ռ�
	int& ra = a;
	cout << &a << " " << &ra << endl;//0058F6A4 0058F6A4
}

void SetNULLPtr(int*& p)
{
	p = NULL;
}

void SetNULLPtr(int** p)
{
	//*p����ʵ�α��� 
	*p = NULL;
}

int main()
{
	int a = 10;
	int* pa = &a;
	*pa = 20;

	SetNULLPtr(pa);
	SetNULLPtr(&pa);
	TestRef();
	return 0;
}
#endif

//������-->const���͵�����
#if 0
int main()
{
	const int a = 10;//a�ǲ��ܱ��޸ĵ�
	const int& ra = a;//��ȷ

	//int& ra = a;//����
	             //�����ͨ���͵����ñ���raȥ����a�������޸�a�������޸�ra��ͻ��a�޸ĵ�
	
	double d = 12.34;
	//double& rd = d;//��ȷ
	// rd = 23.34;

	const int& rd = d;//�������ʹ�����һ����ʱint�ͱ�����
	               //rd�Ͳ���ֱ�����ã���int��double����֮����Է�����ʽ����ת��
	             //��ʱ�ռ���г���---���ܱ��޸ģ���˱�����ʹ��const int&������
	return 0;
}
#endif

#if 0 
int main()
{
	int a = 10;//��a����֮�󣬱�������a������һ���ڴ�ռ�
	int& ra = a;//ra���������͵ı������ڶ���ʱ�������������ra����һ���ڴ�ռ䣬���Ǻ�a����һ���ڴ�ռ�

	cout << typeid(a).name() << endl;
	cout << typeid(ra).name() << endl;
	return 0;
}
#endif

#include <ctime>

struct A
{
	int array[10000];
};

void TestValue(A a)
{}

void TestRef(A& a)
{}

void TestPtr(A* a)
{}

void TestFunc()
{
	A a;

	//��ֵ���ڴ����ڼ���Ҫ����ʵ�ε�һ�ݿ���
	size_t begin1 = clock();
	for (int i = 0; i < 100000; i++)
		TestValue(a);
	size_t end1 = clock();

	//�����Ǳ������ڴ����ڼ䲻��Ҫ���п���
	size_t begin2 = clock();
	for (int i = 0; i < 100000; i++)
		TestRef(a);
	size_t end2 = clock();

	//��ָ�룬�ڴ����ڼ䲻��Ҫ���ж���Ŀ���--�������Ƕ���ĵ�ַ--32λƽ̨�ĸ��ֽ�
	size_t begin3 = clock();
	for (int i = 0; i < 100000; i++)
		TestRef(a);
	size_t end3 = clock();

	cout << "��ֵ���ܣ�" << end1 - begin1 << endl;//100
	cout << "���������ܣ�" << end2 - begin2 << endl;//1
	cout << "��ָ�����ܣ�" << end3 - begin3 << endl;//1
}

int main()
{
	TestFunc();
	return 0;
}