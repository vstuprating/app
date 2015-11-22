/*
 * classifier.h
 *
 *  Created on: Nov 21, 2015
 *      Author: denis
 */

#ifndef CLASSIFIER_H_
#define CLASSIFIER_H_

#include "../storage/storage.h"


enum ClassifiersList
{
	cl_standart = 0,
	cl_exp
};



class Classifier;

typedef std::vector< std::pair < std::string, double > > ranged_list;
typedef Classifier* base_classifier;



class Classifier
{
public:

	virtual const ranged_list process(const std::string& categ, const std::string& text, const Storage& storage) const = 0;
	virtual ~Classifier(){}
};






class StandartClassifier: public Classifier
{
public:

	const ranged_list process(const std::string& categ, const std::string& text, const Storage& storage) const;

private:


};


class ExperienceClassifier: public Classifier
{
public:

	const ranged_list process(const std::string& categ, const std::string& text, const Storage& storage) const;

private:

};


const std::vector<std::string> split(const std::string& text);



#endif /* CLASSIFIER_H_ */
