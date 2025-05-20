#include <iostream> 
#include "matrix.hpp"

Matrix::Matrix()
{
    //We have to enter the inputs of the matrix whenver we create them
    for(int row = 0 ; row<number_rows; row++)
    {
        for(int column = 0; column<number_columns; column++)
        {
            int input; 
            std::cin>>input; 
            actaul_Matrix[row][column] = input;
        }
    }
}
void Matrix::display() const
{
    for(int row = 0 ; row<number_rows; row++)
    {
        for(int column = 0; column<number_columns; column++)
        {
            std::cout<<actaul_Matrix[row][column]<<" "; 
        }
        std::cout<<std::endl;
    }
}
//Have to overlaod the operators 
int Matrix::operator[](int element_place) const
{
    if (element_place <= 3)
    {
        int column = 2 - (3 - element_place); 
        return actaul_Matrix[0][column]; 
    }
    else if (element_place <= 6)
    {
        int column  = 2 - (6- element_place); 
        return actaul_Matrix[1][column]; 
    }
    else if (element_place<=9)
    {
        int column  = 2 - (9 - element_place); 
        return actaul_Matrix[2][column]; 
    }
    else
    {
        std::cout<<"No such element in the matrix"<<std::endl; 
        return -9999;
    }
}

const Matrix& Matrix::operator=(const Matrix& otherMatrix)
{
    //check for self assignment
    if (this != &otherMatrix)
    {
        for (int row = 0 ; row < 3; row++)
        {
            for (int column = 0; column < 3; column++)
            {
                actaul_Matrix[row][column] = otherMatrix.actaul_Matrix[row][column]; 
            }
        }
    }
    return *this;
}
const Matrix& Matrix::operator+(const Matrix& otherMatrix)
{
    //check for self assignment
    if (this != &otherMatrix)
    {
        for (int row = 0 ; row < 3; row++)
        {
            for (int column = 0; column < 3; column++)
            {
                actaul_Matrix[row][column] += otherMatrix.actaul_Matrix[row][column]; 
            }
        }
    }
    return *this;
}
const Matrix& Matrix::operator-(const Matrix& otherMatrix)
{
    //check for self assignment
    if (this != &otherMatrix)
    {
        for (int row = 0 ; row < 3; row++)
        {
            for (int column = 0; column < 3; column++)
            {
                actaul_Matrix[row][column] -= otherMatrix.actaul_Matrix[row][column]; 
            }
        }
    }
    return *this;
}
bool Matrix::operator==(const Matrix& otherMatrix) const
{
    //check for self assignment
    if (this != &otherMatrix)
    {
        for (int row = 0 ; row < 3; row++)
        {
            for (int column = 0; column < 3; column++)
            {
                if (actaul_Matrix[row][column] != otherMatrix.actaul_Matrix[row][column])
                {
                    return false; 
                }
                 
            }
        }
    }
    return true; 
} 
bool Matrix::operator!=(const Matrix& otherMatrix) const
{
    //check for self assignment
    if (this != &otherMatrix)
    {
        for (int row = 0 ; row < 3; row++)
        {
            for (int column = 0; column < 3; column++)
            {
                if (actaul_Matrix[row][column] != otherMatrix.actaul_Matrix[row][column])
                {
                    return true; 
                }
                 
            }
        }
    }
    return false; 
}  
Matrix::~Matrix(){}