#include <bits/stdc++.h>

using namespace std;

// Complete the substrings function below.
int substrings(string n) {
    long long int sum = 0;
    long long int prev = 0;
    long int modulo = 1000000007;
    for (int i = 0; i < n.size(); i++)
    {
        prev = ((prev * 10) % modulo + ((i + 1) * (n[i] - '0')) % modulo) % modulo;
        sum = (sum + prev) % modulo;
    }
    return sum;
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
