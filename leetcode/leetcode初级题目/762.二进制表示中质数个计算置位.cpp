class Solution
{
  public:
    int countPrimeSetBits(int L, int R)
    {
        int res = 0;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23};
        for (int num = L; num <= R; num++)
        {
            int setbit = countOne(num);
            if (find(primes.begin(), primes.end(), setbit) != primes.end())
            {
                res += 1;
            }
        }
        return res;
    }
    int countOne(int n)
    {
        int res = 0;
        while (n != 0)
        {
            if ((n & 1) == 1)
            {
                res += 1;
            }
            n = (n >> 1);
        }
        return res;
    }
};