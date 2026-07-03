//Problem Statement: 
//Given an array, we have to find the largest element in the array.

/*Example 1:
Input:
 arr[] = {2, 5, 1, 3, 0}  
Output:
 5  
Explanation: 5 is the largest element in the array.*/

//ALGORITHM:
/*Sort the array in ascending order.
Print the element at the (size of the array - 1)th index, which corresponds to the largest element in the array.*/


// BRUTE FORCE CODE:
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 5, 3, 9, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n); //sort() arranges the array in ascending order.

    int largest = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != largest) {
            cout << "Second largest: " << arr[i] << endl;
            return 0;
        }
    }

    cout << "No second largest element exists" << endl;
    return 0;
}

                                      //Time Complexity: O(N log N)
                                    //Space Complexity: O(1)

//BetterApproach solution

/*Perform a single traversal to find the smallest and largest elements in the array.
After that, traverse the array again to find the element just larger than the largest element*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 5, 3, 9, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);
    int largest = arr[0];
    int slargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>slargest && arr[i]!=largest){
            slargest = arr[i];
        }
    }
    cout << slargest << endl;
    return 0;
}                      //Time Complexity: O(2N)


//optimal solution

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 5, 3, 9, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);
    int largest = arr[0];
    int slargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    else if(arr[i]<largest && arr[i]>slargest){
        slargest = arr[i];
    }
    cout << slargest << endl;
    return 0;
}                      //Time Complexity: O(N)