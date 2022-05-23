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

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
map<string, T> singleKeyDeserialize(
	const string& path, 
	int key_index, 
	bool skip_header = false) 
{

    map<string, T> result;
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
	
	cout << "Read process started." << endl;

	while (getline(fs, buffer))
	{
		// Break row in fields
		cout << "Break row into fields" << endl;
		stringstream ss(buffer);
		list<string> fields;
		string field, pk;

		size_t column_index = 0;
		while (getline(ss, field, ';'))
		{
			cout << "For field : " << field << endl;
			if (column_index == pk_index) { pk = field; }
			else { fields.push_back(field); }
			column_index++;
		}

		// Insert retreived data
		cout << "Insert record into db" << endl;
		data.insert(std::make_pair(pk, T(fields)));
	}

	fs.close();
	return data;
}
#endif
