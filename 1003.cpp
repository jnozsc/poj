#include <iostream>
using namespace std;

float hangoverResult(int card) {
    float result = 0;
    for (int i = 2; i <= card; i++) {
        result += 1.0 / i;
    }
    return result;
}

int hangover(float input) {
    int result = 2;
    while (hangoverResult(result) < input) {
        result++;
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
