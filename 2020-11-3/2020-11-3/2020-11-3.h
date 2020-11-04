#pragma once
#include <assert.h>

namespace bite
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public: 
		vector()
			: start(nullptr)
			, finish(nullptr)
			, endofstorage(nullptr)
		{}

		vector(int n, const T& data = T())
			: start(new T[n])
			, finish(start+n)
			, endofstorage(finish)
		{
			for (int i = 0; i < n; ++i)
				start[i] = data;
		}

		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			//ȷ���������ж��ٸ�Ԫ��
			size_t count = 0;
			Iterator it = first;
			while (it != last)
			{
				count++;
				++it;
			}

			//����ǰ���󿪱ٿռ䣬����ʼ����Ա����
			start = new T[count];
			finish = start;
			endofstorage = start + count;

			while (first != last)
			{
				*finish++ = *first++;
			}

		}
		
		vector(const vector<T>& v)
		{ 
			size_t vsize = v.size();
			start = new T[vsize];
			finish = endofstorage = start + vsize;
			for (size_t i = 0; i < visze; i++)
				start[i] = v[i];
		}

		~vector()
		{
			if (start)
			{
				delete[] start;
				start = nullptr;
				finish = nullptr;
				endofstorage = nullptr;
			}
		}

		///////////////////////////
		iterator begin()
		{
			return start;
		}

		iterator end()
		{
			return finish;
		}

		///////////////////////////////

		size_t size()const
		{
			return finish - start;
		}

		size_t capacity()const
		{
			return endofstorage - start;
		}

		bool empty()const
		{
			return start == finish;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
				finish = start + newsize;
			else
			{
				if (newsize > capacity)
				{
					reserve(newsize);
				}
				for (size_t i = oldsize; i < newcapacity; ++i)
				{
					start[i] = data;
				}
				finish = start + newsize;
			}
		}

		void reserve(size_t newcapacity)
		{
			size_t oldcapacity = capacity();
			size_t oldsize = size();
			if (newcapacity > oldcapacity)
			{
				//�����¿ռ�
				T* temp = new T[newcapacity];

				//����Ԫ��
				//memcpy(temp, start, i < oldcapacity*sizeof(T));
				for (size_t i = 0; i < oldsize; ++i)
				{
					temp[i] = start[i];
				}

				//�ͷžɿռ�
				delete[] start;

				start = temp;
				finish = start + oldsize;
				endofstorage = start + newcapacity;
			}
		}

		//////////////////////////////////////
		T& operator[](size_t index)
		{
			assert(index < size());
			return start[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < size());
			return start[index];
		}

		T& front()
		{
			return start[0];
		}

		const T& front()const
		{
			return start[0];
		}

		T& back()
		{
			return start[size()-1];
		}

		const T& back()const
		{
			return start[size()-1];
		}

		////////////////////////////
		void push_back(const T& data)
		{
			if (size() == capacity())
				reserve(2 * capacity()+3);

			*finish++ = data;
		} 

		void pop_back()
		{
			if (empty())
				return;

			--finish;
		}

		iterator insert(iterator pos, const T& data)
		{
			assert(pos <= end());
			if (size() == capacity())
				reserve(capacity()*2);

			auto it = end();
			while (it > pos)
			{
				*it = *(it - 1);
				--it;
			}

			*pos = data;
			++finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos<end());
			if (size() == 1)
			{
				pop_back();
				return end();
			}

			auto it = pos;
			while (it < end())
			{
				*it = *(it + 1);
				++it;
			}

			--finish;
			return pos;
		}

		void clear()
		{
			finish = start;
		}
	private:
		iterator* start; 
		iterator* finish;
		iterator* endofstorage;
	};
}

#include <iostream>
using namespace std;

#include <string>

void TestMyVector1()
{
	bite::vector<int> v1;

	bite::vector<int> v2(10, 5);

	for (size_t i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	int array[] = {1,2,3,4,5};
	bite::vector<int> v3(array, array+5);
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << "";
		++it;
	}
	cout << endl;

	std::string s("hello");
	bite::vector<char> vc(s.begin(), s.end());
	bite::vector<int> v4(v3);
	for (auto e : v4)
		cout << e << "";
	cout << endl;
}

void TestMyVector2()
{
	bite::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (auto e : v)
		cout << e << "";
	cout << endl;

	v.erase(v.begin());
	for (auto e: v)
		cout << e << "";
	cout << endl;

	v.clear();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void TestMyVector3()
{
	bite::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	cout << v[0] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;

	// capacity:9  size: 4
	v.resize(8, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(15, 6);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(20, 6);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(12);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}
