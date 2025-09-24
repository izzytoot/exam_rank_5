#include "bigint.hpp"

//BASICS
bigint::bigint(): _digits("0") {}

bigint::bigint(unsigned long long n): _digits(std::to_string(n)) {}

bigint::bigint(std::string str): _digits(str) {}

bigint::bigint(const bigint& src){
    *this = src;
}

bigint& bigint::operator= (const bigint& src){
    if (this != &src)
        this->_digits = src._digits;
    return *this;
}

std::ostream& operator <<(std::ostream& output, const bigint& obj){
    output << obj.getDigits();
    return output;
}

bigint::~bigint() {};

//UTILS
void bigint::remove_zeros(){
    while(_digits.size() > 1 && _digits[0] == '0')
        _digits.erase(0, 1);
}

std::string bigint::getDigits() const{
    return this->_digits;
}

std::string bigint::toString(const bigint& obj) const{
    std::string res = obj.getDigits();

    return res;
}

// COMPARISON OPERATORS
bool bigint::operator <(const bigint& other) const{
    if(_digits.size() != other._digits.size())
        return _digits.size() < other._digits.size();
    return (_digits < other._digits);
}

bool bigint::operator >(const bigint& other) const{
    return (other < *this);
}

bool bigint::operator <=(const bigint& other) const{
    return ((*this < other) || (*this == other));
}

bool bigint::operator >=(const bigint& other) const{
    return ((*this > other) || (*this == other));
}

bool bigint::operator ==(const bigint& other) const{
    return this->_digits == other._digits;
}

bool bigint::operator !=(const bigint& other) const{
    return this->_digits != other._digits;
}

//ADDITION
bigint bigint::operator+ (const bigint& other)const{
   std::string result;
   int carry = 0;

   int i = _digits.size() - 1;
   int j = other._digits.size() - 1;

   while( i >= 0 || j >= 0 || carry != 0){
        int sum = carry;
        if (i >= 0)
            sum += _digits[i--] - '0';
        if (j >= 0)
            sum += other._digits[j--] - '0';
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
   }

   std::reverse(result.begin(), result.end());
   return bigint(result);
}

bigint& bigint::operator+= (const bigint& other){
    *this = *this + other;
    return *this;
}

//INCREMENT

bigint& bigint::operator++(){ //pre-increment
    *this = *this + bigint(1);
    return *this;
}

bigint bigint::operator ++(int){ //post-increment
    bigint tmp = *this;
    *this = *this + bigint(1);
    return tmp;
}

//DIGIT SHIFT

bigint bigint::operator <<(unsigned int n) const{
    if (*this == bigint(0))
        return *this;
    
    std::string res = _digits;
    res.append(n, '0');
    return bigint(res);
}

bigint bigint::operator >>(unsigned int n) const{
    if (_digits.size() <= n)
        return bigint(0);
    
    std::string res = _digits.substr(0, _digits.size() - n);
    return bigint(res);
}

bigint& bigint::operator <<=(unsigned int n){
    *this = *this << n;
    return *this;
}

bigint& bigint::operator >>=(unsigned int n){
    *this = *this >> n;
    return *this;
}

//BIGINT SHIFT

static int toInt(const bigint& b){
    std::string str = b.toString(b);
    if (str.size() > 9)
        return INT_MAX;
    return std::stoi(str);
}

bigint bigint::operator <<(const bigint& n) const{
    return *this << toInt(n);
}

bigint bigint::operator >>(const bigint& n) const{
    return *this >> toInt(n);
}

bigint& bigint::operator <<=(const bigint& n){
    return *this <<= toInt(n);
}

bigint& bigint::operator >>=(const bigint& n){
    return *this >>= toInt(n);
}

