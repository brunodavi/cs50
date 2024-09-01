from libs import get_int, print_half_pyramid


def main():
    number = get_int("Height: ")
    print_half_pyramid(number, '{spaces}{hashtags}')


if __name__ == "__main__":
    main()
