#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~test():" << this << endl;
	}

private:
	int _t;
};

void TestFunc()
{
	//��Ҫ�ڶ��Ͽ���һ���ڴ�ռ�,����Test���͵Ķ���
	Test* pt = (Test*)malloc(sizeof(Test));

	free(pt);
}
int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
int main()
{
	//�ռ�����
	//���뵥���ռ�
	int* p1 = new int;

	//���뵥�����Ϳռ䲢�����ʼ��
	int* p2 = new int(10);

	//����һ�������Ŀռ�
	int* p3 = new int[10];

	//����һ�������Ŀռ���г�ʼ��
	int* p4 = new int[10]{1,2,3,4,5,6,7,8,9,0}; 

	//�ͷſռ�
	//�ͷŵ������͵Ŀռ�
	delete p1;
	delete p2;

	//�ͷ��������͵Ŀռ�
	delete[] p3;
	delete[] p4;
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test()
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~test():" << this << endl;
	}

private:
	int _t;
};

int main()
{
	Test* pt1 = new Test;
	Test* pt2 = new Test[10];

	delete pt1;
	delete[] pt2;
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t)
		:_t(t)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~test():" << this << endl;
	}

private:
	int _t;
};

int main()
{
	Test* pt1 = new Test(10);
	Test* pt2 = new Test(20);

	delete pt1;
	delete pt2;
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t = 10)
		:_t(t)
	{
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~test():" << this << endl;
	}

private:
	int _t;
};

int main()
{
	//ע�⣺������������Ŀռ�ʱ��������Ǿ����޲εĻ�����ȫȱʡ�Ĺ��캯��
	Test* pt1 = new Test[10];

	delete pt1;
	return 0;
}
#endif

class Test
{
public:
	Test(int t = 10)
		:_t(t)
	{
		p = new int;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		delete p;
		cout << "~test():" << this << endl;
	}

private:
	int _t;
	int* p;
};

void TestFunc()
{
	//��malloc��������Ķ��󣬲�����delete���ͷ�
	//��Ϊ��malloc��������Ĳ���һ��Test���͵Ķ��󣬶�����Test���ʹ�С��ͬ��һ�οռ�
	//������ͷŸÿռ�ʱ������ʹ��delete�������ͷţ���Ϊ�ڴ����л������������
	//��������������Ҫ�Զ�����pָ��ָ��ռ��е����ݽ����ͷţ���malloc����Ŀռ�û�е�����������
	//��p1���г�ʼ����p1ָ��Ŀռ��е����������ֵ
	//Test* p1 = (Test*)malloc(sizeof(Test));
	//delete p1;//�������
}

int main()
{
	TestFunc();
	return 0;
}