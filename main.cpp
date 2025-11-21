#include <iostream>
#include "Tree.h"
using namespace std;

#include "Node.h"


int main() {
    //File the session is saved to
    string outputFileName = "MR.txt"; //Name of the file the game is saved to
    string inputFileName = "MRGuessingTree.txt"; //Change to whatever file they want to open

    char loadGame;
    cout << "Do you want to load " << inputFileName << "?" << endl;
    cin >> loadGame;
    Tree MRGuessingTree;
    //Playing With Default Tree

    if (loadGame == 'y' || loadGame == 'Y') {
        MRGuessingTree.ReadTreeFromFile(inputFileName);
    }
    else {
        MRGuessingTree.ReadTreeFromFile(inputFileName); //I Don't know why this needs to be here but it does
        Node N;
        string aQorThing;
        aQorThing = N.GetText();
        cout << "The question or thing is: " << aQorThing << endl;
        // Stores default text for the root
         N.StoreText("a duelist?");

         //Storing defualt text for the left and right nodes
         Node *L = new Node("Squirrel_Girl");
         Node *R = new Node("Jeff_The_LandShark");
         N.AppendLeft(L);
         N.AppendRight(R);


         Tree DefaultTree(N.GetText(), N.LChild()->GetText(), N.RChild()->GetText());
         MRGuessingTree = DefaultTree;
    }


    Node *Current;
    Node *Previous;
    char YorN; //Answer to yes or no questions
    char LorR = 'L'; //Indicates whether the previous node is appending left or right



    string NewAnswer; //For input of correct answer
    string NewQuestion; //For input of incorrect answer

    bool ContinueGame = true; //Bool determines when the while loop ends
    char KeepPlaying = 'y';



    Current = MRGuessingTree.GetRoot();
    Previous = MRGuessingTree.GetRoot();
    bool GameOver = false;
    while (!GameOver) {



        if (Current->IsLeaf()) { //Prefacing the user that it is going to the guess the character
            cout << "----------------------------" << endl;
            cout << "I am going to Guess the Character" << endl;
        }
        cout << "Are They " <<Current->GetText() << "?" << endl;
        cout << "Y/N  ";
        cin >> YorN;
        if (!Current->IsLeaf() && YorN == 'y' || YorN == 'Y') {
            Previous = Current;
            Current = Current->LChild();
            LorR = 'L';


        } //if
        else if (!Current->IsLeaf() && YorN == 'n' || YorN == 'N') {
            Previous = Current;
            Current = Current->RChild();
            LorR = 'R';
        } //else if

        else if (YorN == 'n' || YorN == 'N') {
                cout << "Enter correct answer:  ";
                cin >> NewAnswer;
                cout << "Enter new question:  ";
                cin >> NewQuestion;
                Node *Answer = new Node(NewAnswer);
                Node *Question = new Node(NewQuestion);
            if (LorR == 'L'){

                Current -> InsertNodeLeft(Answer, Question, Previous);

            }//if
            else {
                Current -> InsertNodeRight(Answer, Question, Previous);

            }
            cout << "Do You want to play Again Y/N" << endl;
            cin >> KeepPlaying;
            if (KeepPlaying == 'n' || KeepPlaying == 'N') {
                ContinueGame = false;
            }
            else {
                Current = MRGuessingTree.GetRoot();
                Previous = MRGuessingTree.GetRoot();

            }
        }//else if
        else {
            cout << "The correct answer was " << Current -> GetText() << endl;
            cout << "Do You want to play Again Y/N: " << endl;
            cin >> KeepPlaying;
            if (KeepPlaying == 'n' || KeepPlaying == 'N') {
                ContinueGame = false;
            }
            else {
                Current = MRGuessingTree.GetRoot();
                Previous = MRGuessingTree.GetRoot();

            }
        }
        if (!ContinueGame) {
            GameOver = true;
            //Asks the user if they want to save their current game
            cout << "Save this Game to " << outputFileName << " y/n ";
            char SaveGame;
            cin >> SaveGame;
            if (SaveGame == 'y' || SaveGame == 'Y') {
                MRGuessingTree.SaveTreeToFile(outputFileName);
            }
        }






    }//While (!correct)




     // after you write AppendLeft(), AppendRight(), LChild(), and RChild() methods,
     // you can then:  cout Node objects (see the friend overloaded operator<<() method)




    cout << "Done." << endl;
    return 0;
}