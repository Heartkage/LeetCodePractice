#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> product_count;

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                product_count[nums[i]*nums[j]]++;
            }
        }

        int totalSet = 0;
        for(const auto& p : product_count) {
            int count = p.second;
            totalSet += count * (count-1) / 2;
        }
        return totalSet * 8;
    }
};

int main(void) {

    vector<int> input = {2, 3, 4, 6, 8, 12};
    Solution s;
    cout << "Ans: " << s.tupleSameProduct(input) << endl;
}

