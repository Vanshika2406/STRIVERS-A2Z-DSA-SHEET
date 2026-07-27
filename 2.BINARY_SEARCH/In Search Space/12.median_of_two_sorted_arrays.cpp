/*QUESTION:
Given two sorted arrays nums1 and nums2 of sizes m and n respectively, you need to find the median of the two sorted arrays.

APPROACH:
To find the median of two sorted arrays, we can apply the concept of binary search. The overall time complexity of the solution should be O(log (m+n)).

1. First, we ensure that nums1 is the smaller sized array. If not, we swap nums1 and nums2.
2. Calculate the optimal count opt_cnt, which is (nums1.size() + nums2.size() + 1) / 2. This represents the median index in the merged array.
3. Initialize low to 0 and high to nums1.size() - 1.
4. Perform binary search until low is less than or equal to high:
     - Calculate the cut1 as low + (high - low) / 2, which represents the potential index to partition nums1.
     - Calculate cut2 as opt_cnt - cut1, which represents the corresponding index in nums2.
     - Calculate l1, l2, r1, and r2 as the left and right elements around the potential partition points.
     - If l1 is less than or equal to r2 and l2 is less than or equal to r1, it means we have found the correct partition points.
          - If the total number of elements is even, return the average of the maximum of l1 and l2 and the minimum of r1 and r2.
          - If the total number of elements is odd, return the maximum of l1 and l2.
     - If l1 is greater than r2, move the high pointer to cut1 - 1.
     - Otherwise, move the low pointer to cut1 + 1.
5. If no median is found, return 0.0.

CODE:*/
double median(vector<int>& a, vector<int>& b){
  int n1 = a.size();
  int n2 = b.size();
  if(n1>n2) return median(b,a); //Always binary search on the smaller array.
  int low =  0, high = n1;
  int left = (n1 + n2 + 1)/2;
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
            if(n%2 == 1) return max(l1,l2);
            return ((double)(max(l1, l2) + min(r1,r2))) / 2.0;
       }
       else if(l1>r2) high = mid1-1;
        else low = mid1 + 1;
  }
  return 0;
}
/*Time & Space Complexity
Time: O(log(min(n1, n2))) because binary search is performed only on the smaller array.
Space: O(1) since only a few variables are used.*/
double median(vector<int>& a, vector<int>& b){
  int n1 = a.size(), n2= b.size();
  int i = 0;
  int j = 0;
  int n = (n1+n2); //Calculates the total number of elements across both arrays combined.
  int ind2 = n/2;
  int ind1 = ind2 - 1;
  int cnt = 0;
  int ind1el = -1, ind2el = -1;
  while(i<n1 && j<n2){
      if(a[i] < b[j]){ //Compares the current elements. If a[i] is smaller, it belongs next in our sorted sequenc
        if(cnt == ind1) ind1el = a[i]; //if our current step cnt matches the left median index, save the number a[i] into ind1el.
        if(cnt == ind2) ind2el = a[i]; //If our current step cnt matches the right median index, save the number a[i] into ind2el.
        cnt++;
        i++;
      }
      else{
        if(cnt == ind1) ind1el = b[j];
        if(cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
      }
  }
  while(i<n1){
        if(cnt == ind1) ind1el = a[i];
        if(cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
  }
  while(j<n2){
        if(cnt == ind1) ind1el = b[i];
        if(cnt == ind2) ind2el = b[i];
        cnt++;
        j++;
  }
  if(n%2 == 1){ //Checks if the total number of elements (n) is odd. If it is, there is a single exact middle element, which is stored in ind2el.
     return ind2el;
  } //If n is even, the median is the average of the two middle elements (ind1el and ind2el). We cast to double and divide by 2.0 to preserve decimal precision.
  return (double)(ind1el + ind2el) / 2.0;
}
