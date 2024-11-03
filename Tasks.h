#pragma once
#ifndef TASKS_H
#define TASKS_H
#include <string>
using namespace std;

class Tasks
{
	string task_id;
	string task_description;
	string task_status;
	string task_at;
public:
	void set_id(const string&);
	void set_description(const string&);
	void set_status(const string&);
	void set_at(const string&);
	void list_task() const;
	string get_id() const;
	string get_description() const;
	string get_status() const;
	string get_at() const;
};

#endif

