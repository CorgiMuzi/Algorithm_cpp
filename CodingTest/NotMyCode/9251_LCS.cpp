// Written by "asjasj3964"
// !!! I didn't wrote this code !!!
// !!! I copied this code for studying LCS algorithm !!!
// !!! Much more optimized code than LCS algorithm with O(N^2) time complexity !!!

#include <iostream>
#include <string>
using namespace std;
#define MAX 2000

int main()
{
    string str1;
    string str2;

    int arr[MAX] = { 0 };

    cin >> str1;
    cin >> str2;

    int str1Size = str1.size();
    int str2Size = str2.size();

    int max1;

    for (int i = 0; i < str1Size; i++)
    {
        max1 = 0;

        for (int j = 0; j < str2Size; j++)
        {
            if (max1 < arr[j]) max1 = arr[j];
            else if (str2[j] == str1[i]) arr[j] = max1 + 1;
        }
    }

    int max2 = arr[0];

    for (int i = 1; i < MAX; i++)
        if (max2 < arr[i]) max2 = arr[i];

    cout << max2;
}