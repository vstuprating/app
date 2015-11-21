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




const std::string PL = "Programming languages";
const std::string FW = "Frameworks";
const std::string EX = "Experience";
const std::string OT = "Other tools";

const std::string text_text = "with English strong Boost Boost Boost C++, "
							  "of multithreading, G French, STL STL and good English "
							  "to join Uplay PC Kiev team.STL STL STL, Boost Django Django C++ Java C++ C# Python Python C++";


int main(int argc, char** argv)
{
	try
	{

		/*
		 * Tests for TextMiner - success
		 */
		TextMiner app;
		app.addCategory(PL, cl_standart);
		app.addCategory(FW, cl_standart);
		app.addCategory(EX, cl_standart);
		app.addCategory(OT, cl_exp);
		app.openDictionary("Dictionary.json");

		app.removeCategory(OT);

		app.process("input_file.json");



		/*
		 * Tests for Storage - success
		 */
		Storage st;
		st.addCateg(PL);
		st.addCateg(FW);
		st.addCateg(EX);
		st.addCateg(OT);
//		st.removeCateg(OT);
		st.addWordInCateg("Java", PL);
		st.addWordInCateg("C++", PL);
		st.addWordInCateg("C#", PL);
		st.addWordInCateg("Pascal", PL);
		st.addWordInCateg("Python",PL);
		st.addWordInCateg("English", OT);
		st.addWordInCateg("French", OT);
		st.addWordInCateg("Boost", FW);
		st.addWordInCateg("Django", FW);
		st.addWordInCateg("STL", FW);

//		st.removeWordFromCateg("Pascal", PL);

		// false calls
//		st.addWordInCateg("WTF", "NoName");
//		st.removeCateg("WTF");

//		std::cout << st.getWordCateg("Java") << std::endl;
//		std::cout << st.getWordCateg("Borya") << std::endl;


		/*
		 * Test for StandartClassifier
		 */
		Classifier* clf = new StandartClassifier();
		std::cout << std::endl;
		std::cout << PL << ": [ "; show_frequency_vector_m( clf->process(PL, text_text, st) ); std::cout << "]" << std::endl;
		std::cout << OT << ": [ "; show_frequency_vector_m( clf->process(OT, text_text, st) ); std::cout << "]" << std::endl;
		std::cout << FW << ": [ "; show_frequency_vector_m( clf->process(FW, text_text, st) ); std::cout << "]" << std::endl;
		std::cout << std::endl;
		delete clf;

	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}










