#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#if 0
//�����ռ�Ķ���
//N1��һ�������ռ�
//�����ռ䣺ʵ�ʾ���һ���������ֵ�������
namespace N1
{
	int a = 10;
	int ADD(int left, int right)
	{
		return left + right;
	}
}

//�����ռ�֮�����Ƕ��
namespace N2
{
	int a = 50;
	int Mul(int left, int right)
	{
		return left + right;
	}

	namespace N3
	{
		int a = 30;
		int Sub(int left , int right)
		{
			return left + right;
		}
	}
}

//::�����������
int a = 20;

int main()
{
	int a = 10;
	printf("%d\n", a);//�������a
	printf("%d\n", ::a);//���ʵ���ȫ���������е�a
	printf("%d\n", N1::a);//����N1�������ռ��е�a

	N1::ADD(10,90);
	printf("%d\n", N2::N3::a);
	return 0;
}
#endif

#if 0
//��C++�У�һ�������п��Գ�����ͬ�������ռ�,���������ս���ͬ���ռ�����ݺϲ���һ��
namespace N
{
	int a = 10;
	int ADD(int left, int right)
	{
		return left + right;
	}
}

namespace N
{
	int b = 20;
	int Sub(int left, int right)
	{
		return left + right;
	}
}

int main()
{
	printf("%d\n", N::a);
	printf("%d\n", N::b);
	return 0;
}
#endif 

//�����ռ��ʹ��
//1 ֱ���ڳ�Աǰ���� N::
//2 using N::a ,�൱�ڽ�a����ȫ�ֱ���ʹ��
//3 using namespace N;�൱�ڽ�N�����ռ��е����г�Ա���ɵ�ǰ�ļ��е�ȫ�ֱ���ʹ��
namespace N
{
	int a = 10;
	int ADD(int left, int right)
	{
		return left + right;
	}
}

//�൱�ڽ�a����ȫ�ֱ���
//ע�⵱ǰȫ������������a,����������ͻ
//using N::a;
using namespace N;

int main()
{
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);

	printf("%d\n", a);
	ADD(10, 20);
	return 0;
}
