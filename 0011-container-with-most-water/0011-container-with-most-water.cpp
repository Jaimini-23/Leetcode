class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1;
        int maxArea = 0;
        while(j > i) {
            int h = min(height[i],height[j]);
            int area = (j-i)*h;
            maxArea = max(maxArea, area);
            
            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};