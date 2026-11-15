/*
 * Game-Arena - A Multi-Game Console Application
 * Copyright (C) 2026 RAHUL MANNA
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Author: Rahul Manna
 * Date: 2026
 * Description: A console-based multi-game application featuring
 *              1. Rock Paper Scissors     5. Tic-Tac-Toe (unbeatable AI)
 *              2. Number Guessing         6. Snake (real-time)
 *              3. Math Challenge          7. Memory Master
 *              4. Hangman                 8. Blackjack
 *
 * This file is written in C89 style, so it compiles in old Dev-C++ too.
 *
 *-------------------HAPPY GAMING-------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

// global data
static const char ch[] = {'+', '-', '*', '/', '%'};

// helper functions
static void enableANSI(void) {
    HANDLE h;
    DWORD mode = 0;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleMode(h, &mode))
        SetConsoleMode(h, mode | 0x0004);   // turn on ANSI colors
}

static void clr(void) { system("cls"); }

static void readLine(char *buf, int n) {
    if (!fgets(buf, n, stdin)) exit(0);
    buf[strcspn(buf, "\r\n")] = '\0';
}

// read an int, keep asking until the input is valid
static int readInt(const char *prompt) {
    char buf[64];
    char *end;
    long v;
    while (1) {
        if (prompt) printf("%s", prompt);
        if (!fgets(buf, sizeof buf, stdin)) exit(0);
        v = strtol(buf, &end, 10);
        if (end == buf) { printf("\033[91mPlease enter a number.\033[0m\n"); continue; }
        while (*end == ' ' || *end == '\t') end++;
        if (*end != '\n' && *end != '\0') { printf("\033[91mPlease enter a number.\033[0m\n"); continue; }
        return (int)v;
    }
}

static void flushKeys(void) { while (_kbhit()) _getch(); }

static void banner(const char *title) {
    int w = 38, len, l, r;
    len = (int)strlen(title);
    l = (w - len) / 2;
    r = w - len - l;
    printf("\n\033[1;96m+--------------------------------------+\n");
    printf("|%*s%s%*s|\n", l, "", title, r, "");
    printf("+--------------------------------------+\033[0m\n");
}

static void blinkterminate(int dsa) {
    for (dsa = 0; dsa <= 2; dsa++) {
        printf("\033[0;91mTerminating the game!!!\033[0m\r");
        fflush(stdout);
        Sleep(300);
        printf("                       \r");
        fflush(stdout);
        Sleep(300);
    }
}

static void quitGame(void) {
    blinkterminate(0);
    exit(0);
}

static void blinkalert(int dsa, int j) {
    for (dsa = 1; dsa <= j; dsa++) {
        printf("\033[0;91mAlert!! Equation will vanish after %d seconds\033[0m\r", j - dsa + 1);
        fflush(stdout);
        Sleep(1000);
        printf("                                                                        \r");
        fflush(stdout);
    }
}

static void pressEnter(void) {
    char tmp[8];
    printf("\n\033[90mPress ENTER to continue...\033[0m");
    readLine(tmp, sizeof tmp);
}

// math result printers
static void result(int win, int loss, float x) {
    float percent = 0.0f;

    if (win == 0 && loss == 0) {
        printf("\n\033[100;93mNo Game Played \033[0m\n");
        return;
    }
    printf("\033[1;93m\nYOUR RESULT\033[0m");
    printf("\ntotal game: %d   win: %d  loss: %d", win + loss, win, loss);
    percent = (100.0f * win) / (win + loss);
    printf("\npercentage of win: %.3f%%", percent);
    printf("\naverage time: %.3f seconds\n", x / (win + loss));

    if (percent <= 10.0f)
        printf("\033[91mYou are noob bro, go to study\033[0m\n");
    else if (percent <= 30.0f)
        printf("\033[91mNot so good. Need more practice\033[0m\n");
    else if (percent <= 60.0f)
        printf("\033[91mYou are a good player but need some extra practice\033[0m\n");
    else if (percent <= 80.0f)
        printf("\033[91mYou are a pro player at this level\033[0m\n");
    else
        printf("\033[91mKudos sir, GM\033[0m\n");
}

static void result2(int win, int loss, int sec) {
    printf("\033[94m%d sec finished!!!\n\033[0m", sec);
    printf("\ntotal game: %d   win: %d  loss: %d\n", win + loss, win, loss);
}

// GAME 1 : Rock Paper Scissors
static void rpsGame(void) {
    int e = 0, f = 0, g = 0;
    int choice, n, r, rem;
    float d;

    printf("\nLET'S PLAY ROCK PAPER SCISSORS!!\n");

    while (1) {
        printf("\033[1;32m\n1. Play\033[0m ");
        printf("\033[1;34m2. Result\033[0m ");
        printf("\033[1;35m3. Main Menu\033[0m ");
        printf("\033[1;31m4. EXIT\033[0m\n");
        choice = readInt("\nEnter your choice: ");

        if (choice == 1) {
            n = 0;
            while (n < 1 || n > 3) {
                printf("\nTake your choice:\n");
                printf("\033[1;93m1. ROCK\033[0m  ");
                printf("\033[1;35m2. PAPER\033[0m  ");
                printf("\033[1;31m3. SCISSORS\033[0m\n");
                n = readInt("Enter your choice: ");
                if (n == 1)      printf("\033[93m\nYour choice is ROCK\033[0m\n");
                else if (n == 2) printf("\033[94m\nYour choice is PAPER\033[0m\n");
                else if (n == 3) printf("\033[92m\nYour choice is SCISSORS\033[0m\n");
                else             printf("\033[1;31mInvalid input! Choose 1-3\033[0m\n");
            }
            r = (rand() % 3) + 1;
            printf("\033[38;5;178mComputer's choice: \033[0m");
            printf("%s\n", r == 1 ? "ROCK" : r == 2 ? "PAPER" : "SCISSORS");

            rem = (n - r + 3) % 3;
            if (rem == 0)      { printf("\033[1;36mDraw match!!\033[0m\n"); g++; }
            else if (rem == 1) { printf("\033[1;32mCongratulations!! You win\033[0m\n"); e++; }
            else               { printf("\033[1;31mBetter luck next time\033[0m\n"); f++; }
        }
        else if (choice == 2) {
            printf("\033[93m\nYOUR RESULT\033[0m\n");
            if (e + f + g == 0) {
                printf("\033[91mNo game played\033[0m\nPlay at least one game\n");
            } else {
                d = (e * 100.0f) / (e + f + g);
                printf("\033[95mTotal games: %d\033[0m\n", e + f + g);
                printf("Win: %d   Loss: %d   Draw: %d\n", e, f, g);
                printf("Win probability: %.3f%%\n", d);
                if (e > f)                  printf("\033[1;32mYou are winning!\033[0m\n");
                else if (f > e)             printf("\033[93mComputer is winning!\033[0m\n");
                else if (e == f && e != 0)  printf("\033[1;31mBoth are winners!\033[0m\n");
            }
        }
        else if (choice == 3) { printf("\033[1;31m\nMAIN MENU\033[0m\n"); return; }
        else if (choice == 4) quitGame();
        else printf("\033[1;33mInvalid input\033[0m\n");
    }
}

// GAME 2 : Number Guessing
static void guessGame(void) {
    int e = 0, f = 0;
    int choice, n, r;
    float d;

    printf("\nYOU CHOOSE: NUMBER GUESSING GAME\n");

    while (1) {
        printf("\033[1;32m\n1. Play\033[0m ");
        printf("\033[1;34m2. Result\033[0m ");
        printf("\033[1;35m3. Main Menu\033[0m ");
        printf("\033[1;31m4. EXIT\033[0m\n");
        choice = readInt("\nEnter your choice: ");

        if (choice == 1) {
            n = readInt("\033[1;36m\nGuess your number (1-5): \033[0m");
            printf("\033[93mYour guess: %d\033[0m\n", n);
            r = 1 + rand() % 5;
            printf("\033[35mComputer's number: %d\033[0m\n", r);
            if (n == r) { printf("\033[1;32mCongratulations! You won!\033[0m\n"); e++; }
            else        { printf("\033[1;31mBetter luck next time!\033[0m\n"); f++; }
        }
        else if (choice == 2) {
            printf("\033[1;31m\nRESULT\033[0m\n");
            if (e + f == 0) {
                printf("\033[36mNo game played\033[0m\nPlay at least one game\n");
            } else {
                d = (e * 100.0f) / (e + f);
                printf("\033[93mTotal games: %d\033[0m\n", e + f);
                printf("Win: %d\nLoss: %d\n", e, f);
                printf("Win probability: %.3f%%\n", d);
                if (e > f)       printf("\033[1;32mYou are winning!\033[0m\n");
                else if (e == f) printf("\033[93mBoth are winners!\033[0m\n");
                else             printf("\033[91mComputer is winning!\033[0m\n");
            }
        }
        else if (choice == 3) { printf("\033[1;31m\nMAIN MENU\033[0m\n"); return; }
        else if (choice == 4) quitGame();
        else printf("\033[1;31mInvalid input\033[0m\n");
    }
}

// GAME 3 : Math Challenge
typedef struct {
    const char *name;
    const char *color;
    const char *rule;
    int lo, span;      // operand = lo + rand() % span
    int nops;          // how many operators from ch[] are used
    int operands;      // 2 or 3
    int mode;          // 0 visible, 1 vanish, 2 timed reveal
    int limit;         // seconds, 0 = no limit
} Level;

static const Level LV[6] = {
    {"NOOB",         "\033[91m", "2 operands (1-10) | 2 operators (+,-) | No time limit",                  1, 10, 2, 2, 0, 0},
    {"BEGINNER",     "\033[91m", "2 operands (5-15) | 4 operators (+,-,*,/) | No time limit",              5, 11, 4, 2, 0, 0},
    {"INTERMEDIATE", "\033[91m", "2 operands (10-20) | 5 operators (+,-,*,/,%) | No time limit",           10, 11, 5, 2, 0, 0},
    {"ADVANCE",      "\033[91m", "2 operands (10-30) | 5 operators | Equation vanishes after 3 sec",       10, 21, 5, 2, 1, 0},
    {"PRO",          "\033[93m", "2 operands (10-30) | Equation revealed slowly | Answer within 5 sec",    10, 21, 5, 2, 2, 5},
    {"GRAND MASTER", "\033[91m", "3 operands (10-30) | 5 operators | Answer within 5 sec",                10, 21, 5, 3, 2, 5}
};

static int applyOp(int a, char op, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;     // operands are never 0
        default:  return a % b;
    }
}

static void playMath(int idx) {
    const Level *L = &LV[idx];
    int win = 0, loss = 0;
    float total = 0.0f, diff;
    int c, a, b, k, answer, given, inTime;
    char o1, o2;
    char eq[80];
    DWORD t0;

    printf("\n%sYour level: %s\033[0m\n", L->color, L->name);
    printf("\033[93mGAME RULE:\033[0m\n%s\n", L->rule);

    while (1) {
        printf("\n\033[0;32m1. Start\033[0m ");
        printf("\033[0;33m2. Result\033[0m ");
        printf("\033[0;34m3. Previous Menu\033[0m ");
        printf("\033[0;31m4. Exit\033[0m\n");
        c = readInt("Enter your choice: ");

        if (c == 1) {
            a = L->lo + rand() % L->span;
            b = L->lo + rand() % L->span;
            k = L->lo + rand() % L->span;
            o1 = ch[rand() % L->nops];
            o2 = ch[rand() % L->nops];

            if (L->operands == 2) {
                answer = applyOp(a, o1, b);
                sprintf(eq, "%d %c %d", a, o1, b);
            } else {
                answer = applyOp(applyOp(a, o1, b), o2, k);
                sprintf(eq, "( %d %c %d ) %c %d", a, o1, b, o2, k);
            }

            if (L->mode == 0) {
                printf("\033[93m%s\033[0m\n", eq);
            } else if (L->mode == 1) {
                printf("\033[93m%s\033[0m\n", eq);
                blinkalert(0, 3);
                clr();
            } else {
                printf("\033[93m");
                if (L->operands == 3) { Sleep(1000); printf("( "); }
                Sleep(1000); printf("%d ", a);
                Sleep(1000); printf("%c ", o1);
                if (L->operands == 3) {
                    Sleep(1000); printf("%d ) ", b);
                    Sleep(1000); printf("%c ", o2);
                    Sleep(1000); printf("%d", k);
                } else {
                    Sleep(1000); printf("%d", b);
                }
                printf("\033[0m\n");
                blinkalert(0, 3);
                clr();
            }

            t0 = GetTickCount();
            given = readInt("\nEnter your answer: ");
            diff = (GetTickCount() - t0) / 1000.0f;
            total += diff;

            if (L->mode > 0)
                printf("\033[1;93mThe equation was: \033[96m%s\033[0m\n", eq);

            inTime = (L->limit == 0) || (diff <= (float)L->limit);
            if (given == answer && inTime) {
                printf("\033[32m\nWow! You are right!\033[0m");
                printf("\033[93m\nYou took %.3f seconds\033[0m\n", diff);
                win++;
            } else if (given == answer) {
                printf("\033[92m\nSorry! You are right but out of time!\033[0m");
                printf("\033[93m\nYou took %.3f seconds\033[0m\n", diff);
                loss++;
            } else {
                printf("\n\033[93mSorry!\033[0m\n\033[91mRight answer is %d\033[0m\n", answer);
                loss++;
            }
        }
        else if (c == 2) result(win, loss, total);
        else if (c == 3) { printf("\n\033[1;36mPREVIOUS MENU\033[0m\n"); return; }
        else if (c == 4) quitGame();
        else printf("Invalid input\n");
    }
}

static void timeChallenge(void) {
    int c, sec, win, loss, q, a, b, given, answer;
    char op;
    DWORD t0, limitMs;

    printf("\nTIME CHALLENGE\n");
    printf("\033[96mGAME RULE:\033[0m\n");
    printf("2 operands (1-15) | User defined time limit\n");

    while (1) {
        printf("\n\033[0;32m1. Start\033[0m ");
        printf("\033[0;33m2. Previous Menu\033[0m ");
        printf("\033[0;31m3. Exit\033[0m\n");
        c = readInt("Enter your choice: ");

        if (c == 1) {
            sec = readInt("Enter time limit (seconds): ");
            if (sec <= 0) { printf("\033[91mTime must be at least 1 second.\033[0m\n"); continue; }
            printf("\033[34mTime limit: %d seconds\033[0m\n", sec);
            printf("\nLet's start!\n");

            win = 0; loss = 0; q = 1;
            t0 = GetTickCount();
            limitMs = (DWORD)sec * 1000;

            while (GetTickCount() - t0 < limitMs) {
                a = 1 + rand() % 15;
                b = 1 + rand() % 15;
                op = ch[rand() % 5];
                answer = applyOp(a, op, b);

                printf("Question %d: \033[93m%d %c %d\033[0m\n", q, a, op, b);
                given = readInt("Enter your answer: ");

                if (GetTickCount() - t0 >= limitMs) {
                    printf("\033[91mToo late - that answer is not counted.\033[0m\n");
                    break;
                }
                if (given == answer) { printf("\033[32mCorrect!\033[0m\n"); win++; }
                else { printf("\033[31mWrong! Answer was %d\033[0m\n", answer); loss++; }
                q++;
            }
            printf("\nTIME UP!!\n");
            result2(win, loss, sec);
        }
        else if (c == 2) { printf("\n\033[1;36mPREVIOUS MENU\033[0m\n"); return; }
        else if (c == 3) quitGame();
        else printf("Invalid input\n");
    }
}

static void mathChallenge(void) {
    int c;
    while (1) {
        printf("\n\033[0;31m1. Noob\033[0m ");
        printf("\033[0;33m2. Beginner\033[0m ");
        printf("\033[0;32m3. Intermediate\033[0m ");
        printf("\033[0;34m4. Advance\033[0m ");
        printf("\033[0;36m5. Pro\033[0m ");
        printf("\033[0;35m6. Grand Master\033[0m ");
        printf("\033[1;33m7. Time Challenge\033[0m ");
        printf("\033[1;91m8. Main Menu\033[0m ");
        printf("\033[0;37m9. Exit\033[0m\n");
        c = readInt("\nEnter your level: ");

        if (c >= 1 && c <= 6) playMath(c - 1);
        else if (c == 7) timeChallenge();
        else if (c == 8) { printf("\n\033[1;36mMAIN MENU\033[0m\n"); return; }
        else if (c == 9) quitGame();
        else printf("\033[1;33mInvalid input! Choose 1-9\033[0m\n");
    }
}

// GAME 4 : Hangman
static const char *HANG[7] = {
    "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
};

static const char *CAT_NAME[4] = {"ANIMALS", "COUNTRIES", "TECH", "FOOD"};
static const char *WORDS[4][6] = {
    {"ELEPHANT", "GIRAFFE", "PENGUIN", "DOLPHIN", "KANGAROO", "CHEETAH"},
    {"INDIA", "BRAZIL", "CANADA", "JAPAN", "EGYPT", "GERMANY"},
    {"COMPILER", "POINTER", "KEYBOARD", "ALGORITHM", "NETWORK", "VARIABLE"},
    {"BIRYANI", "SANDESH", "PIZZA", "CHOCOLATE", "NOODLES", "SAMOSA"}
};

static void hangmanGame(void) {
    int wins = 0, losses = 0;
    int c, cat, len, i, pick, nc, missing;
    int used[26], cand[26];
    int wrong, hints, solved;
    const char *word;
    char msg[100], buf[64], g;

    while (1) {
        banner("HANGMAN");
        printf("\033[1;32m1. Animals\033[0m  \033[1;34m2. Countries\033[0m  \033[1;35m3. Tech\033[0m  \033[1;33m4. Food\033[0m\n");
        printf("\033[1;96m5. Surprise me\033[0m  \033[1;91m6. Main Menu\033[0m\n");
        c = readInt("\nPick a category: ");
        if (c == 6) { printf("\033[1;31m\nMAIN MENU\033[0m\n"); return; }
        if (c < 1 || c > 5) { printf("\033[1;33mInvalid input\033[0m\n"); continue; }

        cat = (c == 5) ? rand() % 4 : c - 1;
        word = WORDS[cat][rand() % 6];
        len = (int)strlen(word);
        memset(used, 0, sizeof used);
        wrong = 0; hints = 1; solved = 0;
        msg[0] = '\0';

        while (wrong < 6) {
            missing = 0;
            clr();
            banner("HANGMAN");
            printf("\033[93mCategory: %s\033[0m   \033[91mLives: %d\033[0m   \033[96mHints: %d\033[0m\n\n",
                   CAT_NAME[cat], 6 - wrong, hints);
            printf("\033[1;97m%s\033[0m\n\n  ", HANG[wrong]);
            for (i = 0; i < len; i++) {
                if (used[word[i] - 'A']) printf("\033[1;92m%c \033[0m", word[i]);
                else { printf("_ "); missing++; }
            }
            printf("\n\n\033[90mUsed: \033[0m");
            for (i = 0; i < 26; i++)
                if (used[i]) printf("%s%c \033[0m", strchr(word, 'A' + i) ? "\033[92m" : "\033[91m", 'A' + i);
            printf("\n");
            if (msg[0]) printf("\n%s\033[0m\n", msg);
            msg[0] = '\0';

            if (missing == 0) { solved = 1; break; }

            printf("\nGuess a letter (? = hint): ");
            readLine(buf, sizeof buf);
            g = (char)toupper((unsigned char)buf[0]);

            if (g == '?') {
                if (hints == 0)       sprintf(msg, "\033[91mNo hints left!");
                else if (wrong >= 5)  sprintf(msg, "\033[91mA hint would cost your last life!");
                else {
                    nc = 0;
                    for (i = 0; i < len; i++)
                        if (!used[word[i] - 'A']) cand[nc++] = word[i] - 'A';
                    pick = cand[rand() % nc];
                    used[pick] = 1; hints--; wrong++;
                    sprintf(msg, "\033[96mHint used: revealed '%c' (cost 1 life)", 'A' + pick);
                }
            } else if (!isalpha((unsigned char)g)) {
                sprintf(msg, "\033[91mType a single letter A-Z.");
            } else if (used[g - 'A']) {
                sprintf(msg, "\033[93mYou already tried '%c'.", g);
            } else {
                used[g - 'A'] = 1;
                if (strchr(word, g)) sprintf(msg, "\033[92mNice! '%c' is in the word.", g);
                else { wrong++; sprintf(msg, "\033[91mNope, no '%c'.", g); }
            }
        }

        clr();
        banner("HANGMAN");
        printf("\033[1;97m%s\033[0m\n\n", HANG[wrong > 6 ? 6 : wrong]);
        if (solved) { wins++; printf("\033[1;92mYOU SAVED HIM! The word was %s\033[0m\n", word); }
        else        { losses++; printf("\033[1;91mGAME OVER! The word was %s\033[0m\n", word); }
        printf("\n\033[93mSession: %d win(s), %d loss(es)\033[0m\n", wins, losses);
        pressEnter();
    }
}

// GAME 5 : Tic-Tac-Toe
static const int LINES[8][3] = {
    {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}
};

// returns 'X', 'O', 'D' for draw, or 0 if the game is still going
static int tttWinner(const char *b) {
    int i;
    for (i = 0; i < 8; i++)
        if (b[LINES[i][0]] != ' ' && b[LINES[i][0]] == b[LINES[i][1]] && b[LINES[i][1]] == b[LINES[i][2]])
            return b[LINES[i][0]];
    for (i = 0; i < 9; i++) if (b[i] == ' ') return 0;
    return 'D';
}

static int minimax(char *b, int oTurn, int depth) {
    int w, best, i, s;
    w = tttWinner(b);
    if (w == 'O') return 10 - depth;
    if (w == 'X') return depth - 10;
    if (w == 'D') return 0;
    best = oTurn ? -100 : 100;
    for (i = 0; i < 9; i++) {
        if (b[i] != ' ') continue;
        b[i] = oTurn ? 'O' : 'X';
        s = minimax(b, !oTurn, depth + 1);
        b[i] = ' ';
        if (oTurn ? (s > best) : (s < best)) best = s;
    }
    return best;
}

static int tttAI(char *b, int level) {
    int empty[9], bestMoves[9];
    int ne = 0, nb = 0, i, pass, w, best, s;
    char who;

    for (i = 0; i < 9; i++) if (b[i] == ' ') empty[ne++] = i;

    if (level >= 2) {   // win if possible, else block
        for (pass = 0; pass < 2; pass++) {
            who = (pass == 0) ? 'O' : 'X';
            for (i = 0; i < ne; i++) {
                b[empty[i]] = who;
                w = tttWinner(b);
                b[empty[i]] = ' ';
                if (w == who) return empty[i];
            }
        }
    }
    if (level == 1) return empty[rand() % ne];
    if (level == 2) {
        if (b[4] == ' ' && rand() % 2) return 4;
        return empty[rand() % ne];
    }
    // level 3: minimax, random pick among the best moves
    best = -100;
    for (i = 0; i < ne; i++) {
        b[empty[i]] = 'O';
        s = minimax(b, 0, 1);
        b[empty[i]] = ' ';
        if (s > best) { best = s; nb = 0; }
        if (s == best) bestMoves[nb++] = empty[i];
    }
    return bestMoves[rand() % nb];
}

static void tttDraw(const char *b) {
    int r, c;
    char v;
    printf("\n");
    for (r = 0; r < 3; r++) {
        printf("        ");
        for (c = 0; c < 3; c++) {
            v = b[r * 3 + c];
            if (v == 'X')      printf(" \033[1;91mX\033[0m ");
            else if (v == 'O') printf(" \033[1;96mO\033[0m ");
            else               printf(" \033[90m%d\033[0m ", r * 3 + c + 1);
            if (c < 2) printf("|");
        }
        printf("\n");
        if (r < 2) printf("        ---+---+---\n");
    }
    printf("\n");
}

static void tttGame(void) {
    int w = 0, l = 0, d = 0, playerStarts = 1;
    int level, again, m, res, turnPlayer;
    char b[9], note[80];

    while (1) {
        banner("TIC-TAC-TOE");
        printf("\033[1;32m1. Easy\033[0m  \033[1;33m2. Medium\033[0m  \033[1;31m3. Unbeatable\033[0m  \033[1;35m4. Main Menu\033[0m\n");
        level = readInt("\nChoose difficulty: ");
        if (level == 4) { printf("\033[1;31m\nMAIN MENU\033[0m\n"); return; }
        if (level < 1 || level > 3) { printf("\033[1;33mInvalid input\033[0m\n"); continue; }

        while (1) {
            memset(b, ' ', sizeof b);
            turnPlayer = playerStarts;
            res = 0;
            note[0] = '\0';

            while (!(res = tttWinner(b))) {
                clr();
                banner("TIC-TAC-TOE");
                printf("  You: \033[1;91mX\033[0m   Computer: \033[1;96mO\033[0m   %s\n",
                       level == 1 ? "[Easy]" : level == 2 ? "[Medium]" : "[Unbeatable]");
                tttDraw(b);
                if (note[0]) { printf("%s\033[0m\n", note); note[0] = '\0'; }

                if (turnPlayer) {
                    m = readInt("Your move (1-9): ");
                    if (m < 1 || m > 9)  { sprintf(note, "\033[91mPick a number from 1 to 9."); continue; }
                    if (b[m - 1] != ' ') { sprintf(note, "\033[91mThat cell is taken!"); continue; }
                    b[m - 1] = 'X';
                } else {
                    printf("\033[93mComputer is thinking...\033[0m\n");
                    Sleep(600);
                    b[tttAI(b, level)] = 'O';
                }
                turnPlayer = !turnPlayer;
            }

            clr();
            banner("TIC-TAC-TOE");
            tttDraw(b);
            if (res == 'X')      { w++; printf("\033[1;92mYOU WIN! Nicely played.\033[0m\n"); }
            else if (res == 'O') { l++; printf("\033[1;91mComputer wins. Try again!\033[0m\n"); }
            else                 { d++; printf("\033[1;93mIt's a draw.\033[0m\n"); }
            printf("\n\033[96mScore -> Win: %d  Loss: %d  Draw: %d\033[0m\n", w, l, d);

            playerStarts = !playerStarts;
            printf("\n1. Play again   2. Change difficulty / menu\n");
            again = readInt("Enter your choice: ");
            if (again != 1) break;
        }
    }
}

// GAME 6 : Snake
#define SW 30      // board width (each cell is 2 chars wide)
#define SH 18      // board height

static void snakeSpawn(int *fx, int *fy, const int *sx, const int *sy, int len, int ax, int ay) {
    int ok, i;
    do {
        *fx = rand() % SW;
        *fy = rand() % SH;
        ok = !(*fx == ax && *fy == ay);
        for (i = 0; i < len && ok; i++)
            if (sx[i] == *fx && sy[i] == *fy) ok = 0;
    } while (!ok);
}

static void snakeGame(void) {
    static int best = 0;
    static char buf[32768];
    static const int dx[4] = {0, 1, 0, -1};
    static const int dy[4] = {-1, 0, 1, 0};
    int sx[SW * SH], sy[SW * SH];
    char grid[SH][SW];
    char *p;
    int lvl, baseDelay, len, dir, nd, score, foods;
    int fx, fy, bx, by, bt, dead;
    int k, nx, ny, eatFood, eatBonus, limit, tx, ty, i, x, y, delay;

    banner("SNAKE");
    printf("Eat \033[1;91m()\033[0m for +10, grab the timed \033[1;93m$$\033[0m for +30.\n");
    printf("Controls: W A S D / Arrow keys | P = pause | Q = quit\n\n");
    printf("\033[1;32m1. Slow\033[0m  \033[1;33m2. Normal\033[0m  \033[1;31m3. Fast\033[0m  \033[1;35m4. Main Menu\033[0m\n");
    lvl = readInt("\nChoose speed: ");
    if (lvl == 4) { printf("\033[1;31m\nMAIN MENU\033[0m\n"); return; }
    if (lvl < 1 || lvl > 3) { printf("\033[1;33mInvalid input\033[0m\n"); return; }
    baseDelay = (lvl == 1) ? 150 : (lvl == 2) ? 105 : 70;

    len = 3; dir = 1; nd = 1; score = 0; foods = 0;
    sx[0] = SW / 2;     sy[0] = SH / 2;
    sx[1] = SW / 2 - 1; sy[1] = SH / 2;
    sx[2] = SW / 2 - 2; sy[2] = SH / 2;
    bx = -1; by = -1; bt = 0;
    snakeSpawn(&fx, &fy, sx, sy, len, -1, -1);

    dead = 0;   // 1 crashed, 2 quit, 3 board full
    clr();
    printf("\033[?25l");

    while (!dead) {
        while (_kbhit()) {
            k = _getch();
            if (k == 0 || k == 224) {
                k = _getch();
                if (k == 72 && dir != 2) nd = 0;
                else if (k == 77 && dir != 3) nd = 1;
                else if (k == 80 && dir != 0) nd = 2;
                else if (k == 75 && dir != 1) nd = 3;
            } else {
                k = tolower(k);
                if (k == 'w' && dir != 2) nd = 0;
                else if (k == 'd' && dir != 3) nd = 1;
                else if (k == 's' && dir != 0) nd = 2;
                else if (k == 'a' && dir != 1) nd = 3;
                else if (k == 'q') dead = 2;
                else if (k == 'p') {
                    printf("\033[%d;1H\033[1;93m  == PAUSED - press P to resume ==\033[K", SH + 4);
                    fflush(stdout);
                    while (tolower(_getch()) != 'p') { }
                }
            }
        }
        if (dead) break;

        dir = nd;
        nx = sx[0] + dx[dir];
        ny = sy[0] + dy[dir];
        eatFood = (nx == fx && ny == fy);
        eatBonus = (bx >= 0 && nx == bx && ny == by);

        if (nx < 0 || nx >= SW || ny < 0 || ny >= SH) { dead = 1; break; }
        limit = eatFood ? len : len - 1;   // tail moves unless we eat
        for (i = 0; i < limit; i++)
            if (sx[i] == nx && sy[i] == ny) { dead = 1; break; }
        if (dead) break;

        tx = sx[len - 1]; ty = sy[len - 1];
        for (i = len - 1; i > 0; i--) { sx[i] = sx[i - 1]; sy[i] = sy[i - 1]; }
        sx[0] = nx; sy[0] = ny;

        if (eatFood) {
            sx[len] = tx; sy[len] = ty; len++;
            score += 10; foods++;
            if (len >= SW * SH - 2) { dead = 3; break; }
            snakeSpawn(&fx, &fy, sx, sy, len, bx, by);
            if (foods % 5 == 0 && bx < 0) {
                snakeSpawn(&bx, &by, sx, sy, len, fx, fy);
                bt = 60;
            }
        }
        if (eatBonus) { score += 30; bx = -1; bt = 0; }
        if (bx >= 0 && --bt <= 0) bx = -1;
        if (score > best) best = score;

        // draw the whole frame into one buffer
        memset(grid, ' ', sizeof grid);
        grid[fy][fx] = '*';
        if (bx >= 0) grid[by][bx] = '$';
        for (i = len - 1; i >= 1; i--) grid[sy[i]][sx[i]] = 'o';
        grid[sy[0]][sx[0]] = 'O';

        p = buf;
        p += sprintf(p, "\033[H\033[1;96m SCORE %-5d BEST %-5d LENGTH %-4d\033[0m\033[K\n", score, best, len);
        p += sprintf(p, "\033[1;94m+");
        for (i = 0; i < SW * 2; i++) *p++ = '=';
        p += sprintf(p, "+\033[0m\n");
        for (y = 0; y < SH; y++) {
            p += sprintf(p, "\033[1;94m|\033[0m");
            for (x = 0; x < SW; x++) {
                switch (grid[y][x]) {
                    case 'O': p += sprintf(p, "\033[1;92m@@\033[0m"); break;
                    case 'o': p += sprintf(p, "\033[32moo\033[0m");   break;
                    case '*': p += sprintf(p, "\033[1;91m()\033[0m"); break;
                    case '$': p += sprintf(p, "\033[1;93m$$\033[0m"); break;
                    default:  p += sprintf(p, "  ");
                }
            }
            p += sprintf(p, "\033[1;94m|\033[0m\n");
        }
        p += sprintf(p, "\033[1;94m+");
        for (i = 0; i < SW * 2; i++) *p++ = '=';
        p += sprintf(p, "+\033[0m\n\033[K");
        fwrite(buf, 1, (size_t)(p - buf), stdout);
        fflush(stdout);

        delay = baseDelay - (len - 3) / 3 * 4;
        if (delay < 40) delay = 40;
        if (dir == 0 || dir == 2) delay += delay / 3;   // cells are taller than wide
        Sleep(delay);
    }

    printf("\033[?25h");
    flushKeys();
    printf("\033[%d;1H\033[J", SH + 4);
    if (dead == 1)      printf("\033[1;91mCRASH! Game over.\033[0m\n");
    else if (dead == 3) printf("\033[1;92mINCREDIBLE! You filled the board!\033[0m\n");
    else                printf("\033[1;93mYou quit the game.\033[0m\n");
    printf("\033[96mFinal score: %d   Best this session: %d\033[0m\n", score, best);
    pressEnter();
}

// GAME 7 : Memory Master
static void memoryGame(void) {
    static int best = 0;
    static const char *COL[9] = {
        "\033[1;91m", "\033[1;92m", "\033[1;93m", "\033[1;94m", "\033[1;95m",
        "\033[1;96m", "\033[1;97m", "\033[1;33m", "\033[1;32m"
    };
    int lvl, showMs, seq[40], len, lives, score, add;
    int i, ans[64], na, ok, gain;
    char line[256];

    banner("MEMORY MASTER");
    printf("Watch the digits flash, then type them back in order.\n");
    printf("Each round adds one more digit. You have 3 lives.\n\n");
    printf("\033[1;32m1. Easy\033[0m  \033[1;33m2. Medium\033[0m  \033[1;31m3. Hard\033[0m  \033[1;35m4. Main Menu\033[0m\n");
    lvl = readInt("\nChoose difficulty: ");
    if (lvl == 4) { printf("\033[1;31m\nMAIN MENU\033[0m\n"); return; }
    if (lvl < 1 || lvl > 3) { printf("\033[1;33mInvalid input\033[0m\n"); return; }
    showMs = (lvl == 1) ? 900 : (lvl == 2) ? 600 : 350;

    len = 0; lives = 3; score = 0; add = 1;

    while (lives > 0 && len < 30) {
        if (add) seq[len++] = 1 + rand() % 9;

        clr();
        printf("\n\033[1;96m ROUND %d\033[0m   \033[91mLives: %d\033[0m   \033[93mScore: %d\033[0m\n", len, lives, score);
        printf("\n  Get ready...\n");
        Sleep(1200);

        for (i = 0; i < len; i++) {
            clr();
            printf("\n\n\n          %s+-------+\n          |       |\n          |   %d   |\n          |       |\n          +-------+\033[0m\n",
                   COL[seq[i] - 1], seq[i]);
            Sleep(showMs);
            clr();
            Sleep(160);
        }

        clr();
        printf("\n\033[1;96m ROUND %d\033[0m - your turn! (%d digits)\n", len, len);
        printf("Type the sequence (spaces optional): ");
        readLine(line, sizeof line);

        na = 0;
        for (i = 0; line[i] && na < 64; i++)
            if (line[i] >= '1' && line[i] <= '9') ans[na++] = line[i] - '0';

        ok = (na == len);
        for (i = 0; ok && i < len; i++) if (ans[i] != seq[i]) ok = 0;

        if (ok) {
            gain = len * 10 * lvl;
            score += gain;
            add = 1;
            printf("\n\033[1;92mPERFECT! +%d points\033[0m\n", gain);
        } else {
            lives--;
            add = 0;
            printf("\n\033[1;91mNot quite!\033[0m The sequence was: ");
            for (i = 0; i < len; i++) printf("%s%d \033[0m", COL[seq[i] - 1], seq[i]);
            printf("\n");
            if (lives > 0) printf("\033[93mLives left: %d - same pattern again!\033[0m\n", lives);
        }
        if (score > best) best = score;
        Sleep(1600);
    }

    clr();
    banner("MEMORY MASTER");
    if (len >= 30 && lives > 0) printf("\033[1;92mLEGENDARY MEMORY! You cleared all 30 rounds!\033[0m\n");
    else printf("\033[1;91mGame over! You reached round %d.\033[0m\n", len);
    printf("\033[96mScore: %d   Best this session: %d\033[0m\n", score, best);
    pressEnter();
}

// GAME 8 : Blackjack
static int deck[52], dpos = 52;

static void shuffleDeck(void) {
    int i, j, t;
    for (i = 0; i < 52; i++) deck[i] = i;
    for (i = 51; i > 0; i--) {
        j = rand() % (i + 1);
        t = deck[i]; deck[i] = deck[j]; deck[j] = t;
    }
    dpos = 0;
}

static int drawCard(void) {
    if (dpos >= 52) shuffleDeck();
    return deck[dpos++];
}

static int cardVal(int c) {
    int r = c % 13;
    if (r == 0) return 11;
    if (r >= 9) return 10;
    return r + 1;
}

static int handVal(const int *h, int n) {
    int t = 0, aces = 0, i, v;
    for (i = 0; i < n; i++) {
        v = cardVal(h[i]);
        t += v;
        if (v == 11) aces++;
    }
    while (t > 21 && aces) { t -= 10; aces--; }
    return t;
}

static void showCard(int c) {
    static const char *RANK[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    static const char SUIT[4] = {'S', 'H', 'D', 'C'};
    int s = c / 13;
    printf("%s[%s%c]\033[0m ", (s == 1 || s == 2) ? "\033[1;91m" : "\033[1;97m", RANK[c % 13], SUIT[s]);
}

static void bjTable(const int *p, int np, const int *d, int nd, int hide, int chips, int bet) {
    int i;
    clr();
    banner("BLACKJACK");
    printf("\033[93mChips: %d\033[0m   \033[96mBet: %d\033[0m\n\n", chips, bet);
    printf("Dealer: ");
    for (i = 0; i < nd; i++) {
        if (hide && i == 1) printf("\033[90m[??]\033[0m ");
        else showCard(d[i]);
    }
    if (hide) printf("  (showing %d)", cardVal(d[0]));
    else      printf("  = %d", handVal(d, nd));
    printf("\n\nYou:    ");
    for (i = 0; i < np; i++) showCard(p[i]);
    printf("  = %d\n\n", handVal(p, np));
}

static void blackjackGame(void) {
    int chips = 500, peak = 500;
    int bet, p[12], d[12], np, nd, pv, dv;
    int outcome, payout, first, busted, doubled, canDouble, a;
    const char *why;

    shuffleDeck();

    banner("BLACKJACK");
    printf("Beat the dealer without going over 21.\n");
    printf("Blackjack pays 3:2 | Dealer stands on 17 | Double down on first move.\n");
    printf("You start with \033[93m%d chips\033[0m. Bet 0 to leave the table.\n", chips);

    while (chips > 0) {
        printf("\n\033[93mChips: %d\033[0m\n", chips);
        bet = readInt("Place your bet: ");
        if (bet == 0) break;
        if (bet < 0 || bet > chips) { printf("\033[91mBet must be between 1 and %d.\033[0m\n", chips); continue; }

        np = 0; nd = 0;
        p[np++] = drawCard(); d[nd++] = drawCard();
        p[np++] = drawCard(); d[nd++] = drawCard();

        pv = handVal(p, np);
        dv = handVal(d, nd);
        outcome = 0;      // 1 win, -1 lose, 0 push
        payout = 0;
        why = "";

        if (pv == 21 || dv == 21) {
            bjTable(p, np, d, nd, 0, chips, bet);
            if (pv == 21 && dv == 21) { outcome = 0; why = "Both have Blackjack - push."; }
            else if (pv == 21)        { outcome = 1; payout = bet * 3 / 2; why = "BLACKJACK! Pays 3:2."; }
            else                      { outcome = -1; payout = bet; why = "Dealer has Blackjack."; }
        } else {
            first = 1; busted = 0; doubled = 0;
            while (1) {
                bjTable(p, np, d, nd, 1, chips, bet);
                printf("\033[1;32m1. Hit\033[0m  \033[1;33m2. Stand\033[0m");
                canDouble = first && chips >= bet * 2;
                if (canDouble) printf("  \033[1;36m3. Double\033[0m");
                printf("\n");
                a = readInt("Your move: ");
                if (a == 1) {
                    p[np++] = drawCard(); first = 0;
                    if (handVal(p, np) > 21) { busted = 1; break; }
                    if (handVal(p, np) == 21) break;
                } else if (a == 2) break;
                else if (a == 3 && canDouble) {
                    doubled = 1; bet *= 2;
                    p[np++] = drawCard();
                    if (handVal(p, np) > 21) busted = 1;
                    break;
                } else printf("\033[91mInvalid choice.\033[0m\n");
            }
            pv = handVal(p, np);

            if (busted) {
                bjTable(p, np, d, nd, 0, chips, bet);
                outcome = -1; payout = bet; why = "BUST! You went over 21.";
            } else {
                bjTable(p, np, d, nd, 1, chips, bet);
                printf("\033[93mDealer reveals...\033[0m\n");
                Sleep(900);
                bjTable(p, np, d, nd, 0, chips, bet);
                while (handVal(d, nd) < 17 && nd < 12) {
                    Sleep(900);
                    d[nd++] = drawCard();
                    bjTable(p, np, d, nd, 0, chips, bet);
                }
                dv = handVal(d, nd);
                if (dv > 21)      { outcome = 1;  payout = bet; why = "Dealer busts - you win!"; }
                else if (pv > dv) { outcome = 1;  payout = bet; why = "You beat the dealer!"; }
                else if (pv < dv) { outcome = -1; payout = bet; why = "Dealer wins this hand."; }
                else              { outcome = 0;  why = "Push - bet returned."; }
            }
            (void)doubled;
        }

        if (outcome > 0)      { chips += payout; printf("\033[1;92m%s +%d chips\033[0m\n", why, payout); }
        else if (outcome < 0) { chips -= payout; printf("\033[1;91m%s -%d chips\033[0m\n", why, payout); }
        else                  { printf("\033[1;93m%s\033[0m\n", why); }
        if (chips > peak) peak = chips;
        Sleep(800);
    }

    printf("\n");
    banner("BLACKJACK");
    if (chips <= 0) printf("\033[1;91mYou're out of chips - the house wins.\033[0m\n");
    else printf("\033[1;92mYou leave the table with %d chips.\033[0m\n", chips);
    printf("\033[96mPeak bankroll: %d\033[0m\n", peak);
    pressEnter();
}

// MAIN
int main(void) {
    int choice1, game;

    srand((unsigned)time(0));
    enableANSI();

    printf("\033[93mDo you want to play?\033[0m\n");
    printf("\033[0;31m1. Yes\033[0m \033[0;33m2. No\033[0m\n");
    choice1 = readInt("\nEnter your choice: ");

    if (choice1 == 2) { blinkterminate(0); return 0; }
    if (choice1 != 1) {
        printf("\033[92m\nWrong input\033[0m\n");
        blinkterminate(0);
        return 0;
    }

    while (1) {
        printf("\n\033[1;96m=========== GAME ARENA ===========\033[0m\n");
        printf("Which game you wanna play?\n");
        printf("\033[1;32m1. ROCK PAPER SCISSORS\033[0m\n");
        printf("\033[1;34m2. NUMBER GUESSING\033[0m\n");
        printf("\033[1;35m3. MATH CHALLENGE\033[0m\n");
        printf("\033[1;33m4. HANGMAN\033[0m\n");
        printf("\033[1;36m5. TIC-TAC-TOE\033[0m\n");
        printf("\033[1;92m6. SNAKE\033[0m\n");
        printf("\033[1;95m7. MEMORY MASTER\033[0m\n");
        printf("\033[1;91m8. BLACKJACK\033[0m\n");
        printf("\033[1;31m9. EXIT\033[0m\n");
        game = readInt("\n\033[1;93mEnter your choice: \033[0m");

        switch (game) {
            case 1: rpsGame();        break;
            case 2: guessGame();      break;
            case 3: mathChallenge();  break;
            case 4: hangmanGame();    break;
            case 5: tttGame();        break;
            case 6: snakeGame();      break;
            case 7: memoryGame();     break;
            case 8: blackjackGame();  break;
            case 9: quitGame();       break;
            default: printf("\033[1;32mInvalid input! Choose 1-9\033[0m\n"); break;
        }
    }
    return 0;
}
