# Weather App - Usage Examples

This document provides step-by-step examples of using the Weather App.

## Compilation and Running

### Compile the application:
```bash
make
```

### Run the application:
```bash
./weather_app
```

Or use:
```bash
make run
```

## Example Usage Scenarios

### Scenario 1: Query Weather for a City

1. Run the application
2. Select option `2` (Query Weather by City)
3. Enter city name: `NewYork`
4. Output shows:
   ```
   --- Weather Information ---
   City: NewYork
   Temperature: 22.5°C
   Humidity: 65%
   Condition: Sunny
   Last Updated: [timestamp]
   ```

### Scenario 2: Add New Weather Data

1. Select option `1` (Add/Update Weather Data)
2. Enter city name: `Mumbai`
3. Enter temperature: `32.5`
4. Enter humidity: `75`
5. Enter condition: `Humid`
6. System confirms: "Weather data updated for Mumbai"

### Scenario 3: View Weather Alerts (Priority Queue Demo)

1. Select option `5` (Display Weather Alerts)
2. System shows alerts in priority order:
   ```
   *** ALERT [Priority 1] ***
   City: London
   Type: Storm Warning
   Message: Severe storm approaching
   
   *** ALERT [Priority 2] ***
   City: NewYork
   Type: Heat Wave
   Message: High temperature expected
   ```

### Scenario 4: View Weather History (Stack Demo)

1. Update weather for a city (option 1)
2. Select option `3` (View Weather History)
3. System shows previous weather states in LIFO order
4. Most recent change appears first

### Scenario 5: View Forecasts (Queue Demo)

1. Select option `7` (Display Forecasts)
2. System shows forecasts in FIFO order:
   ```
   === Weather Forecasts ===
   City: NewYork | Tomorrow | 24.0°C | Sunny
   City: NewYork | Day After | 23.5°C | Partly Cloudy
   City: London | Tomorrow | 14.0°C | Rainy
   ```

### Scenario 6: View City Connections (Graph Demo)

1. Select option `8` (Display City Connections)
2. Enter city name: `NewYork`
3. System shows connected cities:
   ```
   === Connections for NewYork ===
   NewYork <-> London (Distance: 5570 km)
   ```

### Scenario 7: Search Cities by Weather Condition

1. Select option `11` (Search Cities by Weather Condition)
2. Enter condition: `Sunny`
3. System shows all cities with sunny weather:
   ```
   === Cities with condition: Sunny ===
   - NewYork (22.5°C)
   - Sydney (28.0°C)
   ```

### Scenario 8: Add a New Weather Alert

1. Select option `4` (Add Weather Alert)
2. Enter city name: `Tokyo`
3. Enter alert type: `Typhoon Warning`
4. Enter priority: `1` (highest priority)
5. Enter message: `Typhoon approaching from the Pacific`
6. System confirms: "Weather alert added for Tokyo"

### Scenario 9: Add a Forecast

1. Select option `6` (Add Forecast)
2. Enter city name: `Paris`
3. Enter date: `Next Week`
4. Enter temperature: `16.0`
5. Enter condition: `Cloudy`
6. System confirms: "Forecast added for Paris - Next Week"

### Scenario 10: Display All Cities

1. Select option `10` (Display All Cities)
2. System lists all cities in the database:
   ```
   === All Cities in Database ===
   - NewYork
   - London
   - Tokyo
   - Paris
   - Sydney
   ```

## DSA Operations Demonstrated

### Hash Map Operations (O(1) average)
- **Insert/Update**: Adding or updating weather data for a city
- **Lookup**: Querying weather by city name
- **Iterate**: Displaying all cities or searching by condition

### Stack Operations (LIFO)
- **Push**: Adding weather data to history when updating
- **Pop**: Viewing history (most recent first)
- **Peek**: Checking the most recent update

### Priority Queue Operations
- **Insert**: Adding weather alerts with priority
- **Extract-Max**: Displaying alerts (highest priority first)
- **Heap Property**: Maintained automatically by STL

### Queue Operations (FIFO)
- **Enqueue**: Adding forecast data
- **Dequeue**: Processing forecasts in order
- **Front**: Viewing next forecast

### Graph Operations
- **Add Vertex**: Creating new city nodes
- **Add Edge**: Connecting cities with distances
- **Traverse**: Displaying connections from a city
- **Adjacency List**: Efficient representation using vectors

## Tips for Testing

1. **Test Hash Map**: Add multiple cities, query them, and search by condition
2. **Test Stack**: Update weather for the same city multiple times, then view history
3. **Test Priority Queue**: Add alerts with different priorities and verify correct ordering
4. **Test Queue**: Add multiple forecasts and verify FIFO order
5. **Test Graph**: Add city connections and verify bidirectional links

## Clean Up

To remove the compiled binary:
```bash
make clean
```

## Performance Notes

- Hash Map lookups: O(1) average time
- Stack push/pop: O(1) time
- Priority Queue insert: O(log n) time
- Queue enqueue/dequeue: O(1) time
- Graph edge addition: O(1) time (using adjacency list)

## Common Issues

### Issue: "Invalid input! Please enter a number."
**Solution**: Make sure to enter numeric values for menu choices, temperature, humidity, and priority.

### Issue: "No weather data found for [city]"
**Solution**: The city name is case-sensitive. Make sure to use the exact name (e.g., "NewYork" not "new york").

### Issue: Compilation error
**Solution**: Ensure you have g++ with C++11 support installed. Try: `g++ --version`
