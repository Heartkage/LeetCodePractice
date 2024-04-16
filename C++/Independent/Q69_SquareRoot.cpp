#include<iostream>
#include<climits>
#include<sstream>

using namespace std;

class Solution {
    int answer;

    void RecursiveSearch(int left, int right, int target)
    {
        if(left > right)
            return;

        int mid = (left + right) / 2;
        if(mid*mid > target)
        {
            RecursiveSearch(left, mid-1, target);
        }
        else
        {
            answer = mid;
            RecursiveSearch(mid+1, right, target);
        }
    }
public:
    int mySqrt(int x) {
        RecursiveSearch(1, 46340, x);
        return answer;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    stringstream ss;
    ss << argv[1];
    int x;
    ss >> x;
    cout << s.mySqrt(x) << endl;

    return 0;
}