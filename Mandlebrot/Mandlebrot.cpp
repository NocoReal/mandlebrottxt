#include <iostream>
#include <fstream>
#include <math.h>
#include <complex>

using namespace std;

int maxI = 256,sizeMap; // iterations
int Map[4096][4096];

complex<double> f(complex<double> z1, complex<double> c) {
    complex<double> z2;
    z2 = z1 * z1 + c;
    return z2;
}


int Mandlebrot(double x, double y) {
    complex<double> c(x,y);
    complex<double> z(0,0);
    for (int i = 1; i <= maxI; ++i)
    {
        z = f(z, c);
        if (abs(z) > 64) {
            return i;
        }
        if (i == maxI)
            return i;
    }
    if (abs(z) < 64 ) {
        return 0;
    }
}

int main()
{
    cin >> sizeMap;

    ofstream outFile("mandlebrot.txt");

    for (int i = 0; i < sizeMap*2; ++i) {
        for (int j = 0; j < sizeMap * 3; ++j) {
            double x, y;
            y = i; x = j;
            x -= sizeMap*2.25;
            y -= sizeMap*1;
            x /= sizeMap*1;
            y /= sizeMap*.75;
            switch (Mandlebrot(x, y)/8) {
            case 0:
                outFile << "@";
                break;
            case 1:
                outFile << "%";
                break;
            case 2:
                outFile << "#";
                break;
            case 3:
                outFile << "?";
                break;
            case 4:
                outFile << "/";
                break;
            case 5:
                outFile << "{";
                break;
            case 6:
                outFile << "[";
                break;
            case 7:
                outFile << "l";
                break;
            case 8:
                outFile << "i";
                break;
            case 9:
                outFile << "(";
                break;
            case 10:
                outFile << ";";
                break;
            case 11:
                outFile << "=";
                break;
            case 12:
                outFile << "-";
                break;
            case 13:
                outFile << "^";
                break;
            case 14:
                outFile << "'";
                break;
            case 15:
                outFile << " ";
                break;
            default:
                outFile << " ";
            }
        }
        outFile << "\n";
    }
    outFile.close();
    return 0;
}
