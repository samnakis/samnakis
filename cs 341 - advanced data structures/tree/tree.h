#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;
#include "treenode.h"

template<typename NODETYPE>
class Tree {
    private:
        TreeNode<NODETYPE> * root;

        // helper functions
        void insertNodeHelper(TreeNode<NODETYPE> ** ptr, const NODETYPE & value);

        void preOrderHelper(TreeNode<NODETYPE> * curr) const;
        void inOrderHelper(TreeNode<NODETYPE> * curr) const;
        void postOrderHelper(TreeNode<NODETYPE> * curr) const;

    public:
        // class setup
        Tree() { root = NULL; }
        // ~Tree();

        // core functionality
        // this parameter says "i don't wanna copy a really large object"
        // ant it says "but i'm willing to not modify your stuff if you give me your pointer"
        // compromise!
        void insertNode(const NODETYPE & value) { insertNodeHelper(&root, value); }

        // the name of the traversal tells you when you'll visit the root of the tree
        void preOrder() const { preOrderHelper(root); }
        void inOrder() const { inOrderHelper(root); }
        void postOrder() const { postOrderHelper(root); }
}; // end class Tree

// this function receives a pointer to a node pointer so that we can modify the pointer's value within the function
// another way to say this is that the parameters is a reference to a node pointer
// this is analogous to a reference to an integer, but it feels weird because this is a reference to a pointer, so it's a "double pointer"
template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE> ** curr, const NODETYPE & value) {
    // if the subtree is empty, than we have found our new nesting place
    // this is the base case, so let's create the new node
    if(*curr == NULL) {
        *curr = new TreeNode<NODETYPE>(value);
        return;
    }

    // subtree is not empty, so we need to determine where to go next
    if(value < (*curr)->data)
        insertNodeHelper(&((*curr)->lPtr), value);
    else
        insertNodeHelper(&((*curr)->rPtr), value);
} // end insertNodeHelper


template<typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE> * curr) const {
    // if you print the value of nullptr and NULL, you will see 0 printed twice
    if(curr == NULL)
        return;
    cout << curr->data << ' '; // processed the node
    preOrderHelper(curr->lPtr); // recurse on left subtree
    preOrderHelper(curr->rPtr); // recurse on right subtree
} // end preOrderHelper


template<typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE> * curr) const {
    // if you print the value of nullptr and NULL, you will see 0 printed twice
    if(curr == NULL)
        return;
    inOrderHelper(curr->lPtr); // recurse on left subtree
    cout << curr->data << ' '; // processed the node
    inOrderHelper(curr->rPtr); // recurse on right subtree
} // end inOrderHelper


template<typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNode<NODETYPE> * curr) const {
    // if you print the value of nullptr and NULL, you will see 0 printed twice
    if(curr == NULL)
        return;
    postOrderHelper(curr->lPtr); // recurse on left subtree
    postOrderHelper(curr->rPtr); // recurse on right subtree
    cout << curr->data << ' '; // processed the node
} // end postOrderHelper

#endif