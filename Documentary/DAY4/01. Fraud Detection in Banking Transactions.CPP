#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Transaction {
public:
    int id;
    double amount;
    int frequency;
    string location;
    double suspiciousnessScore;

    Transaction(int id, double amount, int frequency, const string& location)
        : id(id), amount(amount), frequency(frequency), location(location) {
        suspiciousnessScore = calculateSuspiciousnessScore();
    }

    double calculateSuspiciousnessScore() {
        return (amount * 0.5) + (frequency * 0.3) + (locationRiskFactor() * 0.2);
    }

    double locationRiskFactor() {
        if (location == "high-risk-area") {
            return 10.0;
        }
        return 1.0;
    }
};

bool compareBySuspiciousness(const Transaction& t1, const Transaction& t2) {
    return t1.suspiciousnessScore > t2.suspiciousnessScore;
}

int main() {
    vector<Transaction> transactions = {
        Transaction(1, 1000.0, 5, "low-risk-area"),
        Transaction(2, 5000.0, 2, "high-risk-area"),
        Transaction(3, 200.0, 10, "medium-risk-area"),
        Transaction(4, 3000.0, 1, "high-risk-area"),
        Transaction(5, 1500.0, 3, "low-risk-area")
    };

    sort(transactions.begin(), transactions.end(), compareBySuspiciousness);

    cout << "Transactions sorted by suspiciousness score:\n";
    for (const auto& transaction : transactions) {
        cout << "Transaction ID: " << transaction.id
             << ", Amount: " << transaction.amount
             << ", Frequency: " << transaction.frequency
             << ", Location: " << transaction.location
             << ", Suspiciousness Score: " << transaction.suspiciousnessScore << "\n";
    }

    return 0;
}