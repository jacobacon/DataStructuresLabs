//
// Created by Jacob Beneski on 7/5/17.
//

#include "niceKid.h"

using namespace std;



niceKid::niceKid() : name(""), giftList(){
}

niceKid::niceKid(string setName) : name(setName), giftList() {

}

void niceKid::setName(string newName) {
    name = newName;
}

void niceKid::addFakeItem() {

    giftList.insert(1, "puppy");

    cout << "Added a puppy" << endl;
    cout << "Length is now: " << giftList.getLength();
}


string niceKid::getName(){
    return name;
}

void niceKid::addGiftItem(int i, std::string gift) {
    giftList.insert(i, gift);
}

string niceKid::getGiftItem(int i) {
    return giftList.getEntry(i);
}

LinkedList<string> niceKid::getGifts() {
    return giftList;
}

void niceKid::clearGifts() {
    giftList.clear();
}