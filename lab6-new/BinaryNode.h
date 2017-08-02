//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.h */

#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

template<class ItemType>
class BinaryNode {
private:
    ItemType item;           // Data portion
    std::shared_ptr<BinaryNode<ItemType>> leftChildPtr;   // Pointer to left child
    std::shared_ptr<BinaryNode<ItemType>> rightChildPtr;  // Pointer to right child

public:
    BinaryNode() {
        item = nullptr;
        leftChildPtr = nullptr;
        rightChildPtr = nullptr;

    };

    BinaryNode(const ItemType &anItem) {
        item = anItem;
        leftChildPtr = nullptr;
        rightChildPtr = nullptr;
    };

    BinaryNode(const ItemType &anItem,
               std::shared_ptr<BinaryNode<ItemType>> leftPtr,
               std::shared_ptr<BinaryNode<ItemType>> rightPtr){
        item = anItem;
        leftChildPtr = leftPtr;
        rightChildPtr = rightPtr;
    };

    void setItem(const ItemType &anItem){
        item = anItem;
    };

    ItemType getItem() const{
        return item;
    };

    bool isLeaf() const{
        return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
    };

    auto getLeftChildPtr() const{
        return leftChildPtr;
    };

    auto getRightChildPtr() const{
        return rightChildPtr;
    };

    void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr){
        leftChildPtr = leftPtr;
    };

    void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr){
        rightChildPtr = rightPtr;
    };
}; // end BinaryNode



#endif 
