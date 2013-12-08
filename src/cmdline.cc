/* cmdline.cc
 *
 */

#include "database.h"

// everything starts from here
int main (int argc, char *argv[]) {
	SimpleDB *solution = new SimpleDB;
	while (1) {
		string command, name, value;
		cin >> command;
		if (command.compare("SET") == 0) {
			cin >> name >> value;
			if (solution->set_element(name, value) < 0)
				return 0;
		} // end "SET" if
		else if (command.compare("UNSET") == 0) {
			cin >> name;
			if (solution->unset_element(name) < 0)
				return 0;
		} // end "UNSET" if 
		else if (command.compare("GET") == 0) {
			cin >> name;
			string *value = new string;
			if (solution->get_element(name, value) < 0)
				return 0;
			cout << *value << endl;
		} // end "GET" if
		else if (command.compare("NUMEQUALTO") == 0) {
			cin >> value;
			int *number = new int;
			if (solution->num_equal_to(value, number) < 0)
				return 0;
			cout << *number << endl;
		} // end "NUMEQUALTO" if
		else if (command.compare("BEGIN") == 0) {
			if (solution->begin() < 0)
				return -1;
		} // end "BEGIN" if
		else if (command.compare("ROLLBACK") == 0) {
			if (solution->rollback() < 0)
				cout << "NO TRANSACTION\n";
		} // end "ROLLBACK" if
		else if (command.compare("COMMIT") == 0) {
			if (solution->commit() < 0)
				cout << "NO TRANSACTION\n";
		} // end "COMMIT" if
		else if (command.compare("END") == 0){ 
			
			return 0;
		}
	} // end while loop
	return 0;
}
