#include "Tasks.h"
#include "Methods.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <ctime>
#include <list>
using namespace std;

void Tasks::set_id(const string& id) { task_id = id; }
void Tasks::set_description(const string& description) { task_description = description; }
void Tasks::set_status(const string& status) { task_status = status; }
void Tasks::set_at(const string& at) { task_at = at; }
string Tasks::get_id() const { return task_id; }
string Tasks::get_description() const { return task_description; }
string Tasks::get_status() const { return task_status; }
string Tasks::get_at() const { return task_at; }
void Tasks::list_task() const
{
	string str = "<info>==========================</>";
	output(str);
	str = "ID: ";
	str.append(task_id);
	output(str);
	str = "Description: ";
	str.append(task_description);
	output(str);
	str = "Status: ";
	str.append(task_status);
	output(str);
	str = "Updated: ";
	str.append(task_at);
	output(str);
}

int main()
{
	Tasks task;
	list<Tasks> tasks;
	string choose, id, description, status = "Todo", at;
	list<Tasks>::iterator  it;
	bool exist = false;
	
start:
	cmd();
	getline(cin, choose);
	while (!correct_choose(choose))
	{
		cerr << "choose from 1 to 10.\n";
		cout << "Enter a valid choose: ";
		getline(cin, choose);
	}
	if (choose.size() == 1)
	{
		switch (choose.at(0))
		{
			case '1':
				cout << "Enter ID: ";
				getline(cin, id);
				while (!correct_id(id))
				{
					cerr << "Error!, The ID consists of numbers only and is less than 1000\n";
					cout << "Enter a valid id: ";
					getline(cin, id);
				}
				output("Wait, I'm search for the ID.");
				loading();
				it = find_if(tasks.begin(), tasks.end(), [&](const Tasks& word) { return word.get_id() == id; });
				if (it != tasks.end())
				{
					output("The ID was found I can't add a task.\n");
					goto start;
				}
				cout << "\nEnter decription: ";
				getline(cin, description);
				while (!correct_description(description))
				{
					cerr << "Error!, The name consists of letters only and the number of letters is greater than 7.\n";
					cout << "Enter a valid description: ";
					getline(cin, description);
				}
				output("Added in progress.");
				loading();
				task.set_id(id);
				task.set_description(description);
				task.set_status(status);
				at = set_time();
				task.set_at(at);
				tasks.push_front(task);
				output("Added successful.\n");
				goto start;

			case '2':
				cout << "Enter ID: ";
				getline(cin, id);
				while (!correct_id(id))
				{
					cerr << "Error!, The ID consists of numbers only and is less than 1000\n";
					cout << "Enter a valid id: ";
					getline(cin, id);
				}
				output("Wait, I'm search for the ID.");
				loading();
				it = find_if(tasks.begin(), tasks.end(), [&](const Tasks& word) { return word.get_id() == id; });
				if (it == tasks.end())
				{
					output("ID is not available\n");
					goto start;
				}
				cout << "\nEnter decription: ";
				getline(cin, description);
				while (!correct_description(description))
				{
					cerr << "Error!, The name consists of letters only and the number of letters is greater than 7.\n";
					cout << "Enter a valid description: ";
					getline(cin, description);
				}
				output("Update in progress.");
				loading();
				it->set_description(description);
				at = set_time();
				it->set_at(at);
				output("Updated successful.\n");
				goto start;
			case '3':
				cout << "Enter ID: ";
				getline(cin, id);
				while (!correct_id(id))
				{
					cerr << "Error!, The ID consists of numbers only and is less than 1000\n";
					cout << "Enter a valid id: ";
					getline(cin, id);
				}
				output("Wait, I'm search for the ID.");
				loading();
				it = find_if(tasks.begin(), tasks.end(), [&](const Tasks& word) { return word.get_id() == id; });
				if (it == tasks.end())
				{
					output("ID is not available\n");
					goto start;
				}
				output("\nDelete in progress.");
				loading();
				tasks.erase(it);
				output("Deleted successful.\n");
				goto start;
			
			case '4':
				cout << "Enter ID: ";
				getline(cin, id);
				while (!correct_id(id))
				{
					cerr << "Error!, The ID consists of numbers only and is less than 1000\n";
					cout << "Enter a valid id: ";
					getline(cin, id);
				}
				output("Wait, I'm search for the ID.");
				loading();
				it = find_if(tasks.begin(), tasks.end(), [&](const Tasks& word) { return word.get_id() == id; });
				if (it == tasks.end())
				{
					output("ID is not available\n");
					goto start;
				}
				output("\nMark a task as in progress.");
				loading();
				it->set_status("Progress");
				it->set_at(at);
				output("Marked a task successful.\n");
				goto start;
			
			case '5':
				cout << "Enter ID: ";
				getline(cin, id);
				while (!correct_id(id))
				{
					cerr << "Error!, The ID consists of numbers only and is less than 1000\n";
					cout << "Enter a valid id: ";
					getline(cin, id);
				}
				output("Wait, I'm search for the ID.");
				loading();
				it = find_if(tasks.begin(), tasks.end(), [&](const Tasks& word) { return word.get_id() == id; });
				if (it == tasks.end())
				{
					output("ID is not available\n");
					goto start;
					
				}
				output("\nMark a task as in done.");
				loading();
				it->set_status("Done");
				it->set_at(at);
				output("Marked a task successful.\n");
				goto start;
			
			case '6':
				it = tasks.begin();
				if (it == tasks.end())
				{
					output("List empty!\n");
					goto start;
				}
				for (; it != tasks.end(); ++it) it->list_task();
				goto start;
			case '7':
				it = tasks.begin();
				exist = false;
				for (; it != tasks.end(); ++it)
				{
					if (it->get_status() == "Done")
					{
						it->list_task();
						exist = true;
						goto start;
					}
				}
				if (it == tasks.end() || !exist) output("List empty!\n");
				goto start;
			case '8':
				it = tasks.begin();
				exist = false;
				for (; it != tasks.end(); ++it)
				{
					if (it->get_status() == "Todo")
					{
						it->list_task();
						exist = true;
						goto start;
					}
				}
				if (it == tasks.end() || !exist) output("List empty!\n");
				goto start;
			case '9':
				it = tasks.begin();
				exist = false;
				for (; it != tasks.end(); ++it)
				{
					if (it->get_status() == "Progress")
					{
						it->list_task();
						exist = true;
						goto start;
					}
				}
				if (it == tasks.end() || !exist) output("List empty!\n");
				goto start;
		}
	}
	else if (choose == "10")
	{
		loading();
		output("Dev: Abdurahman");
	}
	return 0;
}



string set_time()
{
	time_t now;
	time(&now);
	char buffer[26];
	ctime_s(buffer, sizeof(buffer), &now);
	return buffer;
}

void output(const string input)
{
	for (int i = 0; i < input.size(); ++i)
	{
		clog << input.at(i);
		Sleep(10);
	}
	cout << endl;
}



void cmd()
{
	cout << "[1] Add task\n";
	cout << "[2] Update task\n";
	cout << "[3] Delete task\n";
	cout << "[4] Mark a task in progress\n";
	cout << "[5] Mark a task in done\n";
	cout << "[6] List all tasks\n";
	cout << "[7] List all tasks that are done\n";
	cout << "[8] List all tasks that are not done\n";
	cout << "[9] List all tasks that are in progress\n";
	cout << "[10] Exit\n";
}

bool correct_choose(const string& choose)
{
	return (choose.size() == 2 && choose == "10" || choose.size() == 1 && choose != "0");
}

bool correct_id(const string& id)
{
	auto it = find_if(id.begin(), id.end(), [](const char& z) { return (isdigit(z)); });
	return (id.size() < 4 && it != id.end() && id != "0");
}

bool correct_description(const string& description)
{
	auto it = find_if(description.begin(), description.end(), [](const char& z) { return (isalpha(z) && z == ' '); });
	return (it != description.end() || description.size() > 7);
}

void loading()
{
	for (int i = 0; i <= 100; ++i)
	{
		cout << "\rLoading " << i;
		Sleep(10);
	}
	cout << endl;
}
