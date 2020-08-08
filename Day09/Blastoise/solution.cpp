class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        long long int answer = 0;
        int count = 0;

        if (S == 0)
        {
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i] == 0)
                {
                    count++;
                }
                else {
                    answer = answer + ((count + 1) * count) / 2;
                    count = 0;
                }
            }
            if (count != 0)
            {
                answer = answer + ((count + 1) * count) / 2;
            }
            return answer;
        }



        vector<int> v;
        int prev;
        int addPrefix = 0;

        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == 1)
            {
                v.push_back(A.size() - 1 - i);
                if (count == 0)
                {
                    addPrefix = i;
                }

                else {
                    v[count - 1] =  i - prev - 1;
                }

                count++;
                prev = i;
            }

        }

        if (count < S)
        {
            return 0;
        }
        else {
            for (int i = S - 1; i < v.size(); i++)
            {
                if (i == S - 1)
                {
                    answer = answer + (addPrefix + 1) * (v[i] + 1);
                }
                else {
                    answer = answer + (v[i - S] + 1) * (v[i] + 1);
                }
            }
        }
        return answer;

    }
};