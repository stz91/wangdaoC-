#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>

using namespace std;

class LRUCache
{
public:
    LRUCache(int cacheSize)
        : _cacheSize(cacheSize)
    {
        cout << "LRUCache(int)" << endl;
    }
    ~LRUCache()
    {
        cout << "~LRUCache()" << endl;
    }
    void put(int key, int value)
    {
        auto it = _map.find(key);
        if (it != _map.end())
        {
            _list.erase(it->second);
            _list.push_front(make_pair(key, value));
            _map[key] = _list.begin();
            cout << "写入数据成功" << endl;
        }
        else if (_map.size() < _cacheSize)
        {
            _list.push_front(make_pair(key, value));
            _map[key] = _list.begin();
            cout << "写入数据成功" << endl;
        }
        else
        {
            auto it = --_list.end();
            _map.erase(it->first);
            _list.push_front(make_pair(key, value));
            _map[key] = _list.begin();
            cout << "写入数据成功" << endl;
            cout << "最老的秘钥已作废" << endl;
        }
    }
    int get(int key)
    {
        auto it = _map.find(key);
        int ans = -1;
        if (it != _map.end())
        {
            ans = it->second->second;
            _list.erase(it->second);
            _list.push_front(make_pair(key, ans));
            it->second = _list.begin();
        }
        return ans;
    }

private:
    int _cacheSize;
    list<pair<int, int>> _list;
    map<int, list<pair<int, int>>::iterator> _map;
};

int main(void)
{
    LRUCache cache = LRUCache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;    // 返回  1
    cache.put(3, 3); // 该操作会使得密钥 2 作废
    cout << cache.get(2) << endl;    // 返回 -1 (未找到)
    cache.put(4, 4); // 该操作会使得密钥 1 作废
    cout << cache.get(1) << endl;    // 返回 -1 (未找到)
    cout << cache.get(3) << endl;    // 返回  3
    cout << cache.get(4) << endl;    // 返回  4
}