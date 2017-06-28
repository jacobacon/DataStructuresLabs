#include <iostream>

#include "LinkedStack.h"

using namespace std;

//Check if char is a numeral
bool isNumeral(char c);

//Check if char is an operator
bool isOperator(char c);

//Evaluate the operation
double eval(int v1, int v2, char op);


double postfix() {

    string parseString;

    cout << "Enter postfix to calculate: ";

    cin >> parseString;


    LinkedStack<int> numeralStack;
    LinkedStack<char> operatorStack;


    for (int i = 0; i < parseString.length(); i++) {
        if (isOperator(parseString[i])) {
            //operatorStack.push(parseString[i]);

            int numeralOne = numeralStack.peek();
            numeralStack.pop();
            int numeralTwo = numeralStack.peek();
            numeralStack.pop();

            numeralStack.push(eval(numeralOne, numeralTwo, parseString[i]));

            cout << "Value is: " << numeralStack.peek();

        //cout << "Value is: " << eval(numeralOne, numeralTwo, parseString[i]);




        } else {
            numeralStack.push(parseString[i] - '0');
            cout << numeralStack.peek() << endl;
        }


    }


    //return numeralStack.peek();


}

bool isNumeral(char c) {

}

bool isOperator(char c) {
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
        return true;
    } else {
        return false;
    }
}

double eval(int v1, int v2, char op){

    double returnVal;

    switch(op){

        case '+': {
            returnVal = v1 + v2;
            break;
        }
        case '-':{
            returnVal = v2 - v1;
            cout << returnVal;
            break;
        }
        case '*': {
            returnVal = v2 * v2;
            break;
        }
        case '/': {
            returnVal = v2 / v1;
            break;
        }
    }

    return returnVal;

}


int main() {


    postfix();
    return 0;
}