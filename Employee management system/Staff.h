#ifndef STAFF_H
#define STAFF_H
#define _MAX_LENGTH 50
using namespace std;
class Staff {
private:
	bool type; // 0 for regular staff, 1 for manager
	char id[_MAX_LENGTH];
	char name[_MAX_LENGTH];
	int score;
	char project[_MAX_LENGTH];
public:
	Staff();
	~Staff();

	void setType(bool t);
	bool getType() const;
	void setId(const char* i);
	const char* getId() const;
	void setName(const char* n);
	const char* getName() const;
	void setScore(int s);
	int getScore() const;
	void setProject(const char* p);
	const char* getProject() const;
};


#endif
