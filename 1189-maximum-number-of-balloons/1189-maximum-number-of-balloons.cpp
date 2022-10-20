class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        if(text.size()<7){
            return 0;
        }
        for(auto i:text){
            if(i=='b'||i=='a'||i=='l'||i=='o'||i=='n'){
                m[i]++;
            }
        }
        int mx=INT_MAX;
        for(auto i:text){
            if(i=='b'||i=='a'||i=='n'){
                mx=min(mx,m[i]);
            }
            else if(i=='l'||i=='o'){
                mx=min(mx,m[i]/2);
            }
        }
        return mx;
    }
};