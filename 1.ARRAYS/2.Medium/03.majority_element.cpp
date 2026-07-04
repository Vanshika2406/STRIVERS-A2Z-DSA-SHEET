/*
Problem Statement:
Given an integer array nums of size n, find and return the majority element.
A majority element is an element that appears more than ⌊n/2⌋ times in the array.
It is guaranteed that the input array always contains a majority element.

Example 1
Input:
nums = [3, 2, 3]
Output: 3
Explanation:
3 appears 2 times.
n = 3, and n/2 = 1.

Since 2 > 1, 3 is the majority element.

APROACH:-
-> Initialize two variables: candidate and count. Set candidate to the first element of the array, and count to 1.
-> Iterate through the array starting from the second element:
    If the current element is equal to the candidate, increment the count by 1.
    If the current element is different from the candidate, decrement the count by 1.
    If the count becomes 0, update the candidate to the current element and set the count to 1 again.
-> After the iteration, the candidate variable will hold the majority element.
Return the candidate as the result.
*/

//CODE:
int maxcount(vector<int> & nums){
  int cnt=0;
  int el;
  for(int i=0;i<nums.size();i++){
     if(cnt==0){
       cnt=1;
       el=nums[i]; //Make the current element the new candidate.
     }
     else if (nums[i]==el){
       cnt++;
     }
     else{
       cnt--;
     }
  }
int cnt1=0; //verification
for(int i=0;i<nums.size();i++){
   if(nums[i]==el)cnt1++;
}
if(cnt1>(nums.size()/2)){
  return el;
}
return -1;
}

//tc=O(n)
//sc=O(1)
