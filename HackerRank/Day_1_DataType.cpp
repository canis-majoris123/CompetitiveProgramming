//https://www.hackerrank.com/challenges/30-data-types/problem

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    int i2;
    double d2;
    string s2;
    string temp;
    getline(cin, temp);
    i2 = stoi(temp);
    getline(cin, temp);
    d2 = stod(temp);
    getline(cin, s2);
    printf("%i\n", i+i2);
    printf("%.1f", d+d2);
    cout << endl << s + s2 << endl;

    return 0;
}
