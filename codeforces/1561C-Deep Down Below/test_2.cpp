#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define DEBUG
inline signed read()
{
    int s = 0, t = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = (s << 1) + (s << 3) + (ch ^ 48);
        ch = getchar();
    }
    return s * t;
}
struct node
{
    ll num, max;
} monster[100001];
bool cmp(node x, node y)
{
    if (x.max == y.max)
        return x.num < y.num;
    return x.max < y.max;
}
int main()
{
    ll t = read(), n, now, min;
    while (t--)
    {
        bool pd = 1;
        n = read();
        for (ll i = 1; i <= n; i++)
        {
            monster[i].num = read();
            now = read();
            monster[i].max = now + 1;
            for (int j = 2; j <= monster[i].num; j++)
            {
                now = read();
                if (now - j + 1 >= monster[i].max)
                    monster[i].max = now - j + 2;
            }
#ifdef DEBUG
            printf("i: %d max: %d\n", i, monster[i].max);
#endif
        }
        sort(monster + 1, monster + 1 + n, cmp);
        min = monster[n].max;
        for (ll i = n - 1; i >= 1; i--)
        {
            if (monster[i].max + monster[i].num > min && pd == 1)
            {
                min = monster[i].max;
            }
            else
            {
                min = max(min - monster[i].num, monster[i].max);
                pd = 0;
            }
#ifdef DEBUG
            printf("i: %d min: %d \n", i, min);
#endif
        }
        cout << min << endl;
    }
    return 0;
}