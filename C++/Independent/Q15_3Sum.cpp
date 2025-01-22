#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i < n;) {
            int j = i+1;
            int k = n-1;

            while(j < k) {
                int result = nums[i] + nums[j] + nums[k];
                if(result == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int jValue = nums[j];

                    do{
                        j++;
                    }while(j < k && nums[j] == jValue);
                } else if(result < 0) {
                    j++;
                } else {
                    k--;
                }
            }

            int iValue = nums[i];
            do {
                i++;
            }while(i < n && nums[i] == iValue);
        }

        return ans;
    }
};

int main(void){
    vector<int> input = {-1,0,1,2,-1,-4};

    Solution s;
    auto ans = s.threeSum(input);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}