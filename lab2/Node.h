//
// Created by Jacob Beneski on 6/16/17.
//

#ifndef LAB2_NODE_H
#define LAB2_NODE_H


class Node {
private:
    char character; //item type
    Node *nextPtr; //pointer to next node

public:
    Node();

    Node(char aChar);

    Node(char aChar, Node *nextNodePtr);

    void setItem(char aChar);

    void setNext(Node *nextNodePtr);

    char getItem();

    Node *getNext() const;
};


#endif //LAB2_NODE_H
