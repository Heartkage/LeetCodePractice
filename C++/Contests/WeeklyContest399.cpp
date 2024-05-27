#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<math.h>
using namespace std;

class Solution {
public:

    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0;

        int n = nums1.size();
        int m = nums2.size();

        for(int i = 0; i < m; i++)
            nums2[i] *= k;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(nums1[i] % nums2[j] == 0)
                    ans++;
            }
        }

        return ans;
    }

    string compressedString(string word) {
        int n = word.length();
        string answer = "";
        
        char lastCharacter = word[0];
        int count = 1;
        for(int i = 1; i < n; i++){
            if(word[i] != lastCharacter){
                answer.append(to_string(count));
                answer.push_back(lastCharacter);
                lastCharacter = word[i];
                count = 1;
            }
            else {
                count++;
            }

            if(count > 9) {
                answer.append("9");
                answer.push_back(lastCharacter);
                count = 1;
            }
        }

        answer.append(to_string(count));
        answer.push_back(lastCharacter);

        return answer;
    }

   
};

int main(void){
    cout << "Testing: WeeklyContest-399" << endl;

    vector<int> n1;
    n1.push_back(1);
    n1.push_back(3);
    n1.push_back(4);
    n1.push_back(8);

    vector<int> n2;
    n2.push_back(1);
    n2.push_back(3);
    n2.push_back(4);
    n2.push_back(8);

    Solution s;
    cout << "Question No.1" << endl;
    cout << s.numberOfPairs(n1, n2, 2) << endl;


    cout << "Question No.2" << endl;
    cout << s.compressedString("aaaaaaaaaaaaaabb") << endl;

    return 0;
}