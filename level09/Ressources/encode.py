import sys

word = sys.argv[1]
print(f"converting {word}")

for i in range(len(word)):
    print(chr(ord(word[i]) + i), end="")

