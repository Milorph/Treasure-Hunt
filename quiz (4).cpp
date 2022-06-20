#include<string>
#include<iostream>
#include<fstream>
#include<random>
#include<nlohmann/json.hpp>
#include"quiz.hpp"

using std::string;
using std::ifstream;

Quiz::Quiz(string file_name){
 
  ifstream in_stream;
	in_stream.open(file_name);
  nlohmann::json j;
  in_stream >> j;
  // figure out how many questions there are in the json file
  // then for each question instantiate a question object and place it into 
	//the the vector of question
  int number_questions = j["results"].size();
	
	for (int x = 0; x < number_questions; x++) {
		
		Question *question = new Question(file_name, x);
		questions.push_back(question);
		
	}

}
Quiz::~Quiz(){

	
}
void Quiz::print_all_questions() {
  for (int x = 0; x < questions.size(); x++) {
   
// get the question object out pointer of the vector and call 
//that question objects print_question function 
		questions[x]->print_question();
		std::cout << std::endl;
	}
}