class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> asteroid_stack;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] < 0) {
                while (!asteroid_stack.empty() && asteroid_stack.top() > 0 &&
                       asteroid_stack.top() < -asteroids[i]) {
                    asteroid_stack.pop();
                }

                if (asteroid_stack.empty() || asteroid_stack.top() < 0)
                    asteroid_stack.push(asteroids[i]);

                if (!asteroid_stack.empty() &&
                    asteroid_stack.top() == -asteroids[i])
                    asteroid_stack.pop();
            } else
                asteroid_stack.push(asteroids[i]);
        }

        std::vector<int> result(asteroid_stack.size());
        int i = asteroid_stack.size() - 1;
        while (!asteroid_stack.empty()) {
            result[i--] = asteroid_stack.top();
            asteroid_stack.pop();
        }

        return result;
    }
};