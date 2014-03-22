#include "word_ladder.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	// Function prototypes
	void buildLadderDataStructure(vector<element> &);
	void updateNumberOfLadders(vector<element> &);

	void printLinksForEachEntry(vector<element> &);
	void printLinksForEntry(element );

	string findLongestLadder(vector<element> &);

	vector<element> wordListDS;
	string word;
	int wordIndex = 0;

	// Maps a word to the index in the vector
	map<string, int> wordToVectorIndex;

	// Push the word to the vector
	while (cin >> word)
	{
		element e;
		e.word = word;
		e.noOfLadders = 0;
		e.isVisited = ELEMENT_NOT_VISITED;
		e.distanceFromSource = 0;
		wordListDS.push_back(e);

		wordToVectorIndex[word] = wordIndex++;
	}

	cout <<"Input processed"<<endl;

	// Build Ladder DS
	cout <<"Building Ladder data structure"<<endl;
	buildLadderDataStructure(wordListDS);
	cout <<"Data structure built"<<endl;

	// Update number of ladders in the DS
	cout <<"Updating number of Ladders for each node"<<endl;
	updateNumberOfLadders(wordListDS);
	cout <<"Number of Ladders updated"<<endl;

	printLinksForEntry(wordListDS.at(wordToVectorIndex["puma"]));

	string longestLadder = findLongestLadder(wordListDS);

	cout <<"Longest ladder : "<<longestLadder<<endl;

	// Go through the graph to find reachable words
	vector<string> reachableWords = getWordsReachableInNSteps(&wordListDS.at(wordToVectorIndex["best"]), 3);

	cout <<"Reachable words from best : "<<endl;
	int reachableWordsSize = reachableWords.size();

	for (int i = 0; i < reachableWordsSize; ++i)
	{
		cout <<reachableWords.at(i)<<endl;
	}

	return 0;
}

/**
*	Helper function for gdb
**/
void printVectorEntry(element entry)
{
	cout <<entry.word<<endl;
	cout <<entry.noOfLadders<<endl;
	cout <<entry.isVisited<<endl;
	cout <<entry.distanceFromSource<<endl;
}

void printLinksForEachEntry(vector<element> &wordListDS) 
{
	void printLinksForEntry(element );

	for (vector<element>::iterator elementIterator = wordListDS.begin(); 
			elementIterator != wordListDS.end(); ++elementIterator)
	{
		printLinksForEntry(*elementIterator);
	}
}

void printLinksForEntry(element entry)
{
	cout <<endl;
	cout <<"********"<<endl;
	cout <<"Ladders for word : "<<entry.word<<endl;
	cout <<"********"<<endl;
	list<element *>::iterator linksIterator;
	for (linksIterator = entry.links.begin(); 
			linksIterator != entry.links.end(); ++linksIterator) 
	{
		cout <<(*linksIterator)->word<<endl;
	}
}