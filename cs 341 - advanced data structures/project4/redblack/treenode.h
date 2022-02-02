#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of a class Tree
// notify the TreeNode class that another class called Tree will exist
template<typename NODETYPE> class Tree;

enum Color {BLACK = 0, RED};
template<typename NODETYPE>
class TreeNode {
    // Any member function of class Tree can access private members of 
    // TreeNode because it's a friend. Awwww.
    friend class Tree<NODETYPE>;

    private:
        TreeNode<NODETYPE> * left;
        TreeNode<NODETYPE> * right;
        TreeNode<NODETYPE> * parent;
        NODETYPE data;
        Color color;

    public:
        // Class setup
        // Reminder of the alternate way to initialize parameters.
        TreeNode(const NODETYPE & d) : left(NULL), right(NULL), data(d) {}

        // Access function
        NODETYPE getData() const {return data;}
}; // end class TreeNode
#endif