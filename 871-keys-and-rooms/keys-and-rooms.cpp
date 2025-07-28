class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int> > &rooms) {
    std::stack<int> keys;
    std::unordered_set<int> visited_rooms;
    keys.push(0);


    while (!keys.empty() && visited_rooms.size() != rooms.size()) {
        int room_n = keys.top();
        visited_rooms.emplace(room_n);
        keys.pop();
        for (int key: rooms[room_n]) {
            if (!visited_rooms.contains(key))
                keys.push(key);
        }
    }

    return rooms.size() == visited_rooms.size();
}

};