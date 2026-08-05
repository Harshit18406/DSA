class Solution {
public:

    int countPartitions(vector<int>& nums, int limit) {

        int partitions = 1;
        int sum = 0;

        for (int x : nums) {

            if (sum + x <= limit)
                sum += x;
            else {
                partitions++;
                sum = x;
            }
        }

        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int partitions = countPartitions(nums, mid);

            if (partitions <= k)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};