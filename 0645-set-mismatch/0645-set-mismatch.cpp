class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int miss,twice;
        for(int i=1;i<=nums.size();i++){
            if(m[i]==2){
                twice=i;
            }
            if(m[i]==0){
                miss=i;
            }
        }
        return {twice,miss};
    }
};