#ifndef _CharWeight_H_

#define _CharWeight_H_

class CharWeight
{
public:
	CharWeight(char c = '\0', double weight = 0, int num = -1);
	void Output()const;
	char c;
	double weight;
	int num;
};

int CompareWeight(const CharWeight& one, const CharWeight& other);

#endif