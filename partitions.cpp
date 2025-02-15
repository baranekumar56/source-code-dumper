#include <iostream>
#include <vector>

using namespace std;

vector<int> d = {1,2,3};

void partition(vector<vector<vector<int>>>& res, vector<vector<int>> cur_par, int ind) {

    if (ind == d.size()) {
        res.push_back(cur_par);

        return;
    }
    vector<int> t;
    for (int i = ind; i < d.size(); i++) {
        t.push_back(d[i]);
        cur_par.push_back(t);
        partition(res, cur_par, i + 1);
        cur_par.pop_back();
    }

}

int main() {
    vector<vector<vector<int>>> res;
    vector<vector<int>> cur_par;
    vector<int> curr;

    partition(res, cur_par, 0);

    for (auto& i: res) {
        for (auto& j: i) {
            for (auto& k: j) cout << k <<  " ";
            cout << endl;
        }cout << endl;
    }
}