#include "grid.h"
#include <cmath>
#include <iostream>
using namespace std;

Grid::Grid(vector<int>& hvals, vector<int>& gvals, int n) {
    dim = sqrt(n);
    min = 0;
    max = dim - 1;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            nodes.push_back(Node(hvals[i * dim + j], gvals[i * dim + j], i, j));
        }
    }
}

void Grid::assignNeighbours() {
    int index = 0;
    int row = 0;
    int column = 0;

    for (auto& node : nodes) {
        row = index / dim;
        column = index % dim;
        
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int neighborRow = row + i;
                int neighborCol = column + j;

                if (neighborRow < min || neighborRow > max || neighborCol < min || neighborCol > max) {
                    continue;
                }

                node.neighbours.push_back(&nodes[neighborRow * dim + neighborCol]);
            }
        }

        index++;
    }
}

void Grid::print() {
    int k = 0;
    for (auto& x : nodes) {
        if (k % 3 == 0) {
            cout << '\n';
        }
        cout << x.f << ':';
        k++;
    }
}
