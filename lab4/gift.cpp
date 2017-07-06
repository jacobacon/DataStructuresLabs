//
// Created by Jacob Beneski on 7/5/17.
//

#include "gift.h"

using namespace std;



gift::gift() : name(""), giftList(){
}

void gift::setName(string newName) {
    name = newName;
}


string gift::getName(){
    return name;
}

void gift::addGift(int i, std::string gift) {
    giftList.insert(i, gift);
}

string gift::getGift(int i) {
    return giftList.getEntry(i);
}
