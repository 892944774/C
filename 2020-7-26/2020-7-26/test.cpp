#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std; 

#if 0
void  Swap(int& left, int& right)
{
	int temp = left;
	left = right;//����������
	right = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	int* pb = NULL;
	*pb = 100;//�Կ�ָ������ã�����ִ���ڼ����
	//�ڴ���ʱ���������ǰ���ֵ�ķ�ʽ���ݣ�
	//���ڱ������ڱ������ʱ����⵽Swap�������������͵Ĳ���ת��Ϊָ��
	//��ˣ�Swap(a,*pb)-->����ɣ�Swap(&a, pb)
	Swap(a, *pb);//���Ǹ�λ�õĿ�ָ�룬������ִ���ڼ�û�б���
	return 0;
}
#endif

//��C++�б�const���εı������к��滻�Ĺ���
//�꣺��Ԥ����׶η����滻--���뻹û�б���--������ֱ���滻������������ͼ�⣬���԰�ȫ�Բ���
//const���Σ����ڱ���׶ν����滻������в������ͼ�⣬��ȫ�Ը�
#if 0
int main()
{
	const int a = 10;
	int* pa = (int*)&a;
	*pa = 100;

	cout << *pa << endl;//100
	cout << a << endl;//10  const���ε�a�ڱ���ǰ�Ѿ����滻��10��
	return 0;
}
#endif

//��C++�У���inline���εĹؼ��ֳ�Ϊ��������
//�����������ԣ��ڱ����������ڼ䣬���������������������չ�������˺������õĿ�����������߳��������Ч��
#if 0
inline int Add(int left, int right)
{
	return left + right;
}

int main()
{
	int sum = Add(2,3);

	//�����������������ʲôչ����
	//���û��չ����sum = Add(a,b);�ڸ�����е���Add��������call Addָ��
	//���������չ�����������Ѿ���Add�����ĺ������滻�˺�������
	//Debugģʽ�¡�Ĭ���ǲ���չ���ġ���ΪDebugΪ����ģʽ���������չ�����Ͳ��ܽ��е���
	//��Ҫ֪��չ����Ҫ��������
	cout << sum << endl;
	return 0;
}
#endif

int main()
{
	//����auto��Ӱ����ʱ������Ա������г�ʼ��
	//��Ϊ�������ڱ����ڼ�Ҫ���ݱ����ĳ�ʼ�����ʽ�����ݸñ�����ʵ�ʱ��ʽ
	//����ʵ���������ݳ���֮���滻auto
	auto a = 10;
	auto b = "1234";
	auto c = 12.34;
	auto d = a + 10;

	cout << typeid(a).name() << endl;//int
	cout << typeid(b).name() << endl;//char const *
	cout << typeid(c).name() << endl;//double
	cout << typeid(d).name() << endl;//int
	return 0;
}