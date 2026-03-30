class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        int n = temperatures.size();
        vector<int> output(n);
        int i = 0;
        while(i<n){
            while(!stk.empty()&& temperatures[stk.top()]<temperatures[i]){
                    int position = stk.top();
                    stk.pop();
                    output[position] = (i - position);
                }
                stk.push(i);
            i++;
        }
        return output;
    }
};
