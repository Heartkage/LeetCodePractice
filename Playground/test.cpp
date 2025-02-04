#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int floyd(vector<int> &nums) {
    int tortoise = nums[0];
    int hare = nums[nums[0]];
    while(tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    }

    hare = 0;

    while(tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    return nums[tortoise];
}

int main(void){
    // int a = 0;
    // cout << "a: " << a << endl;
    // cout << "a position: " << &a << endl;
    // int b[10];
    // b[0] = 1;
    // b[2] = 10;
    // int* c = b;
    // (*c) = 5;

    // cout << "b[0]: " << b[0] << endl;
    // cout << "b   : " << b << endl;
    // cout << "b+1 : " << b+1 << endl;
    // cout << "b+2 : " << b+2 << endl;
    // cout << "b+3 : " << b+3 << endl;
    
    // cout << "b[0]: " << (*(b)) << endl;
    // cout << "b[2]: " << (*(b+2)) << endl;

    // cout << "c: " << *c << endl;
    
    vector<int> input = {1,2,3,5,4,5};
    cout << "ans: " << floyd(input) << endl;

    return 0;
}