#include <iostream>
using namespace std;

int hangover(float input) {
    int result = 2;
    float sum = 1.0 / result;
    while (sum < input) {
        result++;
        sum += 1.0 / result;
    }
    return result - 1;
}

int main(void) {
    float input;
    while (cin >> input) {
        if (input < 0.00000001) { // zero
            continue;
        } else if (input < 0.5) {
            cout << "1 card(s)" << endl;
        } else {
            cout << hangover(input) << " card(s)" << endl;
        }
    }
    return 0;
}
