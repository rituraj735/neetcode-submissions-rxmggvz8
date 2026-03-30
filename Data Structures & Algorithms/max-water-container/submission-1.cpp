class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0, p2 = heights.size()-1;
        int max_water = INT_MIN;
        while(p1<p2){
            max_water = max(max_water,(p2-p1)*min(heights[p2],heights[p1]));
            if(heights[p2]> heights[p1])
                p1++;
            else if(heights[p2]< heights[p1])
                p2--;
            else
                p1++, p2--;
        }
        return max_water;
    }
};
