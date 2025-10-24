# Makefile for Weather App

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = weather_app
SOURCES = main.cpp
HEADERS = WeatherApp.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
