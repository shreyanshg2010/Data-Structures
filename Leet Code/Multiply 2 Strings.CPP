class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        
        vector<int> prod(n1+n2,0);
        int i = n1-1;
        while(i >= 0) {
            int j = n2-1;
            int carry = 0;
            while(j >= 0) {
                int mul = prod[i+j+1] + carry + (num1[i]-'0') * (num2[j]-'0');
                prod[i+j+1] = mul%10;
                carry = mul/10;
                j--;
            }
            if (carry > 0) {
                prod[i] = carry;
            }
            i--;
        }
        
        string res = "";
        for (int i = 0; i < n1+n2; ++i) {
            res.append(1,prod[i]+'0');
        }
        
        size_t first_non_zero = res.find_first_not_of('0');
        if (first_non_zero != string::npos) {
            return string(res, first_non_zero);
        } else {
            return "0";
        }
    }
};
