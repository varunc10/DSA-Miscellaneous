class Solution {
public:
    int sumOfDig(long long n) {
        int ans=0;
        while(n){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long ans=0;
        for(long long j=1;sumOfDig(n)>target;j*=10){
            ans+=(10-n%10)*j;
            n=(n/10)+1;
        }
        return ans;
    }
};