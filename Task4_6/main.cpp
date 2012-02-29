#include "main.h"       // Here we contain class and function GetScalar
#include <iostream>

using namespace std;


int main()
{
    const int N = 4;
    TMatr a(N);

    a.FillRandom(10);                                   // Fill our MATR with random values
    a.PrintMatr();                                      // Print this

    int * first = new int[a.GetSIze()];                 // Array of first multipliers
    int * second = new int[a.GetSIze()];                // Array of sec multiplier


    for(int i = 0; i < a.GetSIze(); i++)                // ---------- TASK 6 --------------
    {                                                   // Find scalar of two diagonals
        first[i] = a.GetValue(i,i);                     //
        second[i] = a.GetValue(i,a.GetSIze() - i - 1);  //
    }                                                   //---------------------------------

    cout << GetScalar(first,second,a.GetSIze());        // Call GetScalar func with 1,2 multiplier
    return 0;
}

