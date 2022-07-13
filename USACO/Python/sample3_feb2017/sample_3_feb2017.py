


# file_in is the input file
def run(file_in):
	#print 'Reading from ' + file_in

	f = open(file_in, "r")
	observations = int(f.readline().strip())
	values = {}

	crossings = 0

	for i in xrange(observations):
		crossing = f.readline().strip().split()
		cow_index = crossing[0]
		side = crossing[1]
		if cow_index in values:
			if values[cow_index] != side:
				crossings += 1

		values[cow_index] = side

	f = open("crossroad.out", "w")
	print >>f, crossings



	


# This is the real run.
# It reads from 'crossroad.in'
def main():
	run("crossroad.in")
	# run("crossroad_bronze_feb17/2.in")



if __name__ == "__main__":
	main()

