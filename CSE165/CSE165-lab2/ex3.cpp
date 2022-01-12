#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    string num = "";
    if(argc != 2) {
        cout << "Must provide a number" << endl;
        exit(1);
    }

    double d = atof(argv[1]);
    unsigned char* cp = reinterpret_cast<unsigned char*>(&d);

    for(int i = sizeof(double); i > 0; i -= 2) {

        for(int j = 7; j >= 0; j--) {
            if(cp[j-1] & (1 << j)) {
                num = num + "1";
            }
            else {
                num = num + "0";
            }
        }

        for(int k = 7; k >= 0; k--) {
            if(cp[k] & (1 << k)) {
                num = num + "1";
            }
            else {
                num = num + "0";
            }
        }

    }

    cout << "Sign    : " << num[0]             << endl;
    cout << "Exponent: " << num.substr( 1, 12) << endl;
    cout << "Fraction: " << num.substr(13, 63) << endl;
}