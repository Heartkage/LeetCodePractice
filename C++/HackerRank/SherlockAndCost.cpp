#include<iostream>
#include<vector>
using namespace std;

// Complete the cost function below.
int cost(vector<int> B) {

    int low = 0;
    int high = 0;

    for(int i = 1; i < B.size(); i++)
    {
        int highToHigh = abs(B[i-1] - B[i]);
        int highToLow = B[i-1] - 1;
        int lowToHigh = B[i] - 1;

        int previousLow = low;
        low = high + highToLow;
        high = max(high + highToHigh, previousLow + lowToHigh);
    }
    return max(high, low);
}

int main()
{
    vector<int> list{56, 32, 60, 73, 29};

    cout << cost(list) << endl;
    return 0;
}
