class Solution {
public:
    vector<string> readBinaryWatch(int n) {
    
        vector<string> ans;    
        
        for(int i = 0 ; i < 12 ; i++){
            for(int j = 0 ; j < 60 ; j++ ){
                string temp = "";
                if(__builtin_popcount(i) + __builtin_popcount(j)  == n){
                    
                    temp += (to_string(i) + ":");
                    
                    if( j < 10){
                        temp += "0";
                    }
                    
                    temp += (to_string(j));
                    
                    ans.push_back(temp);
                    
                }
            }
        }
        
        return ans;
        
        
        
    }
};