#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin>>t;
    while(t-- > 0){
        cin>>n;
        multiset<int> s;
        int elem;
        int suma = 0;
        while(n-- > 0){
            cin >> elem;
            s.insert(elem);
            auto it = s.upper_bound(elem); 
            int ans = distance(s.begin(), it) - 1;
            suma += ans;
        }
        cout<<suma<<endl;
    }
}
