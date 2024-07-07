//tairmazriv@gmail.com
//id: 209188382

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>
#include <unordered_set>
using namespace std;

namespace ariel{
    class Algorithms {
        public:
            static bool isConnected(const Graph& g);

            static string shortestPath(const Graph& g,int start, int end);

            static bool checkCycle(size_t node, vector<size_t> adj[], size_t vis[], size_t parent, vector<size_t> &path, size_t &cycleStart, std::unordered_set<size_t> &visitedNodes);
            static bool isContainsCycle(const Graph& g);

            static string isBipartite(const Graph& g);

            static bool negativeCycle(const Graph& g);

        };

}

#endif // ALGORITHMS_HPP