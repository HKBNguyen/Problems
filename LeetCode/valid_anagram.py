#!/usr/bin/python3

def isAnagram(self, s, t):
    if len(s) != len(t):
        return False;
    count = collections.defaultdict(int)
    for c in s:
        count[c] += 1
    for c in t:
        count[c] -= 1
    for letter in count:
        if letter != 0:
            return False;
    return True;



