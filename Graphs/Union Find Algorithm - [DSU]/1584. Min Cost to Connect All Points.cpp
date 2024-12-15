/*---------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
-----------------------------*/

class DisJointSet {
private:
    map<pair<int, int>, int> size;
    map<pair<int, int>, pair<int, int>> parent;
public:
    DisJointSet(vector<vector<int>> &points) {
        int numPoints = points.size();
        for(int i = 0; i <= numPoints - 1; i++){
            size[{points[i][0], points[i][1]}] = 1;
            parent[{points[i][0], points[i][1]}] = {points[i][0], points[i][1]}; 
        }

    }

    pair<int, int> findUParent(pair<int, int> &point){
        if(parent[point] == point) return point;
        return parent[point] = findUParent(parent[point]);
    }

    bool UnionBySize(pair<int, int> &firstPoint, pair<int, int> &secondPoint){
        pair<int, int> ult_u = findUParent(firstPoint);
        pair<int, int> ult_v = findUParent(secondPoint);
        if(ult_u.first == ult_v.first && ult_u.second == ult_v.second) return false;

        if(size[ult_u] >= size[ult_v]){
            size[ult_u] += size[ult_v];
            parent[ult_v] = ult_u;
        }
        else {
            size[ult_v] += size[ult_u];
            parent[ult_u] = ult_v;
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numPoints = points.size();
        vector<tuple<int, pair<int, int>, pair<int, int>>> pointDistances;
        for (int i = 0; i <= numPoints - 1; i++) {
            for (int j = 0; j <= numPoints - 1; j++) {
                int currDist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pointDistances.push_back({currDist, {points[i][0], points[i][1]}, {points[j][0], points[j][1]}});
            }
        }

        DisJointSet ds = DisJointSet(points);
        sort(pointDistances.begin(), pointDistances.end(), [](const tuple<int, pair<int, int>, pair<int, int>> &a, const tuple<int, pair<int, int>, pair<int, int>> &b) {
            return get<0>(a) < get<0>(b);
        });

        int minCost = 0;
        for (int i = 0; i < pointDistances.size(); i++) {
            pair<int, int> firstPoint = get<1>(pointDistances[i]);
            pair<int, int> secondPoint = get<2>(pointDistances[i]);
            int currCost = get<0>(pointDistances[i]);

            if(ds.UnionBySize(firstPoint, secondPoint)) minCost += currCost;
        }
        return minCost;
    }
};

/*
Question Link: https://leetcode.com/problems/min-cost-to-connect-all-points/
Author: M.R.Naganathan
*/
