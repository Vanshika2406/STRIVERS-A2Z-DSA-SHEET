//Find Second Smallest and Second Largest Element in an array
/*Example 1:
Input:
 [1, 2, 4, 7, 7, 5]  
Output:
Second Smallest : 2  
Second Largest : 5

brute force algorithm:
1. Sort the array in ascending order.
2. Traverse the sorted array to find the second smallest and second largest elements.
*/

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