#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "point_in_poly.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        cout << "Error. Program takes 4 arguments as input" << endl;
        exit(-1);
    }
    else
    {
        ifstream f(argv[1]);
        double x_dot = atof(argv[2]), y_dot = atof(argv[3]);
        double x, y;
        vector<double> xarr, yarr;

        while (f >> x >> y)
        {
            if (f.good())
            {
                xarr.push_back(x);
                yarr.push_back(y);
            }
            else
            {
                cout << "Error while opening file " << endl;
                exit(-1);
            }

        }
        int result = is_point_inside_polygon(xarr, yarr, x_dot, y_dot);
        switch (result)
        {
            case -1:
                cout << "Point is on the edge" << endl;
                break;
            case 0:
                cout << "Point is inside" << endl;
                break;
            case 1:
                cout << "Point is outside" << endl;
                break;
            default:
                cout << "Smth went wrong" << endl;
                break;
        }
    }
    return 0;
}
