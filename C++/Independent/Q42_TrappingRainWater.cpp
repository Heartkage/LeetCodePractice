#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n, 0), rmax(n, 0);
        
        lmax[0] = height[0];
        for(int i=1; i < n; i++) {
            lmax[i] = max(lmax[i-1], height[i]);
        }

        rmax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--) {
            rmax[i] = max(rmax[i+1], height[i]);
        }

        int totalHeight = 0;
        for(int i=1; i<n-1; i++) {
            totalHeight += min(lmax[i], rmax[i]) - height[i];
        }

        return totalHeight;
        

    }
};

int main(void) {
    vector<int> height;
    height.push_back(4);
    height.push_back(2);
    height.push_back(0);
    height.push_back(3);
    height.push_back(2);
    height.push_back(5);

    Solution s;
    cout << "ans: " << s.trap(height) << endl;
    
    return 0;
}