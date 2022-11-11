#include <iostream>
#include <vector>
#include <cmath>
#include <numbers>

using namespace std;

double get_dir(double first[3], double second[3]) {
    double cx = 0, cy = 0, cz = 1;
    double sub = first[0] * second[1] * cz + first[1] * second[2] * cx + second[0] * cy * first[2] -
                 first[2] * second[1] * cx - second[0] * first[1] * cz - first[0] * cy * second[2];
    int sign = (sub >= 0) ? 1 : -1;
    return sign;
}

double norm(double vector[3])
{
    return std::sqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
}

int is_point_inside_polygon(vector<double> x_arr, vector<double> y_arr, double x, double y)
{

    int is_outside = 0;
    double first[3];
    double second[3];
    double eps = 1e-5;
    vector<double> angles;
    double summary_angle = 0;

    for (int i = 0; i < x_arr.size() - 1; ++i)
    {

        double x1 = x_arr[i];
        double x2 = x_arr[i + 1];
        double y1 = y_arr[i];
        double y2 = y_arr[i + 1];

        first[0] = x1 - x;
        first[1] = y1 - y;
        first[2] = 0;

        second[0] = x2 - x;
        second[1] = y2 - y;
        second[2] = 0;

        double dir = get_dir(first, second);

        double norm_a = norm(first);
        double norm_b = norm(second);

        if ((norm_a < eps) || (norm_b < eps))
        {
            return -1;
        }

        double cos_alpha = (first[0] * second[0] + first[1] * second[1]) / (norm_a * norm_b);

        double alpha = std::acos(cos_alpha);
        alpha = alpha * dir;

        if (fabs(fabs(alpha) - 3.1415926535) < eps)
        {
            return -1;
        }
        summary_angle += alpha * dir;
    }
    is_outside = !(fabs(fabs(summary_angle) - 2 * M_PI) < eps);

    return is_outside;
}
