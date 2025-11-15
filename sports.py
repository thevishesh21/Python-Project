import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import random

def sport_info(choice):
    if choice == "1":
        return ("Cricket", ["Mumbai", "Chennai", "Bangalore", "Kolkata", "Delhi", "Punjab", "Rajasthan", "Hyderabad"], (120, 220))
    elif choice == "2":
        return ("Volleyball", ["Phoenix", "Thunder", "Lightning", "Storm", "Blaze", "Titans", "Warriors", "Champions"], (15, 25))
    elif choice == "3":
        return ("Badminton", ["A", "B", "C", "D", "E", "F", "G", "H"], (15, 21))
    else:
        return ("Football", ["United", "Liverpool", "Chelsea", "Arsenal", "City", "Tottenham", "Leicester", "Everton"], (0, 5))

def generate_random_matches(team_list, score_range, n=10):
    matches = []
    for i in range(n):
        a, b = random.sample(team_list, 2)
        sa = random.randint(*score_range)
        sb = random.randint(*score_range)
        matches.append({'Match': i+1, 'Team A': a, 'Score A': sa, 'Team B': b, 'Score B': sb})
    return pd.DataFrame(matches)

def enter_manual_matches(team_list, n):
    matches = []
    for i in range(n):
        print(f"--- Match {i+1} ---")
        print("Teams:")
        a = input("Enter Team A name: ")
        b = input("Enter Team B name: ")
        sa = int(input(f"Enter score for {a}: "))
        sb = int(input(f"Enter score for {b}: "))
        matches.append({'Match': i+1, 'Team A': a, 'Score A': sa, 'Team B': b, 'Score B': sb})
    return pd.DataFrame(matches)

def main_menu():
    print("--- Sports Match Analyzer Menu ---")
    print("1. Cricket")
    print("2. Volleyball")
    print("3. Badminton")
    print("4. Football")
    return input("Choose a sport (1-4): ")

def mode_menu():
    print("--- Score Entry Mode ---")
    print("1. Random scores")
    print("2. Manual entry")
    return input("Choose score mode (1-2): ")

# MAIN FLOW
sport_choice = main_menu()
sport_name, teams, score_range = sport_info(sport_choice)
mode_choice = mode_menu()

if mode_choice == "1":
    num_matches = 10  # default for random mode
    df = generate_random_matches(teams, score_range, num_matches)
else:
    num_matches = int(input("How many matches do you want to enter? "))
    df = enter_manual_matches(teams, num_matches)

print(f"You selected: {sport_name}")
print("=== Data Sample ===")
print(df)

# 10 Queries/Operations
print("#1. Shape:", df.shape)
print("#2. Columns:", df.columns.tolist())
print("#3. First 3 rows:", df.head(3))
print("#4. Last 3 rows:", df.tail(3))
print("#5. Describe stats:", df[['Score A', 'Score B']].describe())
print("#6. Mean score:", np.mean(df[['Score A', 'Score B']].values))
print("#7. Max score:", np.max(df[['Score A', 'Score B']].values))
print("#8. Min score:", np.min(df[['Score A', 'Score B']].values))
print("#9. Total matches:", len(df))
all_teams = pd.concat([
    df[['Team A', 'Score A']].rename(columns={'Team A': 'Team', 'Score A': 'Score'}),
    df[['Team B', 'Score B']].rename(columns={'Team B': 'Team', 'Score B': 'Score'})
])
team_totals = all_teams.groupby('Team')['Score'].sum()
print("#10. Total scores per team:", team_totals)
print("#11. Unique teams list:", np.unique(df[['Team A', 'Team B']].values))

# Create side-by-side plots
fig, axs = plt.subplots(1, 2, figsize=(12, 6))

# Bar graph: total scores per team (left)
team_totals.plot(kind='bar', ax=axs[0])
axs[0].set_title(f'Team Total Scores ({sport_name})')
axs[0].set_xlabel('Team')
axs[0].set_ylabel('Total Score')

# Pie chart: Win percentage per team (right)
winners = np.where(df['Score A'] > df['Score B'], df['Team A'], df['Team B'])
win_counts = pd.Series(winners).value_counts()
win_percentages = (win_counts / len(df)) * 100
win_percentages.plot(kind='pie', ax=axs[1], autopct='%1.1f%%', startangle=90)
axs[1].set_title(f'Win Percentage per Team ({sport_name})')
axs[1].set_ylabel('')

plt.tight_layout()
plt.show()