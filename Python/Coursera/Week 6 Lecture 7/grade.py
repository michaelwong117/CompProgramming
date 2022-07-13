def read_grades(gradefile):
    line = gradefile.readline()
    while line != '\n':
        line = gradefile.readline()

    grades = []

    line = gradefile.readline()
    while line != '':
        # Now we have s string containing the info for a single student.
        # Find the last space and take everything after that.
        grade = line[line.rfind(' ') + 1:]
        grades.append(float(grade))
        line = gradefile.readline()

    return grades

def count_grade_ranges(grades):
    range_counts = [0] * 11

    for grade in grades:
        which_range = int(grade // 10)
        range_counts[which_range] = range_counts[which_range] + 1

    return range_counts
    
        
        
