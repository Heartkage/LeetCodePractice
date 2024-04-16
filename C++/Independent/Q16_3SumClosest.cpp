#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int answer = 0;
        int shortest = 100000000;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(target - sum) < shortest){
                    shortest = abs(target - sum);
                    if(shortest == 0)
                        return sum;
                    answer = sum;
                }
                if(sum > target)
                    right--;
                else
                    left++;
            }
        }
        return answer;
    }
};

int main(void){
    vector<int> input;
    input.push_back(-1);
    input.push_back(2);
    input.push_back(1);
    input.push_back(-4);
    Solution s;
    cout << s.threeSumClosest(input, 1) << endl;
    return 0;
}