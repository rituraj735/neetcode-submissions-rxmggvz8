class MinStack {
public:
    vector<int> arr;
    vector<int> prefix_arr;
    int min_ = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(arr.size()==0){
            
            prefix_arr.push_back(val);
            min_ = min(min_, val);
        }
        else{
            if(val< min_){
                prefix_arr.push_back(val);
                min_ = val;
            }
            else{
                prefix_arr.push_back(min_);
            }
        }
        arr.push_back(val);

        
    }
    
    void pop() {
        if(arr[arr.size()-1]== min_){
            min_ = prefix_arr[arr.size()-2];
        }
        arr.pop_back();
        prefix_arr.pop_back();
    }
    
    int top() {
        return arr[arr.size()-1];
    }
    
    int getMin() {
        return prefix_arr[prefix_arr.size()-1];
    }
};
