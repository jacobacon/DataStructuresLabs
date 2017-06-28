//
// Created by Jacob Beneski on 6/16/17.
//

#ifndef LAB2_LINKEDCHAR_H
#define LAB2_LINKEDCHAR_H

#include "Node.h"
#include <string>


class LinkedChar {
private:
    Node *headPtr; //First Node
    int length; //Length of LinkedChar
    // Node *getPointerTo(char target);

public:
    LinkedChar(); //Default Constructor
    LinkedChar(std::string convertString); //Convert Constructor
    virtual ~LinkedChar(); //Destructor
    int getLength();

    void setString(std::string newString);

    bool isEmpty();

    bool add(const char newItem);

    bool remove();

    void clear();

    bool contains(LinkedChar linkedChar);

    int find(char c);

    std::string toString();

    void append(LinkedChar &linkedChar);

    Node *getHeadPtr();

};


#endif //LAB2_LINKEDCHAR_H
