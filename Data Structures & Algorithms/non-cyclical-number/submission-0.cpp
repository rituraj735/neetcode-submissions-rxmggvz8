class Solution {
public:
    int check(int n){
        int sum = 0;
        while(n){
            sum += pow((n%10),2);
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(check(n)!=1){
            n = check(n);
            if(seen.find(n) != seen.end()) return false;
            seen.insert(n);
        }
        return true;
    }
};
