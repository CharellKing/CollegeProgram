#include <iostream>


using namespace std;

#include "NODE.H"

NODE::NODE(double components, NODE *next): components(components), next(next)
{

}

NODE*& NODE::Next()
{
	return this->next;
}

double& NODE::Components()
{
	return this->components;
}
