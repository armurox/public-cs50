import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py csvfile textfile")
        sys.exit(1)
    # TODO: Read database file into a variable
    people = []
    with open(sys.argv[1]) as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            people.append(row)
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    longest_matches = {}
    keys = list(people[0].keys())
    for short_tandem_repeat in keys[1:]:
        longest_matches[short_tandem_repeat] = str(
            longest_match(sequence, short_tandem_repeat)
        )

    # TODO: Check database for matching profiles
    for person in people:
        no_match = 1
        longest_matches["name"] = person["name"]
        if longest_matches == person:
            print(person["name"])
            no_match = 0
            break
    if no_match == 1:
        print("no match")

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


main()
