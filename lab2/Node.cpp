//
// Created by Jacob Beneski on 6/16/17.
//

#include "Node.h"

Node::Node() : nextPtr(nullptr) {
}

Node::Node(char aChar) : character(aChar), nextPtr(nullptr) {
}

Node::Node(char aChar, Node *nextPtr) : character(aChar), nextPtr(nextPtr) {
}

char Node::getItem() {
    return character;
}

Node *Node::getNext() const {
    return nextPtr;
}

void Node::setNext(Node *nextNodePtr) {
    nextPtr = nextNodePtr;
}

void Node::setItem(char newCharacter) {
    character = newCharacter;
}