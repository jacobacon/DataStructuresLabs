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
    SortedLinkList();

    SortedLinkList(const SortedLinkList<ItemType> &aList);
    virtual ~SortedLinkList();

    bool insertSorted(const ItemType &anEntry);
    bool removeSorted(const ItemType &anEntry);
    int getPosition(const ItemType &anEntry);

    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const;

};
#endif //LAB5_SORTEDLINKLIST_H
