#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <queue>
#include <utility>
using namespace std;
/* #define DEBUG */
class TopVotedCandidate
{
public:
    vector<pair<int, int>> winner;
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        int lastWinPerson = -1;
        int lastWinVoteNum = -1;
        int voters[persons.size()];
        memset(voters, 0, sizeof(voters));
        for (int i = 0; i < times.size(); i++)
        {
            int vote = persons[i];
            int time = times[i];
            voters[vote]++;
            if (voters[vote] >= lastWinVoteNum)
            {
                if (vote != lastWinPerson)
                {
                    winner.push_back(pair<int, int>(time, vote));
                    lastWinPerson = vote;
                }
                lastWinVoteNum = voters[vote];
            }
        }
#ifdef DEBUG
        for (int i = 0; i < winner.size(); i++)
        {
            cout << winner[i].first << " " << winner[i].second << endl;
        }
#endif
    }

    int find(int left, int right, int target)
    {
        if (left > right)
        {
            return -1;
        }

        int mid = (left + right) / 2;
        auto win = winner[mid];
#ifdef DEBUG
        cout << "mid: " << mid << " time: " << win.first << " winner: " << win.second << endl;
#endif
        if (win.first < target)
        {
            int next = find(mid + 1, right, target);
            if (next == -1)
            {
                return win.second;
            }
            return next;
        }
        if (win.first == target)
        {
            return win.second;
        }

        return find(left, mid - 1, target);
    }

    int q(int t)
    {
        return find(0, winner.size() - 1, t);
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

// for test
int main()
{
    vector<int> person1{0, 1, 1, 0, 0, 1, 0};
    vector<int> time1{0, 5, 10, 15, 20, 25, 30};
    TopVotedCandidate s(person1, time1);

    cout << s.q(3) << endl;
    cout << s.q(12) << endl;
    cout << s.q(25) << endl;
    cout << s.q(15) << endl;
    cout << s.q(24) << endl;
    cout << s.q(8) << endl;
    return 0;
}