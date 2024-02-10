#include "testlib.h"
#include<iostream>
#include<fstream>
using namespace std;

void checker(int n, int m , ofstream& output) {
    output  << n / 3 - (m - 1) / 3 << '\n';
}

void generate(ofstream& outputFile , ofstream& output) {
    int n , m;
    // Test case 1: Small range
    m = rnd.next(1, 500);
    n = rnd.next(m, 500);
    outputFile << m << " " << n << endl;
    checker(n, m, output);

    // Test case 2: Medium range
    m = rnd.next(100, 900);
    n = rnd.next(m, 900);
    outputFile << m << " " << n << endl;
    checker(n, m,output);

    // Test case 3: Large range
    m = rnd.next(900, 2000);
    n = rnd.next(m, 2000);
    outputFile << m << " " << n << endl;
    checker(n, m,output);

    // Test case 4: Equal values
    int value = rnd.next(1, 2000);
    outputFile << value << " " << value << endl;
    checker(value, value,output);

    // Test case 5: Random values
    m = rnd.next(1, 2000);
    n = rnd.next(m, 2000);
    outputFile << m << " " << n << endl;
    checker(n, m,output);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ofstream outputFile("input_B.txt");
    ofstream output("output_B.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    for (int i = 0; i < 1000; ++i) {
        generate(outputFile , output);
    }

    outputFile.close();

    return 0;
}
