// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int isvalid(int maxPages, int a[], int n, int totalStudents){
        
        int stud = 1;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += a[i];
            if(sum > maxPages){
                stud++;
                sum = a[i];
            }
            if(stud > totalStudents){
                return false;
            }
        }
        
        return true;
        
    }
        
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N){
            return -1;
        }
        
        int start = 0;
        for(int i = 0 ; i < N ; i++){
            start = max(start, A[i]);
        }
        
        int end = 0;

        for(int i = 0 ; i < N ; i++){
            end+= A[i];
        }
        
        int res = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(isvalid(mid, A, N, M)){
                res= mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends