/**************************************************************************
**Program: counting.cpp
**Author: William Mays
**Date: 11/8/14
**Description: This program gathers a users test, labs, assignment, 
**homework and final scores to calculate their final grade in the class.
**Input:
**Output:
**************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

//Gets the lab scores and finds the final grade for the labs
void lab_scores (int a, int labs, int& lab_score, int l_score)
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

//Gets the test scores and finds the final grade for tests
void test_scores (int b, int& tests, int& test_score, int t_score)
{
    b = tests;
    test_score = 0;
	//gets all of the test scores
	while (b > 0)
{
	cout << "Please insert a test score: " << endl;
	cin >> t_score;
	while (!(t_score <= 100) || !(t_score >= 0))
{
            cout << "Error! Invalid Input:\nPlease insert a test score: " << endl;
            cin >> t_score;
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
    c = quizzes;
    quiz_score = 0;
	//gets all of the quiz scores
    while (c > 0)
{
        cout << "Please insert a quiz score: " << endl;
        cin >> q_score;
        while (!(q_score <= 100) || !(q_score >= 0))
{
            cout << "Error! Invalid Input:\nPlease insert a quiz score: " << endl;
            cin >> q_score;
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
    d = assign;
    assign_score = 0;
	//gets all of the assignment scores 
	
    while (d > 0)
{
        cout << "Please insert an assignment score: " << endl;
        cin >> a_score;
        while (!(a_score <= 100) || !(a_score >= 0))
{
            cout << "Error! Incorrect Input!\nPlease insert an assignment score: " << endl;
            cin >> a_score;
}
		//adds all of the assignment scores together
        assign_score = assign_score + a_score;
        --d;
}
	//gets the weighted average of your assignment scores
    assign_score = assign_score / assign * .40;
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

//checks to see if input is actually a number
int get_number_tests()
{
	int x;
	string a;
	cin >> a;
	x = num_pos(a);
	while (x == -1)
	{
		cout << "Error! Invalid Input!\nPlease input how many tests:" << endl;
		cin >> a;
		x = num_pos(a);
	}
	return x;
}

//checks to see if input is actually a number
int get_number_assignments()
{
	int x;
	string a;
	cin >> a;
	x = num_pos(a);
	while (x == -1)
	{
		cout << "Error! Invalid Input!\nPlease input how many assignments: " << endl;
		cin >> a;
		x = num_pos(a);
	}
	return x;
}

//checks to see if input is actually a number
int get_number_labs()
{
	int x;
	string a;
	cin >> a;
	x = num_pos(a);
	while (x == -1)
	{
		cout << "Error! Invalid Input!\nPlease input how many tests: " << endl;
		cin >> a;
		x = num_pos(a);
	}
	return x;
}

//checks to see if input is actually a number
int get_number_quizzes()
{
	int x;
	string a;
	cin >> a;
	x = num_pos(a);
	while (x == -1)
	{
		cout << "Error! Invalid Input!\nPlease input how many quizzes: " << endl;
		cin >> a;
		x = num_pos(a);
	}
	return x;
}

//Gets how many test and quizzes were taken
void calcTQ (int& tests, int& quizzes)
{
    cout << "How many tests? " << endl;
    tests = get_number_tests();
    cout << "How many quizzes? " << endl;
    quizzes = get_number_quizzes();
}

//Gets how many assignments and labs were done
void calcAL (int& assign, int&labs)
{
    cout << "How many assignments? " << endl;
    assign = get_number_assignments();
    cout << "How many labs? " << endl;
    labs = get_number_labs();
}

//Asks if their is a final
void final_calc (int& final)
{
    cout << "Is there a final (1 = yes, 0 = no)? " << endl;
    cin >> final;
    while (!(final == 1) && !(final == 0))
{
        cout << "Error! Invalid Input!\nIs there a final (1= yes, 0= no): ";
        cin >> final;
}
}

//runs everything
int main ()
{
    int a, b, c, d, tests, quizzes, assign, labs, final, test_score, t_score, quiz_score, q_score, assign_score, a_score, lab_score, l_score, total, final_score, s_final;
    calcTQ (tests, quizzes);
    calcAL(assign, labs);
    final_calc(final);
    test_scores (b, tests, test_score, t_score);
    quiz_scores (c, quizzes, quiz_score, q_score);
    assign_scores (d, assign, assign_score, a_score);
    lab_scores (a, labs, lab_score, l_score);
    finalScore (final_score, final, s_final, lab_score, test_score, quiz_score, assign_score);
	return 0;
}
