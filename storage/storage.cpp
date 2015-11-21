#include <iostream>
#include "storage.h"



void Storage::addCateg(const std::string& categName)
{
	std::cout << "addCateg working..." << std::endl;
}



void Storage::removeCateg(const std::string& categName)
{
	std::cout << "removeCateg working..." << std::endl;
}



void Storage::addWordInCateg(const std::string& word, const std::string& categName)
{
	std::cout << "addWordInCateg working..." << std::endl;
}


void Storage::removeWordFromCateg(const std::string& word, const std::string& categName)
{
	std::cout << "removeWordFromCateg working..." << std::endl;
}


const std::string Storage::getWordCateg(const std::string& word) const
{
	std::cout << "getWordCateg working..." << std::endl;
	return std::string();
}


const std::vector<std::string> Storage::getCategList() const
{
	std::cout << "getCategList working..." << std::endl;
	return std::vector<std::string>(1, "moc_string");
}

const std::map<std::string, std::set<std::string> > Storage::getStorage() const
{
	std::cout << "getStorage working..." << std::endl;

	return _storage;
}


