//
// Created by Jacob Beneski on 7/5/17.
//

#ifndef LAB4_NICELIST_H
#define LAB4_NICELIST_H

#include "niceKid.h"


class niceList {
private:
public:
    niceList();
    LinkedList<std::string> list;
    void createGiftObject(std::string name);
    void addGiftItem();


};


#endif //LAB4_NICELIST_H
