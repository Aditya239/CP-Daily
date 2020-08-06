class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>v(num + 1, 0);
        if (num == 0)
        {
            return v;
        }
        v[1] = 1;
        if (num == 1)
        {
            return v;
        }

        int start = 2;
        int endIndex = log2(num);


        for (int i = 1; i <= endIndex; i++)
        {
            v[start] = 1;
            start *= 2;
        }

        start = 2;

        for (int i = 3; i <= num; i++)
        {
            v[i] = 1 + v[i - start];
            if (i == num)
            {
                break;
            }
            if (v[i + 1] == 1)
            {
                start *= 2;
            }
        }
        return v;
    }
};