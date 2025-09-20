struct Packet {
    int source, destination, timestamp;
};

class Router {
private:
    size_t memoryLimit;
    queue<Packet> q;
    unordered_set<long long> dupKey;
    unordered_map<int, vector<int>> destToTime;

    long long makeKey(int s, int d, int t) {
        return (long long)s * 1e10 + (long long)d * 1e5 + t;
    }

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        auto key = makeKey(source, destination, timestamp);
        if (dupKey.contains(key))
            return false;

        if (q.size() == memoryLimit) {
            auto old = q.front(); q.pop();
            auto oldKey = makeKey(old.source, old.destination, old.timestamp);
            dupKey.erase(oldKey);

            destToTime[old.destination].erase(destToTime[old.destination].begin());
            if (destToTime[old.destination].empty())
                destToTime.erase(old.destination);
        }

        q.push({source, destination, timestamp});
        dupKey.insert(key);
        destToTime[destination].emplace_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};

        auto p = q.front(); q.pop();
        auto key = makeKey(p.source, p.destination, p.timestamp);
        dupKey.erase(key);

        destToTime[p.destination].erase(destToTime[p.destination].begin());
            if (destToTime[p.destination].empty())
                destToTime.erase(p.destination);
        
        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (destToTime[destination].empty()) return 0;
        auto &v = destToTime[destination];

        auto it1 = lower_bound(v.begin(), v.end(), startTime);
        auto it2 = upper_bound(v.begin(), v.end(), endTime);
        return distance(it1, it2);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */