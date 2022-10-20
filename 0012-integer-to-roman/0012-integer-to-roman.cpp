class Solution {
public:
    string intToRoman(int num) {
        int count=0;
        string s="";
        string s1[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int s2[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int i=0;
        while(num!=0){
            if(num-s2[i]>=0){
                num=num-s2[i];
                s+=s1[i];
            }
            else{
                i++;
            }
        }
        return s;
    }
};