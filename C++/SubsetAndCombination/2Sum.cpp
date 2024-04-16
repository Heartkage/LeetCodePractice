#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> hashmap;
        vector<int> answer;
        for(int i = 0; i < numbers.size(); i++)
        {
            if(hashmap.count(numbers[i]) != 0)
            {
                answer.push_back(hashmap[numbers[i]]);
                answer.push_back(i + 1);
                break;
            }
            else
                hashmap.insert(pair<int, int>(target - numbers[i], i + 1));
        }
        return answer;
    }
};

int main(void)
{
    Solution s;

    vector<int> list{2,3,4};

    vector<int> answer = s.twoSum(list, 6);
    cout << "Answer is: "  << answer[0] << ", " << answer[1] << endl; 

    return 0;
}