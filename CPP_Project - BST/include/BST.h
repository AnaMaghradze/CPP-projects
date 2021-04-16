#include <iostream>
#ifndef BST_H
#define BST_H
#include "TreeNode.h"

class BST
{
    public:
        BST();
        bool searchNode(const int & data) const;      // search function
        void insertNode(const int & data);            // insert function
        void removeNode(const int & data);            // remove function
        void display(char & choice);        // display function to perform Inorder, Preorder, Postorder traversals
        void inorderTraversal();            // Inorder traversal to show binary search tree

    private:
        TreeNode* myRoot;
        void inorder(TreeNode*);
        void preorder(TreeNode*);
        void postorder(TreeNode*);
        // search function for remove function
        void searchForRemove(const int & data, bool & found, TreeNodePtr & ptr, TreeNodePtr & parentNode);

};

#endif // BST_H
