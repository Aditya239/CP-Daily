class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int pos=digits.size()-1; pos>=0; pos--){
            if(digits[pos]<9){
                digits[pos] = digits[pos] + 1;
                return digits;
            }
            else
                digits[pos] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
