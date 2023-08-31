
/*  BST312.h
  EE312 Fall 2020
  Melanie Saenzpardo, mis868, ECE312, Summer 2023

  a simple implementation of a binary search tree


*/

#ifndef BST_312_H
#define BST_312_H

#include <cstdlib>  // Provides size_t
#include <iostream>
#include <vector>

using namespace std;

template<class ItemType>
class BST_312 {
public:

    BST_312();

    //Copy constructor
    BST_312(const BST_312& src);

    ~BST_312();

/****************************
makeEmpty

Function: Removes all the items from the BST.
Preconditions: BST has been initialized
Postconditions: All the items have been removed
*****************************/
    void makeEmpty();

/****************************
isEmpty

Function: Checks to see if there are any items in the BST.
Preconditions: BST has been initialized
Postconditions: Returns true if there are no items in the BST, else false.
*****************************/
    bool isEmpty() const;

/****************************
isFull

Function: Determines if you have any more room to add items to the BST
Preconditions: BST has been initialized
Postconditions: Returns true if there is no more room to add items, else false
*****************************/
    bool isFull() const;

/****************************
insertItem

Function: Adds newItem to the BST.
Preconditions: BST has been initialized and is not full.
Postconditions: newItem is in the proper position for a BST.
*****************************/
    void insertItem(const ItemType&);

/****************************
deleteItem

Function: Removes target from BST.
Preconditions: BST has been initialized.
Postconditions: If found, element has been removed from BST.
*****************************/
    void deleteItem(const ItemType& newItem);

/****************************
countNodes

Function: Counts the number of nodes in the BST
Preconditions: BST has been initialized.
Postconditions: returns the number of nodes in the BST
*****************************/
    int countNodes();

/****************************
preOrderTraversal

Function: Returns the preOrder (Node, Left, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> preOrderTraversal();

/****************************
inOrderTraversal

Function: Returns the inOrder (Left, Node, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> inOrderTraversal();

/****************************
postOrderTraversal

Function: returns the postOrder (Left, Right, Node) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> postOrderTraversal();

/********************
 isItemInTree

Function: Determines if a given Item is in tree.
Preconditions: BST has been initialized.
Postconditions: none
*****************************/

    bool isItemInTree(const ItemType& item);


private:
    struct TreeNode {
        ItemType data;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* root;


    void insertItem(TreeNode*& t, const ItemType& newItem);
    void inOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    int countNodes(TreeNode* t) const;
    void deleteNode(TreeNode*& node);
    void makeEmpty(TreeNode*& t);
    void deleteItem(TreeNode*& t, const ItemType& newItem);
    void getPredecessor(TreeNode* t, ItemType& data);
    void preOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    void postOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    void copyTree(TreeNode*& copy, const TreeNode* originalTree);

};

/*******************************
//Function implementations
********************************/

template<class ItemType>
BST_312<ItemType>::BST_312 ()
{
    root = NULL;
}

template<class ItemType>
BST_312<ItemType>::BST_312(const BST_312& src)
{
    copyTree(root, src.root);
}

template<class ItemType>
BST_312<ItemType>::~BST_312()
{
    makeEmpty();
}

template<class ItemType>
void BST_312<ItemType>::copyTree(TreeNode*& copy, const TreeNode* originalTree)
{
    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode;
        copy->data = originalTree->data;

        copyTree(copy->left, originalTree->left);
        copyTree(copy->right, originalTree->right);
    }
}

template<class ItemType>
void BST_312 <ItemType>::deleteNode(TreeNode*& t)
{
    ItemType info;
    TreeNode* tempPtr;

    tempPtr = t;

    if (t->left == NULL)
    {
        t = t->right;
        delete tempPtr;
    }
    else if (t->right == NULL)
    {
        t = t->left;
        delete tempPtr;
    }
    else
    {
        getPredecessor(t->left, info);
        t->data = info;
        deleteItem(t->left, info);
    }
}

//find largest in left subtree
template<class ItemType>
void BST_312 <ItemType>::getPredecessor(TreeNode* t, ItemType& data)
{
    while (t->right != NULL)
        t = t->right;
    data = t->data;
}

template<class ItemType>
void BST_312 <ItemType>::deleteItem(TreeNode*& t, const ItemType& newItem)
{
    if (t == NULL)
        return;
    else if (newItem < t->data)
        deleteItem(t->left, newItem);
    else if (newItem > t->data)
        deleteItem(t->right, newItem);
    else
        deleteNode(t);
}

template<class ItemType>
void BST_312 <ItemType>::deleteItem(const ItemType& newItem)
{
    deleteItem(root, newItem);

}

/****************************
makeEmpty

Function: Removes all the items from the BST.
Preconditions: BST has been initialized
Postconditions: All the items have been removed
*****************************/
template<class ItemType>
void BST_312 <ItemType>::makeEmpty(TreeNode*& t)
{
    /*
     * if t is not null, we will make sure to recursively call each node. what makeEmpty will do is that we
     * will deallocate (or delete) each node after visiting it.
     */
     if (t != NULL) {
         makeEmpty(t->left);
         makeEmpty(t->right);
         //t = NULL;
         delete (t);
     }
}

template<class ItemType>
void BST_312 <ItemType>::makeEmpty()
{
    /*
     * dont forget to null the root after the public function is called.
     */
    makeEmpty(root);
    root = NULL;
}

template<class ItemType>
bool BST_312 <ItemType>::isEmpty() const
{
    return root == NULL;
}

template<class ItemType>
bool BST_312 <ItemType>::isFull() const
{
    try
    {
        TreeNode* temp = new TreeNode;
        delete temp;
        return false;
    }
    catch (std::bad_alloc)
    {
        return true;
    }
}

/****************************
insertItem

Function: Adds newItem to the BST.
Preconditions: BST has been initialized and is not full.
Postconditions: newItem is in the proper position for a BST.
*****************************/
template<class ItemType>
void BST_312 <ItemType>::insertItem(TreeNode*& t, const ItemType& newItem)
{
    /*
     * while the tree is not null we will insert the new item depending on where the
     * position is better in the tree. If the new item we are trying to add ends up
     * being the same as one of the nodes then we will do nothing since it
     * already exists.
     */
    if (t != NULL) {
        if (newItem == t->data) {
            return;
        }
        else if (newItem < t -> data) {
            return insertItem(t->left, newItem);
        }
        else {
            return insertItem(t->right, newItem);
        }
    }
    //otherwise we make a new node.
    t = new TreeNode;
    t-> data = newItem;
    t -> left = NULL;
    t -> right = NULL;
}

template<class ItemType>
void BST_312 <ItemType>::insertItem(const ItemType& newItem)
{
    /*
     * we add the pointer of the beginning of the tree (since insertion
     * happens since the beginning of the tree) as well as the item
     * that we want to add.
     */
    insertItem(root, newItem);
}

/****************************
countNodes

Function: Counts the number of nodes in the BST
Preconditions: BST has been initialized.
Postconditions: returns the number of nodes in the BST
*****************************/
template<class ItemType>
int BST_312 <ItemType>::countNodes(TreeNode* t) const
{
    /*
     * unless the tree is empty, we will count every left and right node plus 1
     * (since that's the root of the tree that we have to account for at the
     * end)
     */
    if (t == NULL) {
        return 0;
    }

    int l = countNodes(t->left);
    int r = countNodes(t->right);

    return (1 + l + r);
}

template<class ItemType>
int BST_312 <ItemType>::countNodes()
{
    return countNodes(root);
    //YOUR CODE GOES HERE
}

/****************************
preOrderTraversal

Function: Returns the preOrder (Node, Left, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
template<class ItemType>
void BST_312 <ItemType>::preOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    /*
     * unless the node is not empty, we will make sure that we push the node into the vector and then
     * iterate from left to right after (recursively).
     */
    if (t == NULL) {
        return;
    }
    result.push_back(t->data);
    preOrderTraversal(t->left, result);
    preOrderTraversal(t->right, result);

}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::preOrderTraversal()
{
    /*
     * return the vector.
     */
    //YOUR CODE GOES HERE
    vector<ItemType>result;
    preOrderTraversal(root, result);
    return result;
}

/****************************
inOrderTraversal

Function: Returns the inOrder (Left, Node, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
template<class ItemType>
void BST_312 <ItemType>::inOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    /*
     * we first print all the data in the left node then the data in the right
     * node (recursively) as a way to put things in order (from smallest to largest size)
     */
    if (t != NULL) {
        if (t -> left != NULL) {
            inOrderTraversal(t -> left, result);
        }
        result.push_back(t -> data);
        if (t -> right != NULL) {
            inOrderTraversal(t -> right, result);
        }
    }
    /*
     * in case the node ends up being null
     */
    else {
        return;
    }
}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::inOrderTraversal()
{
    /*
     * return the vector
     */
    vector<ItemType>result;
    inOrderTraversal(root, result);
    return result;
    //YOUR CODE GOES HERE
}

/****************************
postOrderTraversal

Function: returns the postOrder (Left, Right, Node) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
template<class ItemType>
void BST_312 <ItemType>::postOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    /*
     * if the treenode is null return (as a base case)
     * otherwise we want to make sure that for post order traversal we visit notes from left to right and then
     * print the node.
     */
    if (t == NULL) {
        return;
    }

    postOrderTraversal(t -> left, result);
    postOrderTraversal(t -> right, result);
    result.push_back(t->data);
    //YOUR CODE GOES HERE
}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::postOrderTraversal()
{
    /*
     * return the vector
     */
    vector<ItemType>result;
    postOrderTraversal(root, result);
    return result;
    //YOUR CODE GOES HERE
}

/********************
 isItemInTree

Function: Determines if a given Item is in tree.
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
template<class ItemType>
bool BST_312 <ItemType>::isItemInTree(const ItemType& item)
{
    // make a temporary struct for the root.
    TreeNode *temp = root;
    /*
     * if the root is not null then we will check its data and see if it equals to the key.
     * otherwise we will move from left to right until it matches our desired outcome and then return true.
     * we will return false if we have visited all nodes but have not found the key.
     */
    while (temp != NULL) {
        if (item == temp -> data) {
            return true;
        }
        else if (item < temp -> data) {
            temp = temp -> left;
        }
        else {
            temp = temp -> right;
        }
    }
    return false;
    //YOUR CODE GOES HERE

}
#endif

