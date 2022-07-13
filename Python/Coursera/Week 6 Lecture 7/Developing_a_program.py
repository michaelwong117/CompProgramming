import tkinter.filedialog
import grade

al_filename = tkinter.filedialog.asksaveasfilename()
al_file = open(al_filename, 'r')


# Read the grades into a list.
grades = grade.read_grades.read_grades(al_file)
range_counts = grade.count_grade_ranges(grades)

print(range_counts)

# Count the grades per range.

# Write the histogram to the file.


