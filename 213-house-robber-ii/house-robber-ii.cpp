class Solution {
public:
int solve(int n, vector<int>& dp, vector<int>& nums) {
        if (n < 0) return 0;      
        if (n == 0) return nums[0]; 
        
        if (dp[n] != -1) return dp[n];
        
        int pick = nums[n] + solve(n - 2, dp, nums);
        int notpick = 0 + solve(n - 1, dp, nums);
        
        return dp[n] = max(pick, notpick);
    }
    
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, dp, nums);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
       vector<int> first(nums.begin(),nums.end()-1);
       vector<int> second(nums.begin()+1,nums.end());
       return max(robLinear(first),robLinear(second));
    }
};