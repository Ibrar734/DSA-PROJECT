# DSA Concepts Demonstration

This document provides a clear mapping of Data Structures and Algorithms concepts implemented in the Weather App.

## 1. Hash Map (unordered_map)

### Purpose
Fast storage and retrieval of weather data by city name.

### Implementation Location
- **File**: `WeatherApp.h`
- **Line**: 92 - `unordered_map<string, WeatherData> weatherDatabase;`

### Operations Demonstrated
| Operation | Function | Time Complexity | Menu Option |
|-----------|----------|-----------------|-------------|
| Insert/Update | `addWeatherData()` | O(1) average | Option 1 |
| Lookup | `queryWeather()` | O(1) average | Option 2 |
| Iterate | `displayAllCities()` | O(n) | Option 10 |
| Search | `searchByCondition()` | O(n) | Option 11 |

### Key Features
- Case-sensitive city name keys
- Stores complete WeatherData struct as value
- Efficient for frequent lookups
- No ordering maintained

## 2. Stack (stack)

### Purpose
Track weather update history in Last-In-First-Out (LIFO) order.

### Implementation Location
- **File**: `WeatherApp.h`
- **Line**: 95 - `stack<WeatherData> weatherHistory;`

### Operations Demonstrated
| Operation | Function | Time Complexity | Menu Option |
|-----------|----------|-----------------|-------------|
| Push | `addWeatherData()` (automatic) | O(1) | Option 1 |
| Pop/View | `viewWeatherHistory()` | O(1) per element | Option 3 |
| Peek | View most recent | O(1) | Option 3 |

### Key Features
- Automatically saves old data before updates
- Shows most recent changes first
- Maintains last 10 updates
- Demonstrates LIFO principle

## 3. Priority Queue (priority_queue)

### Purpose
Manage weather alerts sorted by priority level (1=highest, 5=lowest).

### Implementation Location
- **File**: `WeatherApp.h`
- **Line**: 98 - `priority_queue<WeatherAlert> alertQueue;`

### Operations Demonstrated
| Operation | Function | Time Complexity | Menu Option |
|-----------|----------|-----------------|-------------|
| Insert | `addWeatherAlert()` | O(log n) | Option 4 |
| Extract-Max | `displayAlerts()` | O(log n) | Option 5 |
| View Top | Display highest priority | O(1) | Option 5 |

### Key Features
- Custom comparison operator in WeatherAlert struct
- Heap-based implementation (max-heap behavior)
- Priority levels from 1 (critical) to 5 (low)
- Critical alerts displayed first

### Custom Comparator
```cpp
bool operator<(const WeatherAlert& other) const {
    return priority > other.priority; // Inverted for max-heap
}
```

## 4. Queue (queue)

### Purpose
Store weather forecasts in First-In-First-Out (FIFO) chronological order.

### Implementation Location
- **File**: `WeatherApp.h`
- **Line**: 101 - `queue<ForecastData> forecastQueue;`

### Operations Demonstrated
| Operation | Function | Time Complexity | Menu Option |
|-----------|----------|-----------------|-------------|
| Enqueue | `addForecast()` | O(1) | Option 6 |
| Dequeue | Process forecasts | O(1) | Option 7 |
| Front | View next forecast | O(1) | Option 7 |

### Key Features
- Maintains chronological order of forecasts
- FIFO processing ensures temporal sequence
- Each forecast includes date, temperature, condition

## 5. Graph (Adjacency List)

### Purpose
Represent connections between cities with distances.

### Implementation Location
- **File**: `WeatherApp.h`
- **Line**: 104 - `unordered_map<string, CityNode> cityGraph;`

### Implementation Details
```cpp
struct CityNode {
    string cityName;
    vector<pair<string, double>> connections; // city name, distance
};
```

### Operations Demonstrated
| Operation | Function | Time Complexity | Menu Option |
|-----------|----------|-----------------|-------------|
| Add Vertex | `addCityConnection()` | O(1) | Option 9 |
| Add Edge | `addCityConnection()` | O(1) | Option 9 |
| View Edges | `displayCityConnections()` | O(degree) | Option 8 |

### Key Features
- Bidirectional edges (undirected graph)
- Weighted edges (distance in km)
- Adjacency list representation using vectors
- Efficient for sparse graphs

### Graph Structure
```
NewYork --- 5570km --- London
              |
            343km
              |
            Paris --- 9715km --- Tokyo
                                  |
                               7823km
                                  |
                                Sydney
```

## STL Components Used

| STL Container | C++ Header | DSA Concept |
|---------------|------------|-------------|
| `unordered_map` | `<unordered_map>` | Hash Table |
| `stack` | `<stack>` | LIFO Stack |
| `priority_queue` | `<queue>` | Binary Heap |
| `queue` | `<queue>` | FIFO Queue |
| `vector` | `<vector>` | Dynamic Array |

## Time Complexity Summary

| Data Structure | Insert | Delete | Search | Access |
|----------------|--------|--------|--------|--------|
| Hash Map | O(1)* | O(1)* | O(1)* | O(1)* |
| Stack | O(1) | O(1) | O(n) | O(n) |
| Priority Queue | O(log n) | O(log n) | O(n) | O(1) |
| Queue | O(1) | O(1) | O(n) | O(1) |
| Graph (Adj List) | O(1) | O(V) | O(V+E) | O(1) |

*Average case; worst case is O(n) due to hash collisions

## Space Complexity

| Data Structure | Space Complexity |
|----------------|------------------|
| Hash Map | O(n) |
| Stack | O(n) |
| Priority Queue | O(n) |
| Queue | O(n) |
| Graph | O(V + E) |

Where:
- n = number of elements
- V = number of vertices (cities)
- E = number of edges (connections)

## Real-World Applications

### Hash Map
- Database indexing
- Caching systems
- Symbol tables in compilers
- Dictionary implementations

### Stack
- Undo/Redo functionality
- Browser history
- Expression evaluation
- Function call stack

### Priority Queue
- Task scheduling
- Dijkstra's shortest path algorithm
- Huffman coding
- Event-driven simulation

### Queue
- Print job scheduling
- Breadth-first search
- Request handling in servers
- Message queuing systems

### Graph
- Social networks
- Road networks
- Network routing
- Recommendation systems

## Learning Outcomes

By studying this project, you will learn:

1. **Practical DSA Usage**: How to choose the right data structure for specific problems
2. **STL Mastery**: Using C++ Standard Template Library effectively
3. **Time/Space Trade-offs**: Understanding when to optimize for speed vs. memory
4. **Object-Oriented Design**: Structuring a menu-driven application
5. **Real-World Modeling**: Representing real-world entities with data structures

## Advanced Concepts (Future Extensions)

Potential enhancements demonstrating more DSA concepts:

1. **Binary Search Tree**: Maintain cities in sorted order
2. **Trie**: Fast prefix-based city name search
3. **Dijkstra's Algorithm**: Find shortest path between cities
4. **Min-Max Heap**: Track both coldest and hottest cities
5. **Bloom Filter**: Quick negative lookup for city existence
6. **LRU Cache**: Cache frequently queried cities
7. **Union-Find**: Group cities by weather regions
8. **Segment Tree**: Range queries for temperature statistics

## Conclusion

This Weather App successfully demonstrates five fundamental data structures:
- **Hash Map**: Fast lookups
- **Stack**: History tracking
- **Priority Queue**: Priority-based alerts
- **Queue**: Sequential forecasts
- **Graph**: City networks

Each structure is chosen for its specific strengths and real-world applicability.