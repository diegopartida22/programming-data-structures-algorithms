#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Comprehensive Activity of Basic Concepts and Fundamental Algorithms

// Authors:
// Diego Partida Romero A01641113
// Carlos Alberto Veryan Peña A01641147

// Date: 30 - 08 - 2022

int main()
{

    ifstream file("Bitacora.txt");
    string line;
    vector<string> lines;
    while (getline(file, line))
    {
        lines.push_back(line);
    }
    file.close();

    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i][4] >= '0' && lines[i][4] <= '9' && lines[i][5] == ' ')
        {
            lines[i].insert(4, "0");
        }
    }

    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    vector<string> days = {"01", "02", "03", "0 ", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};

    vector<string> sortedLines;

    for (int i = 0; i < months.size(); i++)
    {
        for (int j = 0; j < days.size(); j++)
        {
            for (int k = 0; k < lines.size(); k++)
            {
                if (lines[k].substr(0, 3) == months[i] && lines[k].substr(4, 2) == days[j])
                {
                    sortedLines.push_back(lines[k]);
                }
            }
        }
    }

    string startMonth, startDay, endMonth, endDay;

    cout << "This program will sort the lines of a text file by date" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "Please enter the start month and day (ex. Jan 01) " << endl;
    cout << "Enter the start date (mmm dd): ";
    while (true)
    {
        cin >> startMonth >> startDay;
        if (startMonth == "Jan" || startMonth == "Feb" || startMonth == "Mar" || startMonth == "Apr" || startMonth == "May" || startMonth == "Jun" || startMonth == "Jul" || startMonth == "Aug" || startMonth == "Sep" || startMonth == "Oct" || startMonth == "Nov" || startMonth == "Dec")
        {
            if (startDay == "01" || startDay == "02" || startDay == "03" || startDay == "04" || startDay == "05" || startDay == "06" || startDay == "07" || startDay == "08" || startDay == "09" || startDay == "10" || startDay == "11" || startDay == "12" || startDay == "13" || startDay == "14" || startDay == "15" || startDay == "16" || startDay == "17" || startDay == "18" || startDay == "19" || startDay == "20" || startDay == "21" || startDay == "22" || startDay == "23" || startDay == "24" || startDay == "25" || startDay == "26" || startDay == "27" || startDay == "28" || startDay == "29" || startDay == "30" || startDay == "31")
            {
                break;
            }
        }
        cout << "Invalid input. Please enter a valid START date (mmm dd): ";
    }

    cout << "Enter the end date (mmm dd): ";
    while (true)
    {
        cin >> endMonth >> endDay;
        if (endMonth == "Jan" || endMonth == "Feb" || endMonth == "Mar" || endMonth == "Apr" || endMonth == "May" || endMonth == "Jun" || endMonth == "Jul" || endMonth == "Aug" || endMonth == "Sep" || endMonth == "Oct" || endMonth == "Nov" || endMonth == "Dec")
        {
            if (endDay == "01" || endDay == "02" || endDay == "03" || endDay == "04" || endDay == "05" || endDay == "06" || endDay == "07" || endDay == "08" || endDay == "09" || endDay == "10" || endDay == "11" || endDay == "12" || endDay == "13" || endDay == "14" || endDay == "15" || endDay == "16" || endDay == "17" || endDay == "18" || endDay == "19" || endDay == "20" || endDay == "21" || endDay == "22" || endDay == "23" || endDay == "24" || endDay == "25" || endDay == "26" || endDay == "27" || endDay == "28" || endDay == "29" || endDay == "30" || endDay == "31")
            {
                break;
            }
        }
        cout << "Invalid input. Please enter a valid END date (mmm dd): ";
    }

    cout << endl;

    cout << "Month - Day - Hour - IP - Action" << endl;

    int startIndex = 0;
    for (int i = 0; i < sortedLines.size(); i++)
    {
        if (sortedLines[i].substr(0, 3) == startMonth && sortedLines[i].substr(4, 2) == startDay)
        {
            startIndex = i;
            break;
        }
    }

    int endIndex = 0;
    for (int i = 0; i < sortedLines.size(); i++)
    {
        if (sortedLines[i].substr(0, 3) == endMonth && sortedLines[i].substr(4, 2) == endDay)
        {
            endIndex = i;
            break;
        }
    }

    ofstream newFile("SearchResults.txt");
    for (int i = startIndex; i < endIndex; i++)
    {
        newFile << sortedLines[i] << endl;
    }
    newFile.close();

    for (int i = startIndex; i <= endIndex; i++)
    {
        cout << sortedLines[i] << endl;
    }

    return 0;
}