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

    vector<int>hvals = {1,2,3,4,5,6,7,8,9};
    vector<int>gvals = {0,0,0,0,0,0,0,0,0};
    Grid grid(hvals,gvals,9);
    Node& startNode = grid.nodes[start_index];
    Node& endNode = grid.nodes[end_index];

    minHeap.push(&startNode);
    inQueue[&startNode]=true;
    Node*parent=nullptr;

    while (!minHeap.empty())//can put true
    {
        auto currentNode= minHeap.top();
        currentNode->connection=parent;
        processed[currentNode]=true;
        minHeap.pop();

        if (*currentNode==endNode)
        {
            //backtracking with the help of connection string until null node doesnt appear
            printPath(currentNode);
            return 0;
        };

        for (auto neighbour:currentNode->neighbours)
        {
            if (!neighbour->explored || processed.find(neighbour) != processed.end())
            {
                continue;
            };

            int newGValFromcurrent = calcNewGval(currentNode,neighbour);
            
            if ((newGValFromcurrent<neighbour->g) || inQueue.find(neighbour) == inQueue.end())
            {
                neighbour->g=newGValFromcurrent;
                neighbour->setF();
                neighbour->connection=currentNode;

                if (inQueue.find(neighbour) == inQueue.end())
                {
                    inQueue[neighbour]=true;
                    minHeap.push(neighbour);
                }else{
                    minHeap.push(neighbour);
                }
                
            }

        }
        inQueue[currentNode]=false;
    }
    
};