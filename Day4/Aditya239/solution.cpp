class Solution {
public:
    string add(string num1, string num2) {
        string answer = string();
        int carry = 0;
        if(num1.size() > num2.size())
            num2 = string(num1.size() - num2.size(), '0') + num2;
        else if(num2.size() > num1.size())
            num1 = string(num2.size() - num1.size(), '0') + num1;
        for(int pos=num1.size()-1; pos>=0; pos--){
            int sumhere = (int)(num1[pos]) - 48  +  (int)(num2[pos]) - 48 + carry;
            answer = to_string(sumhere%10) + answer;
            carry = sumhere/10;
        }
        if(carry > 0)
            answer = to_string(carry) + answer;
        return answer;
    }
    string multdigitaddzero(string num1, int digit, int numzeros) {
        int carry = 0;
        string answer = string();
        if(numzeros > 0)
            answer = string(numzeros, '0') + answer;
        for(int pos=num1.size()-1; pos>=0; pos--){
            int prodhere = ((int)(num1[pos]) - 48)*digit + carry;
            answer = to_string(prodhere%10) + answer;
            carry = prodhere/10;
        }
        if(carry > 0)
            answer = to_string(carry) + answer;
        return answer;
    }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        int numzeros = 0;
        string answer = string();
        for(int pos=num1.size()-1; pos>=0; pos--){
            answer = add(answer, multdigitaddzero(num2, ((int)(num1[pos]) - 48), numzeros++));
        }
        return answer;
    }
};
