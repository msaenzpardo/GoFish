Melanie Saenzpardo 
ECE312, Summer 2023 

BST312 

The purpose of this header file is portray the implementation and testing of
a binary search tree (BST). By the header file being a templated BST header
file, it should work for any data type or object (int, doubles, strings, chars). 

The following are public functions that you as a user are allowed to use. Further
explanation will be provided down below: 

**please assume that for all functions (except isEmpty & isFull) the BST must
have already been initialized**


void makeEmpty(): This function will remove all items from the BST. Only
condition is that the BST must already be initialized (meaning that it 
must have at least one node). 

bool isEmpty(): This function will either return true or false when there
are any items left in the BST. It will return true if there are no items in
the BST. 

bool isFull(): This function will either return true or false to see if there
is anymore room to add items to the BST. It will return true when there is no
more room to add. This is useful becasue it prevents stack overflow from 
happening. 

void insertItem(insert item to add): This function will add a new item to 
the BST and place it in the proper location. In case that the item already
exists, then it won't do anything. 

void deleteItem(insert item to delete): This function will remove the wanted
item from the BST (if found) as long as the BST has been initialized. 

int countNodes(): This function will count the number of nodes in the BST as
long as the BST has been initialized (meaning its root is not null) it will
return the number of nodes in the BST. 

vector<ItemType> preOrderTravelsal(): This function will return the BST
in the order from which they came from (how they were when being inputted/
without any sorting done to it). 

vector<ItemType> inOrderTraversal(): This function will return the BST from 
smallest to largest as they come from in the internal nodes (so basically
sorted in increasing size).

vector<ItemType> postOrderTraversal(): This function will return the BST 
by how it finally ended up looking in the BST (so it will visit the left
node, right node, and then the actual node). 

bool isItemInTree(insert key): This function will return true whenever the 
target that we are trying to find in the BST is found. Otherwise, it will 
return a false. The only condition is that the BST must have already been initialized.

***Recommendations/Things to Watch out For:

In order to print out the vector, it is suggested to use in main


template <typename T>
void print(vector<T> vec){
    for(auto vecVal : vec){
        cout << vecVal << endl;;
    }
}

so that whenever we call any of the traversal functions the vector will print
automatically and we will be able to see our results. 


// test taking out the root. 