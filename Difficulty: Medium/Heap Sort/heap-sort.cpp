//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
    //   // Your Code Here
    //   int large = i;
    //   int left = 2*i +1;
    //   int right = 2*i +2;
      
    //   if(left < n && arr[large] < arr[left] ) large = left;
    //   if(right < n && arr[large] < arr[right] ) large = right;
      
    //   if(large!=i) {
    //       swap(arr[i] , arr[large]);
    //       heapify(arr , n , large);
    //   }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // // Your Code Here
    //     for(int i = n/2 -1; i>=0 ; i++) {
    //         heapify(arr , n ,i);
    //     }
        
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // buildHeap(arr,n);
        // //code here
        // while(n>0) {
        //     swap(arr[n-1],arr[0]);
        //     n--;
        //     heapify(arr,n,0);
        // }
        priority_queue<int> pq;
        for(int i=0;i<n;i++) {
            pq.push(arr[i]);
        }
        for(int i=n-1;i>=0;i--){
            arr[i] = pq.top();
            pq.pop();
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends