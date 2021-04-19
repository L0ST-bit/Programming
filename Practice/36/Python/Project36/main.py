import math
import copy

grad = 1e-10

class Point:
    def __init__(self, a1=0, a2=0, coord_system = 'Cartesian'):
        if type(a1) == str:
            p = a1.find(',')
            self.x = float(a1[1: p].strip())
            self.y = float(a1[p + 1: -2].strip())
            return

        if (coord_system == 'Cartesian'):
            self.x = a1
            self.y = a2
            return

        else:
            self.x = math.cos(a2) * a1
            self.y = math.sin(a2) * a1

    def __eq__(self, p):
        return type(p) == Point and (abs(self.x - p.x) < grad) and (abs(self.y - p.y) < grad)

    def __ne__(self, p):
        return not self == p

    def get_x(self):
        return self.x

    def set_x(self, x):
        self.x = x

    def get_y(self):
        return self.y

    def set_y(self, y):
        self.y = y

    def get_r(self):
        return math.hypot(self.x, self.y)

    def set_r(self, r):
        phi = self.get_phi()
        self.x = math.cos(phi) * r
        self.y = math.sin(phi) * r

    def get_phi(self):
        return math.atan2(self.y, self.x)

    def set_phi(self, phi):
        r = self.get_r()
        self.x = math.cos(phi) * r
        self.y = math.sin(phi) * r

    def __repr__(self):
        return f"Point({self.x},{self.y})"

    def __str__(self):
        return f"({self.x},{self.y})"


if __name__ == '__main__':
    with open('data.txt') as file:
        original = [Point(point) for point in file.readline().split(', ')]

    simulacrum = copy.deepcopy(original)
    for point in simulacrum:
        print(point, end='')
        point.set_x(point.get_x() + 10)
        point.set_phi(point.get_phi() + 180 * math.pi / 180)
        point.set_y(-point.get_y())
        point.set_x(-point.get_x() - 10)
        print(point)

    print('\nIt works!\n' if simulacrum == original else '\nIt not works!\n')