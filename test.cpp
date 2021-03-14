// Leetcode 732
#include <stdio.h>
#include <utility>
#include <vector>
#include <list>
using namespace std;

class MyHashMap {
    vector<list<pair<int, int>>> data;
    static const int base=769;
    static int hash(int key){return key%base;}
public:
    /** Initialize your data structure here. */
    MyHashMap(): data(base){

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hk=hash(key);
        auto& hl=data[hk];
        for(auto it=hl.begin();it!=hl.end();++it){
            if(it->first==key){
                it->second=value;
                return;
            }
        }
        hl.push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hk=hash(key);
        auto hl=data[hk];
        for(auto it=hl.begin();it!=hl.end();++it){
            if(it->first==key){
                return it->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hk=hash(key);
        auto hl=data[hk];
        for(auto it=hl.begin();it!=hl.end();++it){
            if(it->first==key){
                hl.erase(it);
                return;
            }
        }

    }
};

int main(void)
{
    MyHashMap hm;
    hm.put(1, 1);
    hm.put(2, 2);
    printf("%d",hm.get(1));
    return 0;
}
