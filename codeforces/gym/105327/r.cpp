#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num_tables;
    cin >> num_tables; 
    vector<long long> happiness(num_tables);
    for (int i = 0; i < num_tables; i++)  {
        cin >> happiness[i];
    }
    long long maximum_happ_subarr = 0; 
    long long maximum_happ_curr = 0; 
    for (int i = 0; i < num_tables; i++) {
        maximum_happ_curr = max(happiness[i], happiness[i] + maximum_happ_curr);
        maximum_happ_subarr = max(maximum_happ_subarr, maximum_happ_curr);
    }
    cout << maximum_happ_subarr << '\n';
    return 0;
}