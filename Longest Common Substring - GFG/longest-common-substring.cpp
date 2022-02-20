// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string X, string Y, int n, int m)
    {
        // your code here
        
        int t[n+1][m+1];
        
        int maxLength = 0;
        
        for(int i = 0 ; i < n+1 ; i ++){
            t[i][0] = 0;
        }
        
        for(int j = 0 ; j < m+1 ; j++){
            t[0][j] = 0;
        }
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(X[i-1] == Y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                    maxLength = max(t[i][j], maxLength);
                }
                else{
                    t[i][j] = 0;
                }
            }
        }
        
        return maxLength;
        
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends