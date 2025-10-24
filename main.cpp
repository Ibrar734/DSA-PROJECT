#include "WeatherApp.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayMenu() {
    cout << "\n\n";
    cout << "╔════════════════════════════════════════════════════╗\n";
    cout << "║        WEATHER APP - DSA CONCEPTS IN C++          ║\n";
    cout << "╚════════════════════════════════════════════════════╝\n";
    cout << "\n1.  Add/Update Weather Data (Hash Map)\n";
    cout << "2.  Query Weather by City (Hash Map)\n";
    cout << "3.  View Weather History (Stack)\n";
    cout << "4.  Add Weather Alert (Priority Queue)\n";
    cout << "5.  Display Weather Alerts (Priority Queue)\n";
    cout << "6.  Add Forecast (Queue)\n";
    cout << "7.  Display Forecasts (Queue)\n";
    cout << "8.  Display City Connections (Graph)\n";
    cout << "9.  Add City Connection (Graph)\n";
    cout << "10. Display All Cities\n";
    cout << "11. Search Cities by Weather Condition\n";
    cout << "0.  Exit\n";
    cout << "\nEnter your choice: ";
}

int main() {
    WeatherApp app;
    int choice;
    
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════╗\n";
    cout << "║  Welcome to the Weather Application!              ║\n";
    cout << "║  This app demonstrates various DSA concepts:      ║\n";
    cout << "║  - Hash Map (Weather Database)                    ║\n";
    cout << "║  - Stack (Weather History)                        ║\n";
    cout << "║  - Priority Queue (Weather Alerts)                ║\n";
    cout << "║  - Queue (Forecast Data)                          ║\n";
    cout << "║  - Graph (City Connections)                       ║\n";
    cout << "╚════════════════════════════════════════════════════╝\n";
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        if (cin.fail()) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        
        clearInputBuffer();
        
        switch (choice) {
            case 1: {
                // Add/Update Weather Data
                string city, condition;
                double temp;
                int humidity;
                
                cout << "\nEnter city name: ";
                getline(cin, city);
                cout << "Enter temperature (°C): ";
                cin >> temp;
                cout << "Enter humidity (%): ";
                cin >> humidity;
                clearInputBuffer();
                cout << "Enter weather condition: ";
                getline(cin, condition);
                
                app.addWeatherData(city, temp, humidity, condition);
                break;
            }
            
            case 2: {
                // Query Weather by City
                string city;
                cout << "\nEnter city name: ";
                getline(cin, city);
                app.queryWeather(city);
                break;
            }
            
            case 3: {
                // View Weather History
                app.viewWeatherHistory();
                break;
            }
            
            case 4: {
                // Add Weather Alert
                string city, alertType, message;
                int priority;
                
                cout << "\nEnter city name: ";
                getline(cin, city);
                cout << "Enter alert type (e.g., Storm, Heat Wave, etc.): ";
                getline(cin, alertType);
                cout << "Enter priority (1=highest, 5=lowest): ";
                cin >> priority;
                clearInputBuffer();
                cout << "Enter alert message: ";
                getline(cin, message);
                
                app.addWeatherAlert(city, alertType, priority, message);
                break;
            }
            
            case 5: {
                // Display Weather Alerts
                app.displayAlerts();
                break;
            }
            
            case 6: {
                // Add Forecast
                string city, date, condition;
                double temp;
                
                cout << "\nEnter city name: ";
                getline(cin, city);
                cout << "Enter date (e.g., Tomorrow, Next Monday): ";
                getline(cin, date);
                cout << "Enter temperature (°C): ";
                cin >> temp;
                clearInputBuffer();
                cout << "Enter weather condition: ";
                getline(cin, condition);
                
                app.addForecast(city, date, temp, condition);
                break;
            }
            
            case 7: {
                // Display Forecasts
                app.displayForecasts();
                break;
            }
            
            case 8: {
                // Display City Connections
                string city;
                cout << "\nEnter city name: ";
                getline(cin, city);
                app.displayCityConnections(city);
                break;
            }
            
            case 9: {
                // Add City Connection
                string city1, city2;
                double distance;
                
                cout << "\nEnter first city name: ";
                getline(cin, city1);
                cout << "Enter second city name: ";
                getline(cin, city2);
                cout << "Enter distance (km): ";
                cin >> distance;
                clearInputBuffer();
                
                app.addCityConnection(city1, city2, distance);
                cout << "City connection added successfully!\n";
                break;
            }
            
            case 10: {
                // Display All Cities
                app.displayAllCities();
                break;
            }
            
            case 11: {
                // Search by Condition
                string condition;
                cout << "\nEnter weather condition to search: ";
                getline(cin, condition);
                app.searchByCondition(condition);
                break;
            }
            
            case 0: {
                // Exit
                cout << "\nThank you for using the Weather App!\n";
                cout << "Goodbye!\n\n";
                return 0;
            }
            
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        
        cout << "\nPress Enter to continue...";
        cin.get();
    }
    
    return 0;
}
