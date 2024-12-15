from libs import get_int


def main():
    number = get_int("Height: ")

    for i in range(1, number + 1):
        print(f"{i * '#':>{number}}  {'#' * i}")


if __name__ == "__main__":
    main()
