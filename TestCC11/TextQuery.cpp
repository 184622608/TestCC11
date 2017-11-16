#include "stdafx.h"
#include "TextQuery.h"

#include <sstream>

using namespace std;

TextQuery::TextQuery(ifstream& is) : file(new vector<string>)
{
	string text;

	while (getline(is, text))
	{
		file->push_back(text);       //���������е�����

		int n = file->size() - 1;    //�к�

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

	// δ�ҵ�ָ��ʱ�����ؿ�ָ��
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	// ʹ��find �������±꣬������ӵ���
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file); // δ�ҵ�
	else
		return QueryResult(sought, loc->second, file);
}
