/*Problem Statement: 
Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

Examples
Input Format: arr[] = {2,2,1}
Result: 1
Explanation: In this array, only the element 1 appear once and so it is the answer.

APPROACH:
We can use XOR operation as we know xor cancles out the same elements
-> Since only one element is present once and all other are present twice so the remaining element would be the
    one which is present only once cause all other gets cancels out*/

//CODE:

int singlenumber(vector<int>&nums){
  int xorr=0;
  for(int i=0;i<arr.size();i++){
      xorr=xorr^arr[i];
  }
return xorr;
}
// tc = O(n)
// sc = O(1)
