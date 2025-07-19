#include "path.hpp"
#include <climits>
#include <vector>
#include <iostream>

path::path(graph* g, queue* q) {
    gr = g;
    qu = q;
    dist = new int[gr->get_graph_size()];
    pred = new int[gr->get_graph_size()];
}

path::~path() {
    delete[] dist;
    delete[] pred;
}

void path::shortest_path(int src) {
    // Initialize distances and predecessors
    for(int i = 0; i < gr->get_graph_size(); i++) {
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    dist[src] = 0;
    
    // Add source to priority queue
    qu->prepend_priority(src, 0);
    
    while(qu->priority_size() > 0) {
        // Get node with minimum distance
        int u = qu->priority_min_node();
        int u_dist = qu->get_priority_priority();
        qu->remove_first_priority();
        qu->prepend_visited(u, u_dist);
        
        // Get neighbors of current node
        int* neighbors = gr->neghibours(u);
        
        // Process all neighbors
        for(int i = 0; i < gr->get_graph_size(); i++) {
            if(neighbors[i] != -1) {  // If i is a neighbor
                int v = i;
                int weight = gr->get_edge_value(u, v);
                
                // Relaxation step
                if(!qu->is_visited(v) && dist[u] != INT_MAX && 
                   dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pred[v] = u;
                    
                    // Update priority queue
                    if(qu->not_in_queue(v)) {
                        qu->prepend_priority(v, dist[v]);
                    } else {
                        qu->update_priority(v, dist[v]);
                    }
                }
            }
        }
        delete[] neighbors;  // Clean up neighbors array
        qu->sort_by_priority();
    }
}

void path::print_path(int src, int dest) {
    if(dist[dest] == INT_MAX) {
        std::cout << "No path exists from " << src << " to " << dest << std::endl;
        return;
    }
    
    std::vector<int> path;
    int current = dest;
    
    // Build path by following predecessors
    while(current != -1) {
        path.push_back(current);
        current = pred[current];
    }
    
    // Print path and distance
    std::cout << "Shortest path from " << src << " to " << dest 
              << " (distance = " << dist[dest] << "): ";
    for(int i = path.size() - 1; i >= 0; i--) {
        std::cout << path[i];
        if(i > 0) std::cout << " -> ";
    }
    std::cout << std::endl;
}

int path::get_distance(int dest) {
    return dist[dest];
} 