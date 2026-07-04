/*Problem Statement:
Given an integer array nums of size n, find the contiguous subarray (containing at least one element) that has the largest sum, and return that sum

Example:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output:6
Explanation:The subarray with the maximum sum is [4, -1, 2, 1]
Sum: 4 + (-1) + 2 + 1 = 6
No other contiguous subarray has a larger sum.

APPROACH:-
-> Initialize two variables: maxSum and currentSum. Set both variables to the first element of the array.
-> Iterate through the array starting from the second element:
    Update currentSum by adding the current element to it.
    If currentSum becomes negative, reset it to 0. This step ensures that we consider only the subarrays with positive sums.
    Update maxSum by taking the maximum value between maxSum and currentSum. This keeps track of the maximum subarray sum encountered so far.
-> After the iteration, the maxSum variable will hold the largest sum of any subarray.
-> Return the maxSum as the result.
*/

//CODE:
int maxsum(vector<int> &arr){
  long long sum =0;
  long long maxi = llong_min; //LLONG_MIN ensures that even if all elements are negative, the algorithm still returns the correct answer.
  for(int i = 0;i<n;i++){
      sum+=arr[i];
      if(sum>maxi){
          maxi=sum;
      }
      if(sum<0){
         sum=0;
      }
  }
  return maxi;
}

//time complexity = O(n)
//space complexity = o(1)
