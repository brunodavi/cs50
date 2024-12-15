coins = (25, 10, 5, 1)


def get_float(prompt: str):
    while True:
        try:
            number = float(input(prompt))
            if (number < 0.01):
                continue
            return number
        except ValueError:
            pass


def count_coins(number: int):
    count = 0

    number *= 100

    for coin in coins:
        if (number >= coin):
            count += number // coin
            number %= coin

    return int(count)


def main():
    number = get_float("Change: ")

    print(
        count_coins(number)
    )


if __name__ == "__main__":
    main()
