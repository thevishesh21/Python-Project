import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import random
import os

def generate_random_matches(sport):
    """Generate random match data for selected sport"""
    if sport == "Cricket":
        teams = ["Mumbai Indians", "Chennai Super Kings", "Royal Challengers", "Kolkata Knights", 
                 "Delhi Capitals", "Punjab Kings", "Rajasthan Royals", "Sunrisers Hyderabad"]
        score_range = (120, 220)
    elif sport == "Football":
        teams = ["Manchester United", "Liverpool", "Chelsea", "Arsenal", 
                 "Manchester City", "Tottenham", "Leicester", "Everton"]
        score_range = (0, 5)
    elif sport == "Volleyball":
        teams = ["Team Phoenix", "Team Thunder", "Team Lightning", "Team Storm",
                 "Team Blaze", "Team Titans", "Team Warriors", "Team Champions"]
        score_range = (15, 25)
    else:  # Badminton
        teams = ["Player A", "Player B", "Player C", "Player D",
                 "Player E", "Player F", "Player G", "Player H"]
        score_range = (15, 21)
    
    matches = []
    num_matches = random.randint(5, 8)
    
    for i in range(num_matches):
        team_a, team_b = random.sample(teams, 2)
        score_a = random.randint(*score_range)
        score_b = random.randint(*score_range)
        matches.append([f"Match {i+1}", team_a, team_b, score_a, score_b])
    
    return pd.DataFrame(matches, columns=["Match", "Team A", "Team B", "Score A", "Score B"])

def enter_manual_matches(sport):
    """Allow user to enter match data manually"""
    matches = []
    print(f"\n📝 Enter {sport} match data:")
    num_matches = int(input("How many matches do you want to enter? "))
    
    for i in range(num_matches):
        print(f"\n--- Match {i+1} ---")
        team_a = input("Enter Team A name: ")
        team_b = input("Enter Team B name: ")
        score_a = int(input(f"Enter {team_a}'s score: "))
        score_b = int(input(f"Enter {team_b}'s score: "))
        matches.append([f"Match {i+1}", team_a, team_b, score_a, score_b])
    
    return pd.DataFrame(matches, columns=["Match", "Team A", "Team B", "Score A", "Score B"])

def read_from_csv(sport):
    """Read match data from CSV file"""
    filename = f"{sport.lower()}.csv"
    
    if not os.path.exists(filename):
        print(f"\n❌ Error: {filename} not found!")
        return None
    
    try:
        df = pd.read_csv(filename)
        print(f"\n✅ Successfully loaded data from {filename}")
        return df
    except Exception as e:
        print(f"\n❌ Error reading file: {e}")
        return None

def determine_winner(row):
    """Determine winner for each match"""
    if row['Score A'] > row['Score B']:
        return row['Team A']
    elif row['Score B'] > row['Score A']:
        return row['Team B']
    else:
        return "Draw"

def analyze_data(df, sport):
    """Perform Pandas and NumPy analysis"""
    print(f"\n{'='*70}")
    print(f"📊 {sport.upper()} TOURNAMENT ANALYSIS")
    print(f"{'='*70}\n")
    
    # Add Winner column
    df['Winner'] = df.apply(determine_winner, axis=1)
    
    # Display full DataFrame
    print("📋 Complete Match Data:")
    print(df.to_string(index=False))
    print()
    
    # Pandas/NumPy Queries (14 total)
    print(f"{'='*70}")
    print("🔍 STATISTICAL ANALYSIS")
    print(f"{'='*70}\n")
    
    # Query 1: Shape
    print(f"1. Dataset Shape: {df.shape[0]} rows × {df.shape[1]} columns")
    
    # Query 2: Columns
    print(f"2. Columns: {list(df.columns)}")
    
    # Query 3: Head
    print(f"\n3. First 3 Matches:\n{df.head(3).to_string(index=False)}\n")
    
    # Query 4: Tail
    print(f"4. Last 3 Matches:\n{df.tail(3).to_string(index=False)}\n")
    
    # Query 5: Describe
    print(f"5. Score Statistics:\n{df[['Score A', 'Score B']].describe()}\n")
    
    # Query 6-8: Mean, Max, Min
    avg_score = df[['Score A', 'Score B']].values.mean()
    max_score = df[['Score A', 'Score B']].values.max()
    min_score = df[['Score A', 'Score B']].values.min()
    
    print(f"6. Average Score (NumPy): {avg_score:.2f}")
    print(f"7. Highest Score: {max_score}")
    print(f"8. Lowest Score: {min_score}")
    
    # Query 9: Total matches
    total_matches = len(df)
    print(f"9. Total Matches: {total_matches}")
    
    # Create team scores DataFrame
    all_teams = pd.concat([
        df[['Team A', 'Score A']].rename(columns={'Team A': 'Team', 'Score A': 'Score'}),
        df[['Team B', 'Score B']].rename(columns={'Team B': 'Team', 'Score B': 'Score'})
    ])
    
    # Query 10: GroupBy and Sum
    team_totals = all_teams.groupby('Team')['Score'].sum().sort_values(ascending=False)
    print(f"\n10. Total Scores by Team (GroupBy + Sum):\n{team_totals}")
    
    # Query 11: Unique teams
    unique_teams = df[['Team A', 'Team B']].values.flatten()
    print(f"\n11. Unique Teams: {np.unique(unique_teams)}")
    
    # Query 12: Number of unique teams
    num_teams = len(np.unique(unique_teams))
    print(f"12. Number of Unique Teams: {num_teams}")
    
    # Query 13: Value counts for winners
    win_counts = df['Winner'].value_counts()
    print(f"\n13. Win Counts:\n{win_counts}")
    
    # Query 14: Loc - Top team
    top_team = team_totals.index[0]
    top_score = team_totals.iloc[0]
    print(f"\n14. Top Performing Team: {top_team} (Total Score: {top_score})")
    
    # Summary
    print(f"\n{'='*70}")
    print("📈 SUMMARY")
    print(f"{'='*70}")
    print(f"🏆 Total Matches Played: {total_matches}")
    print(f"📊 Average Score: {avg_score:.2f}")
    print(f"🔝 Highest Score: {max_score}")
    print(f"🔻 Lowest Score: {min_score}")
    print(f"🥇 Top Performing Team: {top_team} ({top_score} total points)")
    print(f"{'='*70}\n")
    
    return df, team_totals, win_counts

def create_visualizations(team_totals, win_counts, sport):
    """Create bar and pie charts"""
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))
    fig.suptitle(f'{sport} Tournament Analysis', fontsize=16, fontweight='bold')
    
    # Bar Chart - Team Total Scores
    team_totals.plot(kind='bar', ax=ax1, color='steelblue', edgecolor='black')
    ax1.set_title('Total Scores by Team', fontsize=14, fontweight='bold')
    ax1.set_xlabel('Team', fontsize=12)
    ax1.set_ylabel('Total Score', fontsize=12)
    ax1.tick_params(axis='x', rotation=45)
    ax1.grid(axis='y', alpha=0.3)
    
    # Pie Chart - Win Percentages
    colors = plt.cm.Set3(range(len(win_counts)))
    ax2.pie(win_counts, labels=win_counts.index, autopct='%1.1f%%', 
            startangle=90, colors=colors)
    ax2.set_title('Win Distribution', fontsize=14, fontweight='bold')
    
    plt.tight_layout()
    plt.show()

def data_mode_menu():
    """Display data mode selection menu"""
    print("\n" + "="*50)
    print("Select Data Mode:")
    print("1. Generate Random Scores")
    print("2. Enter Real Scores Manually")
    print("3. Read Scores from CSV File")
    print("4. Go Back")
    print("="*50)

def main_menu():
    """Display main sports menu"""
    print("\n" + "="*50)
    print("🏆 Welcome to Sports Tournament Score Analyzer 🏆")
    print("="*50)
    print("1. Cricket")
    print("2. Football")
    print("3. Volleyball")
    print("4. Badminton")
    print("5. Exit")
    print("="*50)

def main():
    """Main program loop"""
    sports_map = {
        '1': 'Cricket',
        '2': 'Football',
        '3': 'Volleyball',
        '4': 'Badminton'
    }
    
    while True:
        main_menu()
        sport_choice = input("Enter your choice (1-5): ").strip()
        
        if sport_choice == '5':
            print("\nThank you for using the Sports Tournament Score Analyzer! 🏆")
            break
        
        if sport_choice not in sports_map:
            print("\n❌ Invalid choice! Please select 1-5.")
            continue
        
        sport = sports_map[sport_choice]
        
        while True:
            data_mode_menu()
            mode_choice = input("Enter your choice (1-4): ").strip()
            
            if mode_choice == '4':
                break
            
            df = None
            
            if mode_choice == '1':
                df = generate_random_matches(sport)
                print(f"\n✅ Generated random {sport} matches!")
            elif mode_choice == '2':
                df = enter_manual_matches(sport)
            elif mode_choice == '3':
                df = read_from_csv(sport)
            else:
                print("\n❌ Invalid choice! Please select 1-4.")
                continue
            
            if df is not None and not df.empty:
                analyzed_df, team_totals, win_counts = analyze_data(df, sport)
                create_visualizations(team_totals, win_counts, sport)
                
                while True:
                    again = input("\nDo you want to analyze more scores? (yes/no): ").strip().lower()
                    if again in ['yes', 'no']:
                        break
                    print("Please enter 'yes' or 'no'.")
                
                if again == 'yes':
                    break
                else:
                    print("\nThank you for using the Sports Tournament Score Analyzer! 🏆")
                    return

if __name__ == "__main__":
    main()
