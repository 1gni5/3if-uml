#if ! defined DESERIALIZE_HPP
#define DESERIALIZE_HPP

#include <string>
#include <list>
#include <map>
#include <sstream>
#include <fstream>

using std::list;
using std::string;
using std::stringstream;
using std::ifstream;
using std::multimap;

template <typename T>
multimap<string, T> deserialize(
	const string& path, 
	int key_index, 
	bool skip_header = false) 
{

    multimap<string, T> result;
    ifstream fs(path);
    string buffer;

	// File not open properly
	if (!fs.is_open()) { exit(1);}

    if (skip_header) {
        getline(fs, buffer);
    }

	while (getline(fs, buffer))
	{
		// Break row in fields
		stringstream ss(buffer);
		list<string> fields;
		string field, key;

        int column_index = 0;
		while (getline(ss, field, ';'))
		{
            if (column_index == key_index) { key = field; }
            else { fields.push_back(field); }
            column_index++;
		}

        result.insert(std::make_pair(key, T(fields)));
	}

	fs.close();
    return result;
}
#endif