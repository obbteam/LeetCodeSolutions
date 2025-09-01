class Solution {
public:
    double maxAverageRatio(vector<vector<int> > &classes, int extraStudents) {
    auto profit = [](const int &a, const int &b) {
        return (double) (a + 1) / (b + 1) - (double) a / b;
    };
    priority_queue<pair<double, int> > maxHeap;


    for (int i = 0; i < classes.size(); i++)
        maxHeap.emplace(profit(classes[i][0], classes[i][1]), i);


    for (int i = 0; i < extraStudents; i++) {
        auto [gain, idx] = maxHeap.top();
        maxHeap.pop();
        classes[idx][0]++;
        classes[idx][1]++;
        maxHeap.emplace(profit(classes[idx][0], classes[idx][1]), idx);
    }

    double sum = 0.0;
    for (auto &c: classes)
        sum += static_cast<double>(c[0]) / c[1];

    return sum / classes.size();
}

};