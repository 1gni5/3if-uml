#if ! defined DESERIALIZE_H
#define DESERIALIZE_H

#include <string>
#include <list>
#include <map>
#include <sstream>
#include <fstream>

using std::list;
using std::string;
using std::stringstream;
using std::ifstream;
using std::map;
using std::pair;

template <typename T, typename M>
M deserialize(
	const string& path,
	M& data,
	size_t pk_index,
	bool skip_header = false)
{
	ifstream fs(path);
	string buffer;

	// File not open properly
	if (!fs.is_open()) { exit(1);}

	// Skip header if needed
    if (skip_header) { getline(fs, buffer); }


	while (getline(fs, buffer))
	{
		// Break row in fields
		stringstream ss(buffer);
		list<string> fields;
		string field, pk;

		size_t column_index = 0;
		while (getline(ss, field, ';'))
		{
			if (column_index == pk_index) { pk = field; }
			fields.push_back(field);
			column_index++;
		}

		// std::cout << "ROW NUMBER : " << pk << std::endl;

		// Insert retreived data
		data.insert(std::make_pair(pk, T(fields)));
	}

	fs.close();
	return data;
}
#endif
