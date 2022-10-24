class Solution {
public:
    #define pi pair<int,int>
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pi> v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end(),[&](pi a,pi b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first<b.first;
        });
        priority_queue<int> pq;
        int i=0;
        while(k--){
            while(i<v.size()&&v[i].first<=w){
                pq.push(v[i].second);
                i++;
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
        }
        return w;
    }
};