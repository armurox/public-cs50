def main():
    camel = input("camelCase: ")
    snake = convert(camel)
    print("snake_case:", snake)

def convert(var):
    words = []
    split_loc = 1
    for i in var:
        if i.isupper():
            words = var.split(i)
            words[split_loc] = i.lower() + words[split_loc]
            var = "_".join(words)
    return var


main()