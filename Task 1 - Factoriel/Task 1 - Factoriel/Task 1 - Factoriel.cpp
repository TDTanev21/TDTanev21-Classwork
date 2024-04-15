#include <iostream>
using namespace std;


class Fact {
private:
    int number;
    int result;
public:
    Fact(int n)
    {
        number = n;
        result = 1;
    }
    void factoriel() {
        for (int i = 1; i <= number; ++i) {
            result *= i;
        }
    }
    int getResult() {
        return result;
    }
};
int main() {
    int num;
    cin >> num;
    Fact fact(num);
    fact.factoriel();
    cout << "Factoriel: " << fact.getResult();

}