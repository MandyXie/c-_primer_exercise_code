#include<string>
using namespace std;

class TreeNode{
public:
   TreeNode():value(""),count(new int(1)),left(nullptr),right(nullptr) {}
   TreeNode(const TreeNode& tn);
   TreeNode& operator=(const TreeNode& tn);
   ~TreeNode();
private:
   string value;
   int *count;
   TreeNode *left;
   TreeNode *right;
};

TreeNode::TreeNode(const TreeNode& tn)
{
   value = tn.value;
   count = tn.count;
   left = tn.left;
   right = tn.right;
   ++*count;
}

TreeNode::TreeNode& operator=(const TreeNode& tn)
{
   *++tn.count;
   if(*--count == 0)
   {
      delete count;
      delete left;
      delete right;
   }
   count = tn.count;
   left = tn.left;
   right = tn.right;
   return *this;
}

TreeNode::~TreeNode()
{
   if(--*count == 0)
   {
      delete left;
      delete right;
      delete count;
   }
}

class BinStrTree{
public:
   BinStrTree():root(new TreeNode()) {}
   BinStrTree(BinStrTree& bst);
   BinStrTree& operator=(const BinStrTree& bst);
   ~BinStrTree() {if(root) delete root;} 
private:
   TreeNode *root;   
};

BinStrTree::BinStrTree(BinStrTree& bst)
{
   root = new BinStrTree(*bst.root);
}

BinStrTree::BinStrTree& operator=(const BinStrTree& bst)
{
   TreeNode new_root = new BinStrTree(*bst.root);
   delete root;
   root = new_root;
   return *this;
}
