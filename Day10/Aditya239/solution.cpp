class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> numleft;
        vector<int> index(26, -1);
        for(vector<char>::iterator it=tasks.begin();it!=tasks.end();++it){
            int currindex = index[int(*it)-65];
            if(currindex==-1){
                index[int(*it)-65] = numleft.size();
                numleft.push_back(1);
            }
            else
                numleft[currindex]++;
        }
        int allsum = accumulate(numleft.begin(), numleft.end(), 0);
        if(n==0)
            return allsum;
        sort(numleft.rbegin(), numleft.rend());
        int endidx = n + 1;
        while(numleft.size() > 0){
            endidx = min(n+1, int(numleft.size()));
            allsum += (n+1 - endidx);
            transform(numleft.begin(), numleft.begin() + endidx, numleft.begin(), \
                      bind2nd(minus<int>(), 1));   
            sort(numleft.rbegin(), numleft.rend());
            auto rit = find_if(numleft.rbegin(), numleft.rend(), [](int v) {return v != 0;});
            numleft.erase(rit.base(), end(numleft));
        }
        allsum = allsum - (n+1 - endidx);
        return allsum;
    }
};
