#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
#define _DEBUG

typedef struct Node
{
    struct Node *next[26];
    int val;
    int sum;

    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            next[i] = nullptr;
            this->val = 0;
            this->sum = 0;
        }
    };
} Node;

class MapSum
{
public:
    Node *root;

    MapSum()
    {
        root = new Node();
    }

    void insert(string key, int val)
    {
        Node *now = root;
        for (int i = 0; i < key.length(); i++)
        {
            int keyNum = key[i] - 'a';
            if (now->next[keyNum] == nullptr)
            {
                now->next[keyNum] = new Node();
            }
            now = now->next[keyNum];
        }
        if (now != nullptr)
        {
            if (now->val != val)
            {
                int diff = val - now->val;
                now->val = val;
                Node *newNow = root;
                newNow->sum += diff;
                for (int i = 0; i < key.length(); i++)
                {
                    int keyNum = key[i] - 'a';
                    newNow = newNow->next[keyNum];
                    newNow->sum += diff;
                }
            }
        }
    }

    int sum(string prefix)
    {
        Node *now = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            int keyNum = prefix[i] - 'a';
            if (now->next[keyNum] == nullptr)
            {
                return 0;
            }
            now = now->next[keyNum];
        }

        return now->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

// for test
int main()
{
    MapSum *obj = new MapSum();
    obj->insert("apple", 3);
    cout << obj->sum("ap") << endl;
    obj->insert("app", 2);
    cout << obj->sum("ap") << endl;
    return 0;
}