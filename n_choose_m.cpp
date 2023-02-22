// implemented in dfs

int num[300005] = {0};
int n;  // length of list

/// @brief 
/// @param cur : cureent pointer
/// @param chosen : length of cureent choosen number
/// @param cho : number have been choosen
/// @param m : length of m
void n_choose_m(int cur, int chosen, int cho[300005], int m)
{
    if (chosen >= m)
    {
        // judge(cho);
        return;
    }
    else if (cur >= n)
    {
        return;
    }

    for (int i = cur; i < n; ++i)
    {
        cho[chosen] = num[i];
        n_choose_m(i + 1, chosen + 1, cho, m);
    }
}