#include <iostream>

struct edge {
	int first, second;
	int weight;
};

int main() {
  int n, m, result = 0;
  std::cin >> n >> m;
  
  edge edges[m]; 
  int parents[n + 1];
  
  for (int k = 0; k < m; ++k) { 
  	std::cin >> edges[k].first >> edges[k].second >> edges[k].weight; 
  }
  
  for (int i = 1; i <= n; ++i) {
  	parents[i] = i;
  }
  
  for (int i = 0; i < n - 1; ++i) {
    int weight = 30001, j = 0;
    
    for (int k = 0; k < m; ++k) {
      if (parents[edges[k].first] != parents[edges[k].second] && edges[k].weight < weight) {
     		weight = edges[k].weight;
        j = k;
      }
    }
    
    result += weight;
    
    int first = parents[edges[j].first], second = parents[edges[j].second];
    
    for (int j = 1; j <= n; ++j) {
      if (parents[j] == second) 
      	parents[j] = first;
    }
  }
  
  std::cout << result << std::endl;
  return 0;
}
