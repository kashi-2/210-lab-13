#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// constants 

const int DAYS_IN_MONTH = 30;

//function proties

bool loadTemperatures(vector<int> &temps);
void displayTemperatures(const vector<int> &temps);
void analyzeTemperatures(const vector<int> &temps);

//mainfun below

int main()
{ 
    vector<int> temperatures;

    if (!loadTemperatures(temperatures))
    {
        cout << "Error loading temperature data." << endl;
        return 1;
    }
    
    displayTemperatures(temperatures);
    analyzeTemperatures(temperatures);
    return 0;
}
// func definations aka loadTemperatures, going to now read temp data from file into a vector.
//have to show push_back(), size() in this assignment

bool loadTemperatures(vector<int> &temps)
{
    ifstream inputFile("temperatures.txt");

    if (!inputFile)
    {
        return false;
    }

    int value = 0;

    while (inputFile >> value)
    {
        temps.push_back(value);
    }

    inputFile.close();

    //validating expected # of elements
    if (temps.size() != DAYS_IN_MONTH)
    {
        cout << "Warning: Expected " << DAYS_IN_MONTH << " values, but read " << temps.size() << endl;
    }

    return true;
} 
//func: displayTemperatures where it will output all temperature values.
//this will fill the requirement for front(), back(), empty(), size()

void displayTemperatures(const vector<int> &temps)
{
    if (temps.empty())
    {
        cout << "No temperature data available.\n";
        return;
    } 
    cout << "\nDaily Temperatures:\n";

    for (size_t i = 0; i < temps.size(); i++)
    {
        cout << "Day " << (i + 1) << ": " << temps[i] << " degrees\n";

    } 
    cout << "\nFirst day temperature: " << temps.front() << endl;
    cout << "Last day temperature: " << temps.back() << endl;
} 

//creating func: analyzeTemperatures which will perform statistical analysis on the temperatures
// this will basically cover begin(), end()

void analyzeTemperatures(const vector<int> &temps)
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