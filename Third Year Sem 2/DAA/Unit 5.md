# Unit 5

## Approximation Algorithm

* An approximation algorithm is a way of dealing with NP-completeness for an optimization problem.

* This technique does not guarantee the best solution

* The goal of the approximation algorithm is to come as close as possible to the optimal solution in polynomial time. Such algorithms are called approximation algorithms or heuristic algorithms

* An approximation algorithm has a performance ratio that measures how close the solution is to the optimal one

* Depending on the problem, we may define an optimal solution as one with maximum possible cost or one with minimum possible cost,i.e, the problem can either be a maximization or minimization problem

* Examples

    1. The Vertex Cover Problem – In the vertex cover problem, the optimization problem is to find the vertex cover with the fewest vertices, and the approximation problem is to find the vertex cover with few vertices

    2. Travelling Salesman Problem – In the traveling salesperson problem, the optimization problem is to find the shortest cycle, and the approximation problem is to find a short cycle

    3. The Set Covering Problem – This is an optimization problem that models many problems that require resources to be allocated. Here, a logarithmic approximation ratio is used

    4. The Subset Sum Problem – In the Subset sum problem, the optimization problem is to find a subset of {x1,×2,×3…xn} whose sum is as large as possible but not larger than the target value t

* Let's go deep into **vertex cover** problem

    1. Vertex Cover Problem is a known NP Complete problem, i.e., there is no polynomial-time solution for this unless P = NP

    2. Consider all the subset of vertices one by one and find out whether it covers all edges of the graph. For eg. in a graph consisting only 3 vertices the set consisting of the combination of vertices are:{0,1,2,{0,1},{0,2},{1,2},{0,1,2}}

    3. Approximate Algorithm for Vertex Cover

        1) Initialize the result as {}
        2) Consider a set of all edges in given graph.  Let the set be E.
        3) Do following while E is not empty

                a) Pick an arbitrary edge (u, v) from set E and add 'u' and 'v' to result
                b) Remove all edges from E which are either incident on u or v.
        4) Return result

![IMG](./Images/vertex%20cover.png)

* Terms of approximation algo

    1. C --> Cost of Solution

    2. C* --> Cost of optimal solution

    3. P(n) --> approximation ratio

    4. n --> i/p size

* Problem

![IMG](./Images/vertex%20prb.png)

        E = { (c,d), (b,c), (a,b) }

        C = fi

        C = fi U {b,c}

        furthur

        (b,c) U (e,f)

        {b,c,e,f} U {d, g }

        {b,c,e,f,d,g}

## Approximation Algorithm for Travelling Salesman Problem

* Travelling Salesman Probelm and an approximation algorithm named 2 approximation algorithm, that uses Minimum Spanning Tree in order to obtain an approximate path

* TSP *"Given a set of cities and distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point."*

* The approximate algorithms for TSP works only if the problem instance satisfies Triangle-Inequality

* Most of the times in Naive & dynamic we are using intermediate vertices inorder to move from one vertex to the other to minimize the cost of the path

* *"The least distant path to reach a vertex j from i is always to reach j directly from i, rather than through some other vertex k (or vertices)"*

        dis(i, j) <= dis(i, k) + dist(k, j)

* dis(a,b) = diatance between a & b, i.e. the edge weight

* When the cost function satisfies the triangle inequality, we may design an approximate algorithm for the Travelling Salesman Problem that returns a tour whose cost is never more than twice the cost of an optimal tour. The idea is to use Minimum Spanning Tree (MST)

### The Algorithm

1. Let 0 be the starting and ending point for salesman.
2. Construct Minimum Spanning Tree from with 0 as root using Prim’s Algorithm.
3. List vertices visited in preorder walk/Depth First Search of the constructed MST and add source node at the end

Note: The cost of best possible Travelling Salesman tour is never less than the cost of MST

### Approach

1. Constructing The Minimum Spanning Tree

        1. Creating a set mstSet that keeps track of vertices already included in MST.
        2. Assigning a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign key value as 0 for the first vertex so that it is picked first.
        3. [The Loop] While mstSet doesn’t include all vertices

2. Getting the preorder walk/ Defth first search walk

        1. Getting the preorder walk/ Defth first search walk
        2. Constructing an adjacency matrix where graph[i][j] = 1 means both i & j are having a direct edge and included in the MST

3. Final Code

```cpp

#include <bits/stdc++.h>
using namespace std;
 
// Number of vertices in the graph 
#define V 5 

// Dynamic array to store the final answer
vector<int> final_ans;

int minimum_key(int key[], bool mstSet[]) 
{ 
    int min = INT_MAX, min_index; 
 
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
 
    return min_index; 
} 
 
vector<vector<int>> MST(int parent[], int graph[V][V]) 
{ 
    vector<vector<int>> v;
    for (int i = 1; i < V; i++) 
    {
        vector<int> p;
        p.push_back(parent[i]);
        p.push_back(i);
        v.push_back(p);
        p.clear();
    }
    return v;  
} 
 
// getting the Minimum Spanning Tree from the given graph
// using Prim's Algorithm
vector<vector<int>> primMST(int graph[V][V]) 
{ 
    int parent[V]; 
    int key[V];

    // to keep track of vertices already in MST 
    bool mstSet[V]; 

    // initializing key value to INFINITE & false for all mstSet
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 

    // picking up the first vertex and assigning it to 0
    key[0] = 0; 
    parent[0] = -1; 

    // The Loop
    for (int count = 0; count < V - 1; count++)
    { 
        // checking and updating values wrt minimum key
        int u = minimum_key(key, mstSet); 
        mstSet[u] = true; 
        for (int v = 0; v < V; v++) 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
    vector<vector<int>> v;
    v = MST(parent, graph);
    return v; 
} 

// getting the preorder walk of the MST using DFS
void DFS(int** edges_list,int num_nodes,int starting_vertex,bool* visited_nodes)
{
    // adding the node to final answer
    final_ans.push_back(starting_vertex);

    // checking the visited status 
    visited_nodes[starting_vertex] = true;

    // using a recursive call
    for(int i=0;i<num_nodes;i++)
    {
        if(i==starting_vertex)
        {
            continue;
        }
        if(edges_list[starting_vertex][i]==1)
        {
            if(visited_nodes[i])
            {
                continue;
            }
            DFS(edges_list,num_nodes,i,visited_nodes);
        }
    }
}
int main() 
{ 
    // initial graph
    int graph[V][V] = { { 0, 10, 18, 40, 20 }, 
                        { 10, 0, 35, 15, 12 }, 
                        { 18, 35, 0, 25, 25 }, 
                        { 40, 15, 25, 0, 30 },
                        { 20, 13, 25, 30, 0 } }; 
 
    vector<vector<int>> v;

    // getting the output as MST 
    v = primMST(graph);

    // creating a dynamic matrix
    int** edges_list = new int*[V];
    for(int i=0;i<V;i++)
    {
        edges_list[i] = new int[V];
        for(int j=0;j<V;j++)
        {
            edges_list[i][j] = 0;
        }
    }

    // setting up MST as adjacency matrix
    for(int i=0;i<v.size();i++)
    {
        int first_node = v[i][0];
        int second_node = v[i][1];
        edges_list[first_node][second_node] = 1;
        edges_list[second_node][first_node] = 1;
    }

    // a checker function for the DFS
    bool* visited_nodes = new bool[V];
    for(int i=0;i<V;i++)
    {
        bool visited_node;
        visited_nodes[i] = false;
    }

    //performing DFS
    DFS(edges_list,V,0,visited_nodes);

    // adding the source node to the path
    final_ans.push_back(final_ans[0]);

    // printing the path
    for(int i=0;i<final_ans.size();i++)
    {
        cout << final_ans[i] << "-";
    }
    return 0; 
} 
```

### Steps

1. Let's have a look at the graph(adjacency matrix) given as input

   ![IMG](./Images/tsp%201.png)

2. After performing step-1, we will get a Minimum spanning tree as below,

   ![IMG](./Images/tsp%202.png)

3. Performing DFS, we can get something like this

   ![IMG](./Images/tsp%203.png)

4. Final step, connecting DFS nodes and the source node

   ![IMG](./Images/tsp%204.png)

### Complexity Analysis

* The time complexity for obtaining MST from the given graph is O(V^2) where V is the number of nodes.

* The worst case space complexity for the same is O(V^2), as we are constructing a vector data structure to store the final MST

## Approximating MaxCliqueConcept of randomized algorithms

* Max Clique is the problem of finding the largest subset of vertices in a graph such that every pair of vertices in the subset is connected by an edge

* A clique is a complete subgraph of a graph, meaning that every vertex in the subgraph is adjacent to every other vertex

* A maximal clique is a clique that cannot be extended by adding one more adjacent vertex, meaning it is not a subset of a larger clique

* For example, in the following graph, the red vertices form a maximal clique of size 4, which is also the maximum clique of the graph

### Randomized Algorithm for it

* Randomized Algorithms are algorithms that use random numbers to decide what to do next anywhere in their logic

* For example, in Randomized Quick Sort, we use a random number to pick the next pivot (or we randomly shuffle the array)

* Typically, this randomness is used to reduce time complexity or space complexity in other standard algorithms

* There are different ways to design randomized algorithms for the max clique problem, depending on the trade-off between running time, accuracy and complexity

* For example, one simple randomized algorithm is to pick a random vertex and add it to the current clique if it is adjacent to all the vertices in the clique, and repeat this process until no more vertices can be added

* This algorithm can find a maximal clique (a clique that cannot be extended by adding one more adjacent vertex) in linear time, but it may not find the maximum clique

* Another example of a randomized algorithm for the max clique problem is based on the reduction from the Boolean satisfiability problem (SAT), which is an NP-complete problem.

## Randomized Quick Sort

* Randomized quicksort algorithm is a sorting algorithm that uses random numbers to decide what element to use as a pivot in each partition step

* A pivot is an element that divides the array into two subarrays, such that all elements to the left of the pivot are smaller or equal to the pivot, and all elements to the right of the pivot are larger or equal to the pivot

* The algorithm then recursively sorts the left and right subarrays until the whole array is sorted

* The advantage of using random numbers to choose the pivot is that it avoids the worst-case scenario of picking a very small or very large element as the pivot, which would result in an unbalanced partition and a high time complexity of O (n 2)

### Different ways to implement randomized quicksort

1. Randomly picking an element from the array and swapping it with the last element, then using the last element as the pivot (Lomuto partition scheme)

2. Randomly picking an element from the array and swapping it with the first element, then using the first element as the pivot (Hoare partition scheme)

3. Randomly shuffling the array before applying the standard quicksort algorithm

## Natural Algorithms–Evolutionary Computing and Evolutionary Algorithms

### Natural Algorithms–Evolutionary Computing

1. Natural Algorithms–Evolutionary Computing is a term that refers to a branch of natural computing that uses computational algorithms inspired by biological evolution

2. Evolutionary computing is a family of algorithms for global optimization that mimic the processes of natural selection and mutation

3. In evolutionary computing, an initial population of candidate solutions is generated and iteratively updated by applying genetic operators such as crossover and mutation

4. Each new generation is evaluated by a fitness function that measures how well the solutions fit the problem

5. The fittest solutions are more likely to survive and reproduce, while the less fit ones are more likely to be eliminated. As a result, the population evolves towards better solutions over time

* Evolutionary computing is a subfield of artificial intelligence and soft computing that studies these algorithms and their applications in various domains. Evolutionary computing includes different variants and extensions, such as

        Genetic algorithms: A type of evolutionary algorithm that uses binary strings to represent solutions and applies bitwise operators for crossover and mutation

        Genetic programming: A type of evolutionary algorithm that uses computer programs (usually in the form of trees) to represent solutions and applies syntactic operators for crossover and mutation

        Evolution strategies: A type of evolutionary algorithm that uses real-valued vectors to represent solutions and applies Gaussian perturbations for mutation

        Differential evolution: A type of evolutionary algorithm that uses real-valued vectors to represent solutions and applies arithmetic operators for crossover and mutation

        Particle swarm optimization: A type of evolutionary algorithm that uses real-valued vectors to represent solutions and updates them by following the best solution in their neighborhood or in the whole population

        Ant colony optimization: A type of evolutionary algorithm that uses artificial ants to construct solutions by following pheromone trails left by previous ants

## Evolutionary Algorithms

* Evolutionary Algorithms are a family of algorithms for global optimization that mimic the processes of biological evolution

* In evolutionary algorithms, an initial population of candidate solutions is generated and iteratively updated by applying genetic operators such as crossover and mutation

* Each new generation is evaluated by a fitness function that measures how well the solutions fit the problem. The fittest solutions are more likely to survive and reproduce, while the less fit ones are more likely to be eliminated

* Evolutionary algorithms can be used to solve problems that cannot be easily solved in polynomial time, such as NP-hard problems, or problems that require exploring a large and complex search space

* Evolutionary algorithms are a subset of evolutionary computation, which is a branch of natural computing that uses computational algorithms inspired by natural systems and phenomena

* Examples

        Genetic algorithms: A type of evolutionary algorithm that uses binary strings to represent solutions and applies bitwise operators for crossover and mutation

        Genetic programming: A type of evolutionary algorithm that uses computer programs (usually in the form of trees) to represent solutions and applies syntactic operators for crossover and mutation

        Evolution strategies: A type of evolutionary algorithm that uses real-valued vectors to represent solutions and applies Gaussian perturbations for mutation

        Ant colony optimization: A type of evolutionary algorithm that uses artificial ants to construct solutions by following pheromone trails left by previous ants

## Intro to Genetic Algorithms

* Genetic Algorithms(GAs) are adaptive heuristic search algorithms that belong to the larger part of evolutionary algorithms

* Genetic algorithms are based on the ideas of natural selection and genetics

* These are intelligent exploitation of random search provided with historical data to direct the search into the region of better performance in solution space

* Genetic algorithms simulate the process of natural selection

* Analogy of Genetic Algorithm

        1. Individual in population compete for resources and mate 
        2. Those individuals who are successful (fittest) then mate to create more offspring than others
        3. Genes from “fittest” parent propagate throughout the generation, that is sometimes parents create offspring which is better than either parent.
        4.Thus each successive generation is more suited for their environment

* Search space

        1. Each individual represents a solution in search space for given problem.

        2. Each individual is coded as a finite length vector (analogous to chromosome) of components

        3. These variable components are analogous to Genes. Thus a chromosome (individual) is composed of several genes (variable components)

  ![IMG](./Images/genetic%201.png)

* Fitness Score

        It is given to each individual which shows the ability of an individual to “compete”

        The GAs maintains the population of n individuals (chromosome/solutions) along with their fitness scores.

        The individuals having better fitness scores are given more chance to reproduce than others.

* Operators of Genetic Algorithms

        1. Selection Operator: The idea is to give preference to the individuals with good fitness scores and allow them to pass their genes to successive generations.

        2. Crossover Operator: This represents mating between individuals. Two individuals are selected using selection operator and crossover sites are chosen randomly. Then the genes at these crossover sites are exchanged thus creating a completely new individual (offspring)

        3. Mutation Operator: The key idea is to insert random genes in offspring to maintain the diversity in the population to avoid premature convergence

* Summary of genetic algorithms

        1) Randomly initialize populations p
        2) Determine fitness of population
        3) Until convergence repeat:
            a) Select parents from population
            b) Crossover and generate new population
            c) Perform mutation on new population
            d) Calculate fitness for new population

## Simulated annealing

* It is a probabilistic technique for approximating the global optimum of a given function. Specifically, it is a metaheuristic to approximate global optimization in a large search space for an optimization problem

* It is often used when the search space is discrete (for example the traveling salesman problem, the boolean satisfiability problem, protein structure prediction, and job-shop scheduling)

* Simulated annealing is inspired by annealing in metallurgy where metal is heated to a high temperature quickly, then cooled slowly, which increases its strength and makes it easier to work with

* The solution is perturbed by making a random change to it, and the resulting new solution is evaluated using an objective function. If the new solution is better (i.e., has a lower cost), it is accepted as the new current solution

* If the new solution is worse (i.e., has a higher cost), it may still be accepted with a probability that depends on the temperature and the degree of worsening
