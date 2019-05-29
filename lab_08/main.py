import sys
import time
from boyer_moore import boyer_moore_match
from kmp import kmp_match

if __name__ == "__main__":
    if len(sys.argv) != 3:
        raise "Error the amount of args too low - expected: string substring"
    string = sys.argv[1]
    substring = sys.argv[2]

    s_bm = time.time()
    r1 = boyer_moore_match(string, substring)
    e_bm = time.time()
    
    s_kmp = time.time()
    r2 = kmp_match(string, substring)
    e_kmp = time.time()
    print("BM time is {}\tKMP time is {} \nshifts {} and {}".format( \
        e_bm - s_bm, e_kmp - s_kmp, r1, r2))
