#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

#if 0
int main()
{
	string s("12345");
	int value = atoi(s.c_str());

	string s1("hello");
	char* p = (char*)s1.c_str();
	*p = 'H';

	cout << sizeof(string) << endl; 
	return 0;
}
#endif

#if 0
int main()
{
	string s1("hello");
	string s2("world");

	if (s1 < s2)
	{
		cout << "s1 < s2" << endl;
	}
	else
	{
		cout << "s1 >= s2";
	}
	return 0;
}
#endif

#include <string>
#if 0
int main()
{
	string s;
	//cin >> s;
	//cout << s << endl;

	//getline(cin, s);
	//cout << s << endl;

	//ѭ������
	while (getline(cin, s))
	{
		cout << s << endl;
	}
	return 0;
}
#endif

#include <algorithm>
#if 0
int main()
{
	string s("hello");

	reverse(s.begin(), s.end());//����
	sort(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
#endif

#if 0
int main()
{ 
	string s("hello");
	//������ʽ1��ʹ�÷ǳ�Ƶ��
	for (size_t i=0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}

	//������ʽ2
	for (auto e : s)
		cout << e << "";
	cout << endl;

	//������ʽ3--���������
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
#endif

#if 0
//����
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//������Ĭ�ϵ��ǿ������캯��--ǳ����
	String(const String& s)
		: _str(s._str)
	{}

	//���������ɵ�Ĭ�ϸ�ֵ���������--ǳ����
	String& operator=(const String& s)
	{
		_str = s._str;
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;

};

int main()
{
	String s1("hello");
	String S1(nullptr);
	return 0;
}
#endif

// ע�⣺ �������漰����Դ(���ڴ�ռ䡢�ļ�ָ���)����ʱ
//�û�����Ҫ��ʽʵ�ֿ������캯������ֵ��������ء���������---three big
//���ǳ����
//��ʽһ�����--��ͳ��
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str)+1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

int main()
{
	String s1("hello");
	String S1(nullptr);
	return 0;
}