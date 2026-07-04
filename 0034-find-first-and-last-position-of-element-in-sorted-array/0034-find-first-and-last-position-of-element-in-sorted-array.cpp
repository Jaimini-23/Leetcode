class Solution {
public:
    int findFirst(vector<int> &arr, int n, int target) {
        int low = 0;
        int high = n - 1;
        int first = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if(arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return first;
    }
    int findLast(vector<int> &arr, int n, int target) {
        int low = 0;
        int high = n - 1;
        int last = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if(arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        int first = findFirst(nums, n, target);
        ans.push_back(first);
        int last = findLast(nums, n, target);
        ans.push_back(last);
        return ans;
    }
};