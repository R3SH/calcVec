#include <iostream>

struct point
{
	double x;
	double y;
};

class LVec
{
private:
	point* vertex;
public:
	LVec();
	LVec(struct point spnt);
	LVec(const LVec& src);
	~LVec();
	double getLength();
	double getAngle(LVec& fVec, LVec& sVec);
	point get_sp();
	point get_ep();
	void set_sp();			//Set starting point
	void set_ep();			//Set ending point
	void printVec();

	friend void operator- (const LVec& src);
	friend void operator* (const LVec& src, double mult);
	friend double operator* (LVec& lSrc, LVec& rSrc);
};

