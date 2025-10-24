#ifndef WEATHER_APP_H
#define WEATHER_APP_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>

using namespace std;

// Structure to represent weather data
struct WeatherData {
    string city;
    double temperature;
    int humidity;
    string condition;
    time_t timestamp;
    
    WeatherData() : temperature(0), humidity(0), timestamp(0) {}
    
    WeatherData(string c, double temp, int hum, string cond) 
        : city(c), temperature(temp), humidity(hum), condition(cond) {
        timestamp = time(nullptr);
    }
    
    void display() const {
        cout << "\n--- Weather Information ---\n";
        cout << "City: " << city << "\n";
        cout << "Temperature: " << temperature << "°C\n";
        cout << "Humidity: " << humidity << "%\n";
        cout << "Condition: " << condition << "\n";
        cout << "Last Updated: " << ctime(&timestamp);
    }
};

// Structure for weather alerts (Priority Queue)
struct WeatherAlert {
    string city;
    string alertType;
    int priority; // 1 = highest, 5 = lowest
    string message;
    
    WeatherAlert(string c, string type, int p, string msg)
        : city(c), alertType(type), priority(p), message(msg) {}
    
    // For priority queue (lower number = higher priority)
    bool operator<(const WeatherAlert& other) const {
        return priority > other.priority;
    }
    
    void display() const {
        cout << "\n*** ALERT [Priority " << priority << "] ***\n";
        cout << "City: " << city << "\n";
        cout << "Type: " << alertType << "\n";
        cout << "Message: " << message << "\n";
    }
};

// Structure for forecast data (Queue)
struct ForecastData {
    string city;
    string date;
    double temperature;
    string condition;
    
    ForecastData(string c, string d, double temp, string cond)
        : city(c), date(d), temperature(temp), condition(cond) {}
    
    void display() const {
        cout << date << " | " << temperature << "°C | " << condition << "\n";
    }
};

// Graph Node for city connections
struct CityNode {
    string cityName;
    vector<pair<string, double>> connections; // neighboring cities with distance
    
    CityNode() : cityName("") {}
    CityNode(string name) : cityName(name) {}
};

// Main Weather App Class
class WeatherApp {
private:
    // Hash Map for storing current weather data (City -> WeatherData)
    unordered_map<string, WeatherData> weatherDatabase;
    
    // Stack for weather history (Last 10 weather updates)
    stack<WeatherData> weatherHistory;
    
    // Priority Queue for weather alerts
    priority_queue<WeatherAlert> alertQueue;
    
    // Queue for forecast data
    queue<ForecastData> forecastQueue;
    
    // Graph for city connections
    unordered_map<string, CityNode> cityGraph;
    
    // Helper function to convert string to lowercase
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

public:
    // Constructor
    WeatherApp() {
        cout << "Weather App Initialized with DSA Concepts!\n";
        initializeSampleData();
    }
    
    // Initialize with sample data
    void initializeSampleData() {
        // Add sample cities with weather data
        addWeatherData("NewYork", 22.5, 65, "Sunny");
        addWeatherData("London", 15.0, 80, "Cloudy");
        addWeatherData("Tokyo", 25.0, 70, "Partly Cloudy");
        addWeatherData("Paris", 18.0, 75, "Rainy");
        addWeatherData("Sydney", 28.0, 60, "Sunny");
        
        // Add city connections (Graph)
        addCityConnection("NewYork", "London", 5570.0);
        addCityConnection("London", "Paris", 343.0);
        addCityConnection("Paris", "Tokyo", 9715.0);
        addCityConnection("Tokyo", "Sydney", 7823.0);
        
        // Add sample alerts
        addWeatherAlert("NewYork", "Heat Wave", 2, "High temperature expected");
        addWeatherAlert("London", "Storm Warning", 1, "Severe storm approaching");
        
        // Add sample forecasts
        addForecast("NewYork", "Tomorrow", 24.0, "Sunny");
        addForecast("NewYork", "Day After", 23.5, "Partly Cloudy");
        addForecast("London", "Tomorrow", 14.0, "Rainy");
    }
    
    // Hash Map: Add or update weather data
    void addWeatherData(string city, double temp, int humidity, string condition) {
        WeatherData data(city, temp, humidity, condition);
        
        // Add to history stack before updating
        if (weatherDatabase.find(city) != weatherDatabase.end()) {
            weatherHistory.push(weatherDatabase[city]);
        }
        
        // Update hash map
        weatherDatabase[city] = data;
        cout << "Weather data updated for " << city << "\n";
    }
    
    // Hash Map: Query weather data by city
    void queryWeather(string city) {
        if (weatherDatabase.find(city) != weatherDatabase.end()) {
            weatherDatabase[city].display();
        } else {
            cout << "No weather data found for " << city << "\n";
        }
    }
    
    // Stack: View weather history
    void viewWeatherHistory() {
        if (weatherHistory.empty()) {
            cout << "No weather history available.\n";
            return;
        }
        
        cout << "\n=== Weather History (Most Recent First) ===\n";
        stack<WeatherData> tempStack = weatherHistory;
        int count = 1;
        
        while (!tempStack.empty() && count <= 10) {
            cout << "\nHistory Entry #" << count << ":\n";
            tempStack.top().display();
            tempStack.pop();
            count++;
        }
    }
    
    // Priority Queue: Add weather alert
    void addWeatherAlert(string city, string type, int priority, string message) {
        WeatherAlert alert(city, type, priority, message);
        alertQueue.push(alert);
        cout << "Weather alert added for " << city << "\n";
    }
    
    // Priority Queue: Display all alerts (highest priority first)
    void displayAlerts() {
        if (alertQueue.empty()) {
            cout << "No active weather alerts.\n";
            return;
        }
        
        cout << "\n=== Active Weather Alerts ===\n";
        priority_queue<WeatherAlert> tempQueue = alertQueue;
        
        while (!tempQueue.empty()) {
            tempQueue.top().display();
            tempQueue.pop();
        }
    }
    
    // Queue: Add forecast data
    void addForecast(string city, string date, double temp, string condition) {
        ForecastData forecast(city, date, temp, condition);
        forecastQueue.push(forecast);
        cout << "Forecast added for " << city << " - " << date << "\n";
    }
    
    // Queue: Display forecasts
    void displayForecasts() {
        if (forecastQueue.empty()) {
            cout << "No forecast data available.\n";
            return;
        }
        
        cout << "\n=== Weather Forecasts ===\n";
        queue<ForecastData> tempQueue = forecastQueue;
        
        while (!tempQueue.empty()) {
            cout << "City: " << tempQueue.front().city << " | ";
            tempQueue.front().display();
            tempQueue.pop();
        }
    }
    
    // Graph: Add city connection
    void addCityConnection(string city1, string city2, double distance) {
        // Create nodes if they don't exist
        if (cityGraph.find(city1) == cityGraph.end()) {
            cityGraph[city1] = CityNode(city1);
        }
        if (cityGraph.find(city2) == cityGraph.end()) {
            cityGraph[city2] = CityNode(city2);
        }
        
        // Add bidirectional connection
        cityGraph[city1].connections.push_back({city2, distance});
        cityGraph[city2].connections.push_back({city1, distance});
    }
    
    // Graph: Display city connections
    void displayCityConnections(string city) {
        if (cityGraph.find(city) == cityGraph.end()) {
            cout << "City not found in the network.\n";
            return;
        }
        
        cout << "\n=== Connections for " << city << " ===\n";
        for (const auto& connection : cityGraph[city].connections) {
            cout << city << " <-> " << connection.first 
                 << " (Distance: " << connection.second << " km)\n";
        }
    }
    
    // Display all cities in database
    void displayAllCities() {
        if (weatherDatabase.empty()) {
            cout << "No cities in the database.\n";
            return;
        }
        
        cout << "\n=== All Cities in Database ===\n";
        for (const auto& pair : weatherDatabase) {
            cout << "- " << pair.first << "\n";
        }
    }
    
    // Search for cities with specific condition
    void searchByCondition(string condition) {
        cout << "\n=== Cities with condition: " << condition << " ===\n";
        bool found = false;
        
        for (const auto& pair : weatherDatabase) {
            if (toLowerCase(pair.second.condition) == toLowerCase(condition)) {
                cout << "- " << pair.first << " (" << pair.second.temperature << "°C)\n";
                found = true;
            }
        }
        
        if (!found) {
            cout << "No cities found with this condition.\n";
        }
    }
};

#endif // WEATHER_APP_H
