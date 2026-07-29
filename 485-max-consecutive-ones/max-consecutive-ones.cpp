class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int max_i = 0;
        int count = 0;

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            if(nums[i] == 1) {
                count++;
                max_i = max(max_i, count);
            }
            else {
                count = 0;
            }
        }

        return max_i;
    }
};