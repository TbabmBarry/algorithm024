/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache
{
private:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    int cap;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key)
    {
        auto it = hash.find(key);
        if (it == hash.end())
            return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value)
    {
        auto it = hash.find(key);

        if (it != hash.end())
        {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        else
        {
            cache.push_front({key, value});
            hash[key] = cache.begin();

            if (hash.size() > cap)
            {
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
