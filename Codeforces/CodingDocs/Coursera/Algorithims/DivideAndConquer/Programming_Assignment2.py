def split_list(a_list):

    half = len(a_list)/2

    return a_list[:half], sorteda_list[half:]



# file_in is the input file
def run(file_in):
	#print 'Reading from ' + file_in

	f = open(file_in, "r")

	array = []

	n = 100000

	i = 0

	j = 0

	for k in range(0, n):

		str_in = int(f.readline().strip())
		#if str_in == '100000':
		#    print 'str_in =', str_in
		array.append(str_in)

	for k in 






	


# This is the real run.
# It reads from 'crossroad.in'
def main():
	run("Assignment2Data.txt")


if __name__ == "__main__":
	main()