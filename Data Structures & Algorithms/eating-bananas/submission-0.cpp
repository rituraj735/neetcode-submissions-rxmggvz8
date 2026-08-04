class Solution {
public:
    int getOut(int mid, vector<int>& piles){
        int ans = 0;
        for(int i =0; i<piles.size();i++){
            ans += (piles[i]+mid-1)/mid;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int _min= 1, _max = INT_MIN;
        for(int i =0; i<piles.size(); i++){
            _max = max(_max, piles[i]);
        }
        int n = piles.size();
        int l = 1, r = _max;
        int mid;
        int ans = r;
        while(l<=r){
            mid = (l+r)/2;
            if(getOut(mid, piles)>h) l = mid+1;
            else{
                ans = mid;
                r = mid -1;
            }
        }
        return ans;
    }
};
