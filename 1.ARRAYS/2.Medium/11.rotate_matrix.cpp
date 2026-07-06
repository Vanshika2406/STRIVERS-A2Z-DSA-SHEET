/*Problem Statement
Given an N × N integer matrix, rotate the matrix by 90 degrees clockwise.
The rotation must be performed in-place, which means you cannot use another matrix to store the rotated result. You must modify the given matrix directly.

EXAMPLE:
Input

1 2 3
4 5 6
7 8 9
Output

7 4 1
8 5 2
9 6 3

APPROACH:
Rotating a matrix directly may seem difficult because every element changes its position.
Instead of moving every element individually, we can observe an important pattern:
  ->Transpose the matrix
  ->Reverse every row
These two operations together rotate the matrix by 90° clockwise.

CODE:
void rotateMatrix(vector<vector<int>> &mat){
  int n= mat.size();
  for(int i = 0;i<n-1;i++){
      for(int j = i+1;j<n;j++){
          swap(mat[i][j],mat[j][i]);
      }
  }
   for(int i =0;i<n;i++){
      revrse(mat[i].begin(),mat[i].end());
   }
}

//time complexity:O(N^2)
//space complexity:O(1)
