#include "node.h"
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <cstdlib>
#include "grid.h"

using namespace std;

void printPath(Node* endNode){
    while (endNode!=NULL)
    {
        cout<<endNode->position.first<<endNode->position.second<<endl;
        endNode=endNode->connection;
    };
}

int calcNewGval(Node*source,Node* desired){
    if ((desired->position.first-source->position.first != 0)&&(desired->position.second-source->position.second != 0))
    {
        return source->g + 14;
    }else{
        return source->g + 10;
    }
};

struct compareF {
    bool operator()(const Node* a, const Node* b) {
        return (a->f > b->f)||(a->f == b->f && a->h>b->h);
    }
};

int main(int argc,char*argv[]){
    int start_index,end_index;

    if (argc>1)
    {
        start_index = stoi(argv[1]);
        end_index = stoi(argv[2]);
    }else{
        start_index=0;
        end_index=8;
    };

     unordered_map<Node*,bool> processed;
     unordered_map<Node*,bool> inQueue;

    priority_queue<Node*,vector<Node*>,compareF> minHeap;

    vector<int>gvals = {0,9999,9999,9999,9999,9999,9999,9999,99999};
    vector<int>hvals = {9,8,7,6,5,4,3,2,1};
    Grid grid(hvals,gvals,9);
                 grid.print();
                 grid.assignNeighbours();
                 cin;
    Node& startNode = grid.nodes[start_index];
    Node& endNode = grid.nodes[end_index];

    minHeap.push(&grid.nodes[start_index]);
    inQueue[&grid.nodes[start_index]]=true;
            bool istrue=minHeap.empty();

    while (true) {
    Node* currentNode = minHeap.top();
    minHeap.pop();

    if (!currentNode->explored||processed.find(currentNode) != processed.end()) {
        continue; // Skip if already processed
    }

    processed[currentNode] = true;

    cout << "Processing Node: (" << currentNode->position.first << ", " << currentNode->position.second << ")" << endl;

    if (*currentNode == endNode) {
        printPath(currentNode);
        return 0;
    }

    for (auto neighbour : currentNode->neighbours) {
        if (processed.find(neighbour) != processed.end()) {
            continue;
        }

        int newGValFromCurrent = calcNewGval(currentNode, neighbour);

        if (newGValFromCurrent < neighbour->g || inQueue.find(neighbour) == inQueue.end()) {
            neighbour->g = newGValFromCurrent;
            neighbour->setF();
            neighbour->connection = currentNode;
            

            if (inQueue.find(neighbour) == inQueue.end()) {
                inQueue[neighbour] = true;
            }
            minHeap.push(neighbour); // Always push to re-prioritize
        }
    }
}

return 0;

    
};