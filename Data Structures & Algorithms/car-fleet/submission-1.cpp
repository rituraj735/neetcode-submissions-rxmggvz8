class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;
        cars.reserve(n);

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(),
             [](const auto& a, const auto& b) { return a.first > b.first; });

        int fleets = 0;
        double maxTime = 0.0;

        for (int i = 0; i < n; i++) {
            double t = (double)(target - cars[i].first) / cars[i].second;
            if (t > maxTime) {
                fleets++;
                maxTime = t;
            }
        }
        return fleets;
    }
};