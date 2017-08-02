//
// Created by Jacob Beneski on 7/21/17.
//

#ifndef LAB5_SORTEDLINKLIST_H
#define LAB5_SORTEDLINKLIST_H

#include <memory>
#include "SortedListInterface.h"
#include "ListInterface.h"
#include "PrecondViolatedExcep.h"
#include "LinkedList.h"
//#include "SortedLinkList.cpp"

template <class ItemType>
class SortedLinkList : public SortedListInterface<ItemType>{

private:
    std::unique_ptr<ListInterface<ItemType>> listPtr;
public:
    SortedLinkList() { listPtr = std::make_unique<LinkedList<ItemType>>(); };

    SortedLinkList(const SortedLinkList<ItemType> &aList) {};
    virtual ~SortedLinkList() { clear(); };

    bool insertSorted(const ItemType &anEntry) { return false;};
    bool removeSorted(const ItemType &anEntry) { return false;};
    int getPosition(const ItemType &anEntry) const { return 1; };

    bool isEmpty() const { return listPtr->getLength()==0; };
    int getLength() const { return listPtr->getLength(); };
    bool remove(int position) { return false; };
    void clear() {};
    ItemType getEntry(int position) const { return listPtr->getEntry(position); };

};
#endif //LAB5_SORTEDLINKLIST_H
