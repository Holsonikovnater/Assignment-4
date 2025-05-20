#pragma once
#include <iostream> 

template <class T> 
class DataStorage
{
    private:
    T* ptr; 
    int ptr_size; 

    public: 
    DataStorage(std::string string,std::string type, int begin_index, int end_index,int number_elements); 
    void display() const; 
    ~DataStorage(); 

}; 