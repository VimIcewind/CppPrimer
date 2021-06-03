#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <cassert>
#include <iomanip>

using namespace std;

class String;

istream& operator>>(istream &, String&);
ostream& operator>>(ostream &, const String&);

class String {
public:
	// 一组重载的构造函数
	// 提供自动初始化功能
	// String str1;			// String();
	// String str2("literal");	// String(const char*);
	// String str3(str2);		// String(const String&);
	String();
	String(const char*);
	String(const String&);

	// 析构函数：自动析构
	~String();

	// 一组重载的赋值操作符
	// str1 = str2
	// str3 = "a string literal"
	String& operator=(const String&);
	String& operator=(const char*);

	// 一组重载的等于操作符
	// str1 == str2;
	// str3 == "a string literal";
	bool operator==(const String&);
	bool operator==(const char*);

	// 重载的下标操作符
	// str1[0] = str2[0];
	char& operator[](int);

	// 成员访问函数
	int size()
	{
		return _size;
	}

	char *c_str()
	{
		return _string;
	}

	int count(char ch) const;

	String operator+(const String &rhs) const;

private:
	int _size;
	char *_string;

	void init(const char*);
	void init(const String &);
};

inline void String::init(const char *str)
{
	if (!str) {
		_size = 0;
		_string = 0;
	} else {
		_size = strlen(str);
		_string = new char[_size + 1];
		strcpy(_string, str);
	}
}

inline void String::init(const String &rhs)
{
	_size = rhs._size;
	if (!rhs._string)
		_string = 0;
	else {
		_string = new char[_size + 1];
		strcpy(_string, rhs._string);
	}
}

// 缺省构造函数
inline String::String()
{
	init(0);
}

inline String::String(const char *str)
{
	init(str);
}

// 拷贝构造函数
inline String::String(const String &rhs)
{
	init(rhs);
}

// 析构函数
inline String::~String()
{
	delete [] _string;
}

inline String& String::operator=(const char *s)
{
	delete [] _string;
	init(s);
	return *this;
}

inline String& String::operator=(const String &rhs)
{
	if (this != &rhs) {
		delete [] _string;
		init(rhs);
	}
	return *this;
}

inline char& String::operator[](int elem)
{
	assert(elem >= 0 && elem < _size);
	return _string[elem];
}

inline istream& operator>>(istream &io, String &s)
{
	// 人工限制最多 4096 个字符
	const int limit_string_size = 4096;
	char inBuf[limit_string_size];

	// setw() 是 iostream 库的一部分
	// 限制被读取的字符个数为 limit_string_size - 1
	io >> setw(limit_string_size) >> inBuf;
	s = inBuf; // Sring::operator=(const char*);

	return io;
}

inline ostream& operator<<(ostream& os, String &s)
{
	return os << s.c_str();
}

inline bool String::operator==(const String &rhs)
{
	if (_size != rhs._size)
		return false;
	return strcmp(_string, rhs._string) ? false : true;
}

inline bool String::operator==(const char *s)
{
	return strcmp(_string, s) ? false : true;
}

inline int String::count(char ch) const
{
	int chCnt = 0;

	for (int ix = 0; ix < _size; ++ix)
		if (_string[ix] == ch)
			++chCnt;

	return chCnt;
}

inline String String::operator+(const String &rhs) const
{
	String newString;

	if (!rhs._string)
		newString = *this;
	else if (!_string)
		newString = rhs;
	else {
		newString._size = _size + rhs._size;
		newString._string = new char[newString._size + 1];
		strcpy(newString._string, _string);
		strcat(newString._string, rhs._string);
	}

	return newString;
}

#endif /* end of include guard: STRING_H */
