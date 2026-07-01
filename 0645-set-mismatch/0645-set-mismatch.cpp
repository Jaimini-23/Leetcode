class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        long long S = 0, S2 = 0;
        long long Sn = (1LL * n * (n + 1)) / 2;
        long long S2n = (1LL * n * (n + 1) * (2 * n + 1)) / 6;
        for(int i=0;i<n;i++) {
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }
        long long val1 = S - Sn;           // x - y
        long long val2 = S2 - S2n;        // x^2 -y^2
        val2 = val2 / val1;                // x + y
        long long x = (val1 + val2) / 2;
        ans.push_back(x);
        long long y = x - val1;
        ans.push_back(y);
        return ans;
    }
};