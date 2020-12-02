#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
class Person
{
public:
	virtual void Buyticket()
	{
		cout << "ȫ��Ʊ" << endl;
	}
};

class Derived : public Person
{
public:
	virtual void Buyticket()
	{
		cout << "���Ʊ" << endl;
	}
};

//�ڱ���������׶Σ��������޷�֪�������Ǹ���Ķ���
//ֻ���ڳ������н׶βŻ�֪��pbָ������ĸ���Ķ���
void TestVirtual(Person * pb)
{
	pb->Buyticket();//call Base::BuyTicket()
}

int main()
{
	Person p;
	Derived d;
	TestVirtual(&p);
	TestVirtual(&d);
	return 0;
}
#endif

#if 0
class A
{
public:
	A(int a)
		: _a(a)
	{}

	virtual ~A()
	{
		cout << "~A()" << endl;
	}
protected:
	int _a;
};

class B : public A
{
public:
	B(int a,int b)
		: A(a)
		, _b(b)
	{
		_p = new int[10];
	}

private:
	~B()
	{
		delete[] _p;
	}
protected:
	int _b;
	int* _p;
};

int main()
{
	A* pa = new B(1, 2);

	delete pa;
	pa = nullptr;
	return 0;
}
#endif

#if 0
//override :C++11 �������ӵĹؼ��֣��ñ���������׶μ���û��Ƿ񽫻����麯����д�ɹ�
class A
{
public:
	virtual void Test1()
	{
		cout << "A::Test()" << endl;
	}

	virtual void Test2()
	{
		cout << "A::Test()" << endl;
	}
};

class B : public A
{
public:
	virtual void Test1()
	{
		cout << "B::Test1()" << endl;
	}

	virtual void Test2()
	{
		cout << "B::Test2()" << endl;
	}

	/*virtual void Test3() override
	{
		cout << "B::Test()" << endl;
	}*/
};

void Test(A& pb)
{
	pb.Test1();
	pb.Test2();
}

int main()
{
	A a;
	B b;
	Test(a);
	Test(b);
	return 0;
}
#endif 

//static�÷�

//static���ε�����������������г�ʼ��
#if 0
class Test
{
public:
	static int count;
};

int Test::count = 1;

int main()
{
	Test t;
	cout << t.count << endl;
	return 0;
}
#endif

//���ж�����һ��static���Ա
#if 0
class Test
{
public:
	static int count;
};

int Test::count = 1;

int main()
{
	Test t1;
	Test t2;

	t1.count = 10;
	//t1����count��ֵ�޸ĺ�
	//t2��ȥ���ʵ�ʱ��ֵҲ�͸ı��ˣ�Ҳ����˵static���εĳ�Ա�����ǹ���һ���ڴ�ռ��
	cout << t2.count << endl;
	return 0;
}
#endif

//���ܷ��ʷ�static�����Ա��ֻ�ܷ��� static���ε����Ա��
#if 0
class Test
{
public:
	static int fun()
	{
		return num;
	}

	static int count;
	int num = 1;
};

int Test::count = 1;

int main()
{
	Test t1;
	t1.fun();//error��fun����return���Ƿ�static���Ա ���return count����ȷ
	return 0;
}
#endif 

#if 0
class A
{
public:
	static A* GetIntrance(int a)
	{
		return new A(a);
	}

	static void Destroy(A* pa)
	{
		delete pa;
	}

private:
	A(int a)
		: _a(a)
	{}
protected:
	int _a;
};

int main()
{
	A* pa = A::GetIntrance(1);
	A::Destroy(pa);
	return 0;
}
#endif

#if 0
class Base
{
public:
	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}

	virtual Base* f2()
	{
		cout << "Base::f2()" << endl;
		return this;
	}

	virtual void f3()
	{
		cout << "Base::f3()" << endl;
	}

	void f4()
	{
		cout << "Base::f4()" << endl;
	}

	void f5()
	{
		cout << "Base::f5()" << endl;
	}

	virtual int f6()
	{
		cout << "Base::f6()" << endl;
		return 0;
	}

	int f7()
	{
		cout << "Base::f7()" << endl;
		return 0;
	}
};

class Derived : public Base
{
public:
	///////////////////////////////
	// ��д
	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}

	//Э��
	//�����麯�����ػ����ָ����������ã������麯�����������ָ���������
	virtual Derived* f2()
	{
		cout << "Derived::f2()" << endl;
		return this;
	}

	//////////////////////////////////////////////
	// ͬ������
	virtual void f3(int)
	{
		cout << "Derived::f3(int)" << endl;
	}

	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	void f5()
	{
		cout << "Derived::f5()" << endl;
	}

	char f7()
	{
		cout << "Base::f7()" << endl;
		return 0;
	}

	///////////////////////////////////////
	// ����ʧ�ܣ���Ϊû�й���Э��
	//virtual char f6()
	//{
	//	cout << "Derived::f6()" << endl;
	//	return 0;
	//}
};
#endif

#include <windows.h>
#if 0
class WashRoom
{
public:
	void ManWC()
	{
		cout << "�в�" << endl;
	}

	void WomanWC()
	{
		cout << "Ů��" << endl;
	}
};

//������---�������麯��������ǳ�����
class Person
{
public:
	//���麯��
	virtual void GoTOWC(Person& wc) = 0;
};

// ��������һ��Ҫ���̳е�
// ����̳�һ��������֮�����û����д����Ĵ��麯����������Ҳ�ǳ�����
class Man : public Person
{
public:
	virtual void GoTOWC(WashRoom& wc)
	{
		wc.ManWC();
	}
};

class Woman : public Person
{
public:
	virtual void GoTOWC(WashRoom& wc)
	{
		wc.WomanWC();
	}
};

void TestWC()
{
	Person* p = nullptr;
	WashRoom wr;
	for (size_t i = 0; i < 10; i++)
	{
		if (rand() % 2 == 0)
		{
			p = new Man;
		}
		else
		{
			p = new Woman;
		}
		
		p->GoTOWC(wr);
		delete p;

		Sleep(2000);
	}
}

int main()
{
	TestWC();
	return 0;
}
#endif

class Base
{
public:
	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}

	virtual void f2()
	{
		cout << "Base::f2()" << endl;
	}

	virtual void f3()
	{
		cout << "Base::f3()" << endl;
	}
	int _b;
};


class Derived :public Base
{
public:
	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}

	virtual void f3()
	{
		cout << "Derived::f3()" << endl;
	}

	virtual void f5()
	{
		cout << "Derived::f5()" << endl;
	}
	int _d;
};

#include <string>
typedef void(*PVF)();//����ָ��

void PrintfPVF(Base& b, const string& info)
{
	PVF* pVFT = (PVF*)(*(int*)(&b));
	//pVFT[0]();//���õ�һ��
	while (*pVFT)
	{
		*pVFT = nullptr;
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(Base) << endl;//8
	Base b;
	
	//PrintfPVF(b);
	PrintfPVF(b, "base virtual function table:");
	return 0;
}