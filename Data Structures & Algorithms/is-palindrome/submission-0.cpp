class Solution {
public:
    bool isPalindrome(string s) {
        int pointer_1=0, pointer_2=s.length()-1;
        while(pointer_1<= pointer_2){
            if(isalnum(s[pointer_1]) && isalnum(s[pointer_2]) ){
                if(tolower(s[pointer_1]) != tolower(s[pointer_2]))
                    return false;
                else{
                    pointer_1++;
                    pointer_2--;
                }
            }
            else{
                if(!isalnum(s[pointer_1])) pointer_1++;
                if(!isalnum(s[pointer_2])) pointer_2--;
            }
        }
        return true;
    }
};
