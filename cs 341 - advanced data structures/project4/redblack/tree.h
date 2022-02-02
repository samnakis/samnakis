#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;
#include "treenode.h"

// // Move this to bitarray.cpp
// ostream & operator << (ostream & out, BitArray & array){
//    	int NUMPERLINE = 4;
//    	int numPrinted = 0;
//    	for (int x = 0; x < array.length(); x++) {
// 	if (array.get(x)){
//         out.width(4);
//         out << x;
//         numPrinted++;
//         if (numPrinted % NUMPERLINE == 0)
//         	out << "\n";
//       	} // end if
//    	} // end for
//    	return out;
// } // end ostream & operator <<

template<typename NODETYPE> class Tree {
	private:
		TreeNode<NODETYPE> * root;
		
		typedef TreeNode<NODETYPE> * TreeNodePtr;
	
		// Helper functions
		void insertNodeHelper(TreeNodePtr & curr, const NODETYPE & value);
		TreeNodePtr deleteNodeHelper(TreeNodePtr & curr, const NODETYPE & value);		
		
		void preOrderHelper(TreeNodePtr curr) const;
		void inOrderHelper(TreeNodePtr curr) const;
		void postOrderHelper(TreeNodePtr curr) const;
		void depthHelper(TreeNodePtr curr, int & total, int current) const;

        // Red/Black recoloring helper functions
        void leftRotate(TreeNodePtr x);
        void rightRotate(TreeNodePtr y);
        void recolor(TreeNodePtr k);
        void doubleBlack(TreeNodePtr x);
        
	public:
		// Class setup
		Tree() { root = NULL; }
		~Tree();

		// function to return the root of the tree
		TreeNodePtr getRoot() { return root; }
		void printRoot() {
			if(root)
				cout << root->data << endl;
			else
				cout << "NULL" << endl;
		}
		
		// Core functionality
		void insertNode(const NODETYPE & value) { insertNodeHelper(root, value); }
		void deleteNode(const NODETYPE & value) { deleteNodeHelper(root, value); }
		void preOrder() const { preOrderHelper(root); }
		void inOrder() const { inOrderHelper(root); }
		void postOrder() const { postOrderHelper(root); }
		int depth() const {
			int total = 0, current = 0;
			depthHelper(root, total, current);
			return total;
		} // end function depth()
		void leftRotateStarter() {leftRotate(root->right);}
		void rightRotateStarter() {rightRotate(root->left);}
        
}; // end class Tree

template<typename NODETYPE>
Tree<NODETYPE>::~Tree() {
	while (root != NULL)
		deleteNode(root->data);
} // end destructor

template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNodePtr & curr, const NODETYPE & value) {
	// If the subtree is empty, then we have found our new nesting place.
	// This is the base case, so let's create the new node.
	if (curr == NULL) {
		curr = new TreeNode<NODETYPE>(value);
        if(curr == root)
			curr->color = BLACK;
		else
			curr->color = RED;
		return;
	}
	if (value < curr->data){
		insertNodeHelper(curr->left, value);
        curr->left->parent = curr;
		recolor(curr->left);
    }
	else {
		insertNodeHelper(curr->right, value);
        curr->right->parent = curr;
		recolor(curr->right);
    }
} // end insertNodeHelper

// start recolor
template<typename NODETYPE>
void Tree<NODETYPE>::recolor(TreeNodePtr curr) {
	cout << curr->data << endl;
    // Case 1: T has one element. Color the root black.
    if(curr==root){
        return;
    }
	if(curr->parent)
		cout << "parent: " << curr->parent->data << endl;
	else
		cout << "no parent" << endl;

    // Case 2: Parent is black. Do nothing.
	if(curr->parent->color == BLACK)
		return;

    // Case 3: Parent is red. Here we go.
    while(curr->parent && curr->parent->color == RED) {
		cout << "here" << endl;
        if(curr->parent == curr->parent->parent->right) { // Node on right side. Cases 3.1, 3.2.1, and 3.2.2
            TreeNode<NODETYPE> * uncle = curr->parent->parent->left;
            if(uncle->color == RED) { // Case 3.1: Parent and Uncle are both red
                uncle->color = BLACK;
                curr->parent->color = BLACK;
                curr->parent->parent->color = RED;
                curr = curr->parent->parent;
            }
            else {
                if(curr == curr->parent->left) { // Case 3.2.2: P is the right child of G and curr is the left child of P
                    curr = curr->parent;
                    rightRotate(curr);
                }
                // Case 3.2.1: P is the right child of G and curr is the right child of P
                curr->parent->color = BLACK;
                curr->parent->parent->color = RED;
                leftRotate(curr->parent->parent);
            }
        }

        else { // Node on left side. Cases 3.1, 3.2.3, and 3.2.4
			cout << "left child" << endl;
            TreeNode<NODETYPE> * uncle = curr->parent->parent->right;
			cout << "made uncle" << endl;
            if(uncle->color == RED) { // Case 3.1: Parent and Uncle are both red
                cout << "here5" << endl;
				uncle->color = BLACK;
                curr->parent->color = BLACK;
                curr->parent->parent->color = RED;
                curr = curr->parent->parent;
            }
            else {
                if(curr == curr->parent->right) { // Case 3.2.4: P is the left child of G and curr is the right child of P
                    curr = curr->parent;
                    leftRotate(curr);
                }
                // Case 3.2.3: P is the left child of G and curr is the left child of P
                curr->parent->color = BLACK;
                curr->parent->parent->color = RED;
                rightRotate(curr->parent->parent);
            }
        }
    }
	cout << "here3" << endl;
	
	// cleaning up the root back to black if it was changed in the loop
	if(root->color == RED)
		root->color = BLACK;

	cout << "here4" << endl;
    return;
}   // end recolor

// start leftRotate
template<typename NODETYPE>
void Tree<NODETYPE>::leftRotate(TreeNodePtr curr) {
    TreeNode<NODETYPE> * y = curr->right;
    curr->right = y->left;
    if(y->left)
        y->left->parent = curr;
    y->parent = curr->parent;
    if(!curr->parent)
        root = y;
    else if(curr->parent->left == curr)
        curr->parent->left = y;
    else
        curr->parent->right = y;
    y->left = curr;
    curr->parent = y;
}

// start rightRotate
template<typename NODETYPE>
void Tree<NODETYPE>::rightRotate(TreeNodePtr curr) {
    TreeNode<NODETYPE> * y = curr->left;
    curr->left = y->right;
    if(y->right)
        y->right->parent = curr;
    y->parent = curr->parent;
    if(!curr->parent)
        root = y;
    else if(curr->parent->right == curr)
        curr->parent->right = y;
    else
        curr->parent->left = y;
    y->right = curr;
    curr->parent = y;
}

template<typename NODETYPE>
TreeNode<NODETYPE> * Tree<NODETYPE>::deleteNodeHelper(TreeNodePtr & curr, const NODETYPE & value) {
	// If the subtree is empty, quit
	if (curr == NULL)
		return curr;
	else if (value < curr->data)
		curr->left = deleteNodeHelper(curr->left, value);
	else if (value > curr->data)
		curr->right = deleteNodeHelper(curr->right, value);
	else {
		// We know that curr->data == value, so we're ready to delete
		
		// Let's call the "node to be deleted" . . . . doomed
		// Case 1: (doomed has no children)
		if ((curr->left == NULL) && (curr->right == NULL)) {
			delete curr;
			curr = NULL;
		} // end case 1 if
		
		// Case 2: (doomed has one child)
		else if (curr->left == NULL) {
			TreeNodePtr temp = curr;
			curr = curr->right;
			delete temp;
		} // end case 2a if
		else if (curr->right == NULL) {
			TreeNodePtr temp = curr;
			curr = curr->left;
			delete temp;
		} // end case 2b if
		
		// Case 3: (doomed has two children)
		else {
			// Find the smallest element on the right side of the tree.
			TreeNodePtr smallestRight = curr->right;
			while (smallestRight->left != NULL)
				smallestRight = smallestRight->left;
			
            // Notice that you actually only ever delete a node with 0 or 1 child from the tree.
            // Nodes with two children are too big to fail.
			curr->data = smallestRight->data;
			curr->right = deleteNodeHelper(curr->right, smallestRight->data);
		} // end case 3
	} // end outside else

	return curr;
}	

template<typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
	if(curr->parent)
		cout << "Node: " << curr->data << " Color : " << curr->color << " Parent: " << curr->parent->data << endl;		// process the node
	else
		cout << "Node: " << curr->data << " Color : " << curr->color << " Parent: NULL" << endl;		// process the node
	preOrderHelper(curr->left);		// traverse the left subtree
	preOrderHelper(curr->right);		// traverse the right subtree
} // end preOrderHelper

template<typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
	inOrderHelper(curr->left);		// traverse the left subtree
	if(curr->parent)
		cout << "Node: " << curr->data << " Color : " << curr->color << " Parent: " << curr->parent->data << endl;		// process the node
	else
		cout << "Node: " << curr->data << " Color : " << curr->color << " Parent: NULL" << endl;		// process the node
	inOrderHelper(curr->right);		// traverse the right subtree
} // end inOrderHelper

template<typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
	postOrderHelper(curr->left);		// traverse the left subtree
	postOrderHelper(curr->right);		// traverse the right subtree
	if(curr->parent)
		cout << "Node: " << curr->data << " Color : " << curr->color << " Parent: " << curr->parent->data << endl;		// process the node
	else
		cout << "Node: " << curr->data << " Color : " << curr->color << " Parent: NULL" << endl;		// process the node} // end postOrderHelper
} // end postOrderHelper

template<typename NODETYPE>
void Tree<NODETYPE>::depthHelper(TreeNodePtr curr, int & total, int current) const {
	// if tree is empty, quit
	if (curr == NULL)
		return;
	current++;
	
	// Update total if it's bigger.
	if (current > total)
		total = current;
	depthHelper(curr->left, total, current);
	depthHelper(curr->right, total, current);
} // end depthHelper

#endif