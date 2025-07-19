# Dijkstra's Shortest Path Algorithm Implementation

This project implements Dijkstra's shortest path algorithm in C++. It includes a weighted graph implementation using adjacency matrices and demonstrates finding shortest paths between vertices in randomly generated connected graphs.

## Implementation Details

### Graph Class
- Uses two matrices: boolean for connections and integer for weights.
- Generates random connected graphs with weights between 1-10.
- Includes methods for graph manipulation and connectivity checking.

### Queue Class
- Implements a priority queue using linked lists.
- Maintains separate lists for visited nodes and priority queue.
- Includes methods for queue operations and priority management.

### Path Class
- Implements Dijkstra's shortest path algorithm.
- Uses graph and queue objects.
- Maintains distance and predecessor arrays.
- Reconstructs and displays shortest paths.

## Project Structure

```
.
├── graph.hpp       # Graph class declaration
├── graph.cpp       # Graph class implementation
├── queue.hpp       # Priority queue class declaration
├── queue.cpp       # Priority queue class 
├── path.hpp        # Shortest path class declaration
├── path.cpp        # Shortest path class implementation
└── main.cpp        # Main program and demonstrations
```

## Features

### Graph Implementation
- **`prob()`**: Generates a random boolean with a 60% chance of returning 1.
- **`is_connected()`**: Checks if the graph is connected.
- **`graph()`**: Default constructor that allocates memory for the two matrices (weights, connection).
- **`graph(int s)`**: Constructor to allocate s*s for the two matrices and gives the connection matrix random connections. If two nodes are connected, it assigns a random weight from 1 to 10; if no connection, it assigns a weight of 0. This process repeats until the generated graph is connected.
- **`~graph()`**: Destructor to delete both matrices.
- **`std::ostream& operator<<(std::ostream& out, const graph& gr)`**: When using the << operator with the graph, it prints the two matrices.
- **`get_graph_size()`**: Gets the graph size.
- **`get_number_of_connected_nodes()`**: Returns the number of edges.
- **`adjacent()`**: Makes two nodes adjacent.
- **`neghibours(int n)`**: Returns the neighbors of a node.
- **`add_edge(int n1, int n2)`**: Adds an edge between two nodes with a random weight from 1 to 10.
- **`delete_edge(int n1, int n2)`**: Removes an edge between two nodes.
- **`get_edge_value(int n1, int n2)`**: Gets the edge weight value.
- **`set_edge_value(int n1, int n2, int v)`**: Sets the edge weight value manually.

### Priority Queue
- Has two lists: one for visited vertices and the other for unvisited vertices sorted by priority.
- **`prepend_priority(int n, int p)`**: Prepends to the priority list the node n with the distance to source p.
- **`prepend_visited(int n, int p)`**: Prepends to the visited list the node n with the distance to source p.
- **`priority_size()`**: Gets the number of elements in the priority list.
- **`sorted()`**: Checks if the priority list is sorted.
- **`sort_by_priority()`**: Goes through the queue and swaps values (not nodes) because it is easier to manipulate values than swapping addresses (nodes) until the priority list is sorted.
- **`remove_first_priority()`**: Removes the first node from the priority list.
- **`priority_min_node()`**: Gets the node with the minimal distance.
- **`get_visited_priority()`**: Gets the visited vertex distance to source.
- **`get_priority_priority()`**: Gets the priority vertex distance to source.
- **`not_in_queue(int n)`**: Checks if a node is in the priority queue.
- **`is_visited(int n)`**: Checks if a node is visited or not.
- **`node_priority(int n)`**: Checks the node priority.
- **`update_priority(int n, int p)`**: Updates the node distance to source and sorts the queue again.
- **`ostream& operator<<(std::ostream& out, queue& q)`**: Prints the visited and priority lists when using <<.

### Shortest Path Finding using Dijkstra's Algorithm
- **`path(graph* g, queue* q)`**: Constructor to create queue, graph, distance, and predecessor objects.
- **`shortest_path(int src)`**: Method to compute the shortest path using Dijkstra's Algorithm. 
  - First, initializes the queue with the source node.
  - Processes queue elements until the priority queue is empty.
  - For the first iteration, removes the source from the priority queue, adds it to the visited queue, and searches for its neighbors.
  - For the neighbors, gets edge values and updates the distance array with the minimal distance following Dijkstra's algorithm.
  - Prepends or updates neighbors based on whether they exist in the queue.
  - For subsequent iterations, gets the minimal node, removes it from the queue, adds it to the visited list, searches for its neighbors, and repeats the process until all nodes are visited.
- **`print_path(int src, int dest)`**: Prints the path from source to destination.

## Requirements

- C++ compiler (g++ recommended)
- Standard Template Library (STL)

## Building the Project

To compile the project, run:

```bash
g++ -Wall -o dijkstra main.cpp graph.cpp queue.cpp path.cpp
```

## Usage

Run the compiled program:

```bash
./dijkstra
```

The program will:
1. Create a random connected graph.
2. Display the adjacency and weight matrices.
3. Find shortest paths from vertex 0 to all other vertices.
4. Display the paths and their total distances.

## Example Output

```
=== Graph Demonstration ===
Created a random connected graph with 6 vertices
Adjacency matrix (left) and weight matrix (right):
0  1  0  1  1  0                        0   3   0   6   8   0   
1  0  1  1  1  1                        3   0   1   2   9   2   
0  1  0  0  0  0                        0   1   0   0   0   0   
1  1  0  0  1  0                        6   2   0   0   9   0   
1  1  0  1  0  0                        8   9   0   9   0   0   
0  1  0  0  0  0                        0   2   0   0   0   0   

Number of edges: 8
Graph is connected

=== Shortest Paths Demonstration ===
Finding shortest paths from vertex 0:
Shortest path from 0 to 1 (distance = 3): 0 -> 1
Shortest path from 0 to 2 (distance = 4): 0 -> 1 -> 2
Shortest path from 0 to 3 (distance = 5): 0 -> 1 -> 3
Shortest path from 0 to 4 (distance = 8): 0 -> 4
Shortest path from 0 to 5 (distance = 5): 0 -> 1 -> 5
```