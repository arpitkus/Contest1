#include "testlib.h"
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
const int N = 1e6+1;

void checker(const set<int>& st, ofstream& output) {
    int n = st.size();
    vector<int> dp(N+1, 0); 
    for(auto& x : st){
        dp[x]+=1;
    }
    int ans = 0;
    for(int i = N ; i >= 1 ; i--){
        if(!dp[i]) continue;
        for(int j = 2*i ; j <= N ; j+=i){
            dp[i] = max(dp[i] , dp[j]+1);
        }
        ans = max(dp[i] , ans);
    }
    output << ans << '\n';
}

void generate(ofstream& input , ofstream& output) {
    int n = rnd.next(100, 1000);
    input << n << endl;
    set<int> st;
    while(st.size() < n){
        st.insert(rnd.next(100,1000000));
    }
    for(auto&x: st){
        input << x << ' ';
    }
    input << '\n';
    checker(st , output);



    int m = rnd.next(1,100);
    input << m << '\n';

    st.clear();

    while(st.size() < m){
        st.insert(rnd.next(1,1000000));
    }
    for(auto&it:st){
        input  << it<< ' ';
    }
    input  << '\n';
    checker(st,output);
    
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ofstream input("input_D.txt");
    ofstream output("output_D.txt");
    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening input or output file." << endl;
        return 1;
    }

    for (int i = 0; i < 10; ++i) {
        generate(input, output);
    }

    input.close();
    output.close();

    return 0;
}
