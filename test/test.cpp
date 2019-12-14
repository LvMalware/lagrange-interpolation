#include <iostream>
#include "../src/lagrange.hpp"

using namespace std;

int
main(int argc, char *argv[])
{
    Lagrange interp;
    interp.loadData("data.txt");
    cout << "+-----------------------+" << endl;
    cout << "|   YEAR  |  ACCIDENTS  |" << endl;
    cout << "+-----------------------+" << endl;
    for (int year = 2008; year < 2018; year++)
    {
        cout << "|  " << year << "   |\t" <<
            interp.interpolate(year) << "\t|" << endl;
    }
    cout << "+-----------------------+" << endl;
    return 0;
}