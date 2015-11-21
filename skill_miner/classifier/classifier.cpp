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


void show_vector(const std::vector<std::string>& vstrings)
{
	for(std::vector<std::string>::const_iterator it = vstrings.begin(); it != vstrings.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}


void show_frequency_vector(const ranged_list& vstrings)
{
	for(ranged_list::const_iterator it = vstrings.begin(); it != vstrings.end(); ++it)
	{
		std::cout << it->first << ":"<< it->second << "  ";//std::endl;
	}
	std::cout << std::endl;
}


const int find_in_vector(const std::vector< std::pair<std::string, double> >& vec, const std::string& str)
{
	for(unsigned int i = 0; i < vec.size(); i++)
	{
		if( str.compare( vec[i].first ) == 0 )
			return i;
	}

	return -1;
}


const ranged_list StandartClassifier::process(const std::string& categ, const std::string& text, const Storage& storage) const
{
//	std::cout << "StandartClassifier working..." << std::endl;


	const std::vector<std::string> vstrings = split(text);

	std::vector< std::pair<std::string, double> > frequency_vector;
	unsigned int total = 0;

	for(unsigned int i = 0; i < vstrings.size(); i++)
	{
		if( categ.compare(storage.getWordCateg( vstrings[i] )) == 0)
		{
			total++;

//			std::cout << "FOUND: " << vstrings[i] << std::endl;

			const int indx = find_in_vector( frequency_vector, vstrings[i] );

			if( indx != -1)
			{
//				std::cout << "INDEX: " << indx << std::endl;
//				std::cout << "SIZE: " << frequency_vector.size() << std::endl;
//				std::cout << "DATA: " << frequency_vector[indx].second << std::endl;
				frequency_vector[indx].second++; // HERE IS A BUG!!!
			}
			else
			{
				const std::pair<std::string, double> _pair(vstrings[i], 1);
				frequency_vector.push_back( _pair );

//				std::cout << "INDEX: " << indx << std::endl;
//				std::cout << "SIZE: " << frequency_vector.size() << std::endl;
//				std::cout << "DATA: " << frequency_vector[indx].second << std::endl;
			}
		}
	}

//	std::cout << "TOOOOTAL: " << total << std::endl;

	for(unsigned int i = 0; i < frequency_vector.size(); i++)
		frequency_vector[i].second /= total;

//	show_vector(vstrings);
//	show_frequency_vector(frequency_vector);

	return frequency_vector;
}






const ranged_list ExperienceClassifier::process(const std::string& categ, const std::string& text, const Storage& storage) const
{
	const std::string moc_string = "experience_classifier";
	const double moc_double = 0.1;

	const std::pair<std::string, double> moc_pair(moc_string, moc_double);
	const std::vector<std::pair<std::string, double> > moc_vector(1, moc_pair);

	std::cout << "ExperienceClassifier working..." << std::endl;

	const std::vector<std::string> vstrings = split(text);

//	show_vector(vstrings);


	return moc_vector;
}
