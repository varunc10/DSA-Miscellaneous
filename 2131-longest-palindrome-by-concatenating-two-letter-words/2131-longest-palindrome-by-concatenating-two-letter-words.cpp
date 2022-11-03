class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        bool flag=false;
        int ans=0;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            reverse(s.begin(),s.end());
            if(m.find(s)!=m.end()){
                m[s]--;
                if(m[s]==0){
                    m.erase(s);
                }
                ans+=4;
            }
            else{
                m[words[i]]++;
            }
        }
        for(auto i:m){
            string s=i.first;
            string t=i.first;
            reverse(t.begin(),t.end());
            if(s==t){
                flag=true;
            }
        }
        return flag?ans+2:ans;
    }
};