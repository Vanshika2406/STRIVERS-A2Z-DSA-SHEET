/*
QUESTION:-

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
APPROACH:-

To find the length of the longest consecutive elements sequence, we can follow these steps:

1. Create a set to store all the elements of the array.
2. Iterate through the array and insert each element into the set.
3. For each element, check if its previous consecutive element (num-1) exists in the set. If it does not exist, it means the current element is the starting element of a sequence.
4. For each starting element, keep incrementing the current element (num+1) and checking if it exists in the set. This will help find the consecutive elements in the sequence.
5. Keep track of the maximum length of consecutive elements encountered.
6. Return the maximum length as the result.

*/

// CODE:
int longestconsecutive(vector<int>&a){
  int n =a.size();
  if(n==0) return 0;
  int longest =1; //Stores the longest sequence found so far.Why initialize to 1? Because if there is at least one element, that element itself is a sequence of length 1.
  unordered_set<int> st;  //Why use a set? A set lets us check if a number exists in O(1) average time.
  for(int i =0;i<n;i++){
     st.insert(a[i]);
  }
  for(auto it:st){   //loops through every element in the set
    if(st.find(it-1) == st.end()) {  //Check whether the previous number exists. If it doesn't exist, then it is the starting point of a sequence.
       int cnt=1;  //Current sequence length.
       int x=it;   //Store the current number.
      while(st.find(x+1) != st.end()){  //Keep checking whether the next consecutive number exists.
            x=x+1;
            cnt=cnt+1;
      }
      longest = max(longest, cnt);
    }
  }
  return longest;
}

// TIME COMPLEXITY: O(n), where n is the size of the input array.
// SPACE COMPLEXITY: O(n), as we are using a set to store the elements of the array.
        
