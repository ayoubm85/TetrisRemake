# 🎮 Tetris Project

## 📚 Description
This project is an implementation of the classic **Tetris** game using **C++** and the **SFML** library for graphics and user inputs.

## 🚀 Features
- 🎮 **Classic Tetris gameplay**
- 🌊 **Score and level management**
- ⏪ **Progressive acceleration of falling pieces**
- ⏸️ **Pause and resume functionality**
- 🎨 **Custom graphical interface**

## 📋 Prerequisites
To compile and run this project, you will need:
- 🔹 **C++20**
- 🔹 **SFML 3.0.0**
- 🔹 A **C++20-compatible compiler** (GCC, Clang, or Visual Studio)
- 🔹 Proper **library configuration** to link SFML:
    - **Required SFML libraries:**
      - 📦 `sfml-graphics`
      - 📦 `sfml-window`
      - 📦 `sfml-system`

💡 **Ensure SFML is correctly installed on your system.** Refer to the [official SFML documentation](https://www.sfml-dev.org/documentation/) for more details.

## 🛠️ Installation
1. Clone the repository:
    ```sh
    git clone https://github.com/Anis13200/tetrisProject.git
    ```
2. Navigate to the project directory:
    ```sh
    cd tetrisProject
    ```
3. Install SFML:
    - **Windows:** Download SFML from the official site and configure it in Visual Studio.
    - **Linux:** Install SFML via your package manager:
      ```sh
      sudo apt install libsfml-dev
      ```
    - **MacOS:** Use Homebrew:
      ```sh
      brew install sfml
      ```

## ⚙️ Compilation
### ✅ With Visual Studio:
1. Open the solution file in Visual Studio.
2. Configure the **include** and **library directories** for SFML.
3. Build and run the project.

### ✅ With GCC (Command-Line):
1. Ensure SFML is installed and accessible.
2. Compile the project:
    ```sh
    g++ -std=c++20 -o tetris main.cpp Game.cpp Grid.cpp -lsfml-graphics -lsfml-window -lsfml-system
    ```
3. Run the executable:
    ```sh
    ./tetrisProject
    ```

## 🎮 Usage
After compiling and running the game, use the following controls:

🎯 **Controls**
- ⬅️ **Left Arrow**: Move the piece to the left.
- ➡️ **Right Arrow**: Move the piece to the right.
- ⬇️ **Down Arrow**: Accelerate the piece's descent.
- 🔁 **L**: Rotate the piece clockwise.
- 🔄 **J**: Rotate the piece counterclockwise.
- ⏸️ **Space**: Pause, resume, or restart the game.

🏆 **Game Objective**
- Stack the pieces (**Tetriminos**) to form complete horizontal lines.
- The more lines you clear simultaneously, the more points you earn:
    - 1⃣ line: **40 × (level + 1) points**
    - 2⃣ lines: **100 × (level + 1) points**
    - 3⃣ lines: **300 × (level + 1) points**
    - 4⃣ lines: **1200 × (level + 1) points**
- The game speeds up every **10 lines cleared**, making it more challenging.

## 📝 License
This project is licensed under the **MIT License**, meaning you are free to use, modify, and distribute this project as long as you credit the original author.  
Refer to the [LICENSE](LICENSE) file for more details.

## 👥 Authors
- **Anis Gadouche**
- **Ayoub Marfouk**

## 🙌 Acknowledgements
- Special thanks to the **SFML** team for providing a simple and efficient library for 2D graphics.
- Inspired by the original **Tetris game** created by **Alexey Pajitnov** in 1984.

---

🚀 *Made by [Anis Gadouche](https://github.com/Anis13200) & [Ayoub Marfouk](https://github.com/ayoubm85).*
