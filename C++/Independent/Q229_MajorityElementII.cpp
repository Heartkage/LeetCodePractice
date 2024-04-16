#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0, b = 0;
        int aCount = 0, bCount = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == a)
                aCount++;
            else if(nums[i] == b)
                bCount++;
            else if(aCount == 0){
                a = nums[i];
                aCount = 1;
            }
            else if(bCount == 0){
                b = nums[i];
                bCount = 1;
            }
            else{
                aCount--;
                bCount--;
            }
        }

        aCount = count(nums.begin(), nums.end(), a);
        if(a != b)
            bCount = count(nums.begin(), nums.end(), b);
        nums.clear();
        if(aCount > (n / 3))
            nums.push_back(a);
        if(bCount > (n / 3))
            nums.push_back(b);
        return nums;
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    Solution s;
    auto ans = s.majorityElement(nums);
    for(auto i : ans){
        cout << i << endl;
    }
    return 0;
}