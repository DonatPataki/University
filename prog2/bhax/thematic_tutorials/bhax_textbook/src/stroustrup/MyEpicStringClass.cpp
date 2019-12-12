#include "MyEpicStringClass.h"

MyEpicStringClass::MyEpicStringClass()
	{
		size = 0;
		text = nullptr;
	}

MyEpicStringClass::MyEpicStringClass(const char* string)
	{
		size = length(string);
		text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			text[i] = string[i];
		}
		text[size] = '\0';
	}

MyEpicStringClass::MyEpicStringClass(const MyEpicStringClass& old)
	{
		size = old.size;
		text = new char[size + 1];
		for (int i = 0; i < old.size; i++)
		{
			text[i] = old.text[i];
		}
		text[size] = '\0';
	}

MyEpicStringClass::~MyEpicStringClass()
	{
		delete[] text;
	}

	unsigned int MyEpicStringClass::length(const char* string)
	{
		if (nullptr == string)
		{
			return 0;
		}

		unsigned int counter = 0;

		while (*string)
		{
			counter++;
			string++;
		}

		return counter;
	}

	unsigned int MyEpicStringClass::length()
	{
		return size;
	}

	void MyEpicStringClass::insert(const char* string, const unsigned int position)
	{
		if (position > size)
		{
			throw "Out of index";
		}

		unsigned int insertlength = length(string);
		MyEpicStringClass temp = text;
		delete[] text;
		size += insertlength;
		text = new char[size + 1];
		int x = 0, y = 0, z = 0;
		for (int i = 0; i < position; i++)
		{
			text[i] = temp[y];
			y++;
		}
		for (int i = position; i < (position + insertlength); i++)
		{
			text[i] = string[z];
			z++;
		}
		for (int i = (position + insertlength); i < size; i++)
		{
			text[i] = temp[y];
			y++;
		}
		text[size] = '\0';
	}

	void MyEpicStringClass::append(const char* string)
	{
		this->insert(string, size);
	}

	char& MyEpicStringClass::operator[](unsigned int index)
	{
		return text[index];
	}

	MyEpicStringClass& MyEpicStringClass::operator=(const MyEpicStringClass& string)
	{
		delete[] text;
		size = string.size;
		text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			text[i] = string.text[i];
		}
		text[size] = '\0';

		return *this;
	}

	MyEpicStringClass& MyEpicStringClass::operator=(const char* string)
	{
		delete[] text;
		size = length(string);
		text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			text[i] = string[i];
		}
		text[size] = '\0';

		return *this;
	}

	MyEpicStringClass& MyEpicStringClass::operator+(const MyEpicStringClass& string)
	{
		this->append(string.text);
		return *this;
	}

	MyEpicStringClass& MyEpicStringClass::operator+(const char* string)
	{
		this->append(string);
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const MyEpicStringClass& string)
	{
		stream << string.text;
		return stream;
	}
