#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// submit
class Solution
{
public:
    int minimumTimeRequired(vector<int> &jobs, int k)
    {
        long long ret = 0;
        sort(jobs.begin(), jobs.end());
        //solve(1, 1000000000, jobs, k, ret);
        solve(16274131, 16274131, jobs, k, ret);
        return ret;
    }
    void solve(long long left, long long right, vector<int> &jobs, int k, long long &ret)
    {
        if (left > right)
        {
            return;
        }

        long long mid = (left + right) / 2;
        bool find = judge(mid, k, jobs, jobs.size());

        if (find)
        {
            ret = mid;
            solve(left, mid - 1, jobs, k, ret);
        }
        else
        {
            solve(mid + 1, right, jobs, k, ret);
        }
    }
    bool tryWork(long long limit, vector<int> &jobs, int idx,)
    bool judge(long long target, int k, vector<int> jobs, int size)
    {
        if (k == 0)
        {
            return false;
        }

        bool find = false;
        long long now = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            if (jobs[i] != 0)
            {
                //   cout << "now: " << now << " now + jobs[i]:" << now + jobs[i] << " judge: " << (now + jobs[i] <= target) << endl;
                if (now + jobs[i] <= target)
                {
                    now = now + jobs[i];
                    jobs[i] = 0;
                }
            }
            if (jobs[i] != 0)
            {
                find = true;
            }
        }
        if (!find)
        {
            return true;
        }

        cout << "k:" << k << " now:" << now << " " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << jobs[i] << " ";
        }
        cout << endl;
        return judge(target, k - 1, jobs, size);
    }
};

// for test
int main()
{
    Solution s;

    /*
    vector<int> i{3, 2, 3};
    cout << s.minimumTimeRequired(i, 3) << endl;
    vector<int> j{1, 2, 4, 7, 8};
    cout << s.minimumTimeRequired(j, 2) << endl;

    vector<int> l{1, 3, 5, 1000};
    cout << s.minimumTimeRequired(l, 4) << endl;
    vector<int> m{9899456, 8291115, 9477657, 9288480, 5146275, 7697968, 8573153, 3582365, 3758448, 9881935, 2420271, 4542202};
    cout << s.minimumTimeRequired(m, 9) << endl;
    vector<int> a{1867731, 4771762, 2710043, 7567506, 5011359};
    cout << s.minimumTimeRequired(a, 2) << endl;
*/
    vector<int> test{6518448, 8819833, 7991995, 7454298, 2087579, 380625, 4031400, 2905811, 4901241, 8480231, 7750692, 3544254};
    cout << s.minimumTimeRequired(test, 4) << endl;
    return 0;
}
