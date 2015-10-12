/***********************************************************************************
*Filename: FileFilter.hpp
*Name: John R Toth
*Date: 4/29/15
*Description: FileFilter header file
***********************************************************************************/

#ifndef FILEFILTER_HPP
#define FILEFILTER_HPP


#include <fstream>
#include <iostream> 

using namespace std;


class FileFilter {

public:
	virtual void doFilter(ifstream &inValue, ofstream &outValue, string &inputFile, string &outputFile) = 0;

};

class Copy: public FileFilter {

public:
	void doFilter(ifstream &inValue, ofstream &outValue, string &inputFile, string &outputFile); 


};


class Encrypt: public FileFilter {

public:
	void doFilter(ifstream &inValue, ofstream &outValue, string &inputFile, string &outputFile); 
	char transform(char ch, int keyVal);

protected: 
	char ch;
};


class Transform: public FileFilter {

public:
	void doFilter(ifstream &inValue, ofstream &outValue, string &inputFile, string &outputFile); 
	char transform(char ch);

protected: 
	char ch;
};


class Special: public FileFilter {

public:
	void doFilter(ifstream &inValue, ofstream &outValue, string &inputFile, string &outputFile); 
	char transform(char ch, int keyVal);
	char jump(char ch);

protected: 
	char ch;
	int keyVal;
};

#endif
