#include <stdexcept>
#include <cmath>
#include <iostream>

struct VolumeCalculator {
    // ОБЪЕМ КУБА
    // Формула: V = a³, где a — длина стороны куба
    static double cubeVolume(double side) {
        if (side <= 0) {
            throw std::invalid_argument("Сторона куба должна быть положительной");
        }
        return side * side * side;
    }
    // ОБЪЕМ СФЕРЫ
    // Формула: V = (4/3) * π * r³, где r — радиус сферы
        static double sphereVolume(double radius) {
        if (radius <= 0) {
            throw std::invalid_argument("Радиус сферы должен быть положительным");
        }
        return (4.0 / 3.0) * 3.14 * radius * radius * radius;
    }
    // ОБЪЕМ ЦИЛИНДРА
    // Формула: V = π * r² * h, где r — радиус основания, h — высота
    static double cylinderVolume(double radius, double height) {
        if (radius <= 0) {
            throw std::invalid_argument("Радиус цилиндра должен быть положительным");
        }
        if (height <= 0) {
            throw std::invalid_argument("Высота цилиндра должна быть положительной");
        }
        return 3.14 * radius * radius * height;
    }
    // ОБЪЕМ КОНУСА
    // Формула: V = (1/3) * π * r² * h, где r — радиус, h — высота
    static double coneVolume(double radius, double height) {
        if (radius <= 0) {
            throw std::invalid_argument("Радиус конуса должен быть положительным");
        }
        if (height <= 0) {
            throw std::invalid_argument("Высота конуса должна быть положительной");
        }
        return (1.0 / 3.0) * 3.14 * radius * radius * height;
    }
};
int main() {
    setlocale(0, "");
    std::cout << "Куб (a=3):       " << VolumeCalculator::cubeVolume(3) << std::endl;
    std::cout << "Сфера (r=2):     " << VolumeCalculator::sphereVolume(2) << std::endl;
    std::cout << "Цилиндр (r=2,h=5): " << VolumeCalculator::cylinderVolume(2, 5) << std::endl;
    std::cout << "Конус (r=2,h=5): " << VolumeCalculator::coneVolume(2, 5) << std::endl;
    return 0;
}