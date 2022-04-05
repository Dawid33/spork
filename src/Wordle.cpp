//
// Created by dawids on 30/03/2022.
//

#include <QTextEdit>
#include <string>
#include <iostream>
#include <fstream>
#include <QDebug>
#include <stdlib.h>
#include "Wordle.hpp"

Wordle::Wordle() {
    //Get words.txt from file
    std::ifstream words;
    words.open("resources/words.txt");
    int line_count = std::count(std::istreambuf_iterator<char>(words),std::istreambuf_iterator<char>(), '\n');
    long line = rand() % line_count;
    words.close();

    words.open("resources/words.txt");
    std::string word;
    for(int i = 0; i < line; i++) {
        std::getline(words, word);
    }
    word_to_solve = word;
    words.close();
    qDebug() << QString::fromStdString(word_to_solve);

    for(char c : word_to_solve) {
        word_state.emplace_back(LetterState());
    }
}

bool Wordle::guess(const QString &value) {
    guesses.push_back(value);
    guess_correctness.emplace_back(value.length());
    // Assumes value is the same length as word_to_guess.
    for(int i = 0; i < value.length(); i++) {
        if (value[i] == word_to_solve[i]) {
            word_state[i].correct = true;
            letters[(int)word_to_solve[i] - 97].correct = true;
            guess_correctness.at(guess_correctness.size() - 1).at(i).correct = true;
        } else {
            for(char c : word_to_solve) {
                if (c == value[i]) {
                    word_state[i].in_word_but_wrong_spot = true;
                    letters[c - 97].in_word_but_wrong_spot = true;
                    guess_correctness.at(guess_correctness.size() - 1).at(i).in_word_but_wrong_spot = true;
                }
            }
            if(!word_state[i].in_word_but_wrong_spot) {
                word_state[i].wrong = true;
                letters[value[i].toLatin1() - 97].wrong = true;
                guess_correctness.at(guess_correctness.size() - 1).at(i).wrong = true;
            }
        }
    }

    bool is_correct = true;
    for(int i = 0; i < value.length(); i++) {
        if (!guess_correctness.at(guess_correctness.size() - 1).at(i).correct) {
            is_correct = false;
            break;
        }
    }
    return is_correct;
}

void Wordle::print(QTextEdit *editor) {
    QString output;
    QTextCursor cursor(editor->textCursor());
    QTextCharFormat format;


    for(int i = 0; i < 25; i++) {
        if(letters[i].correct) {
            format.setForeground(QBrush( QColor( "green")));
        } else if (letters[i].in_word_but_wrong_spot) {
            format.setForeground(QBrush( QColor( "yellow")));
        } else if (letters[i].wrong){
            format.setForeground(QBrush( QColor( "black")));
        } else {
            format.setForeground(QBrush( QColor( "white")));
        }

        cursor.setCharFormat(format);
        cursor.insertText(QString((char)(97+i)) + " ");
    }
    cursor.insertText("\n\n");

    format.setFontWeight(QFont::DemiBold);
    format.setForeground(QBrush( QColor( "white")));
    output += "Guesses thus far : " + QString::number(guesses.size()) + "\n";
    cursor.setCharFormat(format);
    cursor.insertText(output);

    for(int i = 0; i < guesses.size(); i++) {
        for(int j = 0; j < guesses[i].length(); j++) {
            if(guess_correctness[i][j].correct) {
                format.setForeground(QBrush( QColor( "green")));
            } else if (guess_correctness[i][j].in_word_but_wrong_spot) {
                format.setForeground(QBrush( QColor( "yellow")));
            } else if (guess_correctness[i][j].wrong){
                format.setForeground(QBrush( QColor( "black")));
            } else {
                format.setForeground(QBrush( QColor( "white")));
            }

            cursor.setCharFormat(format);
            cursor.insertText(guesses[i].at(j));
        }
        cursor.insertText("\n");
    }
}

std::ostream& operator<<(std::ostream &os, const Wordle &w) {
    QString output;

    for(int i = 0; i < 25; i++) {
        output += QString((char)(97+i)) + " ";
    }
    output += "\n\n";

    output += "Guesses thus far : " + QString::number(w.guesses.size()) + "\n";

    for(int i = 0; i < w.guesses.size(); i++) {
        for(int j = 0; j < w.guesses[i].length(); j++) {
            output += w.guesses[i].at(j);
        }
    }
    os << output.toStdString();
    return os;
}
