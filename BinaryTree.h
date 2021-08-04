#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include "ItemType.h"

struct NodeType{
    ItemType key;
    NodeType *left;
    NodeType *right;
};

class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();
    void insert(ItemType key);
    void deleteItem(ItemType key);
    void retrieve(ItemType &item, bool &found) const;
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    int getLength();
    void getSameLevelNonsiblings(ItemType &key);

    // recursion functions
    void getLevel(NodeType* tree, ItemType item, bool &found, int &lvl);
    void printNonsiblings(NodeType* tree, ItemType item, int lvl, int searchLvl, bool &found);
    int countNodes(NodeType* tree);
    void add(NodeType*& tree, ItemType item);
    void destructor(NodeType* tree);
    void printInOrder(NodeType* tree) const;
    void printPostOrder(NodeType* tree) const;
    void printPreOrder(NodeType* tree) const;

private:
    NodeType *root;
};
#endif
