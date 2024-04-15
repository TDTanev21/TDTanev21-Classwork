#include <iostream>
using namespace std;

class Gcd {
private:
    int a;
    int b;

public:

    Gcd(int a, int b) {
        Gcd::a = a;
        Gcd::b = b;
    } 
    

    int evklidMethod() {
        int x = a;
        int y = b;
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
};

int main() {
    int a, b;
    while (true) {
        cin >> a >> b;
        if (a >= 0 && b >= 0) {
            break;
        }
        else {
            cout << "The numbers must be higher than 0!";
        }
    }

    Gcd gcd(a, b);
    int result = gcd.evklidMethod();
    cout << "GCD: " << result << endl;
}