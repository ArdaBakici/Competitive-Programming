#include <iostream>
 
using namespace std;
 
int main() {
    double radius;
    double pi = 3.14159;
    cin >> radius;
    cout.precision(4);
    cout << "A=" << std::fixed << (radius*radius*pi)<< endl;
    return 0;
}
