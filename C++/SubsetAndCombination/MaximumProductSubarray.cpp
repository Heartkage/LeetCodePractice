#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> products;
        
        int minimum = 1;
        int maximum = 1;
        int largest = -2147483648;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0)
                swap(minimum, maximum);
            minimum = min(minimum * nums[i], nums[i]);
            maximum = max(maximum * nums[i], nums[i]);
            //cout << "Max: " << maximum << ", Min: " << minimum << endl;
            largest = max(largest, maximum);
        }

        return largest;
    }
};

int main(void)
{
    Solution s;

    vector<int> list{2,3,0,4,-1};

    cout << s.maxProduct(list) << endl;
    return 0;
}