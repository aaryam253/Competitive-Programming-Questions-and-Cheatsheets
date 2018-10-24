def numCards(num):  
    return (3*pow(num, 2) + num) // 2 # Floor division


height = int(input())  
while (numCards(height) % 4 != 0):  
    height += 1

print(height)  