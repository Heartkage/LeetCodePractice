#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0;
        int index2 = 0;
        int n = nums1.size();
        int m = nums2.size();
        int maxSize = max(n, m);
        while(index1 < n && index2 < m){
            if(nums1[index1] < nums2[index2])
                index1++;
            else if(nums1[index1] > nums2[index2])
                index2++;
            else
                return nums1[index1];
        }

        if(index1 == n){
            index1 -= 1;
            while(index2 < maxSize){
                if(nums1[index1] == nums2[index2])
                    return nums1[index1];
                index2++;
            }
        }
        else{
            index2 -= 1;
            while(index1 < maxSize){
                if(nums1[index1] == nums2[index2])
                    return nums1[index1];
                index1++;
            }
        }
        return -1;
    }
};

int main(void){
    vector<int> input1;
    input1.push_back(1);
    input1.push_back(2);
    input1.push_back(4);

    vector<int> input2;
    input2.push_back(3);
    input2.push_back(5);
    Solution s;
    cout << s.getCommon(input1, input2) << endl;
    return 0;
}