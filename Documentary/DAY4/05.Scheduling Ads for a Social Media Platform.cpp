#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Advertisement structure
struct Advertisement {
    string advertiserName;
    double bidAmount;      // Bid amount per impression
    double engagementRate; // Engagement rate (e.g., clicks/impressions)
    double remainingBudget;
    double priorityScore;  // Calculated priority score

    Advertisement(string name, double bid, double engagement, double budget)
        : advertiserName(name), bidAmount(bid), engagementRate(engagement), remainingBudget(budget), priorityScore(0.0) {}

    // Calculate priority score
    void calculatePriorityScore() {
        priorityScore = bidAmount * 0.5 + engagementRate * 0.3 + remainingBudget * 0.2;
    }
};

// Comparator for priority queue
struct CompareAd {
    bool operator()(const Advertisement& a, const Advertisement& b) {
        // Higher priority score comes first
        return a.priorityScore < b.priorityScore;
    }
};

// Schedule ads in real-time
void scheduleAds(priority_queue<Advertisement, vector<Advertisement>, CompareAd>& adQueue) {
    cout << left << setw(15) << "Advertiser"
         << setw(10) << "Bid"
         << setw(15) << "Engagement"
         << setw(15) << "Budget"
         << "Priority Score" << endl;
    cout << string(60, '-') << endl;

    while (!adQueue.empty()) {
        Advertisement ad = adQueue.top();
        adQueue.pop();

        cout << left << setw(15) << ad.advertiserName
             << setw(10) << ad.bidAmount
             << setw(15) << ad.engagementRate
             << setw(15) << ad.remainingBudget
             << ad.priorityScore << endl;
    }
}

int main() {
    // Priority queue to manage advertisements
    priority_queue<Advertisement, vector<Advertisement>, CompareAd> adQueue;

    // Sample advertisements
    vector<Advertisement> ads = {
        {"Advertiser A", 2.5, 0.8, 1000},
        {"Advertiser B", 3.0, 0.7, 800},
        {"Advertiser C", 1.5, 0.9, 1200},
        {"Advertiser D", 2.8, 0.6, 500},
        {"Advertiser E", 3.5, 0.85, 300}
    };

    // Calculate priority scores and add ads to the queue
    for (auto& ad : ads) {
        ad.calculatePriorityScore();
        adQueue.push(ad);
    }

    // Schedule and display ads
    cout << "Scheduled Ads:\n";
    scheduleAds(adQueue);

    return 0;
}
