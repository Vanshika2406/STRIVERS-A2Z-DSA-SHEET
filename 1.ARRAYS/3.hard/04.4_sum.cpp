/*
Problem Statement:
Given an integer array nums of size N and an integer target, return all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

a != b
b != c
c != d
a != c
a != d
b != d
nums[a] + nums[b] + nums[c] + nums[d] == target
The solution set must not contain duplicate quadruplets.

Example:
Input:
nums = [1,0,-1,0,-2,2]
target = 0

Output:
[
 [-2,-1,1,2],
 [-2,0,0,2],
 [-1,0,0,1]
]

  Approach:
Sort the array.
Fix the first element using loop i.
Fix the second element using loop j.
Place two pointers:
left = j + 1
right = n - 1
Calculate the sum of the four elements.
If:
Sum equals target → Store the quadruplet.
Sum is less than target → Move left.
Sum is greater than target → Move right.
Skip duplicate values.
Return all unique quadruplets.

code:
*/
vector<vector<int>> foursum(vector<int>& nums, int target){
  int n = nums.size();
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  for(int i =0,i<n;i++){
    if(i>0 && nums[i]==nums[i-1]) continue;
    for(int j = i+1;j<n:j++){
       if(j!= (i+1) && nums[j]==nums[j-1]) continue;
       int k = j+1;
       int l = n-1;
       while(k<l){
            long long sum = nums[i];
            sum+=nums[j];
            sum+=nums[k];
            sum+=nums[l];
            if(sum==target){
               vector<int. temp = {nums[i],nums[j],nums[k],nums[l]};
               ans.push_back(temp);
               k++;l--;
               while(k<l && nums[k] == nums[k-1] k++;
               while(k<l && nums[l] == nums[l+1] l--;
            }
            else if(sum < target) k++;
            else l--;
       }
    }
  }
  return ans;
}

// time complexity = O(n^3)
//space complexity = O(1)

  
