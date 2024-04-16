#include<iostream>
#include<vector>
using namespace std;

class SummaryRanges {
    vector<bool> check;
    vector<vector<int> > ans;

    int findNumIndexInSortedVector(int target, int left, int right){
        if(left > right)
            return -1;
        int mid = (left + right) / 2;
        if(target >= ans[mid][0] && target <= ans[mid][1])
            return mid;
        else if(target < ans[mid][0])
            return findNumIndexInSortedVector(target, left, mid - 1);
        else
            return findNumIndexInSortedVector(target, mid + 1, right);
    }

    int findInsertIndexInSortedVector(int target, int left, int right){
        int mid = (left + right) / 2;
        int n = ans.size();
        if(mid < n && target >= ans[mid][0] && target <= ans[mid][1])
            return -1;
        else if(right-left < 2){
            if(left < n && target < ans[left][0])
                return left;
            else if(right < n && target > ans[right][1])
                return right + 1;
            else
                return right;
        }
        else if(target < ans[mid][0])
            return findInsertIndexInSortedVector(target, left, mid - 1);
        else
            return findInsertIndexInSortedVector(target, mid + 1, right);
    }
public:
    SummaryRanges() {
        check = vector<bool>(10003, false);
        ans.clear();
    }
    
    void addNum(int value) {
        int shiftIndex = value + 1;
        int n = ans.size();
        if(check[shiftIndex])
            return;
        else if(check[shiftIndex-1] && check[shiftIndex+1]){
            int updateIndex = findNumIndexInSortedVector(shiftIndex-2, 0, n);
            int removeIndex = findNumIndexInSortedVector(shiftIndex, 0, n);
            ans[updateIndex][1] = ans[removeIndex][1];
            ans.erase(ans.begin()+removeIndex);
        }
        else if(check[shiftIndex-1]){
            int updateIndex = findNumIndexInSortedVector(shiftIndex-2, 0, n);
            ans[updateIndex][1] = value;
        }
        else if(check[shiftIndex+1]){
            int updateIndex = findNumIndexInSortedVector(shiftIndex, 0, n);
            ans[updateIndex][0] = value;
        }
        else{
            int insertIndex = findInsertIndexInSortedVector(value, 0, n);
            ans.insert(ans.begin() + insertIndex, vector<int>(2, value));
        }
        check[shiftIndex] = true;
    }

    vector<vector<int> > getIntervals() {
        return ans;
    }
};

int main(void){
    SummaryRanges s;

    return 0;
}