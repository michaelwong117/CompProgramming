'''A board is a list of list of str. For example, the board
    ANTT
    XSOB
is represented as the list
    [['A', 'N', 'T', 'T'], ['X', 'S', 'O', 'B']]

A word list is a list of str. For example, the list of words
    ANT
    BOX
    SOB
    TO
is represented as the list
    ['ANT', 'BOX', 'SOB', 'TO']
'''


def is_valid_word(wordlist, word):
    ''' (list of str, str) -> bool

    Return True if and only if word is an element of wordlist.

    >>> is_valid_word(['ANT', 'BOX', 'SOB', 'TO'], 'TO')
    True
    '''
    if word in wordlist:
        return True
    
    return False


def make_str_from_row(board, row_index):
    '''(list of list of str, int) -> str

    Return the characters from the row of the board with index row_index
    as a single string.

    >>> make_str_from_row([['A', 'N', 'T', 'T'], ['X', 'S', 'O', 'B']], 0)
    'ANTT'
    '''
    row = board[row_index]
    sum_of_lists = ''
    for s in row:
        sum_of_lists = sum_of_lists + s
    return sum_of_lists


    
def make_str_from_column(board, column_index):
    ''' (list of list of str, int) -> str

    Return the characters from the column of the board with index column_index
    as a single string.

    >>> make_str_from_column([['A', 'N', 'T', 'T'], ['X', 'S', 'O', 'B']], 1)
    'NS'
    '''
    total_list = ''
    for row in board:
        total_list = total_list + row[column_index]
    return total_list
        
def board_contains_word_in_row(board, word):
    ''' (list of list of str, str) -> bool

    Return True if and only if one or more of the rows of the board contains
    word.

    Precondition: board has at least one row and one column, and word is a
    valid word.

    >>> board_contains_word_in_row([['A', 'N', 'T', 'T'], ['X', 'S', 'O', 'B']], 'SOB')
    True
    '''

    for row_index in range(len(board)):
        if word in make_str_from_row(board, row_index):
            return True
  
    return False


def board_contains_word_in_column(board, word):
    ''' (list of list of str, str) -> bool

    Return True if and only if one or more of the columns of the board
    contains word.

    Precondition: board has at least one row and one column, and word is a
    valid word.

    >>> board_contains_word_in_column([['A', 'N', 'T', 'T'], ['X', 'S', 'O', 'B']], 'NO')
    False
    '''
    num_columns = len(board[0])
    for column_index in range(num_columns):
        if word in make_str_from_column(board, column_index):
            return True

    return False
            

        
def board_contains_word(board, word):
    '''(list of list of str, str) -> bool

    Return True if and only if word appears in board.

    Precondition: board has at least one row and one column.

    >>> board_contains_word([['A', 'N', 'T', 'T'], ['X', 'S', 'O', 'B']], 'ANT')
    True
    '''
    if board_contains_word_in_column(board, word):
        return True
    if board_contains_word_in_row(board, word):
        return True
    return False


    
def word_score(word):
    '''(str) -> int

    Return the point value the word earns.

    Word length: < 3: 0 points
                 3-6: 1 point per character in word
                 7-9: 2 points per character in word
                 10+: 3 points per character in word

    >>> word_score('DRUDGERY')
    16
    '''
    total_points = 0
    word_len = len(word)
    if word_len < 3:
        total_points = 0
    if word_len <= 6 and word_len >= 3:
        total_points = 1 * word_len
    if word_len >= 7 and word_len <= 9:
        total_points = 2 * word_len
    if word_len >= 10:
        total_points = 3 * word_len
    return total_points
        
            
        


def update_score(player_info, word):
    '''([str, int] list, str) -> NoneType

    player_info is a list with the player's name and score. Update player_info
    by adding the point value word earns to the player's score.

    >>> update_score(['Jonathan', 4], 'ANT')
    '''
    player_info[1] = player_info[1] + word_score(word)
    print(player_info)
    
   
    
    
    


def num_words_on_board(board, words):
    '''(list of list of str, list of str) -> int

    Return how many words appear on board.

    >>> num_words_on_board([['A', 'N', 'T', 'T'], ['X', 'S', 'O', 'B']], ['ANT', 'BOX', 'SOB', 'TO'])
    3
    '''
    total_num_of_words = 0
    for w in words:
        if board_contains_word(board, w):
            total_num_of_words = total_num_of_words + 1

    return total_num_of_words
  
    
    
        


def read_words(words_file):
    ''' (file open for reading) -> list of str

    Return a list of all words (with newlines removed) from open file
    words_file.

    Precondition: Each line of the file contains a word in uppercase characters
    from the standard English alphabet.
    '''
    list_of_words = []
    for l in words_file:
        word = str(l)
        
        #Get rid of carriage return in word
        if word.endswith('''\n'''):
            word = word.replace('''\n''', '')

        list_of_words.append(word)        
        #print('word = ' + word)        
        #print(list_of_words)        

    return list_of_words       
        


def read_board(board_file):
    ''' (file open for reading) -> list of list of str

    Return a board read from open file board_file. The board file will contain
    one row of the board per line. Newlines are not included in the board.
    '''
    list_of_rows = []

    for row in board_file:
        if row.endswith('''\n'''):
            row = row.replace('''\n''', '')

        # Work on a single row

        list_of_char = []

        for c in row:
            list_of_char.append(c)
            
        list_of_rows.append(list_of_char)

    return list_of_rows
        
        
        
   



