//---------- Interface de la classe <model> --------------------------
#if ! defined MODEL_H
#define MODEL_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include <map>
#include <list>
#include <fstream>
#include <sstream>

using std::vector;
using std::string;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

template <typename T>
class Model {

//----------------------------------------------------------------- PUBLIC
    public:
        
//----------------------------------------------------- Méthodes publiques
        static T& get(size_t);
        static T& get(const string&);
        static void populate(const string&, bool skip = false);
        static vector<T>& getAll(void);

//------------------------------------------------------------------ PRIVE
    private:

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
        static vector<T> objects;
        static std::map<string, size_t> index;
friend class TestsMeasurement;
};

template <typename T>
vector<T> Model<T>::objects;

template <typename T>
std::map<string, size_t> Model<T>::index;

template <typename T>
T& Model<T>::get(size_t id) {
    return objects[id];
}

template <typename T>
T& Model<T>::get(const string& name) {
    return objects[index[name]];
}

template <typename T>
void Model<T>::populate(
    const string& filename, 
    bool skipHeader) { 

    std::ifstream fs(filename);
    string buffer;

    // File not open properly
    if (!fs.is_open()) { exit(1); }

    // Skip first line
    if (skipHeader) { getline(fs, buffer); }

    // For every row in the file
    while (getline(fs, buffer)) {

        // Break row in fields
        std::stringstream ss(buffer);
        std::list<string> fields;
        string field;

        while (getline(ss, field, ';')) {
            fields.push_back(field);
        }

        // Create and register object
        T* object = new T(fields);
        object->_id = objects.size();
        object->updateBackRefs();
        objects.push_back(*object);
        index.insert(std::make_pair(
            object->getUnique(), 
            object->_id
        ));

    }

    fs.close();
}

template <typename T>
vector<T>& Model<T>::getAll(void) {
    return objects;
}

#endif