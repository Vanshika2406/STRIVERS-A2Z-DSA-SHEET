/*
Question:-
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K.
Find the element that would be at the kth position of the final sorted array.

Example:- 

Input:
arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
k = 5
Output:
6
Explanation:
The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.

CODE:
int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
  if(n1>n2) return kth Element(b,a,n2,n1,k); //Always binary search on the smaller array.
  int low =  max(k-n2,0), high = min(k,n1);
  int left = k;
  int n = n1 + n2;
  while(low <= high){
       int mid1 = (low + high) >> 1; // taking equal elements from both sides
       int mid2 = left - mid1;
       int l1 = INT_MIN, l2 = INT_MIN; //Because partition can occur at the boundaries.
       int r1 = INT_MAX, r2 = INT_MAX;
       if(mid1 < n1) r1 = a[mid1];
       if(mid2 < n2) r2 = b[mid2];
       if(mid1 - 1 >= 0) l1 = a[mid1-1];
       if(mid2 - 1 >= 0) l2 = b[mid2-1];
       if(l1 <= r2 && l2 <= r1){
           return max(l1,l2);
       }
       else if(l1>r2) high = mid1-1;
        else low = mid1 + 1;
  }
  return 0;
}

//Time Complexity: O(log(min(N, M)))
//space complexity = O(1)
