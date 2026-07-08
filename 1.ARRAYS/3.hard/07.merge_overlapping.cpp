/*
Problem Statement:
Given an array of intervals where [intervals[i] = [starti, endi]]
merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

Examples:
Input:
intervals = [[1,3],[2,6],[8,10],[15,18]]
Output:
[[1,6],[8,10],[15,18]]

Explanation:
[1,3] and [2,6] overlap.
Merge them into [1,6].

APPROACH:
-> What is an Overlapping Interval?
Two intervals overlap if Current   {Start ≤ Previous End}
Example: [2,6] [4,8]
Since 4 ≤ 6
they overlap. Merged interval becomes [2,8]

1.Sort all intervals by their starting value.
2.Create an empty answer vector.
3.traverse every interval.
4.If the answer vector is empty, insert the interval.
5.Otherwise compare the current interval with the last merged interval.
6.If they overlap, extend the ending point.
7.Otherwise, push the current interval into the answer.
8.Return the merged intervals.

CODE:
*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  int n = arr.size();
  sort(arr.begin(),arr.end());
  vector<vector<int>> ans;
  for(int i=0;i<n;i++){
  //If no interval has been added yet,simply insert the first interval. 
  //or Start of the current interval is greater than End of the last merged interval.There is no overlap.Push the interval. 
      if(ans.empty() || arr[i][0] > ans.back()[1]){  
         ans.push_back(arr[i]); //Store the new interval because there is no overlap.
      }
      else{
          ans.back()[1] = max(ans.back()[1], arr[i][1]); compare last element of previous interval  with the current last element select max 
      }
  }
  return ans;
}

//tc = O(NlogN)
//sc = O(N)(for the answer vector)
