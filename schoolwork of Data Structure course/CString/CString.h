#ifndef CSTRING_H
#define CSTRING_H
#define MAX 1000
using namespace std;
class CString {
private:
	char m_data[MAX];
	int m_len;
public:
	// Constructor
	CString(const char* str , int len=0);
	// Destructor
	~CString();

	// Member Functions
	void StrReverse();
	void GetDifference(const CString& str1, const CString& str2, CString& result, int* time) const;
	void Replace(CString& S, CString T, CString V);
	void StrAssign(CString &T,const CString& chars);
	bool StrCompare(const CString& S,const CString& T);
	void SetValue(const char str[],int len);
	void Print() const;
	int GetLength() const;
	void DeleteSubstr(int pos, int len);
	void InsertSubstr(int pos, const CString& substr);
	CString Concat(const CString& str1, const CString& str2) const;
	CString Substr(int pos, int len) const;
};




#endif
