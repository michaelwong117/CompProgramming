# file_in is the input file
def run(file_in):
	#print 'Reading from ' + file_in
	maxArrive = 0
	maxArriveSpent = 0
	maxSum = 0

	f = open(file_in, "r")
	arrivals = int(f.readline().strip())

	for i in xrange(arrivals):

		queueTimes = f.readline().strip().split()

		timeArrived = int(queueTimes[0])

		timeSpent = int(queueTimes[1])

		if timeArrived >= maxArrive:

			maxArrive = timeArrived

			maxArriveSpent = timeSpent

		if timeArrived + timeSpent > maxSum:

			maxSum = timeArrived + timeSpent
	if maxSum == maxArrive + maxArriveSpent:
		minTime = maxSum
	else:

		minTime = maxSum + maxArriveSpent

	f = open("cowqueue.out", "w")
	print >>f, minTime

	#print minTime





def main():
	run("cowqueue.in")
	#run("cowqueue_bronze_feb17/4.in")



if __name__ == "__main__":
	main()

