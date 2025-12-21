<div id="top" align="center">

# 📖 Get Next Line

<em>A 42 School project - Reading lines from file descriptors made simple</em>

<br>

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)
![License](https://img.shields.io/github/license/nicoco23/GetNextLine?style=for-the-badge&color=0080ff)
![Last Commit](https://img.shields.io/github/last-commit/nicoco23/GetNextLine?style=for-the-badge&color=0080ff)

</div>

---

## 📑 Table of Contents

- [🎯 Overview](#-overview)
- [✨ Features](#-features)
- [📂 Project Structure](#-project-structure)
- [🚀 Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Compilation](#compilation)
  - [Usage](#usage)
- [🧪 Testing](#-testing)
- [⚙️ How It Works](#️-how-it-works)
- [💡 Key Concepts](#-key-concepts)
- [🎓 Learning Outcomes](#-learning-outcomes)
- [📝 License](#-license)
- [👤 Author](#-author)

---

## 🎯 Overview

**Get Next Line** is a fundamental project from 42 School that challenges students to create a function capable of reading a line from a file descriptor, regardless of buffer size. This project deepens understanding of:

- Static variables in C
- Dynamic memory allocation
- File descriptor operations
- Buffer management

The goal is to implement a function that returns one line at a time from a file descriptor, handling various buffer sizes efficiently.

---

## ✨ Features

### 📌 Mandatory Part

- ✅ Read and return one line at a time from any file descriptor
- ✅ Handle different `BUFFER_SIZE` values (compile-time parameter)
- ✅ Proper memory management with no leaks
- ✅ Works with files, stdin, and other file descriptors
- ✅ Returns line including the newline character `\n` (if present)
- ✅ Returns `NULL` when EOF is reached or an error occurs

### 🌟 Bonus Part

- ✅ Manage multiple file descriptors simultaneously
- ✅ Each file descriptor maintains its own reading position
- ✅ Switch between different file descriptors without losing progress

---

## 📂 Project Structure

```
GetNextLine/
├── get_next_line.c              # Main function implementation
├── get_next_line.h              # Header file with prototypes
├── get_next_line_utils.c        # Helper functions
├── get_next_line_bonus.c        # Bonus: multi-fd support
├── get_next_line_bonus.h        # Bonus header
├── get_next_line_utils_bonus.c  # Bonus utilities
├── get_next_line.pdf            # Project subject (42 School)
└── test.txt                     # Sample test file
```

### 📄 File Descriptions

| File | Description |
|------|-------------|
| **get_next_line.c** | Core implementation with `read_and_stash`, `extract_line`, and `clean_stash` functions |
| **get_next_line.h** | Header with function prototypes and BUFFER_SIZE definition |
| **get_next_line_utils.c** | Utility functions: `ft_strlen`, `ft_strchr`, `ft_strjoin` |
| **get_next_line_bonus.c** | Enhanced version supporting multiple file descriptors with array of static variables |
| **get_next_line_bonus.h** | Bonus header with OPEN_MAX definition |
| **get_next_line_utils_bonus.c** | Bonus utility functions (identical to mandatory) |
| **get_next_line.pdf** | Official 42 project subject with requirements |
| **test.txt** | Sample text file for testing ("Petit ours brun" lyrics) |

---

## 🚀 Getting Started

### Prerequisites

- GCC or any C compiler
- Make (optional)
- Unix-based system (Linux, macOS) or WSL

### Installation

1. **Clone the repository:**

```bash
git clone https://github.com/nicoco23/GetNextLine.git
cd GetNextLine
```

### Compilation

#### Standard Version

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

#### Bonus Version

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c
```

#### With Different Buffer Sizes

```bash
# Small buffer (slower, more read() calls)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c

# Large buffer (faster, fewer read() calls)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10000 get_next_line.c get_next_line_utils.c main.c
```

### Usage

#### Basic Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

#### Bonus Example (Multiple File Descriptors)

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd1, fd2, fd3;
    char    *line;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    fd3 = open("file3.txt", O_RDONLY);

    // Read alternately from different files
    line = get_next_line(fd1); // Line 1 from file1
    free(line);
    line = get_next_line(fd2); // Line 1 from file2
    free(line);
    line = get_next_line(fd1); // Line 2 from file1 (keeps position!)
    free(line);

    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}
```

---

## 🧪 Testing

### Run Included Tests

```bash
# Test standard version
./a.out

# Expected output: Contents of test.txt printed line by line
```

### Test with Different Buffer Sizes

```bash
# Test with BUFFER_SIZE=1
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 *.c && ./a.out

# Test with BUFFER_SIZE=9999
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 *.c && ./a.out
```

### Memory Leak Testing

```bash
# Compile with debug symbols
cc -g -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c

# Run with valgrind
valgrind --leak-check=full --show-leak-kinds=all ./a.out
```

### Recommended External Testers

- [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
- [xicodomingues/francinette](https://github.com/xicodomingues/francinette)

---

## ⚙️ How It Works

### Architecture

The function is divided into three main operations:

1. **`read_and_stash`**: Reads from fd and accumulates data in a static buffer until `\n` is found or EOF
2. **`extract_line`**: Extracts one complete line from the stash (including `\n`)
3. **`clean_stash`**: Removes the extracted line from stash, keeping remaining data for next call

### Visual Flow

```
┌─────────────────────────────────────────────────────────┐
│  File: "Hello\nWorld\nTest"                             │
└─────────────────────────────────────────────────────────┘
                          │
                          ▼
         ┌────────────────────────────────┐
         │  read_and_stash(fd, stash)     │  ← Read BUFFER_SIZE bytes
         │  Accumulates: "Hello\nWorld\n" │
         └────────────────────────────────┘
                          │
                          ▼
         ┌────────────────────────────────┐
         │  extract_line(stash)           │  ← Extract until \n
         │  Returns: "Hello\n"            │
         └────────────────────────────────┘
                          │
                          ▼
         ┌────────────────────────────────┐
         │  clean_stash(stash)            │  ← Keep remaining data
         │  Stash now: "World\n"          │
         └────────────────────────────────┘
```

---

## 💡 Key Concepts

### 📌 Static Variables

```c
static char *stash;  // Mandatory: single static variable
```
- Preserves data between function calls
- Retains remainder after extracting a line

### 🌟 Bonus: Static Array

```c
static char *stash[OPEN_MAX];  // Bonus: array of stashes
```
- Each file descriptor has its own stash
- Allows reading from multiple files simultaneously

### 🔧 BUFFER_SIZE

The `BUFFER_SIZE` defines how many bytes are read per `read()` call:

- **Small BUFFER_SIZE (1-10)**: More system calls, slower but works
- **Large BUFFER_SIZE (1000+)**: Fewer system calls, faster
- **Does NOT affect the output**: Always returns complete lines

Example with `BUFFER_SIZE=5` reading `"Hello World\n"`:
1. Read: `"Hello"` → no `\n`, store in stash
2. Read: `" Worl"` → no `\n`, append to stash
3. Read: `"d\n"` → found `\n`, return `"Hello World\n"`

---

## 🎓 Learning Outcomes

This project teaches essential C programming concepts:

- ✅ **Memory Management**: Dynamic allocation, avoiding leaks, proper freeing
- ✅ **Static Variables**: Understanding scope and lifetime
- ✅ **File I/O**: Working with file descriptors and `read()` system call
- ✅ **Buffer Management**: Handling data that doesn't fit in a single read
- ✅ **Edge Cases**: EOF, empty lines, invalid fd, read errors
- ✅ **Code Organization**: Modular design with helper functions

---

## 📝 License

This project is part of the 42 School curriculum and follows their academic guidelines.

---

## 👤 Author

**Nicolas Tassin (ntassin)**

- GitHub: [@nicoco23](https://github.com/nicoco23)
- 42 Login: `ntassin`

---

<div align="center">

### ⭐ Don't forget to star this repo if it helped you!

[![Back to Top](https://img.shields.io/badge/-BACK_TO_TOP-151515?style=flat-square)](#top)

</div>
