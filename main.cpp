/**
 * @file main.cpp
 * @brief Main program demonstrating Dijkstra's shortest path algorithm implementation
 * @author Oussama Darouez
 * @date 2024
 * 
 * This program demonstrates the usage of a weighted graph implementation
 * and Dijkstra's shortest path algorithm. It creates a random connected
 * graph and finds shortest paths between specified vertices.
 */

#include "graph.hpp"
#include "queue.hpp"
#include "path.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Demonstrates the creation and manipulation of a weighted graph
 * @param size Number of vertices in the graph
 */
void demonstrate_graph(int size) {
    graph g(size);
    std::cout << "Created a random connected graph with " << size << " vertices\n";
    std::cout << "Adjacency matrix (left) and weight matrix (right):\n";
    std::cout << g << std::endl;
    
    std::cout << "Number of edges: " << g.get_number_of_connected_nodes() << std::endl;
    std::cout << "Graph is " << (g.is_connected() ? "connected" : "not connected") << std::endl;
}

/**
 * @brief Demonstrates finding shortest paths in the graph
 * @param g Pointer to the graph
 * @param source Source vertex for paths
 */
void demonstrate_paths(graph* g, int source) {
    queue q;
    path p(g, &q);
    
    std::cout << "\nFinding shortest paths from vertex " << source << ":\n";
    p.shortest_path(source);
    
    // Print paths to all other vertices
    for(int i = 0; i < g->get_graph_size(); i++) {
        if(i != source) {
            p.print_path(source, i);
        }
    }
}

/**
 * @brief Main function demonstrating the shortest path implementation
 * @return 0 on successful execution
 */
int main() {
    // Seed random number generator
    srand(time(0));
    
    // Create and demonstrate a graph
    const int GRAPH_SIZE = 6;
    graph* g = new graph(GRAPH_SIZE);
    
    std::cout << "=== Graph Demonstration ===\n";
    demonstrate_graph(GRAPH_SIZE);
    
    std::cout << "\n=== Shortest Paths Demonstration ===\n";
    // Find paths from vertex 0 to all other vertices
    demonstrate_paths(g, 0);
    
    // Clean up
    delete g;
    
    return 0;
} 