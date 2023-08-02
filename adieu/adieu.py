def main():
    names = []
    while True:
        try:
            name = input("Name: ")
            names.append(name)
        except EOFError:
            print()
            print("Adieu, adieu, to", end = " ")
            if len(names) == 1:
                print(names[0])
            elif len(names) == 2:
                print(names[0], "and", names[1])
            else:
                for i in range(len(names) - 1):
                    print(names[i], ",", sep = "", end = " ")
                print("and", names[len(names) - 1])
            break








if __name__ == "__main__":
    main()