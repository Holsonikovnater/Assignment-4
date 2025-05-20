#pragma once 
#include <iostream> 

class Matrix 
{
    private: 
    //Making the dimensions statinc const, because thats the only way to do it
    const static int number_rows = 3; 
    const static int number_columns = 3; 
    //Making a two dimentional array
    int actaul_Matrix[number_rows][number_columns]; 

    public: 
    //Making the default constructor
    //The constructor will ask you for the input
    Matrix(); 
    //Have to overlaod the operators 
    int operator[](int element_place) const;
    const Matrix& operator=(const Matrix& otherMatrix); 
    const Matrix& operator+(const Matrix& otherMatrix); 
    const Matrix& operator-(const Matrix& otherMatrix);
    bool operator==(const Matrix& otherMatrix) const ; 
    bool operator!=(const Matrix& otherMatrix) const ;  
    void display()const; 
    ~Matrix(); 

}; 