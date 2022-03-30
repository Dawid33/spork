//
// Created by dawids on 30/03/2022.
//

#ifndef SPORK_WORDLE_H
#define SPORK_WORDLE_H


#include <QString>
#include <vector>

class LetterState {
public:
    LetterState() {
        correct = false;
        in_word_but_wrong_spot = false;
        wrong = false;
    }
    bool correct;
    bool in_word_but_wrong_spot;
    bool wrong;
};

class Wordle {
public:
    Wordle();
    void guess(const QString &);
    void print(QTextEdit* editor);
private:
    std::string word_to_solve;
    std::vector<LetterState> word_state;

    LetterState letters[25];
    std::vector<QString> guesses;
    std::vector<std::vector<LetterState>> guess_correctness;
};




#endif //SPORK_WORDLE_H
