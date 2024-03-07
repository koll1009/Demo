#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

void
populateLps(const char *needle, int *lps, size_t lpsBytes, size_t lpsLen)
{
    int len = 0;
    size_t idx = 1;

    memset(lps, 0, lpsBytes);

    while (idx < lpsLen) {
        if (needle[idx] == needle[len]) {
            lps[idx++] = ++len;
        }
        else if (len > 0) {
            len = lps[len - 1];//largest prefix string means the prefix 'one' matches with lps[len-1] chars
        }
        else {
            lps[idx++] = 0;
        }
    }
}

const char *kmpSearch(const char *haystack, size_t haystackLen, const char *needle, size_t needleLen)
{
    const char *match = nullptr;

    if (0 == needleLen) {
        return &haystack[0];
    }

    int *lps = new int[needleLen];
    if (!lps) {
        return nullptr;
    }
    populateLps(needle, lps, needleLen * sizeof(int), needleLen);

    size_t haystackIdx = 0;
    size_t needleIdx   = 0;

    while (haystackIdx < haystackLen) {
        if (needle[needleIdx] == haystack[haystackIdx]) {
            ++needleIdx;
            ++haystackIdx;
        }

        if (needleIdx == needleLen) {
            match = &haystack[haystackIdx - needleIdx];
            delete [] lps;
            return match;
        }
        if (haystackIdx < haystackLen && needle[needleIdx] != haystack[haystackIdx]) {
            if (needleIdx > 0) {
                needleIdx = lps[needleIdx - 1];
            }
            else {
                ++haystackIdx;
            }
        }
    }

    delete [] lps;
    return match;
}