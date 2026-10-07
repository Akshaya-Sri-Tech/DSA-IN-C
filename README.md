# DSA-IN-C

This repository follows a two-layer structure:

- ADT layer: reusable implementations under `ADT/`
- Practice layer: numbered folders for problem-solving programs that use those ADTs

## Repository structure

- `ADT/00_Tree/` contains BST and threaded tree implementations
- `ADT/01_Linked_List/` contains singly, doubly, circular, and sorted linked-list implementations
- `ADT/02_Stack/` contains integer and character stacks
- `ADT/03_Queue/` contains integer and character queues
- `00_Tree/`, `01_Linked_List/`, `02_Stack/`, `03_Queue/`, `04_Sorting/`, `05_Recursion/`, and `06_Polynomials/` contain practice questions only

## Compile a practice question with its ADT

Example:

```bash
gcc 02_Stack/balanced_brackets.c ADT/02_Stack/char_stack.c -o balanced_brackets
```

```bash
gcc 00_Tree/bst_operations.c ADT/00_Tree/bst.c -o bst_operations
```

This keeps the reusable data-structure code separate from the problem-solving logic.
