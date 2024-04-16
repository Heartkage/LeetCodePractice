#include<iostream>
#include<vector>

using namespace std;

int equal(vector<int> arr) {

    int highest = -2147483648;
    int lowest = 2147483647;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > highest)
            highest = arr[i];
        if(arr[i] < lowest)
            lowest = arr[i];
    }

    for(int i = 0; i < arr.size(); i++)
        arr[i] = highest - arr[i];

    int counter = 0;
    while(highest != lowest)
    {
        highest = -2147483648;
        lowest = 2147483647;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] > highest)
                highest = arr[i];
            if(arr[i] < lowest)
                lowest = arr[i];
        }

        //cout << "Highest: " << highest << ", Lowest: " << lowest << endl;
        if(highest == lowest)
            break;

        bool foundSource = false;
        int difference = highest - lowest;
        
        int decreaseAmount = (difference / 5) * 5;
        difference %= 5;
        decreaseAmount = (difference / 2) * 2;
        difference %= 2;
        decreaseAmount = (difference / 1);

        //cout << "[ ";
        for(int i = 0; i < arr.size(); i++)
        {
            if(lowest == arr[i] && !foundSource)
                foundSource = true;
            else
                arr[i] -= decreaseAmount;
            //cout << arr[i] << " ";
        }
        //cout << "]" << endl;
        counter++;
    }
    
    return counter;
}


int main(void)
{
    vector<int> nums{512,125,928,381,890,90, 512, 789, 469, 473, 908, 990, 195, 763, 102, 643, 458, 366, 684, 857, 126, 534, 974, 875, 459, 892, 686, 373, 127, 297, 576, 991, 774, 856, 372, 664, 946, 237, 806, 767, 62, 714, 758, 258, 477, 860, 253, 287, 579, 289, 496};
    cout << equal(nums) << endl;
    return 0;
}
