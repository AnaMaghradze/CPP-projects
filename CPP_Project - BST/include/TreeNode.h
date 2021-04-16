#ifndef TREENODE_H
#define TREENODE_H
#include "BST.h"

 class TreeNode
{
    friend class BST;   // BST is the friend class of TreeNode

        private:
            int item;
            TreeNode* left;
            TreeNode* right;

        public:
            //default constructor
            TreeNode();
            //explicit value constructor
            TreeNode(int data);
            // accessor function
            int getItem () const;
};
typedef TreeNode * TreeNodePtr;

// default constructor
inline TreeNode::TreeNode()
 : left(0), right(0) {}

// explicit value constructor
inline TreeNode::TreeNode(int data)
    : item(data), left(0), right(0) {}


#endif // TREENODE_H
