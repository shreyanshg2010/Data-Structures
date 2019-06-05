def plusOne(A):
    
    for i in range(len(A)-1, -1, -1):
        if A[i] == 9:
             A[i] = 0
        else:
            A[i] += 1
            print(A[i])
            while True:
                if A[0] == 0:
                    del A[0]
                else:
                    return A
            return A
    A = [1] + A
    return A
s = input()
A = list(map(int, s.split()))
print(plusOne(A))

