#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;

//find ������ʵ��
//iterator find(iterator first, iterator last, const& data)
//{
//	while (first != last)
//	{
//		if (*first == data)
//			return first;
//
//		++first;
//	}
//	return last;
//}

#if 0
//https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;

		for (size_t i = 0; i<tokens.size(); ++i)
		{
			string& str = tokens[i];

			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(atoi(str.c_str()));
			}
			else
			{
				//strΪ������
				//s.topֻ�ǰ�ֵ��ֵ����right��û��ȡ��Ԫ��
				int right = s.top();
				s.pop();

				int left = s.top();
				s.pop();

				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;

				case '-':
					s.push(right - left);
					break;

				case '*':
					s.push(right * left);
					break;

				case '/':
					s.push(right / left);
					break;
				}
			}
		}
		return s.top();
	}
};
#endif

#if 0 
//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		//��ջ�ͳ�ջԪ�ظ���������ͬ
		if (pushV.size() != popV.size())
			return false;

		//��s��ģ����ջ�ͳ�ջ�Ĺ���
		stack<int> s;
		int outidx = 0;
		int inidx = 0;

		while (outidx < popV.size())
		{
			//ջ��Ԫ�غ�popV�е�Ԫ�رȽϣ��������ջ����ȳ�ջ
			while (s.empty() || s.top() != popV[outidx])
			{
				if (inidx < pushV.size())
					s.push(pushV[inidx++]);
				else
					return false;
			}

			//ջ��Ԫ�غͳ�ջԪ����ȣ���ջ
			s.pop();
			outidx++;
		}
		return true;
	}
};
#endif