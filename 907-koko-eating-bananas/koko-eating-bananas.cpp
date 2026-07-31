class Solution {
public:
    
    int findMax(vector<int>& nums) {
        int maxi = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }

    long long calculateHours(vector<int>& nums, int speed) {
        long long totalHours = 0;

        for (int pile : nums) {
            totalHours += (pile + speed - 1LL) / speed;
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = findMax(piles);

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hours = calculateHours(piles, mid);

            if (hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};