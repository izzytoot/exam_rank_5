#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>

class bigint{
    private:
        std::string _digits;
        void remove_zeros();

    public:
        bigint();
        bigint(unsigned long long n);
        bigint(std::string str);
        bigint(const bigint& src);

        bigint& operator= (const bigint& src);

        ~bigint();

        std::string getDigits() const;
        std::string toString(const bigint& obj) const;

        bool operator <(const bigint& other) const;
        bool operator >(const bigint& other) const;
        bool operator <=(const bigint& other) const;
        bool operator >=(const bigint& other) const;
        bool operator ==(const bigint& other) const;
        bool operator !=(const bigint& other) const;

        //addition + +=
        bigint operator+ (const bigint& other) const;
        bigint& operator+= (const bigint& other);
        
        //increment ++x x++
        bigint& operator ++();
        bigint operator ++(int);

        //digit shifts
        bigint operator <<(unsigned int n) const;
        bigint operator >>(unsigned int n) const;
        bigint& operator <<=(unsigned int n);
        bigint& operator >>=(unsigned int n);

        //bigint shifts
        bigint operator <<(const bigint& n) const;
        bigint operator >>(const bigint& n) const;
        bigint& operator <<=(const bigint& n);
        bigint& operator >>=(const bigint& n);
};

std::ostream& operator <<(std::ostream& output, const bigint& obj);