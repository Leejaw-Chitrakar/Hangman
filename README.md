# Hangman Game in C

A classic, interactive terminal-based Hangman game developed in C. Challenge yourself to guess secret words from various categories using helpful hints!

## 🚀 Features

- **Interactive Gameplay**: Classic letter-by-letter guessing mechanics.
- **Word Hints**: Each word comes with a descriptive hint to aid your guesses.
- **Visual Hangman**: A dynamic text-based hangman figure that evolves with every incorrect guess.
- **Replayability**: Easily start new rounds after winning or losing.
- **Educational**: Great for learning C programming fundamentals like structures, loops, and string manipulation.

## 🛠️ Requirements

- A C compiler (e.g., `gcc`, `clang`, or MSVC).
- Windows environment (uses `conio.h` for `getch()`).

## 📥 Getting Started

### 1. Clone the repository
```bash
git clone https://github.com/Leejaw-Chitrakar/hangman.git
cd hangman
```

### 2. Compile the game
Using `gcc`:
```bash
gcc Hangman.c -o Hangman.exe
```

### 3. Run the game
```bash
./Hangman.exe
```

## 🎮 How to Play

1.  The game selects a secret word and displays it as underscores (`_`).
2.  A **hint** is provided to help you identify the word.
3.  Enter a single letter when prompted.
4.  If the letter is in the word, it will be revealed.
5.  If the letter is **not** in the word, a part of the hangman figure is drawn.
6.  You have a maximum of **6 tries**.
7.  Guess the word before the hangman is complete to win!

## 📂 Project Structure

- `Hangman.c`: The main source code of the game.
- `Hangman.txt`: Detailed breakdown and explanation of the code logic.
- `introduction.txt`: An overview of the game's development and functions.

## 🤝 Contributing

Contributions are welcome! Feel free to open issues or submit pull requests to improve the word list, enhance visuals, or optimize the code.

## 📄 License

This project is open-source and available under the MIT License.
