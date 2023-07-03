import cs50

amount = cs50.get_float("Change required: ")
coins = 0

while (amount < 0):
    amount = cs50.get_float("Change required: ")

while (amount >= 0.25):
    amount = round(amount - 0.25, 2)
    coins += 1

while (amount >= 0.1):
    amount = round(amount - 0.1, 2)
    coins += 1

while (amount >= 0.05):
    amount = round(amount - 0.05, 2)
    coins += 1

while (amount >= 0.01):
    amount = round(amount - 0.01, 2)
    coins += 1

print(coins)

