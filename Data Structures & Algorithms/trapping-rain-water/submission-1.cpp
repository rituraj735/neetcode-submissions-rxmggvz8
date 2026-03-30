class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        int maxLeft = height[0], maxRight = height[n-1];
        int p1 = 0, p2 = n-1;
        int res =0;
        while(p1< p2){
            if(maxLeft < maxRight){
                p1++;
                maxLeft = max(maxLeft, height[p1]);
                res += maxLeft - height[p1];
            }
            else{
                p2--;
                maxRight = max(maxRight,height[p2]);
                res += maxRight - height[p2];
            }
        }
        return res;
    }
};
