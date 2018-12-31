#include "stdafx.h"
#include "permutations.h"
#include <iostream>

using namespace std;

permutations::permutations() {}

permutations::~permutations() {}

string permutations::multiply_cycle(string formula) {
    // Sanity check
    if (0 == formula.length())
        return string();

    // Make a copy of the input that we can manipulate
    string working = formula;
    bool* tags = new bool[working.length()]{false};
    bool* tag = &tags[0];

    // A1: Tag all of the left parenthesis and replace each right parenthesis
    // by a tagged copy of the input symbol that follows its matching left parenthesis.
    bool open_paren = false;
    char first_char = '\0';
    for (size_t i = 0; i < working.length(); i++, ++tag) {
        char* c = &working[i];

        if ('(' == *c) {
            open_paren = true;
            *tag = true;
            continue;
        }

        if (')' == *c) {
            *c = first_char;
            *tag = true;
        }

        if (open_paren) {
            open_paren = false;
            first_char = *c;
            continue;
        }
    }

    for (char& c : working) {
        ++tag;
    }

    char start = '\0';
    char current = '\0';
    string output;
    bool set_current = false;
    bool done = false;

    while (!done) {
        done = true;
        tag = tags;
        for (size_t i = 0; i < working.length(); i++, ++tag) {
            const char c = working[i];
            // Check if everything is tagged from the input.
            done &= *tag;

            // A3: Set CURRENT equal to the next element of the formula.
            if (set_current) {
                set_current = false;
                current = c;
                continue;
            }

            // A2: Searching from left to right, find the first untagged element
            // of the input. (If all elements are tagged, the algorithm terminates.) Set START
            // equal to it; output a left parenthesis; output the element; and tag it.
            if ('\0' == current && !*tag) {
                start = c;
                output += '(';
                output += c;
                *tag = true;
                set_current = true;
                continue;
            }

            // A4: Proceed to the right until either reaching the end of the formula, or
            // finding an element equal to CURRENT; in the latter case, tag it and go back
            // to step A3.
            if (c == current) {
                *tag = true;
                set_current = true;
                continue;
            }
        }

        // A5: If CURRENT != START, output CURRENT and go back to step A4 starting again at the left
        // of the formula (thereby continuing the development of a cycle in the output).
        if (start != current) {
            output += current;
            continue;
        }

        // A6: (A complete cycle in the output has been found.) Output a right parenthesis and go back to
        // step A2.
        output += ')';
        current = '\0';
    }

    delete[] tags;
    return output;
}
