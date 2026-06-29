# GroceryListCounter

1. Summary of the project and the problem it solved
The Corner Grocer project required building a console-based C++ application that reads a text file containing grocery item names (one item per line), counts the frequency of each item in a case-insensitive way, and gives the user an interactive menu. The menu lets users search for the frequency of a specific item,
print a sorted list of all items with their counts, or display a text-based histogram using asterisks. The program also automatically creates a backup file (frequency.dat) at startup.
The core problem it solved was turning raw, messy purchase data into useful, quickly accessible information for a small grocery store—essentially a lightweight inventory/sales frequency tracker.

3. What I did particularly well
I think the strongest part of my solution was the clean separation of concerns using the GroceryTracker class. All the data loading, frequency counting, searching, printing, and backup logic lives inside the class, while main() only handles the menu loop. This made the code much easier to read and test.
I also handled case-insensitivity correctly with the toLower() helper and properly capitalized the first letter when displaying items. Creating the backup file automatically at program start was a nice touch that met the requirements without extra user steps.

4. Where I could enhance the code
Several improvements would make the program more robust and professional:

Input validation: The menu uses cin >> choice, which can fail or leave the input stream in a bad state if the user types letters. Adding proper validation (or using a safer input method) would prevent crashes or infinite loops.
Use unordered_map for lookups: Since we only need fast frequency checks and don’t strictly require sorted output for every operation, an unordered_map could offer faster average-case performance for very large files (though map is fine for this small dataset).

Configurable file paths: Hard-coding the filenames makes the program less flexible. Passing filenames as command-line arguments or reading them from a config file would make it more adaptable.
Better error handling and logging: More descriptive error messages and possibly logging to a file would improve maintainability in a real-world setting.

These changes would increase reliability, performance for larger datasets, and ease of future modification.

4. Most challenging pieces and how I overcame them
The trickiest parts were:

Correctly stripping the Windows carriage return (\r) when reading lines with getline().
Formatting the histogram neatly with setw() and asterisks while keeping the output aligned.

I overcame these by testing small pieces incrementally, using the Visual Studio debugger to inspect strings, and consulting cppreference.com for std::map and std::setw behavior.

5. Transferable skills
This project strengthened several skills I’ll use again:

Reading and writing text files in C++.
Using STL containers (map) and string manipulation.
Designing a simple menu-driven program with a class.
Creating backup/output files automatically.
Thinking about data cleaning and how to turn messy inputs into useable data.

These skills directly transfer to future projects involving data processing, logging, inventory systems, or any application that needs to read, analyze, and report on text-based data.

6. How I made the program maintainable, readable, and adaptable
I kept the code readable by using clear method names (loadData, getFrequency, printHistogram, createBackupFile) and consistent formatting. I separated concerns so each method has one clear responsibility. The capitalization logic is centralized in the display methods, making it easy to change later.
Adding new menu options or switching the data source would require only small, localized changes. The use of a class instead of global variables also makes the code easier to understand and extend.
