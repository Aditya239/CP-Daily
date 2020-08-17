#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, w, u, v, begin, end;
    cin>>n>>w>>u>>v>>begin>>end;
    vector<pair<double, double>> ships;
    double K = 0.0;
    vector<pair<int, int>> answer;
    char dir; int m; int nose; int len;
    double cross = double(w)/double(v);
    for(int j=0; j<n; j++){
        cin>>dir>>m;
        int eastbound = -1;
        if(dir=='E')
            eastbound = 1;
        for(int k=0; k<m; k++){
            cin >> len >> nose;
            double start = double(-eastbound*nose)/double(u) - (j+1)*cross;
            double stop  = double(len - eastbound*nose)/double(u) - j*cross;
            if(start>=double(end))
                continue;
            ships.push_back(pair<double, double>(start, stop));
        }
    }
    sort(ships.begin(), ships.end(), [](const std::pair<double, double> &left, const std::pair<double, double> &right){return left.first < right.first;});
    double free_since = double(begin);
    for(size_t j=0; j < ships.size(); j++){
        if(ships[j].first - free_since > K)
            K = ships[j].first - free_since;
        free_since = max(free_since, ships[j].second);
    }
    if(double(end) - free_since > K)
        K = double(end) - free_since;
    cout << K << endl;
    return 0;
}
