#include "node.h"
#include <vector>
class Grid{
public:
    vector<Node> nodes;
    int min;
    int max;
    int dim;

    Grid(vector<int>&hvals,vector<int>&gvals,int n=100);
    void assignNeighbours();
    void print();
};