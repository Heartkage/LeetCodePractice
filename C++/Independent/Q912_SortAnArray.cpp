#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    void QuickSort(vector<int> &nums, int left, int right){
        if((right - left) < 1)
            return;

        int i = left + 1;
        int j = right;
        while(i <= j){
            while((i <= j) && nums[i] <= nums[left]) i++;
            while((i <= j) && nums[j] >= nums[left]) j--;
            if(i <= j)
                swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[j]);
        QuickSort(nums, left, j - 1);
        QuickSort(nums, j + 1, right);
    }
    void PriorityQueueSort(vector<int> &nums){
        priority_queue<int> pq;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            pq.push(nums[i]);
        for(int i = n-1; i > -1; i--){
            nums[i] = pq.top();
            pq.pop();
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        //QuickSort(nums, 0, nums.size() - 1);
        PriorityQueueSort(nums);
        return nums;
    }

    void print(vector<int> &nums){
        for(int i = 0; i < nums.size(); i++)
            cout << nums[i] << " ";
        cout << endl;
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);

    Solution s;
    nums = s.sortArray(nums);
    cout << endl;
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}