class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1[0] == '0' || num2[0] == '0')
        {
            return "0";
        }
        
        vector<int> answer(num1.size()+num2.size(),0);
        int carry;
        int place = 0;
        int product =0;
        
        for(int i = num2.size()-1;i>=0;i--)
        {   carry = 0;
            for(int j = num1.size()-1;j>=0;j--)
            {
                product = (num2[i]-'0')*(num1[j]-'0');
                product+=carry;
                carry = (answer[place+num1.size()-1-j]+product)/10;
                answer[place+num1.size()-1-j] = (answer[place+num1.size()-1-j]+product)%10;
                
                
            }
             while(carry!=0)
             {
                answer[num1.size()+place] = (carry%10);
                carry/=10;
             }
          place++;
        }
        
        
        int i=0;
        string ans;
        for(i = answer.size()-1;i>=0;i--)
        {
            if(answer[i]!=0)
            {
                break;
            }
        }
        for(int j = i;j>=0;j--)
        {
            ans+='0'+answer[j];
        }
        return ans;
    }
};