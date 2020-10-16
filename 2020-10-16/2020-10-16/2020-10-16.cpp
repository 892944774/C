#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
#endif

#if 0
//Add����ģ��
template<class T>  //ģ��Ĳ����б���������
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	//�Ժ���ģ���ʵ����
	Add(1, 2);//int 
	Add(2.1, 3.2);//double
	Add('1', '2');//char
	return 0;
}
#endif

#if 0
template<class T>
void Swap(T left, T right)
{
	T temp = left;
	left = right;
	right = temp;
}

//�������͵�����
template<class T>
void PrintArray(T array[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << "-";
	}

	cout << endl;
}

int main()
{
	int array[] = {1,2,3,4,5,6};
	PrintArray(array, sizeof(array) / sizeof(int));

	double array[] = {1.1, 2.2, 3.3};
	PrintArray(array, sizeof(array) / sizeof(double));
	return 0;
}
#endif

#if 0
//����ģ�岻��һ������������һ��������ģ��
template<class T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	//��ʽʵ����
	//����ʽʵ�����У������������ɴ���ʱ���������ʽ����ת��
	Add(1, 2);//int
	//�ڵײ��еĺ���ʵ��
	/*int Add<int>(int left, int right)
	{
		cout << typeid(int).name() << endl;
		return left + right;
	}*/

	Add(1.0, 2.0);
	//�ڵײ��еĺ���ʵ��
	/*double Add<double>(double left, double right)
	{
		cout << typeid(double).name() << endl;
		return left + right;
	}*/

	//int��double֮�������ʽ����ת��
	Add(1, (int)2.0);

	//��ʾʵ����
	//�������ڱ�������ڼ䣬�����Ժ���ģ�������ʾʵ������
	//�������ʾʵ������T�ľ�������ֱ�����ɴ���
	//�پ�����õ�ʱ����ܻᷢ����ʽ����ת��
	Add<int>(1, 2.0);
	Add<double>(1, 2.0);

	//Add(int)(1, "hello");//error
	return 0;
}
#endif

#if 0
template<class T, class U>
T Add(T left, U right)
{
	return left + right;
}

int main()
{
	Add(1, 2.0);
	//�ڵײ��е�ʵ��
	/*int Add<int, double><int left, double right>
	{
		return left + right;
	}*/
	return 0;
}
#endif

#if 0
//����ģ�壺���Ա�ʵ���������Ͳ�ͬ�Ĳ���
template<class T1, class T2>
T1 Add(const T1& left, const T2& right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add<int>(1, 2.0);
	return 0;
}
#endif

//ģ�����͵Ķ�̬˳���
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}

	void PushBack(const T& data);

	void PopBack()
	{
		if (!Empty())
		{
			--_size;
		}
	}

	bool Empty()const
	{
		return _size == 0;
	}

	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	T& operator[](size_t index)const
	{
		assert(insex<_size);
		return _array[index];
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
void SeqList<T>::PushBack(const T& data)
{
	if (_size = _capacity)
	{
		//����
	}

	//β��
	_array[_size++] = data;
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,0};
	cout << array[2] << endl;
	array[2] = 10;

	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	cout << s1[2] << endl;//[]-->�±������

	const SeqList<int> s0;//������һ��˳���Ķ������ж�����Ԫ�ض���int��

	SeqList<double> s2;
	SeqList<Date> s3;
	return 0;
}