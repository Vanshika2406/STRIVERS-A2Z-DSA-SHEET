/*
Question:
You are given an array of integers nums and an integer threshold. We need to find the smallest divisor
such that the result of dividing each element of the array by the divisor and summing up the results
is less than or equal to the threshold.

Example:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum of 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4, we can get a sum of 7 (1+1+2+3).
If the divisor is 5, the sum will be 5 (1+1+1+2).
The smallest divisor that gives a sum less than or equal to the threshold is 5.

Algorithm:
Find the maximum element.
Binary search between 1 and maxElement.
For each divisor:
Compute the sum of ceil(arr[i] / divisor).
If the sum is within the threshold, search left.
Otherwise, search right.
Return the smallest valid divisor.

code:
*/
int sumByD(vector<int> &arr, int div){
  int sum = 0;
  int n = arr.size();
  for(int i = 0;i<n;i++){
      sum = sum + ceil((double)(arr[i]) / (double)(div));
  }
  return sum;
}
int smallestDivisor(vector<int>& arr,int limit){
  int n = arr.size();
  if(n>limit) return -1;
  int low = 1, high = *max_element(arr.begin(),arr.end());
  while(low<= high){
        int mid = (low + high)/2;
        if(sumByD(arr,mid)<=limit){
           high = mid - 1;
        }
        else{
             low = mid + 1;
        }
  }
  return low;
}
// Time Complexity: O(n log(max(nums)))
// Space Complexity: O(1)
