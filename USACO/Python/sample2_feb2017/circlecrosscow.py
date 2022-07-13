def run(file_in):
	#print 'Reading from ' + file_in
	circleCross = 0
	f = open(file_in, "r")
	characters = f.readline().strip()
	for c in characters:
		index = characters.index(c)
		index2 = characters.index(c, c+1)
		
		
			








	#f = open("circlecross.out", "w")
	#print >>f, circleCross
	print circleCross









def main():
	#run("circlecross.in")
	run("circlecross_bronze_feb17/1.in")



if __name__ == "__main__":
	main()