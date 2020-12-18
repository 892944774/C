#pragma once

<<<<<<< HEAD
#if 0
=======
>>>>>>> d605849ff67a22563680907e8ed16041240f4436
template <class T>

//�������ڵ�ģ��
struct BSTNode
{
	BSTNode(const T& val = T())
		: left(nullptr)
		, right(nullptr)
		, data(val)
	{}

	BSTNode<T>* left;
	BSTNode<T>* right;
	T data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		: root(nullptr)
	{}

	~BSTNode()
	{
		_Destroy(root);
	}

	bool Insert(const T& data)
	{
		if (nullptr == root)
		{
			root = new Node(data);
			return true;
		}

		//BSTree�ǿ�
		//1 �Ҵ�����ڵ������е�λ�ã�����Ҫ��¼��parent��λ��
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data == cur->data)
				return false;
			else if (data < cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}

		//2 �����½ڵ�
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;

		return true;
	}

	Node* find(const T& data)
	{
		Node* cur = root;
		while (cur)
		{
			if (data == root->data)
				return cur;
			else if (data < root->data)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return nullptr;
	}

	//��Ҫ�����������֤BSTree����ȷ��
	void Inorder()
	{
		_Inorder(root);
	}

	bool Erase(const T& data)
	{
		if (root == nullptr)
			return false;

		//BSTree�ǿ�
		//1�Ҵ�ɾ�ڵ���BSTree�е�λ�ã���������˫��
		Node* parent = nullptr;
		Node* cur = root;
		while (cur)
		{
			if (cur->data == data)
				break;
			else if (cur->data < data)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				parent = cur;
				cur = cur->left;
			}
		}
		
		//ֵΪdata�Ľڵ㲻����
		if (cur == nullptr)
			return false;

		//2 ɾ���ڵ�
		//cur���ֻ���Һ��ӻ���Ҷ�ӽڵ�
		if (nullptr == cur->left)
		{
			if (nullptr == parent)
				root = cur->right;

			else
			{
				if (cur == parent->left)
					parent->left = parent->right;
				else
					parent->right = cur->right;
			}
		}

		else if (nullptr == cur->right)
		{
			//curֻ������
			if (nullptr == parent)
			{
				root = cur->left;
			}
			else
			{
				if (cur == parent->left)
					parent->left = cur->left;
				else
					parent->right = cur->left;
			}
		}

		else
		{
			//cur���Һ��Ӿ�����
			//������ڵ�--������������������ڵ�
			Node* del = cur->right;
			parent = cur;
			while (del->left)
			{
				parent = del;
				del = del->left;
			}

			// ������ڵ��е�ֵ�򽻸�֮ǰҪɾ����cur
			cur->data = del->data;

			// �൱�ڱ��Ҫɾ��del
			if (del == parent->left)
				parent->left = del->right;
			else
				parent->right = del->right;

			cur = del;
		}
		delete cur;
		return true;
	}

private:
	void _Inorder(Node* pRoot)
	{
		if (pRoot)
		{
			_Inorder(pRoot = pRoot->left);
			cout << pRoot->data << " ";
			_Inorder(pRoot = pRoot->right);
		}
	}

	void _Destroy(Node*& pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->left);
			_Destroy(pRoot->right);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	Node* root;
};

void Test()
{
	int a[] = {5,4,3,1,7,8,9,0,2};
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.Inorder();
<<<<<<< HEAD
}
#endif 

#if 0
class Person
{
protected:
	string _name; // ����
	string _sex; // �Ա�
	int _age; // ����
};

class Student : public Person
{
public:
	int _No; // ѧ��
};

void Test()
{
	Student sobj;
	// 1.���������Ը�ֵ���������/ָ��/����
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	//2.��������ܸ�ֵ�����������
	sobj = pobj;
	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
	pp = &sobj
		Student* ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
	ps1->_No = 10;
	pp = &pobj;
	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
	ps2->_No = 10;
}
#endif 

#if 0
// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};
#endif 

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
public:
	int _b;
};

class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived" << endl;
	}
	int _d;
};

void test()
{
	Base B;
	Derived D;
	Base& B = D;
	//ͨ����������ָ��������ã�ָ��������Ķ���ֻ�ܷ��ʻ���ĳ�Ա����
	B._b;
=======
>>>>>>> d605849ff67a22563680907e8ed16041240f4436
}