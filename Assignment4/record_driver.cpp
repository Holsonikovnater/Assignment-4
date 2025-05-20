#include <iostream> 
#include <string>
#include <fstream>

#include "DataStorage.hpp"

int main()
{
     
    //We first need to open an input file
    std::ifstream recordfile;
    recordfile.open("record_file.txt", std::ios::in); 
    
    //Code in case we fail to open the file
    if (!recordfile)//Returns the open status
    {
        std::cout<<"Cant open the file;"; 
        exit(EXIT_FAILURE); 

    }
    
    // For the record array
    int amount_of_record = 0; 
    int index_of_record = 0 ; 


    //Getting the amount of records in the file
    while(!recordfile.eof())
    {
        std::string blob; 
        std::getline(recordfile,blob); 
        amount_of_record++;
    }

    //Now we make a pointer that will contain all the records
    DataStorage<T>* dsPtr = new DataStorage<T>[amount_of_record]; 

    //Repositioning the file pointer
    recordfile.seekg(0,std::ios::beg); 

    //Reading from the file line by line
    //Making sure we are not at the end of the file 
    while (!recordfile.eof())// Returns true when we are at the end of the file
    {
        std::string line; 
        std::getline(recordfile,line); //Reads the entire record line

        //Place holder strings for the info in the record
        std::string type; 
        std::string type_number; 
        

        //Lets parse through the string;
        int start  = 0;  
        int end = line.find(" ",start);
        int displacement = end - start; 
         
        //Reading the type
        type = line.substr(start,displacement);
        start = end+1; 

        //Reading the number of elements
        end = line.find(" ",start); 
        displacement = end - start; 
        type_number = line.substr(start,displacement); 
        start = end+1; 

        //Lets gets the last index of the string 
        int last_index = line.find("\n",start); 

        //Lets split between the constructors; 
        if (type=="int")
        {
            dsPtr[index_of_record] = DataStorage<int> object(line,"int",start,last_index,type_number);
            //Lets make the constructor take into acoount just the string and the last idex of the string
            //Also the number of elements
            //And the first index 
            
        }
        else if(type == "float")
        {
            dsPtr[index_of_record] =
            //Lets make the constructor take into acoount just the string and the last idex of the string
            //Also the number of elements
            //And the first index
            
        }
        else if (type == "char")
        {
            dsPtr[index_of_record] =
            //Lets make the constructor take into acoount just the string and the last idex of the string
            //Also the number of elements
            //And the first index
             
        }
        else
        {
            dsPtr[index_of_record] =
            std::cout<<"Invalid type"<<std::endl; 
        }
        index_of_record++; 
         
    } 

    std::cout<<"Made it out of the reading phase"<<std::endl; 

    
    //Closing the file 
    recordfile.close(); 

    return 0; 

}