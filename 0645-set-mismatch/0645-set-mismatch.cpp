class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;

        // XOR of array elements and numbers from 1 to n
        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
            xr ^= (i + 1);
        }

        // Rightmost set bit
        int number = xr & ~(xr - 1);

        int one = 0, zero = 0;

        // Divide array elements into two groups
        for (int i = 0; i < n; i++) {
            if (nums[i] & number)
                one ^= nums[i];
            else
                zero ^= nums[i];
        }

        // Divide numbers 1 to n into two groups
        for (int i = 1; i <= n; i++) {
            if (i & number)
                one ^= i;
            else
                zero ^= i;
        }

        // Determine which is repeating
        int cnt = 0;
        for (int x : nums) {
            if (x == one)
                cnt++;
        }

        if (cnt == 2)
            return {one, zero};   // repeating, missing
        else
            return {zero, one};   // repeating, missing
    }
};