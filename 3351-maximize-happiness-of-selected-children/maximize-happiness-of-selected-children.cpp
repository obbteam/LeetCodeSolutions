class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        int i = 0;
        while (k > 0) {
            if (happiness[i] - i < 0)
                happiness[i] = i;
            sum += happiness[i] - i;
            i++;
            k--;
        }
        return sum;
    }
};