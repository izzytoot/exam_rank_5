
#include "vect2.hpp"


vect2::vect2(){
    _vec.push_back(0);
    _vec.push_back(0);
//    std::cout << "def constr" << std::endl;
}

vect2::vect2(int x, int y){
    _vec.push_back(x);
    _vec.push_back(y);
//    std::cout << "constr with value" << std::endl;
}

vect2::vect2(const vect2& src): _vec(src._vec){
//    std::cout << "copy constr" << std::endl;
}

vect2& vect2::operator= (const vect2& src){
    if (this != &src)
        this->_vec = src._vec;
//    std::cout << "copy assign" << std::endl;
    return *this;
}

vect2::~vect2(){
//   std::cout << "destruct" << std::endl;
}

// OPERATORS: ACCESS AND PRINTING
int& vect2::operator[] (unsigned int index){
    if (index > this->_vec.size()){
        throw std::runtime_error("Error - index out of bounds");
    }
    else
        return this->_vec[index];
}

int vect2::operator[] (unsigned int index) const{
    if (index > this->_vec.size()){
        throw std::runtime_error("Error - index out of bounds");
    }
    else
        return this->_vec[index];
}

std::ostream& operator<< (std::ostream& output, const vect2& obj){
    output << "{" << obj[0] << ", " << obj[1] << "}" << std::endl;
    return output;
}

// OPERATORS: +, -, *, +=, -=, *=
vect2& vect2::operator+= (const vect2& other){
    this->_vec[0] += other._vec[0];
    this->_vec[1] += other._vec[1];
    return *this;
}

vect2 vect2::operator+ (const vect2& other) const{
    int x = this->_vec[0] + other._vec[0];
    int y = this->_vec[1] + other._vec[1];
    return vect2(x, y);
}

vect2& vect2::operator-= (const vect2& other){
    this->_vec[0] = other._vec[0];
    this->_vec[1] = other._vec[1];   
    return *this;
}

vect2 vect2::operator- (const vect2& other) const{
    int x = this->_vec[0] - other._vec[0];
    int y = this->_vec[1] - other._vec[1];
    return vect2(x, y);
}

vect2& vect2::operator*= (const vect2& other){
    this->_vec[0] = other._vec[0];
    this->_vec[1] = other._vec[1];
    return *this;
}

vect2 vect2::operator* (const vect2& other) const{
    int x = this->_vec[0] * other._vec[0];
    int y = this->_vec[1] * other._vec[1];
    return vect2(x, y);
}

// OPERATORS: ==, !=

bool vect2::operator== (const vect2& other){
    return ((this->_vec[0] == other._vec[0]) 
            && (this->_vec[1] == other._vec[1]));
}

bool vect2::operator!= (const vect2& other){
    return !(this == &other);
}