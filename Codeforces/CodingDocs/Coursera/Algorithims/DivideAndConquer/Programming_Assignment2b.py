test1 = [1, 20, 6, 4, 5]
test2 = [1, 3, 4, 2, 5]


def count_inversions(l):

	inversions = 0
	i = 1
	for x in l:
		for y in l[i:]:
			if x > y:
				inversions += 1
		i+=1 
		if i % 1000 == 0:
			print "i=", i


	print inversions
	return inversions
print "test1 = ", count_inversions(test1)
print "test2 = ", count_inversions(test2)

def run(file_in):
	#print 'Reading from ' + file_in

	f = open(file_in, "r")

	array = []

	n = 100000

	for k in range(0, n):

		str_in = int(f.readline().strip())

		array.append(str_in)

	print count_inversions(array)
	return count_inversions(array)






def main():
	run("Assignment2Data.txt")


if __name__ == "__main__":
	main()
