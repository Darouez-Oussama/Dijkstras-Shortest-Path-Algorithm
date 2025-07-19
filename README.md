# Dijkstra's Shortest Path Algorithm Implementation

This project implements Dijkstra's shortest path algorithm in C++. It includes a weighted graph implementation using adjacency matrices and demonstrates finding shortest paths between vertices in randomly generated connected graphs.

## Project Structure

```
.
├── graph.hpp       # Graph class declaration
├── graph.cpp       # Graph class implementation
├── queue.hpp       # Priority queue class declaration
├── queue.cpp       # Priority queue class implementation
├── path.hpp        # Shortest path class declaration
├── path.cpp        # Shortest path class implementation
└── main.cpp        # Main program and demonstrations
```

## Features

- **Graph Implementation**
  - prob() : generates a random boolean with 60% chance of getting 1 more 
  - is_connected() : checks if the graph is connected 
  - graph() : default constructer that allocate memory for the 2 matrices (weights , conncetion)
  - graph(int s ) : constructor to allocate s*s for the 2 matrices and gives the connection matrix random connections and if 2 nodes are connected it give to tat connection random weight from 1 to 10 if no connrction we give 0 weight we do this process until the generated graph is connected 
  - ~ graph (): deconstructor to delete both matrices 
  - std::ostream& operator<<(std::ostream& out, const graph& gr) : when using the operator << with the graph we print the 2 matrices 
  - get_graph_size() : get graph size 
  - get_number_of_connected_nodes()
  - adjacent() : makes two nodes adjacent 
  - neghibours(int n) : return the neighbours of a node 
  - add_edge(int n1, int n2) : adds an edge between 2 nodes with its random weight from 1 to 10 
  - delete_edge(int n1, int n2)
  - get_edge_value(int n1, int n2) : get edge weight value 
  - set_edge_value(int n1, int n2, int v) : set edge weight value manually 

- **Priority Queue**
  - prepend(char * c ) : preappends data 
  - std::ostream& operator<<(std::ostream& out , const slist& a) : print the priority queu using <<
  - ~slist() : destructor of the priority queue 
  - Custom implementation using linked lists
  - Maintains visited nodes and distances
  - Priority-based node selection

- **Shortest Path Finding**
  - Implements Dijkstra's algorithm
  - Finds shortest paths from a source vertex
  - Displays paths and distances
  - Handles unreachable nodes

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
1. Create a random connected graph
2. Display the adjacency and weight matrices
3. Find shortest paths from vertex 0 to all other vertices
4. Display the paths and their total distances

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

## Implementation Details

### Graph Class
- Uses two matrices: boolean for connections and integer for weights
- Generates random connected graphs with weights between 1-10
- Includes methods for graph manipulation and connectivity checking

### Queue Class
- Implements a priority queue using linked lists
- Maintains separate lists for visited nodes and priority queue
- Includes methods for queue operations and priority management

### Path Class
- Implements Dijkstra's shortest path algorithm
- Uses graph and queue objects
- Maintains distance and predecessor arrays
- Reconstructs and displays shortest paths
