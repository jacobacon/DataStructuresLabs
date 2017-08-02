//
// Created by Jacob Beneski on 7/21/17.
//


#include "LinkedList.h"
#include "SortedLinkList.h"


template <class ItemType>
SortedLinkList<ItemType>::SortedLinkList(){
    listPtr = std::make_unique<LinkedList<ItemType>>();
}


template <class ItemType>
SortedLinkList<ItemType>::SortedLinkList(const SortedLinkList &aList) : listPtr(std::make_unique<LinkedList<ItemType>>()) {
    for(int i =1; i<aList.getLength(); i++){
        listPtr->insert(i, aList.getEntry(i));
    }
}

template <class ItemType>
SortedLinkList<ItemType>::~SortedLinkList() {
    clear();
}

template <class ItemType>
bool SortedLinkList<ItemType>::insertSorted(const ItemType &anEntry) {
    int newPosition = std::abs(getPosition(anEntry));
    return listPtr->insert(newPosition, anEntry);
}

template <class ItemType>
int SortedLinkList<ItemType>::getPosition(const ItemType &anEntry) const{

    int position = 1;
    while ((position <= getLength()) && (anEntry > getEntry(position))){
        position++;
    }

    if((position > getLength()) || (anEntry != getEntry(position))){
        position = -position;
    }

    return position;
}

template <class ItemType>
bool SortedLinkList<ItemType>::removeSorted(const ItemType &anEntry) {

}



template <class ItemType>
bool SortedLinkList<ItemType>::isEmpty() const {
    return listPtr->isEmpty();
}

template <class ItemType>
int SortedLinkList<ItemType>::getLength() const {
    return listPtr->getLength();
}

template <class ItemType>
bool SortedLinkList<ItemType>::remove(int position) {
    return listPtr->remove(position);
}

template <class ItemType>
void SortedLinkList<ItemType>::clear() {
    listPtr->clear();
}

template <class ItemType>
ItemType SortedLinkList<ItemType>::getEntry(int position) const {
    return listPtr->getEntry(position);
}