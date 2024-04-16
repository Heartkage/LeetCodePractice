#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long numeratorL = numerator;
        long long denominatorL = denominator;
        int negativeCounter = 0;

        if(numeratorL < 0)
        {
            numeratorL *= -1;
            negativeCounter++;
        }
        if(denominatorL < 0)
        {
            denominatorL *= -1;
            if(numeratorL != 0)
                negativeCounter++;
        }

        long long front = numeratorL / denominatorL;
        map<long long, int> usedNumerator;
        string answer = "";
        int index = 0;
        while(numeratorL = numeratorL % denominatorL)
        {
            numeratorL *= 10;
            if(usedNumerator.count(numeratorL))
                break;
            usedNumerator.insert(pair<long long, int>(numeratorL, index));    
            answer.append(1u, (numeratorL / denominatorL) + 48);
            index++;
        }

        if(numeratorL > 0)
        {
            answer.insert(answer.begin()+usedNumerator[numeratorL], '(');
            answer.insert(answer.end(), ')');
        }
        if(answer.length() > 0)
            answer.insert(answer.begin(), '.');
        
        char buffer[25];
        int n = sprintf(buffer, "%lld", front);
        for(int i = n-1; i >= 0; i--)
            answer.insert(answer.begin(), buffer[i]);

        if(negativeCounter == 1)
            answer.insert(answer.begin(), '-');

        return answer;
    }
};

int main(void)
{
    Solution s;

    cout << s.fractionToDecimal(-1, -2147483648) << endl;

    return 0;
}