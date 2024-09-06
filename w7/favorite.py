# Sorts favorites by value using .get

import csv
import sys

from collections import Counter

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    counts = Counter()

    # Column
    col = 'language'

    if len(sys.argv) >= 2 and sys.argv[1] in ['p', 'problem']:
        col = 'problem'

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row[col]
        counts[favorite] += 1

# Print counts
for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")
