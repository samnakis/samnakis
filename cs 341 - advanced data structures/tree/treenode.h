#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of class Tree
// notify the TreeNode class that a class called Tree with exist soon
template<typename NODETYPE> class Tree;

template<typename NODETYPE>
class TreeNode {
    // any member function of class Tree can access private members of TreeNode because it's a friend function
    friend class Tree<NODETYPE>;
    
    private:
        TreeNode<NODETYPE> * lPtr;
        TreeNode<NODETYPE> * rPtr;
        NODETYPE data;
    public:
        // class setup
        TreeNode(const NODETYPE & d) : lPtr(NULL), rPtr(NULL), data(d) {}

        // access function
        NODETYPE getData() const {return data;}
}; // end class TreeNode

#endif