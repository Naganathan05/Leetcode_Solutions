/*-------------------------------
  Time Complexity: O(E * log(V))
  Space Complexity: O(V)
----------------------------------*/

type DisJointSet struct {
    parent   []int
    size     []int
    totalAnd []int
}

func (ds *DisJointSet) InitDS(numNodes int) {
    ds.parent = make([]int, numNodes);
    ds.size = make([]int, numNodes);
    ds.totalAnd = make([]int, numNodes);

    for i := 0; i < numNodes; i++ {
        ds.parent[i] = i;
        ds.size[i] = 1;
        ds.totalAnd[i] = -1;
    }
}

func (ds *DisJointSet) findUParent(node int) int {
    if ds.parent[node] == node {
        return node;
    }
    ds.parent[node] = ds.findUParent(ds.parent[node]);
    return ds.parent[node];
}

func (ds *DisJointSet) UnionBySize(u, v, cost int) {
    ult_u, ult_v := ds.findUParent(u), ds.findUParent(v);

    if ult_u == ult_v {
        ds.totalAnd[ult_u] &= cost;
        return;
    }

    if ds.size[ult_u] >= ds.size[ult_v] {
        ds.size[ult_u] += ds.size[ult_v];
        ds.parent[ult_v] = ult_u;
        ds.totalAnd[ult_u] &= (ds.totalAnd[ult_v] & cost);
    } else {
        ds.size[ult_v] += ds.size[ult_u];
        ds.parent[ult_u] = ult_v;
        ds.totalAnd[ult_v] &= (ds.totalAnd[ult_u] & cost);
    }
}

func minimumCost(n int, edges [][]int, query [][]int) []int {
    ds := &DisJointSet{};
    ds.InitDS(n);

    for _, edge := range edges {
        u, v, cost := edge[0], edge[1], edge[2];
        ds.UnionBySize(u, v, cost);
    }

    answer := make([]int, len(query));
    for i := 0; i < len(query); i++ {
        u, v := query[i][0], query[i][1];
        ult_u, ult_v := ds.findUParent(u), ds.findUParent(v);
        if ult_u != ult_v {
            answer[i] = -1;
        } else {
            answer[i] = ds.totalAnd[ult_u];
        }
    }
    return answer;
}

/*
Question Link: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/
Author: M.R.Naganathan
*/
