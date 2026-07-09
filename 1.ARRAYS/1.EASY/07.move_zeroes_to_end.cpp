/*Problem Statement: 
You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

Examples
Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order*/

/*APPROACH:
Find the index of the first zero (j).
Traverse the array from j + 1 to the end.
If the current element is non-zero:
Swap arr[i] and arr[j].
Increment j.
*/

//code:
void moveZeroes(vector<int>& nums) {
int j=-1; // point to first zero
for(int i=0;i<n;i++){  //find first zero
   if(arr[i]==0){
      j=i;
      break;
      }
}
for(int i=j+1;i<n;i++){  // start from next index of first
    if(arr[i]!=0){
      swap(arr[i],arr[j]);
          j++;
    }
}
  
