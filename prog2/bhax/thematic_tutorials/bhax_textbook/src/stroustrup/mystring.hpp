class MyEpicStringClass //ékezetes karakterek visszaadása/szóhossz hibás
{
private:
	char* text;
	unsigned int size;
public:
	MyEpicStringClass()
	{
		size = 0;
		text = NULL;
	}

	MyEpicStringClass(const char* string)
	{
		size = length(string);
		text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			text[i] = string[i];
		}
		text[size] = '\0';
	}

	MyEpicStringClass(const MyEpicStringClass& old)
	{
		size = old.size;
		text = new char[size + 1];
		for (int i = 0; i < old.size; i++)
		{
			text[i] = old.text[i];
		}
		text[size] = '\0';
	}

	~MyEpicStringClass()
	{
		delete[] text;
	}

	unsigned int length(const char* string)
	{
		if (NULL == string)
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

	unsigned int length()
	{
		return size;
	}

	void insert(const char* string, const unsigned int position)
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
		for ( int i = (position + insertlength); i < size; i++)
		{
			text[i] = temp[y];
			y++;	
		}
		text[size] = '\0';
	}

	void append(const char* string)
	{
		this->insert(string, size);
	}

	char& operator[](unsigned int index)
	{
		return text[index];
	}

	MyEpicStringClass& operator=(const MyEpicStringClass& string)
	{
		delete[] text;
		size = string.size;
		text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			text[i] = string.text[i];
		}
		text[size] = '\0';
	}

		MyEpicStringClass& operator=(const char* string)
	{
		delete[] text;
		size = length(string);
		text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			text[i] = string[i];
		}
		text[size] = '\0';
	}

	MyEpicStringClass& operator+(const MyEpicStringClass& string)
	{
		this->append(string.text);
		return *this;
	}

	MyEpicStringClass& operator+(const char* string)
	{
		this->append(string);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& stream, const MyEpicStringClass& string)
	{
		stream << string.text;
		return stream;
	}
};