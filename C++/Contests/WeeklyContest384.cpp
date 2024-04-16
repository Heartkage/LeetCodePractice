#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
using namespace std;

bool comparator(pair<int, bool> a, pair<int, bool> b){
    if (a.first != b.first) {
        return a.first < b.first; 
    } 
    else {
        return !a.second && b.second;
    }
}

class Solution{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> maximum(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[j][i] > maximum[i])
                    maximum[i] = matrix[j][i];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] < 0)
                    matrix[i][j] = maximum[j];
            }
        }
        return matrix;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        int count = 0;
        for(int i = 0; i < n; i++){
            int lastNum = nums[i];
            if((i + m) >= n)
                break;

            bool failed = false;
            for(int j = 0; j < m; j++){
                int currentNum = nums[i+j+1]; 
                if(pattern[j] == 1){
                    if(currentNum <= lastNum){
                        failed = true;
                        break;
                    }
                }
                else if(pattern[j] == 0){
                    if(currentNum != lastNum){
                        failed = true;
                        break;
                    }
                }
                else{
                    if(currentNum >= lastNum){
                        failed = true;
                        break;
                    }
                }
                lastNum = currentNum;
            }

            if(failed == false)
                count++;
        }
        return count;
    }

    int maxPalindromesAfterOperations(vector<string>& words) {
        int n = words.size();
        vector<pair<int, bool>> pairsNeed(n);
        vector<int> table(26, 0);

        for(int i = 0; i < n; i++){
            pairsNeed[i] = make_pair(words[i].length()/2, words[i].length() & 1);
            for(int j = 0; j < words[i].length(); j++){
                table[words[i][j]-'a']++;
            }
        }

        sort(pairsNeed.begin(), pairsNeed.end(), comparator);
        // for(int i = 0; i < n; i++)
        //     cout << pairsNeed[i].first << ", " << pairsNeed[i].second << endl;

        int single = 0;
        int totalPairs = 0;
        for(int i = 0; i < 26; i++){
            if(table[i] & 1)
                single++;
            totalPairs += (table[i] / 2);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(totalPairs < pairsNeed[i].first)
                break;

            if(pairsNeed[i].second == false){
                totalPairs -= pairsNeed[i].first;
                ans++;
            }
            else{
                if(single < 1){
                    totalPairs--;
                    single += 2;
                }

                if(totalPairs >= pairsNeed[i].first){
                    totalPairs -= pairsNeed[i].first;
                    single--;
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<int> pat;
    pat.push_back(1);
    // pat.push_back(1);

    vector<string> words;
    words.push_back("abbbc");
    words.push_back("ab");

    Solution s;
    cout << s.maxPalindromesAfterOperations(words) << endl;
    return 0;
}