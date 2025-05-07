#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void evaluateEmployee() {
    cout << "=== Expert System: Employee Performance Evaluation ===\n";

    string name, role;
    int teamwork, punctuality, task_completion, communication, problem_solving, leadership;

    cout << "Enter Employee Name: ";
    getline(cin, name);

    cout << "Enter Role/Department: ";
    getline(cin, role);

    cout << "\nRate the following on a scale of 1 (Poor) to 5 (Excellent):\n";

    cout << "Teamwork: ";
    cin >> teamwork;

    cout << "Punctuality: ";
    cin >> punctuality;

    cout << "Task Completion: ";
    cin >> task_completion;

    cout << "Communication Skills: ";
    cin >> communication;

    cout << "Problem Solving: ";
    cin >> problem_solving;

    cout << "Leadership (if not applicable, rate as 3): ";
    cin >> leadership;

    int total_score = teamwork + punctuality + task_completion + communication + problem_solving + leadership;
    double average_score = total_score / 6.0;

    string remark, suggestion;

    if (average_score >= 4.5) {
        remark = "Outstanding";
        suggestion = "Keep up the great work. Consider for leadership roles or promotions.";
    } else if (average_score >= 3.5) {
        remark = "Good";
        suggestion = "Consistent performance. Minor improvements will boost further.";
    } else if (average_score >= 2.5) {
        remark = "Average";
        suggestion = "Needs improvement in some areas. Consider targeted training.";
    } else {
        remark = "Below Average";
        suggestion = "Immediate attention needed. Schedule a performance review and support plan.";
    }

    cout << "\n=== Performance Report ===\n";
    cout << "Employee Name: " << name << endl;
    cout << "Department/Role: " << role << endl;
    cout << "Average Score: " << fixed << setprecision(2) << average_score << "/5" << endl;
    cout << "Performance Remark: " << remark << endl;
    cout << "Recommendation: " << suggestion << endl;
}

int main() {
    evaluateEmployee();
    return 0;
}
