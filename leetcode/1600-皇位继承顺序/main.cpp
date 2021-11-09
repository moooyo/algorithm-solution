#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#define _DEBUG
using namespace std;
class Node
{
public:
    string name;
    bool alive;
    vector<Node *> son;
    Node(string name)
    {
        this->name = name;
        this->alive = true;
    }
};
class ThroneInheritance
{
public:
    Node *root;
    map<string, Node *> nodeMap;

    ThroneInheritance(string kingName)
    {
        root = new Node(kingName);
        nodeMap[kingName] = root;
    }

    void birth(string parentName, string childName)
    {
        Node *now = nodeMap[parentName];
        Node *son = new Node(childName);
        now->son.push_back(son);
        nodeMap[childName] = son;
    }

    void death(string name)
    {
        Node *now = nodeMap[name];
        now->alive = false;
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> ret;
        solve(root, ret);
        return ret;
    }

    void solve(Node *now, vector<string> &ret)
    {
        if (now == nullptr)
        {
            return;
        }

        if ( now->alive)
        {
            ret.push_back(now->name);
        }
        for (int i = 0; i < now->son.size(); i++)
        {
            solve(now->son[i], ret);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance obj = new ThroneInheritance(kingName);
 * obj.birth(parentName,childName);
 * obj.death(name);
 * List<String> param_3 = obj.getInheritanceOrder();
 */

// for test
int main()
{
    Solution s;

    return 0;
}