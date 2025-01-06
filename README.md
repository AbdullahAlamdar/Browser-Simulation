# Browser History Management System

## Description
This project is a **Browser History Management System** implemented in C++. It simulates browser functionality to manage, navigate, and sort through a user's web browsing history. The system uses a custom linked list structure to store URLs and track their visit counts.

## Features
1. **Visit a URL**: 
   - Adds a new URL to the browsing history.
   - Updates visit count if the URL already exists.
   - Clears forward history upon visiting a new URL.
   - Automatically opens the URL in the default web browser.

2. **Move Backward in History**:
   - Moves back by a specified number of steps in the browsing history.
   - Prints the URL after moving backward.
   - Opens the current URL in the default web browser.

3. **Move Forward in History**:
   - Moves forward by a specified number of steps in the browsing history.
   - Prints the URL after moving forward.
   - Opens the current URL in the default web browser.

4. **Most Visited URL**:
   - Determines the URL with the highest visit count.
   - Displays the most visited URL.

5. **Sort by Visit Count**:
   - Sorts the browsing history in descending order of visit counts.
   - Useful for viewing frequently visited URLs.

6. **Display History**:
   - Prints the entire browsing history.

## Class Structure

### `node` Class
Represents a single URL in the browsing history.
- **Attributes**:
  - `url`: The URL string.
  - `visitCount`: Number of times the URL has been visited.
  - `next`: Pointer to the next node in the list.
- **Constructor**:
  - Initializes the URL, sets visit count to 0, and sets `next` to `nullptr`.

### `linkedList` Class
Manages the linked list of nodes representing browsing history.
- **Methods**:
  - `addNode(string url)`: Adds a new node or updates an existing node.
  - `moveBack(int steps)`: Moves backward in history.
  - `moveForward(int steps)`: Moves forward in history.
  - `clearForwardHistory()`: Clears forward history after visiting a new URL.
  - `getCurrentUrl()`: Returns the current URL.
  - `mostVisited()`: Returns the most visited URL.
  - `sortNodesByVisitCount()`: Sorts nodes by visit count.
  - `display()`: Displays all URLs in the history.

### `BrowserHistory` Class
Provides a user-friendly interface to interact with the browsing history.
- **Methods**:
  - `visitUrl(string url)`: Visits a new URL and opens it in the browser.
  - `back(int steps)`: Moves back in history.
  - `forward(int steps)`: Moves forward in history.
  - `most_visited()`: Retrieves the most visited URL.
  - `sort()`: Sorts history by visit count.
  - `disp()`: Displays all URLs.

## File Opening Function
The `openHtmlFile` function opens a URL in the default web browser based on the operating system:
- Windows: Uses `start`.
- Linux: Uses `xdg-open`.
- macOS: Uses `open`.

## How to Run
1. **Compile the Code**:
   ```bash
   g++ -o browser_history browser_history.cpp
   ```
2. **Run the Program**:
   ```bash
   ./browser_history
   ```
3. **Input Prompts**:
   - Enter URLs to visit.
   - Specify steps to move backward or forward in history.

## Example Interaction
```
Enter the 1st URL to visit: https://example.com
Visited: https://example.com
URL visited: https://example.com

Enter the 2nd URL to visit: https://openai.com
Visited: https://openai.com
URL visited: https://openai.com

Enter the number of steps to move back: 1
Moved back to: https://example.com

Enter the number of steps to move forward: 1
Moved forward to: https://openai.com

The most visited site is: https://example.com
Sorted Browsing History:
https://example.com
https://openai.com
```

## Key Points
- The program automatically opens URLs in the default browser.
- Forward history is cleared when visiting a new URL after moving back.
- Sorting is based on visit counts, with the most visited URLs appearing first.

## Future Enhancements
- Add support for deleting specific URLs from history.
- Implement a persistent storage mechanism to save history between sessions.
- Allow importing/exporting history to/from a file.

## Author
- Abdullah
