/*
QUESTION:
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Example:
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

APPROACH:
To solve this problem, we can use the merge sort algorithm. While merging the two sorted subarrays, we can count the number of reverse pairs.

1. Define a variable 'rev_pair' to store the count of reverse pairs.
2. Implement the 'merge' function to merge two subarrays and count the reverse pairs.
3. Implement the 'mergesort' function to recursively divide the array into subarrays and perform merge sort.
4. Initialize 'rev_pair' to 0 and call the 'mergesort' function on the given array.
5. Return the 'rev_pair' as the result.

CODE:
*/
int merge(vector<int> &arr, int low, int mid, int high){
  vector<int> temp; //temporary array
  int left = low; // starting index opf left half of array
  int right = mid + 1;  //starting index of right half of array

//storing elements in the temporary array in a sorted manner
  int cnt =0;
  while(left<=mid && right<=high){
     if(arr[left] <= arr[right]){
        temp.push_back(arr[left]);
        left++;
     }
     // right is smaller
     else{
        temp.push_back(arr[right]);
        cnt +=(mid-left +1);  //gives the number of remaining elements in the left sorted subarray, all of which are greater than the current right element
        right++;
     }
  }
// if elements on the left half is still left
  while(left<=mid){
      temp.push_back(arr[left]);
      left++;
  }
  //same for right
  while(right<=high){
      temp.push_back(arr[right]);
      right++;
  }
// transfering all elements from temp to array
 for(int i = low; i <= high; i++){
    arr[i] = temp[i-low];  //Subtracting low converts the index in arr into the corresponding index in temp.
 }
}
int countPairs(vector<int> &arr,int low, int mid,int high){
    int right = mid +1;
    int cnt = 0;
    for(int i = low;i<=mid;i++){
        while(right<= high && arr[i] > 2*arr[right]) right++;
        cnt += (right - ( mid + 1));
    }
    return cnt;
}
//merge sort
int mergeSort(vector<int> &arr, int low, int high){
    int cnt =0;
    if(low>= high) return cnt;
    int mid = (low+high)/2;
    cnt+= mergeSort(arr, low, mid); //left half 
    cnt += mergeSort(arr, mid+1, high); //right half
    cnt += countPairs(arr,low,mid,high);  // merging sorted halves
    merge(arr,low,mid,high);
    return cnt;
}
int team(vector<int>&skill, int n){
    return mergeSort(skill, 0, n-1);
}
//TIME COMPLEXITY : O(2Nlogn)
//SPACE COMPLEXITY : O(N)
