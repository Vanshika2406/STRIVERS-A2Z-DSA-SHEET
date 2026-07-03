/*QUESTION:
intersection of two sorted arrays given to you and return
If an element appears multiple times in both arrays, include it as many times as it appears in both arrays

EXAMPLE:
Input:
arr1 = [1,2,2,3,4]
arr2 = [2,2,3,5]
Output: [2,2,3]

APPROACH:
If both elements are equal, add the element to the answer and move both pointers.
If the first array's element is smaller, move the first pointer.
Otherwise, move the second pointer.

Initialize:
i = 0
j = 0
While both pointers are within their arrays:
If arr1[i] == arr2[j]
Add the element to the answer.
Increment both pointers.
Else if arr1[i] < arr2[j]
Increment i.
Else
Increment j.
*/

//code:
vector<int> findintersection( int arr1[], int arr2[], int n, int m){
int i =0;
int j =0;
vector<int>ans;
while(i<n && j<m){
     if(arr1[i]<arr2[j]){
        i++;
     }
     else if(arr2[j]<arr1[i]){
           j++;
     }
     else{
     ans.pushback(a[i]);
        i++;
        j++;
     }
}
return ans;

//tc-O(n1+n2)
//sc - O(1)
