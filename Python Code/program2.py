import math as m


def compute_pi(n):
    pi = 1.0
    flag = -1
    for num in range(1, n+1):
        pi += flag / (2.0 * num + 1.0)
        flag = -flag
    return 4.0 * pi


def compute_sqrt(x):
    last = x
    sqrt = 1
    count = 0
    while (count < 10):
        count += 1
        sqrt = 0.5 * (last + (x / last))
        last = sqrt
    return sqrt


def is_prime(n):
    x = (int)((n / 2) + 1)
    for num in range(2, x):
        if (n % num == 0):
            return False
    return True


def display_primes(n):
    temp = []
    for num in range(2, n+1):
        if (is_prime(num) == True):
            temp.append(num)
    print(temp)


def process_scores():
    count = 1
    sum = 0

    inputScore = input(
        "Please enter in a student name and score, seperated by a space: ")
    t = inputScore.split(" ")
    avgScore = t[1]
    minScore = t[1]
    maxScore = t[1]
    sum += int(t[1])
    bestScore = t[0]
    worstScore = t[0]

    print("Avg Score:", avgScore, "\tMin Score:",
          minScore, "\tMax Score:", maxScore)
    print("Student with best score:", bestScore,
          "\nStudent with worst score:", worstScore)

    inputScore = input(
        "Please enter in a student name and score, seperated by a space (or 'q' to quit): ")
    while (inputScore.lower() != "q"):
        t = inputScore.split(" ")
        count += 1
        sum += int(t[1])
        avgScore = sum / count
        if (int(t[1]) < int(minScore)):
            minScore = int(t[1])
            worstScore = t[0]
        elif (int(t[1]) > int(minScore)):
            maxScore = int(t[1])
            bestScore = t[0]
        print("Avg Score:", avgScore, "\tMin Score:",
              minScore, "\tMax Score:", maxScore)
        print("Student with best score:", bestScore,
              "\nStudent with worst score:", worstScore)
        inputScore = input(
            "Please enter in a student name and score, seperated by a space (or 'q' to quit): ")


def compute_tax(income, status, state):
    taxRate = 0.0
    status = status.lower()
    state = state.lower()
    if (state == 'i'):
        if (status == "single" and income <= 30000):
            taxRate = 0.20
        elif (status == "single"):
            taxRate = 0.25
        if (status == "married" and income <= 50000):
            taxRate = 0.10
        elif (status == "married"):
            taxRate = 0.15
    if (state == 'o'):
        if (status == "single" and income <= 30000):
            taxRate = 0.17
        elif (status == "single"):
            taxRate = 0.22
        if (status == "married" and income <= 50000):
            taxRate = 0.07
        elif (status == "married"):
            taxRate = 0.12
    return taxRate * income


def solve_quadratic(a, b, c):
    d = b * b - 4 * a * c
    sol1 = 0.0
    sol2 = 0.0
    if (d >= 0):
        sol1 = (-b - m.sqrt(d)) / (2 * a)
        sol2 = (-b + m.sqrt(d)) / (2 * a)
    return sol1, sol2


def sort(list):
    for i in range(len(list)):
        min = i
        for j in range(i+1, len(list)):
            if (int(list[min]) > int(list[j])):
                min = j
    # I can't believe this works. Python is crazy
        list[i], list[min] = list[min], list[i]
    return list


def id_password(first, last):
    first, last = first.upper(), last.upper()
    username = first[:1] + last
    password = first[:1] + first[-1] + \
        last[:3] + str(len(first)) + str(len(last))
    return username, password


def file_sort(infile, outfile):
    bank = []
    inf = open(infile)
    ouf = open(outfile, "w")
    numStudents = inf.readline()
    for line in inf:
        strip = line.strip()
        t = strip.split()
        bank.append(t)
    inf.close()

    for i in range(len(bank) - 1):
        min_index = i
        for j in range(i+1, len(bank)-1):
            if bank[j][0] < bank[min_index][0]:
                min_index = j
        bank[i], bank[min_index] = bank[min_index], bank[i]

    for line in bank:
        touf = " "
        ouf.write(touf.join(line))
        ouf.write("\n")
    ouf.close()

inp = ''
while (inp != 'q'):
    inp = input("Please enter in a number 1-9, or type 'q' to quit: ")
    if (inp == 'q'):
        break
    else:
        inp = int(inp)
    if (inp == 1):
        digits = int(input("Calculate Pi using ___ digits: "))
        print(compute_pi(digits))
    elif (inp == 2):
        digits = int(input("Calculate Square Root of ___: "))
        print(compute_sqrt(digits))
    elif (inp == 3):
        digits = int(input("Display primes up to ___: "))
        display_primes(digits)
    elif (inp == 4):
        process_scores()
    elif (inp == 5):
        income = int(input("Enter Income: "))
        status = input("Enter Marital Status ('single' or 'married'): ")
        state = input("In or Out of State ('i' or 'o'): ")
        print("Your tax amount is: ", compute_tax(income, status, state))
    elif (inp == 6):
        t = input("Enter in A, B, and C for Quadratic Equation (space seperated): ")
        t = t.split(" ")
        print(solve_quadratic(int(t[0]),int(t[1]),int(t[2])))
    elif (inp == 7):
        l = input("Please enter in any amount of numbers (space seperated): ")
        l = l.split(" ")
        print(l)
        print(sort(l))
    elif (inp == 8):
        name = input("Please enter first and last name (space seperated): ")
        name = name.split(" ")
        print(id_password(name[0], name[1]))
    elif (inp == 9):
        inp = input("Please enter file input name: ")
        oup = input("Please enter file output name: ")
        file_sort(inp, oup)
        print("Written to:", oup)


