def run(file_in):
	#print 'Reading from ' + file_in

	f = open(file_in, "r")
	rectangle1 = f.readline().strip().split()
	rectangle2 = f.readline().strip().split()

	maxDiffx = 0
	maxDiffy = 0

	x1 = int(rectangle1[0])

	y1 = int(rectangle1[1])

	x2 = int(rectangle1[2])

	y2 = int(rectangle1[3])


	x3 = int(rectangle2[0])

	y3 = int(rectangle2[1])

	x4 = int(rectangle2[2])

	y4 = int(rectangle2[3])

	if x3 - x1 > maxDiffx:
		maxDiffx = x3 - x1
	if x4 - x1 > maxDiffx:
		maxDiffx = x4 - x1
	if x3 - x2 > maxDiffx:
		maxDiffx = x3 - x2
	if x4 - x2 > maxDiffx:
		maxDiffx = x4 - x2

	if x1 - x3 > maxDiffx:
		maxDiffx = x1 - x3
	if x1 - x4 > maxDiffx:
		maxDiffx = x1 - x4
	if x2 - x3 > maxDiffx:
		maxDiffx = x2 - x3
	if x2 - x4 > maxDiffx:
		maxDiffx = x2 - x4 

	if y3 - y1 > maxDiffy:
		maxDiffy = y3 - y1
	if y4 - y1 > maxDiffy:
		maxDiffy = y4 - y1
	if y3 - y2 > maxDiffy:
		maxDiffy = y3 - y2
	if y4 - y2 > maxDiffy:
		maxDiffy = y4 - y2

	if y1 - y3 > maxDiffy:
		maxDiffy = y1 - y3
	if y1 - y4 > maxDiffy:
		maxDiffy = y1 - y4
	if y2 - y3 > maxDiffy:
		maxDiffy = y2 - y3
	if y2 - y4 > maxDiffy:
		maxDiffy = y2 - y4

	#if maxDiffx > maxDiffy:
	#	print maxDiffx * maxDiffx
	#else:
	#	print maxDiffy * maxDiffy

	squarex = maxDiffx * maxDiffx
	squarey = maxDiffy * maxDiffy
	
	f = open("square.out", "w")
	if maxDiffx > maxDiffy:

		print >>f, squarex


	else:

		print >>f, squarey











def main():
	run("square.in")
	#run("square_bronze_dec16/2.in")



if __name__ == "__main__":
	main()