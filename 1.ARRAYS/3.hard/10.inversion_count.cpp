/*
QUESTION:
Given an array of integers. Find the Inversion Count in the array.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Example 1:
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
Input: N = 5, arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted, there is no inversion count.

APPROACH:
To find the inversion count in the array, we can utilize the merge sort algorithm. The idea is to divide the array into two halves, recursively count the inversions in each half, and then merge the two halves while counting the inversions across them.

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

  return cnt;
}
//merge sort
int mergeSort(vector<int> &arr, int low, int high){
    int cnt =0;
    if(low>= high) return cnt;
    int mid = (low+high)/2;
    cnt+= mergeSort(arr, low, mid); //left half 
    cnt += mergeSort(arr, mid+1, high); //right half
    cnt += merge(arr,low,mid,high);  // merging sorted halves
    return cnt;
}
int numberOfInversions(vector<int>&a, int n){
    return mergeSort(a, 0, n-1);
}

//time complexity= O(nlogn)
//space complexity = O(n)
   
