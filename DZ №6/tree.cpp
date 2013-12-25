#include <iostream>
#include "tree.h"

using std::cin;
using std::cout;
using std::endl;

namespace Trees
{

TreeNode *createNode(char *inputString, int &index)
{
	TreeNode * treeNode = new TreeNode();

	while((inputString[index] == ' ') || (inputString[index] == ')')) 
		index++;
	if (inputString[index] == '(')
	{
		index++;
		treeNode->value = inputString[index];
		treeNode->isLeaf = false;
	
		index++;
		treeNode->left = createNode(inputString, index);
		treeNode->right = createNode(inputString, index);	
	}
	else
	{
		int newValue = 0;
		
		while('0' <= inputString[index] && inputString[index] <= '9')
		{
			newValue *= 10;
			newValue += (inputString[index] - '0');
			index++;
		}

		index++;
		treeNode->value = newValue;
		treeNode->isLeaf = true;
		treeNode->left = NULL;
		treeNode->right = NULL;
	}
	return treeNode;
}

Tree * create(char *inputString)
{
	Tree * tree = new Tree();
	tree->root = NULL;
	int index = 0;
	tree->root = createNode(inputString, index);
	return tree;
}

void printTree(TreeNode *treeNode)
{
	if (treeNode->isLeaf)
		cout << treeNode->value;
	else
	{
		cout << "(";
		printTree(treeNode->left);
		cout << " " << (char) treeNode->value << " ";
		printTree(treeNode->right);
		cout << ")";
	}
}


void deleteTree(TreeNode *&treeNode)
{
	if (treeNode != NULL)
	{
		deleteTree(treeNode->left);
		deleteTree(treeNode->right);
		delete treeNode;
		treeNode = NULL;
	}
}

void deleteTree(Tree *tree)
{
	deleteTree(tree->root);
	delete(tree);
}

void printTree(Tree *tree)
{
	if (tree->root != NULL)
		printTree(tree->root);
}

int operation(int a, int b, char c)
{
	if(c == '+')
		return a + b;
	if(c == '*')
		return a * b;
	if(c == '/')
		return a / b;
	if(c == '-')
		return a - b;
}

int answer(TreeNode * treeNode)
{
	if (treeNode->isLeaf)
	{
		return treeNode->value;
	}
	else
	{
		return operation(answer(treeNode->left), answer(treeNode->right), treeNode->value);
	}

	return 0;
}

int answer(Tree *tree)
{
	return answer(tree->root);
}

}