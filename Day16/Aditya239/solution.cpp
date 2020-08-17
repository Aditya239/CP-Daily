#include <bits/stdc++.h>

using namespace std;

// Complete the substrings function below.
int substrings(string n) {
    long long S = 0; long long pow = 1;
    for(int i=n.length()-1; i>=0; i--){
        int elem = n[i]-'0';
        S = S + elem*pow*((i+1)%1000000007);
        pow = (pow*10+1)%1000000007;
        S = S%1000000007;
    }
    return S;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
