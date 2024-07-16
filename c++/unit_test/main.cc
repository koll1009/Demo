#include "gtest/gtest.h"

// pthread_once_t object used to control the one-time initialization
pthread_once_t once_control = PTHREAD_ONCE_INIT;

// The initialization function that will be called once
void initialize_once(void) {
  printf("Initialization routine called.\n");
  // Perform your initialization here (e.g., open files, allocate memory, etc.)
}

// Thread function that calls pthread_once
void *thread_func(void *arg) {
  printf("Thread %ld is running\n", (long)arg);
  pthread_once(&once_control, initialize_once);
  printf("Thread %ld initialization complete\n", (long)arg);
  return NULL;
}

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);

  pthread_t threads[3];

  // Create multiple threads
  for (long i = 0; i < 3; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)i);
  }

  // Wait for all threads to finish
  for (int i = 0; i < 3; i++) {
    pthread_join(threads[i], NULL);
  }

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

void populateLps(const char *needle, int *lps, size_t lpsBytes, size_t lpsLen) {
  int len = 0;
  size_t idx = 1;

  memset(lps, 0, lpsBytes);

  while (idx < lpsLen) {
    if (needle[idx] == needle[len]) {
      lps[idx++] = ++len;
    } else if (len > 0) {
      len = lps[len - 1]; // largest prefix string means the prefix 'one'
                          // matches with lps[len-1] chars
    } else {
      lps[idx++] = 0;
    }
  }
}

const char *kmpSearch(const char *haystack, size_t haystackLen,
                      const char *needle, size_t needleLen) {
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
  size_t needleIdx = 0;

  while (haystackIdx < haystackLen) {
    if (needle[needleIdx] == haystack[haystackIdx]) {
      ++needleIdx;
      ++haystackIdx;
    }

    if (needleIdx == needleLen) {
      match = &haystack[haystackIdx - needleIdx];
      delete[] lps;
      return match;
    }
    if (haystackIdx < haystackLen &&
        needle[needleIdx] != haystack[haystackIdx]) {
      if (needleIdx > 0) {
        needleIdx = lps[needleIdx - 1];
      } else {
        ++haystackIdx;
      }
    }
  }

  delete[] lps;
  return match;
}