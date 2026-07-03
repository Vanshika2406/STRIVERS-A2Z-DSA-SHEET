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

//CODE:
#include<bits/stdc++.h>
using namespace std;

// Function to sort the array and return the largest element
int sortArr(vector<int>& arr) {
    // Sort the array in ascending order
    sort(arr.begin(), arr.end());
    
    // Return the last element (largest element) after sorting
    return arr[arr.size() - 1];
}

int main() {
    // Initialize arrays
    vector<int> arr1 = {2, 5, 1, 3, 0};
    vector<int> arr2 = {8, 10, 5, 7, 9};
   
    // Find and output the largest element in both arrays
    cout << "The Largest element in the array is: " << sortArr(arr1) << endl;
    cout << "The Largest element in the array is: " << sortArr(arr2) << endl;
   
    return 0;
}

//Time Complexity: O(N log N)
//Space Complexity: O(1)