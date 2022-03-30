//
// Created by dawids on 30/03/2022.
//

#include <QTextEdit>
#include <string>
#include <QDebug>
#include "Wordle.hpp"

Wordle::Wordle() {
    //Get words from file
    word_to_solve = "abcde";
    for(char c : word_to_solve) {
        word_state.emplace_back(LetterState());
    }
}

void Wordle::guess(const QString &value) {
    guesses.push_back(value);
    // Assumes value is the same length as word_to_guess.
    for(int i = 0; i < value.length(); i++) {
        if (value[i] == word_to_solve[i]) {
            word_state[i].correct = true;
            letters[(int)word_to_solve[i] - 97].correct = true;
        } else {
            for(char c : word_to_solve) {
                if (c == value[i]) {
                    word_state[i].in_word_but_wrong_spot = true;
                    letters[c - 97].in_word_but_wrong_spot = true;
                }
            }
            if(!word_state[i].in_word_but_wrong_spot) {
                word_state[i].wrong = true;
                letters[value[i].toLatin1() - 97].wrong = true;
            }
        }
    }
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
    std::reverse(guesses.begin(), guesses.end());
    for(QString guess : guesses) {
        output += guess + "\n";
    }

    cursor.setCharFormat(format);
    cursor.insertText(output);
}
