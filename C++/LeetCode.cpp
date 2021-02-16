#include "LeetCode.h"

using namespace std;
using namespace LeetCode;

int main()
{
    Solution106 s106;
    Solution110 s;

    vector<int> t;
    t.push_back(5);

    s106.buildTree(t, t);

    cout << s.isBalanced(NULL) << endl;

    return 0;
}