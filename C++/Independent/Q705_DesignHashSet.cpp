#include<iostream>
#include<vector>
using namespace std;

class MyHashSet {
    vector<bool> hash;
public:
    MyHashSet() {
        hash.resize(1000001, false);
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }
    
    bool contains(int key) {
        return hash[key];
    }
};

int main(void){
    MyHashSet* mySet = new MyHashSet();
    mySet->add(1);
    mySet->add(2);
    mySet->add(1);
    cout << mySet->contains(1) << endl;
    mySet->remove(1);
    cout << mySet->contains(1) << endl;

    return 0;
}