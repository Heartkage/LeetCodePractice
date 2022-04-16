#include<iostream>
#include<sstream>
#include<string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        
        int s_length = s.length();
        int t_length = t.length();

        int dp[t_length][s_length];
        memset(dp, 0, sizeof(dp));

        // Pre-calculate if there is possible answer, because the question only has INT_MAX answers
        int answer = 0;
        for(int i = 0; i < t_length; i++)
        {
            bool hasValue = false;
            answer = 0;
            for(int j = 0; j < s_length; j++)
            {
                if(i == 0)
                {
                    if(s[j] == t[i])
                    {
                        dp[i][j] = 1;
                        answer += 1;
                    }
                }
                else
                {
                    if(hasValue && s[j] == t[i])
                    {
                        dp[i][j] = 1;

                        if(i == t_length - 1)
                            answer += 1;
                    }

                    if(dp[i-1][j] > 0)
                        hasValue = true;
                }
            }
        }
        if(answer == 0)
            return 0;
        
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < t_length; i++)
        {
            long accumulate = 0;
            answer = 0;
            for(int j = 0; j < s_length; j++)
            {
                if(i == 0)
                {
                    if(s[j] == t[i])
                    {
                        dp[i][j] = 1;
                        answer += 1;
                    }
                }
                else
                {
                    if(s[j] == t[i])
                    {
                        dp[i][j] = accumulate;

                        if(i == t_length - 1)
                            answer += accumulate;
                    }    

                    accumulate += dp[i-1][j];
                }
            }
        }
        return answer;
    }
};

int main(int argc, char *argv[])
{
    stringstream ss;
    string s;
    string t;
    ss << argv[1];
    ss >> s;
    ss.clear();
    ss << argv[2];
    ss >> t;
    cout << "s: " << s << endl;
    cout << "t: " << t << endl;
    Solution sol;
    cout << sol.numDistinct(s, t) << endl;

    return 0;
}