"""
quick_sort.py

Worst case run time: O(n^2) (extremely rare)
Average case run time: O(nlogn)
Best case run time: O(nlogn)
"""


def quick_sort(sequence):
	if len(sequence) <= 1:
		return sequence
	else:	
		pivot = sequence[0]
		less = sorted([x for x in sequence[1:] if x < pivot])
		greater = sorted([x for x in sequence[1:] if x >= pivot])
		return less + [pivot] + greater



