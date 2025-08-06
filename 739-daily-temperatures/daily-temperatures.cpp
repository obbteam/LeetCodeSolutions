class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> answer(temperatures.size(), 0);
    std::stack<int> stackIndex;

    for (int i = 0; i < temperatures.size(); i++) {
        while (!stackIndex.empty() && temperatures[stackIndex.top()] < temperatures[i]) {
            auto prevIndex = stackIndex.top();
            stackIndex.pop();
            answer[prevIndex] = i - prevIndex;
        }

        stackIndex.push(i);
    }

    return answer;
}

};