#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cstring>

#include "classifier.h"


struct tokens: std::ctype<char>
{
    tokens(): std::ctype<char>(get_table()) {}

    static std::ctype_base::mask const* get_table()
    {
        typedef std::ctype<char> cctype;
        static const cctype::mask *const_rc= cctype::classic_table();

        static cctype::mask rc[cctype::table_size];
        std::memcpy(rc, const_rc, cctype::table_size * sizeof(cctype::mask));

        rc[','] = std::ctype_base::space;
        rc[' '] = std::ctype_base::space;
        rc['.'] = std::ctype_base::space;
        rc[';'] = std::ctype_base::space;
        rc['\n'] = std::ctype_base::space;
        rc['\t'] = std::ctype_base::space;
        rc['('] = std::ctype_base::space;
        rc[')'] = std::ctype_base::space;

        return &rc[0];
    }
};


const std::vector<std::string> split(const std::string& text)
{
	std::stringstream ss( text );
	ss.imbue(std::locale(std::locale(), new tokens()));

	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;

	return std::vector<std::string>(begin, end);
}

void show_vector(std::vector<std::string> vstrings)
{
	for(std::vector<std::string>::const_iterator it = vstrings.begin(); it != vstrings.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}


const ranged_list StandartClassifier::process(const std::string& text, const Storage& storage) const
{
	const std::string moc_string = "standart_classifier";
	const double moc_double = 0.1;

	const std::pair<std::string, double> moc_pair(moc_string, moc_double);
	const std::vector< std::pair<std::string, double> > moc_vector(1, moc_pair);

	std::cout << "StandartClassifier working..." << std::endl;


	const std::vector<std::string> vstrings = split(text);

	show_vector(vstrings);




	return moc_vector;
}






const ranged_list ExperienceClassifier::process(const std::string& text, const Storage& storage) const
{
	const std::string moc_string = "experience_classifier";
	const double moc_double = 0.1;

	const std::pair<std::string, double> moc_pair(moc_string, moc_double);
	const std::vector<std::pair<std::string, double> > moc_vector(1, moc_pair);

	std::cout << "ExperienceClassifier working..." << std::endl;

	const std::vector<std::string> vstrings = split(text);

	show_vector(vstrings);


	return moc_vector;
}
