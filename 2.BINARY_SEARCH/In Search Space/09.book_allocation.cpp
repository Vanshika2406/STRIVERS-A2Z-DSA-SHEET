/*
Question:
You have N books, each with Ai number of pages. M students need to be allocated contiguous books, with each student getting at least one book. 
Out of all the permutations, the goal is to find the permutation where the student with the most pages allocated to him gets the minimum number of pages, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order.

Example:
Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output: 113
Explanation:
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.

Approach:
- We can use binary search to find the minimum number of pages that can be allocated to the student with the most pages.
- The range for binary search will be from the minimum number of pages in the array to the sum of all the pages in the array.
- For each mid value, we will check if it is possible to allocate the books in a way that the maximum number of pages for a student is less than or equal to mid.
- To check this, we iterate through the array of pages and keep track of the number of students and the sum of pages allocated to the current student.
- If at any point, the sum exceeds the mid value, we increment the number of students and reset the sum to the current page value.
- If the number of students exceeds the given M, it means we need more students to allocate the pages, so we return false.
- If at the end, the number of students is less than or equal to M, it means it is possible to allocate the pages within the given constraints, so we return true.
- Finally, we perform binary search and find the minimum mid value that returns true in the isPossible function.

Code:
*/
int countStudents(vector<int> &arr, int pages){ //If one student can read at most pages pages, how many students are needed?
  int students = 1;
  long long pagesStudent = 0;
  for(int i =0; i<arr.size();i++){
      if(pagesStudent + arr[i] <= pages){
         pagesStudent += arr[i];
      }
      else{
           students += 1;
           pagesStudent = arr[i];
      }
  }
  return students;
}
int findPages(vector<int>&arr, int n, int m){
    if(m>n) return -1;
    int low = *max_element(arr.begin(),arr.end());//Largest book 90 Capacity cannot be smaller than 90 because a single book cannot be split.
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<= high){
          int mid = ( low + high)/2;
          int students = countStudents(arr,mid);
          if(students>m){
            low = mid+1;
          }
          else{
               high = mid -1;
          }
    }
    return low;
};
//Time Complexity: O(N×log(sum of pages−maximum pages))
	​
