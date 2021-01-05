#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:

public:
    // Q119
    vector<int> getRow(int rowIndex) {
        vector<int> answer;

        answer.push_back(1);

        while(rowIndex--)
        {
            answer.push_back(1);
            int leftValue = 1;
            int rightValue;
            for(int i = 1; i < answer.size()-1; i++)
            {
                rightValue = answer[i];
                answer[i] = leftValue + answer[i];
                leftValue = rightValue;
            }
        }

        return answer;
    }
};

// 125. Valid Palindrome
class Solution125 {
private:
    bool IsAlphabetNumeric(char _s)
    {
        if((_s >= 48 && _s <= 57) || (_s >= 65 && _s <= 90) || (_s >= 97 && _s <= 122))
            return true;
        else
            return false;
    }
    bool IsSameChar(char _first, char _second)
    {
        if(_first >= 65 && _first <= 90)
            _first += 32;
        if(_second >= 65 && _second <= 90)
            _second += 32;
        return _first == _second;
    }
public:
    bool isPalindrome(string s) {
        int frontIndex = 0;
        int backIndex = s.size()-1;

        while(frontIndex <= backIndex)
        {
            while((frontIndex <= backIndex) && !IsAlphabetNumeric(s[frontIndex])) frontIndex++;
            while((frontIndex <= backIndex) && !IsAlphabetNumeric(s[backIndex])) backIndex--;

            if(frontIndex <= backIndex)
            {
                if(!IsSameChar(s[frontIndex++], s[backIndex--]))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution125 s;

    s.isPalindrome("A man, a plan, a canal: Panama");

    return 0;
}