/*QUESTION:

Given an integer array nums, find a subarray that has the largest product, and return the product.

Example:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

APPROACH:

To find the subarray with the largest product, we iterate through the array while keeping track of the current product. We maintain two variables: `ans` to store the maximum product found so far and `prdct` to store the current product. Since negative numbers can change the sign and potentially result in a larger product, we run the loop twice, once from left to right and once from right to left.

CODE:*/

int subarrayWithMaxProduct(vector<int> &arr){
  int pre = 1, suff = 1;
  int ans = INT_MIN;
  int n = arr.size();
  for(int i = 0 ;i<n;i++){
      if(pre == 0) pre = 1;
      if(suff == 0) suff =1;

      pre = pre * arr[i];
      suff = suff * arr[n-i-1];
      ans = max(ans,max(pre,suff));
  }
  return ans;
}
//TIME COMPLEXITY: o(N)
//SPACE COMPLEXITY: O(1)
 
