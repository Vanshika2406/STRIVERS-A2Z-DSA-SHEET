/*
Problem Statement:
Given an integer array A of size N and an integer K, return the total number of subarrays whose bitwise XOR of all elements is equal to K.
A subarray is a contiguous sequence of elements in the array.

Examples:
Input:
A = [4,2,2,6,4]
K = 6

Output: 4
Explanation:
The subarrays having XOR equal to 6 are:
[4,2]
[2,2,6]
[6]
[4,2,2,6,4]

Approach:
Create a Hash Map to store prefix XOR frequencies.
Initially store
0 → 1
because XOR before starting is 0.
Traverse the array.
Compute Prefix XOR.
Calculate
x = xr ^ K
If x exists in the map,
then a valid subarray has been found.
Add its frequency to the answer.
Store the current Prefix XOR in the map.

code:
*/
int subarraysWithSumK(vector<int>a, int k){
  int xr = 0;
  map<int,int> mpp;
  mpp[xr]++;
  int cnt =0;
  for(int i =0;i<a.size();i++){
      xr = xr^a[i];
      int x = xr^k;
      cnt += mpp[x];
      mpp[xr]++;
  }
  return cnt;
}
/*
TIME COMPLEXITY: O(n), where n is the size of the input array a.
SPACE COMPLEXITY: O(n), as we are using a hashmap to store the prefix XOR values and their corresponding counts.
*/
