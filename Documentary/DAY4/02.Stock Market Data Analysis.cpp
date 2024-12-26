#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Trade {
public:
    string timestamp; // Trade timestamp
    string stockSymbol; // Stock symbol
    double tradePrice; // Trade price
    int tradeVolume; // Trade volume

    Trade(const string& timestamp, const string& stockSymbol, double tradePrice, int tradeVolume)
        : timestamp(timestamp), stockSymbol(stockSymbol), tradePrice(tradePrice), tradeVolume(tradeVolume) {}
};

// Comparator for sorting trades by timestamp
bool compareByTimestamp(const Trade& t1, const Trade& t2) {
    return t1.timestamp < t2.timestamp;
}

// Comparator for sorting trades by stock symbol
bool compareByStockSymbol(const Trade& t1, const Trade& t2) {
    return t1.stockSymbol < t2.stockSymbol;
}

// Function to group trades by stock symbol and calculate total volume
map<string, int> groupByStockVolume(const vector<Trade>& trades) {
    map<string, int> volumeMap;
    for (const auto& trade : trades) {
        volumeMap[trade.stockSymbol] += trade.tradeVolume;
    }
    return volumeMap;
}

int main() {
    vector<Trade> trades = {
        Trade("2023-10-01 09:30:00", "AAPL", 150.0, 100),
        Trade("2023-10-01 09:31:00", "GOOGL", 2800.0, 50),
        Trade("2023-10-01 09:30:30", "AAPL", 151.0, 200),
        Trade("2023-10-01 09:32:00", "MSFT", 300.0, 150),
        Trade("2023-10-01 09:31:30", "GOOGL", 2795.0, 75),
        Trade("2023-10-01 09:33:00", "AAPL", 152.0, 300)
    };

    // Sort trades by timestamp
    sort(trades.begin(), trades.end(), compareByTimestamp);

    cout << "Trades sorted by timestamp:\n";
    for (const auto& trade : trades) {
        cout << "Timestamp: " << trade.timestamp
             << ", Stock Symbol: " << trade.stockSymbol
             << ", Trade Price: " << trade.tradePrice
             << ", Trade Volume: " << trade.tradeVolume << "\n";
    }

    // Sort trades by stock symbol
    sort(trades.begin(), trades.end(), compareByStockSymbol);

    cout << "\nTrades sorted by stock symbol:\n";
    for (const auto& trade : trades) {
        cout << "Timestamp: " << trade.timestamp
             << ", Stock Symbol: " << trade.stockSymbol
             << ", Trade Price: " << trade.tradePrice
             << ", Trade Volume: " << trade.tradeVolume << "\n";
    }

    // Group trades by stock symbol and calculate total volume
    map<string, int> volumeMap = groupByStockVolume(trades);

    cout << "\nTotal trading volume by stock symbol:\n";
    for (const auto& entry : volumeMap) {
        cout << "Stock Symbol: " << entry.first << ", Total Volume: " << entry.second << "\n";
    }

    return 0;
}