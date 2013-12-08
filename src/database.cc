/* database.cc
 *
 */

#include "database.h"


SimpleDB::SimpleDB () {
	/*** Constructor for SimpleDB class
	 * time = O(1)
	 * @param database, the map variable to store the key/value elements
	 * @param cur_transaction, the transaction numbers so far 
	 * @param transaction, the map variable to store the transaction happens
	 */ 
	database.clear();
	cur_transaction = 0;
	transaction.clear();
}

int SimpleDB::begin () {
	/** Function, begin the transaction
	 * time = O(1)
	 */
	cur_transaction++;
	return 0;
}

int SimpleDB::rollback () {
	/** Function, rollback the changes
	 * time = O(n), n is the size of the transaction map
	 * once rollback, update the database latest value
	 */
	if (cur_transaction <= 0)
		return -1;
	for (map<string, vector<string> >::iterator it = transaction.begin();
			it != transaction.end(); ++it) {
		if (!it->second.empty()) {
			database[it->first] = it->second.back();
			it->second.pop_back();
		}
		else {
			database.erase(it->first);
			transaction.erase(it->first);
		}
	}
	cur_transaction--;
	return 0;
}

int SimpleDB::commit () {
	/** Function, commit the changes
	 * time = O(n), n is the size of the transaction size
	 */
	if (cur_transaction <= 0)
		return -1;
	transaction.clear();
	cur_transaction=0;
	return 0;
}

int SimpleDB::set_element (string name, string value) {
	/** Function, set the element in the database
	 * time = O(1)
	 * tansancation map always store the old values
	 * @param name/value, the pair set
	 */
	if (database.find(name) != database.end())
		transaction[name].push_back(database[name]);
	database[name] = value;
	return 0;
}

int SimpleDB::get_element (string name, string *value) {
	/** Function, get the element in the database
	 * time = O(1)
	 * Not required, but return -1 if database not built successfully
	 * @param name, the element to check
	 */
	if (database.find(name) == database.end()) {
		*value = "NULL";
		return 0;
	}
	*value = database[name];
	return 0;
}

int SimpleDB::unset_element (string name) {
	/** Function, unset the element in the database
	 * time = O(1)
	 * Not required, but if needed, return -1 for no key found in map
	 * @param name
	 */
	if (database.find(name) == database.end())
		return 0;
	else
		transaction[name].push_back(database[name]);
	database.erase(name);
	return 0;
}

int SimpleDB::num_equal_to (string value, int *number) {
	/** Function, count the number of value equal to desired
	 * time = O(n), n is the size of the map
	 * one efficient way would be count the number when set the element, which would be constant time but loss the space complexity
	 * @param *number, the count result stored place
	 */
	*number = 0;
	map<string, string>::iterator it;
	for (it=database.begin(); it!=database.end(); it++) {
		if (it->second == value)
			++*number;
	}
	return 0;
}

SimpleDB::~SimpleDB () {
	/** Destructor for SimpleDB class
	 *
	 */
//	database.clear();
	for (map<string, string>::iterator it = database.begin(); it != database.end(); ++it)
		delete &it->second;
	for (map<string, vector<string> >::iterator it = transaction.begin(); it != transaction.end(); ++it)
		delete &it->second;
}
