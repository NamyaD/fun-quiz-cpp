#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void showTerms() {
    cout << "\n===== Terms & Conditions =====\n";
    cout << "1. You confirm that at least 2 brain cells are working today.\n";
    cout << "2. If you fail, don't blame the keyboard or childhood trauma.\n";
    cout << "3. Full marks = Sharma Ji ka beta/beti.\n";
    cout << "4. You cannot use ChatGPT.\n";
    cout << "5. If you score zero, we will pretend we don't know you.\n";
    cout << "6. If you guess and get it right, act natural.\n";
}

bool loginSystem(string &name) {
    string password, confirm_password;
    int age;

    cout << "Enter your username: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    if (age < 18) {
        cout << "Invalid Age. You must be 18 or above to play.\n";
        return false;
    }

    cout << "\nWelcome, " << name << "!\n";
    cout << "Enter your password: ";
    cin >> password;

    for (int i = 1; i <= 3; i++) {
        cout << "Confirm your password: ";
        cin >> confirm_password;

        if (password == confirm_password) {
            cout << "Password matched successfully!\n";
            return true;
        } else {
            cout << "Password does not match. Attempts left: " << 3 - i << endl;
        }
    }

    cout << "Access Denied. The quiz was not even started yet, it was just passwords.\n";
    return false;
}

int readHighScore() {
    ifstream file("highscore.txt");
    int highScore = 0;

    if (file) {
        file >> highScore;
    }

    file.close();
    return highScore;
}

void updateHighScore(int score) {
    int highScore = readHighScore();

    if (score > highScore) {
        ofstream file("highscore.txt");
        file << score;
        file.close();

        cout << "\nNew High Score Created: " << score << endl;
    } else {
        cout << "\nCurrent High Score: " << highScore << endl;
    }
}

int askQuestion(string question, string options[], int correctOption, bool &lifelineUsed) {
    int answer;
    char lifelineChoice;

    cout << "\n------------------------------------\n";
    cout << question << endl;
    cout << "Think fast! Your imaginary timer is running...\n";

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }

    if (!lifelineUsed) {
        cout << "\nDo you want to use 50-50 lifeline? (Y/N): ";
        cin >> lifelineChoice;

        if (lifelineChoice == 'Y' || lifelineChoice == 'y') {
            lifelineUsed = true;
            cout << "\n50-50 Lifeline Activated!\n";
            cout << correctOption << ". " << options[correctOption - 1] << endl;

            for (int i = 0; i < 4; i++) {
                if (i != correctOption - 1) {
                    cout << i + 1 << ". " << options[i] << endl;
                    break;
                }
            }
        }
    }

    for (int attempt = 1; attempt <= 3; attempt++) {
        cout << "\nEnter your answer: ";
        cin >> answer;

        if (answer == correctOption) {
            cout << "Correct Answer!\n";

            if (attempt == 1) {
                return 1;
            } else {
                cout << "Correct, but no score because it took more than one attempt.\n";
                return 0;
            }
        } else {
            cout << "Wrong Answer. Try again.\n";
        }
    }

    cout << "Moving to next question...\n";
    return 0;
}

void showResult(string name, int score, int total) {
    cout << "\n====================================\n";
    cout << "              RESULT                \n";
    cout << "====================================\n";
    cout << "Player Name: " << name << endl;
    cout << "Final Score: " << score << "/" << total << endl;

    if (score == total) {
        cout << "Excellent! Sharma Ji is officially proud.\n";
    } else if (score >= total / 2) {
        cout << "Good attempt! Your brain cells survived.\n";
    } else {
        cout << "Nice try. Please recharge your brain and try again.\n";
    }

    cout << "\n====================================\n";
    cout << "           CERTIFICATE              \n";
    cout << "====================================\n";
    cout << "Congratulations " << name << "!\n";
    cout << "You have successfully completed the Funny Quiz Game.\n";
    cout << "Your score is " << score << " out of " << total << ".\n";
    cout << "====================================\n";
}

void generalKnowledgeQuiz(int &score, bool &lifelineUsed) {
    string q1[] = {"Delhi", "Solan", "Mumbai", "Shimla"};
    score += askQuestion("Q1. What is the capital of India?", q1, 1, lifelineUsed);

    string q2[] = {"Washington D.C.", "New York", "Houston", "San Diego"};
    score += askQuestion("Q2. What is the capital of America?", q2, 1, lifelineUsed);

    string q3[] = {"Hamburg", "Berlin", "Frankfurt", "Cologne"};
    score += askQuestion("Q3. What is the capital of Germany?", q3, 2, lifelineUsed);
}

void cppQuiz(int &score, bool &lifelineUsed) {
    string q1[] = {"Hyper Text Markup Language", "High Text Machine Language", "C++ Library", "None"};
    score += askQuestion("Q1. What does HTML stand for?", q1, 1, lifelineUsed);

    string q2[] = {"cout", "cin", "print", "display"};
    score += askQuestion("Q2. Which is used for output in C++?", q2, 1, lifelineUsed);

    string q3[] = {"int", "float", "string", "All of these"};
    score += askQuestion("Q3. Which of these is a data type?", q3, 4, lifelineUsed);
}

void aptitudeQuiz(int &score, bool &lifelineUsed) {
    string q1[] = {"10", "20", "30", "40"};
    score += askQuestion("Q1. What is 20% of 100?", q1, 2, lifelineUsed);

    string q2[] = {"2", "4", "6", "8"};
    score += askQuestion("Q2. HCF of 8 and 12 is?", q2, 2, lifelineUsed);

    string q3[] = {"12", "18", "24", "36"};
    score += askQuestion("Q3. LCM of 6 and 8 is?", q3, 3, lifelineUsed);
}

int main() {
    string name;
    int category, difficulty;
    int score = 0;
    int totalQuestions = 3;
    bool lifelineUsed = false;

    cout << "------------------------------------\n";
    cout << "\t Funny Quiz Game\n";
    cout << "------------------------------------\n";

    if (!loginSystem(name)) {
        return 0;
    }

    showTerms();

    string terms;
    cout << "\nDo you accept Terms & Conditions? (Y/N): ";
    cin >> terms;

    if (!(terms == "Y" || terms == "y" || terms == "Yes" || terms == "yes" || terms == "YES")) {
        cout << "You must accept Terms & Conditions to play.\n";
        return 0;
    }

    cout << "\nChoose Category:\n";
    cout << "1. General Knowledge\n";
    cout << "2. C++ Basics\n";
    cout << "3. Aptitude\n";
    cout << "Enter choice: ";
    cin >> category;

    cout << "\nChoose Difficulty Level:\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "Enter choice: ";
    cin >> difficulty;

    if (difficulty == 1) {
        cout << "\nEasy mode selected. Relax, but not too much.\n";
    } else if (difficulty == 2) {
        cout << "\nMedium mode selected. Now brain cells are required.\n";
    } else if (difficulty == 3) {
        cout << "\nHard mode selected. Best of luck, warrior.\n";
    } else {
        cout << "\nInvalid difficulty. Defaulting to Easy mode.\n";
    }

    cout << "\nQuiz Started. All the best!\n";

    if (category == 1) {
        generalKnowledgeQuiz(score, lifelineUsed);
    } else if (category == 2) {
        cppQuiz(score, lifelineUsed);
    } else if (category == 3) {
        aptitudeQuiz(score, lifelineUsed);
    } else {
        cout << "Invalid category selected.\n";
        return 0;
    }

    showResult(name, score, totalQuestions);
    updateHighScore(score);

    return 0;
}
