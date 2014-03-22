import sys

lines = []

# Reading from the console
for line in sys.stdin:
    stripped = line.strip()

    if not stripped:
        break

    lines.append(stripped)

# Remove the first line
lines = lines[1:]

# Iterate over each of the lines
for index, line in enumerate(lines):
    words = line.split(" ")
    words.reverse()

    # Print the header
    print "Case #%d:" % (index + 1),

    # Print the words
    for word in words:
        print word,

    print ""
