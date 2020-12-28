#pragma once

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& x)
		: left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, data(x)
		, bf(0)
	{}

	AVLTreeNode<T>* left;
	AVLTreeNode<T>* right;
	AVLTreeNode<T>* parent;
	T data;
	int bf;//ƽ������
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _root(nullptr)
	{}

	bool Insert(const T& data)
	{
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}
	}

	//�ǿ�
	//1. ���ն����������Ĺ�������½ڵ�
	//���½ڵ������еĲ���λ�ã�����¼��˫��
	Node* cur = _root;
	Node* parent = nullptr;
	while (cur)
	{
		parent = cur;
		if (data < cur->data)
			cur = cur->left;
		else if (data > cur->data)
			cur = cur->right;
		else
			return false;
	}

	//�½ڵ�����λ���Ѿ��ҵ�--�ҵ��½ڵ�
	cur = new Node(data);
	if (data < parent->data)
		parent->left = cur;
	else
		parent->right = cur;

	cur->parent = parent;

	while (parent)
	{
		//�½ڵ����֮��AVL����ƽ���Կ��ܻ��⵽�ƻ����������ƽ������
		if (cur == parent->left)
			parent->bf--;
		else
			parent->bf++;

		if (0 == parent->bf)
			return true;
		else if (1 == parent->bf || -1 == parent->bf)
		{
			cur = parent;
			parent = cur->parent;
		}
	}

private:
	Node* _root;
};