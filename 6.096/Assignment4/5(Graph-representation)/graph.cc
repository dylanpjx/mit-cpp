#include "graph.h"
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>
using namespace std;

Graph::Graph(const vector<int> &starts, const vector<int> &ends) {
  if (starts.size() != ends.size()) {
    throw invalid_argument("starts and ends are of different sizes.");
  }

  for (int i = 0; i < starts.size(); ++i) {
    adjacencyList[starts[i]];
    adjacencyList[ends[i]];
    adjacencyList[starts[i]].push_back(ends[i]);
  }
}
int Graph::numOutgoing(const int nodeID) const {
  if (adjacencyList.count(nodeID) == 1) {
    return adjacencyList.find(nodeID)->second.size();
  } else {
    throw invalid_argument("NodeID not found.");
  }
}
const vector<int> &Graph::adjacent(const int nodeID) const {
  if (adjacencyList.count(nodeID) == 1) {
    return adjacencyList.find(nodeID)->second;
  } else {
    throw invalid_argument("NodeID not found.");
  }
}

int main() {
  vector<int> starts = {1, 1, 1, 5, 5, 4};
  vector<int> ends = {2, 3, 4, 4, 2, 2};
  Graph g(starts, ends);
  cout << g.numOutgoing(1) << endl;
  for (auto i : g.adjacent(1)) {
    cout << i << " ";
  }
  cout << endl;
}
