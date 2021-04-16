#include <iostream>
using namespace std;
#include "BST.h"

// default constructor definition
BST::BST()
{
    myRoot = NULL;
}
// display function definition
void BST::display(char & choice)
{
    TreeNode* ptr = myRoot;
    // show Inorder traversal
    if(choice == 'I' || choice == 'i')
    {
        cout << "\n >> BST In Order: "<<endl;
        cout << " ________________\n"<<endl;
        cout << "       ";
        inorder(ptr);
        cout << "\n\n";
    }
    // show Preorder traversal
    if(choice == 'E' || choice == 'e')
    {
        cout << "\n\n >> BST Pre-order: "<<endl;
        cout << " _________________\n"<<endl;
        cout << "       ";
        preorder(ptr);
        cout << "\n\n";
    }
    // show Postorder traversal
    if(choice == 'O' || choice == 'o')
    {
        cout << "\n\n >> BST Post-order: "<<endl;
        cout << " __________________\n"<<endl;
        cout << "       ";
        postorder(ptr);
        cout << "\n\n";
    }
}

// insert function
void BST::insertNode(const int & data)
{
    TreeNode* ptr = myRoot;
    TreeNode* parent = 0;
    bool found = false;
    while(!found && ptr != 0)
    {
        parent = ptr;
        if(data < ptr->item)
            ptr = ptr->left;   //  descend left
        else if(ptr->item < data)
            ptr = ptr->right;   // descend right
        else
            found = true;       // item found
    }
    if(!found)
    {
        ptr = new TreeNode(data);
        if(parent == 0)         // tree is empty
            myRoot = ptr;
        else if(data < parent->item)
            parent->left = ptr;    // insert item to the left
        else
            parent->right = ptr;   // insert item to the right
    }
    else
        cout << "\n     The Item Is Already In The Tree. \n"<<endl;
}

// search function #1
bool BST::searchNode(const int & data) const
{
    TreeNode* ptr = myRoot;
    bool found = false;

    while(!found && ptr !=0)
    {
        if(data < ptr->item)
            ptr = ptr->left;     // descend left
        else if(ptr->item < data)
            ptr = ptr->right;    // descend right
        else
            found = true;        // item found
    }
    return found;
}

// search function #2 for remove
void BST::searchForRemove(const int & data, bool & found, TreeNodePtr & ptr, TreeNodePtr & parentNode)
{
    ptr = myRoot;
    parentNode = 0;
    found = false;

    while(!found && ptr !=0)
    {
        if(data < ptr->item)
        {
            parentNode = ptr;
            ptr = ptr->left;
        }
        else if(ptr->item < data)
        {
            parentNode = ptr;
            ptr = ptr->right;
        }
        else
        {
            found = true;
        }
    }
}

// remove function
void BST::removeNode(const int & data)
{
    TreeNode* targetedChild;   // points to the node to be removed
    TreeNode* parent;           // points to the parent of targetedChild and childSucc
    bool found;

    searchForRemove(data, found, targetedChild, parent);

    if(!found)  // if node is not in the tree
    {
        cout << "\n    The Item You Want To Remove Is Not In The Tree."<<endl;
        return;
    }

     cout << "\n    The Item Is Removing..."<<endl;
        // case when node has two children
        if(targetedChild->left !=0 && targetedChild->right != 0)
        {
            TreeNode* childSucc = targetedChild->right;
            parent = targetedChild;

            while(childSucc->left != 0)
            {
                parent = childSucc;
                childSucc = childSucc->left;
            }
            targetedChild->item = childSucc->item;
            targetedChild = childSucc;
        }

        // case when node has no child or 1 child
        TreeNode *sub;
        sub = targetedChild->left;  // pointing to the subtree of targetedChild
        if(sub == 0)
            sub = targetedChild->right;
        if(parent == 0)             // root being deleted
            myRoot = sub;
        else if(parent->left == targetedChild)
            parent->left = sub;
        else
            parent->right = sub;
        delete targetedChild;
}

// in order function to show the tree
void BST::inorderTraversal()
{
    TreeNode* ptr = myRoot;
    cout<< "\n_____________________________________________________________________\n\n";
    cout<< " >> The Tree In Order:   ";
    inorder(ptr);
    cout<< "\n_____________________________________________________________________\n\n";
}

// in order traversal
void BST::inorder(TreeNode* ptr)
{
   if(ptr != NULL)
   {
            inorder(ptr->left);
       cout << " "<< ptr->item << " ";
            inorder(ptr->right);
   }
    else
        return;
}

// Pre-order traversal
void BST::preorder(TreeNode* ptr)
{
    if(ptr != NULL)
   {
       cout << " "<< ptr->item << " ";
            preorder(ptr->left);
            preorder(ptr->right);
   }
    else
        return;
}

// Postorder traversal
void BST::postorder(TreeNode* ptr)
{
    if(ptr != NULL)
   {
       postorder(ptr->left);
       postorder(ptr->right);
        cout << " "<< ptr->item << " ";
   }
    else
        return;
}
