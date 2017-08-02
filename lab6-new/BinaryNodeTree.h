//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT binary tree: Link-based implementation.
 Listing 16-3.
 @file BinaryNodeTree.h */

#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include <memory>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType> {
private:
    std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------

    int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const {
        if (subTreePtr == nullptr)
            return 0;
        else
            return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                                getHeightHelper(subTreePtr->getRightChildPtr()));
    };

    int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const {
        if (subTreePtr == nullptr)
            return 0;
        else
            return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())
                   + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    };

    // Recursively adds a new node to the tree in a left/right fashion to
    // keep the tree balanced.
    auto balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                     std::shared_ptr<BinaryNode<ItemType>> newNodePtr) {

        if (subTreePtr == nullptr)
            return newNodePtr;
        else {
            auto leftPtr = subTreePtr->getLeftChildPtr();
            auto rightPtr = subTreePtr->getRightChildPtr();

            if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) {
                rightPtr = balancedAdd(rightPtr, newNodePtr);
                subTreePtr->setRightChildPtr(rightPtr);
            } else {
                leftPtr = balancedAdd(leftPtr, newNodePtr);
                subTreePtr->setLeftChildPtr(leftPtr);
            }  // end if

            return subTreePtr;
        }  // end if
    };

    // Copies values up the tree to overwrite value in current node until
    // a leaf is reached; the leaf is then removed, since its value is
    // stored in the parent.
    std::shared_ptr<BinaryNode<ItemType>> moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) {
        auto leftPtr = subTreePtr->getLeftChildPtr();
        auto rightPtr = subTreePtr->getRightChildPtr();
        int leftHeight = getHeightHelper(leftPtr);
        int rightHeight = getHeightHelper(rightPtr);
        if (leftHeight > rightHeight) {
            subTreePtr->setItem(leftPtr->getItem());
            leftPtr = moveValuesUpTree(leftPtr);
            subTreePtr->setLeftChildPtr(leftPtr);
            return subTreePtr;
        } else {
            if (rightPtr != nullptr) {
                subTreePtr->setItem(rightPtr->getItem());
                rightPtr = moveValuesUpTree(rightPtr);
                subTreePtr->setRightChildPtr(rightPtr);
                return subTreePtr;
            } else {
                //this was a leaf!
                // value not important
                return nullptr;
            }  // end if
        }  // end if
    };

    // Removes the target value from the tree by calling moveValuesUpTree
    // to overwrite value with value from child.
    virtual std::shared_ptr<BinaryNode<ItemType>>
    removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                const ItemType target, bool &success) {
        if (subTreePtr == nullptr) // not found here
            return subTreePtr;

        if (subTreePtr->getItem() == target) // found it
        {
            subTreePtr = moveValuesUpTree(subTreePtr);
            success = true;
            return subTreePtr;
        } else {
            auto targetNodePtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
            subTreePtr->setLeftChildPtr(targetNodePtr);
            if (!success) // no need to search right subTree
            {
                targetNodePtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
                subTreePtr->setRightChildPtr(targetNodePtr);
            }  // end if

            return subTreePtr;
        }  // end if
    };

    // Recursively searches for target value in the tree by using a
    // preorder traversal.
    auto findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                  const ItemType &target,
                  bool &success) const {
        if (treePtr == nullptr) // not found here
            return treePtr;

        if (treePtr->getItem() == target) // found it
        {
            success = true;
            return treePtr;
        }
        else
        {
            std::shared_ptr<BinaryNode<ItemType>> targetNodePtr = findNode(treePtr->getLeftChildPtr(), target, success);
            if (!success) // no need to search right subTree
            {
                targetNodePtr = findNode(treePtr->getRightChildPtr(), target, success);
            }  // end if

            return targetNodePtr;
        }  // end if
    };

    // Copies the tree rooted at treePtr and returns a pointer to
    // the copy.
    std::shared_ptr<BinaryNode<ItemType>> copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const {
        std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

        // Copy tree nodes during a preorder traversal
        if (oldTreeRootPtr != nullptr) {
            // Copy node
            newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(), nullptr, nullptr);
            newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
            newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
        }  // end if

        return newTreePtr;
    };

    // Recursively deletes all nodes from the tree.
    void destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) {
        if (subTreePtr != nullptr) {
            destroyTree(subTreePtr->getLeftChildPtr());
            destroyTree(subTreePtr->getRightChildPtr());
            subTreePtr.reset(); // decrement reference count to node
        }  // end if
    };

    // Recursive traversal helper methods:
    void preorder(void visit(ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
        if (treePtr != nullptr) {
            ItemType theItem = treePtr->getItem();
            visit(theItem);
//      visit(treePtr->getItem());
            preorder(visit, treePtr->getLeftChildPtr());
            preorder(visit, treePtr->getRightChildPtr());
        }  // end if
    };

    void inorder(void visit(ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
        if (treePtr != nullptr) {
            inorder(visit, treePtr->getLeftChildPtr());
            ItemType theItem = treePtr->getItem();
            visit(theItem);
            inorder(visit, treePtr->getRightChildPtr());
        }  // end if
    };

    void postorder(void visit(ItemType &), std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
        if (treePtr != nullptr) {
            postorder(visit, treePtr->getLeftChildPtr());
            postorder(visit, treePtr->getRightChildPtr());
            ItemType theItem = treePtr->getItem();
            visit(theItem);
        } // end if
    };

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinaryNodeTree() {

    };

    BinaryNodeTree(const ItemType &rootItem) {
        rootPtr = std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr);
    };

    BinaryNodeTree(const ItemType &rootItem,
                   const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                   const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr) {
        rootPtr = std::make_shared<BinaryNode<ItemType>>(rootItem, copyTree(leftTreePtr->rootPtr),
                                                         copyTree(rightTreePtr->rootPtr));
    };

    BinaryNodeTree(const BinaryNodeTree<ItemType> &tree){
        rootPtr = copyTree(tree.rootPtr);
    };

    virtual ~BinaryNodeTree(){
        destroyTree(rootPtr);
    };

    //------------------------------------------------------------
    // Public BinaryTreeInterface Methods Section.
    //------------------------------------------------------------
    bool isEmpty() const{
        return rootPtr == nullptr;
    };

    int getHeight() const{
        return getHeightHelper(rootPtr);
    };

    int getNumberOfNodes() const{
        return getNumberOfNodesHelper(rootPtr);
    };

    ItemType getRootData() const throw(PrecondViolatedExcep){
        if (isEmpty())
            throw PrecondViolatedExcep("getRootData() called with empty tree.");

        return rootPtr->getItem();
    };

    void setRootData(const ItemType &newData){
        if (isEmpty())
            rootPtr = std::make_shared<BinaryNode<ItemType>>(newData, nullptr, nullptr);
        else
            rootPtr->setItem(newData);
    };

    bool add(const ItemType &newData){
        auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
        rootPtr = balancedAdd(rootPtr, newNodePtr);
        return true;
    }; // Adds a node
    bool remove(const ItemType &data){
        bool isSuccessful = false;
        rootPtr = removeValue(rootPtr, data, isSuccessful);
        return isSuccessful;
    }; // Removes a node
    void clear(){
        destroyTree(rootPtr);
        rootPtr.reset();
    };

    ItemType getEntry(const ItemType &anEntry) const throw(NotFoundException){
        bool isSuccessful = false;
        auto binaryNodePtr = findNode(rootPtr, anEntry, isSuccessful);

        if (isSuccessful)
            return binaryNodePtr->getItem();
        else
            throw NotFoundException("Entry not found in tree!");
    };

    bool contains(const ItemType &anEntry) const{
        bool isSuccessful = false;
        findNode(rootPtr, anEntry, isSuccessful);
        return isSuccessful;
    };

    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse(void visit(ItemType &)) const{
        preorder(visit, rootPtr);
    };

    void inorderTraverse(void visit(ItemType &)) const{
        inorder(visit, rootPtr);
    };

    void postorderTraverse(void visit(ItemType &)) const{
        postorder(visit, rootPtr);
    };

    }; // end BinaryNodeTree

#endif
