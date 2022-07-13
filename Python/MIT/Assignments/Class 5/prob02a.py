
def run_me():
    # Input section
    a = 'How many classes did you take? '
    b = 'What was the name of this class? '
    c = 'What was your grade? '
    list_of_class = []
    list_of_grades = []
    sum_of_grades = 0

    num_of_class = int(input(a))
    while num_of_class >= 1:

        name_of_class = input(b)
        list_of_class.append(name_of_class)
        grade = int(input(c))
        list_of_grades.append(grade)
        num_of_class = num_of_class - 1
       
    # Processing section
    for grade in list_of_grades:
        sum_of_grades += grade
    sum_of_grades /= len(list_of_grades)
    


    # Output section

    print()

    print('REPORT CARD: ')

    print()

    for i in range(len(list_of_class)):
        print(list_of_class[i] + ' - ' + str(list_of_grades[i]))

    print()
    print('Overall GPA - ' + str(sum_of_grades))
    
  
    
                                                 
