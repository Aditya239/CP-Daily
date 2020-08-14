#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	int n;
	long long int answer;
	while (t--)
	{
		cin >> n;
		int arr[n];
		answer = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (arr[j] <= arr[i])
				{
					answer++;
				}
			}
		}
		cout << answer << endl;
	}


	return 0;
}

