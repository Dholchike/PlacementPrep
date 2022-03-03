class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //return max( profit(nums,1, n-2) , profit(nums, 2, n-1) );
        
        if(n==0 ){
            return n; 
        }
        if(n==1){
            return nums[n-1];
        }
        
        
        vector<int> dp(n, -1);
        int firstHouseIncluded = profit2(nums, 0, n-2, dp);
        
        std::fill(dp.begin(), dp.end(), -1);
        
        int firstHouseExcluded = profit2(nums, 1, n-1, dp);
        
        return max(firstHouseIncluded, firstHouseExcluded);    
        
    }
    

    
    int profit2(vector<int> &cost, int i , int j, vector<int> &dp){
        if(j<i){
            return 0;
        }
        if(j==i){
            dp[j] = cost[j];
            return dp[j];
        }
        
        if(dp[j] != -1){
            return dp[j];
        }
        
        dp[j] = max(cost[j] + profit2(cost, i, j-2, dp), profit2(cost, i, j-1, dp)); 
        
        return dp[j];
    }
    
    int profit(vector<int> &cost, int i, int j){
        
        if(j<i ){
            return 0;
        }
        
        if(i==j){
            return cost[i];
        }
        
        
        return max(cost[j] + profit(cost, i, j-1), profit(cost, i, j-2));
        
        
    }
};