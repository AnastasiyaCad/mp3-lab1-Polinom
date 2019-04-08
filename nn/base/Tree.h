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
		tree *left;  // левый 
		tree *right; // правый
	};

	tree *NTree = NULL; // звено дерева
public:
	//проходим по дереву
	void treeprint(tree *tree)
	{
		if (tree != NULL) 
		{
			//cout << tree->field; //Отображаем корень дерева
			treeprint(tree->left); 
			treeprint(tree->right); 
		}
	}
	//удаление поддерева
	void freemem(tree *tree)
	{
		if (tree != NULL) {
			freemem(tree->left);
			freemem(tree->right);
			delete tree;
		}
	}
	//удаление
	void DeleteTree(int _k)
	{

	}

	//добавить
	void AddTree(int _k, TPolinom _p, tree *&MyTree) //Функция добавления звена в дерево
	{
		if (NULL == MyTree)             //Если дерева нет
		{
			MyTree = new tree;          //Выделяем память под звено дерева
			MyTree->key = _k;              //Записываем данные в звено
			MyTree->data = _p;
			MyTree->left = MyTree->right = NULL; //Подзвенья инициализируем пустотой во избежание ошибок
		}
		if (_k < MyTree->key)                   //Если нововведенный элемент x меньше чем элемент x из семечка дерева, уходим влево
		{
			if (MyTree->left != NULL) AddTree(_k, _p, MyTree->left); //При помощи рекурсии заталкиваем элемент на свободный участок
			else                                          //Если элемент получил свой участок, то
			{
				MyTree->left = new tree;                      //Выделяем память левому подзвену. Именно подзвену, а не просто звену
				MyTree->left->left = MyTree->left->right = NULL;        //У левого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
				MyTree->left->key = _k;
				MyTree->left->data = _p;//Записываем в левое подзвено записываемый элемент
			}
			if (_k > MyTree->key)              //Если нововведенный элемент x больше чем элемент x из семечка дерева, уходим вправо
			{
				if (MyTree->right != NULL) AddTree(_k, _p, MyTree->right); //При помощи рекурсии заталкиваем элемент на свободный участок
				else              //Если элемент получил свой участок, то
				{
					MyTree->right = new tree;                 //Выделяем память правому подзвену. Именно подзвену, а не просто звену
					MyTree->right->left = MyTree->right->right = NULL;   //У правого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
					MyTree->right->key = _k;                     //Записываем в правое подзвено записываемый элемент
					MyTree->right->data = _p;
				}
			}
		}
	}

	void show(tree *&Tree)              //Функция обхода
	{
		if (Tree != NULL)               //Пока не встретится пустое звено
		{
			show(Tree->left);               //Рекурсивная функция для вывода левого поддерева
			cout << Tree->key << "  |  " << Tree->data <<'\t';               //Отображаем корень дерева
			show(Tree->right);               //Рекурсивная функци для вывода правого поддерева
		}
	}
};
