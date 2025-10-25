================================================================================
SPORTS TOURNAMENT SCORE ANALYZER - LINE-BY-LINE CODE EXPLANATION
================================================================================

SECTION 1: IMPORTS (Lines 1-5)
================================================================================
Lines 1-5: Import required libraries
- pandas: For creating and managing data tables (DataFrames)
- numpy: For numerical calculations on arrays
- matplotlib.pyplot: For creating bar and pie charts
- random: For generating random team names and scores
- os: For checking if CSV files exist before reading


SECTION 2: GENERATE RANDOM MATCHES FUNCTION (Lines 7-35)
================================================================================
Line 7: Function definition - generates random match data based on sport type

Lines 9-12: Cricket configuration
- Creates list of 8 IPL team names
- Sets score range 120-220 (typical cricket T20 scores)

Lines 13-16: Football configuration
- Creates list of 8 Premier League team names
- Sets score range 0-5 (typical football match scores)

Lines 17-21: Volleyball configuration
- Creates list of 8 generic team names
- Sets score range 15-25 (volleyball set scores)

Lines 22-25: Badminton configuration (else block)
- Creates list of 8 player names (individual sport)
- Sets score range 15-21 (badminton game scores)

Line 27: Initialize empty list to store match data

Line 28: Generate random number of matches between 5-8
- random.randint(5, 8) returns a random integer in this range

Lines 30-34: Loop to create each match
- Line 31: random.sample(teams, 2) picks 2 different teams randomly
- Lines 32-33: Generate random scores within the sport's range
- Line 34: Append match data as a list [Match number, Team A, Team B, Score A, Score B]

Line 35: Convert list of matches to pandas DataFrame with column names
- Returns a structured table ready for analysis


SECTION 3: MANUAL DATA ENTRY FUNCTION (Lines 37-51)
================================================================================
Line 37: Function definition - allows user to input match data manually

Line 39: Initialize empty list for storing matches

Lines 40-41: Display prompt and get number of matches from user
- int(input()) converts user's text input to integer

Lines 43-49: Loop through each match
- Line 44: Display which match is being entered
- Lines 45-46: Get team names from user
- Lines 47-48: Get scores from user (converted to integers)
- Line 49: Append complete match data to list

Line 51: Convert list to DataFrame and return
- Same structure as random generation for consistency


SECTION 4: READ FROM CSV FUNCTION (Lines 53-66)
================================================================================
Line 53: Function definition - reads match data from CSV file

Line 55: Create filename by converting sport name to lowercase + .csv
- Example: "Cricket" becomes "cricket.csv"

Lines 57-59: Check if file exists
- os.path.exists() returns True if file is found
- If not found, display error and return None

Lines 61-66: Try to read CSV file with error handling
- Line 62: pd.read_csv() reads CSV and creates DataFrame
- Line 63: Success message
- Line 64: Return the DataFrame
- Lines 65-66: Catch any errors (file corrupted, wrong format, etc.)


SECTION 5: WINNER DETERMINATION FUNCTION (Lines 68-75)
================================================================================
Line 68: Function definition - determines winner for a single match row

Lines 70-75: Compare scores and return winner
- Line 70-71: If Score A > Score B, Team A wins
- Line 72-73: If Score B > Score A, Team B wins
- Line 74-75: Otherwise it's a Draw
- This function is applied to each row of the DataFrame


SECTION 6: DATA ANALYSIS FUNCTION (Lines 77-166)
================================================================================
Line 77: Function definition - performs comprehensive analysis using Pandas/NumPy

Lines 79-81: Print section header with sport name

Line 84: Add 'Winner' column by applying determine_winner to each row
- df.apply(function, axis=1) applies function to each row

Lines 87-89: Display complete DataFrame
- to_string(index=False) shows table without row numbers

Lines 92-94: Print analysis section header

--- PANDAS/NUMPY QUERY 1: Shape ---
Line 97: Get dataset dimensions
- df.shape returns tuple (rows, columns)
- df.shape[0] = number of rows, df.shape[1] = number of columns
Example: (10, 6) means 10 matches, 6 columns

--- PANDAS QUERY 2: Columns ---
Line 100: Get list of all column names
- df.columns returns column names
- list() converts to Python list for display

--- PANDAS QUERY 3: Head ---
Line 103: Display first 3 rows
- df.head(3) returns first 3 rows of DataFrame
- Useful for quick data preview

--- PANDAS QUERY 4: Tail ---
Line 106: Display last 3 rows
- df.tail(3) returns last 3 rows of DataFrame
- Shows most recent matches

--- PANDAS QUERY 5: Describe ---
Line 109: Statistical summary of score columns
- df.describe() generates count, mean, std, min, quartiles, max
- Applied only to 'Score A' and 'Score B' columns

--- NUMPY QUERIES 6-8: Mean, Max, Min ---
Lines 112-114: Calculate statistics using NumPy
- df[['Score A', 'Score B']].values converts DataFrame to NumPy array
- .mean() calculates average of all scores
- .max() finds highest score
- .min() finds lowest score
Example: If scores are [180, 175, 190, 185], mean = 182.5

Lines 116-118: Print calculated statistics with formatting
- {avg_score:.2f} formats to 2 decimal places

--- PANDAS QUERY 9: Length ---
Line 121: Count total matches
- len(df) returns number of rows (matches)

Lines 124-127: Restructure data for team analysis
- pd.concat() combines Team A and Team B data vertically
- rename() standardizes column names to 'Team' and 'Score'
- Creates single list of all team performances

--- PANDAS QUERY 10: GroupBy and Sum ---
Line 130: Calculate total scores per team
- groupby('Team') groups rows by team name
- ['Score'].sum() adds up all scores for each team
- sort_values(ascending=False) orders from highest to lowest
Example: Mumbai Indians played 3 matches scoring 180, 175, 192 → Total = 547

--- NUMPY QUERY 11: Unique ---
Lines 134-135: Find all unique team names
- .values.flatten() converts DataFrame to 1D array
- np.unique() returns sorted array of unique values
- Removes duplicates from team list

--- NUMPY QUERY 12: Count Unique ---
Lines 138-139: Count number of different teams
- len(np.unique()) counts unique teams
Example: If 8 different teams played, returns 8

--- PANDAS QUERY 13: Value Counts ---
Lines 142-143: Count wins per team
- value_counts() counts frequency of each winner
- Shows how many matches each team won
Example: Mumbai Indians: 3, Chennai: 2, Delhi: 1

--- PANDAS QUERY 14: Iloc (Index Location) ---
Lines 146-148: Get top performing team
- team_totals.index[0] gets name of first team (highest total)
- team_totals.iloc[0] gets score of first team
- Works because data is sorted in descending order

Lines 151-159: Print summary section
- Displays all key statistics in organized format
- Uses f-strings for formatting with emojis

Line 161: Return results for visualization
- Returns analyzed DataFrame, team totals, and win counts


SECTION 7: VISUALIZATION FUNCTION (Lines 163-182)
================================================================================
Line 163: Function definition - creates bar and pie charts

Line 165: Create figure with 2 subplots side by side
- plt.subplots(1, 2) creates 1 row, 2 columns
- figsize=(14, 6) sets width=14 inches, height=6 inches
- Returns figure object and two axes (ax1, ax2)

Line 166: Add main title to entire figure

Lines 169-174: Create bar chart (left subplot)
- team_totals.plot(kind='bar') creates vertical bar chart
- ax=ax1 specifies which subplot to use
- color='steelblue' sets bar color
- edgecolor='black' adds black borders to bars
- set_title() adds chart title
- set_xlabel/ylabel() label axes
- tick_params(rotation=45) rotates x-axis labels 45 degrees
- grid() adds horizontal gridlines for easier reading

Lines 177-180: Create pie chart (right subplot)
- plt.cm.Set3() generates color palette
- ax2.pie() creates pie chart
- labels=win_counts.index uses team names as labels
- autopct='%1.1f%%' shows percentages with 1 decimal place
- startangle=90 starts first slice at top
- colors= assigns different color to each slice

Line 182: Display both charts
- plt.tight_layout() automatically adjusts spacing
- plt.show() opens window with charts


SECTION 8: MENU DISPLAY FUNCTIONS (Lines 184-202)
================================================================================
Lines 184-191: Data mode menu
- Shows 4 options: Random, Manual, CSV, Go Back
- Used after sport is selected

Lines 193-202: Main sports menu
- Shows 5 options: 4 sports + Exit
- First menu user sees when program starts


SECTION 9: MAIN PROGRAM LOGIC (Lines 204-258)
================================================================================
Line 204: Function definition - controls entire program flow

Lines 206-211: Create mapping dictionary
- Maps menu choice numbers (strings) to sport names
- Example: '1' → 'Cricket', '2' → 'Football'

Line 213: Start infinite loop for main menu
- while True runs until explicit break
- Allows user to analyze multiple times

Lines 214-215: Display main menu and get user choice
- .strip() removes extra spaces from input

Lines 217-219: Handle exit option
- If choice is '5', print goodbye message and break loop
- Program ends when this executes

Lines 221-223: Validate input
- If choice not in sports_map (not 1-4), show error
- continue skips to next loop iteration (shows menu again)

Line 225: Get sport name from mapping

Line 227: Start inner loop for data mode selection
- Another while True for repeated data mode choices

Lines 228-229: Display data mode menu and get choice

Lines 231-232: Handle "Go Back" option
- If choice is '4', break inner loop
- Returns to main sports menu

Line 234: Initialize df variable as None

Lines 236-246: Process data mode choice
Lines 237-239: Random mode
- Call generate_random_matches()
- Display success message

Lines 240-241: Manual mode
- Call enter_manual_matches()
- User inputs data interactively

Lines 242-243: CSV mode
- Call read_from_csv()
- Reads from file

Lines 244-246: Invalid choice
- Show error and continue to next iteration

Lines 248-258: Process and display results (only if data loaded successfully)
Line 248: Check if DataFrame exists and is not empty

Line 249: Analyze data and create visualizations
- Call analyze_data() to perform all Pandas/NumPy queries
- Call create_visualizations() to show charts

Lines 251-255: Ask if user wants to continue
- Inner while loop ensures valid 'yes' or 'no' input
- .lower() converts input to lowercase for comparison
- Keeps asking until valid input received

Lines 257-260: Handle restart decision
- If 'yes': break inner loop, return to sport selection
- If 'no': print goodbye and return (exits entire program)


SECTION 10: PROGRAM ENTRY POINT (Lines 260-261)
================================================================================
Lines 260-261: Standard Python entry point
- if __name__ == "__main__": checks if script is run directly
- Calls main() to start program
- Prevents automatic execution if file is imported as module


================================================================================
PROGRAM FLOW SUMMARY
================================================================================

1. MENU SYSTEM:
   - Main Menu (Sports Selection) → Data Mode Menu → Processing

2. DATA INPUT MODES:
   - Random: Generates 5-8 matches with random teams/scores
   - Manual: User enters match data through console
   - CSV: Reads pre-existing CSV files

3. DATA ANALYSIS (14 Pandas/NumPy Operations):
   - Shape, Columns, Head, Tail, Describe
   - Mean, Max, Min (NumPy)
   - GroupBy, Sum, Unique, Value Counts, Iloc

4. VISUALIZATION:
   - Bar Chart: Total scores by team
   - Pie Chart: Win distribution percentages

5. RESTART LOOP:
   - After analysis, asks "analyze more scores?"
   - 'yes' → Return to main menu
   - 'no' → Exit program


================================================================================
KEY PANDAS OPERATIONS EXPLAINED WITH EXAMPLES
================================================================================

1. df.head(3) - First 3 rows
   Match         Team A           Team B      Score A  Score B
   Match 1   Mumbai Indians   Chennai SK      185      178
   Match 2   Royal Challengers Kolkata        165      172
   Match 3   Delhi Capitals   Punjab Kings    198      195

2. df.groupby('Team')['Score'].sum()
   Team
   Mumbai Indians        547
   Chennai Super Kings   523
   Delhi Capitals        456

3. df['Winner'].value_counts()
   Mumbai Indians       3
   Chennai Super Kings  2
   Delhi Capitals       1
   Draw                 0

4. df.describe() - Statistical summary
              Score A     Score B
   count      10.00       10.00
   mean      178.50      179.20
   std        16.34       15.67
   min       145.00      142.00
   max       203.00      195.00


================================================================================
END OF EXPLANATION
================================================================================