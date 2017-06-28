#include <iostream>

#include "LinkedStack.h"

using namespace std;

//Check if char is a numeral
bool isNumeral(char c);

//Check if char is an operator
bool isOperator(char c);

//Evaluate the operation
double eval(int v1, int v2, char op);


void postfix() {

    //Capture the input string
    string parseString;

    cout << "Enter postfix to calculate: ";

    cin >> parseString;

    cout << parseString << "evaluates as: ";


    LinkedStack<int> numeralStack;


    //Scan through the input string for each char.
    for (int i = 0; i < parseString.length(); i++) {

        //If char is an operator, perform the action on the top two items in stack.
        if (isOperator(parseString[i])) {

            int numeralTwo = numeralStack.peek();
            numeralStack.pop();
            int numeralOne = numeralStack.peek();
            numeralStack.pop();

            numeralStack.push(eval(numeralOne, numeralTwo, parseString[i]));

            cout << "Value is: " << numeralStack.peek();

            //If char is not an operator add it to the stack.
        } else if(isdigit(parseString[i])){
            numeralStack.push(parseString[i] - '0');
        }


    }


}

bool isNumeral(){

}

//Check if char is an operator
bool isOperator(char c) {
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
        return true;
    } else {
        return false;
    }
}

//Perform math on values
double eval(int v1, int v2, char op){

    double returnVal;

    switch(op){

        case '+': {
            returnVal = v1 + v2;
            break;
        }
        case '-':{
            returnVal = v1 - v2;
            break;
        }
        case '*': {
            returnVal = v1 * v2;
            cout << returnVal;
            break;
        }
        case '/': {
            returnVal = v1 / v2;
            break;
        }
    }

    return returnVal;

}



//Start the main.
int main() {
    postfix();
    return 0;
}