#!/usr/bin/env python3
import sys

def remove_special(string):
    s = ""
    for char in string:
        if 48 <= ord(char) <= 57 or 65 <= ord(char) <= 90 or 97 <= ord(char) <= 122:
            s += char
    return s

for line in sys.stdin:
    for word in line.strip().split():
        w = remove_special(word)
        if w:  # avoid empty output
            print(f"{w}\t1")
