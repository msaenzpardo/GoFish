// Sample driver
// EE 312 Fall 2020
//
// The BST should work for any data type or object.
// Other user created objects must have the << operator
// overloaded for output.
//

#include <iostream>
#include <fstream>
#include "BST312.h"
#include "cardsong.h"

using namespace std;

template <typename T>
void print(vector<T> vec){
    for(auto vecVal : vec){
        cout << vecVal << endl;;
    }
}

int main() {

    ifstream inFile;
    inFile.open("C:\\Users\\melan\\CLionProjects\\ECE312 Project7\\test.txt");

    BST_312<int> bst;

    int s;
    inFile >> s;
    //\stoi(s);
    while (inFile) {;
        cout << "inserting ... " << s << endl;
        bst.insertItem(s);
        inFile >> s;
    }

    cout << "is tree full (stack overflow?)" << endl;
    if (bst.isFull()) {
        cout << "yes full" << endl;
    }

    else {
        cout << "no full" << endl;
    }
    cout << "postorder traversal is " << endl;
    print(bst.postOrderTraversal());
    cout << endl;

    cout << "preorder traversal is " << endl;
    print(bst.preOrderTraversal());
    cout << endl;

    cout << "inorder traversal is " << endl;
    print(bst.inOrderTraversal());
    cout << endl;

    cout << "Remove items " << endl;
    cout << "number of nodes in tree before delete is " << bst.countNodes() << endl;
    //s = "tree";
    s = 10;
    bst.deleteItem(s);
    print(bst.postOrderTraversal());
    cout << endl;
    print(bst.inOrderTraversal());
    cout << endl;
    print(bst.preOrderTraversal());
    cout << endl;
    cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;
    cout << endl;
    cout << "isItemInTree" << endl;
    if (bst.isItemInTree(s)) {
        cout << s << " is in tree" << endl;
    }

    else {
        cout << s << " no, item is not in tree" << endl;
    }

    cout << "make empty" << endl;
    bst.makeEmpty();
    cout << "number of nodes: " << bst.countNodes() << endl;

    cout << "checking if the tree really is empty" << endl;

    if (bst.isEmpty()) {
        cout << "yes empty" << endl;
    }

    else {
        cout << "no empty" << endl;
    }




}


