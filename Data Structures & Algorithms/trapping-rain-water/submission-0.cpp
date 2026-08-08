class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int p1=0, p2=0; 
        const int n = height.size();
        vector<int> arr(n);
        int max_ = INT_MIN;
        for(int i =0; i<height.size(); i++){
            max_ = max(height[i], max_);
            arr[i] = max_;
            
        }
        while(p1 < height.size() && p2 < height.size()){
            while( p2 < height.size() && height[p2]<height[p1] ){
                p2++;
            }
            while( p1!=p2 ){
                if(height[p2] == arr[p2]){
                res += (arr[p1]-height[p1]); 
                }
                p1++;
            }
            if(p1==p2){
                p2++;
            }
        }
        return res;
    }
};
