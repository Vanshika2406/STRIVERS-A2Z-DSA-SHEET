/*QUESTION:
You are given an integer array A of size N containing an equal number of positive and negative elements.
Your task is to rearrange the array such that:
->Positive and negative numbers appear alternately.
->The relative order of positive numbers remains the same.
->The relative order of negative numbers also remains the same.
->The rearranged array should start with a positive number.

Return the rearranged array.

Example:
Input: A = [3, 1, -2, -5, 2, -4]
Output: [3, -2, 1, -5, 2, -4]
Explanation
Positive numbers: [3, 1, 2]
Negative numbers: [-2, -5, -4]
Placing them alternately while preserving their order gives:
[3, -2, 1, -5, 2, -4]

APPROACH:
Since the array contains an equal number of positive and negative elements, we know exactly where each type should go:
Positive numbers → Even indices (0, 2, 4, ...)
Negative numbers → Odd indices (1, 3, 5, ...)
We can create a new array and place each element directly in its correct position while traversing the original array only once
*/

//code:
vector<int>rearrangeArray(vector<int>&nums){
  int n=nums.size(){
  vector<int>ans(n,0);
  int posIndex=0; negIndex=1;
  for(int i=0;i<n;i++){
      if(nums[i]<0){
         ans[negIndex]=nums[i];
         negIndex+=2;
      }
      else{
          ans[posIndex]=nums[i];
          posIndex+=2;
      }
  }
  return ans;
  }
};
//tc=O(N)
//sc=O(1)
