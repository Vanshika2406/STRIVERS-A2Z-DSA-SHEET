/*Problem Statement: 
Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order. The sorting must be done in-place, without making a copy of the original array

EXAMPLE:
Input: nums = [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two

APPROACH:
Case 1: nums[mid] == 0
Swap nums[mid] with nums[low].
Increment both low and mid.

Reason: 0 belongs at the beginning.After swapping, the element at mid has already been processed.

Case 2: nums[mid] == 1
Just increment mid.
Reason:1 is already in its correct middle region.

Case 3: nums[mid] == 2
Swap nums[mid] with nums[high].
Decrement high.
Do not increment mid.

Reason:The element coming from the high position is unprocessed, so it must be checked again.

void sortnums(vector<int> &arr){
    int low=0;mid=0;high=n-1;
    while(mid<=high){
         if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
}
        else if(arr[mid]==1){
             mid++;
}
        else{
            swap(arr[mid],arr[high]);
            high--;
   }
}

//TIME COMPLEXITY = O(N)
//SPACE COMPLEXITY = O(1)
