class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorNums=0;
        for(int it: nums) xorNums ^= it;
        return xorNums;
    }
};