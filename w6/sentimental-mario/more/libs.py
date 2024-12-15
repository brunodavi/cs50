def get_int(prompt: str):
    while True:
        try:
            number = int(input(prompt))
        except ValueError:
            pass
        else:
            if 0 < number <= 8:
                return number


def print_half_pyramid(height: int, template: str):
    i = 1

    while i <= height:
        hashtags = '#' * i
        spaces = ' ' * (height - i)

        print(
            template.format(
                spaces=spaces,
                hashtags=hashtags
            )
        )

        i += 1
