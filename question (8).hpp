#include <string>
#include <vector>
#include <array>

using std::string;

class Question {

private:
 string category;
 string type;
 string difficulty;
 string question;
 string correct_answer;
 string *incorrect_answers;
 int number_incorrect_answers;
 std::vector<string> answers; 
 std::vector<string> rand_answers; 

public:
	string getCategory();
  Question(string file_name, int question_index);
  ~Question();
  virtual void print_question();
};