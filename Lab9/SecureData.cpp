// Workshop 9 - Multi-Threading
// SecureData.cpp
// Name:Qianyun He
// Seneca Student ID: 153515176
// Seneca email: qhe29@myseneca.ca
// Date of completion: 2018/11/21
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {
    
    void converter(char* t, char key, int n, const Cryptor& c) {
        for (int i = 0; i < n; i++)
            t[i] = c(t[i], key);
    }
    
    SecureData::SecureData(const char* file, char key, ostream* pOfs)
    {
        ofs = pOfs;
        
        // open text file
        fstream input(file, std::ios::in);
        if (!input)
            throw string("\n***Failed to open file ") +
            string(file) + string(" ***\n");
        
        // copy from file into memory
        input.seekg(0, std::ios::end);
        nbytes = (int)input.tellg() + 1;
        
        text = new char[nbytes];
        
        input.seekg(ios::beg);
        int i = 0;
        input >> noskipws;
        while (input.good())
            input >> text[i++];
        text[nbytes - 1] = '\0';
        *ofs << "\n" << nbytes - 1 << " bytes copied from file "
        << file << " into memory (null byte added)\n";
        encoded = false;
        
        // encode using key
        code(key);
        *ofs << "Data encrypted in memory\n";
    }
    
    SecureData::~SecureData() {
        delete[] text;
    }
    
    void SecureData::display(std::ostream& os) const {
        if (text && !encoded)
            os << text << std::endl;
        else if (encoded)
            throw std::string("\n***Data is encoded***\n");
        else
            throw std::string("\n***No data stored***\n");
    }
    
    void SecureData::code(char key)
    {   const int threads=3;
        int split = nbytes/threads;
        thread k[threads];
        Cryptor cryptors[threads];
        for (int i=0; i<threads;++i){
            k[i]=thread(bind(converter,text+i*split,key,i+1<threads?split:(nbytes-i*split),cryptors[i]));
        }
       Note:!!// bind(converter,&text[i*nbytes / threads],key, split,cryptors[i])
        //i+1<threads?split:(nbytes-1*split)
        for(int i=0;i<threads;++i)
            k[i].join();
        // TODO: rewrite this function to use at least two threads
        //         to encrypt/decrypt the text.
        //converter(text, key, nbytes, Cryptor());
        encoded = !encoded;
    }
    
    void SecureData::backup(const char* file) {
        if (!text)
            throw std::string("\n***No data stored***\n");
        else if (!encoded)
            throw std::string("\n***Data is not encoded***\n");
        else
        {
            // TODO: open a binary file for writing
            std::fstream binaryf(file,std::ios::out|std::ios::binary);
            if(!binaryf)
                throw string("\n***Failed to open file ") +
                string(file) + string(" ***\n");
            
            binaryf.write(text,nbytes);
            binaryf.close();
            // TODO: write data into the binary file
            //         and close the file
        }
    }
    
    void SecureData::restore(const char* file, char key) {
        // TODO: open binary file for reading
        std::fstream input(file,std::ios::in|std::ios::binary);
        if(!input)
            throw string("\n***Failed to open file ") +
            string(file) + string(" ***\n");
        
        // TODO: - allocate memory here for the file content
        nbytes=0;
        input>>noskipws;
        while(input.good()){
            char k;
            input >> k;
            nbytes++;
        }
        nbytes--;
        input.clear();
        input.seekg(0,std::ios::beg);
        text=new char[nbytes];
        // TODO: - read the content of the binary file
        int i=0;
        while(input.good())
            input>>text[i++];
        text[--i]='\0';
        input.close();
        
        *ofs << "\n" << nbytes << " bytes copied from binary file "
        << file << " into memory.\n";
        
        encoded = true;
        
        // decode using key
        code(key);
        
        *ofs << "Data decrypted in memory\n\n";
    }
    
    std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
        sd.display(os);
        return os;
    }
}
