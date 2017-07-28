#include <iostream>
#include "SortedLinkList.h"
using namespace std;

std::unique_ptr<SortedListInterface<int>> sortedListPtr = make_unique<SortedLinkList<int>>();

//SortedLinkList<int> sortedLinkList;



void insertRandom(){

    for(int i = 0; i < 20; i++){
        //cout << rand() % 100 + 1 << endl;

        sortedListPtr->insertSorted(rand() % 100 + 1);

    }
}

void output(){

    for(int i = 1; i <= sortedListPtr->getLength(); i++){
        cout << sortedListPtr->getEntry(i) << endl;
    }

};

int main() {
    insertRandom();
    output();
    return 0;
}