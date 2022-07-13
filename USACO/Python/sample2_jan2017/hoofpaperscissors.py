def run(file_in):
	max1 = 0
	max2 = 0
	f = open(file_in, "r")
	games = int(f.readline().strip())
	for i in xrange(games):
		hps = f.readline().strip().split()
		#print hps
		if hps[0] == '1' and hps[1] == '2':
			max1 += 1
		if hps[0] == '2' and hps[1] == '3':
			max1 += 1
		if hps[0] == '3' and hps[1] == '1':
			max1 += 1


		if hps[0] == '2' and hps[1] == '1':
			max2 += 1
		if hps[0] == '1' and hps[1] == '3':
			max2 += 1
		if hps[0] == '3' and hps[1] == '2':
			max2 += 1

	f = open("hps.out", "w")

	if max1 > max2:
		print >>f, max1
	else:
		print >>f, max2
	#print max1, max2





def main():
	run("hps.in")
	# run("hps_bronze_jan17/1.in")



if __name__ == "__main__":
	main()