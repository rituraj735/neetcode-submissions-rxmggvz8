class Solution {
public:
    bool isValid(string s) {
        stack<char> input;
        for(auto x: s){
            if(!input.empty() && ((x == ']' && input.top() == '[') || (x == '}' && input.top() == '{') || (x == ')' && input.top() == '('))){
                input.pop();
                continue;
            }
            else{
                input.push(x);
            }
        }
        if(!input.empty()) return false;
        else return true;
    }
};
