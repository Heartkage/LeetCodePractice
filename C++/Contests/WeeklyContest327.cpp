#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
using namespace std;

// struct Compare{
//     bool operator()(const int &a, const vector<int> &b){
//         if(a[1] != b[1])
//             return a[1] > b[1];
//         else
//             return a[2] > b[2];
//     }
// };

class Solution1 {
public:
    int maximumCount(vector<int>& nums) {
        int negative = 0;
        int positive = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                negative++;
            }
            else if(nums[i] > 0){
                positive++;
            }
        }
        return max(negative, positive);
    }
};

class Solution2 {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int> > pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }
        long long ans = 0;
        while(k--){
            int highest = pq.top();
            ans += highest;
            pq.pop();
            pq.push(ceil(highest/3.0));
        }
        return ans;
    }
};

class Solution3 {
public:
    bool isItPossible(string word1, string word2) {
        const int MAX = 26;
        int a[MAX];
        int b[MAX];
        memset(a, 0, sizeof(int)*MAX);
        memset(b, 0, sizeof(int)*MAX);
        for(int i = 0; i < word1.size(); i++){
            a[word1[i] - 'a']++;
        }
        for(int i = 0; i < word2.size(); i++){
            b[word2[i] - 'a']++;
        }
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                if((a[i] != 0) && (b[j] != 0))
                {
                    a[j]++;
                    b[j]--;
                    a[i]--;
                    b[i]++;
                    int aCount = 0;
                    int bCount = 0;
                    for(int k = 0; k < MAX; k++){
                        if(a[k] > 0)
                            aCount++;
                    }
                    for(int k = 0; k < MAX; k++){
                        if(b[k] > 0)
                            bCount++;
                    }
                    if(aCount == bCount)
                        return true;

                    a[j]--;
                    b[j]++;
                    a[i]++;
                    b[i]--;
                }
            }
        }
        return false;
    }
};

int main(void){
    // vector<int> input;

    // input.push_back(10);
    // input.push_back(10);
    // input.push_back(10);
    // input.push_back(10);
    // input.push_back(10);
    // Solution2 s;
    // cout << s.maxKelements(input, 50) << endl;

    // = -1
    // aa c <--- x
    // aab cc
    // aac cc
    // aacdd ccdd
    // ccb cc <----- x
    // aabc ab
    // aabc xy <----- x
    // aabcd xxyz
    // zzbc ab
    // zzbbcc ab  <--- X
    // ccddee ccd
    
    // = 0
    // abc xxyyzz  <----x
    // aabc xxyyzz 
    // abc xxyycc

    // = -2
    // aabbccd aab

    Solution3 a;
    cout << a.isItPossible("aa", "c") << endl;
    cout << a.isItPossible("cc", "aab") << endl;
    cout << a.isItPossible("cc", "aac") << endl;
    cout << a.isItPossible("aacdd", "ccdd") << endl;
    cout << a.isItPossible("ccb", "cc") << endl;
    cout << a.isItPossible("aabc", "ab") << endl;
    cout << a.isItPossible("aabc", "xy") << endl;
    cout << a.isItPossible("aabcd", "xyyz") << endl;
    cout << a.isItPossible("zzbc", "ab") << endl;
    cout << a.isItPossible("zzbbcc", "ab") << endl;
    cout << a.isItPossible("ccddee", "ccd") << endl;

    cout << a.isItPossible("abc", "xxyyzz") << endl;
    cout << a.isItPossible("aabc", "xxyyzz") << endl;
    cout << a.isItPossible("abc", "xxyycc") << endl;

    cout << a.isItPossible("aabbccd", "aab") << endl;

    return 0;
}