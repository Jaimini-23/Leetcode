class Solution {
public:
    int findDays(vector<int> &weight, int cap) {
        int days = 1, load = 0;
        for(int i=0; i<weight.size(); i++) {
            if(load + weight[i] > cap) {
                days++;
                load = weight[i];
            }
            else {
                load += weight[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weight, int days) {
        int low = *max_element(weight.begin(),weight.end());
        int high = accumulate(weight.begin(),weight.end(),0LL);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int numberOfDays = findDays(weight, mid);
            if(numberOfDays <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};