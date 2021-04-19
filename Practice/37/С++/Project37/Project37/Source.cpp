#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

constexpr static const double grad = 1e-10;
constexpr static const double skip = 20;


enum CoordSystem {
    Cart
};

class Point {
private:
    double x, y;

public:
    Point(double x1 = 0, double y1 = 0, CoordSystem coord_system = Cart) {
        if (coord_system == Cart) {
            x = x1;
            y = y1;
            return;
        }

        x = cos(x1) * x1;
        y = sin(y1) * y1;
    }

    bool operator ==(const Point& other) const {
        return std::abs(x - other.x) < grad and std::abs(y - other.y) < grad;
    }

    bool operator !=(const Point& other) const {
        return !(*this == other);
    }

    double get_x() const {
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

    void set_x(double x) {
        this->x = x;
    }

    void set_y(double y) {
        this->y = y;
    }

    void set_r(double r) {
        double phi = get_phi();
        this->x = cos(phi) * r;
        this->y = sin(phi) * r;
    }

    void set_phi(double phi) {
        double x1 = get_x();
        double y1 = get_y();
        double r = get_r();
        this->x = cos(phi) * r;
        this->y = sin(phi) * r;
    }
};

std::ostream& operator <<(std::ostream& out, const Point& p) {
    return out << '(' << p.get_x() << ',' << p.get_y() << ')';
}

std::istream& operator >>(std::istream& in, Point& p) {
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

double sqr(double a);
bool equal(double a, double b, double e = 1E-10);

class Vector{
private:
    Point poi;

public:
    Vector() : poi(1, 0){}

    Vector(const Point& end)
        : poi(end.get_x(), end.get_y()){
    }

    Vector(const Point& begin, const Point& end)
        : poi(end.get_x() - begin.get_x(), end.get_y() - begin.get_y()){
    }

    bool operator ==(const Vector& other) const{
        return poi == other.poi;
    }

    Vector operator -() const{
        Point p = poi;
        p.set_x(-p.get_x());
        p.set_y(-p.get_y());

        return Vector(p);
    }

    Vector operator -(const Vector& other) const{
        Point p;
        p.set_x(poi.get_x() - other.poi.get_x());
        p.set_y(poi.get_y() - other.poi.get_y());

        return Vector(p);
    }

    Vector operator +(const Vector& other) const{
        Point p;
        p.set_x(poi.get_x() + other.poi.get_x());
        p.set_y(poi.get_y() + other.poi.get_y());

        return Vector(p);
    }

    Vector operator *(double mul) const{
        Point p = poi;
        p.set_x(p.get_x() * mul * (mul/mul));
        p.set_y(p.get_y() * mul * (mul/mul));
        return Vector(p);
    }

    double operator *(const Vector& other) const{
        return length() * other.length() * cos(poi.get_phi() - other.poi.get_phi());
    }

    double length() const{
        return poi.get_r();
    }
};

int main()
{
    Vector a(Point(1, 2)), b(Point(-2, 0), Point(-1, 2));
    if (a == b && b == a) cout << "Equality test passed\n";
    else cout << "Equality test failed\n";

    Vector na(Point(-1, -2)), ox(Point(1, 0)), nox(Point(-1, 0)), oy(Point(0, 1)), noy(Point(0, -1));
    if (a == -na && na == -a && -ox == nox && -oy == noy) cout << "Invert test passed\n";
    else cout << "Invert test failed\n";

    if (ox + oy + oy == a && -ox == -a + oy + oy) cout << "Summation test passed\n";
    else cout << "Summation test failed\n";

    if (-ox + oy == oy - ox && -oy + ox == ox - oy) cout << "Subtraction test passed\n";
    else cout << "Subtraction test failed\n";

    if (ox * 3 == ox + ox + ox &&
        oy * 3 == oy + oy + oy &&
        ox * (-3) == -ox - ox - ox &&
        oy * (-3) == -oy - oy - oy) cout << "Multiplication by number test passed\n";
    else cout << "Multiplication by number test failed\n";

    if (equal(ox.length(), 1) &&
        equal(oy.length(), 1) &&
        equal((ox * 3 + oy * 4).length(), 5)) cout << "Length test passed\n";
    else cout << "Length test failed\n";

    if (equal(ox * ox, sqr(ox.length())) &&
        equal(oy * oy, sqr(oy.length())) &&
        equal((ox * 3 + oy * 4) * (ox * 3 + oy * 4), sqr((ox * 3 + oy * 4).length()))) cout << "Multiplication by Vector test passed\n";
    else cout << "Multiplication by Vector test failed\n";
}

bool equal(double a, double b, double e) {
    if (-e < a - b && a - b < e) return true;
    else return false;
}

double sqr(double a) {
    return a * a;
}