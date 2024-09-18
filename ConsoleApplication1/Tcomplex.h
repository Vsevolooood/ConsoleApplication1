#ifndef TCOMPLEX_H
#define TCOMPLEX_H

#include <iostream>
#include <cmath>

class Tcomplex {
private:
    double real;
    double imag;

public:
    // Конструктор с параметрами и значениями по умолчанию
    Tcomplex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Конструктор ввода
    Tcomplex(std::istream& input) {
        std::cout << "Введите действительную часть: ";
        input >> real;
        std::cout << "Введите мнимую часть: ";
        input >> imag;
    }

    // Метод для отображения комплексного числа
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }

    // Перегрузка оператора ввода (>>) для удобства
    friend std::istream& operator>>(std::istream& input, Tcomplex& c) {
        std::cout << "Введите действительную часть: ";
        input >> c.real;
        std::cout << "Введите мнимую часть: ";
        input >> c.imag;
        return input;
    }

    // Перегрузка оператора вывода (<<) для удобства
    friend std::ostream& operator<<(std::ostream& output, const Tcomplex& c) {
        output << c.real << " + " << c.imag << "i";
        return output;
    }

    Tcomplex operator+(const Tcomplex& other) const {
        return Tcomplex(real + other.real, imag + other.imag);
    }

    // Перегрузка оператора вычитания
    Tcomplex operator-(const Tcomplex& other) const {
        return Tcomplex(real - other.real, imag - other.imag);
    }

    // Перегрузка оператора умножения
    Tcomplex operator*(const Tcomplex& other) const {
        return Tcomplex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Перегрузка оператора деления
    Tcomplex operator/(const Tcomplex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Tcomplex((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }

    // Метод для получения действительной части
    double getReal() const {
        return real;
    }

    // Метод для получения мнимой части
    double getImag() const {
        return imag;
    }

    // Метод для вычисления модуля комплексного числа
    double modulus() const {
        return std::sqrt(real * real + imag * imag);
    }

    // Перегрузка оператора меньше (<)
    bool operator<(const Tcomplex& other) const {
        return this->modulus() < other.modulus();
    }

    // Перегрузка оператора больше (>)
    bool operator>(const Tcomplex& other) const {
        return this->modulus() > other.modulus();
    }
    Tcomplex sqrt() const {
        double magnitude = std::sqrt(this->modulus());
        double angle = std::atan2(imag, real) / 2;
        return Tcomplex(magnitude * std::cos(angle), magnitude * std::sin(angle));
    }
};

#endif // TCOMPLEX_H