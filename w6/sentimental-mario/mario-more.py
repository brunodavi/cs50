from libs import get_int, print_half_pyramid


def main():
    number = get_int("Height: ")
    left = '{spaces}{hashtags}'
    right = '{hashtags}{spaces}'
    print_half_pyramid(number, f'{left}  {right}')


if __name__ == "__main__":
    main()
