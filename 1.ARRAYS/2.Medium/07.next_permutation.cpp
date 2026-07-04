/*Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]
*/

/*
APPROACH:-

To find the next permutation of an array, we can follow these steps:

1. Find the first index `i` from the right such that `nums[i] < nums[i+1]`. This is the first element that needs to be swapped.
2. Find the first index `j` from the right such that `nums[j] > nums[i]`. This is the element that will replace `nums[i]`.
3. Swap `nums[i]` and `nums[j]`.
4. Reverse the subarray starting from `i+1` till the end of the array.
5. If step 1 does not find any index `i`, it means the array is in descending order. In that case, reverse the entire array to get the lowest possible order.

*/

// CODE:
void nextPermutation(vector<int> &nums)
{
  int ind=-1;
  int n=nums.size();
  for(int i=n-2;i>=0;i--){   // Find the first decreasing element from end
     if(nums[i]<nums[i+1]){  // If a smaller element found,store index
        ind =i;
        break;
     }
  }
  if(ind==-1){  // If no such index found,reverse entire array
     reverse(nums.begin(),nums.end());
     return nums;
]
for(int i=n-1;i>ind;i--){  //Find element just greater than nums[index],swap the two
    if(nums[i]>nums[ind]){
      swap(nums[i],nums[ind]);
      break;
    }
}
 reverse(nums.begin() + ind+1,nums.end());  // Reverse the part after index
 return nums;
}

//timecomplexity = O(3N)
//spacecomplexity= o(1)
