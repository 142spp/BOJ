---
name: boj-optimize
description: Solve and improve competitive programming (PS) tasks in C++ across major categories (greedy, DP, graph, shortest path, binary search, data structures, math, implementation). Use when a user asks to debug or optimize an existing `.cpp`, generate an `_opt.cpp`, and especially when the original file contains a problem statement comment that must be summarized first, followed by approach selection, code-reuse judgment, and heavily annotated final code.
---

# BOJ PS General Solver

Apply this workflow for general Baekjoon/PS tasks.

## Workflow

1. Read the original source file and parse the top problem comment first.
2. Summarize the problem in short form: goal, input/output, and critical constraints.
3. Inspect the user's current code and infer intent, complexity, and likely failure points.
4. Decide whether the current approach is algorithmically correct for constraints.
5. Choose an algorithmic direction by category:
- Greedy
- Dynamic Programming
- Graph traversal or shortest path
- Binary search or parametric search
- Data structures (stack, queue, heap, union-find, segment tree)
- Math or simulation
6. Reuse-first rule:
- If the user's approach is correct and complexity fits, keep the same approach and refactor/optimize their structure.
- If the user's approach is incorrect or too slow, switch to a correct approach and state the reason briefly.
7. Explain only the required level of detail:
- Hint-only mode: point out root causes, boundary cases, and counterexamples without giving full final code.
- Full-fix mode: implement a correct and efficient solution directly.
8. When optimization is requested, create `<problem>_opt.cpp` with iterative and memory-efficient logic.
9. Do not modify the original source file when generating an `_opt.cpp` file unless the user explicitly asks to edit both.
10. Add detailed comments in the generated code:
- Explain what each major block does.
- Explain why the algorithm is correct.
- Explain complexity and key edge-case handling.
11. Compile and run at least one representative test before finishing.

## Debugging Checklist

- Verify index bounds and off-by-one errors.
- Verify base cases and termination conditions.
- Verify integer overflow risk (`int` vs `long long`).
- Verify sorting/order assumptions before greedy or binary search.
- Verify DP state definition, transition, and initialization.
- Verify graph direction, visited handling, and stale-priority-queue entries.
- Verify corner inputs (`N=1`, minimum/maximum constraints, duplicates, disconnected cases).

## Optimization Rules

- Replace unnecessary recursion with iterative loops if stack depth or overhead is a risk.
- Remove redundant copies by passing containers as `const &`.
- Keep complexity aligned with constraints (`O(N log N)`, `O(N)`, etc.).
- Use fast I/O for large input sizes.

## Commenting Rules

- Write comments in enough detail for a learner to follow the full logic.
- Include both "what this block does" and "why this is valid/correct".
- Add top block comments with problem summary, I/O, constraints, and reasoning when writing `_opt.cpp`.
- Keep comments accurate and tied to the current problem (avoid generic filler text).

## Response Rules

- Stay concise and practical.
- Respect user instruction style (hint-only vs full solution).
- Prioritize correctness, complexity fit, and reproducible verification output.
