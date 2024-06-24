#include "numbersGame.h"
#include "./ui_numbersGame.h"
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

NumbersGame::NumbersGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NumbersGame)
{
    ui->setupUi(this);

    // use randomNumGenerator() to generate a 4 digit number, each digit a random value of 0-9
    numberVec = randomNumGenerator();
    for (int num : numberVec){
        std::cout << num << std::endl;
    }


    // Connect the submit button's clicked signal to a slot that processes that guess
    connect(ui->submitButton, &QPushButton::clicked, this, &NumbersGame::processGuess);
}

// Generate a random 4 digit number with values 0-9 and store each value in a vector<int>

std::vector<int> NumbersGame::randomNumGenerator()
{
    std::vector<int> v;

    for (int i = 0; i < 4; i++){
        bool isSame = false;
        srand(time(0) + i);
        int randomNum = rand() % 10;
        for (int j = 0; j < i; j++){
            if (randomNum == v[j]){
                isSame = true;
                break;
            }
        }
        if (isSame){
            i--;
        } else {
            v.push_back(randomNum);
        }
    }

    return v;
}

void NumbersGame::processGuess()
{
    ui->listBullsCows->clear();

    QString guessText = ui->guessLine->text();
    std::string guessString = guessText.toStdString();

    std::vector<int> guessVec;
    int len = guessString.length();

    for (int i = 0; i < len; i++){
        int end = 1;
        std::string ss = guessString.substr(i, end);
        int num = stoi(ss);
        guessVec.push_back(num);
    }

    for (int guess : guessVec )
    {
        std::cout << "Guess Vec: " << guess << std::endl;
    }

    int cows = 0;
    int bulls = 0;

    for (int i = 0; i < guessVec.size(); i++ )
    {
        // Check if each guess integer matches the number at the same position in the vector
        if (guessVec[i] == numberVec[i])
        {
            // If match is found, incrememt bulls by 1
            bulls++;
        }
        // Check if each guess integer is found somewhere in the number vector, but not at the same position
        for (int j = 0; j < numberVec.size(); j++ )
        {
            if (guessVec[i] == numberVec[j] && i != j )
            {
                // If the same number is found but in a different position in the vector, increment cows by 1
                cows++;
            }
        }
    }

    std::cout << "Bulls: " << bulls << std::endl;
    std::cout << "Cows: " << cows << std::endl;

    QString itemText = QString("Bulls: %1\nCows: %2").arg(bulls).arg(cows);
    ui->listBullsCows->addItem(itemText);

    bool ok;
    int guess = guessText.toInt(&ok);

    if(ok){
        ui->wrongGuesses->addItem(guessText);
    } else {
        ui->guessLine->clear();
    }

    ui->guessLine->clear();

}

NumbersGame::~NumbersGame()
{
    delete ui;
}
