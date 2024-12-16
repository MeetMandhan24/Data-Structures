#include<iostream>
using namespace std;

int linearsearch (int arr [], int size, int target){
    for (int i =0; i < size; i ++){
        if (arr[i]==target){
            cout << "search successful : " << target << " found at " << i << endl;
            // return 0;
        }
    }

    return 0;
}

int main()
{
    int arr [] = {34, 78, 12, 90, 23, 56, 8, 67, 45, 29};
    int n = sizeof(arr)/sizeof(arr[0]);
    linearsearch(arr, n, 12);
    return 0;
}