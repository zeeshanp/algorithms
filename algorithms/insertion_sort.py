#!/usr/bin/py

def insertion_sort(sequence):
	for i in range(0,len(sequence)):
		x = sequence[i]
		j = i
	while ( j > 0 and sequence[j-1] > x):
		sequence[j] = sequence[j-1]
		j = j - 1
	sequence[j] = x


def main():
	sequence = [8,3,6,4]
	insertion_sort(sequence)
	print sequence


if __name__ == "__main__":
	main()
		
