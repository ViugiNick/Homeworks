namespace Trees
{
	struct TreeNode
	{
		int value;
		bool isLeaf;
		TreeNode * left;
		TreeNode * right;
	};

	struct Tree
	{
		TreeNode * root;
	};

	Tree * create(char * str);
	void printTree(Tree* tree);
	int answer(Tree * tree);
	void deleteTree(Tree * tree);
}