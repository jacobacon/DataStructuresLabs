#include <iostream>
#include "LinkedChar.h"

//Driver Program for Lab 2

using namespace std;


LinkedChar linkedChar("Hello World");


void linkedCharTester() {

    cout << " --- Linked Character Chain Test Menu --- " << endl;
    cout << "Please Choose an Option:                  " << endl;
    cout << "1.   Add characters                       " << endl;
    cout << "2.   Test toString()                      " << endl;
    cout << "3.   Output the length                    " << endl;
    cout << "4.   Test setString()                     " << endl;
    cout << "5.   Clear the linkedChar                 " << endl;
    cout << "6.   Find a char                          " << endl;
    cout << "7.   Append                               " << endl;
    cout << "8.   Contains                             " << endl;

    cout << "Enter Value: ";

    int menuValue;
    cin >> menuValue;


    switch (menuValue) {
        case 1: {//Add characters

            cout << linkedChar.toString() << endl;

            linkedChar.add('!');
            linkedChar.add(' ');
            linkedChar.add('a');
            linkedChar.add('b');
            linkedChar.add('c');

            cout << linkedChar.toString() << endl;

            linkedCharTester();
            break;
        }
        case 2: {//To String

            cout << linkedChar.toString() << endl;
            linkedCharTester();
            break;
        }

        case 3: {//Check length
            cout << linkedChar.getLength() << endl;
            linkedCharTester();
            break;
        }
        case 4: {//Set String
            cout << linkedChar.toString() << endl;
            string setString = "New String";
            linkedChar.setString(setString);
            cout << linkedChar.toString() << endl;
            linkedCharTester();
            break;
        }
        case 5: {//Clear
            cout << linkedChar.toString() << endl;
            linkedChar.clear();
            cout << linkedChar.toString() << endl;
            cout << "Is Empty: " << linkedChar.isEmpty();
            linkedCharTester();
            break;
        }

        case 6: {
            cout << linkedChar.toString();
            cout << "Found char 'o' at : " << linkedChar.find('o') << endl;
            linkedCharTester();
            break;

        }

        case 7: {

            LinkedChar appendLink;

            appendLink.add('t');
            appendLink.add('e');
            appendLink.add('s');
            appendLink.add('t');

            linkedChar.append(appendLink);

            linkedCharTester();
            break;
        }

        case 8: {

            LinkedChar containsLink;

            containsLink.add('h');
            containsLink.add('e');
            containsLink.add('l');
            containsLink.add('l');
            containsLink.add('o');


            linkedChar.contains(containsLink);
            linkedCharTester();
            break;

        }


    }


}


int main() {
    linkedCharTester();
    return 0;
}