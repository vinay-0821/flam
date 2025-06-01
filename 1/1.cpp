#include <bits/stdc++.h>

using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> clist;
    unordered_map<int, list<pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        
        auto it = m[key];
        int value = it->second;
        clist.erase(it);
        clist.push_front({key, value});
        m[key] = clist.begin();
        
        return value;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            clist.erase(m[key]);
        }
        else if (clist.size() == capacity) {
            int lruKey = clist.back().first;
            clist.pop_back();
            m.erase(lruKey);
        }

        clist.push_front({key, value});
        m[key] = clist.begin();
    }
};

int main() {
    int capacity;
    cin>>capacity;
    LRUCache lru(capacity);

    while (true) {
        string operation;
        cin>>operation;
        if(operation == "put"){
            int key;
            int value;
            cin>>key;
            cin>>value;
            lru.put(key,value);
        }
        else if(operation == "get"){
            int key;
            cin>>key;
            cout<<lru.get(key)<<endl;
        }
        else if(operation == "exit"){
            break;
        }
    }

    return 0;
}
