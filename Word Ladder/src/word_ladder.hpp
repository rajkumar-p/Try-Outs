#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <queue>
#include <map>

using namespace std;

#ifndef NO_OF_LETTERS
#define NO_OF_LETTERS 4
#endif

enum elementVisitHistory { ELEMENT_NOT_VISITED = 0, ELEMENT_VISITED } ;

struct element
{
	string word;
	int noOfLadders;
	list<element *> links;
	elementVisitHistory isVisited; 
	int distanceFromSource;
};

vector<string> getNextWordsForWord(string , vector<string>);
vector<string> getNextWordsForWord(element &);
string findLongestLadder(vector<string>);
int getDiffCount(string , string );

void buildLadderDataStrucure(vector<element> & );
void updateNumberOfLadders(vector<element> & );
vector<string> getWordsReachableInNSteps(element *, int);