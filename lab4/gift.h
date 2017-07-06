//
// Created by Jacob Beneski on 7/5/17.
//

#ifndef LAB4_GIFT_H
#define LAB4_GIFT_H

#include <string>
#include "LinkedList.h"

class gift {
private:
    std::string name;
    LinkedList<std::string> giftList;
public:
    gift();
    void setName(std::string name);
    std::string getName();
    void addGift(int i, std::string gift);
    std::string getGift(int i);
    LinkedList<std::string> getGifts();
    void clearGifts();
};


#endif //LAB4_GIFT_H
