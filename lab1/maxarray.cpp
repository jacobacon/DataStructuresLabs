/*
 * Jacob Beneski
 * Lab 1
 *
 */

#include <iostream>
#include <math.h>

using namespace std;


//Take any type of ItemType as input, and return ItemType
template<class ItemType>
ItemType maxArray(ItemType arrayItem[], int first, int last) {


    //If we are at the end of an array, return it's only value.
    if (first == last) {
        return arrayItem[first];
    } else {
        //Keep going down the rabbit hole of recursion

        int mid = ceil(first + ((last - first) / 2));


        //Cut Array in 2 and check the parts.
        return max(maxArray(arrayItem, first, mid), maxArray(arrayItem, mid + 1, last));

    }


} //End MaxArray

int main() {

    int intArray[7] = {2, 13, 7, 17, 0, 11, 25};
    float floatArray[10] = {0.5, 11.123, 19.15, 105.6, 34.67, 32.65, 12.65, 13.43, 23.23, 12.54};
    int anotherIntArray[1] = {11};

    cout << "The Max Value in Int Array was: " << maxArray(intArray, 0, 6) << endl;
    cout << "The Max Value in Float Array was: " << maxArray(floatArray, 0, 9) << endl;
    cout << "The Max Value in AnotherIntArray was: " << maxArray(anotherIntArray, 0, 0) << endl;

    return 0;
} //End Main

