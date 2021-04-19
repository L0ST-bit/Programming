#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

constexpr static const double grad = 1e-10;
constexpr static const double skip = 20;

enum CoordSystem{
    Cart
};

class Point{
private:
    double x, y;

public:
    Point(double x1 = 0, double y1 = 0, CoordSystem coord_system = Cart){
        if (coord_system == Cart){
            x = x1;
            y = y1;
            return;
        }

        x = cos(x1) * x1;
        y = sin(y1) * y1;
    }

    bool operator ==(const Point& other) const{
        return abs(x - other.x) < grad and abs(y - other.y) < grad;
    }

    bool operator !=(const Point& other) const{
        return !(*this == other);
    }

    double get_x() const{
        return x;
    }

    double get_y() const {
        return y;
    }

    double get_r() const {
        return sqrt(x * x + y * y);
    }

    double get_phi() const {
        return atan(y / x) + (x < 0 ? PI : 0);
    }

    void set_x(double x){
        this->x = x;
    }

    void set_y(double y){
        this->y = y;
    }

    void set_r(double r){
        double phi = get_phi();
        this->x = cos(phi) * r;
        this->y = sin(phi) * r;
    }

    void set_phi(double phi){
        double x1 = get_x();
        double y1 = get_y();
        double r = get_r();
        this->x = cos(phi) * r;
        this->y = sin(phi) * r;
    }
};

ostream& operator <<(ostream& out, const Point& p){
    return out << '(' << p.get_x() << ',' << p.get_y() << ')';
}

istream& operator >>(istream& in, Point& p){
    double a;
    in.ignore(skip, '(');
    in >> a;
    p.set_x(a);
    in.ignore(skip, ',');
    in >> a;
    p.set_y(a);
    in.ignore(skip, ')');
    return in;
}

int main()
{
    std::vector<Point> original;
    std::ifstream file("data.txt");

    if (!file.is_open())
    {
        std::cout << "File not exists or can't read file" << std::endl;
        return 1;
    }

    while (!file.eof())
    {
        Point p;
        file >> p;

        file.ignore(2);
        original.push_back(p);
    }

    file.close();

    std::vector<Point> simulacrum(original);

    for (auto& p : simulacrum)
    {
        std::cout << p;
        p.set_x(p.get_x() + 10);
        p.set_phi(p.get_phi() + 180 * PI / 180);
        p.set_y(-p.get_y());
        p.set_x(-p.get_x() - 10);
        std::cout << p << std::endl;
    }

    if (std::equal(original.begin(), original.end(), simulacrum.begin()))
    {
        std::cout << "\nIt works!\n";
    }
    else
    {
        std::cout << "\nIt not works!\n";
    }
}