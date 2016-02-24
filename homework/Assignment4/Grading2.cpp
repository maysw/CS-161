/**************************************************************************
**Program: Grading2.cpp
**Author: William Mays
**Date: 11/19/14
**Description: This program gathers a users test, labs, assignment, 
**homework and final scores from the command line and outputs their final grade.
**Input:
**Output:
**************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>



using namespace std;

int check (string a)
{
	int i = 0;
	cin >> a;
	do
{
	for (i = 0; i < a.length(); i++)
	if(!((a.at(i) >= '0') && (a.at(i) <= '9')))
{
	cout << "Error! Invalid Input!\nPlease try again: " << endl;
	cin >> a;
}
}
	while (i != a.length());
	return atoi(a.c_str());
}

//Gets the test scores and finds the final grade for tests
void test_scores (int b, int& tests, int& test_score, int t_score)
{
    string temp_1;
	b = tests;
    test_score = 0;
	//gets all of the test scores
	while (b > 0)
{
	cout << "Please insert a test score: " << endl;
	t_score = check(temp_1);
	while (!(t_score <= 100) || !(t_score >= 0))
{
            cout << "Error! Invalid Input:\nPlease insert a test score: " << endl;
            t_score = check(temp_1);
}
        //adds all of the test scores together
		test_score = test_score + t_score;
        --b;
}
	//gets the weighted average of your test scores
    test_score = test_score / tests * 0.25;
}

//Gets the quiz scores and finds the final grade for quizzes
void quiz_scores (int c, int quizzes, int& quiz_score, int q_score)
{
    string temp_1;
	c = quizzes;
    quiz_score = 0;
	//gets all of the quiz scores
    while (c > 0)
{
        cout << "Please insert a quiz score: " << endl;
        q_score = check(temp_1);
        while (!(q_score <= 100) || !(q_score >= 0))
{
            cout << "Error! Invalid Input:\nPlease insert a quiz score: " << endl;
            q_score = check(temp_1);
}
		//adds all of the test scores together
		quiz_score = quiz_score + q_score;
        --c;
}
	//gets the weighted average of your quiz scores
    quiz_score = quiz_score / quizzes * 0.1;
}

//Gets the assignment scores and finds the final grade for the assignments
void assign_scores (int d, int assign, int& assign_score, int a_score)
{
    string temp_1;
	d = assign;
    assign_score = 0;
	//gets all of the assignment scores 
	
    while (d > 0)
{
        cout << "Please insert an assignment score: " << endl;
        a_score = check(temp_1);
        while (!(a_score <= 100) || !(a_score >= 0))
{
            cout << "Error! Incorrect Input!\nPlease insert an assignment score: " << endl;
            a_score = check(temp_1);
}
		//adds all of the assignment scores together
        assign_score = assign_score + a_score;
        --d;
}
	//gets the weighted average of your assignment scores
    assign_score = assign_score / assign * .40;
}

//Gets the lab scores and finds the final grade for the labs
void lab_scores (int a, int labs, int& lab_score, int& l_score)
{
	a = labs;
    lab_score = 0;
	//gets all of the lab scores
    while (a > 0)
{
        cout << "Please insert a lab score: " << endl;
        cin >> l_score;
		while (!(l_score <= 100) || !(l_score >= 0))
{
            cout << "Error! Invalid Input!\nPlease insert a lab score: " << endl;
            cin >> l_score;
			
}
		//adds all of the lab scores together
        lab_score = lab_score + l_score;
        --a;
}

	//gets the weighted average of your final lab scores
    lab_score = lab_score / labs * 0.1;
}

//Gets the final score and finds the final grade with all of the weighted averages
void finalScore (int& final_score, int final, int s_final, int lab_score, int assign_score, int quiz_score, int test_score)
{
	//checks to see if their is a final
	if (final == 1)
{
		//makes sure it is a number
        cout << "Please insert the final score: " << endl;
		cin >> final_score;
        while (!(final_score <= 100) || !(final_score >= 0))
{
            cout << "Error! Invalid Input!\nPlease insert the final score: " << endl;
			cin >> final_score;
}
		//gets the weighted average of the final score
        final_score = final_score * 0.15;
		//adds up all of the weighted averages and displays the final grade
        s_final = final_score + lab_score + assign_score + test_score + quiz_score;
        cout << "Final Grade: " << s_final << endl;
}
    if (final == 0)
{
		//adds up all of the weighted averages and displays the final grade
        s_final = (lab_score + assign_score + quiz_score + test_score) / 0.85;
        cout << "Final Grade: " << s_final << endl;
}
}

//Checks to see if the input is actually a number
int num_pos(string num_str)
{
    for(int x = 0; x < num_str.length(); x++)
        if(!((num_str.at(x) >= '0') && (num_str.at(x) <= '9')))
        {
            return -1;
        }
    return atoi(num_str.c_str());
}

//runs everything
int main (int argc, char *argv[])
{
    int a, b, c, d, tests, quizzes, assign, labs, final, test_score, t_score, quiz_score, q_score, assign_score, a_score, lab_score, l_score, final_score, s_final;
    
	if (argc == 11)
	{
	for(int i = 1; i < argc; i += 2)
	{
		if(argv[i][0] == '-' && argv[i][1] == 't')
		{
			tests = atoi(argv[i+1]);
			test_scores (b, tests, test_score, t_score);
		}
		else if(argv[i][0] == '-' && argv[i][1] == 'q')
		{
			quizzes = atoi(argv[i+1]);
			quiz_scores (c, quizzes, quiz_score, q_score);
		}
			else if(argv[i][0] == '-' && argv[i][1] == 'a')
		{
			assign = atoi(argv[i+1]);
			assign_scores (d, assign, assign_score, a_score);
		}
		else if(argv[i][0] == '-' && argv[i][1] == 'l')
		{
			labs = atoi(argv[i+1]);
			lab_scores (a, labs, lab_score, l_score);
		}
		else if(argv[i][0] == '-' && argv[i][1] == 'f')
		{
			final = atoi(argv[i+1]);
			finalScore (final_score, final, s_final, lab_score, test_score, quiz_score, assign_score);
		}
		else
		{
			cout << "Error!" << endl;
		}						
	}
	}
	else
	{
		cout << "Error!" << endl;
	}
	return 0;
}
