def main():
    amount_due = 50
    calculate(amount_due)

def calculate(amount_due):
    while True:
        if amount_due <= 0:
            print("Change Owed:", -1 * amount_due)
            break
        print("Amount Due:", amount_due)
        amount_paid = int(input("Insert Coin: "))
        if amount_paid == 25 or amount_paid == 10 or amount_paid == 5:
            amount_due -= amount_paid





main()