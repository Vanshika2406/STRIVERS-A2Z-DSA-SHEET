/*
QUESTION:
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Intuition:
Since both arrays are already sorted,
the largest elements of arr1 are at the end.
the smallest elements of arr2 are at the beginning.
So compare:
Last element of arr1
First element of arr2
If the last element of arr1 is larger,
they are in the wrong arrays.
Swap them.

CODE:
*/
void merge(long long arr1[], long long arr2[], int n, int m){
          int left = n-1;
          int right = 0;
          while(left>=0 && right < m){
               if(arr1[left]>arr2[right]){
                   swap(arr1[left], arr2[right]);
                   left--, right++;
               }
                else{
                     break;
                }
          }
           sort(arr1, arr1 + n);
           sort(arr2, arr2 + m);
       }
};

//Time Complexity: O(min(n,m) + n log n + m log m)
//Space Complexity: O(1)


