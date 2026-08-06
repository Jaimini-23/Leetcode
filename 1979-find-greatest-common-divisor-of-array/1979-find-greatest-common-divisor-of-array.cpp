class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = *min_element(nums.begin(),nums.end());
        int b = *max_element(nums.begin(),nums.end());
        
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};