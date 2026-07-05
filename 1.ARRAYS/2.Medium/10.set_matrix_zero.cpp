/*
QUESTION:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

APPROACH:
To solve this problem in-place, we can follow these steps:
1. Use two boolean variables, firstRowZero and firstColZero, to check if the first row and first column contain zeros initially.
2. Iterate through the matrix and if an element is zero, set the corresponding element in the first row and first column to zero.
3. Iterate through the matrix again, excluding the first row and first column. If an element in the first row or first column is zero, set the current element to zero.
4. Finally, based on the values in firstRowZero and firstColZero, set the first row and first column to zero if needed.

TIME COMPLEXITY: O(m * n), where m and n are the dimensions of the matrix.
SPACE COMPLEXITY: O(1), as we are using constant extra space.

*/

// CODE:
vector<vector<int>> zeroMatrix(vector<vector<int>>&matrix,int n,int m){
  //int col[m] = {0}; -> matrix[0][...]  //Instead of making these arrays...we will use First Row & First Column as marker arrays.
  //int row[n] = {0}; _> matrix[...][0]
  int col0 =1; //means "No need to make first column zero."
  for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
         if(matrix[i][j]==0){    //If current cell is zero...
           //mark the ith row
           matrix[i][0]=0;  //only the first element changed.
          //mark the jth col
          if(j !=0)
            matrix[0][j]=0;  //Column 1 must become zero.
          else
             col0=0;  //This means If the zero was found in Column 0 don't touch matrix[0][0] Instead remember separately First column should become zero.
         }
     }
  }
for(int i=1;i<n;i++){
   for(int j=1;j<m;j++){
      if(matrix[i][j] !=0){
        if(matrix[0][j]==0 || matrix[i][0]==0){  
           matrix[i][j]=0;  //If its column is marked OR its row is marked then make current cell zero.
        }
      }
   }
}
if(matrix[0][0]==0){  //Now first row
   for(int j=0;j<m;j++) matrix[0][j] = 0;  //Entire first row becomes zero.
}
if(col0 == 0)  //now first column
  for(int i=0;i<n;i++){  //Entire first column becomes zero.
      matrix[i][0]=0;
  }
}
return matrix;
}
