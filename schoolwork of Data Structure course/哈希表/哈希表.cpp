#include <iostream>
using namespace std;
class HashTable
{
private:
	static const int tableSize = 11;
	int table[tableSize];
public:
	HashTable()
	{
		for (int i = 0; i < tableSize; i++)
		{
			table[i] = -1; // -1 indicates empty slot
		}
	}
	int hashFunction(int key)
	{
		return key % tableSize;
	}
	void insert(int key)
	{
		int index = hashFunction(key);
		while (table[index] != -1)
		{
			index = (index + 1) % tableSize; // Linear probing
		}
		table[index] = key;
	}
	bool search(int key)
	{
		int index = hashFunction(key);
		int startIndex = index;
		while (table[index] != -1)
		{
			if (table[index] == key)
			{
				return true;
			}
			index = (index + 1) % tableSize;
			if (index == startIndex)
			{
				break; // We have looped through the table
			}
		}
		return false;
	}
	void display()
	{
		for (int i = 0; i < tableSize; i++)
		{
			if (table[i] != -1)
			{
				std::cout << i << " --> " << table[i] << std::endl;
			}
			else
			{
				std::cout << i << " --> " << "Empty" << std::endl;
			}
		}
	}
};
int main()
{
	HashTable ht;
	ht.insert(10);
	ht.insert(20);
	ht.insert(30);
	ht.insert(25);
	ht.display();
	cout << "Searching for 20: " << (ht.search(20) ? "Found" : "Not Found") << endl;
	cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
	return 0;
}
