class Solution {
public:
    string helper(int n, unordered_map<int,string>& m, vector<string>& v ,int j){
        string s = ""; 
        vector<int> t;
        while(n){
            t.push_back(n % 10);
            n /= 10;
        }
        reverse(t.begin(), t.end());
        if(t.size() == 1){
            s += m[t[0]] + " " + v[j] + " ";
        }
        else if(t.size() == 2){
            int n = t[0]*10 + t[1];
            if(n == 0){
                s += m[n] + " " + v[j] + " ";
            }
            else if(n < 20){
                s += m[n] + " " + v[j] + " ";
            }
            else{
                if(t[1] == 0){
                    s += m[n - t[1]] + " " + v[j] + " ";
                }
                else{
                    s += m[n - t[1]] + " " + m[t[1]] + " " + v[j] + " "; 
                }
            }
        }
        else if(t.size() == 3){
            int l = t[0];
            int n = t[1]*10 + t[2];
            if(n == 0){
                s += m[l] + " " + "Hundred" + " " + v[j] + " ";
            }
            else if(n < 20){
                s += m[l] + " " + "Hundred" + " " + m[n] + " " + v[j] + " ";
            }
            else{
                if(t[2] == 0){
                    s += m[l] + " " + "Hundred" + " " + m[n - t[2]] + " " + v[j] + " "; 
                }
                else{
                    s += m[l] + " " + "Hundred" + " " + m[n - t[2]] + " " + m[t[2]] + " " + v[j] + " "; 
                }
            }
        }
        return s;
    }
    int func(vector<int>& temp, int j){
        int n = 0, end = j - 3;
        while(j > end && j >= 0){
            n *= 10;
            n += temp[j] % 10;
            j--;
        }
        return n;
    }
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        unordered_map<int,string> m {{1,"One"}, {2,"Two"}, {3,"Three"}, {4,"Four"}, {5,"Five"},
                                    {6,"Six"}, {7,"Seven"}, {8,"Eight"}, {9,"Nine"}, {10,"Ten"},
                                    {11,"Eleven"}, {12,"Twelve"}, {13,"Thirteen"}, {14,"Fourteen"},
                                    {15,"Fifteen"}, {16,"Sixteen"}, {17,"Seventeen"}, {18,"Eighteen"},
                                    {19,"Nineteen"}, {20,"Twenty"}, {30,"Thirty"}, {40,"Forty"},
                                    {50,"Fifty"}, {60,"Sixty"}, {70,"Seventy"}, {80,"Eighty"}, {90,"Ninety"}};
        vector<string> v {"", "Thousand", "Million", "Billion"};
        vector<int> temp;
        while(num){
            temp.push_back(num % 10);
            num /= 10;
        }
        while(temp.size() != 12){
            temp.push_back(0);
        }
        string s = "";
        int i = 3, j = temp.size()-1;
        while(j >= 0){
            int n = func(temp, j);
            //cout<<n<<" "<<j<<endl;
            s += helper(n, m, v, i);
            i--;
            j -= 3;
        }
        while(s[s.size()-1] == ' '){
            s.pop_back();
        }
        return s;
    }
};