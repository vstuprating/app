/*
 * text_miner.h
 *
 *  Created on: Nov 21, 2015
 *      Author: denis
 */

#ifndef TEXT_MINER_H_
#define TEXT_MINER_H_



#include "storage/storage.h"
#include "classifier/classifier.h"




class TextMiner
{
public:

	TextMiner(const unsigned int classifiersNumber = 1);
	~TextMiner();

	const std::vector<ranged_list> process(const std::string& fileName) const;


	void addCategory(const std::string& categName, const unsigned int classifierType);
	void removeCategory(const std::string& categName);

	/* fileName - file should contain categories and words for each category */
	void openDictionary(const std::string& fileName);

private:

	std::vector< base_classifier > _classifiers;
	Storage _storage;

};



#endif /* TEXT_MINER_H_ */
