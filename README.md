# DSA-IN-C

A hands-on DSA repository focused on **implementing core data structures from scratch in C** and solving problems using those implementations.

## 🧠 Why C?

I use C to build ADTs from the ground up and understand what happens underneath — **pointers, memory allocation, dynamic structures, and core operations**.

The focus is on understanding how **Linked Lists, Stacks, Queues, Trees, and other data structures actually work**, rather than only using pre-built implementations.

I use **C++ for LeetCode and competitive programming**.

**⚙️LeetCode:** https://leetcode.com/u/AkCodeZone/

## Folder Structure

```text
ADT/
├── 00_Tree/          → Reusable tree implementations
├── 01_Linked_List/   → Reusable linked-list implementations
├── 02_Stack/         → Reusable stack implementations
└── 03_Queue/         → Reusable queue implementations

00_Tree/              → Tree practice
01_Linked_List/       → Linked-list practice
02_Stack/             → Stack practice
03_Queue/             → Queue practice
04_Sorting/            → Sorting algorithms
05_Recursion/          → Recursion problems
06_Polynomials/        → Polynomial problems
```

The `ADT/` layer contains the **reusable implementations**. The numbered folders contain **practice problems that include and use those ADTs**, keeping implementation and problem-solving logic separate.

## ⚙️ How to Execute

Compile a practice program together with the ADT it uses:

```bash
gcc 02_Stack/balanced_brackets.c ADT/02_Stack/char_stack.c -o balanced_brackets
```

Run:

```bash
./balanced_brackets
```

On Windows:

```bash
balanced_brackets.exe
```

## Focus

- Implement data structures from scratch
- Understand pointers and memory management
- Build reusable ADTs
- Solve problems using those implementations
- Strengthen DSA fundamentals through low-level implementation
