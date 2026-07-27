/*
QUESTION:-
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input:
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).
*/

/*
APPROACH:-
-> We can use two pointer i and j which indicates current row and col
-> As we know the matrix is row-wise sorted we can intilaize j=m-1 i.e. last col and i=0 i.e. first row
-> Now, the idea is we will keep moving left j while we occur 1 and if 0 is found we will check in next row
-> The last row where we encountered 1 will be our ans

                {*0, *1, *1, *1}
                {*0,  0,  1,  1}
out of matrix  *{*1,  1,  1,  1} ---> ans
                {0,  0,  0,  0}



*/

// CODE:-
int lowerBound(vector<long long> v, long long n, long long x) { // find first occurance of one
    long long low = 0, high = n - 1;
    int ans = -1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (v[mid] <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n ,int m){
  int cnt_max = 0;
  int index = -1;
  for(int i = 0;i<n;i++){
      int cnt_ones = m - lowerBound(matrix[i], m, 1);
      if(cnt_ones > cnt_max){
         cnt_max = cnt_ones;
         index = i;
      }
  }
  return index;
}
//time complexity = O(nlog2m)
//space complexity = O(1)
