## C++ Simple Stack

This is a simple stack implementation in C++ to get familiar with the language.
It implements a C++ library for a stack data structure, and a main C++ binary
defining a command line prompt to interact with a stack.

## Files

- stack.{h, cpp}
  - Stack implementation using Lists.
- stack_node.{h, cpp}
  - Stack implementation using a Node structure.
- main.cpp
  - Command line prompt binary to interact with a stack.

## Usage

1. Install [Bazel][bazel] 💚
2. Execute binary with
   ```shell
   $ bazel run :main
   ```
3. _(optional)_ Modify `BUILD` file to change stack implementation (node, list).

[bazel]: https://bazel.build/
