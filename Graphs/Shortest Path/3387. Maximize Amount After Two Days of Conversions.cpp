/*--------------------------------
  Time Complexity: O(n * n * n)
  Space Complexity: O(n * n)
----------------------------------*/

class Solution {
public:
    pair<vector<vector<double>>, unordered_map<string, int>> buildGraph(vector<vector<string>>& pairs, vector<double>& rates) {
        unordered_map<string, int> currencyIndex;
        int index = 0;

        for (const auto& pair : pairs) {
            if (currencyIndex.find(pair[0]) == currencyIndex.end()) currencyIndex[pair[0]] = index++;
            if (currencyIndex.find(pair[1]) == currencyIndex.end()) currencyIndex[pair[1]] = index++;
        }

        vector<vector<double>> graph(index, vector<double>(index, 0));
        for (int i = 0; i < pairs.size(); ++i) {
            int u = currencyIndex[pairs[i][0]];
            int v = currencyIndex[pairs[i][1]];
            graph[u][v] = max(graph[u][v], rates[i]);
            graph[v][u] = max(graph[v][u], 1.0 / rates[i]);
        }

        return {graph, currencyIndex};
    }

    void floydWarshall(vector<vector<double>>& graph) {
        int n = graph.size();
        for (int k = 0; k <= n - 1; k++) {
            for (int i = 0; i <= n - 1; i++) {
                for (int j = 0; j <= n - 1; j++) {
                    if (graph[i][k] > 0 && graph[k][j] > 0) {
                        graph[i][j] = max(graph[i][j], graph[i][k] * graph[k][j]);
                    }
                }
            }
        }
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        auto [graph1, currencyIndex1] = buildGraph(pairs1, rates1);
        auto [graph2, currencyIndex2] = buildGraph(pairs2, rates2);
    
        floydWarshall(graph1);
        floydWarshall(graph2);
    
        if (currencyIndex1.find(initialCurrency) == currencyIndex1.end() || currencyIndex2.find(initialCurrency) == currencyIndex2.end()) {
            return 1.0;
        }
    
        int startCurrencyIndexDay1 = currencyIndex1[initialCurrency];
        vector<double> maxCurrencyDay1(graph1.size(), 0.0);
        maxCurrencyDay1[startCurrencyIndexDay1] = 1.0;
    
        for (int i = 0; i < graph1.size(); ++i) maxCurrencyDay1[i] = graph1[startCurrencyIndexDay1][i];
    
        int endCurrencyIndexDay2 = currencyIndex2[initialCurrency];
        double maxResult = 1.0;
    
        for (int i = 0; i < graph1.size(); ++i) {
            if (maxCurrencyDay1[i] > 0) {
                string currency = "";
                for (const auto& entry : currencyIndex1) {
                    if (entry.second == i) {
                        currency = entry.first;
                        break;
                    }
                }
    
                if (currency.empty() || currencyIndex2.find(currency) == currencyIndex2.end()) continue;
    
                int startCurrencyIndexDay2 = currencyIndex2[currency];
                if (graph2[startCurrencyIndexDay2][endCurrencyIndexDay2] > 0) {
                    maxResult = max(maxResult, maxCurrencyDay1[i] * graph2[startCurrencyIndexDay2][endCurrencyIndexDay2]);
                }
            }
        }
        return maxResult;
    }
};

/*
Question Link: https://leetcode.com/problems/maximize-amount-after-two-days-of-conversions/
Author: M.R.Naganathan
*/
