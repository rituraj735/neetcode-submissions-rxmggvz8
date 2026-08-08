class Solution {
public:
    static bool compare_pairs(const pair<int,int>& p1,const pair<int, int>& p2){
        return (p1.first > p2.first);
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res = 0;
        vector<pair<int,int>> paired;
        for(int i =0; i<position.size(); i++){
            paired.push_back({position[i], speed[i]});
        }
        sort(paired.begin(), paired.end(), compare_pairs);
        vector<double> time;
        for(int i =0; i< paired.size(); i++){
            time.push_back((double)(target - paired[i].first)/paired[i].second);
        }
        stack<double> stk;
        int i =0; 
        int n = position.size();
        while(i<n){
            if(!stk.empty() && stk.top()>=time[i]){
                stk.pop();
            }
            stk.push(time[i]);
            i++;
        }
        return stk.size();
    }
};
