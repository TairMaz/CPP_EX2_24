//tairmazriv@gmail.com
//id: 209188382

#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <sstream> 
using namespace std;

namespace ariel {

    size_t Graph::size() const {
        return Matrix.size();
    }

    void Graph::loadGraph(const vector<vector<int>>& matrix) {
        // Check if the matrix is square
        size_t n = matrix.size();
        for (size_t i = 0; i < n; ++i) {
            if (matrix[i].size() != n) {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        Matrix = matrix;
    }

    void Graph::printGraph() {
        cout << "Graph with " << size() << " vertices and ";
        int edges = 0;
        for (size_t i = 0; i < size(); ++i) {
            for (size_t j = 0; j < size(); ++j) {
                if (Matrix[i][j] != 0) {
                    edges++;
                }
            }
        }
        cout << edges << " edges." << endl;
    }
    
    string Graph::toString() const {
        ostringstream oss;
        for (const auto& row : Matrix) {
            oss << "[";
            for (size_t i = 0; i < row.size(); ++i) {
                oss << row[i];
                if (i < row.size() - 1) {
                    oss << ", ";
                }
            }
            oss << "]\n";
        }
        return oss.str();
    }

    ostream& operator<<(ostream& os, const Graph& g) {
        for (const vector<int>& row : g.Matrix) {
            os << "[";
            for (size_t i = 0; i < row.size(); ++i) {
                os << row[i];
                if (i < row.size() - 1) {
                    os << ", ";
                }
            }
            os << "]\n";
        }
        return os;
    }

    Graph operator+(const Graph& g1, const Graph& g2) {
        size_t n = g1.Matrix.size();
        if (n != g2.Matrix.size()) {
            throw invalid_argument("Invalid addition: graphs not the same size");
        }

        Graph g;
        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                graph[i][j] = g1.Matrix[i][j] + g2.Matrix[i][j];
            }
        }

        g.loadGraph(graph);
        return g;
    }

    Graph& Graph::operator+=(const Graph& other) {
        if (size() != other.Matrix.size()) {
            throw invalid_argument("Invalid addition: graphs not the same size");
        }

        for (size_t i = 0; i < size(); ++i) {
            for (size_t j = 0; j < size(); ++j) {
                Matrix[i][j] += other.Matrix[i][j];
            }
        }
        return *this;
    }

    Graph Graph::operator+() const {
        return *this;
    }

    Graph operator-(const Graph& g1, const Graph& g2) {
        size_t n = g1.Matrix.size();
        if (n != g2.Matrix.size()) {
            throw invalid_argument("Invalid subtraction: graphs not the same size");
        }

        Graph g;
        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                graph[i][j] = g1.Matrix[i][j] - g2.Matrix[i][j];
            }
        }

        g.loadGraph(graph);
        return g;
    }

    Graph& Graph::operator-=(const Graph& other) {
        if (size() != other.Matrix.size()) {
            throw invalid_argument("Invalid subtraction: graphs not the same size");
        }

        for (size_t i = 0; i < size(); ++i) {
            for (size_t j = 0; j < size(); ++j) {
                Matrix[i][j] -= other.Matrix[i][j];
            }
        }
        return *this;
    }

    Graph Graph::operator-() const {
        Graph g;
        vector<vector<int>> graph(size(), vector<int>(size(), 0));

        for (size_t i = 0; i < size(); ++i) {
            for (size_t j = 0; j < size(); ++j) {
                graph[i][j] = -Matrix[i][j];
            }
        }

        g.loadGraph(graph);
        return g;    }

    Graph Graph::operator++(int) {
        Graph copy = *this;
        for (size_t i = 0; i < size(); ++i) {
            for (size_t j = 0; j < size(); ++j) {
                if (Matrix[i][j] != 0)
                    Matrix[i][j]++;
            }
        }
        return copy;
    }

    Graph& Graph::operator++() {
        for (size_t i = 0; i < size(); ++i) {
            for (size_t j = 0; j < size(); ++j) {
                if (Matrix[i][j] != 0)
                    Matrix[i][j]++;
            }
        }
        return *this;
    }

    Graph Graph::operator--(int) {
        Graph copy = *this;
        for (size_t i = 0; i < size(); ++i) {
            for (size_t j = 0; j < size(); ++j) {
                if (Matrix[i][j] != 0)
                    Matrix[i][j]--;
            }
        }
        return copy;
    }

    Graph& Graph::operator--() {
        for (size_t i = 0; i < size(); ++i) {
            for (size_t j = 0; j < size(); ++j) {
                if (Matrix[i][j] != 0)
                    Matrix[i][j]--;            }
        }
        return *this;
    }

    Graph operator*(const Graph& g1, const Graph& g2){
        size_t n = g1.Matrix.size();
        if (n != g2.Matrix.size()) {
            throw invalid_argument("Invalid multiplication: graphs not the same size");
        }

        Graph g;
        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                for (size_t k = 0; k < n; ++k) {
                    graph[i][j] += g1.Matrix[i][k] * g2.Matrix[k][j];
                }
            }
        }
        g.loadGraph(graph);
        return g;
    }

    Graph& Graph::operator*=(int num){
        for (size_t i = 0; i < size(); ++i) {
            for (size_t j = 0; j < size(); ++j) {
                Matrix[i][j] *= num;
            }
        }
        return *this;
    }

    Graph& Graph::operator/=(int num){
        for (size_t i = 0; i < size(); ++i) {
            for (size_t j = 0; j < size(); ++j) {
                Matrix[i][j] /= num;
            }
        }
        return *this;
    }

    int Graph::edges() const {
        int ans = 0;
        size_t n = Matrix.size();
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (Matrix[i][j] != 0)
                    ans++;
            }
        }
        return ans;
    }

    bool operator==(const Graph& g1, const Graph& g2) {
        return ((g1<=g2)&&(g1>=g2));
        // if (g1.Matrix.size() != g2.Matrix.size()) {
        //     return false;
        // }
        // size_t n = g1.Matrix.size();
        // for (size_t i = 0; i < n; ++i) {
        //     for (size_t j = 0; j < n; ++j) {
        //         if (g1.Matrix[i][j] != g2.Matrix[i][j]) {
        //             return false;
        //         }
        //     }
        // }
        // return true;
    }

    bool operator!=(const Graph& g1, const Graph& g2){
        return !(g1==g2);
    }

    bool operator<(const Graph& g1, const Graph& g2){
        if(g1.edges()<g2.edges()){
            return true;
        }
        if (g1.edges()==g2.edges()){
            if(g1.Matrix.size()<g2.Matrix.size()){
                return true;
            }
        }
        return false;
    }

    bool operator<=(const Graph& g1, const Graph& g2){
        return (!(g1>g2));
    }

    bool operator>(const Graph& g1, const Graph& g2){
        return (g2<g1);
    }

    bool operator>=(const Graph& g1, const Graph& g2){
        return (!(g1<g2));
    }
}