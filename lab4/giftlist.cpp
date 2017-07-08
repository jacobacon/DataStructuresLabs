#include <iostream>
#include "niceKid.h"
using namespace std;

LinkedList<niceKid> niceList;

void createList(){



    cout << "Enter the Name of Nice Kid: ";
    std::string name;

    int nameCounter = 1;

    while (getline(std::cin, name))
    {
        cout << "Length of nameList: " << nameCounter << endl;
        if (name.empty())
            break;
        niceKid nice(name);
        niceList.insert(nameCounter, nice);

        string gift;

        int giftCounter = 1;
        cout << "Enter a gift for " << name << ": ";
        while(getline(std::cin, gift)){
            if(gift.empty())
                break;

            cout << "Enter a gift for " << name << ": ";
            

            //niceList.getEntry(nameCounter).getGifts().insert(giftCounter,gift);
            giftCounter++;

            cout << "Length of gifts: " << niceList.getEntry(nameCounter).getGifts().getLength() << endl;
            cout << "Gift counter: " << giftCounter << endl;

          //  niceList.getEntry(nameCounter).getGif
        }

        nameCounter++;
        std::cout << std::endl << "Enter the Name of Nice Kid: ";

    }





}

void outputList(){
cout << "Enter loop" << endl;

    for(int i = 1; i <= niceList.getLength(); i++){
        cout << "Inside the loop at: " << i;


        LinkedList<string> temp = niceList.getEntry(i).getGifts();

        cout << "Got temp list with lenght: " << temp.getLength() << endl;

        cout << "Entering second list" << endl;
        for(int i = 1; i <= temp.getLength(); i++){

            cout << temp.getEntry(i);

        }
    }




}




int main() {
    createList();
    outputList();
    return 0;
}