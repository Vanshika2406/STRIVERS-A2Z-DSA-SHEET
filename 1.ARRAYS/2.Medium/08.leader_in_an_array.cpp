/*QUESTION:-

Given an array A of positive integers. Your task is to find the leaders in the array. An element of the array is a leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader.

Example 1:
Input:
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: The first leader is 17 as it is greater than all the elements to its right. Similarly, the next leader is 5. The rightmost element is always a leader, so it is also included.

APPROACH:-

To find the leaders in the array, we can follow these steps:

1. Initialize a variable `maxRight` with the rightmost element of the array.
2. Iterate the array from right to left:
   - If the current element is greater than or equal to `maxRight`, it is a leader. Print the current element and update `maxRight` to the current element.
3. Finally, print `maxRight` as it is always a leader.

*/

// CODE:
vector<int> superiorElements(vector<int>&a){
  vector<int> ans;
//maxi stores the largest element we've seen so far while moving from right to left.At the very beginning, we haven't seen any element yet.
//So we initialize maxi with the smallest possible number, so that the first element we check (the last element of the array) is always greater than it.
  int maxi = INT_MIN;  
  for(int i=n-1;i>=0;i--){  // Last element of the vector is always a leader 
   //Why from right? Because we need to know whether the current element is greater than everything on its right.
      if(a[i]>maxi){        
         ans.push_back(a[i]);
      }
      maxi = max(maxi,a[i]);
  }
   sort(ans.begin(),ans.end());   /* Reverse the vector to match the required output order*/
   return ans;
}

//tc:O(n)
//sc=O(1)
