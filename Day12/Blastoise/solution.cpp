#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& v)
{
    vector<vector<int>>a;
    vector<int> compare = v[0];
    vector<int> temp = v[0];
    int maxi;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i][0] >= compare[0] && v[i][0] <= compare[1])
        {
            maxi = (compare[1] > v[i][1]) ? compare[1] : v[i][1];
            temp = {compare[0], maxi};
            compare = temp;
        }
        else {
            a.push_back(temp);
            compare = v[i];
            temp = v[i];
        }
    }
    a.push_back(temp);
    return a;
}

void print(int input)
{
    if (input <= 9)
    {
        cout << "0" << input << " ";
    }
    else {
        cout << input << " ";
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, k;
    cin >> m >> k;
    string x, y;
    int z, w;
    int input1, input2;
    vector<vector<int>>v(m);
    for (int i = 0; i < m; i++)
    {
        getline(cin, x, ' ');
        getline(cin, y, ' ');
        z = stoi(x);
        w = stoi(y);
        input1 = z * 60 + w;
        getline(cin, x, ' ');
        getline(cin, y);
        z = stoi(x);
        w = stoi(y);
        input2 = z * 60 + w;
        if (input2 == 0 && input1 != 0)
        {
            input2 = 24 * 60;
        }
        v[i].push_back(input1);
        v[i].push_back(input2);
    }
    sort(v.begin(), v.end(), [](auto & a , auto & b) {return a[0] < b[0];});
    vector<vector<int>>a = merge(v);
    int compare = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i][0] - compare >= k)
        {
            input1 = compare / 60;
            input2 = compare % 60;

            print(input1);
            print(input2);

            input1 = a[i][0] / 60;
            input2 = a[i][0] % 60;

            print(input1);

            if (input2 <= 9)
            {
                cout << "0" << input2 << endl;
            }
            else {
                cout << input2 << endl;
            }

        }
        compare = a[i][1];
    }
    if (24 * 60 - compare >= k)
    {
        input1 = compare / 60;
        input2 = compare % 60;

        print(input1);
        print(input2);

        cout << "00" << " " << "00" << endl;
    }
    return 0;
}
