#include <iostream>
#include <stdexcept>
#include "storage.h"



void Storage::addCateg(const std::string& categName)
{
//	std::cout << "addCateg working..." << std::endl;
	if( _storage.find(categName) == _storage.end() )
	{
		_storage[categName] = std::set<std::string>();
	}
	else
	{
		throw std::runtime_error("This category is already exist.");
	}

}



void Storage::removeCateg(const std::string& categName)
{
//	std::cout << "removeCateg working..." << std::endl;
	if( _storage.find(categName) != _storage.end() )
	{
		_storage.erase(categName);
	}
	else
	{
		std::cerr << "Missing category:  " << categName << std::endl;
	}
}



void Storage::addWordInCateg(const std::string& word, const std::string& categName)
{
//	std::cout << "addWordInCateg working..." << std::endl;
	if( _storage.find(categName) != _storage.end() )
	{
		_storage[categName].insert( word );
	}
	else
	{
		std::cerr << "Missing category:  " << categName << std::endl;
	}
}


void Storage::removeWordFromCateg(const std::string& word, const std::string& categName)
{
//	std::cout << "removeWordFromCateg working..." << std::endl;
	if( _storage.find(categName) != _storage.end() )
	{
		_storage[categName].erase( word );
	}
	else
	{
		std::cerr << "Missing category:  " << categName << std::endl;
	}

}


const std::string Storage::getWordCateg(const std::string& word) const
{
//	std::cout << "getWordCateg working..." << std::endl;

	std::map<std::string, std::set<std::string> >::const_iterator map_iter = _storage.begin();

	for( ; map_iter != _storage.end(); ++map_iter)
	{
		std::set<std::string>::const_iterator set_iter = map_iter->second.begin();
		for( ; set_iter != map_iter->second.end(); ++set_iter)
		{
			if( word.compare(*set_iter) == 0)
			{
				return map_iter->first;
			}
		}
	}

	/*
	 * if searching word does not contain in storage - return empty string
	 * */
	return std::string();
}


const std::vector<std::string> Storage::getCategList() const
{
//	std::cout << "getCategList working..." << std::endl;

	std::vector<std::string> res( _storage.size(), std::string() );
	std::map<std::string, std::set<std::string> >::const_iterator map_iter = _storage.begin();

	for(unsigned int i = 0 ; map_iter != _storage.end(); ++map_iter, ++i)
	{
		res[i] = map_iter->first;
	}

	return res;
}


const std::map<std::string, std::set<std::string> > Storage::getStorage() const
{
//	std::cout << "getStorage working..." << std::endl;

	return _storage;
}


