#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#include <map>
#include <string>

#if 0
int main()
{
	map<string, string> m1;

	m1.insert(pair<string, string>("orange", "����"));
	m1.insert(pair<string, string>("apple", "ƻ��"));
	m1.insert(pair<string, string>("banana", "�㽶"));
	m1.insert(make_pair("peach","����"));
	m1.insert(make_pair("watermelon", "����"));

	//��������Χfor
	for(auto& e : m1)
	{
		cout << e.first << "-" << e.second << endl;
	}

	//ͨ��key�����key��Ӧ��valueֵ��
	//�±���������ǲ��ң�Ҳ�ǲ���
	cout << m1["apple"] << endl;//ƻ��
	cout << m1["banana"] << endl;//�㽶

	m1["apple"] = "��";
	cout << m1["apple"] << endl;//��Apple��Ӧ��valueֵ��Ϊ��

	//ɾ��Ԫ��
	m1.erase("orange");

	//ɾ��ָ��Ԫ��
	auto pos = m1.find("orange");
	while (pos != m1.end())
	{
		m1.erase(pos);
	}

	m1.erase(m1.begin(), m1.end());//ɾ��ȫ��Ԫ��

	//������
	//map<string, string>::iterator it = m1.begin();
	cout << m1.size() << endl;
	auto it = m1.begin();
	while (it != m1.end())
	{
		cout << "<" << it->first << "," << it->second << ">"<< endl;
		++it;
	}

	//c++11
 	map<string, string> m2{ {"orange","����"},{"apple","ƻ��"},{"banana","�㽶"} };
	return 0;
}
#endif 

#if 0
#include <queue>
class Compare
{
public:
	bool operator()(const pair<string, size_t>& left, const pair<string, size_t>& right)
	{
		return left.second < right.second;
	}
};

int main()
{
	// ������ˮ��������Ա����ϲ���Ե�����ˮ��---CVTE������
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };

	//1.ͳ��ÿ��ˮ�����ֵĴ���
	map<string, size_t> m;
	for (auto& e : fruits)
	{
		m[e]++;
	}

	//2. �ҳ�Ա����ϲ���Ե�K��ˮ����TOP-K,priority_queue����
	// ʹ��map�е�Ԫ�ع���һ�����---->���ռ�ֵ���еĴ������бȽ�
	priority_queue<pair<string, size_t>, vector<pair<string, size_t>>, Compare> q(m.begin(), m.end());
	
	// ȡ��Ա����ϲ���Ե�����ˮ��
	vector<string> favourite;
	for (size_t i = 0; i < 3; i++)
	{
		favourite.push_back(q.top().first);
		q.pop();
	}
	return 0;
}
#endif

#if 0
#include <set>
int main()
{
	string fruits[] = { "apple", "apple", "apple", "apple", "apple", "orange", "orange", "banana", "apple", "orange", "banana", "peach", "banana", "watermelon", "banana", "banana" };
	multiset<string> s;
	for (auto& e : fruits)
	{
		cout << e << " ";
	}
	cout << endl;
	s.insert(fruits, fruits+sizeof(fruits)/sizeof(fruits[0]));
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
#endif

#include "AVLTree.hpp"
int main()
{
	TestAVLTree1();
	TestAVLTree2();
	return 0;
}