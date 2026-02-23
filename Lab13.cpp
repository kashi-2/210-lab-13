#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;

// constants 

const int DAYS_IN_MONTH = 30;

//function proties

bool loadTemperatures(array<int, DAYS_IN_MONTH> &temps);
void displayTemperatures(const array<int, DAYS_IN_MONTH> &temps);
void analyzeTemperatures(const array<int, DAYS_IN_MONTH> &temps);

//mainfun below

int main()
{ 
    array<int, DAYS_IN_MONTH> temperatures;

    //filling array with zeroes using std:array::fill
    temperatures.fill(0);

    if (!loadTemperatures(temperatures))
    {
        cout << "Error loading temperature data." << endl;
        return 1;
    }
    
    displayTemperatures(temperatures);
    analyzeTemperatures(temperatures);
    return 0;
}
// func definations aka loadTemperatures which will read temperature data from a file into std::array.
//fills requirement to use: at(), size(), data()

bool loadTemperatures(array<int, DAYS_IN_MONTH> &temps)
{
    ifstream inputFile("temperatures.txt");

    if (!inputFile)
    {
        return false;
    }

    for (size_t i = 0; i < temps.size(); i++)
    {
        inputFile >> temps.at(i);
    }
    inputFile.close();
    return true;
} 
//func: displayTemperatures where it will output all temperature values.
//this will fill the requirement for front(), back(), empty()s
void displayTemperatures(const array<int, DAYS_IN_MONTH> &temps)
{
    cout << "\nDaily Temperatures:\n";

    if (temps.empty())
    {
        cout << "No temperature data available.\n";
        return;
    } 

    for (size_t i = 0; i < temps.size(); i++)
    {
        cout << "Day " << (i + 1) << ": " << temps[i] << " degrees\n";

    } 
    cout << "\nFirst day temperature: " << temps.front() << endl;
    cout << "Last day temperature: " << temps.back() << endl;
} 

//creating func: analyzeTemperatures which will perform statistical analysis on the temperatures
// this will basically cover the begin(), end(), max_element(), min_element()

void analyzeTemperatures(const array<int, DAYS_IN_MONTH> &temps)
{
    int maxTemp = *max_element(temps.begin(), temps.end());
    int minTemp = *min_element(temps.begin(), temps.end());

    int total = accumulate(temps.begin(), temps.end(), 0);
    double average = static_cast<double>(total) / temps.size();

    cout << "\nTemperature Analysis: \n";
    cout << "Highest Temperature: " << maxTemp << endl;
    cout << "Lowest Temperature: " << minTemp << endl;
    cout << "Average Temperature: " << average << endl;
}