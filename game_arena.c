/*
 * Game-Arena - A Multi-Game Console Application
 * Copyright (C) 2026  RAHUL MANNA
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Author: Rahul Manna
 * Date: 2026
 * Description: A console-based multi-game application featuring Rock Paper Scissors,
 *              Number Guessing, and Math Challenge with multiple difficulty levels.
 
 *-------------------HAPPY GAMING-------------
 */





#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

// Function prototypes
void result(int win, int loss, float x);
void result2(int win, int loss, int sec);
void blinkterminate(int dsa);
void blinkalert(int dsa, int j);

// Global variables
int a, b, c, compans1, index1, index2;
int  choice, choice1, choice2, choice3, dsa, game;
int ans1, win, loss, rest, i;
int rem, e, f, g, p,n;
time_t start, end, sec, s = 1;
float x = 0.0;
char ch[] = {'+', '-', '*', '/', '%'};

void result(int win, int loss, float x) {
    float persent = 0.0;
    
    if(win == 0 && loss == 0) {
        printf("\n\033[100;93mNo Game Played \033[0m\n");
    } else {
        printf("\033[1;93m\nYOUR RESULT\033[0m");
        printf("\ntotal game: %d   win: %d  loss: %d", win + loss, win, loss);
        persent = ((100.0 * win) / (win + loss));
        printf("\npercentage of win: %.3f%%", persent);
        printf("\naverage time: %.3f seconds\n", x / (win + loss));
    }
    
    if(persent <= 10.000 && (win + loss) != 0) {
        printf("\033[91mYou are noob bro, go to study\033[0m\n");
    } else if(persent <= 30.000 && persent > 10.000) {
        printf("\033[91mNot so good. Need more practice\033[0m\n");
    } else if(persent <= 60.000 && persent > 30.000) {
        printf("\033[91mYou are a good player but need some extra practice\033[0m\n");
    } else if(persent <= 80.000 && persent > 60.000) {
        printf("\033[91mYou are a pro player at this level\033[0m\n");
    } else if(persent <= 100.000 && persent > 80.000 && (win + loss) != 0) {
        printf("\033[91mKudos sir, GM\033[0m\n");
    }
}

void result2(int win, int loss, int sec) {
    printf("\033[94m%d sec finished!!!\n\033[0m", sec);
    printf("\ntotal game: %d   win: %d  loss: %d", win + loss, win, loss);
}

void blinkterminate(int dsa) {
    for(dsa = 0; dsa <= 2; dsa++) {
        printf("\033[0;91mTerminating the game!!!\033[0m\r");
        fflush(stdout);
        Sleep(300);
        printf("                       \r");
        fflush(stdout);
        Sleep(300);
    }
}

void blinkalert(int dsa, int j) {
    for(dsa = 1; dsa <= j; dsa++) {
        printf("\033[0;91mAlert!! Equation will vanish after %d seconds\033[0m\r", j - dsa + 1);
        fflush(stdout);
        Sleep(1000);
        printf("                                                                        \r");
        fflush(stdout);
    }
}

int main() {
    srand(time(0));
    
    printf("\033[93mDo you want to play?\033[0m\n");
    printf("\033[0;31m1. Yes\033[0m \033[0;33m2. No\033[0m\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice1);
    
    if(choice1 == 1) {
        s = 0;
    } else if(choice1 == 2) {
        blinkterminate(0);
        return 0;
    } else {
        printf("\033[92m\nWrong input\033[0m\n");
        blinkterminate(0);
        return 0;
    }
    
    while(1) {
        if(s == 0) {
printf("\nWhich game you wanna play?\n");
printf("\033[1;32m1. ROCK PAPER SCISSORS\033[0m\n");
printf("\033[1;34m2. NUMBER GUESSING\033[0m\n");
printf("\033[1;35m3. MATH CHALLENGE\033[0m\n");
printf("\033[1;31m4. EXIT\033[0m\n");
printf("\n\033[1;93mEnter your choice: \033[0m");
scanf("%d", &game);

switch(game) {
    case 1: {
        e = 0, f = 0, g = 0;
        printf("\nLET'S PLAY ROCK PAPER SCISSORS!!\n");
        
        while(1) {
            printf("\033[1;32m\n1. Play\033[0m ");
            printf("\033[1;34m2. Result\033[0m ");
            printf("\033[1;35m3. Main Menu\033[0m ");
            printf("\033[1;31m4. EXIT\033[0m\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
            
            switch(choice) {
                case 1: {
                    p = 0;
                    while(p == 0) {
                        printf("\nTake your choice:\n");
                        printf("\033[1;93m1. ROCK\033[0m  ");
                        printf("\033[1;35m2. PAPER\033[0m  ");
                        printf("\033[1;31m3. SCISSORS\033[0m\n");
                        printf("Enter your choice: ");
                        scanf("%d", &n);
                        
                        switch(n) {
                            case 1:
                                printf("\033[93m\nYour choice is ROCK\033[0m\n");
                                p++;
                                break;
                            case 2:
                                printf("\033[94m\nYour choice is PAPER\033[0m\n");
                                p++;
                                break;
                            case 3:
                                printf("\033[92m\nYour choice is SCISSORS\033[0m\n");
                                p++;
                                break;
                            default:
                                printf("\033[1;31mInvalid input! Choose 1-3\033[0m\n");
                                break;
                        }
                    }
                    
                    int r = (rand() % 3) + 1;
                    printf("\033[38;5;178mComputer's choice: \033[0m");
                    
                    if(r == 1) printf("ROCK\n");
                    else if(r == 2) printf("PAPER\n");
                    else printf("SCISSORS\n");
                    
                    rem = (n - r + 3) % 3;
                    
                    if(rem == 0) {
                        printf("\033[1;36mDraw match!!\033[0m\n");
                        g++;
                    } else if(rem == 1) {
                        printf("\033[1;32mCongratulations!! You win\033[0m\n");
                        e++;
                    } else {
                        printf("\033[1;31mBetter luck next time\033[0m\n");
                        f++;
                    }
                    break;
                }
                
                case 2: {
                    printf("\033[93m\nYOUR RESULT\033[0m\n");
                    if(e + f + g == 0) {
                        printf("\033[91mNo game played\033[0m\n");
                        printf("Play at least one game\n");
                    } else {
                        float d = ((e * 100.0) / (e + f + g));
                        printf("\033[95mTotal games: %d\033[0m\n", e + f + g);
                        printf("Win: %d   Loss: %d   Draw: %d\n", e, f, g);
                        printf("Win probability: %.3f%%\n", d);
                        
                        if(e > f) printf("\033[1;32mYou are winning!\033[0m\n");
                        else if(f > e) printf("\033[93mComputer is winning!\033[0m\n");
                        else if(e == f && e != 0) printf("\033[1;31mBoth are winners!\033[0m\n");
                    }
                    break;
                }
                
                case 3:
                    printf("\033[1;31m\nMAIN MENU\033[0m\n");
                    break;
                    
                case 4:
                    blinkterminate(0);
                    return 0;
                    
                default:
                    printf("\033[1;33mInvalid input\033[0m\n");
                    break;
            }
            if(choice == 3) break;
        }
        break;
    }
    
    case 2: {
        e = 0, f = 0;
        printf("\nYOU CHOOSE: NUMBER GUESSING GAME\n");
        
        while(1) {
            printf("\033[1;32m\n1. Play\033[0m ");
            printf("\033[1;34m2. Result\033[0m ");
            printf("\033[1;35m3. Main Menu\033[0m ");
            printf("\033[1;31m4. EXIT\033[0m\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
            
            switch(choice) {
                case 1: {
                    printf("\033[1;36m\nGuess your number (1-5): \033[0m");
                    scanf("%d", &n);
                    printf("\033[93mYour guess: %d\033[0m\n", n);
                    
                    int r = 1 + rand() % 5;
                    printf("\033[35mComputer's number: %d\033[0m\n", r);
                    
                    if(n == r) {
                        printf("\033[1;32mCongratulations! You won!\033[0m\n");
                        e++;
                    } else {
                        printf("\033[1;31mBetter luck next time!\033[0m\n");
                        f++;
                    }
                    break;
                }
                
                case 2: {
                    printf("\033[1;31m\nRESULT\033[0m\n");
                    if(e + f == 0) {
                        printf("\033[36mNo game played\033[0m\n");
                        printf("Play at least one game\n");
                    } else {
                        float d = ((e * 100.0) / (e + f));
                        printf("\033[93mTotal games: %d\033[0m\n", e + f);
                        printf("Win: %d\nLoss: %d\n", e, f);
                        printf("Win probability: %.3f%%\n", d);
                        
                        if(e > f) printf("\033[1;32mYou are winning!\033[0m\n");
                        else if(e == f) printf("\033[93mBoth are winners!\033[0m\n");
                        else printf("\033[91mComputer is winning!\033[0m\n");
                    }
                    break;
                }
                
                case 3:
                    printf("\033[1;31m\nMAIN MENU\033[0m\n");
                    break;
                    
                case 4:
                    blinkterminate(0);
                    return 0;
                    
                default:
                    printf("\033[1;31mInvalid input\033[0m\n");
                    break;
            }
            if(choice == 3) break;
        }
        break;
    }
    
case 3: {
    while(1) {
        printf("\n\033[0;31m1. Noob\033[0m ");
        printf("\033[0;33m2. Beginner\033[0m ");
        printf("\033[0;32m3. Intermediate\033[0m ");
        printf("\033[0;34m4. Advance\033[0m ");
        printf("\033[0;36m5. Pro\033[0m ");
        printf("\033[0;35m6. Grand Master\033[0m ");
        printf("\033[1;33m7. Time Challenge\033[0m ");
        printf("\033[1;91m8. Main Menu\033[0m ");
        printf("\033[0;37m9. Exit\033[0m\n");
        printf("\nEnter your level: ");
        scanf("%d", &choice2);
        
switch(choice2) {
    case 1: { // Noob
        win = 0, loss = 0, x = 0.0;
        printf("\n\033[91mYour level: NOOB\033[0m\n");
        printf("\033[93mGAME RULE:\033[0m\n");
        printf("2 operands (1-10) | 2 operators (+,-) | No time limit\n");
        
        while(1) {
            printf("\n\033[0;32m1. Start\033[0m ");
            printf("\033[0;33m2. Result\033[0m ");
            printf("\033[0;34m3. Previous Menu\033[0m ");
            printf("\033[0;31m4. Exit\033[0m\n");
            printf("Enter your choice: ");
            scanf("%d", &choice3);
            
            switch(choice3) {
                case 1: {
                    a = 1 + rand() % 10;
                    b = 1 + rand() % 10;
                    index1 = rand() % 2;
                    printf("\033[93m%d %c %d\033[0m", a, ch[index1], b);
                    
                    if(ch[index1] == '+') compans1 = a + b;
                    else compans1 = a - b;
                    
                    time(&start);
                    printf("\nEnter your answer: ");
                    scanf("%d", &ans1);
                    time(&end);
                    
                    float diff = difftime(end, start);
                    x += diff;
                    
                    if(ans1 == compans1) {
                        printf("\033[32m\nWow! You are right!\033[0m");
                        printf("\033[93m\nYou took %.3f seconds\033[0m\n", diff);
                        win++;
                    } else {
                        printf("\n\033[93mSorry!\033[0m\n\033[91mRight answer is %d\033[0m\n", compans1);
                        loss++;
                    }
                    break;
                }
                case 2:
                    result(win, loss, x);
                    break;
                case 3:
                    printf("\n\033[1;36mPREVIOUS MENU\033[0m\n");
                    break;
                case 4:
                    blinkterminate(0);
                    return 0;
                default:
                    printf("Invalid input\n");
                    break;
            }
            if(choice3 == 3) break;
        }
        break;
    }
            
    case 2: { // Beginner
        win = 0, loss = 0, x = 0.0;
        printf("\n\033[91mYour level: BEGINNER\033[0m\n");
        printf("\033[93mGAME RULE:\033[0m\n");
        printf("2 operands (5-15) | 4 operators (+,-,*,/) | No time limit\n");
        
	while(1) {
	    printf("\n\033[0;32m1. Start\033[0m ");
	    printf("\033[0;33m2. Result\033[0m ");
	    printf("\033[0;34m3. Previous Menu\033[0m ");
	    printf("\033[0;31m4. Exit\033[0m\n");
	    printf("Enter your choice: ");
	    scanf("%d", &choice3);
	    
	    switch(choice3) {
	        case 1: {
	            a = 5 + rand() % 11;
	            b = 5 + rand() % 11;
	            index1 = rand() % 4;
	            printf("\033[93m%d %c %d\033[0m", a, ch[index1], b);
	            
	            if(ch[index1] == '+') compans1 = a + b;
	            else if(ch[index1] == '-') compans1 = a - b;
	            else if(ch[index1] == '*') compans1 = a * b;
	            else compans1 = a / b;
	            
	            time(&start);
	            printf("\nEnter your answer: ");
	            scanf("%d", &ans1);
	            time(&end);
	            
	            float diff = difftime(end, start);
	            x += diff;
	            
	            if(ans1 == compans1) {
	                printf("\033[32m\nWow! You are right!\033[0m");
	                printf("\033[93m\nYou took %.3f seconds\033[0m\n", diff);
	                win++;
	            } else {
	                printf("\n\033[93mSorry!\033[0m\n\033[91mRight answer is %d\033[0m\n", compans1);
	                loss++;
	            }
	            break;
	        }
	        case 2:
	            result(win, loss, x);
	            break;
	        case 3:
	            printf("\n\033[1;36mPREVIOUS MENU\033[0m\n");
	            break;
	        case 4:
	            blinkterminate(0);
	            return 0;
	        default:
	            printf("Invalid input\n");
	            break;
	    }
	    if(choice3 == 3) break;
	}
	break;
}
                
	case 3: { // Intermediate
	win = 0, loss = 0, x = 0.0;
	printf("\n\033[91mYour level: INTERMEDIATE\033[0m\n");
	printf("\033[93mGAME RULE:\033[0m\n");
	printf("2 operands (10-20) | 5 operators (+,-,*,/,%%) | No time limit\n");
	
	while(1) {
	    printf("\n\033[0;32m1. Start\033[0m ");
	    printf("\033[0;33m2. Result\033[0m ");
	    printf("\033[0;34m3. Previous Menu\033[0m ");
	    printf("\033[0;31m4. Exit\033[0m\n");
	    printf("Enter your choice: ");
	    scanf("%d", &choice3);
                        
    switch(choice3) {
        case 1: {
            a = 10 + rand() % 11;
            b = 10 + rand() % 11;
            index1 = rand() % 5;
            printf("\033[93m%d %c %d\033[0m", a, ch[index1], b);
            
            if(ch[index1] == '+') compans1 = a + b;
            else if(ch[index1] == '-') compans1 = a - b;
            else if(ch[index1] == '*') compans1 = a * b;
            else if(ch[index1] == '/') compans1 = a / b;
            else compans1 = a % b;
            
            time(&start);
            printf("\nEnter your answer: ");
            scanf("%d", &ans1);
            time(&end);
            
            float diff = difftime(end, start);
            x += diff;
            
            if(ans1 == compans1) {
                printf("\033[32m\nWow! You are right!\033[0m");
                printf("\033[93m\nYou took %.3f seconds\033[0m\n", diff);
                win++;
            } else {
                printf("\n\033[93mSorry!\033[0m\n\033[91mRight answer is %d\033[0m\n", compans1);
                loss++;
            }
            break;
        }
        case 2:
            result(win, loss, x);
            break;
        case 3:
            printf("\n\033[1;36mPREVIOUS MENU\033[0m\n");
            break;
        case 4:
            blinkterminate(0);
            return 0;
        default:
            printf("Invalid input\n");
            break;
    }
    if(choice3 == 3) break;
}
break;
}
                
    case 4: { // Advance
        win = 0, loss = 0, x = 0.0;
        printf("\n\033[91mYour level: ADVANCE\033[0m\n");
        printf("\033[96mGAME RULE:\033[0m\n");
        printf("2 operands (10-30) | 5 operators | Equation vanishes after 3 sec\n");
        
        while(1) {
            printf("\n\033[0;32m1. Start\033[0m ");
            printf("\033[0;33m2. Result\033[0m ");
            printf("\033[0;34m3. Previous Menu\033[0m ");
            printf("\033[0;31m4. Exit\033[0m\n");
            printf("Enter your choice: ");
            scanf("%d", &choice3);
            
            switch(choice3) {
                case 1: {
                    a = 10 + rand() % 21;
                    b = 10 + rand() % 21;
                    index1 = rand() % 5;
                    printf("\033[93m%d %c %d\033[0m\n", a, ch[index1], b);
                    
                    if(ch[index1] == '+') compans1 = a + b;
                    else if(ch[index1] == '-') compans1 = a - b;
                    else if(ch[index1] == '*') compans1 = a * b;
                    else if(ch[index1] == '/') compans1 = a / b;
                    else compans1 = a % b;
                    
                    time(&start);
                    blinkalert(0, 3);
                    system("cls");
                    
                    printf("\nEnter your answer: ");
                    scanf("%d", &ans1);
                    time(&end);
                    
                    float diff = difftime(end, start);
                    x += diff;
                    
                    if(ans1 == compans1) {
                        printf("\033[1;93mThe equation was: \033[0m");
                        printf("\033[96m%d %c %d\033[0m\n", a, ch[index1], b);
                        printf("\033[32mWow! You are right!\033[0m");
                        printf("\033[93m\nYou took %.3f seconds\033[0m\n", diff);
                        win++;
                    } else {
                        printf("\033[1;93mThe equation was: \033[0m");
                        printf("\033[96m%d %c %d\033[0m\n", a, ch[index1], b);
                        printf("\n\033[93mSorry!\033[0m\n\033[91mRight answer is %d\033[0m\n", compans1);
                        loss++;
                    }
                    break;
                }
                case 2:
                    result(win, loss, x);
                    break;
                case 3:
                    printf("\n\033[1;36mPREVIOUS MENU\033[0m\n");
                    break;
                case 4:
                    blinkterminate(0);
                    return 0;
                default:
                    printf("Invalid input\n");
                    break;
            }
            if(choice3 == 3) break;
        }
        break;
    }
                
case 5: { // Pro
    win = 0, loss = 0, x = 0.0;
    printf("\n\033[93mYour level: PRO\033[0m\n");
    printf("\033[96mGAME RULE:\033[0m\n");
    printf("2 operands (10-30) | Time limit: 5 sec\n");
    
    while(1) {
        printf("\n\033[0;32m1. Start\033[0m ");
        printf("\033[0;33m2. Result\033[0m ");
        printf("\033[0;34m3. Previous Menu\033[0m ");
        printf("\033[0;31m4. Exit\033[0m\n");
        printf("Enter your choice: ");
        scanf("%d", &choice3);
        
        switch(choice3) {
            case 1: {
                a = 10 + rand() % 21;
                b = 10 + rand() % 21;
                index1 = rand() % 5;
                
                printf("\033[93m");
                Sleep(1000);
                printf("%d  ", a);
                Sleep(1000);
                printf("%c ", ch[index1]);
                Sleep(1000);
                printf("%d \033[0m\n", b);
                
                if(ch[index1] == '+') compans1 = a + b;
                else if(ch[index1] == '-') compans1 = a - b;
                else if(ch[index1] == '*') compans1 = a * b;
                else if(ch[index1] == '/') compans1 = a / b;
                else compans1 = a % b;
                
                time(&start);
                blinkalert(0, 3);
                system("cls");
                
                printf("\nEnter your answer: ");
                scanf("%d", &ans1);
                time(&end);
                
                float diff = difftime(end, start);
                x += diff;
                
                printf("\033[1;93mThe equation was: \033[0m");
                printf("\033[96m%d %c %d\033[0m\n", a, ch[index1], b);
                
                if(ans1 == compans1 && diff <= 5.000) {
                    printf("\033[32mWow! You are right!\033[0m");
                    printf("\033[93m\nYou took %.3f seconds\033[0m\n", diff);
                    win++;
                } else if(ans1 == compans1 && diff > 5.000) {
                    printf("\033[92mSorry! You are right but out of time!\033[0m");
                    printf("\033[93m\nYou took %.3f seconds\033[0m\n", diff);
                    loss++;
                } else {
                    printf("\n\033[93mSorry!\033[0m\n\033[91mRight answer is %d\033[0m\n", compans1);
                    loss++;
                }
                break;
            }
            case 2:
                result(win, loss, x);
                break;
            case 3:
                printf("\n\033[1;36mPREVIOUS MENU\033[0m\n");
                break;
            case 4:
                blinkterminate(0);
                return 0;
            default:
                printf("Invalid input\n");
                break;
        }
        if(choice3 == 3) break;
    }
    break;
}
                
case 6: { // Grand Master
    win = 0, loss = 0, x = 0.0;
    printf("\n\033[91mYour level: GRAND MASTER\033[0m\n");
    printf("\033[96mGAME RULE:\033[0m\n");
    printf("3 operands (10-30) | 5 operators | Time limit: 5 sec\n");
    
    while(1) {
        printf("\n\033[0;32m1. Start\033[0m ");
        printf("\033[0;33m2. Result\033[0m ");
        printf("\033[0;34m3. Previous Menu\033[0m ");
        printf("\033[0;31m4. Exit\033[0m\n");
        printf("Enter your choice: ");
        scanf("%d", &choice3);
        
        switch(choice3) {
            case 1: {
                a = 10 + rand() % 21;
                b = 10 + rand() % 21;
                c = 10 + rand() % 21;
                index1 = rand() % 5;
                index2 = rand() % 5;
                
                printf("\033[93m( ");
                Sleep(1000);
                printf("%d ", a);
                Sleep(1000);
                printf("%c ", ch[index1]);
                Sleep(1000);
                printf("%d ) ", b);
                Sleep(1000);
                printf("%c ", ch[index2]);
                Sleep(1000);
                printf("%d \033[0m\n", c);
                
                if(ch[index1] == '+') rest = a + b;
                else if(ch[index1] == '-') rest = a - b;
                else if(ch[index1] == '*') rest = a * b;
                else if(ch[index1] == '/') rest = a / b;
                else rest = a % b;
                
                if(ch[index2] == '+') compans1 = rest + c;
                else if(ch[index2] == '-') compans1 = rest - c;
                else if(ch[index2] == '*') compans1 = rest * c;
                else if(ch[index2] == '/') compans1 = rest / c;
                else compans1 = rest % c;
                
                time(&start);
                blinkalert(0, 3);
                system("cls");
                
                printf("Enter your answer: ");
                scanf("%d", &ans1);
                time(&end);
                
                float diff = difftime(end, start);
                x += diff;
                
                printf("\033[1;93mThe equation was: \033[0m");
                printf("\033[96m( %d %c %d ) %c %d\033[0m\n", a, ch[index1], b, ch[index2], c);
                
                if(ans1 == compans1 && diff <= 5.000) {
                    printf("\033[32mWow! You are right!\033[0m");
                    printf("\033[93m\nYou took %.3f seconds\033[0m\n", diff);
                    win++;
                } else if(ans1 == compans1 && diff > 5.000) {
                    printf("\033[92mSorry! You are right but out of time!\033[0m");
                    printf("\033[93m\nYou took %.3f seconds\033[0m\n", diff);
                    loss++;
                } else {
                    printf("\n\033[93mSorry!\033[0m\n\033[91mRight answer is %d\033[0m\n", compans1);
                    loss++;
                }
                break;
            }
            case 2:
                result(win, loss, x);
                break;
            case 3:
                printf("\n\033[1;36mPREVIOUS MENU\033[0m\n");
                break;
            case 4:
                blinkterminate(0);
                return 0;
            default:
                printf("Invalid input\n");
                break;
        }
        if(choice3 == 3) break;
    }
    break;
}

    case 7: { // Time Challenge
        printf("\nTIME CHALLENGE\n");
        printf("\033[96mGAME RULE:\033[0m\n");
        printf("2 operands (1-15) | User defined time limit\n");
        
        while(1) {
            printf("\n\033[0;32m1. Start\033[0m ");
            printf("\033[0;33m2. Previous Menu\033[0m ");
            printf("\033[0;31m3. Exit\033[0m\n");
            printf("Enter your choice: ");
            scanf("%d", &choice3);
            
            switch(choice3) {
                case 1: {
                    win = 0, loss = 0, x = 0.0;
                    printf("Enter time limit (seconds): ");
                    scanf("%d", &sec);
                    printf("\033[34mTime limit: %d seconds\033[0m\n", sec);
                    printf("\nLet's start!\n");
                    i = 1;
                    time(&start);
                    
                    while(1) {
                        time(&end);
                        float diff = difftime(end, start);
                        
                        if(diff >= sec) {
                            printf("\nTIME UP!!\n");
                            result2(win, loss, sec);
                            break;
                        }
                        
                        a = 1 + rand() % 15;
                        b = 1 + rand() % 15;
                        index1 = rand() % 5;
                        
                        printf("Question %d: \033[93m%d %c %d\033[0m\n", i, a, ch[index1], b);
                        printf("Enter your answer: ");
                        scanf("%d", &ans1);
                        
                        if(ch[index1] == '+') compans1 = a + b;
                        else if(ch[index1] == '-') compans1 = a - b;
                        else if(ch[index1] == '*') compans1 = a * b;
                        else if(ch[index1] == '/') compans1 = a / b;
                        else compans1 = a % b;
                        
                        if(ans1 == compans1) {
                            printf("\033[32mCorrect!\033[0m\n");
                            win++;
                        } else {
                            printf("\033[31mWrong! Answer was %d\033[0m\n", compans1);
                            loss++;
                        }
                        i++;
                    }
                    break;
                }
                case 2:
                    printf("\n\033[1;36mPREVIOUS MENU\033[0m\n");
                    break;
                case 3:
                    blinkterminate(0);
                    return 0;
                default:
                    printf("Invalid input\n");
                    break;
            }
            if(choice3 == 2) break;
        }
        break;
    }
    
    case 8:
        printf("\n\033[1;36mMAIN MENU\033[0m\n");
        break;
        
    case 9:
        blinkterminate(0);
        return 0;
        
    default:
        printf("\033[1;33mInvalid input! Choose 1-9\033[0m\n");
        break;
}
            if(choice2 == 8) break;
        }
        break;
    }
    
    case 4:
        blinkterminate(0);
        return 0;
        
    default:
        printf("\033[1;32mInvalid input! Choose 1-4\033[0m\n");
        break;
            }
        }
    }
    return 0;
}


