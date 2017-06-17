#include <iostream>
#include "LinkedChar.h"

//Driver Program for Lab 2

using namespace std;

LinkedChar linkedChar;

LinkedChar linkedCharString("Hello World");


void linkedCharTester(int value) {

    switch (value) {
        case 1:

            cout << linkedChar.toString() << endl;
            break;
        case 2:

            cout << linkedCharString.toString() << endl;
            break;


    }


    cout << value << endl;


    cout << linkedChar.getLength() << endl;


    linkedChar.add('b');
    linkedChar.add('a');
    linkedChar.add('n');
    linkedChar.add('a');
    linkedChar.add('n');
    linkedChar.add('a');

    cout << linkedChar.toString() << endl;

    linkedChar.clear();

    cout << linkedChar.getLength() << endl;

    linkedChar.setString("Hello");

    cout << linkedChar.toString() << endl;


}

void menu() {
    cout << " --- Linked Character Chain Test Menu --- " << endl;
    cout << "Please Choose an Option:                  " << endl;

    int menuValue;
    cin >> menuValue;
    linkedCharTester(menuValue);
}


int main() {
    menu();
    return 0;
}