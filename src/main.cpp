#include <iostream>
#include "lagrange.hpp"

using namespace std;

int
main(int argc, char *argv[])
{
    Lagrange interpolator;
    interpolator.loadData("data.txt");
    long double y;
    interpolator.interpolate(2015, y);
    cout << "Got: " << y << endl;
    return 0;
}
