#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;

class MyHashMap {
    int* map;
    int size;

    void checkMapSize(int index)
    {
        int* temp;
        while(index >= size)
        {
            temp = map;
            size -= 1;
            size *= 10;
            size += 1;
            map = new int[size];
            memset(map, -1, size*sizeof(int));
            memcpy(map, temp, ((size/10)+1)*sizeof(int));
        }
    }

    void printMap()
    {
        for(int i = 0; i < size; i++)
        {
            cout << map[i] << " ";
        }        
        cout << endl;
        cout << endl;
    }

public:
    MyHashMap() {
        size = 11;
        map = new int[size];
        memset(map, -1, size*sizeof(int));
    }
    
    void put(int key, int value) {
        checkMapSize(key);
        map[key] = value;
        //printMap();
    }
    
    int get(int key) {
        if(key >= size)
            return -1;
        else
            return map[key];
    }
    
    void remove(int key) {
        if(key < size)
            map[key] = -1;
    }
};

int main(int argc, char **argv)
{
    MyHashMap map;
    int index = 0;
    stringstream ss;
    ss << argv[1];
    ss >> index;
    map.put(index, 1);
    map.put(12, 2);
    cout << map.get(index) << endl;
    cout << map.get(100) << endl;
    return 0;
}