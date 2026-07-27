/*
QUESTION:
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

Example 1:
Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

Example 2:
Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

APPROACH:
- Perform a binary search on the columns of the matrix.
- Find the maximum element in each column and check if it is a peak element by comparing it with its adjacent elements.
- If it is a peak element, return its position [i, j].

TIME COMPLEXITY: O(m log(n)) or O(n log(m)) - Binary search is performed on the columns of the matrix.
SPACE COMPLEXITY: O(1) - Constant space is used.

CODE:*/
// Finds the row index of the maximum element in column 'col'
int max_finder(vector<vector<int>>& mat, int n, int m, int col) {
    int maxi = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (mat[i][col] > maxi) {
            maxi = mat[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &mat){
  int n = mat.size();
  int m = mat[0].size();
  int low = 0, high = m-1;
  while(low <= high){
       int mid = (low+high)/2;
       int maxRowIndex = max_finder(mat,n,m,mid);
    //Grabs the value of the neighbor immediately to the left of our column max. 
    //If mid - 1 is out of bounds (we are at column 0), it assigns a sentinel value of -1 so any valid grid number will be larger than it.
       int left = mid - 1>= 0 ? mat[maxRowIndex][mid-1] : -1;
    //Grabs the value of the neighbor immediately to the right. If mid + 1 is out of bounds (we are at the last column), it assigns -1
       int right = mid + 1 < m ? mat[maxRowIndex][mid+1] : -1;
       if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
          return {maxRowIndex, mid};
       }
       else if (mat[maxRowIndex][mid]<left){
              high = mid - 1;
       }
        else{
              low = mid + 1;
        }
  }
  return{-1,-1};
}
