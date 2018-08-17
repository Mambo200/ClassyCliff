#pragma region system include
#include <sstream>
#include <istream>
#pragma endregion


#pragma region project include
#include "Score.h"
#include "Helper.h"
#pragma endregion

int GScore::m_score = 0;

void GScore::SetScoreToFile(int _score)
{
	// string from file
	string s = LoadStringFromFile("Save/score.txt");

	// create stream from string
	istringstream iss(s);

	// through all lines
	for (string line; getline(iss, line);)
	{
		// key and value of variable
		string key;
		string value;

		// string stream of line
		istringstream issLine(line);

		// get key and value
		getline(issLine, key, ':');
		getline(issLine, value);

		// if key find set variable
		if (key == "SCORE")
			m_score = atoi(value.c_str());
		
		// write score in value
		stringstream ss;
		ss << "SCORE:" <<_score;
		string str = ss.str();

		// write score in file
		if (_score > m_score)
			SaveStringToFile(str, "Save/score.txt");
	}
}
	int GScore::GetScoreFromFile()
	{
		// string from file
		string s = LoadStringFromFile("Save/score.txt");

		// create stream from string
		istringstream iss(s);

		// through all lines
		for (string line; getline(iss, line);)
		{
			// key and value of variable
			string key;
			string value;

			// string stream of line
			istringstream issLine(line);

			// get key and value
			getline(issLine, key, ':');
			getline(issLine, value);

			// if key find set variable
			if (key == "SCORE")
				m_score = atoi(value.c_str());
		}
		return m_score;
	}
