class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long totalSum = 0;

        for (auto num: nums) {
            totalSum += num;
        }

        long leftSum = 0;
        int ways = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            if (leftSum >= (totalSum - leftSum)) {
                ways++;
            }
        }
        return ways;
    }
};