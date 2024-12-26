#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct MediaItem {
    string title;
    int totalViews;
    double userRating;
    int releaseYear;
    double popularityScore;

    // Calculate a combined popularity score
    void calculatePopularityScore(int currentYear) {
        int age = currentYear - releaseYear;
        double recencyWeight = exp(-0.1 * age); // Exponential decay for older items
        popularityScore = totalViews * 0.7 + userRating * 20 + recencyWeight * 50;
    }
};

// Sort for trending content: based on popularity score
void sortTrending(vector<MediaItem>& catalog, int currentYear) {
    for (auto& item : catalog) {
        item.calculatePopularityScore(currentYear);
    }
    sort(catalog.begin(), catalog.end(), [](const MediaItem& a, const MediaItem& b) {
        return a.popularityScore > b.popularityScore;
    });
}

// Sort for personalized recommendations: based on user preferences
void sortPersonalized(vector<MediaItem>& catalog, const vector<string>& userHistory) {
    sort(catalog.begin(), catalog.end(), [&userHistory](const MediaItem& a, const MediaItem& b) {
        // Check if items are in user's history
        bool aInHistory = find(userHistory.begin(), userHistory.end(), a.title) != userHistory.end();
        bool bInHistory = find(userHistory.begin(), userHistory.end(), b.title) != userHistory.end();

        // Prioritize items in history, then use popularity score as a tiebreaker
        if (aInHistory != bInHistory) {
            return aInHistory > bInHistory;
        }
        return a.popularityScore > b.popularityScore;
    });
}

// Utility function to display the catalog
void displayCatalog(const vector<MediaItem>& catalog) {
    for (const auto& item : catalog) {
        cout << "Title: " << item.title
             << ", Views: " << item.totalViews
             << ", Rating: " << item.userRating
             << ", Release Year: " << item.releaseYear
             << ", Popularity Score: " << item.popularityScore << "\n";
    }
}

int main() {
    int currentYear = 2024;

    // Sample catalog
    vector<MediaItem> catalog = {
        {"Movie A", 50000, 4.5, 2022},
        {"Movie B", 30000, 4.0, 2018},
        {"TV Show X", 100000, 4.8, 2023},
        {"Movie C", 20000, 3.5, 2019},
        {"TV Show Y", 40000, 4.2, 2021}
    };

    // User's viewing history
    vector<string> userHistory = {"Movie B", "TV Show Y"};

    // Sort and display trending content
    cout << "Trending Content:\n";
    sortTrending(catalog, currentYear);
    displayCatalog(catalog);

    // Sort and display personalized recommendations
    cout << "\nPersonalized Recommendations:\n";
    sortPersonalized(catalog, userHistory);
    displayCatalog(catalog);

    return 0;
}
