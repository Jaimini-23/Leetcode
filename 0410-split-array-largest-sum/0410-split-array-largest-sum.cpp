class Solution {
public:
    int cntSubarray(vector<int> &nums, int num) {
        int subarray = 1;
        long long cntNum = 0;
        for(int i=0; i<nums.size(); i++) {
            if(cntNum + nums[i] <= num) {
                cntNum += nums[i];
            }
            else {
                subarray++;
                cntNum = nums[i];
            }
        }
        return subarray;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int subarray = cntSubarray(nums,mid);
            if(subarray > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};