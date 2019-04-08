#include "TPolinom.h"
#include "TPolinom.cpp"
//#include"polinom.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

class TTree
{
	struct tree {
		int key;
		TPolinom data;
		tree *left;  // ����� 
		tree *right; // ������
	};

	tree *NTree = NULL; // ����� ������
public:
	//�������� �� ������
	void treeprint(tree *tree)
	{
		if (tree != NULL) 
		{
			//cout << tree->field; //���������� ������ ������
			treeprint(tree->left); 
			treeprint(tree->right); 
		}
	}
	//�������� ���������
	void freemem(tree *tree)
	{
		if (tree != NULL) {
			freemem(tree->left);
			freemem(tree->right);
			delete tree;
		}
	}
	//��������
	void DeleteTree(int _k)
	{

	}

	//��������
	void AddTree(int _k, TPolinom _p, tree *&MyTree) //������� ���������� ����� � ������
	{
		if (NULL == MyTree)             //���� ������ ���
		{
			MyTree = new tree;          //�������� ������ ��� ����� ������
			MyTree->key = _k;              //���������� ������ � �����
			MyTree->data = _p;
			MyTree->left = MyTree->right = NULL; //��������� �������������� �������� �� ��������� ������
		}
		if (_k < MyTree->key)                   //���� ������������� ������� x ������ ��� ������� x �� ������� ������, ������ �����
		{
			if (MyTree->left != NULL) AddTree(_k, _p, MyTree->left); //��� ������ �������� ����������� ������� �� ��������� �������
			else                                          //���� ������� ������� ���� �������, ��
			{
				MyTree->left = new tree;                      //�������� ������ ������ ��������. ������ ��������, � �� ������ �����
				MyTree->left->left = MyTree->left->right = NULL;        //� ������ �������� ����� ���� ����� � ������ ���������, �������������� �� ��������
				MyTree->left->key = _k;
				MyTree->left->data = _p;//���������� � ����� �������� ������������ �������
			}
			if (_k > MyTree->key)              //���� ������������� ������� x ������ ��� ������� x �� ������� ������, ������ ������
			{
				if (MyTree->right != NULL) AddTree(_k, _p, MyTree->right); //��� ������ �������� ����������� ������� �� ��������� �������
				else              //���� ������� ������� ���� �������, ��
				{
					MyTree->right = new tree;                 //�������� ������ ������� ��������. ������ ��������, � �� ������ �����
					MyTree->right->left = MyTree->right->right = NULL;   //� ������� �������� ����� ���� ����� � ������ ���������, �������������� �� ��������
					MyTree->right->key = _k;                     //���������� � ������ �������� ������������ �������
					MyTree->right->data = _p;
				}
			}
		}
	}

	void show(tree *&Tree)              //������� ������
	{
		if (Tree != NULL)               //���� �� ���������� ������ �����
		{
			show(Tree->left);               //����������� ������� ��� ������ ������ ���������
			cout << Tree->key << "  |  " << Tree->data <<'\t';               //���������� ������ ������
			show(Tree->right);               //����������� ������ ��� ������ ������� ���������
		}
	}
};
