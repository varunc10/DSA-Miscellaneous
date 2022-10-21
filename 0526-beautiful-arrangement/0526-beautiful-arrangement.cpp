class Solution {
public:
    void helper(vector<int>& v,int i,vector<bool>& vis,int &count){
        if(i==v.size()){
            count++;
            return;
        }
        for(int j=1;j<v.size();j++){
            if(!vis[j]&&(v[j]%i==0||i%v[j]==0)){
                vis[j]=true;
                helper(v,i+1,vis,count);
                vis[j]=false;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            v[i]=i;
        }
        vector<bool> vis(n+1,false);
        int count=0;
        helper(v,1,vis,count);
        return count;
    }
};