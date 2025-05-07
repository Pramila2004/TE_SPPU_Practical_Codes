#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class Evaluation {
private:
    string name;
    map<string, vector<float>> competencies;
    map<string, vector<float>> performance;

    void printTable(map<string, vector<float>>& hashMap, bool isCompetency) {
        if (isCompetency) {
            cout << "\nCompetency Goals\n";
            cout << "Competency\t\tRating\tWeightage\tWeighted Score\n";
            for (auto& kv : hashMap) {
                cout << kv.first << "\t\t" << kv.second[0] << "\t" << kv.second[1] << "\t\t" << kv.second[2] << "\n";
            }
        } else {
            cout << "\nPerformance Goals\n";
            cout << "Goals\t\tRating\tWeightage\tWeighted Score\n";
            for (auto& kv : hashMap) {
                cout << kv.first << "\t\t" << kv.second[0] << "\t" << kv.second[1] << "\t\t" << kv.second[2] << "\n";
            }
        }
        cout << endl;
    }

    void input() {
        cout << "Enter rating from 1-3\n";
        cout << "Weightage should be equal to 100\n";
        int weightTotal = 0;
        for (auto& kv : competencies) {
            cout << "Enter rating for " << kv.first << ": ";
            cin >> kv.second[0];
            cout << "Enter weightage(" << 100 - weightTotal << " remaining): ";
            cin >> kv.second[1];
            weightTotal += kv.second[1];
        }
        for (auto& kv : performance) {
            cout << "Enter rating for " << kv.first << ": ";
            cin >> kv.second[0];
            cout << "Enter weightage(" << 100 - weightTotal << " remaining): ";
            cin >> kv.second[1];
            weightTotal += kv.second[1];
        }
    }

    void calcScore() {
        for (auto& kv : competencies) {
            kv.second[2] = kv.second[0] * kv.second[1] / 100.0;
        }
        for (auto& kv : performance) {
            kv.second[2] = kv.second[0] * kv.second[1] / 100.0;
        }
    }

public:
    Evaluation() {
        cout << "Enter name of employee: ";
        getline(cin, name);
        competencies = {
            {"Communication", {0, 0, 0}},
            {"Productivity", {0, 0, 0}},
            {"Creativity", {0, 0, 0}},
            {"Integrity", {0, 0, 0}},
            {"Punctuality", {0, 0, 0}}
        };
        performance = {
            {"Goal 1", {0, 0, 0}},
            {"Goal 2", {0, 0, 0}},
            {"Goal 3", {0, 0, 0}},
            {"Goal 4", {0, 0, 0}},
            {"Goal 5", {0, 0, 0}}
        };
    }

    void calculate() {
        input();
        calcScore();
        printTable(competencies, true);

        float sumCompetency = 0;
        for (auto& kv : competencies) {
            sumCompetency += kv.second[2];
        }
        cout << "Sum of weighted scores-Competency = " << sumCompetency << "\n" << endl;

        printTable(performance, false);
        float sumPerformance = 0;
        for (auto& kv : performance) {
            sumPerformance += kv.second[2];
        }
        cout << "Sum of weighted scores-Performance = " << sumPerformance << "\n" << endl;

        float total = sumCompetency + sumPerformance;
        cout << fixed << setprecision(2);
        cout << "Overall Rating of " << name << " (out of 3): " << total << "\n";

        if (total >= 2.7) {
            cout << "Employee Exceeds expectations" << endl;
        } else if (total >= 1.7 && total < 2.7) {
            cout << "Employee meets expectations" << endl;
        } else {
            cout << "Employee fails expectations" << endl;
        }
    }
};

int main() {
    Evaluation e;
    e.calculate();
    return 0;
}
