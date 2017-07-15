#include <iostream>
#include "niceKid.h"

using namespace std;

LinkedList<niceKid> niceList;

void createList() {


    cout << "Enter the Name of Nice Kid: ";
    std::string name;

    int nameCounter = 1;

    while (getline(std::cin, name)) {
        if (name.empty())
            break;
        niceKid nice(name);


        string gift;

        int giftCounter = 1;
        cout << "Enter a gift for " << name << ": ";
        while (getline(std::cin, gift)) {
            if (gift.empty())
                break;

            cout << "Enter a gift for " << name << ": ";


            nice.getGiftsPtr()->insert(giftCounter, gift);

            giftCounter++;


        }

        niceList.insert(nameCounter, nice);

        nameCounter++;
        std::cout << std::endl << "Enter the Name of Nice Kid: ";

    }


}

void outputList() {

    for (int i = 1; i <= niceList.getLength(); i++) {
        cout << "Gifts for: " << niceList.getEntry(i).getName() << endl;

        int giftLength = niceList.getEntry(i).getGiftsPtr()->getLength();
        for (int j = 1; j <= giftLength; j++) {

            cout << "Found gifts: " << niceList.getEntry(i).getGiftsPtr()->getEntry(j) << endl;

        }
    }


}


int main() {
    createList();
    outputList();
    return 0;
}