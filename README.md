🏆 Sports Tournament Score Analyzer (Hybrid Mode)
📖 Project Overview

The Sports Tournament Score Analyzer is a Python-based program that allows users to simulate, analyze, and visualize sports tournament results. It supports multiple sports and provides a flexible hybrid mode to use randomly generated scores, manual input, or CSV files.

The project demonstrates the use of Python libraries:

pandas → for storing and managing match data

numpy → for statistical calculations

matplotlib → for visualizing team performance

random → for generating random match results

⚙️ Features

Menu-Driven Interface: Select sports and data input mode interactively.

Hybrid Data Modes:

Randomly generate match scores

Enter real scores manually

Load match data from CSV files

Automatic Analysis:

Calculate match winners

Compute average, highest, and lowest scores

Identify the top-performing team

Visualization:

Bar chart showing total scores per team

Pie chart displaying win percentages

Restart Option: After analysis, users can choose to analyze more scores without restarting the program.

🏅 Supported Sports

Cricket

Football

Volleyball

Badminton

📁 Project Files

sports_analyzer.py → Main Python program

cricket.csv → Sample random cricket match scores

football.csv → Sample random football match scores

volleyball.csv → Sample random volleyball match scores

badminton.csv → Sample random badminton match scores

💻 How to Run

Make sure Python is installed (Python 3.x recommended).

Install required libraries if not already installed:

pip install pandas numpy matplotlib


Place all CSV files in the same directory as sports_analyzer.py.

Run the program:

python sports_analyzer.py


Follow the on-screen menu to select a sport and data input mode.

📊 Output

A table of match results displayed in the console.

Bar chart showing total team scores.

Pie chart showing win percentages.

Interactive menu to analyze more matches.

📌 Notes

The project is designed for educational purposes and demonstrates Python data analysis and visualization skills.

Users can modify the CSV files or add more teams to simulate larger tournaments.
