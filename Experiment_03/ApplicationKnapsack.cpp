#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Cargo {
    int id;
    string name;
    double weight;
    double value;
    double ratio;
};
bool compare(const Cargo& a, const Cargo& b) {
    return a.ratio > b.ratio;
}
int main() {
    int n;
    double capacity;
    cout << "Enter number of cargo items: ";
    cin >> n;
    cout << "Enter truck capacity (in weight units): ";
    cin >> capacity;
    vector<Cargo> items(n);
    cout << "Enter cargo details (ID Name Weight Value):";
    for (int i = 0; i < n; i++) {
        cin >> items[i].id >> items[i].name >> items[i].weight >> items[i].value;
        items[i].ratio = items[i].value / items[i].weight;
    }
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    double remaining = capacity;
    cout << fixed << setprecision(2);
    cout << "Cargo Loading Plan:";
    cout << "ID	Name	Taken(Weight)	Value";
    for (int i = 0; i < n && remaining > 0; ++i) {
        if (items[i].weight <= remaining) {
            remaining -= items[i].weight;
            totalValue += items[i].value;
            cout << items[i].id << "	" << items[i].name << "	" 
                 << items[i].weight << "		" << items[i].value << endl;
        } else {
            double fraction = remaining / items[i].weight;
            double valueTaken = items[i].value * fraction;
            totalValue += valueTaken;
            cout << items[i].id << "	" << items[i].name << "	" 
                 << remaining << "		" << valueTaken 
                 << " (Fraction: " << fraction << ")";
            remaining = 0;
        }
    }
    cout << "Total Value Loaded: " << totalValue << endl;
    cout << "Unused Capacity: " << remaining << endl;
    return 0;
}
