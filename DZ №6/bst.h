struct TreeNode
{
	int value;
	int height;
	TreeNode *left;
	TreeNode *right;
};

struct Tree
{
	TreeNode *root;
};

Tree *createTree();
bool exists(Tree *tree, int value);
void add(Tree *tree, int value);
void removeFromTree(Tree *tree, int value);
void printUp(Tree *tree);
void printDown(Tree *tree);
void deleteTree(Tree *tree);
void print(Tree *tree);
