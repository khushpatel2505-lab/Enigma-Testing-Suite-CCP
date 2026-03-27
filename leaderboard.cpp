#include "Leaderboard.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct ScoreEntry {
    string username;
    int score;
};

void Leaderboard::saveScore(const string& username, int score) {
    ofstream file("scores.txt", ios::app);
    file << username << " " << score << endl;
}

void Leaderboard::showLeaderboard() {
    ifstream file("scores.txt");
    vector<ScoreEntry> scores;
    ScoreEntry entry;

    while (file >> entry.username >> entry.score) {
        scores.push_back(entry);
    }

    sort(scores.begin(), scores.end(), [](ScoreEntry a, ScoreEntry b) {
        return a.score > b.score;
    });

    cout << "\n=== LEADERBOARD ===\n";
    for (int i = 0; i < scores.size(); i++) {
        cout << i + 1 << ". " << scores[i].username
             << " - Score: " << scores[i].score << endl;
    }
}
