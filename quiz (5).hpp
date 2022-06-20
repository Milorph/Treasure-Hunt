#include <string>
#include <vector>
#include "question.hpp"

using std::vector;
using std::string;

class Quiz {

public:

	vector<Question*> questions;
	
public:
  Quiz(string file_name);
  ~Quiz();
  void print_all_questions();

};