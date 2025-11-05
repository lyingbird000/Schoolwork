#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CStudent.h"

using namespace std;
int main()
{
    CStudent stu[3]; //以三个学生为例
    char n1[10] = "Charlie";
    char n2[10] = "Julia";
    char n3[10] = "Maria";
    int s1[5] = {80,80,80,80,80};
    int s2[5] = { 100,80,80,80,80 };
    int s3[5] = { 80,80,80,80,80 };
    stu[0].SetStudent(n1,7,s1);
    stu[1].SetStudent(n2, 5, s2);
    stu[2].SetStudent(n3, 5, s3);
    for (int i = 0; i <= 2; i++) {
        stu[i].ShowStudent();
    }
    stu[0].CompareScore(stu[1]);
    CStudent* p = &stu[2];
    stu[0].CompareScore(p);
    Compare(stu[1], stu[2]);
}
