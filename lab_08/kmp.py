def kmp_match(src, pattern):
    lsp = find_lsp(pattern)
    j = 0
    for i in range(len(src)):
        while j>0 and src[i] != pattern[j]:
            j = lsp[j-1]
        if src[i] == pattern[j]:
            j += 1
            if j == len(pattern):
                return i - (j - 1)

    return -1


def find_lsp(pattern):
    lsp = [0]*len(pattern)
    for i in range(1, len(pattern)):
        j  = lsp[i-1]
        while j > 0 and pattern[i] != pattern[j]:
            j = lsp[j-1]
        if pattern[i] == pattern[j]:
            j += 1
        lsp[i] = j

    return lsp

if __name__  == "__main__":

    def show_match(src, pattern):
        print("String: {}".format(src))
        shift = kmp_match(src, pattern)
        print("Match:  {}{}{}".format( \
            "."*shift, pattern, "."*(len(src)-len(pattern)-shift) ))

    string = "the quick brown fox jumps over the lazy dog"
    pattern = "brown"
    show_match(string, pattern)
