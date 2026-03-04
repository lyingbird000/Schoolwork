#ifndef COMPARE_H
#define COMPARE_H
#include <string>
#include "CComplex.h"
using namespace std;
template <class T>
class Compare {
public:
	static bool IsBigger(const T& a, const T& b) {
		return (a > b);
	}
	static bool IsSmaller(const T& a, const T& b) {
		return (a < b);
	}
	static bool IsEqual(const T& a, const T& b) {
		return (a == b);
	}
};

template <>
class Compare<string> {
public:
	static bool IsBigger(const string& a, const string& b) {
		int maxlength = (a.length() > b.length()) ? a.length() : b.length();
		for (int i = 0; i < maxlength; i++) {
			char charA = (i < a.length()) ? a[i] : '\0';
			char charB = (i < b.length()) ? b[i] : '\0';
			if (charA > charB) {
				return true;
			}
			else if (charA < charB) {
				return false;
			}
		}
	};
	static bool IsSmaller(const string& a, const string& b) {
		int maxlength = (a.length() > b.length()) ? a.length() : b.length();
		for (int i = 0; i < maxlength; i++) {
			char charA = (i < a.length()) ? a[i] : '\0';
			char charB = (i < b.length()) ? b[i] : '\0';
			if (charA < charB) {
				return true;
			}
			else if (charA > charB) {
				return false;
			}
		}
	}
	static bool IsEqual(const string& a, const string& b) {
		return (a == b);
	}
};

template <>
class Compare<CComplex> {
public:
	static bool IsBigger(const CComplex& a, const CComplex& b) {
		return (a.abs() > b.abs());
	}
	static bool IsSmaller(const CComplex& a, const CComplex& b) {
		return (a.abs() < b.abs());
	}
	static bool IsEqual(const CComplex& a, const CComplex& b) {
		return (a.abs() == b.abs());
	}
};

#endif

