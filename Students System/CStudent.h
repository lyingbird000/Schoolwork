#define _CRT_SECURE_NO_WARNINGS
#ifndef CStudent_h
#define CStudent_h
class CStudent {
private:
	char mNo[9];
	char* mpName;
	int mNamelength;
	int mScore[5];
	static int mCount;
public:
	CStudent();
	CStudent(const CStudent& other);
	~CStudent();

	void SetStudent(char* zpName, const int& zNamelength, int zScore[5]);
	void ShowStudent() const;
	void CompareScore(const CStudent& zS) const;
	void CompareScore(const CStudent* zp) const;
	void ResetNo(char NewNo[9]);

	double AveScore() const;
	const char* ShowNo() const;

	friend void Compare(const CStudent& zS1, const CStudent& zS2);
};


#endif
