#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main(int argv, char *argc[])
{
    string symbol{argc[1]};
    int n0{stoi(argc[2])};
    int x{stoi(argc[3])};
    int p{stoi(argc[4])};
    int max_hold_days{stoi(argc[5])};
    int c1{stoi(argc[6])};
    int c2{stoi(argc[7])};

    vector<pair<string, double>> data;

    ifstream file("Stocks/" + symbol + ".csv");
    if (!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string first_line;
    getline(file, first_line);

    string line;
    while (getline(file, line))
    {
        string date;
        string price;
        stringstream ss(line);
        getline(ss, date, ',');
        getline(ss, price, '\n');
        data.push_back({date, stod(price)});
    }

    file.close();

    ofstream cash_file("results/daily_cashflow.csv");
    ofstream order_file("results/order_statistics.csv");
    ofstream final_file("results/final_pnl.txt");

    cash_file << "Date,Cashflow\n";
    order_file << "Date,Order_dir,Quantity,Price\n";

    long unsigned int len{data.size()};
    double sma{}, sd{}, variance{}, sumOfSquares{};
    int stocks{}, prevStocks{};
    double cashflow{};
    int hold_days{};

    for (int i = 0; i < len; i++)
    {
        // setting up prevStocks
        prevStocks = stocks;

        // the first n0 days we have no DMA so we can continue
        if (i < n0)
        {
            sma += (data[i].second) / n0;
            sumOfSquares += (data[i].second * data[i].second);
            continue;
        }

        // getting the first value of sma and sd
        variance = sumOfSquares / n0 - (sma * sma);
        sd = sqrt(variance);

        // implementing buy and sell
        if ((data[i].second > sma + (p * sd)) and stocks < x)
        {
            // buy
            stocks++;
            order_file << data[i].first << ",BUY,1," << data[i].second << "\n";
            cashflow -= data[i].second;
        }
        else if ((data[i].second < sma - (p * sd)) and stocks > -x)
        {
            // sell
            stocks--;
            order_file << data[i].first << ",SELL,1," << data[i].second << "\n";
            cashflow += data[i].second;
        }

        // update sma and sd
        sma = sma + ((data[i].second - data[i - n0].second) / n0);
        sumOfSquares = sumOfSquares + (((data[i].second * data[i].second) - (data[i - n0].second * data[i - n0].second)));

        // checking if stock has changed
        if (stocks == prevStocks)
        {
            hold_days += 1;
        }

        // checking if hold_days == max_hold_days
        if (hold_days == max_hold_days and stocks > 0)
        {
            // sell
            stocks--;
            order_file << data[i].first << ",SELL,1," << data[i].second << "\n";
            cashflow += data[i].second;

            // reset hold days
            hold_days = 0;
        }
        else if (hold_days == max_hold_days and stocks < 0)
        {
            // buy
            stocks++;
            order_file << data[i].first << ",BUY,1," << data[i].second << "\n";
            cashflow -= data[i].second;

            // reset hold days
            hold_days = 0;
        }

        // cash_file
        cash_file << data[i].first << "," << cashflow << "\n";
    }

    double final_pnl{cashflow + (stocks * data[len - 1].second)};
    final_file << "Final pnl : " << final_pnl << "\n";

    cash_file.close();
    order_file.close();
    final_file.close();

    return 0;
}