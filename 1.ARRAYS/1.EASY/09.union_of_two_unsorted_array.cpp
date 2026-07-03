/*QUESTION:
Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.
The union of two arrays can be defined as the common and distinct elements in the two arrays.

EXAMPLE:
Input:n = 5,m = 5 arr1[] = {1,2,3,4,5}  arr2[] = {2,3,4,4,5}
Output: {1,2,3,4,5}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5}
*/

/*APPROACH:
Initialize two pointers:
i = 0 for arr1
j = 0 for arr2
Compare arr1[i] and arr2[j].
Add the smaller element to the answer (if it's not already the last added element).
Move the corresponding pointer.
If both are equal:
Add one copy.
Move both pointers.
After one array finishes, add the remaining elements from the other array, skipping duplicates.
*/

//code

vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
  int i=0;
  int j=0;
  vector<int>union arr;
  while(i<n && j<m){
    if(arr1[i]<=arr2[j]){ // If current element in arr1 is smaller
      if(union.empty() || union.back() != arr1[i])  // Add element if union empty or different from last added
         union.push_back(arr1[i]);
      i++;
    }
    else if (arr2[j] < arr1[i]){    //If current element in arr2 is smaller
           if(union.empty() || union.back() != arr2[j])  // Add element if union empty or different from last added
         union.push_back(arr2[j]);
      j++;
    }
    else{   // Elements are equal, add once if not duplicate
         if(union.empty() || union.back() != arr1[i])  // Add element if union empty or different from last added
         union.push_back(arr1[i]);
      i++; j++;  // Move both pointers
    }
  }
// Append remaining elements from arr1
        while (i < n) {
            if (Union.empty() || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }

        // Append remaining elements from arr2
        while (j < m) {
            if (Union.empty() || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
        return union;
  }
};

//tc= o(n+m)
//sc=o(n+m)
  
