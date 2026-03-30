class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i =0; i<tokens.size(); i++){
            if(tokens[i]=="+"){
                int operand_1 = stk.top(); stk.pop();
                int operand_2 = stk.top(); stk.pop();
                int res = operand_1 + operand_2;
                stk.push(res);
            }
            else if(tokens[i]=="-"){
                int operand_1 = stk.top(); stk.pop();
                int operand_2 = stk.top(); stk.pop();
                int res = operand_2 - operand_1;
                stk.push(res);
            }
            else if(tokens[i]=="*"){
                int operand_1 = stk.top(); stk.pop();
                int operand_2 = stk.top(); stk.pop();
                int res = operand_1 * operand_2;
                stk.push(res);
            }
            else if(tokens[i]=="/"){
                int operand_1 = stk.top(); stk.pop();
                int operand_2 = stk.top(); stk.pop();
                int res = (operand_2 / operand_1);
                stk.push(res);
            }   
            else{
                stk.push(stoi(tokens[i]));
            }
    
        }
        return stk.top();
    }
};
