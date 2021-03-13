#include "LeetCode.h"

using namespace std;
using namespace LeetCode;

int Solution42::trap(vector<int>& height) {
    int totalArea = 0;
    int highestIndex = -1;
    int biggest = -1;

    for(int i = 0; i < height.size(); i++)
    {
        if(height[i] >= biggest)
        {
            biggest = height[i];
            highestIndex = i;
        }
    }

    if(highestIndex >= 0)
    {
        stack<pair<int, int>> previousHeight;
        for(int i = 0; i <= highestIndex; i++)
        {
            if(!previousHeight.empty())
            {
                pair<int, int> peek = previousHeight.top();

                if(peek.first <= height[i])
                {
                    totalArea += ((i-1) - peek.second) * peek.first;
                    previousHeight.pop();
                }
                else
                {
                    totalArea -= height[i];
                    continue;
                }
            }

            if((i + 1) < highestIndex)
                previousHeight.push(pair<int, int>(height[i], i)); 
        }

        for(int i = height.size()-1; i >= highestIndex; i--)
        {
            if(!previousHeight.empty())
            {
                pair<int, int> peek = previousHeight.top();

                if(peek.first <= height[i])
                {
                    totalArea += (peek.second - (i+1)) * peek.first;
                    previousHeight.pop();
                }
                else
                {
                    totalArea -= height[i];
                    continue;
                }
            }

            if((i - 1) > highestIndex)
                previousHeight.push(pair<int, int>(height[i], i)); 
        }
    }

    return totalArea;
}

void Solution42::test()
{
    SupportBase::test();

    vector<int> height = {0,0,30,0,30,0,0};
    int answer = trap(height);
    cout << "The area is: " << answer << endl;
    SupportBase::endTest();
}