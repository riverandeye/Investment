A, B = map(int, input().split())

result = (str(A//B)+".")
A = (A % B) * 10

for _ in range(1000): 
    result += str(A // B)
    A = (A % B) * 10
    
print(result)