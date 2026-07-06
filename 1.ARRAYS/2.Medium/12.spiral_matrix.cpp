/*
Problem Statement
Given a matrix of size N × M, print all the elements of the matrix in spiral order.
Spiral order means starting from the top-left corner, traversing and continuing this process until all elements have been visited.

->Example:
Input

1  2  3
4  5  6
7  8  9
Output

1 2 3 6 9 8 7 4 5

APPROACH:
Initially,

top = 0
bottom = n - 1
left = 0
right = m - 1
We repeatedly traverse the matrix in four directions:
Left → Right
Top → Bottom
Right → Left
Bottom → Top

After completing each traversal, we shrink the corresponding boundary.
We continue until every element has been visited.

CODE:
*/
vector<int> spiralMatrix(vector<vector<int>>&mat) {
  int n = mat.size();
  int m = mat[0].size();
  int left =0, right = m-1;
  int top=0,bottom = n-1;
  vector<int> ans;
  while(top<= bottom && left<=right){  //continue as long as there is at least one unvisited row and one unvisited column.
  //right
      for(int i = left;i<=right;i++){
         ans.push_back(mat[top][i]);
      }
      top++;
      for(int i = top;i<=bottom;i++){
         ans.push_back(mat[i][right]);
      }
      right--;
      if(top<=bottom){  //to ensure that an unvisited bottom row still exists.Then we traverse the bottom row from right to left and decrement bottom.
      for(int i= right;i>=left;i--){
         ans.push_back(mat[bottom][i]);
      }
      bottom--;
   }
   if(left<=right){  //to ensure that an unvisited left column still exists.Then we traverse the leftmost column from bottom to top and increment left.
     for(int i =bottom;i>=top;i--){
         ans.push_back(mat[i][left]);
     }
     left++;
   }
 }
  return ans;
}


/*Time Complexity	O(N × M)
Space Complexity	O(N × M) (for storing the output)*/

