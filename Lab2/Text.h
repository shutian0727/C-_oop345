// Workshop 2 - Copy and Move Semantics
// w2.cpp
// Author:  Shutian Xu
// Date:    2018-08-31
// Updated by Cornel -- Changed the timing to nanoseconds and changed namespace
#ifndef W2_TEXT_H
#define W2_TEXT_H
#include <iostream>
#include <string>

using namespace std;
namespace w2 {
    class Text {
        
        size_t lineNo {0u};
        string* strings {nullptr};
        //string filename;
        
    public:
        Text();// default constructor
        Text(const string str);//constructor with Filename being saved
        Text(const Text& text);//copy constructor
        Text& operator=(const Text& text);// copy operator
        Text(Text&& text);// move constructor
        Text& operator=(Text&& text);//move operator
        ~Text();// Destructor
        size_t size() const;
    };
    
}
#endif

