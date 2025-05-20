#include <iostream>
#include "DataStorage.hpp"

template <class T> 
DataStorage<T>::DataStorage(std::string string,std::string type, int begin_index, int end_index,int number_elements)
{
    ptr_size = number_elements; 
    ptr = new T[number_elements]; 
    for (int i = begin_index; i<end_index;i++)
    {
        if (type == "int")
        {
            ptr[i] = std::stoi(string[i]); 
            //Now we need ot find the next index with a space
            i++; 
        }
        else if (type =="float")
        {
            ptr[i] = std::stof(string[i]); 
            //Now we need ot find the next index with a space
            i = i+4; 
        }

        else 
        {
            ptr[i] = string[i];
            //Now we need ot find the next index with a space
            i++; 
        }

        
        
        
    }

}

template <class T> 
void DataStorage<T>::display() const 
{
    std::cout<<"Printing out the array"<<std:endl; 
    for (int i = 0 ; i<ptr_size;i++)
    {
        std::cout<<ptr[i]<<" "; 
    }
    std::cout<<std::endl; 
}

 
