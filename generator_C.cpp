#include "testlib.h"
#include<iostream>
#include<fstream>
using namespace std;

void checker(int n, int m , ofstream& output) {
    long long a = n , b = m;
	if(a > b)
		swap(b,a);
	for(int i = 0 ; i <= 1e6 ; i++){
		long long sum = i*(i+1)/2;
		if(sum >= b-a){
			if((b-a+sum)%2==0 && (b-a+sum)/2 <= sum){
				output << i << '\n';break;
			}
		}
	}
}

void generate(ofstream& input , ofstream& output) {
    // The number of scenarios (1 ≤ t ≤ 100)
    int t = rnd.next(1, 100);
    input << t  << '\n';
    int i = 0;
    for(int i = 0 ; i <  t - 50 ; i++){
        int a = rnd.next(1 , 1000);
        int b = rnd.next(1,1000);
        input << a << ' ' << b << '\n';
        checker(a,b,output);
    }
    for ( ; i < t-1; ++i) {
        // For each scenario, generate values of a and b with different differences
        int a = rnd.next(1000, 1000000000);
        int b = rnd.next(1000, 1000000000);
        input << a << ' ' << b << '\n';
        checker(a,b , output);
    }
    int a = rnd.next(1,1000000000);
    int b = a;
    input << a << ' ' << b << '\n';
    checker(a,b,output);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ofstream input("input_C.txt");
    ofstream output("output_C.txt");
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
