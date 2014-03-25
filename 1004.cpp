#include<iostream>

using namespace std;

int main(void) {
    double money;
    double all = 0.0;
    while (cin >> money) {
        all += money;
    }
    cout << "$" << (all / 12.0) << endl;
    return 0;
}