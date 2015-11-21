/*
 * storage.h
 *
 *  Created on: Nov 21, 2015
 *      Author: denis
 */

#ifndef STORAGE_H_
#define STORAGE_H_


#include <map>
#include <set>
#include <vector>
#include <string>


class Storage
{
public:

	void addCateg(const std::string& categName);
	void removeCateg(const std::string& categName);

	void addWordInCateg(const std::string& word, const std::string& categName);
	void removeWordFromCateg(const std::string& word, const std::string& categName);

	const std::string getWordCateg(const std::string& word) const;
	const std::vector<std::string> getCategList() const;
	const std::map<std::string, std::set<std::string> > getStorage() const;

private:

	std::map<std::string, std::set<std::string> > _storage;

};


#endif /* STORAGE_H_ */
