# Quick Start Guide

## Build & Run

```bash
# Compile
make

# Run
./weather_app

# Clean
make clean
```

## Quick Test

```bash
# Run with make
make run
```

## Menu Overview

```
1.  Add/Update Weather Data      → Hash Map (O(1))
2.  Query Weather by City        → Hash Map Lookup
3.  View Weather History         → Stack (LIFO)
4.  Add Weather Alert            → Priority Queue Insert
5.  Display Weather Alerts       → Priority Queue (sorted)
6.  Add Forecast                 → Queue Enqueue
7.  Display Forecasts            → Queue (FIFO)
8.  Display City Connections     → Graph Traversal
9.  Add City Connection          → Graph Add Edge
10. Display All Cities           → Hash Map Iteration
11. Search by Weather Condition  → Linear Search
0.  Exit
```

## Pre-loaded Sample Data

**Cities:** NewYork, London, Tokyo, Paris, Sydney

**Try these commands:**
- Enter `2`, then `NewYork` to see weather
- Enter `5` to see priority-sorted alerts
- Enter `7` to see forecast queue
- Enter `8`, then `NewYork` to see graph connections
- Enter `11`, then `Sunny` to search cities

## Files

- `WeatherApp.h` - All DSA implementations
- `main.cpp` - Menu interface
- `README.md` - Full documentation
- `USAGE_EXAMPLES.md` - Detailed examples
- `DSA_CONCEPTS.md` - Technical deep-dive

## DSA Concepts

✅ **Hash Map**: Fast weather lookups  
✅ **Stack**: Weather history tracking  
✅ **Priority Queue**: Alert prioritization  
✅ **Queue**: Chronological forecasts  
✅ **Graph**: City network connections  
