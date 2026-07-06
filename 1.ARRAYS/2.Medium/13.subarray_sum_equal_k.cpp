/*Problem Statement:
Given an integer array nums and an integer k, return the total number of subarrays whose sum is equal to k.
A subarray is a contiguous, non-empty sequence of elements within an array.

Example:
Input:
nums = [1, 1, 1]
k = 2
Output : 2
Explanation: The subarrays whose sum equals 2 are:
[1,1]  (index 0 to 1)
[1,1]  (index 1 to 2)
Hence, the answer is 2.

APPROACH:   PREFIX SUM:
The prefix sum at index i is the sum of all elements from index 0 to i.

Example: nums = [1, 2, 3, 4]

Prefix Sum:
1
3
6
10
Now suppose the current prefix sum is preSum.
If there exists an earlier prefix sum equal to  (preSum - k)
then the elements between those two prefix sums form a subarray whose sum is exactly k.

Therefore, instead of checking every subarray, we simply keep track of how many times each prefix sum has appeared.

    ->  IMPORTANT: Insert (0 → 1) into the map because a prefix sum of 0 exists before the array starts.


CODE:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = 1;  //It represents a prefix sum of 0 before the array starts.

        int preSum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {

            preSum += nums[i];  //Keep adding the current element.

            int remove = preSum - k;  //Find the Required Prefix Sum

             //We add its frequency because multiple earlier prefix sums can produce different valid subarrays ending at the current index.
            count += mp[remove];
            mp[preSum]++;  //Increase the frequency of the current prefix sum.If it is already present, increment its count. Otherwise, insert it with frequency 1.
        }

        return count;
    }
};

//time complexity:O(N)
//space complexity:O(N)
