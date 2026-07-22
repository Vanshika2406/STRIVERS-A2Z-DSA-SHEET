/*
Question: Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.

Example:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays. The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Approach:
- The problem can be solved using the binary search algorithm.
- We need to find the range of possible values for the minimized largest sum.
- The lower bound of the range is the maximum element in the array (as each subarray must contain at least one element).
- The upper bound of the range is the sum of all elements in the array (as the largest sum cannot exceed the total sum of the array).
- We perform binary search within this range to find the minimum largest sum that satisfies the given condition.
- In each iteration, we calculate the mid value of the range and check if it is a valid solution using a helper function.
- The helper function checks if it is possible to split the array into k subarrays with a maximum sum of mid.
- If it is possible, we update the answer and search the lower half of the range.
- If it is not possible, we search the upper half of the range.
- We continue this process until we find the optimal solution.

Time Complexity: O(n * log(sum of array))
Space Complexity: O(1)
*/
bool isPossible(vector<int> &arr, int k,int mid){ //If one student can read at most pages pages, how many students are needed?
  int pos_parts = 1; //one painter starts painting.
  int temp = 0; //Current workload assigned to the current painter.
  for(int i =0; i<arr.size();i++){
      if(temp + arr[i] <= mid){ //If the current painter can paint this board
        temp += arr[i];
      }
      else{ //Current painter cannot paint this board.Assign it to the next painter.
           pos_parts += 1;
           temp = arr[i];
      }
  }
  if (pos_m <= k)
        return true; //If the required painters are less than or equal to k, then mid is a valid answer.
    return false;
}
int splitArray(vector<int>& nums, int k) { //performs Binary Search on Answer.
   int low = *max_element(nums.begin(), nums.end());
   int high = accumulate(nums.begin(), nums.end(), 0);
   int ans = -1;
   for(int i = 0; i < nums.size(); i++){
    low = max(low, nums[i]);
    high += nums[i];
  }
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr,k,mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
