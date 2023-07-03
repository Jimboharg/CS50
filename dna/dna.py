import csv
import sys


def main():

    # Check for command-line usage

    if len(sys.argv) != 3:
        sys.exit("Usage: python database sequence")

    # Read database file into a variable

    data = []
    subs = []
    file1 = sys.argv[1]
    with open(file1) as f1:
        reader1 = csv.DictReader(f1)
        subs = reader1.fieldnames
        for person in reader1:
            data.append(person)
    subs.remove('name')

    # Read DNA sequence file into a variable

    sequence = []
    file2 = sys.argv[2]
    with open(file2) as f2:
        sequence = f2.readlines()

    # Find longest match of each STR in DNA sequence

    long_runs = []
    for STR in subs:
        longest_run = longest_match(sequence[0], STR)
        long_runs.append(longest_run)

    # Check database for matching profiles

    for dict in data:
        person_array = []
        name = dict['name']
        dict.pop('name')
        for values in dict.values():
            person_array.append(int(values))
        if (long_runs == person_array):
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


main()
