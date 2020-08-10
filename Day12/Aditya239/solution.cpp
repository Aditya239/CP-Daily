#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int numints, K;
    cin>>numints>>K;
    vector<pair<int, int>> intervals;
    vector<pair<int, int>> answer;
    while(numints-->0){
        int befh, befm, afth, aftm;
        cin>>befh>>befm>>afth>>aftm;
        intervals.push_back(pair<int, int>(befh*60+befm, afth*60+aftm));
    }
    sort(intervals.begin(), intervals.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right)\
         {return left.first < right.first;});
    int free_since = 0;
    for(size_t j=0; j < intervals.size(); j++){
        if(intervals[j].first - free_since >= K)
            printf("%02d %02d %02d %02d\n", free_since/60, free_since%60, intervals[j].first/60, intervals[j].first%60);
        free_since = max(free_since, intervals[j].second);
    }
    if(1440 - free_since >= K)
        printf("%02d %02d 00 00\n", free_since/60, free_since%60);
    return 0;
}
