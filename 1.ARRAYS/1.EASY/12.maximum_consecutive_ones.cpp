/* QUESTION:
Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array

Example 1:
Input: prices = {1, 1, 0, 1, 1, 1}
Output: 3
Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

APPROACH:
Initialize two variables:
cnt → counts the current streak of 1’s.
maxi → stores the maximum streak found so far.

Traverse through the array:
If nums[i] == 1, increment cnt.
If nums[i] == 0, reset cnt to 0.

Update maxi = max(maxi, cnt) at each step.

Finally, return maxi, which contains the length of the longest consecutive 1’s.
*/

//CODE:
int findMaxConsecutiveOnes(vector<int> &nums)
{
  int maxi =0;
  int cnt=0;
  for(int i =0;i<nums.size();i++){
      if(nums[i]==1){
         cnt++;
         maxi=max(maxi,cnt);
      }
       else{
            cnt=0;
       }
  }
  return maxi;
}
};

//tc: O(N)
//sc=O(1)
