#include "word_ladder.hpp"

using namespace std;

vector<string> getNextWordsForWord(string word, vector<string> wordList) {
	vector<string> nextWords;

	for (size_t i = 0; i < wordList.size(); ++i)
	{
		int diff = getDiffCount(word, wordList[i]);
		if (diff == 1)
		{
			nextWords.push_back(wordList[i]);
		}
	}

	return nextWords;
}

vector<string> getNextWordsForWord(element &entry) {
	vector<string> nextWords;

	list<element *>::iterator linksIterator;
	for (linksIterator = entry.links.begin(); 
			linksIterator != entry.links.end(); ++linksIterator) 
	{
		nextWords.push_back((*linksIterator)->word);
	}

	return nextWords;
}

int getDiffCount(string word1, string word2) {
	int diff = 0;

	for (int i = 0; i < NO_OF_LETTERS; ++i)
	{
		if (word1.at(i) != word2.at(i))
		{
			++diff;
		}
	}

	return diff;
}

string findLongestLadder(vector<string> wordList) {
	int wordListSize = wordList.size();
	unsigned int longestLadderSize = 0;
	string longestLadder;

	for (int i = 0; i < wordListSize; ++i)
	{
		vector<string> t_vector = getNextWordsForWord(wordList[i], wordList);
		if (longestLadderSize < t_vector.size()) 
		{
			longestLadderSize = t_vector.size();
			longestLadder = wordList[i];
		}
	}

	cout <<"Longest ladder size : "<<longestLadderSize<<endl;
	return longestLadder;
}

string findLongestLadder(vector<element> &wordListDS) {
	int wordListSize = wordListDS.size();
	int  longestLadderSize= 0;
	string longestLadder;

	for (int i = 0; i < wordListSize; ++i) {
		if (wordListDS.at(i).noOfLadders > longestLadderSize) {
			longestLadderSize = wordListDS.at(i).noOfLadders;
			longestLadder = wordListDS.at(i).word;
		}
	}

	cout <<"Longest ladder size : "<<longestLadderSize<<endl;
	return longestLadder;
}

void buildLadderDataStructure(vector<element> &wordListDS) {
	int wordListSize = wordListDS.size();

	for (int i = 0; i < wordListSize; ++i)
	{
		for (int j = i + 1; j < wordListSize; ++j)
		{
			element e1 = wordListDS.at(i);
			element e2 = wordListDS.at(j);

			int diff = getDiffCount(e1.word, e2.word);

			if (diff == 1) {
				wordListDS.at(i).links.push_back(&wordListDS.at(j));
				wordListDS.at(j).links.push_back(&wordListDS.at(i));
			}			
		}
	}
}

void updateNumberOfLadders(vector<element> &wordListDS) {
	int wordListSize = wordListDS.size();	

	for (int i = 0; i < wordListSize; ++i)
	{
		wordListDS.at(i).noOfLadders = wordListDS.at(i).links.size(); 
	}
}

vector<string> getWordsReachableInNSteps(element *start, int nSteps) {
	vector<string> reachableWords;
	queue<element *> Q;
	list<element *>::iterator linksIterator;

	start->distanceFromSource = 0;
	Q.push(start);

	while(! Q.empty()) {
		element *t_element = Q.front();
		reachableWords.push_back(t_element->word);

		if (t_element->distanceFromSource < nSteps + 1) {
			for(linksIterator = t_element->links.begin(); 
				linksIterator != t_element->links.end(); ++linksIterator)
			{
				(*linksIterator)->distanceFromSource = t_element->distanceFromSource + 1;
				Q.push((*linksIterator));
			}
		}

		Q.pop();
	}

	return reachableWords;
}