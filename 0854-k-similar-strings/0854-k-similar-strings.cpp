class Solution {
public:
    int helper(unordered_map<string,int>& m,string s1,string s2,int i){
        if(i>=s1.size()){
            return 0;
        }
        if(s1==s2){
            return 0;
        }
        if(m.find(s1)!=m.end()){
            return m[s1];
        }
        int ans=INT_MAX;
        while(i<s1.size()&&s1[i]==s2[i]){
            i++;
        }
        for(int j=i+1;j<s1.size();j++){
            if(s1[j]==s2[i]){
                swap(s1[j],s1[i]);
                int temp_ans=helper(m,s1,s2,i+1);
                if(temp_ans!=INT_MAX){
                    ans=min(ans,temp_ans+1);
                }
                swap(s1[j],s1[i]);
            }
        }
        m[s1]=ans;
        return ans;
        
    }
    int kSimilarity(string s1, string s2) {
        unordered_map<string,int> m;
        return helper(m,s1,s2,0);
    }
};