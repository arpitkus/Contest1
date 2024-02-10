#include "testlib.h"
#include<iostream>
#include<fstream>
using namespace std;

void checker(int n,  ofstream& output) {
    output  <<__builtin_popcountll(n)<< '\n';
}

void generate(ofstream& input , ofstream& output) {
    // Set the range for n (1 <= n <= 1e18)
    int64_t power = rnd.next(0LL, 60LL);  // Random power of 2 between 0 and 60
    int64_t n = (1LL << power);
    input << n << '\n';
    checker(n, output);
    n = rnd.next(1LL, 100LL);
    input << n << '\n';
    checker(n , output);
    n = rnd.next(1LL, 1000000000000000000LL);
    input << n << '\n';
    checker(n , output);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ofstream input("input_A.txt");
    ofstream output("output_A.txt");
    if (!input.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    for (int i = 0; i < 100; ++i) {
        generate(input , output);
    }

    input.close();

    return 0;
}
