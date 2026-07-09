/*
QUESTION:-
You are given an array 'A' of size 'N' and an integer 'K'. You need to print the length of the longest subarray of array 'A' whose sum = 'K'.
Example:
Input: 'N' = 7 'K' = 3
'A' = [1, 2, 3, 1, 1, 1, 1]
Output: 3
Explanation: Subarrays whose sum = '3' are:
[1, 2], [3], [1, 1, 1], [1, 1, 1]
Here, the length of the longest subarray is 3, which is our final answer.
*/

/*
APPROACH:-
-> Use sliding window approach using two pointers start and end
-> Run a loop to traverse the entire array add from end and subtract from start when sum>k
-> If sum==k then, update the ans now, window size = end-start+1
*/

// CODE:-
int longestSubarrayWithSumK(vector<int> a, long long k){
  int left=0,right=0;
  long long sum=a[0];
  int maxLen=0;
  int n=a.size();
  while(right<n){
       while(left<=right && sum>k){
            sum-=a[left];
            left++;
       }
       if(sum==k){
          maxLen = max(maxLen,right-left+1);  //calculate the number of elements within a specific range
       }
      right++;
      if(right<n)sum+=a[right];
  }
  return max len;
}
// tc=O(2n)
// sc=O(1)
