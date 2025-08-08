class RecentCounter {
public:
    RecentCounter() : time_queue_() {
    }

    int ping(int t) {
        int low = t - 3000;
        time_queue_.push(t);
        int res = time_queue_.size();
        while (time_queue_.front()) {
            if (time_queue_.front() < low) {
                time_queue_.pop();
                res--;
            }
            else
                break;
        }

        return res;
    }

private:
    std::queue<int> time_queue_;
};
