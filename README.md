# Weather App - DSA Project in C++

A comprehensive weather application demonstrating various Data Structures and Algorithms (DSA) concepts implemented in C++.

## Overview

This project is a menu-driven console application that manages weather data for multiple cities while showcasing the following DSA concepts:

### Data Structures Implemented:

1. **Hash Map (unordered_map)** - For efficient weather data storage and retrieval by city name
2. **Stack** - For maintaining weather history (Last-In-First-Out)
3. **Priority Queue** - For managing weather alerts based on priority levels
4. **Queue** - For storing and displaying weather forecasts (First-In-First-Out)
5. **Graph** - For representing connections between cities with distances

## Features

### 1. Weather Data Management (Hash Map)
- Add/Update weather data for cities
- Query current weather by city name
- O(1) average time complexity for lookups

### 2. Weather History Tracking (Stack)
- View past weather updates
- Most recent changes displayed first
- Maintains last 10 weather updates

### 3. Weather Alerts System (Priority Queue)
- Add weather alerts with priority levels (1-5)
- Display alerts in priority order
- Critical alerts shown first

### 4. Weather Forecast (Queue)
- Add forecast data for future dates
- Display forecasts in chronological order
- FIFO processing of forecast information

### 5. City Network (Graph)
- Connect cities with distances
- View neighboring cities
- Bidirectional connections

### 6. Search Functionality
- Search cities by weather condition
- Display all cities in database

## Project Structure

```
DSA-PROJECT/
├── WeatherApp.h    # Header file with all DSA implementations
├── main.cpp        # Main program with menu interface
├── Makefile        # Build configuration
└── README.md       # Documentation
```

## Requirements

- C++ compiler with C++11 support (g++, clang++, etc.)
- Make (optional, for using Makefile)

## Compilation

### Using Makefile:
```bash
make
```

### Manual Compilation:
```bash
g++ -std=c++11 -Wall -Wextra main.cpp -o weather_app
```

## Running the Application

### Using Makefile:
```bash
make run
```

### Direct Execution:
```bash
./weather_app
```

## Usage

The application provides an interactive menu with the following options:

```
1.  Add/Update Weather Data (Hash Map)
2.  Query Weather by City (Hash Map)
3.  View Weather History (Stack)
4.  Add Weather Alert (Priority Queue)
5.  Display Weather Alerts (Priority Queue)
6.  Add Forecast (Queue)
7.  Display Forecasts (Queue)
8.  Display City Connections (Graph)
9.  Add City Connection (Graph)
10. Display All Cities
11. Search Cities by Weather Condition
0.  Exit
```

## Sample Data

The application comes pre-loaded with sample data for demonstration:

**Cities:**
- New York (22.5°C, Sunny)
- London (15.0°C, Cloudy)
- Tokyo (25.0°C, Partly Cloudy)
- Paris (18.0°C, Rainy)
- Sydney (28.0°C, Sunny)

**City Connections:**
- New York ↔ London (5570 km)
- London ↔ Paris (343 km)
- Paris ↔ Tokyo (9715 km)
- Tokyo ↔ Sydney (7823 km)

**Weather Alerts:**
- New York: Heat Wave (Priority 2)
- London: Storm Warning (Priority 1)

**Forecasts:**
- New York: Tomorrow (24.0°C, Sunny)
- New York: Day After (23.5°C, Partly Cloudy)
- London: Tomorrow (14.0°C, Rainy)

## DSA Concepts Explained

### 1. Hash Map (unordered_map)
- **Use Case**: Store and retrieve weather data by city name
- **Time Complexity**: O(1) average for insert, delete, and search operations
- **Why Used**: Fast lookups when searching for weather data by city name

### 2. Stack
- **Use Case**: Maintain weather update history
- **Time Complexity**: O(1) for push and pop operations
- **Why Used**: LIFO behavior is perfect for showing recent history first

### 3. Priority Queue
- **Use Case**: Manage weather alerts by priority
- **Time Complexity**: O(log n) for insertion, O(1) for accessing highest priority
- **Why Used**: Critical alerts need to be processed before lower priority ones

### 4. Queue
- **Use Case**: Store weather forecasts chronologically
- **Time Complexity**: O(1) for enqueue and dequeue operations
- **Why Used**: FIFO behavior maintains chronological order of forecasts

### 5. Graph
- **Use Case**: Represent city connections and distances
- **Implementation**: Adjacency list using unordered_map
- **Why Used**: Models real-world geographic relationships between cities

## Example Workflow

1. **Start the application** - Sample data is automatically loaded
2. **Query weather** (Option 2) - Check current weather for any city
3. **Add new weather data** (Option 1) - Update weather for a city
4. **View history** (Option 3) - See previous weather states
5. **Add alert** (Option 4) - Create a high-priority weather alert
6. **Display alerts** (Option 5) - View all alerts by priority
7. **Add forecast** (Option 6) - Add future weather predictions
8. **View forecasts** (Option 7) - See all forecasts
9. **Check connections** (Option 8) - View neighboring cities
10. **Search by condition** (Option 11) - Find all sunny cities

## Clean Up

```bash
make clean
```

## Learning Objectives

This project demonstrates:
- Practical applications of common data structures
- Menu-driven program design
- Object-oriented programming in C++
- Standard Template Library (STL) usage
- Real-world problem-solving with DSA

## Future Enhancements

Possible extensions to this project:
- Implement graph algorithms (Dijkstra's for shortest path between cities)
- Add binary search tree for sorted city names
- Implement linked list for detailed forecast timelines
- Add file I/O for persistent data storage
- Implement more complex weather pattern analysis

## Author

DSA Project - Weather Application

## License

This project is created for educational purposes to demonstrate DSA concepts.