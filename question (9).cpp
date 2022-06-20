#include<string>
#include<iostream>
#include<fstream>
#include<deque>
#include<vector>
#include<nlohmann/json.hpp>
#include"question.hpp"

using std::string;
using std::ifstream;


int right = 0;
int wrong = 0;


Question::Question(string file_name, int question_index){


	
  ifstream in_stream2;
	in_stream2.open(file_name);
  nlohmann::json j;
  in_stream2 >> j;
  category = j["results"][question_index]["category"];
	type = j["results"][question_index]["type"];
	difficulty = j["results"][question_index]["difficulty"];
	question = j["results"][question_index]["question"];
  correct_answer = j["results"][question_index]["correct_answer"];
  // inocorrect answers takes special handling because we need to read 
	//several
  // strings into an array of strings.
  number_incorrect_answers = j["results"][question_index]
	["incorrect_answers"].size();
  
	incorrect_answers = new string[number_incorrect_answers];
  for (int x = 0; x < number_incorrect_answers; x++) {
		 incorrect_answers[x] = j["results"][question_index]
		["incorrect_answers"][x];
	}
}
Question::~Question(){
	delete [] incorrect_answers;
}
void Question::print_question() {

	int input;

	
	
  std::cout << "The category is: " << Question::category << std::endl;
  std::cout << "The type is: " << Question::type << std::endl;
  std::cout << "The difficulty is: " << Question::difficulty << std::endl << std::endl;
  std::cout << "The question is: " << Question::question << std::endl <<std::endl;
	
	
  for (int x = 0; x < number_incorrect_answers; x++) {

		answers.push_back(incorrect_answers[x]);
		
	}
	answers.push_back(correct_answer);

	std::random_shuffle(answers.begin(), answers.end());

	
	
	std::cout<< "Choices:" << std::endl << std::endl;

	for(int i = 0 ; i < answers.size(); i ++) {

		std::cout << i+1 << ". " << answers[i] << std::endl << std::endl;
	}

	std::cout << "What is your choice (Numbers only)? ";

	std::cin >> input;

	std::cout << std::endl;

	
	if(input == 1){

		if(answers[0] == correct_answer){

			right += 1;
			std::cout << "You got it right!" << std::endl << std::endl;
		} else {
			
			wrong += 1;
			std::cout<< "You got it wrong!" << std::endl << std::endl;
		}
	}
	else if (input == 2){

		if(answers[1] == correct_answer){

			right += 1;
			std::cout << "You got it right!" << std::endl << std::endl;
		} else {
			
			wrong += 1;
			std::cout<< "You got it wrong!" << std::endl << std::endl;
		}
	}
	else if (input > answers.size()){
		
		wrong += 1;
		std::cout<< "You got it wrong! Choose a valid option!" << std::endl << std::endl;
		
	}
	else if (input == 3) {

		if (answers[2] == correct_answer){
			
			right +=1;
			std::cout << "You got it right!" << std::endl << std::endl;
			
		} else {
			
			wrong += 1;
			std::cout<< "You got it wrong!" << std::endl << std::endl;
		}
	} else if (input == 4) {

		if(answers[3] == correct_answer){
			
			right +=1;
			std::cout << "You got it right!" << std::endl << std::endl;
		} else {
			
			wrong +=1;
			std::cout<< "You got it wrong!" << std::endl << std::endl;
		}
	} 

	std::cout<< "Number of right answers: " << right << std::endl << std::endl;
	std::cout<< "Number of wrong answers: " << wrong << std::endl << std::endl;
	
	
}
string Question::getCategory() {
	
	return category;
}

