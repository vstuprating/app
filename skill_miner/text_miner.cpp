#include <stdexcept>
#include <iostream>
#include <cassert>

#include "text_miner.h"


TextMiner::TextMiner(const unsigned int classifiersNumber)
{
	_classifiers.assign(classifiersNumber, NULL);

	std::cout << "TextMiner() working..." << std::endl;
}


TextMiner::~TextMiner()
{
	for(unsigned int i = 0; i < _classifiers.size(); i++)
	{
		if(_classifiers[i] != NULL)
			delete _classifiers[i];
	}

	std::cout << "~TextMiner() working..." << std::endl;
}


const std::vector<ranged_list> TextMiner::process(const std::string& fileName) const
{
	const std::vector<ranged_list> moc_vec(1, _classifiers[0]->process("Text for processing", _storage) );

	std::cout << "TextMiner::process working..." << std::endl;
	return moc_vec;
}


void TextMiner::addCategory(const std::string& categName, const unsigned int classifierType)
{
	_storage.addCateg(categName);


	assert( (classifierType >= 0) && (classifierType <= 1) );

	switch(classifierType)
	{
		case 0:
			_classifiers[classifierType] = new StandartClassifier;
			break;

		case 1:
			_classifiers[classifierType] = new ExperienceClassifier;
			 break;
		/*
		 * Over here you should add initialization for your own classifier
		 * */

		default:
			throw std::runtime_error("Incorrect classifier type!");
			break;

	}

	std::cout << "TextMiner::addCategory working..." << std::endl;
}




void TextMiner::removeCategory(const std::string& categName)
{
	std::cout << "removeCategory working..." << std::endl;
	_storage.removeCateg( categName );
}



void TextMiner::openDictionary(const std::string& fileName)
{
	std::cout << "TextMiner::addDictionary working..." << std::endl;
//	_storage.add
}






