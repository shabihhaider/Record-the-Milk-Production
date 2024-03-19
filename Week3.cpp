#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
using namespace std;

const int DAYS_IN_WEEK = 7;
const int MILK_THRESHOLD = 12; 

struct Cow
{
    int id;
    vector<double> dailyYields;
};

void task1(vector<Cow>& herd) {
    //Record the milk yields for a week
    for (int i = 0; i < herd.size(); ++i)
    {
        cout << "| Enter the daily milk yield for cow " << herd[i].id << ":" << endl;
        for (int day = 1; day <= DAYS_IN_WEEK; day++)
        {
            double yield;
            cout << "Day " << day << ": ";
            cin >> yield;
            herd[i].dailyYields.push_back(yield);
        }   
    }
}

void task2(vector<Cow>& herd) {
    double totalVolume = 0;
    int totalCows = herd.size();

    for (int i = 0; i < herd.size(); ++i)
    {
        for (int j = 0; j < herd[i].dailyYields.size(); ++j) {
            double yield = herd[i].dailyYields[j];
        	totalVolume += yield;
        }   
    }
    
    double averageYield = totalVolume / (totalCows * DAYS_IN_WEEK);

    cout << "Total weekly volume of milk for the herd: " << fixed  << setprecision(1) << totalVolume << " litres\n";
    cout << "Average yield per cow in a week: " << fixed << setprecision(1) << averageYield << " litres\n";

}

void task3(vector<Cow>& herd) {
    double maxWeeklyYield = 0.0;
    int mostProductiveCow = -1;

    cout << "Cows with less than " << MILK_THRESHOLD << " litres of milk for four or more days:\n";

    for (int i = 0; i < herd.size(); ++i) 
    {
        int lowVolumeDays = 0;

        for (int j = 0; j < herd[i].dailyYields.size(); ++j) 
        {
        	double yield = herd[i].dailyYields[j];
            if (yield < MILK_THRESHOLD) 
            {
                lowVolumeDays++;
            }
        }

        if (lowVolumeDays >= 4) 
        {
            cout << "Cow " << herd[i].id << " - Weekly Yield: " << fixed << setprecision(1) << (herd[i].dailyYields.begin(), herd[i].dailyYields.end(), 0.0) << " litres\n";
        }

        double weeklyYield = (herd[i].dailyYields.begin(), herd[i].dailyYields.end(), 0.0);
        if (weeklyYield > maxWeeklyYield) 
        {
            maxWeeklyYield = weeklyYield;
            mostProductiveCow = herd[i].id;
        }
    }

    if (mostProductiveCow != -1) 
    {
        cout << "The most productive cow is Cow " << mostProductiveCow << " with a weekly yield of " << fixed << setprecision(1) << maxWeeklyYield << " litres\n";
    } 
    else 
    {
        cout << "No cows in the herd.\n";
    }

}

int main() {

    int noOfCows = 0;
    cout << "Enter the number of cows in the herd: ";
    cin >> noOfCows;

    vector<Cow> herd(noOfCows);

    for (int i = 0; i < noOfCows; i++)
    {
        herd[i].id = i + 1;
    }
    
    //Task 1
    task1(herd);

    //Task 2
    task2(herd);

    //Task 3
    task3(herd);
    cout << endl;

    return 0;
}
