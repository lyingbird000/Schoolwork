#include"Staff.h"
#include "StaffSystem.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
	cout << "下面先不引入外部文件，直接在代码中添加员工信息进行测试:"<<endl;
	Staff staff1;
	staff1.setId("1");
	staff1.setName("Alice");
	staff1.setScore(90);
	staff1.setProject("ProjectX");
	staff1.setType(0); // Regular staff
	Staff staff2;
	staff2.setId("2");
	staff2.setName("Bob");
	staff2.setScore(95);
	staff2.setProject("ProjectX");
	staff2.setType(1); // Manager
	StaffSystem system;
	system.addStaff(staff1);
	system.addStaff(staff2);
	system.printStaff("2"); // Print info for Bob and his team members
	
	cout << "下面开始测试文件读写功能:"<<endl;
	StaffSystem newSystem;
	if (newSystem.GetStaffFromFile("test_staff_data.txt")) cout << "读入成功" << endl;
	else cout << "读入失败" << endl;
	newSystem.printStaff("2"); // Print info for Bob and his team members from the new system
	if (newSystem.removeStaff("1")) cout << "删除成功" << endl;
	else cout << "删除失败" << endl; // Remove Alice
	if (newSystem.SaveStaffToFile("test_staff_data.txt")) cout << "保存成功" << endl;
	else cout << "保存失败" << endl;
	
	cout << "按照作业要求的完整文件读写调试：" << endl;
	StaffSystem mySystem;
	if(mySystem.GetStaffFromFile("staff_data.txt"))cout << "读入成功" << endl;
	else cout << "读入失败" << endl;
	mySystem.printStaff("0601");
	cout << endl;
	mySystem.printStaff("0002");
	if (mySystem.removeStaff("1002")) cout << "删除成功" << endl;
	else cout << "删除失败" << endl;
	if (mySystem.removeStaff("0005")) cout << "删除成功" << endl;
	else cout << "删除失败" << endl;
	if(mySystem.SaveStaffToFile("staff_data.txt"))cout << "保存成功" << endl;
	else cout << "保存失败" << endl;
	
	return 0;
}