class Solution {
public:

    string encode(vector<string>& strs) {
          string ans;
        for(int i=0; i<strs.size(); i++){
            ans += to_string(strs[i].size()) + "#" + strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
    //  cout<<"the string is "<<s<<"with length "<<s.length()<<endl;
        vector<string> ans;
        int i =0; 
        int length = 0;
        while(s[i]){
            length = 0;
            string to_put ="";
            if(s[i+1] == '#' && (s[i] - '0' >=0 && s[i] - '0'<=9)){
                // cout<<"the diff is "<<s[i] - '0'<<endl;
                
                length = s[i]- '0';
                int j = i+2; 
            while(j< i+2 + length){
            to_put += s[j];
            j++;
            }
            i = i+length+2;
            ans.push_back(to_put);
            continue;
            }
            
            else{
                string rest_string = "";
                rest_string += s[i++];
                ans.push_back(rest_string);
            }
            
            // cout<<"length toh dekh "<<i<<endl;
        }
        return ans;
    }
};
