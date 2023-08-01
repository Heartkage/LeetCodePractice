#include<iostream>
#include<cmath>
using namespace std;

class Test {
public:
    long Recursion(int n){
        if(n == 1 || n == 2)
            return 4;
        return 3 * Recursion(n - 2) - 2;
    }

    long Pow(int a, int power){
        long ans = 1;
        for(int i = 0; i < power; i++)
            ans *= a;
        return ans;
    }
};

int main(void){
    Test t;
    cout << t.Recursion(50) << endl;
    cout << t.Pow(3, 25) + 1 << endl;
    return 0;
}