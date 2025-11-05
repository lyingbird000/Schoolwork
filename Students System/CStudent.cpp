#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CStudent.h"
#include <string>
#include <cstring>
using namespace std;
int CStudent::mCount = 0;  //在实现文件中初始化静态成员
CStudent::CStudent(){
	string No = "1728";
	string s = to_string(CStudent::mCount);
	if (s.length() < 4) {       //自动补足零
		for (int i = 1; i <= 4 - s.length(); i++) {
			No += "0";
		}
	}
	No += s;
	strcpy(mNo, No.c_str());
	CStudent::mCount++;
}

CStudent::CStudent(const CStudent& other) {
	delete[] mpName;
	strcpy(mNo,other.mNo);
	mpName = new char[other.mNamelength+1];  //注：加一位给\0
	for (int i = 0; i <= other.mNamelength - 1; i++) {
		mpName[i] = other.mpName[i];
	}
	mpName[other.mNamelength] = '\0';
	mNamelength = other.mNamelength;
	for (int i = 0; i <= 4; i++) {
		mScore[i] = other.mScore[i];
	}
}

CStudent::~CStudent() {
	delete[] mpName;
	mpName = nullptr;
}

void CStudent::SetStudent(char* zpName, const int& zNamelength, int zScore[5]) {
	mpName = zpName;
	mNamelength = zNamelength;
	for (int i = 0; i <= 4; i++) {
		mScore[i] = zScore[i];
	}
	mpName = new char[zNamelength + 1];  //注：加一位给\0
	for (int i = 0; i <= zNamelength - 1; i++) {
		mpName[i] = zpName[i];
	}
	mpName[zNamelength] = '\0';
}

void CStudent::ShowStudent() const {
	cout << "=====学生信息=====" << endl;
	cout << "学号： " << mNo << endl;
	cout << "姓名： " ;
	for (int i = 0; i <= mNamelength - 1; i++) {
		cout << mpName[i];
	}
	cout << endl;
	cout << "分数： " << endl; 
	for (int i = 0; i < 5; i++) {
		cout << mScore[i] << " ";
	}
	cout << endl;
}

double CStudent::AveScore() const{
	double mAveScore = 0;
	for (int i = 0; i < 5; i++) {
		mAveScore += mScore[i] / 5.0;
	}
	return mAveScore;
}

const char* CStudent::ShowNo() const{
	return mNo;
}

void CStudent::CompareScore(const CStudent& zS) const {
	if (AveScore() > zS.AveScore()) {
		cout << "学生" << mNo << "的成绩更高" << endl;
	}
	else if(AveScore() < zS.AveScore()){
		cout << "学生" << zS.ShowNo() << "的成绩更高" << endl;
	}
	else {
		cout << "一样高" << endl;
	}
}

void CStudent::CompareScore(const CStudent* zp) const {
	if (AveScore() > zp->AveScore()) {
		cout << "学生" << mNo << "的成绩更高" << endl;
	}
	else if (AveScore() < zp->AveScore()) {
		cout << "学生" << zp->ShowNo() << "的成绩更高" << endl;
	}
	else {
		cout << "一样高" << endl;
	}
}

void Compare(const CStudent& zS1, const CStudent& zS2) {
	if (zS1.AveScore() > zS2.AveScore()) {
		cout << "学生" << zS1.ShowNo() << "的成绩更高" << endl;
	}
	else if (zS1.AveScore() < zS2.AveScore()) {
		cout << "学生" << zS2.ShowNo() << "的成绩更高" << endl;
	}
	else {
		cout << "一样高" << endl;
	}
}

void CStudent::ResetNo(char NewNo[9]) {
	for (int i = 0; i <= 8; i++) {
		mNo[i] = NewNo[i];
	}
}