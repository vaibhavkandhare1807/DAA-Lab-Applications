#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

bool compare(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    double capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    Item* items = new Item[n];
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit >> items[i].weight;
        items[i].ratio = static_cast<double>(items[i].profit) / items[i].weight;
    }

    sort(items, items + n, compare);

    double totalProfit = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            totalProfit += items[i].profit * (capacity / items[i].weight);
            capacity = 0;
        }
    }

    cout <<"MaximumProfit:"<< totalProfit << endl;
    delete[] items;
    return 0;
}
