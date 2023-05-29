class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //this is longest common substring
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        //base case handled via our dp array ki intialisation
        // dp[0][j]= 0 and dp[i][0] = 0 for all i and j
        
        int ans = 0;
        for(int i =1 ; i<= n1 ; i++){
            for(int j =1 ; j <= n2 ; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;
        
    }
};