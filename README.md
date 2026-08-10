# ✊✋✌️ Rock Paper Scissors — C++ Console Game

A clean, interactive console-based Stone Paper Scissors game written in C++. Play multiple rounds against the computer, track your score, and see who wins the final match!

## ✨ Features

- 🎮 **Multi-round gameplay** — choose between 1 and 10 rounds per game
- 🤖 **Random computer moves** — powered by `rand()` seeded with system time
- 🏆 **Round-by-round results** — see who wins each round instantly
- 🎨 **Dynamic console colors** — green for player win, red for computer win, yellow for draw
- 📊 **Final scoreboard** — full summary with total wins, losses, and draws
- 🔄 **Play again option** — restart without closing the terminal
- ✅ **Input validation** — handles invalid choices gracefully

## 📁 Project Structure

-Stone-Paper-Scissors/
-├── main.cpp         # Full game source code
-└── README.md        # Project documentation

## Concepts Applied

- Enumerations (`enum`)
- Structures (`struct`)
- Functions and modular design
- Random number generation
- Loop control
- Conditional logic
- Basic console UI

---

## 🕹️ How the Game Works

1. The player selects a choice:
    - 1 → Stone
    - 2 → Paper
    - 3 → Scissor

2. The computer randomly selects its move.
3. The program compares both choices and determines the winner of the round.
4. The game tracks:
    - Player wins
    - Computer wins
    - Draws
5. After all rounds finish, the final winner is displayed along with the full game summary.

---

## 🖥️ Example Gameplay

Round [1] begins:

Your Choice: [1]:Stone, [2]:Paper, [3]:Scissor? 1

Player1 Choice : Stone Computer Choice: Paper Round Winner : [Computer]

---

## 🛠️ Tech Stack

- Language: C++
- Paradigm: Structured Programming
- Libraries Used:
    - `<iostream>`
    - `<cstdlib>`
    - `<ctime>`

---

## 🚀 Learning Outcomes

Through this project I practiced:

- Designing structured console applications
- Separating logic into reusable functions
- Managing game state using structs
- Improving program readability and organization
