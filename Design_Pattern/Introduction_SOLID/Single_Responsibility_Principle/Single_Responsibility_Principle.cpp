#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;


using namespace std;
using namespace boost;

struct Journal {
	string title;
	vector<string> entries;

	Journal(const string& title) : title(title) {}

	void add_entry(const string& entry) {
		static int count;
		entries.push_back(lexical_cast<string>(count++) + ": " + entry);
	}

	void save(const string& filename) {
		ofstream ofs(filename);
		for (auto& e : entries)
			ofs << e << endl;
	}
};

struct PersistentManager {
	static void save(const Journal& j, const string& filename) {
		ofstream ofs(filename);
		for (auto& e : j.entries)
			ofs << e << endl;
	}
};

void Single_Responsibility_Principle() {
	Journal journal{ "Dear diary" };
	journal.add_entry("I studied cpp");
	journal.add_entry(" I ate Gopchang-Jeongol today");	

	getchar();
}
