class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < arr.size(); ++i) {
            int numOcc = 0;
            for (int j = 0; j < arr.size(); ++j) {
                if (arr[i] == arr[j])
                    numOcc++;
            }

            if (map.contains(numOcc)) {
                if (map[numOcc] != arr[i])
                    return false;
            } else {
                map.insert({numOcc, arr[i]});
            }
        }
        return true;
    }
};