/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adjList;
        unordered_map<string, bool> mappingSupplies;
        unordered_map<string, int> inDegree;
        for(string str : supplies) mappingSupplies[str] = true;
        for(int i = 0; i <= ingredients.size() - 1; i++){
            for(auto const& ing : ingredients[i]){
                adjList[ing].push_back(recipes[i]);
                inDegree[recipes[i]] += 1;
            }
        }

        vector<string> recipeOrder;
        queue<string> fifo;
        for(string str : supplies) fifo.push(str);
        while(!fifo.empty()){
            string currIng = fifo.front();
            fifo.pop();
            if(mappingSupplies.find(currIng) == mappingSupplies.end()) recipeOrder.push_back(currIng);

            for(string recipe : adjList[currIng]){
                inDegree[recipe] -= 1;
                if(inDegree[recipe] == 0) fifo.push(recipe);
            }
        }
        return recipeOrder;
    }
};

/*
Question Link: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
Author: M.R.Naganathan
*/
