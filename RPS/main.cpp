
#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>


using namespace std;

class gameStruct
{
    private:
        int gameChances; //Number of chances for each round of game.
        int winPoint;
        int drawPoint;

    public: //Public data members.
        string userName;
        int gamePoints;

    public: //Public function members.
        explicit gameStruct(int gc, int gp): gameChances(gc), gamePoints (gp)
        {
            winPoint = 3;drawPoint = 1;
        }
        void gameFunct ();
        void gamePlay();

};

int randomNum ()
    {
        int R;
        srand ((unsigned) time (NULL));
        R = ((rand() % 3) + 1);
        return R;
    }

    const char* rockPaperSci(int a)
    {
        if (a == 1)
        {
            return "Rock";
        } else if (a == 2)
        {
            return "Paper";
        } else if (a == 3)
        {
            return "Scissors";
        }

    }


    void readGameFile ()
{
  string rules_of_the_game;
  ifstream gameFile ( "gameRules.txt", ios::in);

  if (gameFile.is_open())
  {
    while (getline(gameFile, rules_of_the_game ))
    {
      cout << "\n" << rules_of_the_game;
    }
    gameFile.close();

  }
  else
  {
    cout << "error occured whiles trying to get game files" << endl;
  }
}

    void gameStruct :: gamePlay ()
{
     cout << "Enter your username with no spaces:";
    cin >> userName;
    char opt;
    cout << "Are you ready to play the game? (y / n)\n";
    cin >> opt;

        if (opt == 'y' || opt == 'Y' )
    {
           cout << "Let's start!!!" <<endl;

    } else if (opt == 'n' || opt == 'N')
    {
        cout << "Hope you come try the game later. Thank you." << endl;
    }

    else if ((opt != 'y' || opt != 'Y') || (opt != 'n' || opt != 'N'))
    {
        cout << "You can only enter 'y' for yes, and  'n' for no." << endl;
        cin >> opt;
        if (opt == 'n' || opt == 'N')
    {
        cout << "Hope you come try the game later. Thank you." << endl;
    }
    }

    while (opt == 'y' || opt == 'Y')
    {
        gameFunct();
        cout << "I hope you enjoyed the game. Would you like to play again?"<< endl;
        cin >> opt;
      if (opt == 'y' || opt == 'Y' )
    {
           cout << "Yeeah!!! Let's go!!!" <<endl;
           gameChances = 7;
           gamePoints = 0;

    } else if (opt == 'n' || opt == 'N')
    {
        cout << "Thank you. See you again sometime." << endl;
    } else
    {
        cout << "You can only enter 'y' for yes, and  'n' for no." << endl;
        cin >> opt;
         if (opt == 'y' || opt == 'Y' )
    {
           cout << "Yeeah!!! Let's go!!!" <<endl;
           gameChances = 7;
           gamePoints = 0;

    } else if (opt == 'n' || opt == 'N')
    {
        cout << "Thank you. See you again sometime. BYEEE!!!" << endl;
    }
    }
    }



}



void gameStruct :: gameFunct ()
{
    int rps;
    int computer;
    while (gameChances > 0)
   {

    cout << "Rock(1)  PAPER(2)  SCISSORS (3) " << endl;
     computer = randomNum();
    cout << "enter number: "; cin >> rps;

    while (cin.fail())
       {
           cin.clear();
           cin.ignore(100,'\n');
           cout <<"Please enter a number only." << endl;
           cin >> rps;

       }

       while (rps < 1 || rps > 3)
       {
           cout << rps << " is out of number range. Enter 1 - 3" << endl;
           cin >> rps;
           while (cin.fail())
       {
           cin.clear();
           cin.ignore(100,'\n');
           cout <<"Please enter a number only." << endl;
           cin >> rps;

       }
       }


    if (rps == 1 && computer == 1)
           {
               cout << "You are " << rockPaperSci(rps);
               cout << " and computer is " << rockPaperSci(computer) << "\n";
               cout << "Its a tigh"<< "\n\n\n";
               gamePoints += drawPoint;

           }

            else if ((rps == 1 && computer == 2) ||  (rps == 2 && computer == 1))
           {
               cout << "You are " << rockPaperSci(rps);
               cout << " and computer is " << rockPaperSci(computer) << "\n";
               cout << "Paper Wins" << "\n\n\n";
               if (rps == 2)
               {
                   gamePoints += winPoint;
               }

           }

            else if ((rps == 1 && computer == 3) || (rps == 3 && computer == 1) )
           {
                cout << "You are " << rockPaperSci(rps);
               cout << " and computer is " << rockPaperSci(computer) << "\n";
               cout << "Rock Wins" << "\n\n\n";

               if (rps == 1)
               {
                   gamePoints += winPoint;
                   ++gameChances;

                }
               else if (rps == 3 )
               {
                   --gameChances  ;
               }

            }

            else if (rps == 2 && computer == 2)
           {
                cout << "You are " << rockPaperSci(rps);
               cout << " and computer is " << rockPaperSci(computer) << "\n";
               cout << "Its a tigh"<< "\n\n\n";
               gamePoints += winPoint;

           }

            else if ((rps == 2 && computer == 3) || ( rps == 3 && computer == 2))
           {
                cout << "You are " << rockPaperSci(rps);
               cout << " and computer is " << rockPaperSci(computer) << "\n";
               cout << "Scissors wins"<< "\n\n\n";

               if (rps == 3)
               {
                   gamePoints += winPoint;
               }

           }

            else if (rps == 3 && computer == 3)
           {
               cout << "You are " << rockPaperSci(rps);
               cout << " and computer is " << rockPaperSci(computer) << "\n";
               cout << "Its a tigh"<< "\n\n\n";
               gamePoints +=drawPoint;

           }
--gameChances;
}
 /////Game point needs construction
 int bufferScore; //temporary storage for score from file.


 fstream score_file ("Score_file.bin", ios :: in | ios :: out | ios::binary |ios::ate);
 if (score_file.is_open()) {
    if (score_file.tellg() != 0)
 {
     score_file.seekg(0);
     score_file.read (reinterpret_cast<char *>(&bufferScore), sizeof(bufferScore));
     if (gamePoints > bufferScore)
     {
         cout << "NEW HIGH SCORE: " << gamePoints << endl;
         score_file.seekp(0);
         score_file.write (reinterpret_cast<char *>(&gamePoints), sizeof(gamePoints));
     }
     else
     {
        cout << "GAME SCORE: " << gamePoints << endl;
        cout << "HIGH SCORE: " << bufferScore << endl;
     }
 }
else
 {
     cout << "NEW HIGH SCORE: " << gamePoints << endl;
     score_file.seekp(0);
      score_file.write (reinterpret_cast<char *>(&gamePoints), sizeof(gamePoints));
 }

}
 score_file.close();



}



int main()
{

 gameStruct game(7, 0);

 readGameFile();
 game.gamePlay ();

    return 0;
}
