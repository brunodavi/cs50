
visa_1 = "4003600000000014"
visa_2 = "430000000000000"
visa_3 = "4222222222222"

amex_1 = "378282246310005"
amex_2 = "371449635398431"

invalid_all = "1234567890"
invalid_len = "4062901840"
invalid_cod = "4222222222223"

def print_card(two_nunbers: int, card_len: int):
    ...

def valid_card(card_number: str):
    card_len = len(card_number)
    
    print_card(card_len)


def get_string(prompt: str):
    value = ''

    while value == '':
        value = input(prompt)

    return value


def main():
    card_number = get_string("Number: ")
    valid_card(card_number)


if __name__ == "__main__":
    main()
