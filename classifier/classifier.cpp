#include <iostream>

#include "classifier.h"


const ranged_list StandartClassifier::process(const std::string& text, const Storage& storage) const
{
	const std::string moc_string = "standart_classifier";
	const double moc_double = 0.1;

	const std::pair<std::string, double> moc_pair(moc_string, moc_double);
	const std::vector< std::pair<std::string, double> > moc_vector(1, moc_pair);

	std::cout << "StandartClassifier working..." << std::endl;

	return moc_vector;
}


const ranged_list ExperienceClassifier::process(const std::string& text, const Storage& storage) const
{
	const std::string moc_string = "experience_classifier";
	const double moc_double = 0.1;

	const std::pair<std::string, double> moc_pair(moc_string, moc_double);
	const std::vector<std::pair<std::string, double> > moc_vector(1, moc_pair);

	std::cout << "ExperienceClassifier working..." << std::endl;

	return moc_vector;
}
