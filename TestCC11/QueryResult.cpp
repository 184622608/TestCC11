#include "stdafx.h"
#include "QueryResult.h"


using namespace std;

ostream& print(ostream& os, const QueryResult& qr)
{
	os << qr.sought << " 出现 " << qr.lines->size() << " 个文本行位置" << endl;
	for (auto num : *qr.lines)
	{
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
		
		
	}
	return os;
}



