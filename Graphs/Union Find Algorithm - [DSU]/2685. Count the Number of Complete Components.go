/*------------------------------
  Time Complexity: O(ElogV + V)
  Space Complexity: O(V)
--------------------------------*/

type DisJointSet struct {
    parent []int
    size []int
    numEdges []int
}

func (ds *DisJointSet) InitDS(numNodes int) {
    ds.parent = make([]int, numNodes);
    ds.size = make([]int, numNodes);
    ds.numEdges = make([]int, numNodes);
    for i := range numNodes {
        ds.parent[i] = i;
        ds.size[i] = 1;
        ds.numEdges[i] = 0;
    }
}

func (ds *DisJointSet) findUParent(node int) int {
    if ds.parent[node] == node {
        return node;
    }
    ds.parent[node] = ds.findUParent(ds.parent[node]);
    return ds.parent[node];
}

func (ds *DisJointSet) UnionBySize(u int, v int) bool {
    ult_u, ult_v := ds.findUParent(u), ds.findUParent(v);
    if ult_u == ult_v {
        ds.numEdges[ult_u] += 1;
        return false;
    }

    if ds.size[ult_u] >= ds.size[ult_v] {
        ds.size[ult_u] += ds.size[ult_v];
        ds.parent[ult_v] = ult_u;
        ds.numEdges[ult_u] += (1 + ds.numEdges[ult_v]);
    } else {
        ds.size[ult_v] += ds.size[ult_u];
        ds.parent[ult_u] = ult_v;
        ds.numEdges[ult_v] += (1 + ds.numEdges[ult_u]);
    }
    return true;
}

func countCompleteComponents(n int, edges [][]int) int {
    ds := &DisJointSet{};
    ds.InitDS(n);
    visited := make(map[int]bool);

    for _, edge := range edges {
        ds.UnionBySize(edge[0], edge[1]);
    }

    numCompleteComponents := 0;
    for node := range n {
        ult_node := ds.findUParent(node);
        if visited[ult_node] {
            continue;
        }

        visited[ult_node] = true;
        componentSize := ds.size[ult_node];
        componentEdges := ds.numEdges[ult_node];
        targetEdges := int((componentSize * (componentSize - 1)) / 2);
        if componentEdges == targetEdges {
            numCompleteComponents += 1;
        }
    }
    return numCompleteComponents;
}

/*
Question Link: https://leetcode.com/problems/count-the-number-of-complete-components/
Author: M.R.Naganathan
*/
