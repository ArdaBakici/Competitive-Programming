#include <iostream>
#include <algorithm>

using namespace std;
 
int main() {
    double sideArray[3];
    double sideA, sideB, sideC, temp;
    cin >> sideArray[0] >> sideArray[1] >> sideArray[2];
    
    std::sort(std::begin(sideArray), std::end(sideArray), greater<int>());

    /*
    
    if A ≥ B + C, write the message: NAO FORMA TRIANGULO
    if A2 = B2 + C2, write the message: TRIANGULO RETANGULO
    if A2 > B2 + C2, write the message: TRIANGULO OBTUSANGULO
    if A2 < B2 + C2, write the message: TRIANGULO ACUTANGULO
    if the three sides are the same size, write the message: TRIANGULO EQUILATERO
    if only two sides are the same and the third one is different, write the message: TRIANGULO ISOSCELES

    */
    if(sideArray[0] >= sideArray[1] + sideArray[2]) cout << "NAO FORMA TRIANGULO" << endl;
    else if((sideArray[0] * sideArray[0]) == ((sideArray[1] * sideArray[1]) + (sideArray[2] * sideArray[2]))) cout << "TRIANGULO RETANGULO" << endl;
    else if((sideArray[0] * sideArray[0]) > ((sideArray[1] * sideArray[1]) + (sideArray[2] * sideArray[2]))) cout << "TRIANGULO OBTUSANGULO" << endl;
    else if((sideArray[0] * sideArray[0]) < ((sideArray[1] * sideArray[1]) + (sideArray[2] * sideArray[2]))) cout << "TRIANGULO ACUTANGULO" << endl;
    if(sideArray[0] == sideArray[2]) cout << "TRIANGULO EQUILATERO" << endl;
    else if(sideArray[0] == sideArray[1] || sideArray[1] == sideArray[2]) cout << "TRIANGULO ISOSCELES" << endl;

    return 0;
}
