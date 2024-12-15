import re

from cs50 import get_string


def print_grade(text: str):
    letters = len(re.findall(r"[A-Za-z]", text))
    words = text.count(' ') + 1
    sentences = sum(
        (text.count(char) for char in '.!?')
    )

    L = (letters / words) * 100
    S = (sentences / words) * 100

    grade = round(0.0588 * L - 0.296 * S - 15.8)

    if grade < 1:
        print("Before Grade 1")
    elif 1 <= grade <= 16:
        print(f"Grade {grade}")
    elif grade > 16:
        print("Grade 16+")


def main():
    text = ''

    while len(text) == 0:
        text = get_string("Text: ")

    print_grade(text)


if __name__ == "__main__":
    main()
