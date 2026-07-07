class Solution {
public:
    bool canMake(vector<int>& bloomDay, int day, int m, int k) {
        int n = bloomDay.size();
        int flowers = 0;
        int bouquets = 0;
        for(int i=0; i<n; i++) {
            if(bloomDay[i] <= day) {
                flowers++;
                if(flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL * m * k > n) return -1; 
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canMake(bloomDay, mid, m, k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};