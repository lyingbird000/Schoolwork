#include<iostream>
#include"CComplex.h"
#include<cmath>
using namespace std;
//以下为复数类成员函数的实现：
CComplex::CComplex(double zR , double zI ) :mR(zR), mI(zI) {
    if (mI == 0) {
        cout <<"<=" << mR;  // 只有实部
    }
    else if (mR == 0) {     //只有虚部
        if (mI == 1)
            cout << "<=" << "i";
        else if (mI == -1)
            cout << "<=" << "-i";
        else
            cout << "<=" << mI << "i";
    }
    else {
        cout << "<=" << mR;
        if (mI > 0) {
            if (mI == 1)
                cout << "+i";
            else
                cout << "+" << mI << "i";
        }
        else {
            if (mI == -1)
                cout << "-i";
            else
                cout << mI << "i";
        }
    }
    cout << endl;
}
CComplex::~CComplex() {
    if (mI == 0) {
        cout  << mR ;  // 只有实部
    }
    else if (mR == 0) {     //只有虚部
        if (mI == 1)
            cout << "i";
        else if (mI == -1)
            cout  << "-i";
        else
            cout  << mI << "i";
    }
    else {
        cout  << mR;
        if (mI > 0) {
            if (mI == 1)
                cout << "+i";
            else
                cout << "+" << mI << "i";
        }
        else {
            if (mI == -1)
                cout << "-i";
            else
                cout << mI << "i";
        }
    }
    cout << "=>"<<endl;
}

void CComplex::SetValue() {
	mR = 0;
	mI = 0;
}
void CComplex::SetValue(double zR , double zI ) {
	mR = zR;
	mI = zI;
}
void CComplex::ShowValue() {
    if (mI == 0) {
        cout << "<=" << mR;  // 只有实部
    }
    else if (mR == 0) {      //只有虚部
        if (mI == 1)
            cout << "<=" << "i";
        else if (mI == -1)
            cout << "<=" << "-i";
        else
            cout << "<=" << mI << "i";
    }
    else {
        cout << "<=" << mR;
        if (mI > 0) {
            if (mI == 1)
                cout << "+i";
            else
                cout << "+" << mI << "i";
        }
        else {
            if (mI == -1)
                cout << "-i";
            else
                cout << mI << "i";
        }
    }
    cout << endl;
}

CComplex CComplex::Add(const CComplex& zC) const {
    return CComplex(mR + zC.mR, mI + zC.mI);
}

CComplex CComplex::Substract(const CComplex& zC) const {
    return CComplex(mR - zC.mR, mI - zC.mI);
}

CComplex CComplex::Multiply(const CComplex& zC) const {
    double realPart = mR * zC.mR - mI * zC.mI;
    double imagPart = mR * zC.mI + mI * zC.mR;
    return CComplex(realPart, imagPart);
}

CComplex CComplex::Divide(const CComplex& zC) const {
    // 复数除法：(a+bi) / (c+di) = [(ac+bd) + (bc-ad)i] / (c²+d²)
    double denominator = zC.mR * zC.mR + zC.mI * zC.mI;

    if (denominator == 0) {
        throw runtime_error("Division by zero: denominator cannot be zero");
    }

    double realPart = (mR * zC.mR + mI * zC.mI) / denominator;
    double imagPart = (mI * zC.mR - mR * zC.mI) / denominator;

    return CComplex(realPart, imagPart);
}

double CComplex::abs() const {
	return sqrt(mR * mR + mI * mI);
}