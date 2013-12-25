namespace Trees
{
	struct TreeNode
	{
		int val;
		char ch;
		
		TreeNode *left;
		TreeNode *right;
	};
	
	struct Tree
	{
		TreeNode *root;
	};
	
	Tree * makeTree(int value, char character);
	Tree * makeNewTree(Tree * tree1, Tree * tree2);
	
	void print(TreeNode * node, char *& str, int index, char c);
	void print(Tree * tree, char c);
	
	void toStr(TreeNode * node, char *str, int &index);
	char * toStr(Tree * tree);
	void deleteTreeNode(TreeNode *& treeNode);
	void deleteTree(Tree *& tree);
}