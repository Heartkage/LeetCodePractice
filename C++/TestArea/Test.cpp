#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    /*vector<int> v1{0};
    vector<int> v2{1};
    vector<int> v3{2};*/
    vector<vector<int>> a{vector<int>{1},vector<int>{2},vector<int>{3}};
    vector<vector<int>> b(a);
    a[0][0] = 30;

    cout << "a0: " << a[0][0] << ", b0: " << b[0][0] << endl;

    for(auto &i:a[0])
        cout << i << endl;


    return 0;
}