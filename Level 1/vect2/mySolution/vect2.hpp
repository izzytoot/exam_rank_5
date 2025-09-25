
#pragma once

#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class vect2{
    private:
        std::vector<int> _vec;

    public:
        vect2();
        vect2(int x, int y);
        vect2(const vect2& src);
        vect2& operator= (const vect2& src);
        ~vect2();

        int& operator[] (unsigned int index);
        int operator[] (unsigned int index) const;

        vect2 operator+ (const vect2& other) const;
        vect2 operator- (const vect2& other) const;
        vect2 operator* (const vect2& other) const;
        vect2& operator+= (const vect2& other);
        vect2& operator-= (const vect2& other);
        vect2& operator*= (const vect2& other);

        bool operator== (const vect2& other);
        bool operator!= (const vect2& other);
};

std::ostream& operator<< (std::ostream& output, const vect2& obj);