// TestCC11.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>

#include <memory>
#include <vector>

#include <fstream>

#include "TextQuery.h"

using namespace std;

void runQueries(ifstream& infile)
{
	TextQuery tq(infile);

	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;

		if (!(cin >> s) || s == "q")
		{
			break;
		}

		print(cout, tq.query(s)) << endl;
	}


}


int main()
{
	ifstream infile("D://test.txt");

	if (infile.is_open())
		runQueries(infile);


	infile.close();


	getchar();
	return 0;
}

