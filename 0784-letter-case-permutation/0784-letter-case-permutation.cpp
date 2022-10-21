class Solution {
public:
    void helper(string s,vector<string>& ans,int i){
        if(i==s.size()){
            ans.push_back(s);
            return;
        }
        if(s[i]>=97&&s[i]<=122){
            s[i]=s[i]-32;
            helper(s,ans,i+1);
            s[i]=s[i]+32;
        }
        else if(s[i]>=65&&s[i]<=91){
            s[i]=s[i]+32;
            helper(s,ans,i+1);
            s[i]=s[i]-32;
        }
        helper(s,ans,i+1);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        helper(s,ans,0);
        return ans;
    }
};