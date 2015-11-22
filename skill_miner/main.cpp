#include <fstream>
#include <iostream>
#include <exception>

#include "text_miner.h"


void show_frequency_vector_m(const ranged_list& vstrings)
{
	for(ranged_list::const_iterator it = vstrings.begin(); it != vstrings.end(); ++it)
	{
		std::cout << it->first << ":"<< it->second << " ";//std::endl;
	}
//	std::cout << std::endl;
}




const std::string PL = "programming_languages";
const std::string FW = "frameworks";
const std::string EX = "experience";
const std::string OT = "other_tools";
const std::string OS = "operating_systems";
const std::string FL = "foreign_languages";
const std::string DG = "degree";












int main(int argc, char** argv)
{
	if(argc != 3)
	{
		std::cerr << "Invalid arguments..." << std::endl;
		return 1;
	}

	try
	{

		/*
		 * Tests for TextMiner - success
		 */
		TextMiner app;
		app.addCategory(PL, cl_standart);
		app.addCategory(FW, cl_standart);
		app.addCategory(EX, cl_standart);
		app.addCategory(OT, cl_standart);
		app.addCategory(OS, cl_standart);
		app.addCategory(FL, cl_standart);
		app.addCategory(DG, cl_standart);

		app.openDictionary(argv[2]);

		app.removeCategory(OT);

		const std::vector<ranged_list> vec = app.process(argv[1]);
		for(unsigned int i=0; i < vec.size(); i++)
		{
			std::cout << "[ "; show_frequency_vector_m(vec[i]); std::cout << "]" << std::endl;
		}


		/*
		 * Tests for Storage - success
		 */
//		Storage st;
//		st.addCateg(PL);
//		st.addCateg(FW);
//		st.addCateg(EX);
//		st.addCateg(OT);
////		st.removeCateg(OT);
//		st.addWordInCateg("Java", PL);
//		st.addWordInCateg("C++", PL);
//		st.addWordInCateg("C#", PL);
//		st.addWordInCateg("Pascal", PL);
//		st.addWordInCateg("Python",PL);
//		st.addWordInCateg("English", OT);
//		st.addWordInCateg("French", OT);
//		st.addWordInCateg("Boost", FW);
//		st.addWordInCateg("Django", FW);
//		st.addWordInCateg("STL", FW);

//		st.removeWordFromCateg("Pascal", PL);

		// false calls
//		st.addWordInCateg("WTF", "NoName");
//		st.removeCateg("WTF");

//		std::cout << st.getWordCateg("Java") << std::endl;
//		std::cout << st.getWordCateg("Borya") << std::endl;


		/*
		 * Test for StandartClassifier - success
		 */
//		Classifier* clf = new StandartClassifier();
//		std::cout << std::endl;
//		std::cout << PL << ": [ "; show_frequency_vector_m( clf->process(PL, text_text, st) ); std::cout << "]" << std::endl;
//		std::cout << OT << ": [ "; show_frequency_vector_m( clf->process(OT, text_text, st) ); std::cout << "]" << std::endl;
//		std::cout << FW << ": [ "; show_frequency_vector_m( clf->process(FW, text_text, st) ); std::cout << "]" << std::endl;
//		std::cout << std::endl;
//		delete clf;



	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}










