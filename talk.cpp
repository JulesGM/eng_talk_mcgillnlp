#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <random>
using namespace std;


void busy_work(int n, double* result) {
    *result = 1;
    for (int i = 1; i <= n; i++) {
        *result = fmod(*result + rand(), 10000000);
    }
}

vector<double> run(int n_threads, int fn_arg) {
    vector<double> results(n_threads, 0);
    std::thread* threads[n_threads];

    for (int i = 0; i < n_threads; i++) {
        threads[i] = new std::thread(busy_work, fn_arg, &results[i]);
    }
    for (int i = 0; i < n_threads; i++) {
        threads[i]->join();
    }

    return results;
}

int main(int argc, char** argv) {
    vector<double> results = run(1, 50000000);
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    return 0;
}