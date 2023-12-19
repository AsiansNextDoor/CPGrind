t = int(input())

letters = ["a", "b", "c", "d", "e", "f", "g", "h"]
numbers = [1, 2, 3, 4, 5, 6, 7, 8];
for tests in range(t):
    s1 = input();
    for i in range (8):
        for j in range(8):
            if ((letters[i] != s1[0] and numbers[j] == int(s1[1])) or (letters[i] == s1[0] and numbers[j] != int(s1[1]))):
                print(letters[i] + str(numbers[j]))