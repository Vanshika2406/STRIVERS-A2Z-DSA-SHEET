/*Problem Statement:
Given an integer array nums of size N, return all the unique triplets [nums[i], nums[j], nums[k]] such that:
i != j
j != k
i != k
nums[i] + nums[j] + nums[k] == 0

The solution set must not contain duplicate triplets.

EXAMPLE:
Input  : nums = [-1,0,1,2,-1,-4]

Output:
[
 [-1,-1,2],
 [-1,0,1]
]
Explanation: Both triplets have a sum of 0.
-1 + (-1) + 2 = 0
-1 + 0 + 1 = 0
  
APPROACH:
Sort the array.
Fix one element using a loop.
Place two pointers:
left = i + 1 && right = n - 1
Calculate the sum.
If:
Sum is 0 → Store the triplet.
Sum is less than 0 → Move left.
Sum is greater than 0 → Move right.

Skip duplicate elements.
Return all unique triplets.

CODE:
*/
#include <bits/stdc++.h> 
using namespace std; 
class Solution { 
public: 
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ans;
      sort(nums.begin(),nums.end());
      int n = nums.size();

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                }

                else if(sum > 0) {
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    j++;
                    k--;
                    while(left < right && nums[left] == nums[left-1])
                        left++;

                    while(left < right && nums[right] == nums[right+1])
                        right--;
                }
            }
        }

        return ans;
    }
};
       
     


