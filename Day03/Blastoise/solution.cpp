class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1]==9)
        {
            answer(digits,digits.size());
        }
        else{
            digits[digits.size()-1]++;
        }
        return digits;
    }
    
    void answer(vector<int>& digits,int n)
    {
        if(n==0)
        {
            digits.insert(digits.begin(),1);
        }
        else if(digits[n-1]==9)
        {
            digits[n-1] = 0;
            answer(digits,n-1);
            
        }
        else{
            digits[n-1]++;
        }
    }
    
};
