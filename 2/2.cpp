#include <bits/stdc++.h>

using namespace std;

class MyHashMap {
    vector<int> mapArray;
public:
    MyHashMap() {
        mapArray = vector<int>(1000001, -1);
    }
    void put(int key, int value) {
        mapArray[key] = value;
    }
    int get(int key) {
        return mapArray[key];
    }
    void remove(int key) {
        mapArray[key] = -1;
    }
};


int main() {
    MyHashMap myMap;

    while (true) {
        string operation;
        cin>>operation;

        if (operation == "put") {
            int key;
            int value;
            cin>>key;
            cin>>value;
            myMap.put(key, value);
        } 
        else if (operation == "get") {
            int key;
            cin>>key;
            cout<< myMap.get(key)<<endl;
        } 
        else if (operation == "remove") {
            int key;
            cin>>key;
            myMap.remove(key);
        } 
        else if(operation == "exit"){
            break;
        }
    }

    return 0;
}
