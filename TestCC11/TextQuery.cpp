#include "stdafx.h"
#include "TextQuery.h"

#include <sstream>

using namespace std;

TextQuery::TextQuery(ifstream& is) : file(new vector<string>)
{
	string text;

	while (getline(is, text))
	{
		file->push_back(text);       //存入输入行的内容

		int n = file->size() - 1;    //行号

		istringstream line(text);

		string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
			{
				lines.reset(new set<line_no>);
			}

			lines->insert(n);
		}
	}
}


QueryResult TextQuery::query(const std::string& sought) const
{

	// 未找到指定时，返回空指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	// 使用find 而不是下标，避免添加单词
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file); // 未找到
	else
		return QueryResult(sought, loc->second, file);
}
