class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int color = 0;
        int open = -1;
        vector<int> ans(seq.length(), 0);
        for(int j=0; j<seq.length(); j++){
            if(seq[j]=='('){
                open += 1;
                ans[j] = open%2;
            }
            else{
                ans[j] = open%2;
                open -= 1;
            }
        }
        return ans;
    }
};
