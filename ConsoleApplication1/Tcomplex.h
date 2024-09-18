#ifndef TCOMPLEX_H
#define TCOMPLEX_H

#include <iostream>
#include <cmath>

class Tcomplex {
private:
    double real;
    double imag;

public:
    // ����������� � ����������� � ���������� �� ���������
    Tcomplex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // ����������� �����
    Tcomplex(std::istream& input) {
        std::cout << "������� �������������� �����: ";
        input >> real;
        std::cout << "������� ������ �����: ";
        input >> imag;
    }

    // ����� ��� ����������� ������������ �����
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }

    // ���������� ��������� ����� (>>) ��� ��������
    friend std::istream& operator>>(std::istream& input, Tcomplex& c) {
        std::cout << "������� �������������� �����: ";
        input >> c.real;
        std::cout << "������� ������ �����: ";
        input >> c.imag;
        return input;
    }

    // ���������� ��������� ������ (<<) ��� ��������
    friend std::ostream& operator<<(std::ostream& output, const Tcomplex& c) {
        output << c.real << " + " << c.imag << "i";
        return output;
    }

    Tcomplex operator+(const Tcomplex& other) const {
        return Tcomplex(real + other.real, imag + other.imag);
    }

    // ���������� ��������� ���������
    Tcomplex operator-(const Tcomplex& other) const {
        return Tcomplex(real - other.real, imag - other.imag);
    }

    // ���������� ��������� ���������
    Tcomplex operator*(const Tcomplex& other) const {
        return Tcomplex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // ���������� ��������� �������
    Tcomplex operator/(const Tcomplex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Tcomplex((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }

    // ����� ��� ��������� �������������� �����
    double getReal() const {
        return real;
    }

    // ����� ��� ��������� ������ �����
    double getImag() const {
        return imag;
    }

    // ����� ��� ���������� ������ ������������ �����
    double modulus() const {
        return std::sqrt(real * real + imag * imag);
    }

    // ���������� ��������� ������ (<)
    bool operator<(const Tcomplex& other) const {
        return this->modulus() < other.modulus();
    }

    // ���������� ��������� ������ (>)
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