#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        int n = nums.size();
        for(int i = 0; i < n;) {
            for(int j = i+1; j < n;) {
                int k = j+1;
                int l = n-1;

                while(k < l) {
                    long long value = nums[i];
                    value += nums[j];
                    value += nums[k];
                    value += nums[l];

                    if(value == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                        int oldKValue = nums[k];
                        do{
                            k++;
                        }while(k < l && nums[k] == oldKValue);
                    } else if(value > target) {
                        l--;
                    } else {
                        k++;
                    }
                }

                int jOldValue = nums[j];
                do{
                    j++;
                }while(j < n && nums[j] == jOldValue);
            }

            int iOldValue = nums[i];
            do {
                i++;
            }while(i < n && nums[i] == iOldValue);
        }

        return ans;
    }
};

int main(void){
    vector<int> input = {1,0,-1,0,-2,2};

    Solution s;
    auto ans = s.fourSum(input, -1);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}