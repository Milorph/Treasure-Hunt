#include <iostream>
#include <bits/stdc++.h>
#include <deque>
#include "quiz.hpp"

bool compareQuestions (Question *a, Question *b) {
	return (a->getCategory() < b->getCategory());
}

int main() {
	int repeat = 1;
	int x;
  std::cout << "Test Reading JSON Data Containing Many Questions\n";

	while(repeat == 1) {
		system("curl https://opentdb.com/api.php?amount=10 > quiz.txt"); 
			
		Quiz *my_quiz = new Quiz("quiz.txt");
		
		// put all the questions from the vector into a deque
		std::deque<Question*> questions_deque;
		
		for (Question *q : my_quiz->questions) {
			
			questions_deque.push_back(q);
		}
		// sort the deque of Questions on the category field
		std:sort(questions_deque.begin(), questions_deque.end(), compareQuestions);
		
		// put all the questions from the deque into the vector
		// first empty out the vector
		my_quiz->questions.clear();
		for (Question *q : questions_deque) {
			my_quiz->questions.push_back(q);
		}
		// print out the sorted vector of questions
		std::cout << "Sorted Questions" << std::endl;
		std::cout << "------------------" << std::endl;
		
		my_quiz->print_all_questions();
  	std::cout << std::endl;

		std::cout << "Would you like to play again? (type 1 for yes, or 2 for no) ";
		std::cin >> x;

		if(x == 1){

			repeat = 1;
		} else {
			
			repeat = 2;
		}
	}
	
}