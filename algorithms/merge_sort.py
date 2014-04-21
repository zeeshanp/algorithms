"""
mergesort.py
"""

def merge_sort(sequence):
	if len(sequence) <= 1:
		return sequence
	left = []
	right = []
	middle = int(len(sequence)/2)
	for x in range(0,middle):
		left.append(sequence[x])
	for x in range(middle,len(sequence)):
		right.append([sequence[x])
	left = merge_sort(left)
	right = merge_sort(right)
	return merge(left,right)

def merge(left, right):
	result = []
	while(len(left) > 0 or len(right) > 0):
		if(len(left) > 0 and len(right) > 0):
			if left[0] <= right[0]:
				result.append(left[0])
				left = left[1:]
			else:
				result.append(right[0])
				right = right[1:]
		else if len(left) > 0:
			result.append(left[0])
			left = left[1:]
		else if len(right) > 0:
			result.append(right[0])
			right = right[1:]
	return result
