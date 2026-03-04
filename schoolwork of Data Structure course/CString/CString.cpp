#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CString.h"
using namespace std;
CString::CString(const char* str, int len)
{
	m_len = len;
	for (int i = 0; i < len; i++)
	{
		m_data[i] = str[i];
	}
}

CString::~CString()
{
}	

void CString::StrReverse()
{
	for (int i = 0; i < m_len / 2; i++)
	{
		char temp = m_data[i];
		m_data[i] = m_data[m_len - i - 1];
		m_data[m_len - i - 1] = temp;
	}
}

void CString::GetDifference(const CString& s, const CString& t, CString& r, int* time) const
{
	//求得所有在串s中，而不在串t中的字符,放入r中,并将第一次在s中出现的位置放入time中
	int i = 0, j = 0, k = 0;
	for (i = 0; i < s.m_len;i++) {
		bool found = false;
		for (j = 0; j < t.m_len; j++) {
			if (s.m_data[i] == t.m_data[j]) {
				found = true;
				break;
			}
		}
		if (!found) {
			r.m_data[k++] = s.m_data[i];
			time[k - 1] = i;
		}
	}
	r.m_len = k;
}

void CString::Replace(CString& S, CString T, CString V)
{
	//将串S中所有与串T相等的子串替换为串V
	int i = 0;
	while (i <= S.m_len - T.m_len) {
		bool match = true;
		for (int j = 0; j < T.m_len; j++) {
			if (S.m_data[i + j] != T.m_data[j]) {
				match = false;
				break;
			}
		}
		if (match) {
			// 替换子串
			// 先删除子串T
			S.DeleteSubstr(i, T.m_len);
			// 再插入子串V
			S.InsertSubstr(i, V);
			i += V.m_len; // 跳过替换后的子串
		}
		else {
			i++;
		}
	}
}

void CString::StrAssign(CString& T, const CString& chars)
{
	//将串chars赋值给串T
	T.m_len = chars.m_len;
	for (int i = 0; i < chars.m_len; i++) {
		T.m_data[i] = chars.m_data[i];
	}
}

bool CString::StrCompare(const CString& S, const CString& T)
{
	//比较串S和串T的字符大小，若S>=T则返回true，否则返回false
	int minLen = (S.m_len < T.m_len) ? S.m_len : T.m_len;
	for (int i = 0; i < minLen; i++) {
		if (S.m_data[i] > T.m_data[i]) {
			return true;
		}
		else if (S.m_data[i] < T.m_data[i]) {
			return false;
		}
	}
	if (S.m_len >= T.m_len) {
		return true;
	}
	else {
		return false;
	}
}

void CString::SetValue(const char str[], int len)
{
	m_len = len;
	for (int i = 0; i < len; i++)
	{
		m_data[i] = str[i];
	}
}

void CString::Print() const
{
	for (int i = 0; i < m_len; i++)
	{
		cout << m_data[i];
	}
	cout << endl;
}

int CString::GetLength() const 
{ 
	return m_len;
}

void CString::DeleteSubstr(int pos, int len)
{
	//删除从位置pos开始的len个字符
	if (pos < 0 || pos >= m_len || len <= 0 || pos + len > m_len) {
		return; // 无效参数，直接返回
	}
	for (int i = pos + len; i < m_len; i++) {
		m_data[i - len] = m_data[i];
	}
	m_len -= len;
}

void CString::InsertSubstr(int pos, const CString& substr)
{
	//在位置pos插入子串substr
	if (pos < 0 || pos > m_len) {
		return; // 无效参数，直接返回
	}
	// 移动后面的字符
	for (int i = m_len - 1; i >= pos; i--) {
		m_data[i + substr.m_len] = m_data[i];
	}
	// 插入子串
	for (int i = 0; i < substr.m_len; i++) {
		m_data[pos + i] = substr.m_data[i];
	}
	m_len += substr.m_len;
}

CString CString::Concat(const CString& str1, const CString& str2) const
{
	// 连接两个字符串并返回结果
	CString result("", 0);
	result.m_len = str1.m_len + str2.m_len;
	for (int i = 0; i < str1.m_len; i++) {
		result.m_data[i] = str1.m_data[i];
	}
	for (int i = 0; i < str2.m_len; i++) {
		result.m_data[str1.m_len + i] = str2.m_data[i];
	}
	return result;
}

CString CString::Substr(int pos, int len) const
{
	// 提取子串并返回结果
	if (pos < 0 || pos >= m_len || len <= 0 || pos + len > m_len) {
		return CString("", 0); // 无效参数，返回空串
	}
	CString result("", 0);
	result.m_len = len;
	for (int i = 0; i < len; i++) {
		result.m_data[i] = m_data[pos + i];
	}
	return result;
}