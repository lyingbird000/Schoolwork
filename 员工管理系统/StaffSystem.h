#define _CRT_SECURE_NO_WARNINGS
#ifndef STAFFSYSTEM_H
#define STAFFSYSTEM_H
#include "Staff.h"
#include <string>
using namespace std;
class StaffSystem {
private:
	Staff* staffList;
	int staffCount;
	int capacity;
public:
	StaffSystem(int cap = 100);
	~StaffSystem();
	int getStaffCount() const;
	bool addStaff(const Staff& staff);
	bool removeStaff(const char* id);
	Staff* findStaff(const char* id) const;
	void printStaff(const char* id) const;	//查找并展示指定id的员工信息
	bool GetStaffFromFile(const string& filename); //从文件读取员工信息,返回是否成功
	bool SaveStaffToFile(const string& filename) const; //保存员工信息到文件,返回是否成功
};



#endif