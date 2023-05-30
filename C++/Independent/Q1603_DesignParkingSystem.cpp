#include<iostream>
using namespace std;

class ParkingSystem {
    int _big, _medium, _small;
public:
    ParkingSystem(int big, int medium, int small) {
        _big = big;
        _medium = medium;
        _small = small;
    }

    bool addCar(int carType) {
        if(carType == 1)
            return --_big >= 0;
        else if(carType == 2)
            return --_medium >= 0;
        else
            return --_small >= 0;
    }
    
};

int main(void){
    ParkingSystem* ps = new ParkingSystem(555, 0, 1000);
    cout << ps->addCar(1) << endl;
    cout << ps->addCar(2) << endl;
    cout << ps->addCar(3) << endl;
    return 0;
}