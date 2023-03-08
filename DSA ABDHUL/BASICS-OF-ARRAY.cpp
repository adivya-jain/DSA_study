#include<iostream>
using namespace std;

// 1) Arrays
// 2)structure
// 3)pointers
// 4)reference
// 5)paranmeter passing
// 6)classes
// 7)constructor
// 8)templates



// Array is a collection of similar data elements.
// int A[5];   0,1,2,3,4
// A[0]=27;
// A[1]=10;

// int A[5];

int main()
{
    int A[5]={13,12,33,43,67};
    for(int i=0;i<sizeof(A)/sizeof(A[0]);i++)
    {
        printf("%d ",A[i]);
    }



}


