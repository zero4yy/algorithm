#include <bits/stdc++.h>

using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int> > cache; // 存储 <key, value> list容器实现双向链表
    unordered_map<int, list<pair<int, int>>::iterator> hash; // 查找 <key, value>

public:
    LRUCache(int cap) : capacity(cap) {}
    
    int get(int key) {
        if(!hash.contains(key)) return -1;
        auto it = hash[key]; // 查找 key 对应的节点
        int value = it->second; // 得到 key 对应的 value
        cache.erase(it); // 删掉该节点
        cache.push_front({key, value}); // 重新插入头部
        hash[key] = cache.begin(); // 更新哈希
        return value;
    }
    
    void put(int key, int value) {
        if(hash.contains(key)) { // 缓存中有 key
            cache.erase(hash[key]);
        } else if (cache.size() >= capacity){ // 缓存中没有 key，但容量不够
            int old_key = cache.back().first; // 删掉最后一个节点
            cache.pop_back(); 
            hash.erase(old_key); 
        }
        cache.push_front({key, value}); // 将 key 对应节点插入队列头部
        hash[key] = cache.begin(); // 更新哈希
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 int main() {

    return 0;
 }