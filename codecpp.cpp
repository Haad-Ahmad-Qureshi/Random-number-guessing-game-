#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;
int k = 2;
//hint function 
int hinti(int &attempts,int evenodd,int num) {
	int hint=0;
	while (k != 0){
		if (attempts > 0) {
			cout << "Do you want a hint?enter 0 for no hint,1 for hint = ";
			cin >> hint;
			if (hint == 0) {
				break;
			}
			else if (hint == 1) {
				if (k == 1) {
					if (evenodd % 2 == 0) {
						cout << "\n'The number is even'\n";
					}
					else {
						cout << "\n'The number is odd'\n";
					}
					k -= 1;
					attempts -= 1;
					break;
				}
				else if (k == 2) {
					if (num == 1) {
						if (evenodd >= 100) {
							cout << "[The number lies the upper range of numbers]\n";
						}
						else {
							cout << "[The number lies the lower range of numbers]\n";
						}
					}
					else if (num == 2) {
						if (evenodd >= 50) {
							cout << "[The number lies the upper range of numbers]\n";
						}
						else {
							cout << "[The number lies the lower range of numbers]\n";
						}
					}
					else if (num==3) {
						if (evenodd >= 25) {
							cout << "[The number lies the upper range of numbers]\n";
						}
						else {
							cout << "[The number lies the lower range of numbers]\n";
						}
					}
					attempts -= 1;
					k -= 1;
					break;
				}
			}
			else {
				cout << "PLEASE ENTER A VALID NUMBER FROM 0,1,\n";
			}
		}
		else {
			break;
		}
	}
	return 0;
}

int addhint(int input, int random) {
	if (input > random) {
		cout << "[Your guess is higher than the original number]\n";
	}
	else {
		cout << "[Your guess is lower than the original number]\n";
	}
	return 0;
}
//score
int finalscore(int attempt,int k) {
	int score=0;
	switch (attempt) {
	case 1:
		if (k == 2){
			score = 20;
		}
		else if(k==1){
			score = 15;
		}
		else{
			score = 10;
		}
		break;
	case 2:
		if (k == 2) {
			score = 30;
		}
		else if (k == 1) {
			score = 25;
		}
		else {
			score = 20;
		}
		break;
	case 3:
		if (k == 2) {
			score = 40;
		}
		else if (k == 1) {
			score = 35;
		}
		else {
			score = 30;
		}
		break;
	case 4:
		if (k == 2) {
		score = 50;
	}
		  else if (k == 1) {
		score = 45;
	}
		  else {
		score = 40;
	}
		break;
	case 5:
		if (k == 2) {
			score = 60;
		}
		else if (k == 1) {
			score = 55;
		}
		else {
			score = 50;
		}
		break;
	case 6:
		if (k == 2) {
			score =70;
		}
		else if (k == 1) {
			score = 65;
		}
		else {
			score = 60;
		}
		break;
	case 7:
		if (k == 2) {
			score = 80;
		}
		else if (k == 1) {
			score = 75;
		}
		else {
			score = 70;
		}
		break;
	case 8:
		if (k == 2) {
			score = 90;
		}
		else if (k == 1) {
			score = 85;
		}
		else {
			score = 80;
		}
		break;
	case 9:
		if (k == 2) {
			score = 100;
		}
		else if (k == 1) {
			score = 95;
		}
		else {
			score = 90;
		}
		break;
	case 10:
		if (k == 2) {
			score = 110;
		}
		else if (k == 1) {
			score = 105;
		}
		else {
			score = 100;
		}
		break;
	case 11:
		if (k == 2) {
			score = 120;
		}
		else if (k == 1) {
			score = 115;
		}
		else {
			score = 110;
		}
		break;
	case 12:
		score = 130;
		break;
	default:
		score;
		break;
	}
	return score;
}

int main() {
	string name;
	int num, count;
	count = 1;
	//file handling
	ofstream out;
	out.open("score.txt");
	srand(time(0));
	//start
	int start,t=1;
	for (int x = 0; x < t; x++) {
		cout << "\n\n\n\n\n\t\t\t\t\tWELCOME! TO THE  NUMBER GUESSING GAME.\n\n\n\n";
		cout << "\n\t\t\t\t\tSTART(enter 1)        EXIT(enter 0)\n\t\t\t\t\t";
		cin >> start;
		if (start == 1) {
			system("cls");
			cout << "What is your name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Nice to meet you " << name << "\n\n";
			cout << "This game includes three difficulties\n";
			//check for valid level selection
			for (int i = 0; i < count; i++) {
				cout << "Select 1 for hard,2 for medium,3 for easy \nChoose the difficulty: ";
				cin >> num;
				//Hard level
				if (num == 1) {
					system("cls");
					cout << "\t\t\t\t\tHARD LEVEL\n\n" << "You have 8 attempts to guess the number and maximum score is 90 \n(Each hint decrease the attempts by 1 and score by 5  which is loss of 15 score) \n\n\n";
					int attempts = 8, score = 0, input, evenodd;
					//random number 
					double random = (rand() % 200) + 1;
					evenodd = random;
					cout << "SCORE: " << score << "\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS: " << attempts << "\n\n";
					cout << "Guess the number between 1 to 200\n";
					//Attempts
					for (int i = 1; i <= 8; i++) {
						cout << "\t\t\t\t\t\t---Attempt---" << i << endl;
						cout << "Guess:";
						cin >> input;
						//diference of guess
						int differ;
						differ = input - random;
						if (input <= 200) {
							if (differ < 0) {
								differ = differ * (-1);
							}
							//winning condition
							if (differ == 0) {
								system("cls");
								//score according to attempts
								cout << "Correct! You have guessed the number\n";
								cout << "Score:" << finalscore(attempts,k) << endl;
								out << "Score= " << finalscore(attempts,k);
								break;
							}
							else if (differ >= 40 && differ <= 200) {
								attempts -= 1;
								cout << "(Way off)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							else if (differ >= 20 && differ < 40) {
								attempts -= 1;
								cout << "(Still quite far)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							else if (differ > 10 && differ < 20) {
								attempts -= 1;
								cout << "(You are getting close!)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							else if (differ <= 10) {
								attempts -= 1;
								cout << "(Almost there!)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							//losing condition in easy level
							if (attempts == 0) {
								system("cls");
								cout << "Game over.\n";
								cout << "The number is: " << random << endl;
								cout << "Score:0" << "\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								out << "Score= 0";
							}
						}
						else {
							i--;
							cout << "WARNING:[INVALID INPUT]\n";
						}
					}
				}
				//Medium level
				else if (num == 2) {
					system("cls");
					cout << "\t\t\t\t\tMEDIUM LEVEL\n\n" << "You have 10 attempts to guess the number and maximum score is 110\n(Each hint decrease the attempts by 1 and score by 5 which is loss of 15 score) \n\n\n";
					int attempts = 10, score = 0, input, evenodd;
					//random number 
					double random = (rand() % 100) + 1;
					evenodd = random;
					cout << "Score: " << score << "\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS: " << attempts << "\n\n";
					cout << "Guess the number between 1 to 100\n";
					//Attempts
					for (int i = 1; i <= 10; i++) {
						cout << "\t\t\t\t\t\t---Attempt---" << i << endl;
						cout << "Guess:";
						cin >> input;
						//diference of guess
						int differ;
						differ = input - random;
						if (input <= 100) {
							if (differ < 0) {
								differ = differ * (-1);
							}
							//winning condition
							if (differ == 0) {
								system("cls");
								//score according to attempts
								cout << "Correct! You have guessed the number\n";
								cout << "SCORE:" << finalscore(attempts,k) << endl;
								out << "SCORE= " << finalscore(attempts,k);
								break;
							}
							else if (differ >= 40 && differ <= 100) {
								attempts -= 1;
								cout << "(Way off)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							else if (differ >= 20 && differ < 40) {
								attempts -= 1;
								cout << "(Still quite far)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							else if (differ > 10 && differ < 20) {
								attempts -= 1;
								cout << "(You are getting close!)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							else if (differ <= 10) {
								attempts -= 1;
								cout << "(Almost there!)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							//losing condition in easy level
							if (attempts == 0) {
								system("cls");
								cout << "Game over.\n";
								cout << "The number is: " << random << endl;
								cout << "SCORE:0" << "\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								out << "Score= 0";
							}
						}else {
							i -= 1;
							cout << "WARNING:[INVALID INPUT]\n";
						}
					}
				}
				//Easy level
				else if (num == 3) {
					system("cls");
					cout << "\t\t\t\t\tEASY LEVEL\n\n" << "You have 12 attempts to guess the number and maximum score is 130\n(Each hint decrease the attempts by 1 and score by 5 which is loss of 15 score) \n\n\n";
					int attempts = 12, score = 0, input, evenodd;
					//for hint
					int k = 2;
					//random number 
					double random = (rand() % 50) + 1;
					evenodd = random;
					cout << "SCORE: " << score << "\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << "\n\n";
					cout << "Guess the number between 1 to 50\n";
					//Attempts
					for (int i = 1; i <= 12; i++) {
						cout << "\t\t\t\t\t\t---Attempt---" << i << endl;
						cout << "Guess:";
						cin >> input;
						//diference of guess
						int differ;
						differ = input - random;
						if (input <= 50) {
							if (differ < 0) {
								differ = differ * (-1);
							}
							//winning condition
							if (differ == 0) {
								system("cls");
								//score accoreding to attempts
								cout << "Correct! You have guessed the number\n";
								cout << "Score:" << finalscore(attempts,k) << endl;
								out << "Score= " << finalscore(attempts,k);
								break;
							}
							else if (differ >= 40 && differ <= 50) {
								attempts -= 1;
								cout << "(Way off)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								cout << "Do you want a hint?If yes enter 1.\n";
								//check for higher or lower guess
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							else if (differ >= 20 && differ < 40) {
								attempts -= 1;
								cout << "(Still quite far)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							else if (differ > 10 && differ < 20) {
								attempts -= 1;
								cout << "(You are getting close!)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							else if (differ <= 10) {
								attempts -= 1;
								cout << "(Almost there!)\n";
								cout << "\t\t\t\t\t\t\t\t\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								addhint(input, random);
								//hints
								hinti(attempts, random, num);
							}
							//losing condition in easy level
							if (attempts == 0) {
								system("cls");
								cout << "Game over.\n";
								cout << "The number is: " << random << endl;
								cout << "SCORE:0" << "\t\t\t\tREMAINING ATTEMPTS:" << attempts << endl;
								out << "Score= 0";
							}
						}else{
							i -= 1;
							cout << "WARNING:[INVALID INPUT]\n";
						}
					}
				}
				else {
					system("cls");
					cout << "Please enter a valid number\n";
					count++;
				}
			}
		}
		else if (start == 0) {
			system("cls");
			cout << "YOU EXITED THE GAME\n";
		}
		else {
			system("cls");
			t++;
		}
	}
	system("pause");
}
 