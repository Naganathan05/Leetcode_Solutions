/*---------------------------
  Time Complexity: O(V + E)
  Space Complexity: O(V + E)
-----------------------------*/

class DisJointSet {
private:
	vector<int> parent, size;
public:
	DisJointSet(int numNodes){
		parent.resize(numNodes + 1, 0);
		size.resize(numNodes + 1, 1);
		for(int i = 0; i <= numNodes; i++) parent[i] = i;
	}
	
	int findUParent(int node){
		if(parent[node] == node) return node;
		return parent[node] = findUParent(parent[node]);
	}

	int getSize(int node){
		return size[node];
	}

	bool UnionBySize(int u, int v){
		int ult_u = findUParent(u);
		int ult_v  = findUParent(v);
		if(ult_u == ult_v) return false;
		if(size[ult_u] >= size[ult_v]){
			size[ult_u] += size[ult_v];
			parent[ult_v] = ult_u;
		}
		else{
			size[ult_v] += size[ult_u];
			parent[ult_u] = ult_v; 
		}
		return true;
	}
};

int countWays(int n, vector<vector<int>> &fruitIds)
{
	DisJointSet ds = DisJointSet(n);
	for(int i = 0; i <= fruitIds.size() - 1; i++){
		ds.UnionBySize(fruitIds[i][0], fruitIds[i][1]);
	}

	vector<int> componentSizes;
	for(int i = 0; i <= n - 1; i++){
		if(ds.findUParent(i) == i) componentSizes.push_back(ds.getSize(i));
	}

	int currSum = 0, totalWays = 0;
	for(int i = 0; i <= componentSizes.size() - 1; i++){
		currSum += componentSizes[i];
		totalWays += componentSizes[i] * (n - currSum);
	}
	return totalWays;
}

/*
Question Link: https://www.naukri.com/code360/problems/ninja-and-fruits_1170757
Author: M.R.Naganathan
*/
