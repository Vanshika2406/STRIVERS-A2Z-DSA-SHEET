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

void getElements(int nums[], int n) {
    if (n < 2) {
        cout << "Array has less than 2 elements" << endl;
        return;
    }

    int largest = nums[0];
    int slargest = INT_MIN;

    for (int i = 1; i < n; i++) {
        if (nums[i] > largest) {
            slargest = largest;
            largest = nums[i];
        }
        else if (nums[i] < largest && nums[i] > slargest) {
            slargest = nums[i];
        }
    }

    if (slargest == INT_MIN)
        cout << "No second largest element exists" << endl;
    else
        cout << "Second largest: " << slargest << endl;
}

int main() {
    int nums[] = {1, 5, 2, 9, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    getElements(nums, n);

    return 0;
}