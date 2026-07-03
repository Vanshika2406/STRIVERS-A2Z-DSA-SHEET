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

#include <bits/stdc++.h>
using namespace std;

int largestElement(int nums[], int n) {
    int largest = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }

    return largest;
}

int main() {
    int nums[] = {2, 5, 1, 3, 0};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "Largest element: " << largestElement(nums, n);

    return 0;
}  //tc=O(n)  sc=O(1)