# 22.01.2023 - 8054757 - Matvei Maslov
# Question 2
import random

SPECIAL_SYMBOLS = [chr(i) for i in range(33, 48)] + [chr(i) for i in range(58, 65)] + [
    chr(i) for i in range(91, 97)] + [chr(i) for i in range(123, 127)]


# print(''.join(SPECIAL_SYMBOLS))

def createPswd():
    list = [chr(random.randint(48, 57)), random.choice(SPECIAL_SYMBOLS), chr(random.randint(65, 90)),
            chr(random.randint(97, 122))] + [chr(random.randint(33, 126)) for _ in range(random.randint(8, 15) - 4)]
    random.shuffle(list)
    return ''.join(list)


if __name__ == "__main__":
    print(createPswd())
