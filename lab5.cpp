import random
import string

# create the dictionary of replacements for 5 letters
replacements_dict = {}

# we will choose 5 letters and assign 3 replacement characters to each letter
for _ in range(5):
    letter = input("Enter a lowercase character: ")
    replacements = set()  # using a set to ensure unique replacement characters
    while len(replacements) < 3:  # ensure exactly 3 unique replacements
        replacement = input(f"Enter a replacement for '{letter}': ")
        if len(replacement) == 1:  # only allow single characters
            replacements.add(replacement)
        else:
            print("Please enter a single character.")

    replacements_dict[letter] = list(replacements)  # store replacements as a list

# generate random passwords
passwords = []
for _ in range(5):
    password = ''.join(random.choices(string.ascii_lowercase, k=15))
    passwords.append(password)

# replace chosen letters with random replacements
def replace_with_replacements(password):
    new_password = list(password)
    replacements_count = 0
    for i in range(len(new_password)):
        char = new_password[i]
        if char in replacements_dict:
            replacement = random.choice(replacements_dict[char])
            new_password[i] = replacement
            replacements_count += 1
    return ''.join(new_password), replacements_count

# categorize passwords as strong or weak
categorized_passwords = {"strong": [], "weak": []}

for password in passwords:
    new_password, replaced_count = replace_with_replacements(password)
    if replaced_count > 4:
        categorized_passwords["strong"].append(new_password)
    else:
        categorized_passwords["weak"].append(new_password)

# dissplay categorized passwords
print("\nGenerated Passwords:")
print("STRONG PASSWORDS:")
for password in categorized_passwords["strong"]:
    print(password)

print("\nWEAK PASSWORDS:")
for password in categorized_passwords["weak"]:
    print(password)
