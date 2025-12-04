#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long total = 0;
vector<long long> contribution;
vector<int> last_level;

struct Mountain {
    long long index;
    long long height;
};

vector<Mountain> temp;

void merge(vector<Mountain>& l, int left, int middle, int right, int level) {
    long long k = left;
    long long i = left;
    long long j = middle + 1;
    while (i <= middle && j <= right) {
        if (l[i].height < l[j].height) {
            temp[k] = l[i];
            k++; 
            i++;
        } else {
            temp[k] = l[j];
            total += middle - i + 1;
            long long count = middle - i + 1;
            contribution[l[j].index] = count;
            last_level[l[j].index] = level;
            k++; 
            j++;
        }
    }
    while (i <= middle) {
        temp[k] = l[i];
        k++;
        i++;
    }
    while (j <= right) {
        temp[k] = l[j];
        k++;
        j++;
    }
    if (level != 0) {
    for (int i = left; i <= right; i++) {
        l[i] = temp[i];
    }
    }
}


void mergeSort(vector<Mountain>& l, int left, int right, int level) {
    if (left >= right)  {
        return;
    }
    int middle = (left + right) / 2;
    mergeSort(l, left, middle, level + 1);
    mergeSort(l, middle + 1, right, level + 1);
    merge(l, left, middle, right, level);
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int num_mountains;
    cin >> num_mountains;
    vector<Mountain> mountains(num_mountains);
    last_level.assign(num_mountains, -1);
    contribution.assign(num_mountains, 0);
    temp.resize(num_mountains);
    for (int i = 0; i < num_mountains; i++) {
        int mountain;
        cin >> mountain;
        mountains[i] = {i, mountain};
    }
    mergeSort(mountains, 0, num_mountains - 1, 0);
    cout << total << "\n"; 
    for (int i = 0; i < num_mountains; i++) { 
        cout << contribution[i];
        if (i != num_mountains - 1) {
            cout << " ";
        } 
    }
    cout << "\n";
    return 0;
}
 