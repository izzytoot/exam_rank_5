#pragma once

#include <iomanip>
#include <iostream>
#include <limits.h>

class bigint{
    private:
        std::string _digits;

    public:
        bigint();
        bigint(long long n);
        bigint(std::string str);
        bigint(const bigint& src);
        bigint& operator= (const bigint& src);
        ~bigint();

        std::string getDigits() const;
        
        bigint operator+ (const bigint& other) const;
        bigint& operator+= (const bigint& other);

        bigint operator++ (int);
        bigint& operator++ ();

        bool operator== (const bigint& other) const;
        bool operator!= (const bigint& other) const;
        bool operator> (const bigint& other) const;
        bool operator>= (const bigint& other) const;
        bool operator< (const bigint& other) const;
        bool operator<= (const bigint& other) const;

        bigint operator<< (int n);
        bigint operator>> (int n);
        bigint& operator<<= (int n);
        bigint& operator>>= (int n);

        bigint& operator<<= (const bigint& other);
        bigint& operator>>= (const bigint& other);
        bigint& operator<< (const bigint& other);
        bigint& operator>> (const bigint& other);
};

std::ostream& operator<< (std::ostream& output, const bigint& obj);
int toInt(const bigint& obj);