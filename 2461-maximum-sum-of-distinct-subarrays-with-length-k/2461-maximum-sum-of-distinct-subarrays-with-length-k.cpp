class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        long long sum=0,j=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(s.size()==k){
                ans=max(ans,sum);
                sum-=nums[j];
                s.erase(nums[j]);
                j++;
            }
            if(s.find(nums[i])!=s.end()){
                while(nums[j]!=nums[i]&&j<i){
                    sum-=nums[j];
                    s.erase(nums[j]);
                    j++;
                }
                sum-=nums[j];
                s.erase(nums[j]);
                j++;
            }
            s.insert(nums[i]);
            sum+=nums[i];
        }
        if(s.size()==k){
            ans=max(ans,sum);
            s.erase(nums[j]);
            j++;
        }
        return ans;
    }
};