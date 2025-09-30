#include "bigint.hpp"

bigint::bigint() : _digits("0") {}

bigint::bigint(long long n) : _digits(std::to_string(n)) {}

bigint::bigint(std::string str) : _digits(str) {}

bigint::bigint(const bigint& src) : _digits(src._digits) {}

bigint& bigint::operator= (const bigint& src){
    if (this != &src)
        this->_digits = src._digits;
    return *this;
}

bigint::~bigint(){}

std::string bigint::getDigits() const{
    return this->_digits;
}

bigint bigint::operator+ (const bigint& other) const{
    std::string res;
    int carry = 0;
    int i = this->_digits.size() - 1;
    int j = other.getDigits().size() - 1;

    while (i >= 0 || j >= 0 || carry != 0){
        int sum = carry;
        if (i >= 0)
            sum += this->_digits[i--] - '0';
        if (j >= 0)
            sum += other.getDigits()[j--] - '0';
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    std::reverse(res.begin(), res.end());
    return bigint(res);
}

bigint& bigint::operator+= (const bigint& other){
    *this = *this + other;
    return *this;
}

bigint& bigint::operator++ (){
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++ (int){
    bigint tmp = *this;
    *this += bigint(1);
    return tmp;
}

bigint bigint::operator<< (int n) const{
    if (*this == bigint(0))
        return *this;
    
    std::string res = this->_digits;
    res.append(n, '0');
    return bigint(res);
}

bigint bigint::operator>> (int n) const{
    if (this->_digits.size() <= n)
        return bigint(0);
    return bigint(this->_digits.substr(0, (this->_digits.size() - n)));
}

bigint& bigint::operator<<= (int n){
    *this = *this << n;
    return *this;
}

bigint& bigint::operator>>= (int n){
    *this = *this >> n;
    return *this;
}

bigint& bigint::operator>>= (const bigint& other){
    *this = *this >> toInt(other);
    return *this;
}

bool bigint::operator== (const bigint other) const{
    if (this->_digits == other.getDigits())
        return true;
    return false;
}

bool bigint::operator!= (const bigint other) const{
    if (this->_digits != other.getDigits())
        return true;
    return false;
}

bool bigint::operator< (const bigint other) const{
    if (this->_digits.size() != other.getDigits().size())
        return this->_digits.size() < other.getDigits().size();
    return this->_digits < other.getDigits();
}

bool bigint::operator<= (const bigint other) const{
    if (this->_digits.size() != other.getDigits().size())
        return this->_digits.size() <= other.getDigits().size();
    return this->_digits <= other.getDigits();
}

bool bigint::operator> (const bigint other) const{
    if (this->_digits.size() != other.getDigits().size())
        return this->_digits.size() > other.getDigits().size();
    return this->_digits > other.getDigits();
}

bool bigint::operator>= (const bigint other) const{
    if (this->_digits.size() != other.getDigits().size())
        return this->_digits.size() > other.getDigits().size();
    return this->_digits >= other.getDigits();
}

std::ostream& operator<< (std::ostream& output, const bigint& obj){
    output << obj.getDigits();
    return output;
}

int toInt(const bigint& obj){
    if (obj.getDigits().size() > 9)
        return INT_MAX;

    int n = std::stoi(obj.getDigits());
    return n;
}