//
// Created by Jacob Beneski on 7/5/17.
//

#ifndef LAB4_GIFT_H
#define LAB4_GIFT_H

#include <string>
#include "LinkedList.h"

class niceKid {
private:
    std::string name;
    LinkedList<std::string> giftList;
public:
    niceKid();
    niceKid(std::string setName);
    void setName(std::string name);
    std::string getName();
    void addGiftItem(int i, std::string gift);
    void addFakeItem();
    std::string getGiftItem(int i);
    LinkedList<std::string> getGifts();
    void clearGifts();
};


#endif //LAB4_GIFT_H
