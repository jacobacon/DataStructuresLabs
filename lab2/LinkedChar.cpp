//
// Created by Jacob Beneski on 6/16/17.
//

#include <iostream>
#include "LinkedChar.h"

using namespace std;

LinkedChar::LinkedChar() : headPtr(nullptr), length(0) {
}


LinkedChar::LinkedChar(std::string convertString) {

    int counter = 0;
    while (counter < convertString.length()) {
        add(convertString.at(counter));
        counter++;
    }
}


LinkedChar::~LinkedChar() {
    clear();
}


bool LinkedChar::add(const char newItem) {

    Node *nextNodePtr = new Node();
    nextNodePtr->setNext(headPtr);
    nextNodePtr->setItem(newItem);

    headPtr = nextNodePtr;

    length++;

    return true;


}

void LinkedChar::setString(string newString) {

    int counter = 0;
    while (counter < newString.length()) {
        add(newString.at(counter));
        counter++;
    }


}


bool LinkedChar::remove() {
    return true;
}

void LinkedChar::clear() {

    Node *deletePtr = headPtr;
    while (headPtr != nullptr) {

        headPtr = headPtr->getNext();

        deletePtr->setNext(nullptr);
        delete deletePtr;

        deletePtr = headPtr;


    }

    length = 0;


}

int LinkedChar::getLength() {
    return length;
}

bool LinkedChar::isEmpty() {
    return length == 0;
}

bool LinkedChar::contains() {
    return false;
}

int LinkedChar::find() {
    return 0;
}

string LinkedChar::toString() {
    //Returns a string with the value of the linked list.

    std::string charString;


    Node *currentPtr = headPtr;

    int counter = 0;
    while ((counter < length) && (currentPtr != nullptr)) {
        charString = currentPtr->getItem() + charString;
        currentPtr = currentPtr->getNext();
        counter++;
    }


    return charString;

}

char getValue(int index) {

}






