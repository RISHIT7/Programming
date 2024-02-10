#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

// calculate a moving average
double calcMA(double previousAverage, unsigned int previousNumDays, double newStock)
{
    auto rslt = previousNumDays * previousAverage + newStock;
    return rslt / (previousNumDays + 1.0);
}

// calculate an exponential moving average
double calcEMA(double previousAverage, int timePeriod, double newStock)
{
    auto mult = 2.0 / (timePeriod + 1.0);
    auto rslt = (newStock - previousAverage) * mult + previousAverage;
    return rslt;
}

map<std::tuple<int, int>, double> memo_ewm;

double get_ewm(vector<pair<string, double>> data, int i, int n, double alpha)
{
    if (i == 0)
    {
        return data[0].second;
    }

    auto key = std::make_tuple(i, n);
    if (memo_ewm.find(key) != memo_ewm.end())
    {
        return memo_ewm[key];
    }
    double prev_ewm = get_ewm(data, i - 1, n, alpha);
    double ewm = (alpha * (data[i].second - prev_ewm)) + prev_ewm;

    memo_ewm[key] = ewm;
    return ewm;
}

class Trade
{
    unsigned int timePeriod_ = 5;
    double lastMA_ = 0.0;
    std::list<double> stockPrices_;

public:
    void addStock(double newStock)
    {
        stockPrices_.push_back(newStock);
        auto num_days = stockPrices_.size();

        if (num_days <= timePeriod_)
            lastMA_ = calcMA(lastMA_, num_days - 1, newStock);
        else
            lastMA_ = calcEMA(lastMA_, num_days - 1, newStock);
    }

    double getAverage() const { return lastMA_; }
};

// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
int main()
{
    std::vector<double> stocks =
        {1000, 1100, 1200, 1300, 1400, 1500,
         1400, 1300, 1200, 1100, 1000};
    vector<pair<string, double>> stocks_line;
    for (int i = 0; i < stocks.size(); i++)
    {
        stocks_line.push_back({to_string(i), stocks[i]});
    }

    double ewm;
    for (int i = 0; i < stocks.size(); i++)
    {
        ewm = get_ewm(stocks_line, i, 4, 2.0/(1+4));
        cout << ewm << endl;
    }

    Trade trade;
    for (auto stock : stocks)
    {
        trade.addStock(stock);
        std::cout << "Average: " << trade.getAverage() << std::endl;
    }
    return 0;
}