def identify_card(card_number: str):
    """
    Identify card type from nunber

    >>> identify_card("378282246310005")
    'AMEX'

    >>> identify_card("4003600000000014")
    'VISA'

    >>> identify_card("5555555555554444")
    'MASTERCARD'

    >>> identify_card("1234567890")
    """

    two_nunbers = int(card_number[:2])
    card_size = len(card_number)
    
    if two_nunbers in [34, 37] and card_size == 15:
        return "AMEX"
    elif 40 <= two_nunbers <= 49 and card_size in [13, 16]:
        return "VISA"
    elif 51 <= two_nunbers <= 55 and card_size == 16:
        return "MASTERCARD"


def is_valid(card_number: str):
    """
    Solve algorithm to determine if the card is valid

    >>> is_valid("4003600000000014")
    True

    >>> is_valid("378282246310005")
    True

    >>> is_valid("5555555555554444")
    True

    >>> is_valid("1234567890")
    False
    """

    first_list = card_number[-1::-2]
    first_iter = map(int, first_list)
    first_result = sum(first_iter)

    second_list = card_number[-2::-2]

    def duplicate_unit(digit: str):
        digit = int(digit)
        digit *= 2

        if (digit > 9): digit -= 9

        return digit

    second_iter = map(duplicate_unit, second_list)
    second_result = sum(second_iter)

    total = first_result + second_result

    return total % 10 == 0


def get_string(prompt: str):
    value = ''

    while value == '':
        value = input(prompt)

    return value


def main(card_number = None):
    """
    Program to validate credit cards

    >>> main("4003600000000014")
    VISA


    >>> main("4222222222222")
    VISA

    ---

    >>> main("378282246310005")
    AMEX

    >>> main("371449635398431")
    AMEX

    ---

    >>> main("5555555555554444")
    MASTERCARD

    ---

    >>> main("1234567890")
    INVALID

    >>> main("4062901840")
    INVALID

    >>> main("4222222222223")
    INVALID

    >>> main("430000000000000")
    INVALID
    """

    if card_number is None:
        card_number = get_string("Number: ")

    card_type = identify_card(card_number)
    
    if (identify_card(card_number) is None
        or
        not is_valid(card_number)
    ):
        print("INVALID")
    else:
        print(card_type)


if __name__ == "__main__":
    main()
