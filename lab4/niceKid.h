//
// Created by Jacob Beneski on 7/5/17.
//

#ifndef LAB4_GIFT_H
#define LAB4_GIFT_H

#include <string>
#include "LinkedList.h"
#include "ListInterface.h"

class niceKid {
private:
    std::string name;
    std::shared_ptr<ListInterface<std::string>> gifts;
public:
    niceKid();

    niceKid(std::string setName);

    std::string getName();

    std::shared_ptr<ListInterface<std::string>> getGiftsPtr();

    void clearGifts();
};


#endif //LAB4_GIFT_H
