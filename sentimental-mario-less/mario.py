response = input("Height of pyramid (max 8):")

while (not response.isdigit() or int(response) > 8 or int(response) <= 0):
    response = (input("Height of pyramid (max 8):"))

height = int(response)

for number in range(height):
    blocks = "#" * (number + 1)
    spaces = ' ' * (height - number - 1)
    print(spaces, end='')
    print(blocks, end='')
    print('')
