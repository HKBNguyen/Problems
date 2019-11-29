#include <unordered_map>
#include <iostream>
#include <string>
#include <locale>
using namespace std;

void hashConvert(unordered_map<char, int> &map, string str)
{
	for (int i=0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			continue;
		unordered_map<char, int>:: iterator itr;
		// check if the char already exists
		itr = map.find(tolower(str[i]));
		// if it equals end that means it doesn't exist
		if (itr == map.end())
		{
			map.insert({tolower(str[i]), 1});
		}
		else
		{
			itr->second = itr->second + 1;
		}
	}
}

bool isPaliPerm(string str)
{
	unordered_map<char, int> count;
	hashConvert(count, str);
	// count now has the number all of the characters and their number of appearances
	unordered_map<char, int>:: iterator itr;
	int counter = 0;
	for (itr = count.begin(); itr != count.end(); itr++)
	{
		if ((itr->second % 2) != 0)
		{
			counter++;
		}
	}
	cout << counter;
	if (counter <= 1)
	return true;
	else
	return false;
}

int main()
{
	string str = "Tact coa";
	bool x = isPaliPerm(str);
	cout << x;
}