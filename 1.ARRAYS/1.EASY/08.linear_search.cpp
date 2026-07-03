/*
problem Statement: 
Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

Examples:
Input: arr[] = 1 2 3 4 5, num = 3  
Output: 2 
Explanation: 3 is present at the 2nd index of the array.
*/

/*APPROACH:
Start from index 0.
Compare arr[i] with num.
If they are equal: Return i.
Otherwise, move to the next element.
If the loop finishes without finding the element, return -1. */

//CODE:
int search(int arr[], int n, int num){
  for(int i=0;i<n;i++){
     if(arr[i]==num){
        return i;
     }
  }
  return -1;
}
