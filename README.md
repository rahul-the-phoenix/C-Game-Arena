# 🎮 Ultimate Gaming Hub

## A Colorful C Console Gaming Platform for Windows

<div align="center">

![Version](https://img.shields.io/badge/version-2.0.0-blue)
![License](https://img.shields.io/badge/license-GPLv3-green)
![Platform](https://img.shields.io/badge/platform-Windows-lightgrey)
![Language](https://img.shields.io/badge/language-C89-orange)
![Games](https://img.shields.io/badge/games-8-brightgreen)

</div>

---

## 🚀 Overview

**Ultimate Gaming Hub** is a console-based gaming platform written in C. Version 2.0 grows the collection from 3 to **8 games**, including a real-time Snake, an unbeatable Tic-Tac-Toe AI, Blackjack, Hangman and a Simon-style memory game, all with a colorful ANSI interface.

The code is written in plain **C89 style**, so it also builds in old compilers such as Dev-C++.

### Key Statistics

| Metric | Value |
|--------|-------|
| **Lines of Code** | 1000+ |
| **Games Included** | 8 |
| **Math Difficulty Levels** | 6 + Time Challenge |
| **Operators Supported** | 5 (+, -, *, /, %) |
| **AI Difficulty Levels (Tic-Tac-Toe)** | 3 |

---

## 🆕 What's New in 2.0

- **5 new games:** Hangman, Tic-Tac-Toe, Snake, Memory Master and Blackjack
- **Safe input everywhere:** typing letters instead of numbers no longer breaks a menu
- **Millisecond timing** via `GetTickCount()` (the old `difftime()` timer only had 1-second resolution)
- **Math Challenge refactor:** the six levels share one function, cutting hundreds of duplicated lines
- **Fairer timed levels:** the Pro and Grand Master timer now starts when the answer prompt appears, not before the 3-second vanish alert
- **Time Challenge fix:** answers submitted after time is up are not counted
- **ANSI colors are enabled automatically** on Windows consoles that need it

---

## 🎯 Games

| # | Game | Type | Highlights |
|---|------|------|-----------|
| 1 | Rock Paper Scissors | Luck | Win / loss / draw tracking, win probability |
| 2 | Number Guessing | Luck | 1-in-5 odds, session statistics |
| 3 | Math Challenge | Skill | 6 levels + Time Challenge, vanishing equations |
| 4 | Hangman | Word | 4 categories, ASCII gallows, one hint per word |
| 5 | Tic-Tac-Toe | Strategy | Easy, Medium and Unbeatable (minimax) AI |
| 6 | Snake | Real-time | Arrow keys / WASD, speed levels, timed bonus food |
| 7 | Memory Master | Memory | Flashing digit sequences, 3 lives, 3 difficulties |
| 8 | Blackjack | Cards | Hit, Stand, Double Down, 3:2 blackjack payout |

### 1. Rock Paper Scissors 🪨📄✂️

- Computer picks randomly (1-3)
- Tracks wins, losses and draws, with win probability
- Shows who is currently ahead

### 2. Number Guessing 🔢

- Guess a number from 1 to 5
- Tracks win/loss and win percentage

### 3. Math Challenge 🧮

| Level | Operands | Operators | Rule |
|-------|----------|-----------|------|
| **Noob** | 2 (1-10) | +, - | No time limit |
| **Beginner** | 2 (5-15) | +, -, *, / | No time limit |
| **Intermediate** | 2 (10-20) | +, -, *, /, % | No time limit |
| **Advance** | 2 (10-30) | All 5 | Equation vanishes after 3 s |
| **Pro** | 2 (10-30) | All 5 | Equation revealed piece by piece, then vanishes; answer within 5 s |
| **Grand Master** | 3 (10-30), as `( a op b ) op c` | All 5 | Same reveal; answer within 5 s |
| **Time Challenge** | 2 (1-15) | All 5 | You choose the time limit |

> Division is integer division (the remainder is dropped), and `%` is the remainder.

Each level reports total games, wins, losses, win percentage, average response time and a feedback message.

### 4. Hangman 🪢

- Categories: Animals, Countries, Tech, Food, or a random surprise
- 6 lives with an ASCII gallows that updates on every mistake
- Type `?` once per word for a hint (reveals a letter, costs 1 life, never your last life)
- Used letters are colored green (in the word) or red (not in the word)

### 5. Tic-Tac-Toe ❌⭕

| Level | Computer behavior |
|-------|-------------------|
| **Easy** | Random moves |
| **Medium** | Takes a win, blocks your win, otherwise random |
| **Unbeatable** | Full minimax search, picks randomly among equally good moves |

You play `X` and enter cells 1-9. The player who starts alternates every round, and the score is kept across rounds.

### 6. Snake 🐍

- Real-time play on a 30 x 18 board
- Eat `()` for **+10** points and grow
- A timed `$$` bonus appears every 5 foods for **+30**
- The snake speeds up as it grows
- The whole frame is drawn in a single write, so there is no flicker
- Best score is remembered for the session

| Key | Action |
|-----|--------|
| `W A S D` / Arrow keys | Steer |
| `P` | Pause / resume |
| `Q` | Quit to menu |

### 7. Memory Master 🧠

Digits flash one at a time, then you type the whole sequence back (spaces are optional).

| Difficulty | Flash time | Score multiplier |
|------------|-----------|------------------|
| Easy | 900 ms | x1 |
| Medium | 600 ms | x2 |
| Hard | 350 ms | x3 |

Every correct round adds one digit. A wrong answer costs a life and repeats the same pattern. You have 3 lives and the game ends at round 30.

### 8. Blackjack 🃏

- Start with **500 chips**; bet `0` to leave the table
- Blackjack pays **3:2**; the dealer stands on 17
- Actions: **Hit**, **Stand**, **Double Down** (first move only)
- Proper shuffled 52-card deck, with the dealer's cards revealed one by one
- Red cards (hearts and diamonds) are shown in red

---

## ✨ Features

### 🎨 Console Graphics
- ANSI colors throughout the interface
- Blinking exit animation, countdown alerts and gradual equation reveal
- Flicker-free Snake rendering using cursor positioning

### ⏱️ Timing System
- Millisecond-accurate answer timing (`GetTickCount()`)
- Untimed practice, 3-second vanishing equations, 5-second limits and custom time challenges

### 📊 Analytics
- Per-session win / loss tracking in every game
- Average response time and win percentage in the Math Challenge
- Best scores kept for Snake and Memory Master during the session

### 🛡️ Input Handling
- A single `readInt()` helper validates every numeric menu input
- Letters, empty input and out-of-range values are rejected with a message instead of crashing or looping

---

## 🏗️ Technical Architecture

```
Game-Arena.c
├── Includes: stdio, stdlib, string, ctype, time, conio, windows
├── Helpers: readInt, readLine, banner, clr, blinkalert, blinkterminate
├── Game 1  rpsGame()          Rock Paper Scissors
├── Game 2  guessGame()        Number Guessing
├── Game 3  mathChallenge()    Menu for levels 1-6 and Time Challenge
│           playMath()         One data-driven function for all levels
│           timeChallenge()    Custom time limit mode
├── Game 4  hangmanGame()
├── Game 5  tttGame()          tttAI() + minimax()
├── Game 6  snakeGame()        Real-time loop with _kbhit() / _getch()
├── Game 7  memoryGame()
├── Game 8  blackjackGame()    Deck, hand value (soft aces), dealer logic
└── main()  Main menu
```

The Math Challenge levels are described by a small `Level` struct (operand range, operator count, number of operands, reveal mode, time limit), so adding a new level is a single table entry.

---

## 💻 Installation

### System Requirements

| Component | Requirement |
|-----------|-------------|
| **OS** | Windows 7 / 8 / 10 / 11 |
| **Compiler** | GCC (MinGW / TDM-GCC) or Dev-C++ |
| **Terminal** | Windows Terminal or `cmd` (ANSI colors) |

> The game uses `windows.h`, `conio.h` and `system("cls")`, so it targets Windows only.

### Compile

#### GCC (MinGW)
```bash
gcc Game-Arena.c -o game_arena.exe -Wall -Wextra
./game_arena.exe
```

#### Dev-C++
1. Open `Game-Arena.c`
2. Press **F11** (Compile & Run)
3. If colors look garbled (`←[93m`), run the `.exe` from Windows Terminal or `cmd` instead of Dev-C++'s own console window

#### VS Code
```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "Compile Gaming Hub",
            "command": "gcc",
            "args": ["-g", "Game-Arena.c", "-o", "game_arena.exe"]
        }
    ]
}
```

---

## 📖 Usage Guide

### Quick Start

1. Launch `game_arena.exe`
2. Answer the first prompt:
   ```
   Do you want to play?
   1. Yes   2. No
   ```
3. Pick a game from the main menu:
   ```
   =========== GAME ARENA ===========
   1. ROCK PAPER SCISSORS
   2. NUMBER GUESSING
   3. MATH CHALLENGE
   4. HANGMAN
   5. TIC-TAC-TOE
   6. SNAKE
   7. MEMORY MASTER
   8. BLACKJACK
   9. EXIT
   ```

### Navigation

| Action | Input |
|--------|-------|
| Choose a menu item | Type the number, then **Enter** |
| Leave a game for the main menu | The "Main Menu" option in that game's menu |
| Exit the program | `9` in the main menu (or Exit inside a game menu) |

### Sample: Hangman

```
+--------------------------------------+
|               HANGMAN                |
+--------------------------------------+
Category: ANIMALS   Lives: 4   Hints: 1

  +---+
  |   |
  O   |
 /|   |
      |
      |
=========

  P E N G _ I N

Used: P E N G I N A T
Guess a letter (? = hint):
```

### Sample: Tic-Tac-Toe

```
  You: X   Computer: O   [Unbeatable]

         X | 2 | 3
        ---+---+---
         4 | O | 6
        ---+---+---
         7 | 8 | 9

Your move (1-9):
```

### Sample: Blackjack

```
Chips: 500   Bet: 50

Dealer: [KS] [??]  (showing 10)

You:    [8H] [7C]  = 15

1. Hit  2. Stand  3. Double
Your move:
```

---

## 🗺️ Roadmap

### Done in 2.0
- [x] Tic-Tac-Toe
- [x] Hangman
- [x] Snake, Memory Master and Blackjack
- [x] Safe input handling and millisecond timing

### Next Up
- [ ] High score persistence (file I/O)
- [ ] Two-player mode for Tic-Tac-Toe and Hangman
- [ ] Configuration file for settings
- [ ] Achievement system and daily challenges
- [ ] Power and square-root operators in the Math Challenge

### Future Ideas
- [ ] Linux / macOS support (replace `windows.h` and `conio.h`)
- [ ] Online leaderboards
- [ ] Network multiplayer

---

## 🤝 Contributing

Suggestions and feedback are welcome!

1. Fork the repository
2. Create a feature branch
3. Submit a pull request with a clear description of your changes

---

## 📄 License

Copyright (C) 2026 Rahul Manna

This program is free software: you can redistribute it and/or modify it under the terms of the **GNU General Public License** as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details: <https://www.gnu.org/licenses/>.

---

## 📞 Contact

**Rahul Manna**

| Platform | Handle |
|----------|--------|
| **GitHub** | [@rahul-the-phoenix](https://github.com/rahul-the-phoenix) |
| **Email** | rahulmanna3892@gmail.com |
| **Project** | Ultimate Gaming Hub |

---

<div align="center">

### Made with 💻 and ❤️ by Rahul Manna

**Ultimate Gaming Hub - Where Skills Meet Thrills!** 🚀

[Report Bug](https://github.com/rahul-the-phoenix/ultimate-gaming-hub/issues) · [Request Feature](https://github.com/rahul-the-phoenix/ultimate-gaming-hub/issues)

</div>
