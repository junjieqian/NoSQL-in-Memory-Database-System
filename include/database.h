/* database.h
 *
 */

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <map>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class SimpleDB {
private:
	map<string, string> database;
	int cur_transaction;
	map<string, vector<string> > transaction;
public:
	SimpleDB ();
	int begin ();
	int rollback ();
	int commit ();
	int set_element (string name, string value);
	int get_element (string name, string *value);
	int unset_element (string name);
	int num_equal_to (string value, int *number);
	~SimpleDB ();
};

#endif 
//DATABASE_H_
