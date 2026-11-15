<div align="center">

# 🎮 Game Arena

### Ultimate Gaming Hub — a colorful, 8-in-1 console game platform written in pure C

<br>

![Version](https://img.shields.io/badge/version-2.0.0-blue?style=for-the-badge)
![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)
![Platform](https://img.shields.io/badge/platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![Language](https://img.shields.io/badge/language-C89-orange?style=for-the-badge&logo=c&logoColor=white)
![Games](https://img.shields.io/badge/games-8-brightgreen?style=for-the-badge)

<br>

[**Overview**](#-overview) ·
[**Screenshots**](#-screenshots) ·
[**Games**](#-games) ·
[**Features**](#-features) ·
[**Install**](#-installation) ·
[**Usage**](#-usage-guide) ·
[**Roadmap**](#%EF%B8%8F-roadmap) ·
[**Contact**](#-contact)

</div>

---

## 🚀 Overview

**Game Arena** is a console gaming platform written in C. Version 2.0 grows the collection from 3 to **8 games**, including a real-time Snake, an unbeatable Tic-Tac-Toe AI, Blackjack, Hangman and a Simon-style memory game, all wrapped in a colorful ANSI interface.

The code is written in plain **C89 style**, so it builds even in old compilers such as Dev-C++.

<div align="center">

| 📏 Lines of Code | 🎲 Games | 🧮 Math Levels | ➕ Operators | 🤖 TTT AI Levels |
|:---:|:---:|:---:|:---:|:---:|
| **1100+** | **8** | **6 + Time Challenge** | **5** (`+ - * / %`) | **3** |

</div>

---

## 📸 Screenshots

<div align="center">

<table>
  <tr>
    <td align="center" width="33%">
      <img src="assets/Screenshot%20%28555%29.png" alt="Start screen"><br>
      <sub><b>🚪 Start screen</b></sub>
    </td>
    <td align="center" width="33%">
      <img src="assets/Screenshot%20%28556%29.png" alt="Main menu"><br>
      <sub><b>📋 Main menu</b></sub>
    </td>
    <td align="center" width="33%">
      <img src="assets/Screenshot%20%28560%29.png" alt="Math Challenge level select"><br>
      <sub><b>🧮 Math — level select</b></sub>
    </td>
  </tr>
  <tr>
    <td align="center" width="33%">
      <img src="assets/Screenshot%20%28561%29.png" alt="Math Challenge gameplay"><br>
      <sub><b>🧮 Math — gameplay</b></sub>
    </td>
    <td align="center" width="33%">
      <img src="assets/Screenshot%20%28559%29.png" alt="Hangman"><br>
      <sub><b>🪢 Hangman</b></sub>
    </td>
    <td align="center" width="33%">
      <img src="assets/Screenshot%202026-11-15%20201549.png" alt="Tic-Tac-Toe board"><br>
      <sub><b>❌ Tic-Tac-Toe — board</b></sub>
    </td>
  </tr>
  <tr>
    <td align="center" width="33%">
      <img src="assets/Screenshot%202026-11-15%20201614.png" alt="Tic-Tac-Toe win screen"><br>
      <sub><b>🏆 Tic-Tac-Toe — win</b></sub>
    </td>
    <td align="center" width="33%">
      <img src="assets/Screenshot%20%28557%29.png" alt="Snake gameplay"><br>
      <sub><b>🐍 Snake — gameplay</b></sub>
    </td>
    <td align="center" width="33%">
      <img src="assets/Screenshot%20%28558%29.png" alt="Snake long run"><br>
      <sub><b>🐍 Snake — score &amp; length</b></sub>
    </td>
  </tr>
</table>

</div>

---

## 🆕 What's New in 2.0

- 🎲 **5 new games:** Hangman, Tic-Tac-Toe, Snake, Memory Master and Blackjack
- 🛡️ **Safe input everywhere:** typing letters instead of numbers no longer breaks a menu
- ⏱️ **Millisecond timing** via `GetTickCount()` (the old `difftime()` timer only had 1-second resolution)
- 🧹 **Math Challenge refactor:** the six levels share one function, cutting hundreds of duplicated lines
- ⚖️ **Fairer timed levels:** the Pro and Grand Master timer now starts when the answer prompt appears, not before the 3-second vanish alert
- 🐞 **Time Challenge fix:** answers submitted after time is up are not counted
- 🎨 **ANSI colors are enabled automatically** on Windows consoles that need it

---

## 🎯 Games

| # | Game | Type | Highlights |
|:-:|------|:----:|------------|
| 1 | 🪨 Rock Paper Scissors | 🍀 Luck | Win / loss / draw tracking, win probability |
| 2 | 🔢 Number Guessing | 🍀 Luck | 1-in-5 odds, session statistics |
| 3 | 🧮 Math Challenge | 🧠 Skill | 6 levels + Time Challenge, vanishing equations |
| 4 | 🪢 Hangman | 🔤 Word | 4 categories, ASCII gallows, one hint per word |
| 5 | ❌ Tic-Tac-Toe | ♟️ Strategy | Easy, Medium and Unbeatable (minimax) AI |
| 6 | 🐍 Snake | ⚡ Real-time | Arrow keys / WASD, speed levels, timed bonus food |
| 7 | 🧠 Memory Master | 💭 Memory | Flashing digit sequences, 3 lives, 3 difficulties |
| 8 | 🃏 Blackjack | 🎴 Cards | Hit, Stand, Double Down, 3:2 blackjack payout |

<br>

### 1. Rock Paper Scissors 🪨📄✂️

- Computer picks randomly (1-3)
- Tracks wins, losses and draws, with win probability
- Shows who is currently ahead

### 2. Number Guessing 🔢

- Guess a number from 1 to 5
- Tracks win/loss and win percentage

### 3. Math Challenge 🧮

<div align="center">
<img src="assets/Screenshot%20%28560%29.png" alt="Math Challenge level select" width="48%">
<img src="assets/Screenshot%20%28561%29.png" alt="Math Challenge gameplay" width="48%">
</div>

<br>

| Level | Operands | Operators | Rule |
|-------|----------|-----------|------|
| 🟢 **Noob** | 2 (1-10) | `+` `-` | No time limit |
| 🔵 **Beginner** | 2 (5-15) | `+` `-` `*` `/` | No time limit |
| 🟣 **Intermediate** | 2 (10-20) | `+` `-` `*` `/` `%` | No time limit |
| 🟡 **Advance** | 2 (10-30) | All 5 | Equation vanishes after 3 s |
| 🔴 **Pro** | 2 (10-30) | All 5 | Equation revealed piece by piece, then vanishes; answer within 5 s |
| 👑 **Grand Master** | 3 (10-30), as `( a op b ) op c` | All 5 | Same reveal; answer within 5 s |
| ⏳ **Time Challenge** | 2 (1-15) | All 5 | You choose the time limit |

> 💡 Division is integer division (the remainder is dropped), and `%` is the remainder.

Each level reports total games, wins, losses, win percentage, average response time and a feedback message.

### 4. Hangman 🪢

<div align="center">
<img src="assets/Screenshot%20%28559%29.png" alt="Hangman gameplay" width="80%">
</div>

<br>

- Categories: Animals, Countries, Tech, Food, or a random surprise
- 6 lives with an ASCII gallows that updates on every mistake
- Type `?` once per word for a hint (reveals a letter, costs 1 life, never your last life)
- Used letters are colored green (in the word) or red (not in the word)

### 5. Tic-Tac-Toe ❌⭕

<div align="center">
<img src="assets/Screenshot%202026-11-15%20201549.png" alt="Tic-Tac-Toe board" width="48%">
<img src="assets/Screenshot%202026-11-15%20201614.png" alt="Tic-Tac-Toe win screen" width="48%">
</div>

<br>

| Level | Computer behavior |
|-------|-------------------|
| 😴 **Easy** | Random moves |
| 🙂 **Medium** | Takes a win, blocks your win, otherwise random |
| 😈 **Unbeatable** | Full minimax search, picks randomly among equally good moves |

You play `X` and enter cells 1-9. The player who starts alternates every round, and the score is kept across rounds.

### 6. Snake 🐍

<div align="center">
<img src="assets/Screenshot%20%28557%29.png" alt="Snake gameplay" width="48%">
<img src="assets/Screenshot%20%28558%29.png" alt="Snake long run" width="48%">
</div>

<br>

- Real-time play on a 30 x 18 board
- Eat `()` for **+10** points and grow
- A timed `$$` bonus appears every 5 foods for **+30**
- The snake speeds up as it grows
- The whole frame is drawn in a single write, so there is no flicker
- Best score is remembered for the session

| Key | Action |
|-----|--------|
| `W` `A` `S` `D` / Arrow keys | Steer |
| `P` | Pause / resume |
| `Q` | Quit to menu |

### 7. Memory Master 🧠

Digits flash one at a time, then you type the whole sequence back (spaces are optional).

| Difficulty | Flash time | Score multiplier |
|------------|:----------:|:----------------:|
| 🟢 Easy | 900 ms | x1 |
| 🟡 Medium | 600 ms | x2 |
| 🔴 Hard | 350 ms | x3 |

Every correct round adds one digit. A wrong answer costs a life and repeats the same pattern. You have 3 lives and the game ends at round 30.

### 8. Blackjack 🃏

- Start with **500 chips**; bet `0` to leave the table
- Blackjack pays **3:2**; the dealer stands on 17
- Actions: **Hit**, **Stand**, **Double Down** (first move only)
- Proper shuffled 52-card deck, with the dealer's cards revealed one by one
- Red cards (hearts and diamonds) are shown in red

---

## ✨ Features

<table>
  <tr>
    <td width="50%" valign="top">

### 🎨 Console Graphics
- ANSI colors throughout the interface
- Blinking exit animation, countdown alerts and gradual equation reveal
- Flicker-free Snake rendering using cursor positioning

    </td>
    <td width="50%" valign="top">

### ⏱️ Timing System
- Millisecond-accurate answer timing (`GetTickCount()`)
- Untimed practice, 3-second vanishing equations, 5-second limits and custom time challenges

    </td>
  </tr>
  <tr>
    <td valign="top">

### 📊 Analytics
- Per-session win / loss tracking in every game
- Average response time and win percentage in the Math Challenge
- Best scores kept for Snake and Memory Master during the session

    </td>
    <td valign="top">

### 🛡️ Input Handling
- A single `readInt()` helper validates every numeric menu input
- Letters, empty input and out-of-range values are rejected with a message instead of crashing or looping

    </td>
  </tr>
</table>

---

## 🏗️ Technical Architecture

```
game_arena.c
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
| 🖥️ **OS** | Windows 7 / 8 / 10 / 11 |
| 🔧 **Compiler** | GCC (MinGW / TDM-GCC) or Dev-C++ |
| 💬 **Terminal** | Windows Terminal or `cmd` (ANSI colors) |

> ⚠️ The game uses `windows.h`, `conio.h` and `system("cls")`, so it targets **Windows only**.

### Get the code

```bash
git clone https://github.com/rahul-the-phoenix/C-Game-Arena.git
cd C-Game-Arena
```

### Compile & run

<details open>
<summary><b>🔹 GCC (MinGW)</b></summary>

```bash
gcc game_arena.c -o game_arena.exe -Wall -Wextra
./game_arena.exe
```

</details>

<details>
<summary><b>🔹 Dev-C++</b></summary>

1. Open `game_arena.c`
2. Press **F11** (Compile & Run)
3. If colors look garbled (`←[93m`), run the `.exe` from Windows Terminal or `cmd` instead of Dev-C++'s own console window

</details>

<details>
<summary><b>🔹 VS Code</b></summary>

```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "Compile Game Arena",
            "command": "gcc",
            "args": ["-g", "game_arena.c", "-o", "game_arena.exe"]
        }
    ]
}
```

</details>

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

### Sample screens

<details>
<summary><b>🪢 Hangman</b></summary>

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

</details>

<details>
<summary><b>❌ Tic-Tac-Toe</b></summary>

```
  You: X   Computer: O   [Unbeatable]

         X | 2 | 3
        ---+---+---
         4 | O | 6
        ---+---+---
         7 | 8 | 9

Your move (1-9):
```

</details>

<details>
<summary><b>🃏 Blackjack</b></summary>

```
Chips: 500   Bet: 50

Dealer: [KS] [??]  (showing 10)

You:    [8H] [7C]  = 15

1. Hit  2. Stand  3. Double
Your move:
```

</details>

---

## 🗺️ Roadmap

**✅ Done in 2.0**
- [x] Tic-Tac-Toe
- [x] Hangman
- [x] Snake, Memory Master and Blackjack
- [x] Safe input handling and millisecond timing

**🔜 Next Up**
- [ ] High score persistence (file I/O)
- [ ] Two-player mode for Tic-Tac-Toe and Hangman
- [ ] Configuration file for settings
- [ ] Achievement system and daily challenges
- [ ] Power and square-root operators in the Math Challenge

**💭 Future Ideas**
- [ ] Linux / macOS support (replace `windows.h` and `conio.h`)
- [ ] Online leaderboards
- [ ] Network multiplayer

---

## 🤝 Contributing

Suggestions and feedback are welcome!

1. 🍴 Fork the repository
2. 🌿 Create a feature branch
3. 📬 Submit a pull request with a clear description of your changes

---

## 📄 License

Distributed under the **MIT License**. See [`LICENSE`](LICENSE) for the full text.

Copyright © 2026 Rahul Manna

---

## 📞 Contact

**Rahul Manna**

| Platform | Handle |
|----------|--------|
| 🐙 **GitHub** | [@rahul-the-phoenix](https://github.com/rahul-the-phoenix) |
| 📧 **Email** | rahulmanna3892@gmail.com |
| 🎮 **Project** | Game Arena (Ultimate Gaming Hub) |

---

<div align="center">

### Made with 💻 and ❤️ by Rahul Manna

**Game Arena — Where Skills Meet Thrills!** 🚀

[🐞 Report Bug](https://github.com/rahul-the-phoenix/C-Game-Arena/issues) · [✨ Request Feature](https://github.com/rahul-the-phoenix/C-Game-Arena/issues)

⭐ *If you enjoyed it, drop a star on the repo!* ⭐

</div>
