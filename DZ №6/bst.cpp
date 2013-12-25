#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include "bst.h"

using std::cout;
using std::endl;
using std::max;

Tree *createTree()
{
	Tree *result = new Tree;
	result->root = NULL;
	return result;
}

bool exists(TreeNode *root, int value)
{
	if (root == NULL)
		return false;

	if (root->value == value)
		return true;

	if (root->value < value)
		return exists(root->right, value);
	else
		return exists(root->left, value);
}

bool exists(Tree *tree, int value)
{
	return exists(tree->root, value);
}

TreeNode *createNode(int value)
{
	TreeNode *toAdd = new TreeNode;
	toAdd->value = value;
	toAdd->left = NULL;
	toAdd->right = NULL;

	toAdd->height = 1;

	return toAdd;
}

int height(TreeNode *node)
{
	return node ? node->height : 0;
}

int balance(TreeNode *node)
{
	return height(node->right) - height(node->left);
}

void updateHeight(TreeNode *node)
{
	if(node == NULL)
		return;

	int leftHeight = height(node->left);
	int rightHeight = height(node->right);
	node->height = max(leftHeight, rightHeight) + 1;
}

void makeRightSpin(TreeNode *&p, TreeNode *q)
{
	TreeNode *temp = q->right;

	q->right = p;
	p->left = temp;
	p = q;

	updateHeight(p->left);
	updateHeight(p->right);
	updateHeight(p);
}

void makeLeftSpin(TreeNode *&p, TreeNode *q)
{
	TreeNode *temp = q->left;

	q->left = p;
	p->right = temp;
	p = q;

	updateHeight(p->left);
	updateHeight(p->right);
	updateHeight(p);
}

void add(TreeNode *&root, int value)
{
	if (root == NULL)
	{
		root = createNode(value);
		return;
	}

	if (root->value < value)
	{
		add(root->right, value);
	}
	else
	{
		if (root->value > value)
			add(root->left, value);
	}

	updateHeight(root);

	if(root->right != NULL && balance(root) == 2)
	{
		makeLeftSpin(root, root->right);
		return;
	}

	if(root->left != NULL && balance(root) == -2)
	{
		makeRightSpin(root, root->left);
	}
}
void add(Tree *tree, int value)
{
	add(tree->root, value);
}

bool hasOneChild(TreeNode *root)
{
	return ((root->left && !root->right) || (root->right && !root->left));
}

bool isLeaf(TreeNode *root)
{
	return (root->left == NULL && root->right == NULL);
}

void printUp(TreeNode *root)
{
	if (root->left)
		printUp(root->left);

	if (root->right)
		printUp(root->right);
}

void printUp(Tree *tree)
{
	if (tree->root)
		printUp(tree->root);

	cout << endl;
}

void printDown(TreeNode *root)
{
	if (root->right)
		printDown(root->right);

	if (root->left)
		printDown(root->left);
}

void printDown(Tree *tree)
{
	if (tree->root)
		printDown(tree->root);

	cout << endl;
}

void print(TreeNode *root)
{
	if(root != NULL)
	{
		cout << '(' << root->value << " ";
		print(root->left);
		print(root->right);
		cout << ')';
	}
	else
		printf("NULL ");
}

void print(Tree *tree)
{
	if (tree->root)
		print(tree->root);
 
	cout << endl;
}

void remove(TreeNode *&, int);

int theLeft(TreeNode *&root)
{
	if (root->left == NULL)
	{
		int value = root->value;
		remove(root, value);
		return value;
	}
	return theLeft(root->left);
}

void remove(TreeNode *&root, int value)
{
	if (root == NULL)
	{
		cout << "No such element\n";
		return;
	}
	if (root->value > value)
	{
		remove(root->left, value);
		return;
	}
	if (root->value < value)
	{
		remove(root->right, value);
		return;
	}

	if (isLeaf(root))
	{
		delete root;
		root = NULL;
		return;
	}

	if (root->left == NULL)
	{
		TreeNode *tmp = root;
		root = root->right;
		delete tmp;
		return;
	}

	if (root->right == NULL)
	{
	TreeNode *tmp = root;
		root = root->left;
		delete tmp;
		return;
	}

	root->value = theLeft(root->right);
}

void removeFromTree(Tree *tree, int value)
{
	remove(tree->root, value);
}

void deleteNode(TreeNode *root)
{
	if(root != NULL)
	{
		deleteNode(root->left);
		deleteNode(root->right);
		delete(root);
		root = NULL:
	}
}

void deleteTree(Tree *tree)
{
	deleteNode(tree->root);	
	tree->root;
}

