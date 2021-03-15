#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <algorithm> 

using namespace std;

int main() {

  vector<pair<int,int>> questions;
	for(int year = 2019; year > 2001; year--){
		for(int questionNum = 1; questionNum < 7; questionNum++){
			pair<int,int> q = {year, questionNum};
			questions.push_back(q);
		}
	}

	vector<pair<int,int>> questionsAnswered;
	ifstream infile("questionsAnswered.txt");
	int year = 0, questionNum = 0;
	while (infile >> year >> questionNum)
	{
			pair<int,int> qAnswered = {year, questionNum};
			questionsAnswered.push_back(qAnswered);
	}

	random_device random_device;
  mt19937 engine{random_device()};
  uniform_int_distribution<int> dist(0, questions.size() - 1);
	pair<int,int> q = {0, 0};
	bool isAnswered = false;
	
	do{
		q = questions[dist(engine)];
		isAnswered = false;
		for(int i = 0; i < questionsAnswered.size(); i++){
			pair<int,int> qAnswered = questionsAnswered[i];
			if(q.first == qAnswered.first && q.second == qAnswered.second){
				isAnswered = true;
			}
		}
	}
	while(isAnswered);
	
	cout << q.first << " exam, question #" << q.second << endl;

  // ofstream f("questionsAnswered.txt");
	ofstream f;
  f.open("questionsAnswered.txt", ios_base::app); 
	f << q.first << " " << q.second << '\n';

	if(questionsAnswered.size() == 107){
		cout << "Done all questions!" << endl;
	}
	else if(questionsAnswered.size() == 0){
		cout << "Done 1 question." << endl;
	}
	else{
		cout << "Done " << questionsAnswered.size() + 1 << " questions." << endl;
	}

  return 0;
}
