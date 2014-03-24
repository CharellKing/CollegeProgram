#include <iostream>

using namespace std;

#include <string>

#include <cstring>

#include <cctype>

#include "TEACHER.H"

void TEACHER::SetPosition()
{
	//char c;
	string Position;
	int i, k = 0;
	cout << "职 称:(assistant, lecture, associate_professor, professor)" << endl;
	do
	{
		if(k) cout << "请重新输入!" << endl;
		cin >> Position;
		for(i = 0; i < Position.length(); i ++) Position[i] = toupper(Position[i]);
		k ++;
	}
	while(Position != "ASSISTANT" && Position != "LECTURE" && Position != "ASSOCIATE_PROFESSOR" && Position != "PROFESSOR");
	if(Position == "ASSISTANT") position = ASSISTANT;
	if(Position == "LECTURE") position = LECTURE;
	if(Position == "ASSOCIATE_PROFESSOR") position = ASSOCIATE_PROFESSOR;
	if(Position == "PROFESSOR") position = PROFESSOR;
}
	
TITLE TEACHER::GetPosition()
{
	return position;
}

void TEACHER::Position()
{
	if(position == ASSISTANT) cout << "ASSISTANT";
	if(position == LECTURE)   cout << "LECTURE";
	if(position == ASSOCIATE_PROFESSOR) cout << "ASSOCIATE_PROFESSOR";
	if(position == PROFESSOR) cout << "PROFESSOR";
}


