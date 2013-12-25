#include <iostream>
#include "tree_Viu.h"

using namespace std;

const int MAXN = 100;

namespace Trees
{
	Tree * makeTree(int val, char ch)
	{
		Tree * tree = new Tree();
		tree->root = new TreeNode();
		
		tree->root->val = val;
		tree->root->ch = ch;
		
		tree->root->left = NULL;
		tree->root->right = NULL;

		return tree;
	}

	Tree * makeNewTree(Tree * tree1, Tree * tree2)
	{
		Tree * tree = new Tree();
		tree->root = new TreeNode();
		
		tree->root->left = tree1->root;
		tree->root->right = tree2->root;
		
		tree->root->val = (tree1->root->val + tree2->root->val);
		
		delete tree1;
		delete tree2;
		return tree;
	}

	void toStr(TreeNode * node, char *str, int &index)
	{
		if(node->right == NULL && node->left == NULL)
			str[index] = node->ch;
		else
		{
			str[index] = '(';
			if(node->left != NULL)
				toStr(node->left, str, ++index);
			if(node->right != NULL)
				toStr(node->right, str, ++index);
			
			index++;
			str[index] = ')';
		}
	}

	char * toStr(Tree * tree)
	{
		char *str = new char[MAXN];
		
		for(int i = 0; i < MAXN; i++)
			str[i] = 0;
		
		int index = 0;
		toStr(tree->root, str, index);
		
		return str;
	}
	
	void print(TreeNode * node, char *& str, int index, char c)
	{
		if(node->right == NULL && node->left == NULL && node->ch == c)
			for(int i = 0; i < index; i++)
				cout << str[i];
		else
		{
			if(node->left != NULL)
			{
				str[index] = '0';
				print(node->left, str, index + 1, c);
			}
			if(node->right != NULL)
			{
				str[index] = '1';
				print(node->right, str, index + 1, c);
			}
		}
	}

	void print(Tree * tree, char c)
	{
		char *str = new char[MAXN];
		
		int index = 0;
		print(tree->root, str, index, c);
	}

	void deleteTreeNode(TreeNode *& treeNode)
	{
		if (treeNode->left != NULL)
			deleteTreeNode(treeNode->left);
		if(treeNode->right != NULL)
			deleteTreeNode(treeNode->right);
		
		delete treeNode;
	}

	void deleteTree(Tree *& tree)
	{
		if(tree->root != NULL)
			deleteTreeNode(tree->root);
	}
}