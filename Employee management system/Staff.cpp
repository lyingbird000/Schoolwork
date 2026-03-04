#define _CRT_SECURE_NO_WARNINGS
#include "Staff.h"
#include <string>
#include <iostream>
using namespace std;
Staff::Staff() {
	type = 0;
	id[0] = '\0';
	name[0] = '\0';
	score = 0;
	project[0] = '\0';
}

Staff::~Staff() {}
void Staff::setType(bool t) {
	type = t;
}

bool Staff::getType() const {
	return type;
}

void Staff::setId(const char* i) {
	strncpy(id, i, _MAX_LENGTH - 1);
	id[_MAX_LENGTH - 1] = '\0';
}

const char* Staff::getId() const {
	return id;
}

void Staff::setName(const char* n) {
	strncpy(name, n, _MAX_LENGTH - 1);
	name[_MAX_LENGTH - 1] = '\0';
}

const char* Staff::getName() const {
	return name;
}

void Staff::setScore(int s) {
	score = s;
}

int Staff::getScore() const {
	return score;
}

void Staff::setProject(const char* p) {
	strncpy(project, p, _MAX_LENGTH - 1);
	project[_MAX_LENGTH - 1] = '\0';
}

const char* Staff::getProject() const {
	return project;
}

