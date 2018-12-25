class last_occurrence(object):

    def __init__(self, pattern, alphabet):

        self.occurrences = dict()
        for char in alphabet:
            self.occurrences[char] = pattern.rfind(char)

    def __call__(self, char):
        return self.occurrences[char]


def boyer_moore_match(src, pattern):
    alphabet = set(src)
    last = last_occurrence(pattern, alphabet)
    m = len(pattern)
    n = len(src)
    i = m - 1  # text index
    j = m - 1  # pattern index
    while i < n:
        if src[i] == pattern[j]:
            if j == 0:
                return i
            else:
                i -= 1
                j -= 1
        else:
            l = last(src[i])
            i = i + m - min(j, 1+l)
            j = m - 1 

    return -1


if __name__ == "__main__":
    def show_match(src, pattern):
        print("String: {}".format(src))
        shift = boyer_moore_match(src, pattern)
        print("Match:  {}{}{}".format( \
            "."*shift, pattern, "."*(len(src)-len(pattern)-shift) ))
        

    string = "the quick brown fox jumps over the lazy dog"
    pattern = "brown"
    show_match(string, pattern)
