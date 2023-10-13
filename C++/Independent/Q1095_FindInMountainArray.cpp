#include<iostream>
#include<vector>
#include<map>
using namespace std;


// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
    vector<int> myArr;
    public:
    MountainArray(){
        myArr.clear();
        myArr.push_back(3);
        myArr.push_back(5);
        myArr.push_back(3);
        myArr.push_back(2);
        myArr.push_back(0);
    }
    int get(int index){
        return myArr[index];
    }
    int length(){
        return myArr.size();
    }
};

class Solution {
    map<int, int> table;
    int min, max;
    int getValue(int index, MountainArray &ma){
        if(table.find(index) == table.end())
            table[index] = ma.get(index);
        return table[index];
    }

    bool inRange(int index){
        if(index > max)
            return false;
        else if(index < min)
            return false;
        else
            return true;
    }

    int recursiveSearch(MountainArray &ma, int t, int left, int right){
        if(left > right)
            return -1;

        int mid = (left+right) / 2;
        if(inRange(mid) == false)
            return -1;
        else if(left == right){
            if(getValue(mid, ma) == t)
                return mid;
            else
                return -1;
        }
        else{
            int ans = -1;
            if(getValue(mid, ma) >= getValue(left, ma)){
                if(getValue(mid-1, ma) < getValue(mid, ma)){
                    if(left > min && t < getValue(left, ma))
                        min = left;
                    else if(t >= getValue(left, ma) && t < getValue(mid, ma))
                        ans = recursiveSearch(ma, t, left, mid - 1);
                }
                else{
                    if(mid < max && t > getValue(mid, ma))
                        max = mid;
                    ans = recursiveSearch(ma, t, left, mid -1);
                }
            }
            else if(left != right){
                if(getValue(left, ma) > getValue(left+1, ma)){
                    if(mid < max && t > getValue(mid, ma))
                        max = mid;
                    else if(t <= getValue(left, ma) && t > getValue(mid, ma))
                        ans = recursiveSearch(ma, t, left, mid - 1);
                }
                else{
                    if(mid < max && t > getValue(mid, ma))
                        max = mid;
                    ans = recursiveSearch(ma, t, left, mid -1);
                }
            }

            if(ans == -1){
                if(getValue(mid, ma) == t)
                    ans = mid;
            }

            if(ans == -1){
                if(getValue(mid, ma) >= getValue(right, ma)){
                    if(getValue(mid+1, ma) < getValue(mid, ma)){
                        if(right < max && t < getValue(right, ma))
                            max = right;
                        else if(t < getValue(mid, ma) && t >= getValue(right, ma))
                            ans = recursiveSearch(ma, t, mid + 1, right);
                    }
                    else{
                        if(mid > min && t > getValue(mid, ma))
                            min = mid;
                        ans = recursiveSearch(ma, t, mid + 1, right);
                    }
                }
                else if(left != right){
                    ans = recursiveSearch(ma, t, mid + 1, right);
                }
            }

            return ans;
        }
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        min = 0;
        max = mountainArr.length()-1;
        return recursiveSearch(mountainArr, target, min, max);
    }
};

int main(void){
    MountainArray ma;
    Solution s;
    cout << s.findInMountainArray(3, ma) << endl;
    return 0;
}