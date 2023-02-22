vector<int> res;

void get_number(long long n, vector<int> &res)
{
    int len = 0;
    while (n)
    {
        res.push_back(n % 10);
        n /= 10;
    }
}