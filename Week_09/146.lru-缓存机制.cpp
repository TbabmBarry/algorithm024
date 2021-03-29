/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache
{
private:
    int _capacity;
    unordered_map<int, pair<int, list<int>::iterator>> _cache;
    list<int> _lru;

public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key)
    {
        auto item = _cache.find(key);
        if (item == _cache.end())
            return -1;
        use(item);
        return item->second.first;
    }

    void put(int key, int value)
    {
        auto item = _cache.find(key);
        if (item != _cache.end())
        {
            use(item);
            _cache[key] = {value, _lru.begin()};
            return;
        }
        if (_cache.size() == _capacity)
        {
            _cache.erase(_lru.back());
            _lru.pop_back();
        }
        _lru.push_front(key);
        _cache.insert({key, {value, _lru.begin()}});
    }

    void use(unordered_map<int, pair<int, list<int>::iterator>>::iterator &it)
    {
        _lru.erase(it->second.second);
        _lru.push_front(it->first);
        it->second.second = _lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
