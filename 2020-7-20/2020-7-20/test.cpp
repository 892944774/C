#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�ɰ汾�У� �������ͷ�ļ������ #include <iostream.h>
//�°汾���� <iostream> + std(��׼�������ռ�)
//��׼���еĻ������ݶ�����std�ж����
#include <iostream>
using namespace std;

#if 0
int main()
{
	/*cout << 10 << endl;
	cout << " " << endl;
	cout << 20 << "" << endl;*/
	int a, b;
	float c;
	char d;

	cin >> a >> b;
	cout << a << b << endl;
	cin >> c;
	cout << c << endl;
	cin >> d;  
	cout << d << endl;
	return 0;
}
#endif

//ȱʡ����
#if 0
void TestFunc(int a = 10)
{
	cout << a << endl;
}

int main()
{
	TestFunc(100);//100
	TestFunc();//10
	return 0;
}
#endif

//ȱʡ��������
//1.ȫȱʡ���������в���������Ĭ��ֵ
//2.��ȱʡ���������ֲ�������Ĭ��ֵ
//ȫȱʡ����
#if 0 
void TestFunc1(int a = 10, int b = 20, int c = 30)
{
	cout << a <<" "<< b << " " << c << endl;
}

//��ȱʡ����
void TestFunc2(int a, int b = 20, int c = 10)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc1(100);//100, 20, 30
	TestFunc1();//10, 20, 30
	TestFunc2(10);//10 20 10
	TestFunc2(10, 30);//10 30 10
	return 0;
}
#endif 
//ȱʡ���������������Ͷ���ͬʱ��������Ϊ����Ĭ��ֵ��һ���Ļ�����������֪��ʹ���ĸ�
//��������
//void TestFunc(int a = 10)
//
//��������
//void TestFunc(int a = 10)
//{
//	cout << a << endl;
//}

//��������
#if 0 
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}

int main()
{
	Add(10,20);
	Add(10.0, 20.0);
	Add('1', '2');
	return 0;
}

int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

//�ڱ���������׶Σ���Դ��ݺ���ʵ�ε����ͽ������ݣ�Ȼ��������ݵĽ��ѡ���Ӧ���͵ĺ�������ת��
//ע�⣺
// ������ɺ�����к��ʵ��������صĺ�������ã�����ᷢ����ʽ����ת��--ת�����к��ʵ����ͽ��е��ã����򱨴�
int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add('1', '2');//char char -->��Add(char, char)������û�У�������Add(int, int),char��int����֮����Է�����ʽ����ת��
	return 0;
}
#endif

//c++���֧�ֺ������أ�

//ΪʲôC���Բ�֧�ֺ������أ�
//��Ϊc���ԶԺ������������ι���ǳ��򵥣�����ֻ���ں������������"_",������������Add(int a, int b)��Add(char a, char b),��C���Ա������������_Add()���ͺ�����������Ȼ��ʧ�ܡ�
int main()
{

	return 0;
}