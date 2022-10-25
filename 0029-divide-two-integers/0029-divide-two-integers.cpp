class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign=(dividend<0)^(divisor<0)?-1:1;
        if(divisor==1){
            return dividend;
        }
        if(divisor==-1){
            if(dividend==INT_MIN){
                return INT_MAX;
            }
            return -dividend;
        }
        long long a=(long long)abs(dividend);
        long long b=(long long)abs(divisor);
        long long quotient=0;
        while(a>=b){
            a-=b;
            quotient++;
        }
        if(sign>0&&quotient>INT_MAX){
            return INT_MAX;
        }
        else if(sign<0&&quotient<INT_MIN){
            return INT_MIN;
        }
        return quotient*sign;
    }
};