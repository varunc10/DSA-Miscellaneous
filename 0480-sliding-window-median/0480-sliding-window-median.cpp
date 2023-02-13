class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multimap<double,int> m;
        vector<double> ans;
        for(int i = 0; i < k-1; i++){
            m.insert({(double)nums[i], i});
        }
        for(int i = k-1; i < nums.size(); i++){
            m.insert({(double)nums[i],i});
            int n = m.size();
            if(n%2 == 0){
                auto it = m.begin();
                advance(it, n/2);
                int u = it->first;
                it--;
                int v = it->first;
                ans.push_back(u/2.00+v/2.00);
            }
            else{
                auto it = m.begin();
                advance(it, n/2);
                int u = it->first;
                ans.push_back(u);
            }
            auto it=m.find(nums[i-k+1]);
            m.erase(it);
        }
        return ans;
    }
};