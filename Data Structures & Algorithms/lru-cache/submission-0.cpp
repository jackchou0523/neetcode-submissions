// LRU cache: unordered_map for O(1) look up + std::list for O(1) reordering
// order keeps (k, v), most recently used at front, least at back
// pos maps key-> std::list, list nodes never move in memory, so the iterators in pos alwaays stay valid,
// (A vector can move its elements when it grows, which would break them)
// splice moves a node without invalidating it
// Nodes store the key so eviction can erase it from pos
// get: moves the node to the front, which changes the cache
class LRUCache {
public:
    LRUCache(int capacity): cap(capacity) {}
    
    int get(int key) {
        auto it = pos.find(key);
        if(it != pos.end()){
            // iterator to this key's node in order
            auto node = it->second;
            // just used so move it to the front
            order.splice(order.begin(), order, node);
            return node->second;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        // key already exists, update
        auto it = pos.find(key);
        if(it != pos.end()){
            auto node = it->second;
            node->second = value;
            order.splice(order.begin(), order, node);
            return;
        }

        // new key if full, pop back
        if(order.size() == cap){
            int old_key = order.back().first;
            pos.erase(old_key);
            order.pop_back();
        }
        
        // add new to the front
        order.emplace_front(key, value);
        pos[key] = order.begin();

    }

private:
    using Node = std::pair<int, int>;                          // (key, value)
    const size_t cap;
    std::list<Node> order;                                     // front = most recently used
    std::unordered_map<int, std::list<Node>::iterator> pos;    // key -> where it is in order
};
