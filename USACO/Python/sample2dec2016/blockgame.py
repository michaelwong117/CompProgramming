def run(file_in):
	#print 'Reading from ' + file_in

	f = open(file_in, "r")
	numOfBoards = int(f.readline().strip())

	alphabet = 'abcdefghijklmnopqrstuvwxyz'

	# Initialize dictionaries.
	letterFrequency1 = {}

	letterFrequency2 = {}

	maxLetterFrequency = {}

	for c in alphabet:

		letterFrequency1[c] = 0
		letterFrequency2[c] = 0
		maxLetterFrequency[c] = 0

	# letterFrequency1 = {"a" : 0, "b" : 0 , "c" : 0, "d" : 0, "e" : 0, "f" : 0, "g" : 0 , "h" : 0, "i" : 0, "j" : 0, "k" : 0, "l" : 0, "m" : 0, "n" : 0, "o": 0, "p" : 0, "q" : 0, "r" : 0, "s" : 0, "t" : 0, "u" : 0, "v" : 0, "w" : 0, "x": 0, "y" : 0, "z": 0}
	# letterFrequency2 = {"a" : 0, "b" : 0 , "c" : 0, "d" : 0, "e" : 0, "f" : 0, "g" : 0 , "h" : 0, "i" : 0, "j" : 0, "k" : 0, "l" : 0, "m" : 0, "n" : 0, "o": 0, "p" : 0, "q" : 0, "r" : 0, "s" : 0, "t" : 0, "u" : 0, "v" : 0, "w" : 0, "x": 0, "y" : 0, "z": 0}

	# count = 0
	# for key in letterFrequency1:
	# 	count+=1
	# print "count =", count

	for i in xrange(numOfBoards):

		board = f.readline().strip().split()

		side1 = board[0]

		side2 = board[1]

		for i in side1:

			letterFrequency1[i] += 1

		for i in side2:

			letterFrequency2[i] += 1

		for key in alphabet:

			if letterFrequency2[key] > letterFrequency1[key]:
				maxLetterFrequency[key] += letterFrequency2[key]
			else:
				maxLetterFrequency[key] += letterFrequency1[key]
			letterFrequency2[key] = 0
			letterFrequency1[key] = 0




	f = open("blocks.out", "w")

	for key in alphabet:

		print >>f, maxLetterFrequency[key]
		#print maxLetterFrequency[key], key















def main():
	run("blocks.in")
	#run("blocks_bronze_dec16/2.in")



if __name__ == "__main__":
	main()



