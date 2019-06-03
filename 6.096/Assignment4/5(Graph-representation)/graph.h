#include <map>
#include <vector>
using namespace std;

class Graph {
 private:
  map<int, vector<int>> adjacencyList;

 public:
  Graph(const vector<int> &starts, const vector<int> &ends);
  int numOutgoing(const int nodeID) const;
  const vector<int> &adjacent(const int nodeID) const;
};
