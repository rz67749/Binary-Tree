#include <iostream>
#include "BinaryTree.h"
using namespace std;



BinaryTree::BinaryTree(){
    root = NULL;
}// Constructor

BinaryTree::~BinaryTree(){
    destructor(root);
}// Destructor

void BinaryTree::insert(ItemType key){
    add(root, key);
}// insert

void BinaryTree::deleteItem(ItemType key){

}// deleteItem

void BinaryTree::retrieve(ItemType &item, bool &found) const{

}// retrieve

void BinaryTree::preOrder() const{
    printPreOrder(root);
    cout << endl;
}// preOrder

void BinaryTree::inOrder() const{
    printInOrder(root);
    cout << endl;
}// inOrder

void BinaryTree::postOrder() const{
    printPostOrder(root);
    cout << endl;
}// postOrder

int BinaryTree::getLength(){
    return countNodes(root);
}// getLength

void BinaryTree::getSameLevelNonsiblings(ItemType &key){
    bool found;
    int lvl = 0;
    getLevel(root, key, found, lvl); //find which level to print
    if (found){
        found = false;
        printNonsiblings(root, key, lvl, 0, found); // prints nonsiblings
        if (!found){
            cout << "No same level non sibling found."; // in case no nonsiblings are present
        }
        cout << endl;
    } else {
        cout << "Item not in the tree." << endl; // item not present in tree
    }
} // getSameLevelNonsiblings

//recursive function for getLength
int BinaryTree::countNodes(NodeType* tree){
    if (tree == NULL){
        return 0;
    } else {
        return countNodes(tree->left) + countNodes(tree->right) + 1;
    }
}// countNodes

// finds the level that is being searched for nonsiblings 
void BinaryTree::getLevel(NodeType* tree, ItemType item, bool &found, int &lvl){
    if (tree == NULL){
        found = false;
    } else if (item.compareTo(tree->key) == LESS){
        lvl++;
        getLevel(tree->left, item, found, lvl);
    } else if (item.compareTo(tree->key) == GREATER){
        lvl++;
        getLevel(tree->right, item, found, lvl);
    } else {
        found = true;
    }
} // getLevel

// prints an nonsiblings in the same level
void BinaryTree::printNonsiblings(NodeType* tree, ItemType item, int lvl, int searchLvl, bool &found){
    if (tree != NULL){
        bool moreLeft = false, moreRight = false;
        if (tree->left != NULL){
            moreLeft = true;
        }
        if (tree->right != NULL){
            moreRight = true;
        }
    
        if ((moreLeft && item.compareTo(tree->left->key) == EQUAL) || (moreRight && item.compareTo(tree->right->key) == EQUAL)){
            // do nothing
        } else if (lvl == searchLvl && searchLvl != 0){ // print nodes on same level
            tree->key.print();
            cout << " ";
            found = true;
        } else {
            printNonsiblings(tree->left, item, lvl, searchLvl+1, found); //recursion calls
            printNonsiblings(tree->right, item, lvl, searchLvl+1, found);
        }
    }
} //printNonsiblings

//recursive function for insert
void BinaryTree::add(NodeType*& tree, ItemType item){
    if (tree == NULL){
        tree = new NodeType();
        tree->right = NULL;
        tree->left = NULL;
        tree->key = item;
    } else if (item.compareTo(tree->key) == EQUAL){
        cout << "Item already in tree." << endl;
        cout << "In-Order: ";
        printInOrder(root);
    } else if (item.compareTo(tree->key) == LESS){
        add(tree->left, item);
    } else {
        add(tree->right, item);
    }
}

//recursive function for destructor
void BinaryTree::destructor(NodeType* tree){
    if (tree != NULL){
        destructor(tree->left);
        destructor(tree->right);
        delete tree;
    }
}

// recursive function for inOrder printing
void BinaryTree::printInOrder(NodeType* tree) const{
    if (tree != NULL){
        printInOrder(tree->left);
        tree->key.print();
        cout << " ";
        printInOrder(tree->right);
    }
}// printInOrder

// recursive function for preOrder printing
void BinaryTree::printPreOrder(NodeType* tree) const{
    if (tree != NULL){
        tree->key.print();
        cout << " ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}// printPreOrder

// recursive function for postOrder printing
void BinaryTree::printPostOrder(NodeType* tree) const{
    if (tree != NULL){
        printPostOrder(tree->left);
        printPostOrder(tree->right);
        tree->key.print();
        cout << " ";
    }
}// printPostOrder
