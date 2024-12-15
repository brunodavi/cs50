import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) < 3:
        print("Usage: python dna.py database.csv sequences.txt")
        sys.exit(1)

    [_, database_csv, sequence_txt] = sys.argv

    # TODO: Read database file into a variable
    database = []

    with open(database_csv) as file_csv:
        database = [*csv.DictReader(file_csv)]

    # TODO: Read DNA sequence file into a variable
    sequence = ''

    with open(sequence_txt) as file_txt:
        sequence = file_txt.read()

    # TODO: Find longest match of each STR in DNA sequence
    [_, *subsequence_list] = database[0].keys()

    dna_found = [
        longest_match(sequence, subsequence)
        for subsequence in subsequence_list
    ]

    # TODO: Check database for matching profiles
    for db in database:
        name = db['name']
        del db['name']

        db_dna = [int(v) for v in db.values()]

        if db_dna == dna_found:
            print(name)
            return

    print('No match')

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


if __name__ == "__main__":
    main()
