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

void append(LinkedChar linkedChar) {

}

void LinkedChar::setString(string newString) {

    clear();

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

bool LinkedChar::contains(LinkedChar linkedChar) {

    Node *internalPtr = headPtr;
    Node *checkPtr = linkedChar.headPtr;

    int correctCounter = 0;

    int counter = 0;


    while ((internalPtr != nullptr) && (counter <= length)) {

        int checkCounter = 0;
        while (checkCounter <= linkedChar.getLength()) {

            if (internalPtr->getItem() == checkPtr->getItem()) {
                correctCounter++;
                cout << "correct value found: " << checkPtr->getItem() << endl;
            }

            cout << checkPtr->getItem();
            checkPtr = checkPtr->getNext();


            checkCounter++;

        }

        internalPtr = internalPtr->getNext();


        counter++;
    }

    return correctCounter == linkedChar.getLength();
}

int LinkedChar::find(char c) {


    int counter = length;
    Node *nodePtr = headPtr;

    while ((counter >= 0) && (nodePtr != nullptr)) {


        if (nodePtr->getItem() == c) {
            return counter;
        } else {
            nodePtr = nodePtr->getNext();
            counter--;
        }


    }
    cout << "Couldn't find anything..." << endl;

    return -1;
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

void LinkedChar::append(LinkedChar &linkedChar) {


    Node *nodePtr = headPtr;

    int counter = 0;

    while ((nodePtr != nullptr) && (counter < length)) {
        nodePtr = nodePtr->getNext();
        counter++;
    }

    length += linkedChar.getLength();

    headPtr->setNext(linkedChar.getHeadPtr());


}


Node *LinkedChar::getHeadPtr() {
    return headPtr;
}









