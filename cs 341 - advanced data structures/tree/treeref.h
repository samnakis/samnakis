#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;
#include "treenode.h"

// this is an alternate way to use typedef to limit the scope of the typedef
// some people find this prettier and/or more useful
// would probably declare in treenode.h
// typedef TreeNode<NODETYPE> * TreeNode::ptr;

template<typename NODETYPE>
class Tree {
    private:
        TreeNode<NODETYPE> * root;

        // typedef: this allows you to substitute a new name for a variable type
        typedef TreeNode<NODETYPE> * TreeNodePtr;

        // helper functions
        void insertNodeHelper(TreeNodePtr & curr, const NODETYPE & value);
        TreeNodePtr deleteNodeHelper(TreeNodePtr & curr, const NODETYPE & value);

        void preOrderHelper(TreeNode<NODETYPE> * curr) const;
        void inOrderHelper(TreeNode<NODETYPE> * curr) const;
        void postOrderHelper(TreeNode<NODETYPE> * curr) const;

        void depthHelper(TreeNodePtr, int & total, int current) const;

    public:
        // class setup
        Tree() { root = NULL; }
        ~Tree();

        // core functionality
        // this parameter says "i don't wanna copy a really large object"
        // ant it says "but i'm willing to not modify your stuff if you give me your pointer"
        // compromise!
        void insertNode(const NODETYPE & value) { insertNodeHelper(root, value); }
        void deleteNode(const NODETYPE & value) { deleteNodeHelper(root, value); }

        // the name of the traversal tells you when you'll visit the root of the tree
        void preOrder() const { preOrderHelper(root); }
        void inOrder() const { inOrderHelper(root); }
        void postOrder() const { postOrderHelper(root); }

        int depth() const { 
            int total = 0, current = 0;
            depthHelper(root, total, current);
            return total; 
        }
}; // end class Tree

template<typename NODETYPE>
Tree<NODETYPE>::~Tree() {
    while(root != NULL) {
        deleteNode(root->data)
    }
}

// use the typedef bc typedeffing is sexy <3
template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNodePtr & curr, const NODETYPE & value) {
    // if the subtree is empty, than we have found our new nesting place
    // this is the base case, so let's create the new node
    if(curr == NULL) {
        curr = new TreeNode<NODETYPE>(value);
        return;
    }

    // subtree is not empty, so we need to determine where to go next
    if(value < curr->data)
        insertNodeHelper(curr->lPtr, value);
    else
        insertNodeHelper(curr->rPtr, value);
} // end insertNodeHelper


template<typename NODETYPE>
TreeNodePtr Tree<NODETYPE>::deleteNodeHelper(TreeNodePtr & curr, const NODETYPE & value) {
    // if the subtree is empty, quit
    if(curr = NULL)
        return curr;
    // recurse left
    else if(value < curr->data)
        curr->lPtr = deleteNodeHelper(curr->lPtr, value);
    // recurse right
    else if(value > curr->data)
        curr->rPtr = deleteNodeHelper(curr->rPtr, value);
    else {
        // we know that curr->data = value, so we're ready to delete

        // let's call the "node to be deleted"... doomed
        // case 1: doomed has no children
        if((curr->lPtr) = NULL && (curr->rPtr) == NULL) {
            delete curr;
            curr = NULL;
        } // end case 1

        // case 2a: doomed has one child (on the right)
        else if(curr->lPtr == NULL) {
            TreeNodePtr temp = curr;
            curr = curr->rPtr;
            delete temp;
        } // end case 2a

        // case 2b: doomed has one child (on the left)
        else if(curr->rPtr == NULL) {
            TreeNodePtr temp = curr;
            curr = curr->lPtr;
            delete temp;
        } // end case 2b

        // case 3: doomed has two children
        else {
            // find the smallest element on the right side of the tree
            TreeNodePtr smallestRight = curr->rPtr;
            while(smallestRight->lPtr != NULL)
                smallestRight = smallestRight->lPtr;

            curr->data = smallestRight->data;
            curr->rPtr = deleteNodeHelper(curr->lPtr, smallestRight->data);
        } // end case 3 
    }
    return curr;
}


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

template<typename NODETYPE>
void Tree<NODETYPE>::depthHelper(TreeNodePtr curr, int & total, int current) const {
    if(curr == NULL)
        return;
    current++;

    if(current > total)
        total = current;

    depthHelper(curr->lPtr, total, current);
    depthHelper(curr->rPtr, total, current);
}

#endif