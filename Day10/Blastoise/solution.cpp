class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
        {
            return tasks.size();
        }

        int arr[26] = {0};

        for (int i = 0; i < tasks.size(); i++)
        {
            arr[tasks[i] - 'A']++;
        }
        sort(arr, arr + 26);
        int maxi = arr[25];
        int spaceBetween = (maxi - 1) * n;
        int idle = spaceBetween;
        int total = 0;
        for (int i = 0; i < 25; i++)
        {
            if (maxi == arr[i])
            {
                total++;
                idle -= maxi - 1;
            }
            else {
                idle -= arr[i];
            }
        }
        if (idle <= 0)
        {
            return tasks.size();
        }

        return total + spaceBetween + maxi;

    }
};