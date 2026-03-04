#define _CRT_SECURE_NO_WARNINGS
#include "StaffSystem.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
StaffSystem::StaffSystem(int cap) {
	staffCount = 0;
	capacity = cap;
	staffList = new Staff[capacity];
}

StaffSystem::~StaffSystem() {
	delete[] staffList;
}

bool StaffSystem::addStaff(const Staff& staff) {
	if (staffCount >= capacity) {
		return false; // No space to add new staff
	}
	staffList[staffCount++] = staff;
	return true;
}

bool StaffSystem::removeStaff(const char* id) {
	for (int i = 0; i < staffCount; ++i) {
		if (strcmp(staffList[i].getId(), id) == 0) {
			// Shift remaining staff to fill the gap
			for (int j = i; j < staffCount - 1; ++j) {
				//staffList[j].setId(staffList[j+1].getId());
				//staffList[j].setName(staffList[j+1].getName());
				//staffList[j].setScore(staffList[j+1].getScore());
				//staffList[j].setProject(staffList[j + 1].getProject());
				//staffList[j].setType(staffList[j + 1].getType());
				staffList[j] = staffList[j + 1];
			}
			--staffCount;
			return true; // Staff removed successfully
		}
	}
	return false; // Staff not found
}

Staff* StaffSystem::findStaff(const char* id) const {
	for (int i = 0; i < staffCount; ++i) {
		if (strcmp(staffList[i].getId(), id) == 0) {
			return &staffList[i];
		}
	}
	return nullptr; // Staff not found
}

void StaffSystem::printStaff(const char* id) const {
	Staff* s = findStaff(id);
	if (s == nullptr) {
		cout << "Staff not found." << endl;
		return;
	}
	if (!s->getType()) {
		cout << s->getId() << ' ' << s->getName() << ' ' << s->getScore() << ' ' << s->getProject() << endl;
	}
	else {
		cout << s->getId() << ' ' << s->getName() << ' ' << s->getScore() << ' ' << s->getProject() << endl;
		for (int i = 0; i < staffCount; i++) {
			if (staffList[i].getType() == 0 && strcmp(staffList[i].getProject(),s->getProject())==0) {
				cout << staffList[i].getId() << ' ' << staffList[i].getName() << ' ' << staffList[i].getScore() << ' ' << staffList[i].getProject() << endl;
			}
		}
	}
}

bool StaffSystem::GetStaffFromFile(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		return false; // Failed to open file
	}
	int type, score;
	char name[_MAX_LENGTH];
	char project[_MAX_LENGTH];
	char id[_MAX_LENGTH];
	while (file >> type  >> id >> name  >> score  >> project && staffCount < capacity) {
		Staff staff;
		staff.setType(type);
		staff.setId(id);
		staff.setName(name);
		staff.setScore(score);
		staff.setProject(project);
		addStaff(staff);
	}
	file.close();
	return true;
}

bool StaffSystem::SaveStaffToFile(const string& filename) const {
	ofstream file(filename);
	if (!file.is_open()) {
		return false; // Failed to open file
	}
	for (int i = 0; i < staffCount; ++i) {
		file << staffList[i].getType() << ' ' << staffList[i].getId() << ' '
			<< staffList[i].getName() << ' ' << staffList[i].getScore() << ' '
			<< staffList[i].getProject() << endl;
	}
	file.close();
	return true;
}

int StaffSystem::getStaffCount() const {
	return staffCount;
}