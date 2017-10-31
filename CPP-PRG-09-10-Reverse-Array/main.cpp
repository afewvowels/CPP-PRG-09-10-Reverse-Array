//
//  main.cpp
//  CPP-PRG-09-10-Reverse-Array
//
//  Created by Keith Smith on 10/31/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a function that accepts an int array and the array's size as arguments. The
//  function should create a copy of the array, except that the element values should be reversed
//  in the copy. The function should return a pointer to the new array. Demonstrate the
//  function in a complete program.


#include <iostream>

using namespace std;

int *getArraySize();
int *fillArray(int *, int);
int *reverseArray(int *, int);
void swap(int *, int *);


int main()
{
    int *intArrNumbers = nullptr;
    int *intArrSize = nullptr;
    
    intArrSize = getArraySize();
    
    intArrNumbers = new int[*intArrSize];
    
    intArrNumbers = fillArray(intArrNumbers, *intArrSize);
    
    intArrNumbers = reverseArray(intArrNumbers, *intArrSize);
    
    for (int i = 0 ; i < *intArrSize ; i++)
    {
        cout << intArrNumbers[i] << endl;
    }
    
    delete [] intArrNumbers;
    delete [] intArrSize;
    
    intArrNumbers = nullptr;
    intArrSize = nullptr;
    
    return 0;
}

int *getArraySize()
{
    int *intSize = nullptr;
    
    intSize = new int;
    
    cout << "Please enter the size of the array: ";
    cin >> *intSize;
    while (!cin || *intSize <= 1 || *intSize > 100)
    {
        cout << "Please enter a number greater than 1 and less than 100: ";
        cin.clear();
        cin.ignore();
        cin >> *intSize;
    }
    
    return intSize;
}

int *fillArray(int *intArr, int intSize)
{
    
    for (int i = 0 ; i < intSize ; i++)
    {
        cout << "Please enter number " << (i + 1) << " of " << intSize << ": ";
        cin >> intArr[i];
        while(!cin || *(intArr + i) <= 0 || *(intArr + i) >= 100)
        {
            cout << "Please enter a number greater than 0 and less than 100: ";
            cin.clear();
            cin.ignore();
            cin >> *(intArr +i);
        }
    }
    
    return intArr;
}

int *reverseArray(int *intArr, int intSize)
{
    int *intArrTemp = nullptr;
    
    intArrTemp = new int[intSize];
    
    for(int i = 0 ; i < intSize ; i++)
    {
        intArrTemp[i] = intArr[i];
    }
    
    for (int i = 0 ; i < intSize / 2 ; i++)
    {
        swap(intArr[i], intArr[intSize - 1 - i]);
    }
//    So none of this is necessary at all but it's commented anyways.
//    It cuts out the middle (last) swap in an odd-numbered array.
//
//    if(intSize % 2 == 0)
//    {
//        for (int i = 0 ; i < intSize / 2 ; i++)
//        {
//            swap(intArr[i], intArr[intSize - 1 - i]);
//        }
//    }
//    else if(intSize % 2 != 0)
//    {
//        for (int i = 0 ; i < intSize / 2 ; i++)
//        {
//            if (i < intSize / 2)
//            {
//                swap(intArr[i], intArr[intSize - 1 - i]);
//            }
//            else
//            {
//                cout << "ERROR SWAPPING ODD-NUMBERED ARRAY\n";
//                exit(1);
//            }
//        }
//    }
//    else
//    {
//        cout << "ERROR WITH REVERSE SORT\n";
//        exit(1);
//    }
    
    return intArr;
}

void swap(int *intA, int *intB)
{
    int *intTemp = nullptr;
    
    intTemp = intA;
    intA = intB;
    intB = intTemp;
}
