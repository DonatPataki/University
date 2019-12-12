#pragma once

#include <iostream>

class MyEpicStringClass
{
private:
	char* text;
	unsigned int size;
public:
	MyEpicStringClass();
	MyEpicStringClass(const char* string);
	MyEpicStringClass(const MyEpicStringClass& old);
	~MyEpicStringClass();
	unsigned int length(const char* string);
	unsigned int length();
	void insert(const char* string, const unsigned int position);
	void append(const char* string);
	char& operator[](unsigned int index);
	MyEpicStringClass& operator=(const MyEpicStringClass& string);
	MyEpicStringClass& operator=(const char* string);
	MyEpicStringClass& operator+(const MyEpicStringClass& string);
	MyEpicStringClass& operator+(const char* string);
	friend std::ostream& operator<<(std::ostream& stream, const MyEpicStringClass& string);
};
