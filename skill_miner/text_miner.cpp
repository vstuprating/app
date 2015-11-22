#include <stdexcept>
#include <iostream>
#include <cassert>
#include <fstream>

#include "text_miner.h"


const std::string parseFile(const std::string& path)
{
	std::ifstream infile( path.c_str() );
	if( !infile.is_open() )
	{
		throw std::runtime_error("File didn't open: " + path);
	}

	std::string text;
	{
		std::string line;
		if (infile.is_open())
		{
			while ( getline (infile,line) )
			{
				text.append(line);
			}
			infile.close();
		}
	}

	return text;
}



TextMiner::TextMiner(const unsigned int classifiersNumber)
{
	_classifiers.assign(classifiersNumber, NULL);
}


TextMiner::~TextMiner()
{
	for(unsigned int i = 0; i < _classifiers.size(); i++)
	{
		if(_classifiers[i] != NULL)
			delete _classifiers[i];
	}
}


const std::vector<ranged_list> TextMiner::process(const std::string& fileName) const
{
	std::vector<ranged_list> res;

	const std::vector<std::string> categs = _storage.getCategList();
	std::vector<std::string>::const_iterator it = categs.begin();

	std::ifstream infile( fileName.c_str() );
	if( !infile.is_open() )
	{
		throw std::runtime_error("File didn't open: " + fileName);
	}

	std::string text;
	{
		std::string line;
		if (infile.is_open())
		{
			while ( getline (infile,line) )
			{
				text.append(line);
			}
			infile.close();
		}
	}

//	std::cout << "Read text" << text << std::endl;

	for( ; it != categs.end();++it)
		res.push_back( _classifiers[0]->process( *it, text, _storage) );

	return res;
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

}


void TextMiner::removeCategory(const std::string& categName)
{
	_storage.removeCateg( categName );
}


void TextMiner::openDictionary(const std::string& fileName)
{
	std::ifstream infile( fileName.c_str() );
	if( !infile.is_open() )
	{
		throw std::runtime_error("File didn't open: " + fileName);
	}

	std::string path;
	if (infile.is_open())
	{
		while ( getline (infile, path) )
		{
			const std::string text = parseFile(path);
			std::vector<std::string> vec = split(text);

			while( !vec.empty() )
			{
				_storage.addWordInCateg(vec.back(), std::string( path.begin()+11, path.end()-4) );
				vec.pop_back();
			}
		}
		infile.close();
	}
}





