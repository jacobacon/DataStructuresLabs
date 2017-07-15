//
// Created by Jacob Beneski on 7/5/17.
//

#include "niceKid.h"

using namespace std;


niceKid::niceKid() : name("") {
    gifts = std::make_shared<LinkedList<string>>();
}


niceKid::niceKid(string setName) : name(setName) {
    gifts = std::make_shared<LinkedList<string>>();
}


string niceKid::getName() {
    return name;
}

shared_ptr<ListInterface<string>> niceKid::getGiftsPtr() {
    return gifts;
}

void niceKid::clearGifts() {
    gifts->clear();
}