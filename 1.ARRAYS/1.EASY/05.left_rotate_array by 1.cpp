/*QUESTION:-
Given an array "ARR' containing 'N' elements, rotate this array Left by once means to shift all elements by one place to the left and move the first element to the last position in the array.

Example 1:
Input:
nums = [1, 2, 3, 4, 5]  
Output: [2, 3, 4, 5, 1]  
Explanation:
Initially, nums = [1, 2, 3, 4, 5]  
Rotating once to the left results in nums = [2, 3, 4, 5, 1].
*/

//approach

/*The first element will be lost when you shift everything left, so store it first.
Shift every element one position to the left.
Put the stored first element at the last index.

1.Save the first element in a temporary variable.
2.traverse the array from index 0 to N-2.
3.For each index i, assign:
ARR[i] = ARR[i - 1]
4.After the loop, place the saved element at the last position:
ARR[N - 1] = temp
*/

//code:

vector<int> rotateArray(vector<int> &arr, int n){
     int temp=arr[0];
     for(int i=0;i<n;i++){
        arr[i-1]=arr[i];
      }
      arr[n-1]=temp;
      return arr;
}
//tc=o(n)
//sc=o(1)


