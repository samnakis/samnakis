#include "tree.h"
#include "icebbs.cpp"
#include <fstream>
#include <iostream>
using namespace std;

// LicorIce getBB(ifstream bbfile){
//     int score = 0;
//     int power = 0;
//     string name = "";
    
//     bbfile >> name >> score >> power;
//     return LicorIce(score, power, name);
// }

int main() {
    // Tree<LicorIce> licoriceTree;
    Tree<int> intTree;
    int insertVal[11] = {50, 25, 75, 12, 33, 67, 88, 6, 13, 76, 89};

    // ifstream bbfile;
    // bbfile.open("bbfile.txt");

    // for(int i = 0; i < 10; i++) {
    //     licoriceTree.insertNode(getBB(bbfile)); 
    // }

    for(int x = 0; x < 11; x++)
        intTree.insertNode(insertVal[x]);

    cout << "Preorder: \n";
    intTree.preOrder();
    cout << endl;

    cout << "Inorder: \n";
    intTree.inOrder();
    cout << endl;

    cout << "Postorder: \n";
    intTree.postOrder();
    cout << endl;

    cout << "Depth: ";
    cout << intTree.depth();
    cout << endl;

    // cout << endl;
    // cout << "right rotating... ";
    // cout << endl;
    // intTree.rightRotateStarter();
    // cout << endl;

    // cout << endl;
    // cout << "left rotating... ";
    // cout << endl;
    // intTree.leftRotateStarter();
    // cout << endl;

    // intTree.getRoot();
    // cout << endl;

    // cout << "Preorder: \n";
    // intTree.preOrder();
    // cout << endl;

    // cout << "Inorder: \n";
    // intTree.inOrder();
    // cout << endl;

    // cout << "Postorder: \n";
    // intTree.postOrder();
    // cout << endl;

    // cout << "Depth: ";
    // cout << intTree.depth();
    // cout << endl;

    return 0;
}
