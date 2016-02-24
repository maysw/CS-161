#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

void test_scores (int x, int& tests, int& testscore, int tscore)
{
        x = tests;
        testscore = 0;
        while (x > 0)
{
        cout << "Insert test score: ";
        cin >> tscore;
                while (!(tscore <= 100) || !(tscore >= 0))
{
                cout << "Incorrect value\nInsert test score: ";
                cin >> tscore;
}
        testscore = testscore + tscore;
        --x;
}
        testscore = testscore / tests * 0.25;
}
void quiz_scores (int y, int quizzes, int& quizscore, int qscore)
{
        y = quizzes;
        quizscore = 0;
        while (y > 0)
{
        cout << "Insert quiz score: ";
        cin >> qscore;
                while (!(qscore <= 100) || !(qscore >= 0))
{
                cout << "Incorrect value\nInsert quiz score: ";
                cin >> qscore;
}
        quizscore = quizscore + qscore;
        --y;
}
        quizscore = quizscore / quizzes * 0.1;
}

void assign_scores (int z, int assign, int& assignscore, int ascore)
{
        z = assign;
        assignscore = 0;
        while (z > 0)
{
        cout << "Insert assignment score: ";
        cin >> ascore;
                while (!(ascore <= 100) || !(ascore >= 0))
{
                cout << "Incorrect value\nInsert assignment score: ";
                cin >> ascore;
}

        assignscore = assignscore + ascore;
        --z;
}
        assignscore = assignscore / assign * .40;
}
void lab_scores (int a, int labs, int& labscore, int lscore)
{
        a = labs;
        labscore = 0;
        while (a > 0)
{
        cout << "Insert lab score: ";
        cin >> lscore;
                while (!(lscore <= 100) || !(lscore >= 0))
{
                cout << "Incorrect value\nInsert lab score: ";
                cin >> lscore;
}

        labscore = labscore + lscore;
        --a;
}
        labscore = labscore / labs * 0.1;
}
void final_score (int finalscore, int final, int sfinal, int labscore, int assignscore, int quizscore, int testscore)
{
        if (final == 1)
{
        cout << "Insert final score: ";
        cin >> finalscore;
                while (!(finalscore <= 100) || !(finalscore >= 0))
{
                cout << "Incorrect value\nInsert final score: ";
                cin >> finalscore;
}

        finalscore = finalscore * 0.15;
        sfinal = finalscore + labscore + assignscore + testscore + quizscore;
        cout << "Final Grade: " << sfinal << endl;
}
        if (final == 0)
{
        sfinal = (labscore + assignscore + quizscore + testscore) / 0.85;
        cout << "Final Grade: " << sfinal << endl;
}
}
int num_pos(string num_str)
{
        for(int x 0; x < num_str.length(); x++)
                if(!((num_str.at(x) >= '0') && (NUM_STR.AT(X) <= '9')))
                {
                cout << "You did not enter a positive number"
                return -1;
                }
        return atoi(num_str.c_str());
}

void calc (int& tests, int& quizzes)
{
        cout << "How many tests are there: ";
        cin >> tests;
        cout << "How many quizzes are there: ";
        cin >> quizzes;
}

void second_calc (int& assign, int&labs)
{
        cout << "How many assignments are there: ";
        cin >> assign;
        cout << "How many labs are there: ";
        cin >> labs;
}

void third_calc (int& final)
{
        cout << "Is there a final (1= yes, 0= no): ";
        cin >> final;
                while (!(final == 1) && !(final == 0))
{
                cout << "Not an option\n" << "Is there a final (1= yes, 0= no): ";
                cin >> final;
}
}
int main ()
{
        int x, y, z, a, tests, quizzes, assign, labs, final, testscore, tscore, quizscore, qscore, assignscore, ascore, labscore, lscore, total, finalscore, sfinal;
        calc (tests, quizzes);
        second_calc(assign, labs);
        third_calc(final);
        test_scores (x, tests, testscore, tscore);
        quiz_scores (y, quizzes, quizscore, qscore);
        assign_scores (z, assign, assignscore, ascore);
        lab_scores (a, labs, labscore, lscore);
        final_score (finalscore, final, sfinal, labscore, testscore, quizscore, assignscore);

return 0;
}